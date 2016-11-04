#include <stdio.h>

#include "contiki.h"
#include "cfs/cfs.h"
#include "deluge.h"
#include "node-id.h"
#include "loader/elfloader.h"
#include "dev/leds.h"
#include "dev/button-sensor.h"

#define DEBUG 0 /* Debug mode */
#if DEBUG
#define PRINTF(...) printf(__VA_ARGS__) /* */
#else
#define PRINTF(...) /* */
#endif

#ifndef SINK_ID
#define SINK_ID 1
#endif
PROCESS(deluge_simulation_process, "Deluge Simulation Process");
AUTOSTART_PROCESSES(&deluge_simulation_process);

PROCESS_THREAD(deluge_simulation_process, ev, data)
{
static int fd = -1;
static char *file = "hello-world.ce";
static int res = -1;
static char buf[256];
static struct etimer et;

PROCESS_BEGIN();
memset(buf, 0, sizeof(buf));
if ( node_id == SINK_ID ) {
do {
fd = cfs_open(file, CFS_READ);
printf("READ fd = %d\n", fd);
} while ( fd < 0 ); /* ----- end do-while ----- */
}
else {
do {
fd = cfs_open(file, CFS_WRITE|CFS_READ);
printf("WRITE fd = %d\n", fd);
} while ( fd < 0 ); /* ----- end do-while ----- */
}
cfs_close(fd);
SENSORS_ACTIVATE(button_sensor);
etimer_set(&et, CLOCK_SECOND*30);
PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
res = deluge_disseminate(file, node_id == SINK_ID);
printf( "res = %d\n", res);


SENSORS_ACTIVATE(button_sensor);
PROCESS_WAIT_EVENT_UNTIL(data == &button_sensor);

while ( fd < 0 ) {
fd = cfs_open(file, CFS_READ);
printf ( "fd = %d\n", fd );
PROCESS_YIELD();
}

elfloader_init();
if(elfloader_autostart_processes != NULL) {
autostart_exit(elfloader_autostart_processes);
}

fd = cfs_open(file, CFS_READ | CFS_WRITE);
if(fd < 0) {
printf ( "ERROR: cfs_open failed, fd=%d\n", fd);
} else {
int ret;
char *print, *symbol;

ret = elfloader_load(fd);
cfs_close(fd);
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
/*shell_output_str(&exec_command, print, symbol);*/
printf ( "elfloader result:%s, %s\n", print, symbol);

if(ret == ELFLOADER_OK) {
int i;
for(i = 0; elfloader_autostart_processes[i] != NULL; ++i) {
printf ( "elfloader starting: process %s \n",
elfloader_autostart_processes[i]->name );
/*shell_output_str(&exec_command, "exec: starting process ",*/
/*elfloader_autostart_processes[i]->name);*/
}
autostart_start(elfloader_autostart_processes);
}
}

PROCESS_END();
}