#include "loader/symbols.h"

extern int abc_close();
extern int abc_input();
extern int abc_open();
extern int abc_send();
extern int abc_sent();
extern int announcement_heard();
extern int announcement_init();
extern int announcement_list();
extern int announcement_register_observer_callback();
extern int autostart_exit();
extern int autostart_processes();
extern int autostart_start();
extern int broadcast_announcement_init();
extern int broadcast_close();
extern int broadcast_open();
extern int broadcast_send();
extern int button_sensor();
extern int cc2420_arch_init();
extern int cc2420_authority_level_of_sender();
extern int cc2420_driver();
extern int cc2420_get_txpower();
extern int cc2420_init();
extern int cc2420_interrupt();
extern int cc2420_last_correlation();
extern int cc2420_last_rssi();
extern int cc2420_off();
extern int cc2420_on();
extern int cc2420_packets_read();
extern int cc2420_packets_seen();
extern int cc2420_port1_interrupt();
extern int cc2420_process();
extern int cc2420_set_cca_threshold();
extern int cc2420_set_channel();
extern int cc2420_set_pan_addr();
extern int cc2420_sfd_counter();
extern int cc2420_sfd_end_time();
extern int cc2420_sfd_start_time();
extern int cc2420_time_of_arrival();
extern int cc2420_time_of_departure();
extern int cfs_close();
extern int cfs_open();
extern int cfs_read();
extern int cfs_seek();
extern int cfs_write();
extern int chameleon_bitopt();
extern int chameleon_create();
extern int chameleon_hdrsize();
extern int chameleon_init();
extern int chameleon_parse();
extern int channel_close();
extern int channel_init();
extern int channel_lookup();
extern int channel_open();
extern int channel_set_attributes();
extern int clock_delay();
extern int clock_init();
extern int clock_time();
extern int compower_accumulate();
extern int compower_attrconv();
extern int compower_clear();
extern int compower_idle_activity();
extern int contikimac_driver();
extern int crc16_add();
extern int crc16_data();
extern int csma_driver();
extern int ctimer_expired();
extern int ctimer_init();
extern int ctimer_process();
extern int ctimer_reset();
extern int ctimer_set();
extern int ctimer_stop();
extern char* deluge_disseminate();
extern int deluge_process();
extern int deluge_test_process();
extern int ds2411_id();
extern int ds2411_init();
extern int elfloader_arch_allocate_ram();
extern int elfloader_arch_allocate_rom();
extern int elfloader_arch_relocate();
extern int elfloader_arch_write_rom();
extern int elfloader_autostart_processes();
extern int elfloader_load();
extern int elfloader_unknown();
extern int energest_current_mode();
extern int energest_current_time();
extern int energest_flush();
extern int energest_init();
extern int energest_total_count();
extern int energest_total_time();
extern int energest_type_set();
extern int energest_type_time();
extern int etimer_expired();
extern int etimer_next_expiration_time();
extern int etimer_pending();
extern int etimer_process();
extern int etimer_request_poll();
extern int etimer_reset();
extern int etimer_set();
extern int etimer_stop();
extern int frame802154_create();
extern int frame802154_hdrlen();
extern int frame802154_parse();
extern int framer_802154();
extern int free();
extern int get_bits();
extern int get_bits_in_byte();
extern int init_platform();
extern int irq_p2();
extern int leds_arch_init();
extern int leds_arch_set();
extern int leds_init();
extern int leds_off();
extern int leds_on();
extern int list_add();
extern int list_head();
extern int list_init();
extern int list_item_next();
extern int list_length();
extern int list_push();
extern int list_remove();
extern int list_tail();
extern int mac_call_sent_callback();
extern int main();
void *malloc();
extern int memb_alloc();
extern int memb_free();
extern int memb_init();
extern int memb_inmemb();
extern int memcmp();
void *memcpy();
void *memset();
extern int msp430_add_lpm_req();
extern int msp430_cpu_init();
extern int msp430_dco_required();
extern int msp430_init_dco();
extern int msp430_sync_dco();
extern int nbr_table_add_lladdr();
extern int nbr_table_get_from_lladdr();
extern int nbr_table_register();
extern int nbr_table_remove();
extern int node_id();
extern int node_id_restore();
extern int packetbuf_addrs();
extern int packetbuf_attr_clear();
extern int packetbuf_attr_copyfrom();
extern int packetbuf_attr_copyto();
extern int packetbuf_attrs();
extern int packetbuf_clear();
extern int packetbuf_compact();
extern int packetbuf_copyfrom();
extern int packetbuf_copyto();
extern int packetbuf_copyto_hdr();
extern int packetbuf_datalen();
extern int packetbuf_dataptr();
extern int packetbuf_hdr_remove();
extern int packetbuf_hdralloc();
extern int packetbuf_hdrptr();
extern int packetbuf_hdrreduce();
extern int packetbuf_is_reference();
extern int packetbuf_reference_ptr();
extern int packetbuf_set_datalen();
extern int packetbuf_totlen();
extern int phase_init();
extern int phase_update();
extern int phase_wait();
int printf(const char *, ...);
extern int process_alloc_event();
extern int process_current();
extern int process_exit();
extern int process_init();
extern int process_list();
extern int process_maxevents();
extern int process_nevents();
extern int process_poll();
extern int process_post();
extern int process_post_synch();
extern int process_run();
extern int process_start();
extern int putchar();
extern int puts();
extern int queuebuf_attr();
extern int queuebuf_free();
extern int queuebuf_init();
extern int queuebuf_new_from_packetbuf();
extern int queuebuf_to_packetbuf();
extern int queuebuf_update_attr_from_packetbuf();
extern int rand();
extern int random_init();
extern int random_rand();
extern int rime_driver();
extern int rime_output();
extern int rimeaddr_cmp();
extern int rimeaddr_copy();
extern int rimeaddr_node_addr();
extern int rimeaddr_null();
extern int rimeaddr_set_node_addr();
extern int ringbuf_get();
extern int ringbuf_init();
extern int ringbuf_put();
extern int rtimer_arch_init();
extern int rtimer_arch_now();
extern int rtimer_arch_schedule();
extern int rtimer_init();
extern int rtimer_run_next();
extern int rtimer_set();
extern int sensors();
extern int sensors_changed();
extern int sensors_event();
extern int sensors_flags();
extern int sensors_process();
extern int serial_line_event_message();
extern int serial_line_init();
extern int serial_line_input_byte();
extern int serial_line_process();
extern int set_bits();
extern int set_bits_in_byte();
extern int spi_init();
extern int splhigh_();
extern int srand();
extern int strcmp();
char *strcpy();
extern int strncmp();
extern int symtab_lookup();
extern int timer_expired();
extern int timer_reset();
extern int timer_set();
extern int timera0();
extern int timera1();
extern int uart1_active();
extern int uart1_init();
extern int uart1_set_input();
extern int uart1_writeb();
extern int unicast_close();
extern int unicast_open();
extern int unicast_send();
extern int vuprintf();
extern int watchdog_init();
extern int watchdog_interrupt();
extern int watchdog_periodic();
extern int watchdog_start();
extern int watchdog_stop();
extern int xmem_erase();
extern int xmem_init();
extern int xmem_pread();
extern int xmem_pwrite();


