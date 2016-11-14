
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
 if(elfloader_autostart_processes != NULL) {
    autostart_exit(elfloader_autostart_processes);
  }
   etimer_reset(&et);
   int cfs_fd = cfs_open(file, CFS_READ);
   int loadResult = elfloader_load(cfs_fd);
   int j;
   char *printT, *symbolf;
   printf("result: %d\n", loadResult);
   switch(loadResult) {
case ELFLOADER_OK:
 for(j=0; elfloader_autostart_processes[j] != NULL; j++) {
   printf("exec: starting process %s. \n", 
  elfloader_autostart_processes[j]->name);
 }
 autostart_start(elfloader_autostart_processes);
         break;
 case ELFLOADER_BAD_ELF_HEADER:
      printT = "Bad ELF header";
      break;
    case ELFLOADER_NO_SYMTAB:
      printT = "No symbol table";
      break;
    case ELFLOADER_NO_STRTAB:
      printT = "No string table";
      break;
    case ELFLOADER_NO_TEXT:
      printT = "No text segment";
      break;
    case ELFLOADER_SYMBOL_NOT_FOUND:
      printT = "Symbol not found: ";
      symbolf = elfloader_unknown;
      break;
    case ELFLOADER_SEGMENT_NOT_FOUND:
      printT = "Segment not found: ";
      symbolf = elfloader_unknown;
      break;
    case ELFLOADER_NO_STARTPOINT:
      printT = "No starting point";
      break;
    default:
      printT = "Unknown return code from the ELF loader (internal bug)";
      break;
     } 
     printf("Deluge: message: %s symbol: %s\n", printT, symbol);
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
