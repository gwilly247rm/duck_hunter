#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

/* symbolic constants for the dog¡¦s possible directions */
#define DOWN_RIGHT 0
#define UP_RIGHT 1
#define DOWN_LEFT 2
#define UP_LEFT 3

#define SCREEN_W 1080
#define SCREEN_H 430

/* function prototypes */
void movedog(int *direction,int *dog_x,int *dog_y,int dog_SIZE_H,int dog_SIZE_W);
void reverseVerticalDirection(int *direction);
void reverseHorizontalDirection(int *direction);


void movedog(int *direction,int *dog_x,int *dog_y,int dog_SIZE_H,int dog_SIZE_W) /* moves the dog */
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
    if ( *dog_y <= 0 || *dog_y >= (SCREEN_H - dog_SIZE_H) )
        reverseVerticalDirection(direction); /* make it go the other way */

    /* if the dog is going off the left or right... */
    if ( *dog_x <= 0 || *dog_x >= (SCREEN_W - dog_SIZE_W) )
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
