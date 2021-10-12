#include <16F877A.h>
#device ADC=10
#use delay(crystal=20MHz)
#use rs232(baud=9600, parity=N, xmit=PIN_C6, rcv=PIN_C7, bits=8, stream=PORT1)
#use timer(timer=1, tick=1ms, bits=32, NOISR)

#define TICK_PER_MS 1
#define tick_t unsigned long long

#include <stdint.h>