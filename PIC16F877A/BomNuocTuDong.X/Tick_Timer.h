#ifndef TICK_TIMER_H
#define	TICK_TIMER_H
#include <stdbool.h>
#include <stdint.h>

#define Tick_Reset(x)                   x.timeout=1
#define TICK_PER_MS                     4000
#define TMR1_INTERRUPT_TICKER_FACTOR    16384

typedef struct
{
    bool timeout;
    uint32_t start;
    uint32_t stop;
} tick_timer_t;

volatile uint16_t count=0;

#INT_TIMER1
void TMR1_ISR(void)
{
    count++;
    if(count>=TMR1_INTERRUPT_TICKER_FACTOR) count=0;
}

bool Tick_Is_Over(tick_timer_t *tick, uint32_t ms)
{
    uint32_t pre=count;
    pre<<=16;
    pre|=get_timer1();
    pre<<=2;
    if(tick->timeout)
    {
        tick->start=pre;
        tick->stop=tick->start+ms*TICK_PER_MS;
    }
    if(tick->stop>tick->start) tick->timeout=(tick->stop<pre);
    else tick->timeout=((tick->stop<pre)&&(pre<tick->start));
    
    return tick->timeout;
}

void Tick_Init(void)
{
    setup_timer_1(T1_INTERNAL|T1_DIV_BY_4);//Ftimer=1MHz
    set_timer1(0);
    enable_interrupts(INT_TIMER1);
    enable_interrupts(PERIPH);
    enable_interrupts(GLOBAL);
}

#endif