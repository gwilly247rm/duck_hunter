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

void AttackJudgeBullet(ALLEGRO_EVENT events,object*dog,int *dog_killed)
{
    //int count_dog_relife=0;
    int x=0,y=0,i=0;






            x=events.mouse.x;
            y=events.mouse.y;


        for(i=0; i<5; i++)
        {
            if(x<=(dog[i].x+90) && dog[i].x<=x && y<=(dog[i].y+70) && dog[i].y<=y)
            {
                dog[i].hp-=1;
            }
            if(dog[i].hp==0)
            {
                dog[i].kind=0;
                *dog_killed=*dog_killed+1;
            }
        }


}

