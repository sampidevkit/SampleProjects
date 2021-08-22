#ifndef SOFTEVENT_H
#define SOFTEVENT_H

#include <stdint.h>
#include <stdbool.h>

typedef bool(*soft_event_fnc_t)(void *);

typedef struct SOFT_EVENT
{
    soft_event_fnc_t Fnc;
    void *Args;
    struct SOFT_EVENT *Next;
} soft_event_t;

uint8_t SoftEvent(void);
void SoftEvent_Add(soft_event_t *pCxt);
void SoftEvent_Remove(soft_event_t *pCxt);
void SoftEvent_Init(void);

#endif