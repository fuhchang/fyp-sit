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

  int fd, fd_file;
  char *file = "hello-world.ce";
  static struct etimer et;
  PROCESS_BEGIN();
 
  
  if(node_id == SINK_ID) {
   printf("Sink node: trying to transmit file.\n");
 } else {
   printf("Non-sink node: trying to recieve file.\n");
 }

    int ret;
    char *print, *symbol;
    deluge_disseminate(file, node_id == SINK_ID);
    ret = elfloader_load(fd_file);
    cfs_close(fd_file);
    
etimer_set(&et, CLOCK_SECOND * 5);
 PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
 if(node_id != SINK_ID) {
   fd = cfs_open(file, CFS_READ);
   if(fd < 0) {
     printf("failed to open the test file\n");
   } else {
     printf("Start dynamic loading\n");
     int ret = elfloader_load(fd);
     printf("%d\n", ret); 

     cfs_close(fd);

     int i;
     switch(ret) {
case ELFLOADER_OK:
 for(i=0; elfloader_autostart_processes[i] != NULL; i++) {
   printf("exec: starting process %s. \n", 
  elfloader_autostart_processes[i]->name);
 }
 autostart_start(elfloader_autostart_processes);
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
     printf("message: %s symbol: %s\n", print, symbol);
   }
 }
 etimer_reset(&et);
   int fd = cfs_open(file, CFS_READ);
   int loadResult = elfloader_load(fd);
   int j;
   printf("fd %d\n",fd);
   switch(loadResult) {
case ELFLOADER_OK:
 for(j=0; elfloader_autostart_processes[j] != NULL; j++) {
   printf("exec: starting process %s. \n", 
  elfloader_autostart_processes[j]->name);
 }
 autostart_start(elfloader_autostart_processes);
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
     printf("message: %s symbol: %s\n", print, symbol);

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
