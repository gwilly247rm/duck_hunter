#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "function.h"
#include "struct.h"

void shit_launch(object *DOG, object *SHIT,int i,int *count1,int *count2,int *count3,int *count4,int *count5,int *g1,int *g2,int *g3,int *g4,int *g5,int *draw)
{
    int a_dd;
    int b_dd;
    int count,g;
    double p;
    double z;
    int h1,h2,h3;
    int i_shit;
    i_shit=(i/3);

    if(SHIT[i].y>720&&SHIT[i+1].y>720&&SHIT[i+2].y>720&&i==0)
        if(*count1<1)
            *count1=*count1+1;
    if(SHIT[i].y>720&&SHIT[i+1].y>720&&SHIT[i+2].y>720&&i==3)
        if(*count2<1)
            *count2=*count2+1;
    if(SHIT[i].y>720&&SHIT[i+1].y>720&&SHIT[i+2].y>720&&i==6)
        if(*count3<1)
            *count3=*count3+1;
    if(SHIT[i].y>720&&SHIT[i+1].y>720&&SHIT[i+2].y>720&&i==9)
        if(*count4<1)
            *count4=*count4+1;
    if(SHIT[i].y>720&&SHIT[i+1].y>720&&SHIT[i+2].y>720&&i==12)
        if(*count5<1)
            *count5=*count5+1;

    switch(i)
    {
    case 0:
        count=*count1;
        g=*g1;
        break;
    case 3:
        count=*count2;
        g=*g2;
        break;
    case 6:
        count=*count3;
        g=*g3;
        break;
    case 9:
        count=*count4;
        g=*g4;
        break;
    case 12:
        count=*count5;
        g=*g5;
        break;
    }

    srand( time( NULL ) );

    a_dd = rand() % 1200+1;
    b_dd = rand() % 1200+1;

    if(g==4)
        g=1;

    if(a_dd<100&&b_dd%75==0&&count>0)
    {
        p=DOG[i_shit].x+45;
        z=DOG[i_shit].y+35;
        switch(g)
        {
        case 1:
            h1=0;
            SHIT[i].x=p;
            SHIT[i].y=z;
            g=g+1;
            count=count-1;
            break;
        case 2:
            h2=0;
            SHIT[i+1].x=p;
            SHIT[i+1].y=z;
            g=g+1;
            count=count-1;
            break;
        case 3:
            h3=0;
            SHIT[i+2].x=p;
            SHIT[i+2].y=z;
            g=g+1;
            count=count-1;
            break;
        }
    }

        switch(i)
    {
    case 0:
        *count1=count;
        *g1=g;
        break;
    case 3:
        *count2=count;
        *g2=g;
        break;
    case 6:
        *count3=count;
        *g3=g;
        break;
    case 9:
        *count4=count;
        *g4=g;
        break;
    case 12:
       *count5=count;
        *g5=g;
        break;
    }

    SHIT[i].y=SHIT[i].y+0.5;
    SHIT[i+1].y=SHIT[i+1].y+0.5;
    SHIT[i+2].y=SHIT[i+2].y+0.5;

    if(SHIT[i].y==650){
        SHIT[i].y=741;
        h1=1;
    }
    if(SHIT[i+1].y==650){
        SHIT[i+1].y=741;
        h2=1;
    }
    if(SHIT[i+2].y==650){
        SHIT[i+2].y=741;
        h3=1;
    }

    if(h1==0&&i==0)
        *draw=0;
    if(h2==0&&i==0)
        *draw=1;
    if(h3==0&&i==0)
        *draw=2;

    if(h1==0&&i==3)
        *draw=3;
    if(h2==0&&i==3)
        *draw=4;
    if(h3==0&&i==3)
        *draw=5;

    if(h1==0&&i==6)
        *draw=6;
    if(h2==0&&i==6)
        *draw=7;
    if(h3==0&&i==6)
        *draw=8;

    if(h1==0&&i==9)
        *draw=9;
    if(h2==0&&i==9)
        *draw=10;
    if(h3==0&&i==9)
        *draw=11;

    if(h1==0&&i==12)
        *draw=12;
    if(h2==0&&i==12)
        *draw=13;
    if(h3==0&&i==12)
        *draw=14;
}
