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

void DogBorn(object *dog){
    int i,a,b;
    for(i=0;i<=4;i++){
      if(dog[i].hp==0)
        {
            a=rand()%2;
            b=rand()%400;

            dog[i].hp=dog[i].hp+2;

            dog[i].kind=2;
            if(a==1){
                dog[i].x=0-100;
                dog[i].y=420-b;
            }
            else{
                dog[i].x=1080+20;
                dog[i].y=420-b;
            }

        }
    }
}
