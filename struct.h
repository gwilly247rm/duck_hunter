#ifndef _STRUCTURE_HEADER_H_
#define _STRUCTURE_HEADER_H_


#include <allegro5/allegro_image.h>
typedef struct object
{
    ALLEGRO_BITMAP *bmp;
    int kind;//0.no 1.duck  2.dog  3.shit 4.boom
    float x;
    float y;
    int direction;//1.leftup 2.rightup 3.leftdown 4.rightdown
    float m;
    int n;
    int hp;
} object;

#endif // _STRUCTURE_HEADER_H_
