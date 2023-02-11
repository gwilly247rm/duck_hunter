#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#include <stdio.h>
#include <stdlib.h>

#include "function.h"
#include "struct.h"

void AttackJudgeShit(object *duck, object *SHIT)
{
    int i;

    for(i=0; i<15; i++)
    {
        if((SHIT[i].y+40)>=(*duck).y && (SHIT[i].x+40)>=(*duck).x && (SHIT[i].x<=(*duck).x+100)&&(SHIT[i].y+40)<=740)
        {
            (*duck).hp=(*duck).hp-1;
            SHIT[i].y=741;
        }
    }
}
