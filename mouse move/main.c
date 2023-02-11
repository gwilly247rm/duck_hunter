#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#define DISPLAY_WIDTH   1080
#define DISPLAY_HEIGHT  740



int main()
{

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP* windows = NULL;
    ALLEGRO_BITMAP* gun = NULL;
    ALLEGRO_MOUSE_CURSOR *cursor = NULL;//******Unmovable*********
    int x=0,y=0,t=0;

    al_init();
    al_init_image_addon();

    display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);


    al_install_mouse();
    ALLEGRO_MOUSE_STATE MSstate;

    windows = al_load_bitmap("./Window2.png");
    gun = al_load_bitmap("./center2.png");

    al_draw_bitmap(windows, 0, 0, 0);
    al_flip_display();

    al_show_mouse_cursor(display);//******Unmovable*********
    //al_hide_mouse_cursor(display);

    al_get_mouse_state(&MSstate);//******Unmovable*********
    cursor=al_create_mouse_cursor(gun, 15,15);//******Unmovable*********
    t = al_set_mouse_cursor(display, cursor);//******Unmovable*********
    printf("T:%d\n",t);








    system("pause");

    al_destroy_mouse_cursor(cursor);//******Unmovable*********
    al_destroy_bitmap(windows);
    al_destroy_display(display);



}
