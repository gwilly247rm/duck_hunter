#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>
#include <stdio.h>

/* symbolic constants for the dog’s possible directions */
#define DOWN_RIGHT 0
#define UP_RIGHT 1
#define DOWN_LEFT 2
#define UP_LEFT 3

#define SCREEN_W 1080
#define SCREEN_H 430

/* function prototypes */
void movedog(int *direction,int *dog_x,int *dog_y);
void reverseVerticalDirection(int *direction);
void reverseHorizontalDirection(int *direction);

int main()
{
    int dog_x; /* the dog’s x-coordinate */
    int dog_y; /* the dog’s y-coordinate */
    int direction; /* the dog’s direction */

    ALLEGRO_BITMAP *dog1 = NULL; /* pointer to the dog's image bitmap */
    ALLEGRO_BITMAP *dog2 = NULL;
    ALLEGRO_BITMAP *dog3 = NULL;
    ALLEGRO_BITMAP *dog4 = NULL;
    ALLEGRO_BITMAP *dog5 = NULL;
    ALLEGRO_BITMAP *dog11 = NULL; /* pointer to the dog's image bitmap */
    ALLEGRO_BITMAP *dog12 = NULL;
    ALLEGRO_BITMAP *dog13 = NULL;
    ALLEGRO_BITMAP *dog14 = NULL;
    ALLEGRO_BITMAP *dog15 = NULL;
    ALLEGRO_BITMAP *shit1 = NULL;
    ALLEGRO_BITMAP *shit2 = NULL;
    ALLEGRO_BITMAP *shit3 = NULL;
    ALLEGRO_BITMAP *shit4 = NULL;
    ALLEGRO_BITMAP *shit5 = NULL;
    ALLEGRO_DISPLAY *display = NULL;/* pointer to display */
    ALLEGRO_KEYBOARD_STATE KBstate;


    /* first, set up Allegro and the graphics mode */
    al_init(); /* initialize Allegro */
    al_install_keyboard(); /* install the keyboard for Allegro to use */
    al_init_image_addon();

    display = al_create_display(SCREEN_W, SCREEN_H);

    dog1 = al_load_bitmap( "dog1.png"); /* load the dog bitmap */
    dog2 = al_load_bitmap( "dog2.png");
    dog3 = al_load_bitmap( "dog3.png");
    dog4 = al_load_bitmap( "dog4.png");
    dog5 = al_load_bitmap( "dog5.png");
    dog11 = al_load_bitmap( "dog11.png"); /* load the dog bitmap */
    dog12 = al_load_bitmap( "dog12.png");
    dog13 = al_load_bitmap( "dog13.png");
    dog14 = al_load_bitmap( "dog14.png");
    dog15 = al_load_bitmap( "dog15.png");
    shit1 = al_load_bitmap( "shit.png");
    shit2 = al_load_bitmap( "shit.png");
    shit3 = al_load_bitmap( "shit.png");
    shit4 = al_load_bitmap( "shit.png");
    shit5 = al_load_bitmap( "shit.png");

    srand( time( NULL ) ); /* seed the random function */
    direction = rand() % 4; /* and then make a random initial direction */
    dog_x = SCREEN_W / 2; /* give the dog its initial x-coordinate */
    dog_y = SCREEN_H / 2; /* give the dog its initial y-coordinate */

    int x=1;
    int y=1;

    int a;
    int b;
    int g=1;
    double z;
    int p,p1,p2,p3,p4,p5;
    double z1,z2,z3,z4,z5;
    int random;

    int count=5;

    int h=1,m=1,j=1,k=1,l=1;

    while(1)
    {
        al_get_keyboard_state(&KBstate);
        if (al_key_down(&KBstate, ALLEGRO_KEY_ESCAPE))
            break;

        movedog(&direction,&dog_x,&dog_y); /* move the dog */

        if(direction==0||direction==1)
        {
            if(x>0&&x<=50)
                al_draw_bitmap( dog1, dog_x, dog_y, 0);/* draw the bitmap */
            else if(x>50&&x<=100)
                al_draw_bitmap( dog2, dog_x, dog_y, 0);/* draw the bitmap */
            else if(x>100&&x<=150)
                al_draw_bitmap( dog3, dog_x, dog_y, 0);/* draw the bitmap */
            else if(x>150&&x<=200)
                al_draw_bitmap( dog4, dog_x, dog_y, 0);/* draw the bitmap */
            else if(x>200&&x<=250)
                al_draw_bitmap( dog5, dog_x, dog_y, 0);/* draw the bitmap */

            x=x+1;
            if(x==251)
                x=1;
        }

        if(direction==2||direction==3)
        {
            if(y>0&&y<=50)
                al_draw_bitmap( dog11, dog_x, dog_y, 0);/* draw the bitmap */
            else if(y>50&&y<=100)
                al_draw_bitmap( dog12, dog_x, dog_y, 0);/* draw the bitmap */
            else if(y>100&&y<=150)
                al_draw_bitmap( dog13, dog_x, dog_y, 0);/* draw the bitmap */
            else if(y>150&&y<=200)
                al_draw_bitmap( dog14, dog_x, dog_y, 0);/* draw the bitmap */
            else if(y>200&&y<=250)
                al_draw_bitmap( dog15, dog_x, dog_y, 0);/* draw the bitmap */

            y=y+1;
            if(y==251)
                y=1;
        }

        a = rand() % 1200+1;

        if(a<100&&b%13==0)
        {
            if ( direction == DOWN_RIGHT )
                direction = UP_LEFT;
            else if ( direction == DOWN_LEFT )
                direction = UP_RIGHT;
            else if ( direction == UP_RIGHT )
                direction = DOWN_LEFT;
            else if ( direction == UP_LEFT )
                direction = DOWN_RIGHT;
        }
        b=b+1;

        //launch shit

        if(count<1||z1>620||z2>520||z3>520||z4>520||z5>520)
            count=count+1;

        if(g==6)
        {
            g=1;
        }
        if(a<100&&b%8==0&&count>0)
        {
            p=dog_x+45;
            z=dog_y+35;
            switch(g)
            {
            case 1:
                h=0;
                p1=p;
                z1=z;
                g=g+1;
                count=count-1;
                break;
            case 2:
                m=0;
                p2=p;
                z2=z;
                g=g+1;
                count=count-1;
                break;
            case 3:
                j=0;
                p3=p;
                z3=z;
                g=g+1;
                count=count-1;
                break;
            case 4:
                k=0;
                p4=p;
                z4=z;
                g=g+1;
                count=count-1;
                break;
            case 5:
                l=0;
                p5=p;
                z5=z;
                g=g+1;
                count=count-1;
                break;
            }
        }

        z1=z1+0.5;
        z2=z2+0.5;
        z3=z3+0.5;
        z4=z4+0.5;
        z5=z5+0.5;

        printf("%3.2f  %3.2f\n",z1,z2);

        if(h==0)
            al_draw_bitmap(shit1,p1, z1, 0);/* draw the bitmap */
        if(m==0)
            al_draw_bitmap(shit2,p2, z2, 0);/* draw the bitmap */
        if(j==0)
            al_draw_bitmap(shit3,p3, z3, 0);/* draw the bitmap */
        if(k==0)
            al_draw_bitmap(shit4,p4, z4, 0);/* draw the bitmap */
        if(l==0)
            al_draw_bitmap(shit5,p5, z5, 0);/* draw the bitmap */
        //Sleep(10);
        al_rest(0.005);

        /* display */
        al_flip_display(); /* Wait for the beginning of a vertical retrace. */
        al_clear_to_color(al_map_rgb(0,255,255));

        /* Clear the complete target bitmap, but confined by the clipping rectangle. */
    }

    al_destroy_bitmap(shit1);
    al_destroy_bitmap(shit2);
    al_destroy_bitmap(shit3);
    al_destroy_bitmap(shit4);
    al_destroy_bitmap(shit5);
    al_destroy_bitmap(dog1); /* destroy the dog bitmap */
    al_destroy_bitmap(dog2);
    al_destroy_bitmap(dog3);
    al_destroy_bitmap(dog4);
    al_destroy_bitmap(dog5);
    al_destroy_bitmap(dog11); /* destroy the dog bitmap */
    al_destroy_bitmap(dog12);
    al_destroy_bitmap(dog13);
    al_destroy_bitmap(dog14);
    al_destroy_bitmap(dog15);

    al_destroy_display(display); /* destroy the display */

    return 0;
}
/* end function main */
void movedog(int *direction,int *dog_x,int *dog_y) /* moves the dog */
{
    switch ( *direction )
    {
    case DOWN_RIGHT:
        *dog_x=*dog_x+1; /* move the dog to the right */
        ++*dog_y; /* move the dog down */
        break;
    case UP_RIGHT:
        ++*dog_x; /* move the dog to the right */
        --*dog_y; /* move the dog up */
        break;
    case DOWN_LEFT:
        --*dog_x; /* move the dog to the left */
        ++*dog_y; /* move the dog down */
        break;
    case UP_LEFT:
        --*dog_x; /* move the dog to the left */
        --*dog_y; /* move the dog up */
        break;
    } /* end switch */

    /* make sure the dog doesn¡¦t go off the screen */

    /* if the dog is going off the top or bottom... */
    if ( *dog_y <= 0 || *dog_y >= (430-70) )//SCREEN_H - dog_SIZE_H
        reverseVerticalDirection(direction); /* make it go the other way */

    /* if the dog is going off the left or right... */
    if ( *dog_x <= 0 || *dog_x >= (1080-90) )//SCREEN_W - dog_SIZE_W
        reverseHorizontalDirection(direction); /* make it go the other way */
} /* end function movedog */

void reverseVerticalDirection(int *direction) /* reverse the dog¡¦s up-down direction */
{
    if ( *direction == DOWN_RIGHT )
        *direction = UP_RIGHT;
    else if ( *direction == DOWN_LEFT )
        *direction = UP_LEFT;
    else if ( *direction == UP_RIGHT )
        *direction = DOWN_RIGHT;
    else if ( *direction == UP_LEFT )
        *direction = DOWN_LEFT;
} /* end function reverseVerticalDirection */

void reverseHorizontalDirection(int *direction) /* reverses the horizontal direction */
{
    switch ( *direction )
    {
    case DOWN_RIGHT:
        *direction = DOWN_LEFT;
        break;
    case UP_RIGHT:
        *direction = UP_LEFT;
        break;
    case DOWN_LEFT:
        *direction = DOWN_RIGHT;
        break;
    case UP_LEFT:
        *direction = UP_RIGHT;
        break;
    } /* end switch */
} /* end function reverseHorizontalDirection */
