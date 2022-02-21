#ifndef GRAPH_SIOW_CFG_H
#define GRAPH_SIOW_CFG_H

#define graph_writebyte(c)      do{while(!EUSART_is_tx_ready()); EUSART_Write(c);}while(0)
#define GRAPH_TITLE             "MCP9701 THERMAL SENSOR"
#define GRAPH_SERIES1_TITLE     "Series 1"
#define GRAPH_Y_TITLE           "Temperature"
#define GRAPH_X_MIN             "0"
#define GRAPH_Y_MIN             "0"
#define GRAPH_X_MAX             "100"
#define GRAPH_Y_MAX             "150"
#define GRAPH_X_SCALE           "1"
#define GRAPH_Y_SCALE           "1"
#define GRAPH_X_OFFSET          "0"
#define GRAPH_Y_OFFSET          "0"
#define GRAPH_X_DECIMAL_POINTS  "0"
#define GRAPH_Y_DECIMAL_POINTS  "0"

#endif