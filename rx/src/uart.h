#ifndef UART_H
#define UART_H
#include  <avr/interrupt.h>
#include  <util/delay.h>
#include  <avr/io.h>

#define FOSC 16000000 //Clock Speed
#ifndef BAUD
#define BAUD 9600
#endif

#define MYUBRR FOSC/16/BAUD-1

#ifndef F_CPU
#define F_CPU 16000000
#endif

void USART_Init(unsigned int ubrr);
void USART_Transmit(unsigned char data);
unsigned char USART_receive(void);
int test(void);

#endif
