/*
 * Copyright (c) 2007, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 */

/**
 * \file
 *         A test program for Deluge.
 * \author
 *         Nicolas Tsiftes <nvt@sics.se>
 */

#include "contiki.h"
#include "cfs/cfs.h"
#include "deluge.h"
#include "sys/node-id.h"
#include "loader/elfloader.h"
#include "shell-exec.h"
#include <stdio.h>
#include <string.h>
#include "serial-shell.h"
#include "collect-view.h"

#include "dev/watchdog.h"

#include "net/rime.h"
#include "dev/cc2420.h"
#include "dev/leds.h"
#include "dev/light.h"
#include "dev/sht11.h"
#include "dev/battery-sensor.h"

#include "lib/checkpoint.h"

#include "net/rime/timesynch.h"
#include "net/rime.h"
#ifndef SINK_ID
#define SINK_ID	1
#endif

#ifndef FILE_SIZE
#define FILE_SIZE 1000
#endif

PROCESS(deluge_test_process, "Deluge test process");
AUTOSTART_PROCESSES(&deluge_test_process);

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(deluge_test_process, ev, data)
{
  int fd, r, fd_file;
  char buf[2000];
  char *file = "hello-world.ce";
  static struct etimer et;
  PROCESS_BEGIN();
  
  memset(buf, 0, sizeof(buf));
  
  if(node_id == SINK_ID) {
    strcpy(buf, "This is version 1 of the file");
  } else {
    strcpy(buf, "This is version 0 of the file");
  }
  
  //cfs_remove(file);
  fd = cfs_open("version", CFS_WRITE);
  printf("fd %d\n",fd);
  if(fd < 0) {
    process_exit(NULL);
  }
  if(cfs_write(fd, buf, sizeof(buf)) != sizeof(buf)) {
    cfs_close(fd);
    process_exit(NULL);
  }

  if(cfs_seek(fd, FILE_SIZE, CFS_SEEK_SET) != FILE_SIZE) {
    printf("failed to seek to the end\n");
  }

  if(elfloader_autostart_processes != NULL) {
      printf("elf loader failed\n");
      autostart_exit(elfloader_autostart_processes);
    }
     fd_file = cfs_open(file, CFS_READ | CFS_WRITE);
     if(fd_file < 0) {
       printf("failed to load file\n");
    } else {
    int ret;
    char *print, *symbol;

    ret = elfloader_load(fd_file);
    cfs_close(fd_file);
    symbol = "";

    switch(ret) {
    case ELFLOADER_OK:
      print = "OK";
      break;
    case ELFLOADER_BAD_ELF_HEADER:
      print = "Bad ELF header";
      break;
    case ELFLOADER_NO_SYMTAB:
      print = "No symbol table";
      break;
    case ELFLOADER_NO_STRTAB:
      print = "No string table";
      break;
    case ELFLOADER_NO_TEXT:
      print = "No text segment";
      break;
    case ELFLOADER_SYMBOL_NOT_FOUND:
      print = "Symbol not found: ";
      symbol = elfloader_unknown;
      break;
    case ELFLOADER_SEGMENT_NOT_FOUND:
      print = "Segment not found: ";
      symbol = elfloader_unknown;
      break;
    case ELFLOADER_NO_STARTPOINT:
      print = "No starting point";
      break;
    default:
      print = "Unknown return code from the ELF loader (internal bug)";
      break;
    }
    printf("Message: %s  Symbol: %s\n", print, symbol);
    deluge_disseminate(file, node_id == SINK_ID);
  //deluge_disseminate("test", node_id == SINK_ID);
  cfs_close(fd_file);

  etimer_set(&et, CLOCK_SECOND * 5);
  for(;;) {
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
    if(node_id != SINK_ID) {
      fd = cfs_open(file, CFS_READ);
      if(fd < 0) {
        printf("failed to open the test file\n");
      } else {
        r = cfs_read(fd, buf, sizeof(buf));
        cfs_close(fd);
	buf[sizeof(buf) - 1] = '\0';
	if(r <= 0) {
	  printf("failed to read data from the file\n");
	} else {
	  printf("File contents: %s\n", buf);
	}
	
      }
    }
    etimer_reset(&et);
    
  }
 }

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
