#include "libcomp.h"
#include "softevent.h"

static struct
{
    soft_event_t *pCxt;
    uint8_t Count;
} SoftEvent;

uint8_t SoftEvent(void) // <editor-fold defaultstate="collapsed" desc="Soft event">
{
    if(SoftEvent.pCxt!=NULL)
    {
        if(SoftEvent.pCxt->Fnc(SoftEvent.pCxt->Args))
        {
            SoftEvent.Count--;
        }

        SoftEvent.pCxt=SoftEvent.pCxt->Next;
        return SoftEvent.Count;
    }

    return 0;
} // </editor-fold>

void SoftEvent_Add(soft_event_t *pCxt) // <editor-fold defaultstate="collapsed" desc="Add an event">
{
    if(pCxt->Next==NULL)
    {
        pCxt->Next=SoftEvent.pCxt->Next;
        SoftEvent.pCxt->Next=pCxt;
        SoftEvent.Count++;
    }
} // </editor-fold>

void SoftEvent_Remove(soft_event_t *pCxt) // <editor-fold defaultstate="collapsed" desc="Remove an event">
{
    soft_event_t *p=SoftEvent.pCxt;

    while(p->Next!=pCxt)
    {
        p=p->Next;

        if(p==SoftEvent.pCxt) // no event
            return;
    }

    p=pCxt->Next;
    SoftEvent.Count--;
} // </editor-fold>

void SoftEvent_Init(void) // <editor-fold defaultstate="collapsed" desc="Init soft event">
{
    SoftEvent.Count=0;
    SoftEvent.pCxt=NULL;
} // </editor-fold>