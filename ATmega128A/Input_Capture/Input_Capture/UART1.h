/*
 * UART1.h
 *
 * Created: 2018-03-21 오후 5:01:36
 *  Author: dsm2017
 */ 


#ifndef UART1_H_
#define UART1_H_

void UART1_init(void);
void UART1_transmit(char data);
unsigned char UART1_receive(void);
void UART1_print_string(char *str);
void UART1_print_1_byte_number(uint8_t n);

#endif /* UART1_H_ */