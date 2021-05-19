#include "libcomp.h"

tick_timer_t Tick;
#define SET_POINT       37
// Saturation in PID task
#define UPPER_LIMIT     PWM1_MAX_DUTY
#define LOWER_LIMIT     0
// PID parameters
#define KP              125
#define KI              70
#define KD              70
#define SYS_GAIN        1
#define TS              1 // unit time

int32_t C0_k; // the current PID output
int32_t C0_k_1; // the previous PID output
int32_t E_k; // the current PID error
int32_t E_k_1; // the 1st previous PID error
int32_t E_k_2; // the 2nd previous PID error
const int32_t a=((2*KP)*SYS_GAIN+(KI*TS)*SYS_GAIN+(KD*SYS_GAIN)/TS); //(2*KP+KI*TS+KD/TS)*SYS_GAIN;
const int32_t b=((-2*KP)*SYS_GAIN+(KI*TS)*SYS_GAIN-((4*KD)*SYS_GAIN)/TS);//(-2*KP+KI*TS-(4*KD)/TS)*SYS_GAIN;
const int32_t c=((KD*SYS_GAIN)/TS);//(KD/TS)*SYS_GAIN;

int32_t Temperature_Read(void)
{
    int32_t tmp=ADC_GetValOnChannel(ADC_AN0);

    // Convert to temperature (10mV/C degree)
    tmp*=500;
    tmp*=SYS_GAIN;
    tmp/=1024;

    return tmp;
}

uint16_t PID_Task(int32_t Realpoint)
{
    int16_t rslt;
    __debug("\nReal=", Realpoint);
    // Calculate error
    E_k=SYS_GAIN*SET_POINT;
    E_k-=Realpoint;
    __debug("\nE_k=", E_k);
    // Calculate output
    //C0_k=(C0_k_1+a*E_k)+(b*E_k_1)+(c*E_k_2);
    C0_k=a;
    C0_k*=E_k;
    C0_k+=C0_k_1;

    C0_k_1=b;
    C0_k_1*=E_k_1;
    C0_k+=C0_k_1;

    C0_k_1=c;
    C0_k_1*=E_k_2;
    C0_k+=C0_k_1;

    // Backup current state
    E_k_2=E_k_1;
    E_k_1=E_k;
    C0_k_1=C0_k;
    C0_k/=SYS_GAIN;
    // Saturation
    __debug("\nC0_k=", C0_k);

    if(C0_k>UPPER_LIMIT)
        C0_k=UPPER_LIMIT;
    else if(C0_k<LOWER_LIMIT)
        C0_k=LOWER_LIMIT;

    rslt=(int16_t) (C0_k);
    __debug("\nrslt=", rslt);

    return (uint16_t) rslt;
}

void PID_Init(void)
{
    __debug("\na=", a);
    __debug("\nb=", b);
    __debug("\nc=", c);

    C0_k=0;
    C0_k_1=0;
    E_k=E_k_1=E_k_2=0;//SYS_GAIN*SET_POINT-Temperature_Read();
}

void main(void)
{
    // System initialize
    SYSTEM_Initialize();
    Tick_Timer_Init();
    // Application initialize
    DataLog_Init();
    PID_Init(); // PID setpoint initialize
    Tick_Timer_Reset(Tick);
    // Interrupt enable
    Enable_Peripheral_Interrupt();
    Enable_Global_Interrupt();

    while(1)
    {
        int32_t temp=Temperature_Read();

        if(Tick_Timer_Is_Over_Ms(Tick, 100))
            STT_LED_SetHigh();

        if(STT_LED_GetValue()==1)
        {
            uint16_t duty=PID_Task(temp);

            PWM1_LoadDutyValue(duty);
            Tick_Timer_Reset(Tick);
            Tick_Timer_Is_Over_Ms(Tick, 100);
            DataLog_Put2f(SET_POINT, temp/SYS_GAIN);
            STT_LED_SetLow();
            //DbWriteStr("\r\n");
        }

        DataLog_Task();
    }
}
