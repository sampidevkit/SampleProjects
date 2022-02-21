#include <16F18877.h>
#device ADC=10
#use delay(internal=8MHz)
#use FIXED_IO( A_outputs=PIN_A1 )
#use FIXED_IO( D_outputs=PIN_D0 )
#define BLED	PIN_A1
#define VSSEN   PIN_D0

#pin_select U1TX = PIN_B5
#pin_select U1RX = PIN_B4

#use rs232(baud=9600,parity=N,xmit=PIN_B5,rcv=PIN_B4,bits=8,stream=PORT1)

#define GRAPH_TITLE             "MCP9701 Thermal Graph"  
#define GRAPH_Y_TITLE           "Temperature"              
#define GRAPH_SERIES1_TITLE     "Samples"
#define GRAPH_X_MIN             "0"              
#define GRAPH_Y_MIN             "0"              
#define GRAPH_X_MAX             "10"            
#define GRAPH_Y_MAX             "100"            
#define GRAPH_X_SCALE           "1"            
#define GRAPH_Y_SCALE           "1"            
#define GRAPH_X_OFFSET          "0"           
#define GRAPH_Y_OFFSET          "0"           
#define GRAPH_X_DECIMAL_POINTS  "1"    
#define GRAPH_Y_DECIMAL_POINTS  "0"    

#include <graph_siow.h>
#include <stdint.h>