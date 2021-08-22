#ifdef USE_LED_7SEG_CA
#ifdef USER_LED_7SEG_CA
const unsigned int8 Led7SegCode[]={USE_LED_7SEG_CA};
#else
/* Bit 0: segment A
 * Bit 1: segment B
 * Bit 1: segment C
 * Bit 1: segment D
 * Bit 1: segment E
 * Bit 1: segment F
 * Bit 1: segment G
 * Bit 1: segment H */
const unsigned int8 Led7SegCode[]={
    0xC0, // 0
    0xF9, // 1
    0xA4, // 2
    0xB0, // 3
    0x99, // 4
    0x92, // 5
    0x82, // 6
    0xD8, // 7
    0x80, // 8
    0x90, // 9
    0x88, // A
    0x83, // b
    0xC6, // c
    0xA1, // d
    0x86, // E
    0x8E, // F
    0x7F, // .
    0xBF, // -
    0xB7, // =
    0xFF, // Off all segments
    0x00 // On all segments
};
#endif
#endif

#ifdef USE_LED_7SEG_CC
#ifdef USER_LED_7SEG_CC
const unsigned int8 Led7SegCode[]={USE_LED_7SEG_CC};
#else
/* Bit 0: segment A
 * Bit 1: segment B
 * Bit 1: segment C
 * Bit 1: segment D
 * Bit 1: segment E
 * Bit 1: segment F
 * Bit 1: segment G
 * Bit 1: segment H */
const unsigned int8 Led7SegCode[]={
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x27, // 7
    0x7F, // 8
    0x6F, // 9
    0x77, // A
    0x7C, // b
    0x39, // c
    0x5E, // d
    0x79, // E
    0x71, // F
    0x80, // .
    0x40, // -
    0X48, // =
    0x00, // Off all segments
    0xFF // On all segments
};
#endif
#endif

static volatile unsigned int8 DigitIdx=0;
static volatile unsigned int8 Led7SegBuf[NUM_OF_7SEG_DIGIT];
static volatile unsigned int8 Led7SegBufMask1[NUM_OF_7SEG_DIGIT];
static volatile unsigned int8 Led7SegBufMask2[NUM_OF_7SEG_DIGIT];
static volatile unsigned int8 ToggleCount=0;

void Led7Seg_Tasks(void) // <editor-fold defaultstate="collapsed" desc="7-segment Led tasks">
{
    Led7Seg_Digit_Disable(); // Off all digits
    Led7Seg_Segment_Disable(); // Off all segments

    if(DigitIdx>=NUM_OF_7SEG_DIGIT)
        DigitIdx=0;

    if(++ToggleCount>=LED_7SEG_TOGGLE_COUNT)
    {
        unsigned int8 i;

        for(i=0; i<NUM_OF_7SEG_DIGIT; i++)
        {
            if(Led7SegBufMask1[i]!=Led7SegBufMask2[i])
            {
                unsigned int8 tmp;

                tmp=Led7SegBufMask1[i];
                Led7SegBufMask1[i]=Led7SegBufMask2[i];
                Led7SegBufMask2[i]=tmp;
            }
        }

        ToggleCount=0;
    }

#ifdef USE_LED_7SEG_CC
    Led7Seg_Segment_SetState(Led7SegBuf[DigitIdx]&Led7SegBufMask1[DigitIdx]);
#else
    Led7Seg_Segment_SetState(Led7SegBuf[DigitIdx]|Led7SegBufMask1[DigitIdx]);
#endif

    Led7Seg_Digit_SetState(DigitIdx++);
} // </editor-fold>

void Led7Seg_SetDigitValue(unsigned int8 DgIdx, unsigned int8 Value) // <editor-fold defaultstate="collapsed" desc="Set digit value">
{
    if(DgIdx>=NUM_OF_7SEG_DIGIT)
        return;

    Led7SegBuf[DgIdx]=Value;
} // </editor-fold>

void Led7Seg_DisplayInteger(unsigned int32 Value) // <editor-fold defaultstate="collapsed" desc="Display integer">
{
    unsigned int8 i, j;

    j=(NUM_OF_7SEG_DIGIT-1);

    for(i=0; i<NUM_OF_7SEG_DIGIT; i++)
    {
        Led7SegBuf[j]=Led7SegCode[(unsigned int8) (Value%10)];
        Value/=10;
        j--;
    }

    for(i=0; i<NUM_OF_7SEG_DIGIT; i++)
    {
        if(Led7SegBuf[i]==Led7SegCode[0])
        {
            if(i<(NUM_OF_7SEG_DIGIT-1))
                Led7SegBuf[i]=Led7SegCode[19];
        }
        else
            break;
    }
} // </editor-fold>

void Led7Seg_DisplayFloat(unsigned int32 Value, unsigned int8 DotIdx) // <editor-fold defaultstate="collapsed" desc="Display float">
{
    if((DotIdx==0)||(DotIdx>=NUM_OF_7SEG_DIGIT))
        return;

    Led7Seg_DisplayInteger(Value);

#ifdef USE_LED_7SEG_CC
    Led7SegBuf[DotIdx]|=Led7SegCode[16];
#else
    Led7SegBuf[DotIdx]&=Led7SegCode[16];
#endif
} // </editor-fold>

void Led7Seg_DisplayTime(unsigned int8 HH, unsigned int8 MM, unsigned int8 SS) // <editor-fold defaultstate="collapsed" desc="Diplay time">
{
    Led7SegBuf[0]=Led7SegCode[HH/10];

#ifndef LED7SEG_FULL_DISPLAYTIME
    if(Led7SegBuf[0]==Led7SegCode[0])
        Led7SegBuf[0]=Led7SegCode[19]; // Off
#endif

    Led7SegBuf[1]=Led7SegCode[HH%10];
    Led7SegBuf[2]=Led7SegCode[MM/10];
    Led7SegBuf[3]=Led7SegCode[MM%10];

#if(NUM_OF_7SEG_DIGIT>=6)
    Led7SegBuf[4]=Led7SegCode[SS/10];
    Led7SegBuf[5]=Led7SegCode[SS%10];
#endif
} // </editor-fold>

void Led7Seg_DigitToggleEnable(unsigned int8 DgIdx) // <editor-fold defaultstate="collapsed" desc="Digit toggle enable">
{
    Led7SegBufMask1[DgIdx]=Led7SegCode[19];
    Led7SegBufMask2[DgIdx]=Led7SegCode[20];
} // </editor-fold>

void Led7Seg_DigitToggleDisable(unsigned int8 DgIdx) // <editor-fold defaultstate="collapsed" desc="Digit toggle disable">
{
    Led7SegBufMask1[DgIdx]=Led7SegCode[20];
    Led7SegBufMask2[DgIdx]=Led7SegCode[20];
} // </editor-fold>

void Led7Seg_Init(void) // <editor-fold defaultstate="collapsed" desc="7-segment Led initialize">
{
    memset((void *) Led7SegBuf, Led7SegCode[19], NUM_OF_7SEG_DIGIT);
    memset((void *) Led7SegBufMask1, Led7SegCode[20], NUM_OF_7SEG_DIGIT);
    memset((void *) Led7SegBufMask2, Led7SegCode[20], NUM_OF_7SEG_DIGIT);
    DigitIdx=0;
    ToggleCount=0;
} // </editor-fold>

void Led7Seg_DeInit(void) // <editor-fold defaultstate="collapsed" desc="7-segment Led deinitialize">
{
    Led7Seg_Digit_Disable();
    Led7Seg_Segment_Disable();
} // </editor-fold>