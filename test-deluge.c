
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
#ifndef SYBIL_ID
#define SYBIL_ID 2
#endif
#ifndef FILE_SIZE
#define FILE_SIZE 1000
#endif

PROCESS(deluge_test_process, "Deluge test process");
AUTOSTART_PROCESSES(&deluge_test_process);

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(deluge_test_process, ev, data)
{

  char *file = "hello-world.ce";
  char *file2 = "hello-world2.ce";
  static struct etimer et;
  PROCESS_BEGIN();
 
  
  if(node_id == SINK_ID) {
   printf("Sink node: trying to transmit file.\n");
 } else if(node_id == 2){
    printf("Sybil attacking.\n");
 }else {
   printf("Non-sink node: trying to recieve file.\n");
 }

    
    char *print, *symbol;   
    // deluge_disseminate(file2, node_id == SYBIL_ID,node_id);
    deluge_disseminate(file, node_id == SINK_ID,node_id);
 
 etimer_set(&et, CLOCK_SECOND * 5);
 PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
 //etimer_reset(&et);
 /*
 if(node_id == SINK_ID ){
    int cfs_fd = cfs_open(file, CFS_READ | CFS_WRITE);
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
     if(loadResult != ELFLOADER_OK){
      printf("Deluge: message: %s symbol: %s\n", printT, symbolf);
     }
     
 }
  */
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