const int symbols_nelts = 246;
const struct symbols symbols[246] = {
{ "abc_close", (void *)&abc_close },
{ "abc_input", (void *)&abc_input },
{ "abc_open", (void *)&abc_open },
{ "abc_send", (void *)&abc_send },
{ "abc_sent", (void *)&abc_sent },
{ "announcement_heard", (void *)&announcement_heard },
{ "announcement_init", (void *)&announcement_init },
{ "announcement_list", (void *)&announcement_list },
{ "announcement_register_observer_callback", (void *)&announcement_register_observer_callback },
{ "autostart_exit", (void *)&autostart_exit },
{ "autostart_processes", (void *)&autostart_processes },
{ "autostart_start", (void *)&autostart_start },
{ "broadcast_announcement_init", (void *)&broadcast_announcement_init },
{ "broadcast_close", (void *)&broadcast_close },
{ "broadcast_open", (void *)&broadcast_open },
{ "broadcast_send", (void *)&broadcast_send },
{ "button_sensor", (void *)&button_sensor },
{ "cc2420_arch_init", (void *)&cc2420_arch_init },
{ "cc2420_authority_level_of_sender", (void *)&cc2420_authority_level_of_sender },
{ "cc2420_driver", (void *)&cc2420_driver },
{ "cc2420_get_txpower", (void *)&cc2420_get_txpower },
{ "cc2420_init", (void *)&cc2420_init },
{ "cc2420_interrupt", (void *)&cc2420_interrupt },
{ "cc2420_last_correlation", (void *)&cc2420_last_correlation },
{ "cc2420_last_rssi", (void *)&cc2420_last_rssi },
{ "cc2420_off", (void *)&cc2420_off },
{ "cc2420_on", (void *)&cc2420_on },
{ "cc2420_packets_read", (void *)&cc2420_packets_read },
{ "cc2420_packets_seen", (void *)&cc2420_packets_seen },
{ "cc2420_port1_interrupt", (void *)&cc2420_port1_interrupt },
{ "cc2420_process", (void *)&cc2420_process },
{ "cc2420_set_cca_threshold", (void *)&cc2420_set_cca_threshold },
{ "cc2420_set_channel", (void *)&cc2420_set_channel },
{ "cc2420_set_pan_addr", (void *)&cc2420_set_pan_addr },
{ "cc2420_sfd_counter", (void *)&cc2420_sfd_counter },
{ "cc2420_sfd_end_time", (void *)&cc2420_sfd_end_time },
{ "cc2420_sfd_start_time", (void *)&cc2420_sfd_start_time },
{ "cc2420_time_of_arrival", (void *)&cc2420_time_of_arrival },
{ "cc2420_time_of_departure", (void *)&cc2420_time_of_departure },
{ "cfs_close", (void *)&cfs_close },
{ "cfs_open", (void *)&cfs_open },
{ "cfs_read", (void *)&cfs_read },
{ "cfs_seek", (void *)&cfs_seek },
{ "cfs_write", (void *)&cfs_write },
{ "chameleon_bitopt", (void *)&chameleon_bitopt },
{ "chameleon_create", (void *)&chameleon_create },
{ "chameleon_hdrsize", (void *)&chameleon_hdrsize },
{ "chameleon_init", (void *)&chameleon_init },
{ "chameleon_parse", (void *)&chameleon_parse },
{ "channel_close", (void *)&channel_close },
{ "channel_init", (void *)&channel_init },
{ "channel_lookup", (void *)&channel_lookup },
{ "channel_open", (void *)&channel_open },
{ "channel_set_attributes", (void *)&channel_set_attributes },
{ "clock_delay", (void *)&clock_delay },
{ "clock_init", (void *)&clock_init },
{ "clock_time", (void *)&clock_time },
{ "compower_accumulate", (void *)&compower_accumulate },
{ "compower_attrconv", (void *)&compower_attrconv },
{ "compower_clear", (void *)&compower_clear },
{ "compower_idle_activity", (void *)&compower_idle_activity },
{ "contikimac_driver", (void *)&contikimac_driver },
{ "crc16_add", (void *)&crc16_add },
{ "crc16_data", (void *)&crc16_data },
{ "csma_driver", (void *)&csma_driver },
{ "ctimer_expired", (void *)&ctimer_expired },
{ "ctimer_init", (void *)&ctimer_init },
{ "ctimer_process", (void *)&ctimer_process },
{ "ctimer_reset", (void *)&ctimer_reset },
{ "ctimer_set", (void *)&ctimer_set },
{ "ctimer_stop", (void *)&ctimer_stop },
{ "deluge_disseminate", (void *)&deluge_disseminate },
{ "deluge_process", (void *)&deluge_process },
{ "deluge_test_process", (void *)&deluge_test_process },
{ "ds2411_id", (void *)&ds2411_id },
{ "ds2411_init", (void *)&ds2411_init },
{ "elfloader_arch_allocate_ram", (void *)&elfloader_arch_allocate_ram },
{ "elfloader_arch_allocate_rom", (void *)&elfloader_arch_allocate_rom },
{ "elfloader_arch_relocate", (void *)&elfloader_arch_relocate },
{ "elfloader_arch_write_rom", (void *)&elfloader_arch_write_rom },
{ "elfloader_autostart_processes", (void *)&elfloader_autostart_processes },
{ "elfloader_load", (void *)&elfloader_load },
{ "elfloader_unknown", (void *)&elfloader_unknown },
{ "energest_current_mode", (void *)&energest_current_mode },
{ "energest_current_time", (void *)&energest_current_time },
{ "energest_flush", (void *)&energest_flush },
{ "energest_init", (void *)&energest_init },
{ "energest_total_count", (void *)&energest_total_count },
{ "energest_total_time", (void *)&energest_total_time },
{ "energest_type_set", (void *)&energest_type_set },
{ "energest_type_time", (void *)&energest_type_time },
{ "etimer_expired", (void *)&etimer_expired },
{ "etimer_next_expiration_time", (void *)&etimer_next_expiration_time },
{ "etimer_pending", (void *)&etimer_pending },
{ "etimer_process", (void *)&etimer_process },
{ "etimer_request_poll", (void *)&etimer_request_poll },
{ "etimer_reset", (void *)&etimer_reset },
{ "etimer_set", (void *)&etimer_set },
{ "etimer_stop", (void *)&etimer_stop },
{ "frame802154_create", (void *)&frame802154_create },
{ "frame802154_hdrlen", (void *)&frame802154_hdrlen },
{ "frame802154_parse", (void *)&frame802154_parse },
{ "framer_802154", (void *)&framer_802154 },
{ "free", (void *)&free },
{ "get_bits", (void *)&get_bits },
{ "get_bits_in_byte", (void *)&get_bits_in_byte },
{ "init_platform", (void *)&init_platform },
{ "irq_p2", (void *)&irq_p2 },
{ "leds_arch_init", (void *)&leds_arch_init },
{ "leds_arch_set", (void *)&leds_arch_set },
{ "leds_init", (void *)&leds_init },
{ "leds_off", (void *)&leds_off },
{ "leds_on", (void *)&leds_on },
{ "list_add", (void *)&list_add },
{ "list_head", (void *)&list_head },
{ "list_init", (void *)&list_init },
{ "list_item_next", (void *)&list_item_next },
{ "list_length", (void *)&list_length },
{ "list_push", (void *)&list_push },
{ "list_remove", (void *)&list_remove },
{ "list_tail", (void *)&list_tail },
{ "mac_call_sent_callback", (void *)&mac_call_sent_callback },
{ "main", (void *)&main },
{ "malloc", (void *)&malloc },
{ "memb_alloc", (void *)&memb_alloc },
{ "memb_free", (void *)&memb_free },
{ "memb_init", (void *)&memb_init },
{ "memb_inmemb", (void *)&memb_inmemb },
{ "memcmp", (void *)&memcmp },
{ "memcpy", (void *)&memcpy },
{ "memset", (void *)&memset },
{ "msp430_add_lpm_req", (void *)&msp430_add_lpm_req },
{ "msp430_cpu_init", (void *)&msp430_cpu_init },
{ "msp430_dco_required", (void *)&msp430_dco_required },
{ "msp430_init_dco", (void *)&msp430_init_dco },
{ "msp430_sync_dco", (void *)&msp430_sync_dco },
{ "nbr_table_add_lladdr", (void *)&nbr_table_add_lladdr },
{ "nbr_table_get_from_lladdr", (void *)&nbr_table_get_from_lladdr },
{ "nbr_table_register", (void *)&nbr_table_register },
{ "nbr_table_remove", (void *)&nbr_table_remove },
{ "node_id", (void *)&node_id },
{ "node_id_restore", (void *)&node_id_restore },
{ "packetbuf_addrs", (void *)&packetbuf_addrs },
{ "packetbuf_attr_clear", (void *)&packetbuf_attr_clear },
{ "packetbuf_attr_copyfrom", (void *)&packetbuf_attr_copyfrom },
{ "packetbuf_attr_copyto", (void *)&packetbuf_attr_copyto },
{ "packetbuf_attrs", (void *)&packetbuf_attrs },
{ "packetbuf_clear", (void *)&packetbuf_clear },
{ "packetbuf_compact", (void *)&packetbuf_compact },
{ "packetbuf_copyfrom", (void *)&packetbuf_copyfrom },
{ "packetbuf_copyto", (void *)&packetbuf_copyto },
{ "packetbuf_copyto_hdr", (void *)&packetbuf_copyto_hdr },
{ "packetbuf_datalen", (void *)&packetbuf_datalen },
{ "packetbuf_dataptr", (void *)&packetbuf_dataptr },
{ "packetbuf_hdr_remove", (void *)&packetbuf_hdr_remove },
{ "packetbuf_hdralloc", (void *)&packetbuf_hdralloc },
{ "packetbuf_hdrptr", (void *)&packetbuf_hdrptr },
{ "packetbuf_hdrreduce", (void *)&packetbuf_hdrreduce },
{ "packetbuf_is_reference", (void *)&packetbuf_is_reference },
{ "packetbuf_reference_ptr", (void *)&packetbuf_reference_ptr },
{ "packetbuf_set_datalen", (void *)&packetbuf_set_datalen },
{ "packetbuf_totlen", (void *)&packetbuf_totlen },
{ "phase_init", (void *)&phase_init },
{ "phase_update", (void *)&phase_update },
{ "phase_wait", (void *)&phase_wait },
{ "printf", (void *)&printf },
{ "process_alloc_event", (void *)&process_alloc_event },
{ "process_current", (void *)&process_current },
{ "process_exit", (void *)&process_exit },
{ "process_init", (void *)&process_init },
{ "process_list", (void *)&process_list },
{ "process_maxevents", (void *)&process_maxevents },
{ "process_nevents", (void *)&process_nevents },
{ "process_poll", (void *)&process_poll },
{ "process_post", (void *)&process_post },
{ "process_post_synch", (void *)&process_post_synch },
{ "process_run", (void *)&process_run },
{ "process_start", (void *)&process_start },
{ "putchar", (void *)&putchar },
{ "puts", (void *)&puts },
{ "queuebuf_attr", (void *)&queuebuf_attr },
{ "queuebuf_free", (void *)&queuebuf_free },
{ "queuebuf_init", (void *)&queuebuf_init },
{ "queuebuf_new_from_packetbuf", (void *)&queuebuf_new_from_packetbuf },
{ "queuebuf_to_packetbuf", (void *)&queuebuf_to_packetbuf },
{ "queuebuf_update_attr_from_packetbuf", (void *)&queuebuf_update_attr_from_packetbuf },
{ "rand", (void *)&rand },
{ "random_init", (void *)&random_init },
{ "random_rand", (void *)&random_rand },
{ "rime_driver", (void *)&rime_driver },
{ "rime_output", (void *)&rime_output },
{ "rimeaddr_cmp", (void *)&rimeaddr_cmp },
{ "rimeaddr_copy", (void *)&rimeaddr_copy },
{ "rimeaddr_node_addr", (void *)&rimeaddr_node_addr },
{ "rimeaddr_null", (void *)&rimeaddr_null },
{ "rimeaddr_set_node_addr", (void *)&rimeaddr_set_node_addr },
{ "ringbuf_get", (void *)&ringbuf_get },
{ "ringbuf_init", (void *)&ringbuf_init },
{ "ringbuf_put", (void *)&ringbuf_put },
{ "rtimer_arch_init", (void *)&rtimer_arch_init },
{ "rtimer_arch_now", (void *)&rtimer_arch_now },
{ "rtimer_arch_schedule", (void *)&rtimer_arch_schedule },
{ "rtimer_init", (void *)&rtimer_init },
{ "rtimer_run_next", (void *)&rtimer_run_next },
{ "rtimer_set", (void *)&rtimer_set },
{ "sensors", (void *)&sensors },
{ "sensors_changed", (void *)&sensors_changed },
{ "sensors_event", (void *)&sensors_event },
{ "sensors_flags", (void *)&sensors_flags },
{ "sensors_process", (void *)&sensors_process },
{ "serial_line_event_message", (void *)&serial_line_event_message },
{ "serial_line_init", (void *)&serial_line_init },
{ "serial_line_input_byte", (void *)&serial_line_input_byte },
{ "serial_line_process", (void *)&serial_line_process },
{ "set_bits", (void *)&set_bits },
{ "set_bits_in_byte", (void *)&set_bits_in_byte },
{ "spi_init", (void *)&spi_init },
{ "splhigh_", (void *)&splhigh_ },
{ "srand", (void *)&srand },
{ "strcmp", (void *)&strcmp },
{ "strcpy", (void *)&strcpy },
{ "strncmp", (void *)&strncmp },
{ "symtab_lookup", (void *)&symtab_lookup },
{ "timer_expired", (void *)&timer_expired },
{ "timer_reset", (void *)&timer_reset },
{ "timer_set", (void *)&timer_set },
{ "timera0", (void *)&timera0 },
{ "timera1", (void *)&timera1 },
{ "uart1_active", (void *)&uart1_active },
{ "uart1_init", (void *)&uart1_init },
{ "uart1_set_input", (void *)&uart1_set_input },
{ "uart1_writeb", (void *)&uart1_writeb },
{ "unicast_close", (void *)&unicast_close },
{ "unicast_open", (void *)&unicast_open },
{ "unicast_send", (void *)&unicast_send },
{ "vuprintf", (void *)&vuprintf },
{ "watchdog_init", (void *)&watchdog_init },
{ "watchdog_interrupt", (void *)&watchdog_interrupt },
{ "watchdog_periodic", (void *)&watchdog_periodic },
{ "watchdog_start", (void *)&watchdog_start },
{ "watchdog_stop", (void *)&watchdog_stop },
{ "xmem_erase", (void *)&xmem_erase },
{ "xmem_init", (void *)&xmem_init },
{ "xmem_pread", (void *)&xmem_pread },
{ "xmem_pwrite", (void *)&xmem_pwrite },
{ (const char *)0, (void *)0} };
