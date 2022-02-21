#include "graph_siow.h"

static void graph_write(uint8_t *pD, uint8_t len)
{
    if((pD!=0)&&(len==0))
    {
        while(*pD!=0)
            graph_writebyte(*pD++);
    }
    else
    {
        while(len>0)
        {
            graph_writebyte(*pD++);
            len--;
        }
    }
}

void init_graph(void)
{
    graph_write("\xff\xee\xee\xdd\x00\x0d\x0a", 7); // Key that automatically puts SIOW into the graph mode
    graph_write("$" GRAPH_TITLE "," GRAPH_Y_TITLE "," GRAPH_SERIES1_TITLE, 0);

#ifdef GRAPH_SERIES2_TITLE
    graph_write("," GRAPH_SERIES2_TITLE, 0);
#endif

#ifdef GRAPH_SERIES3_TITLE
    graph_write("," GRAPH_SERIES3_TITLE, 0);
#endif

#ifdef GRAPH_SERIES4_TITLE
    graph_write("," GRAPH_SERIES4_TITLE, 0);
#endif

    graph_write("\n");
    graph_write("&" GRAPH_X_MIN "," GRAPH_X_MAX "," GRAPH_X_OFFSET "," GRAPH_X_SCALE "," GRAPH_X_DECIMAL_POINTS "\n", 0);
    graph_write("#" GRAPH_Y_MIN "," GRAPH_Y_MAX "," GRAPH_Y_OFFSET "," GRAPH_Y_SCALE "," GRAPH_Y_DECIMAL_POINTS "\n", 0);
}

void graph_point(int32_t y)
{
    graph_write(y<<"\n");
}

void graph_point(float y)
{

    graph_write(y<<"\n");
}

void graph_points2(int32_t y1, int32_t y2)
{

    graph_write(y1<<","<<y2<<"\n");
}

void graph_points2(float y1, float y2)
{

    graph_write(y1<<","<<y2<<"\n");
}

void graph_points3(int32_t y1, int32_t y2, int32_t y3)
{

    graph_write(y1<<","<<y2<<","<<y3<<"\n");
}

void graph_points3(float y1, float y2, float y3)
{

    graph_write(y1<<","<<y2<<","<<y3<<"\n");
}

void graph_points4(int32_t y1, int32_t y2, int32_t y3, int32_t y4)
{

    graph_write(y1<<","<<y2<<","<<y3<<","<<y4<<"\n");
}

void graph_points4(float y1, float y2, float y3, float y4)
{

    graph_write(y1<<","<<y2<<","<<y3<<","<<y4<<"\n");
}

void graph_clear(void)
{

    putc('\f');
}

void graph_pause(void)
{

    putc('\v');
}

void graph_restart(void)
{
    putc('\a');
}


