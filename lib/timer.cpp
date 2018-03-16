#include "timer.h"

//setup timer1 to create variable-length delays
void initTimer1() {

  //set CTC mode
  TCCR1B |= (1 << WGM12);

  return;
}

//delays for specified number of miliseconds using timer 1
void delayMs(unsigned int delay){
  //pre-scalar of 8 chosen. This makes 1 us = 2 clock cycles.

  //set prescalar to 8
  TCCR1B |= (1 << CS11);

  //set comparison value to 2 * numMicroseconds
  OCR1A = 2 * delay;

  for (unsigned int i = 0; i < 1000; ++i) {
    //reset timer0
    TCNT1 = 0;

    //poll for flag
    while (!((TIFR1) & (1 << OCF1A))) {}

    //clear flag
    TIFR1 |= (1 << OCF1A);
  }

  return;
}