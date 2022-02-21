///////////////////////////////////////////////////////////////////////////
////   Library for using SIOW to display graphs                        ////
////                                                                   ////
////   init_graph(maxX,maxY); Call first with max X and Y              ////
////           optional #defines that may appear before the init call: ////
////              #define GRAPH_TITLE   "Sample Graph"                 ////
////              #define GRAPH_Y_TITLE ""                             ////
////              #define GRAPH_SERIES1_TITLE "Series 1"               ////
////              #define GRAPH_SERIES2_TITLE "Series 2"               ////
////              #define GRAPH_SERIES3_TITLE "Series 3"               ////
////              #define GRAPH_SERIES4_TITLE "Series 4"               ////
////              #define GRAPH_X_MIN  "0"                             ////
////              #define GRAPH_Y_MIN  "0"                             ////
////              #define GRAPH_X_MAX  "255"                           ////
////              #define GRAPH_Y_MAX  "255"                           ////
////              #define GRAPH_X_SCALE  "1"                           ////
////              #define GRAPH_Y_SCALE  "1"                           ////
////              #define GRAPH_X_OFFSET  "0"                          ////
////              #define GRAPH_Y_OFFSET  "0"                          ////
////              #define GRAPH_X_DECIMAL_POINTS "0"                   ////
////              #define GRAPH_Y_DECIMAL_POINTS "0"                   ////
////                                                                   ////
////   graph_point(y);       Draws a line to this y point using the    ////
////                         next sequential x position                ////
////                                                                   ////
////   graph_points2(y1,y2); Same as graph_point() for 2 series graphs ////
////                         You must define GRAPH_SERIES2_TITLE       ////
////   graph_points3(y1,y2); Same as graph_point() for 3 series graphs ////
////                         You must define GRAPH_SERIES3_TITLE       ////
////   graph_points4(y1,y2); Same as graph_point() for 4 series graphs ////
////                         You must define GRAPH_SERIES4_TITLE       ////
////                                                                   ////
////   graph_clear();        Clears the graph                          ////
////                                                                   ////
////   graph_pause( );       Stops all graphing                        ////
////                                                                   ////
////   graph_restart();      Continues graphing                        ////
////                                                                   ////
////                                                                   ////
///////////////////////////////////////////////////////////////////////////
////        (C) Copyright 2013      Custom Computer Services           ////
//// This source code may only be used by licensed users of the CCS C  ////
//// compiler.  This source code may only be distributed to other      ////
//// licensed users of the CCS C compiler.  No other use, reproduction ////
//// or distribution is permitted without written permission.          ////
//// Derivative programs created using this software in object code    ////
//// form are not restricted in any way.                               ////
///////////////////////////////////////////////////////////////////////////

#ifndef GRAPH_SIOW_H
#define GRAPH_SIOW_H

#include <stdint.h>
#include "graph_siow_cfg.h"

#ifndef GRAPH_TITLE
#define GRAPH_TITLE   "Sample Graph"
#endif

#ifndef GRAPH_SERIES1_TITLE
#define GRAPH_SERIES1_TITLE "Series 1"
#endif

#ifndef GRAPH_Y_TITLE
#define GRAPH_Y_TITLE ""
#endif

#ifndef GRAPH_X_MIN
#define GRAPH_X_MIN  "0"
#endif

#ifndef GRAPH_Y_MIN
#define GRAPH_Y_MIN  "0"
#endif

#ifndef GRAPH_X_MAX
#define GRAPH_X_MAX  "255"
#endif

#ifndef GRAPH_Y_MAX
#define GRAPH_Y_MAX  "255"
#endif

#ifndef GRAPH_X_SCALE
#define GRAPH_X_SCALE  "1"
#endif

#ifndef GRAPH_Y_SCALE
#define GRAPH_Y_SCALE  "1"
#endif

#ifndef GRAPH_X_OFFSET
#define GRAPH_X_OFFSET  "0"
#endif

#ifndef GRAPH_Y_OFFSET
#define GRAPH_Y_OFFSET  "0"
#endif

#ifndef GRAPH_X_DECIMAL_POINTS
#define GRAPH_X_DECIMAL_POINTS  "0"
#endif

#ifndef GRAPH_Y_DECIMAL_POINTS
#define GRAPH_Y_DECIMAL_POINTS  "0"
#endif

void init_graph(void);
void graph_point(int32_t y);
void graph_point(float y);
void graph_points2(int32_t y1, int32_t y2);
void graph_points2(float y1, float y2);
void graph_points3(int32_t y1, int32_t y2, int32_t y3);
void graph_points3(float y1, float y2, float y3);
void graph_points4(int32_t y1, int32_t y2, int32_t y3, int32_t y4);
void graph_points4(float y1, float y2, float y3, float y4);
void graph_clear(void);
void graph_pause(void);
void graph_restart(void);

#endif