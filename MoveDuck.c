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



void moveduck(object *duck)
{
    if ((*duck).direction==0) {

            (*duck).x -= (*duck).m;}
    if ((*duck).direction==1) (*duck).x += (*duck).m;



    /* make sure the paddles don go off screen */

    if ((*duck).x < 0)        (*duck).x = 0;
    if ((*duck).x > 980)       (*duck).x = 980;
}
