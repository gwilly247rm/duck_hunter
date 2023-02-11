#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>


#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "function.h"
#include "struct.h"

/* symbolic constants for the DOG’s possible directions */
#define DOWN_RIGHT 0
#define UP_RIGHT 1
#define DOWN_LEFT 2
#define UP_LEFT 3
#define PADDLE_MOVE 10

int main()
{
    //寬(橫) 長(直)
    int display_wid=1080;//螢幕寬
    int display_len=740;//長

    int DOG_wid=90;//狗寬
    int DOG_len=70;//長

    int duck_wid=100;//狗寬
    int duck_len=80;//長

    int shit_wid=40;//屎寬
    int shit_len=40;//長

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *font2 = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT events;
    ALLEGRO_KEYBOARD_STATE KBstate;

    /***/
    ALLEGRO_BITMAP* windows = NULL;
    ALLEGRO_BITMAP* B_start = NULL;
    ALLEGRO_BITMAP* B_explain = NULL;
    ALLEGRO_BITMAP* B_ranking = NULL;
    ALLEGRO_BITMAP* B_back = NULL;
    ALLEGRO_BITMAP* B_exit = NULL;
    ALLEGRO_BITMAP* P_explain = NULL;
    ALLEGRO_BITMAP* P_ranking = NULL;

    ALLEGRO_BITMAP* background = NULL;

    /*DOG and duck*/
    ALLEGRO_BITMAP *DOG1 = NULL; /* pointer to the DOG's image bitmap */
    ALLEGRO_BITMAP *DOG2 = NULL;
    ALLEGRO_BITMAP *DOG3 = NULL;
    ALLEGRO_BITMAP *DOG4 = NULL;
    ALLEGRO_BITMAP *DOG5 = NULL;
    ALLEGRO_BITMAP *DOG11 = NULL; /* pointer to the DOG's image bitmap */
    ALLEGRO_BITMAP *DOG12 = NULL;
    ALLEGRO_BITMAP *DOG13 = NULL;
    ALLEGRO_BITMAP *DOG14 = NULL;
    ALLEGRO_BITMAP *DOG15 = NULL;
    ALLEGRO_BITMAP *duck1 = NULL;
    ALLEGRO_BITMAP *duck2 = NULL;
    ALLEGRO_BITMAP *duck3 = NULL;

    ALLEGRO_BITMAP *dog_hp1 = NULL;
    ALLEGRO_BITMAP *dog_hp2 = NULL;
    ALLEGRO_BITMAP *boom = NULL;
    ALLEGRO_BITMAP *tool = NULL;

    ALLEGRO_BITMAP *shit1 = NULL;
    ALLEGRO_BITMAP *shit2 = NULL;
    ALLEGRO_BITMAP *shit3 = NULL;
    ALLEGRO_BITMAP *shit4 = NULL;
    ALLEGRO_BITMAP *shit5 = NULL;
    ALLEGRO_BITMAP *shit6 = NULL;
    ALLEGRO_BITMAP *shit7 = NULL;
    ALLEGRO_BITMAP *shit8 = NULL;
    ALLEGRO_BITMAP *shit9 = NULL;
    ALLEGRO_BITMAP *shit10 = NULL;
    ALLEGRO_BITMAP *shit11 = NULL;
    ALLEGRO_BITMAP *shit12 = NULL;
    ALLEGRO_BITMAP *shit13 = NULL;
    ALLEGRO_BITMAP *shit14 = NULL;
    ALLEGRO_BITMAP *shit15 = NULL;

    ALLEGRO_BITMAP *hp = NULL;

    ALLEGRO_BITMAP *cursor_bmp = NULL;

    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(9);
    al_init_font_addon();
    al_init_ttf_addon();



    timer = al_create_timer(0.01);
    display = al_create_display(display_wid, display_len);
    srand( time( NULL ) );
    ALLEGRO_MOUSE_STATE MSstate;
    ALLEGRO_MOUSE_CURSOR *cursor = NULL;



    ALLEGRO_EVENT_SOURCE *ms_sourse=al_get_mouse_event_source();
    ALLEGRO_EVENT_SOURCE *kb_sourse=al_get_keyboard_event_source();
    ALLEGRO_EVENT_SOURCE *di_sourse=al_get_display_event_source(display);
    ALLEGRO_EVENT_SOURCE *ti_sourse=al_get_timer_event_source(timer);

    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, ms_sourse);    /* register keyboard to event queue */
    al_register_event_source(event_queue, kb_sourse);
    al_register_event_source(event_queue, di_sourse);
    al_register_event_source(event_queue, ti_sourse);



    int run=1; //等於0時關掉遊戲並結束程式
    int mode=1; //遊戲畫面(1:遊戲選單 2:遊戲進行 3:輸入姓名 4:顯示排行榜5.操作說明
    int DOG_amount=5;
    int shit_amount=15;
    int DOG_killed=0;
    int i=0;
    int x=0;
    int y=0;
    int xr=1000,yr=1000;

    int a_dd;
    int b_dd=0;
    int count1=3;
    int count2=3;
    int count3=3;
    int count4=3;
    int count5=3;
    int h1=1,h2=1,h3=1,h4=1,h5=1,h6=1,h7=1,h8=1,h9=1,h10=1,h11=1,h12=1,h13=1,h14=1,h15=1;
    double p;
    double z;
    int g=1;
    int i_shit=0;
    int time=0;
    /********************************/
    windows = al_load_bitmap("Window2.png");
    B_start = al_load_bitmap("B_Start.png");
    B_ranking = al_load_bitmap("B_explain2.png");
    B_explain = al_load_bitmap("B_explain.png");
    B_exit = al_load_bitmap("B_exit.png");
    P_ranking = al_load_bitmap("P_ranking.png");
    B_back = al_load_bitmap("B_back.png");
    P_explain = al_load_bitmap("P_explain.png");

    /*******************************/
    DOG1 = al_load_bitmap( "DOG1.png"); /* load the DOG bitmap */
    DOG2 = al_load_bitmap( "DOG2.png");
    DOG3 = al_load_bitmap( "DOG3.png");
    DOG4 = al_load_bitmap( "DOG4.png");
    DOG5 = al_load_bitmap( "DOG5.png");
    DOG11 = al_load_bitmap( "DOG11.png"); /* load the DOG bitmap */
    DOG12 = al_load_bitmap( "DOG12.png");
    DOG13 = al_load_bitmap( "DOG13.png");
    DOG14 = al_load_bitmap( "DOG14.png");
    DOG15 = al_load_bitmap( "DOG15.png");

    duck1 = al_load_bitmap( "duck1.png");
    duck2 = al_load_bitmap( "duck2.png");
    duck3 = al_load_bitmap( "duck3.png");

    hp = al_load_bitmap( "hp.png");
    font = al_load_ttf_font("YanoneTagesschrift.ttf", 30, 0);
    font2 = al_load_ttf_font("YanoneTagesschrift.ttf", 43, 0);

    dog_hp1 = al_load_bitmap( "blood1.png");
    dog_hp2 = al_load_bitmap( "blood2.png");
    boom = al_load_bitmap( "dog_die.png");
    tool = al_load_bitmap( "tool.png");

    /*******************************/
    shit1 = al_load_bitmap( "shit.png");
    shit2 = al_load_bitmap( "shit.png");
    shit3 = al_load_bitmap( "shit.png");
    shit4 = al_load_bitmap( "shit.png");
    shit5 = al_load_bitmap( "shit.png");
    shit6 = al_load_bitmap( "shit.png");
    shit7 = al_load_bitmap( "shit.png");
    shit8 = al_load_bitmap( "shit.png");
    shit9 = al_load_bitmap( "shit.png");
    shit10 = al_load_bitmap( "shit.png");
    shit11 = al_load_bitmap( "shit.png");
    shit12 = al_load_bitmap( "shit.png");
    shit13 = al_load_bitmap( "shit.png");
    shit14 = al_load_bitmap( "shit.png");
    shit15 = al_load_bitmap( "shit.png");

    cursor_bmp = al_load_bitmap( "center2.png");

    object duck;
    object dog1;
    object dog2;
    object dog3;
    object DOG[5];
    object SHIT[15];
    object BOOM[5];

    duck.bmp=al_load_bitmap("duck1.png");
    duck.kind=1;
    duck.x=display_wid/2;
    duck.y=display_len-60-80+25;
    duck.direction=0;
    duck.m=0.8;
    duck.n=0;
    duck.hp=3;

    /*****第一種狗*********/
    dog1.bmp=al_load_bitmap("dog1.png");
    dog1.kind=2;
    dog1.x=0;
    dog1.y=0;
    dog1.direction=0;
    dog1.m=2.0;//速度
    dog1.n=0;
    dog1.hp=2;

    /*****第二種狗*********/
    dog2.bmp=al_load_bitmap("dog1.png");
    dog2.kind=5;
    dog2.x=0;
    dog2.y=0;
    dog2.direction=0;
    dog2.m=1;//速度
    dog2.n=0;
    dog2.hp=2;

    /*****第三種狗*********/
    dog3.bmp=al_load_bitmap("dog1.png");
    dog3.kind=6;
    dog3.x=0;
    dog3.y=0;
    dog3.direction=0;
    dog3.m=1;//速度
    dog3.n=0;
    dog3.hp=2;

    for(i=0;i<=DOG_amount-1;i++){
        DOG[i]=dog1;

    }

    for(i=0;i<=shit_amount-1;i++){
        SHIT[i].bmp=al_load_bitmap("shit.png");
        SHIT[i].kind=0;
        SHIT[i].x=0;
        SHIT[i].y=0;
        SHIT[i].direction=0;
        SHIT[i].m=0;
        SHIT[i].n=0;
        SHIT[i].hp=0;
    }

    for(i=0;i<=4;i++){
        BOOM[i].bmp=boom;
        BOOM[i].kind=4;
        BOOM[i].x=0;
        BOOM[i].y=0;
        BOOM[i].direction=0;
        BOOM[i].m=0;
        BOOM[i].n=300;
        BOOM[i].hp=0;
    }

    int t;
    int game_start=1;
    al_show_mouse_cursor(display);
    cursor=al_create_mouse_cursor(cursor_bmp, 15,15);
    t = al_set_mouse_cursor(display, cursor);

    while(run){

        while(mode==1 && run==1){//遊戲選單



            x=0;
            y=0;
            xr=1000,yr=1000;

            al_draw_bitmap(windows, 0, 0, 0);
            al_draw_bitmap(B_start, 430, 360, 0);
            al_draw_bitmap( B_ranking, 430, 440, 0);
            al_draw_bitmap(B_explain, 430, 520, 0);
            al_draw_bitmap(B_exit, 430, 600, 0);

            al_flip_display();

            al_get_mouse_state(&MSstate);
            if(al_mouse_button_down(&MSstate,1))

            {
                x=al_get_mouse_state_axis(&MSstate,0);
                y=al_get_mouse_state_axis(&MSstate,1);
            }

            while(1)
            {
                al_get_mouse_state(&MSstate);

                if(al_mouse_button_down(&MSstate,1)==0)
                {
                    xr=al_get_mouse_state_axis(&MSstate,0);
                    yr=al_get_mouse_state_axis(&MSstate,1);
                    break;
                }

            }
            if(x>=430&&y>=360&&x<=650&&y<=420){//選項框:開始
                mode=2;
                break;
            }
            if(x>=430&&y>=440&&x<=650&&y<=500)//排行
            {
                mode=4;
                printf("排行\n");
                x=0;
                y=0;
                xr=1000,yr=1000;

                al_draw_bitmap( P_ranking, 140, 70, 0);
                al_draw_bitmap( B_back, 430, 610, 0);
                al_flip_display();



                break;
            }//排行
            if(x>=430&&y>=520&&x<=650&&y<=580)
            {
                mode=5;
                printf("operate explaining\n");
                x=0;
                y=0;
                xr=1000,yr=1000;
                al_draw_bitmap( P_explain, 140, 70, 0);
                al_draw_bitmap( B_back, 430, 610, 0);
                al_flip_display();
                break;
            }//選項框:操作說明
            if(x>=430&&y>=600&&x<=650&&y<=660)
            {
                run=0;
                break;
            }//退出

        }

/********************************************************************************************************************************/
        while(mode==2 && run==1){//遊戲進行







            if(game_start==1){//遊戲開始，初始各項數值
                duck.hp=5;
                background = al_load_bitmap("fon2.png");
                DOG_killed=0;
                game_start=0;
                x=1;
                y=1;
                int a,b;
                for(i=0; i<5; i++)
                {
                    DOG[i]=dog1;

                    DOG[i].direction = rand() % 4; // and then make a random initial direction
                    a=rand()%2;
                    b=rand()%400;
                    if(a==1){
                        DOG[i].x=0-100;
                        DOG[i].y=420-b;
                    }
                    else{
                        DOG[i].x=1080+20;
                        DOG[i].y=420-b;
                    }
                }



                al_start_timer(timer);
            }

            al_draw_bitmap(background, 0, 0, 0);//印背景
            al_draw_bitmap(tool,0,680,0);


            al_get_keyboard_state(&KBstate);
            if(al_key_down(&KBstate,ALLEGRO_KEY_A)){
                duck.direction=0;
                moveduck(&duck);//更新鴨子座標
                duck.bmp=duck2;
            }
            else if(al_key_down(&KBstate,ALLEGRO_KEY_D)){
                duck.direction=1;
                moveduck(&duck);//更新鴨子座標
                duck.bmp=duck1;
            }



            if (!al_is_event_queue_empty(event_queue))//如果有event
            {
                //AttackJudgeShit(&duck, SHIT);


                while (al_get_next_event(event_queue, &events))//取出event
                {
                    switch (events.type)//判斷event類型
                    {

                    case ALLEGRO_EVENT_KEY_DOWN://鍵盤被按下

                        if(events.keyboard.keycode == ALLEGRO_KEY_ESCAPE)//esc被按下
                        {
                            run = 0;
                            break;
                        }
                        /*moveduck(events,&duck);//更新鴨子座標

                        if (events.keyboard.keycode == ALLEGRO_KEY_A)//根據鴨子行進方向更改鴨子圖片
                        {

                            duck.bmp=duck2;

                        }
                        else if (events.keyboard.keycode == ALLEGRO_KEY_D)//根據鴨子行進方向更改鴨子圖片
                        {

                            duck.bmp=duck1;

                        }*/

                        break;

                    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN://滑鼠被按下

                        if(events.mouse.button==1)//左鍵被按
                        {
                            AttackJudgeBullet(events, DOG, &DOG_killed);//攻擊判定

                            for(i=0;i<=4;i++){
                                if(DOG[i].hp==0){
                                    BOOM[i].m=1;
                                    BOOM[i].x=DOG[i].x;
                                    BOOM[i].y=DOG[i].y;
                                }
                            }



                            DogBorn(DOG);
                        }
                        break;

                    case ALLEGRO_EVENT_TIMER://計時器計時

                            /*printf("time%d\n",time);
                            time+=1;*/

                            moveDOG(DOG);//更新狗的座標

                            int a_dd;
                            int b_dd;


                            for(i=0; i<5; i++)//狗的動畫
                            {
                                if(DOG[i].direction==0||DOG[i].direction==1)
                                {
                                    if(x>0&&x<=50)
                                        DOG[i].bmp=DOG1;

                                    else if(x>50&&x<=100)
                                        DOG[i].bmp=DOG2;

                                    else if(x>100&&x<=150)
                                        DOG[i].bmp=DOG3;

                                    else if(x>150&&x<=200)
                                        DOG[i].bmp=DOG4;

                                    else if(x>200&&x<=250)
                                        DOG[i].bmp=DOG5;


                                    x=x+1;

                                    if(x==251)
                                        x=1;
                                }
                            }

                            for(i=0; i<5; i++)//狗的動畫
                            {
                                if(DOG[i].direction==2||DOG[i].direction==3)
                                {
                                    if(y>0&&y<=50)
                                        DOG[i].bmp=DOG11;
                                    else if(y>50&&y<=100)
                                        DOG[i].bmp=DOG12;
                                    else if(y>100&&y<=150)
                                        DOG[i].bmp=DOG13;
                                    else if(y>150&&y<=200)
                                        DOG[i].bmp=DOG14;
                                    else if(y>200&&y<=250)
                                        DOG[i].bmp=DOG15;

                                    y=y+1;
                                    if(y==251)
                                        y=1;
                                }
                            }

                            a_dd = rand() % 1200+1;//用亂數控制狗是否要換方向

                            for(i=0; i<5; i++)
                            {
                                if(a_dd<20 && b_dd%8==0)
                                {

                                    DOG[i].direction = rand()%4;

                                }
                                b_dd=b_dd+1;
                            }
                            break;

                                }
                                break;
                            }
                        }


            /*********************************/

            for(i=0;i<=DOG_amount-1;i++){//印出狗

                    if(DOG[i].kind!=0)
                    al_draw_bitmap(DOG[i].bmp, DOG[i].x, DOG[i].y, 0);

                    if(DOG[i].hp==1)
                    al_draw_bitmap(dog_hp1, DOG[i].x, DOG[i].y-5, 0);

                    if(DOG[i].hp==2)
                    al_draw_bitmap(dog_hp2, DOG[i].x, DOG[i].y-5, 0);
            }
            for(i=1;i<=duck.hp;i++){
                al_draw_bitmap(hp,10+63*(i-1),680,0);}

/********************************/
            //launch shit

            if(SHIT[0].y>720&&SHIT[1].y>720&&SHIT[2].y>720)
                if(count1<1)
                    count1=count1+1;

            if(g==4)
            {
                g=1;
            }

            if(a_dd<100&&b_dd%75==0&&count1>0)
            {
                p=DOG[i_shit].x+45;
                z=DOG[i_shit].y+35;
                switch(g)
                {
                case 1:
                    h1=0;
                    SHIT[0].x=p;
                    SHIT[0].y=z;
                    g=g+1;
                    count1=count1-1;
                    break;
                case 2:
                    h2=0;
                    SHIT[1].x=p;
                    SHIT[1].y=z;
                    g=g+1;
                    count1=count1-1;
                    break;
                case 3:
                    h3=0;
                    SHIT[2].x=p;
                    SHIT[2].y=z;
                    g=g+1;
                    count1=count1-1;
                    break;
                }
            }

            i_shit=i_shit+1;

            SHIT[0].y=SHIT[0].y+0.5;
            SHIT[1].y=SHIT[1].y+0.5;
            SHIT[2].y=SHIT[2].y+0.5;

            if(SHIT[0].y==650){
                SHIT[0].y=741;
                //h1=1;
            }
            if(SHIT[1].y==650){
                SHIT[1].y=741;
                //h2=1;
            }
            if(SHIT[2].y==650){
                SHIT[2].y=741;
                //h3=1;
            }

            if(h1==0)
                al_draw_bitmap(shit1,SHIT[0].x, SHIT[0].y, 0);/* draw the bitmap */
            if(h2==0)
                al_draw_bitmap(shit2,SHIT[1].x, SHIT[1].y, 0);/* draw the bitmap */
            if(h3==0)
                al_draw_bitmap(shit3,SHIT[2].x, SHIT[2].y, 0);/* draw the bitmap */

/****************/
            if(SHIT[3].y>720&&SHIT[4].y>720&&SHIT[5].y>720)
                if(count2<1)
                    count2=count2+1;

            a_dd = rand() % 1200+1;

            if(g==4)
            {
                g=1;
            }

            if(a_dd<100&&b_dd%75==0&&count2>0)
            {
                p=DOG[i_shit].x+45;
                z=DOG[i_shit].y+35;
                switch(g)
                {
                case 1:
                    h4=0;
                    SHIT[3].x=p;
                    SHIT[3].y=z;
                    g=g+1;
                    count2=count2-1;
                    break;
                case 2:
                    h5=0;
                    SHIT[4].x=p;
                    SHIT[4].y=z;
                    g=g+1;
                    count2=count2-1;
                    break;
                case 3:
                    h6=0;
                    SHIT[5].x=p;
                    SHIT[5].y=z;
                    g=g+1;
                    count2=count2-1;
                    break;
                }
            }

            i_shit=i_shit+1;

            SHIT[3].y=SHIT[3].y+0.5;
            SHIT[4].y=SHIT[4].y+0.5;
            SHIT[5].y=SHIT[5].y+0.5;

            if(SHIT[3].y==650)
                SHIT[3].y=741;
            if(SHIT[4].y==650)
                SHIT[4].y=741;
            if(SHIT[5].y==650)
                SHIT[5].y=741;

            if(h4==0)
                al_draw_bitmap(shit4,SHIT[3].x, SHIT[3].y, 0);/* draw the bitmap */
            if(h5==0)
                al_draw_bitmap(shit5,SHIT[4].x, SHIT[4].y, 0);/* draw the bitmap */
            if(h6==0)
                al_draw_bitmap(shit6,SHIT[5].x, SHIT[5].y, 0);/* draw the bitmap */

/****************/
            if(SHIT[6].y>720&&SHIT[7].y>720&&SHIT[8].y>720)
                if(count3<1)
                    count3=count3+1;

            a_dd = rand() % 1200+1;

            if(g==4)
            {
                g=1;
            }

            if(a_dd<100&&b_dd%75==0&&count3>0)
            {
                p=DOG[i_shit].x+45;
                z=DOG[i_shit].y+35;
                switch(g)
                {
                case 1:
                    h7=0;
                    SHIT[6].x=p;
                    SHIT[6].y=z;
                    g=g+1;
                    count3=count3-1;
                    break;
                case 2:
                    h8=0;
                    SHIT[7].x=p;
                    SHIT[7].y=z;
                    g=g+1;
                    count3=count3-1;
                    break;
                case 3:
                    h9=0;
                    SHIT[8].x=p;
                    SHIT[8].y=z;
                    g=g+1;
                    count3=count3-1;
                    break;
                }
            }

            i_shit=i_shit+1;

            SHIT[6].y=SHIT[6].y+0.5;
            SHIT[7].y=SHIT[7].y+0.5;
            SHIT[8].y=SHIT[8].y+0.5;

            if(SHIT[6].y==650)
                SHIT[6].y=741;
            if(SHIT[7].y==650)
                SHIT[7].y=741;
            if(SHIT[8].y==650)
                SHIT[8].y=741;

            if(h7==0)
                al_draw_bitmap(shit7,SHIT[6].x, SHIT[6].y, 0);/* draw the bitmap */
            if(h8==0)
                al_draw_bitmap(shit8,SHIT[7].x, SHIT[7].y, 0);/* draw the bitmap */
            if(h9==0)
                al_draw_bitmap(shit9,SHIT[8].x, SHIT[8].y, 0);/* draw the bitmap */

/****************/
            if(SHIT[9].y>720&&SHIT[10].y>720&&SHIT[11].y>720)
                if(count4<1)
                    count4=count4+1;

            a_dd = rand() % 1200+1;

            if(g==4)
            {
                g=1;
            }

            if(a_dd<100&&b_dd%75==0&&count4>0)
            {
                p=DOG[i_shit].x+45;
                z=DOG[i_shit].y+35;
                switch(g)
                {
                case 1:
                    h10=0;
                    SHIT[9].x=p;
                    SHIT[9].y=z;
                    g=g+1;
                    count4=count4-1;
                    break;
                case 2:
                    h11=0;
                    SHIT[10].x=p;
                    SHIT[10].y=z;
                    g=g+1;
                    count4=count4-1;
                    break;
                case 3:
                    h12=0;
                    SHIT[11].x=p;
                    SHIT[11].y=z;
                    g=g+1;
                    count4=count4-1;
                    break;
                }
            }

            i_shit=i_shit+1;

            SHIT[9].y=SHIT[9].y+0.5;
            SHIT[10].y=SHIT[10].y+0.5;
            SHIT[11].y=SHIT[11].y+0.5;

            if(SHIT[9].y==650)
                SHIT[9].y=741;
            if(SHIT[10].y==650)
                SHIT[10].y=741;
            if(SHIT[11].y==650)
                SHIT[11].y=741;

            if(h10==0)
                al_draw_bitmap(shit10,SHIT[9].x, SHIT[9].y, 0);/* draw the bitmap */
            if(h11==0)
                al_draw_bitmap(shit11,SHIT[10].x, SHIT[10].y, 0);/* draw the bitmap */
            if(h12==0)
                al_draw_bitmap(shit12,SHIT[11].x, SHIT[11].y, 0);/* draw the bitmap */

/****************/
            if(SHIT[12].y>720&&SHIT[13].y>720&&SHIT[14].y>720)
                if(count5<1)
                    count5=count5+1;

            a_dd = rand() % 1200+1;

            if(g==4)
            {
                g=1;
            }

            if(a_dd<100&&b_dd%75==0&&count5>0)
            {
                p=DOG[i_shit].x+45;
                z=DOG[i_shit].y+35;
                switch(g)
                {
                case 1:
                    h13=0;
                    SHIT[12].x=p;
                    SHIT[12].y=z;
                    g=g+1;
                    count5=count5-1;
                    break;
                case 2:
                    h14=0;
                    SHIT[13].x=p;
                    SHIT[13].y=z;
                    g=g+1;
                    count5=count5-1;
                    break;
                case 3:
                    h15=0;
                    SHIT[14].x=p;
                    SHIT[14].y=z;
                    g=g+1;
                    count5=count5-1;
                    break;
                }
            }

            i_shit=0;

            SHIT[12].y=SHIT[12].y+0.5;
            SHIT[13].y=SHIT[13].y+0.5;
            SHIT[14].y=SHIT[14].y+0.5;

            if(SHIT[12].y==650)
                SHIT[12].y=741;
            if(SHIT[13].y==650)
                SHIT[13].y=741;
            if(SHIT[14].y==650)
                SHIT[14].y=741;

            if(h13==0)
                al_draw_bitmap(shit13,SHIT[12].x, SHIT[12].y, 0);/* draw the bitmap */
            if(h14==0)
                al_draw_bitmap(shit14,SHIT[13].x, SHIT[13].y, 0);/* draw the bitmap */
            if(h15==0)
                al_draw_bitmap(shit15,SHIT[14].x, SHIT[14].y, 0);


            AttackJudgeShit(&duck,SHIT);
            /**************************************************/





            for(i=0;i<=4;i++){
                    if(BOOM[i].m!=0){
                        if(BOOM[i].n!=0){

                            al_draw_bitmap(BOOM[i].bmp,BOOM[i].x,BOOM[i].y,0);
                            BOOM[i].n=BOOM[i].n-1;
                        }
                        else{
                            BOOM[i].m=0;
                            BOOM[i].n=100;
                        }
                    }
                }

            /*
            for(i=0;i<=shit_amount-1;i++){//印出屎
                if(SHIT[i].kind!=0){
                    al_draw_bitmap(SHIT[i].bmp, SHIT[i].x, SHIT[i].y, 0);
                }
            }*/


            al_draw_bitmap( duck.bmp, duck.x, 610, 0);//印出鴨子
            al_draw_textf( font, al_map_rgb(255, 255, 255), 400+470,400+300, -1, "DOG  KILLED ");
            al_draw_textf( font2, al_map_rgb(255, 255, 255), 520+470,392+300, -1, ": %d", DOG_killed);
            al_flip_display();

            if(duck.hp<=0){
                al_stop_timer(timer);
                game_start=1;
                DOG_killed=0;
                mode=1;
                break;
            }
        }

/********************************************************************************************************************************/
        /*while(mode==3 && run==1){//輸入姓名
        }*/
/********************************************************************************************************************************/
        while(mode==4 && run==1){//顯示排行榜

            al_get_mouse_state(&MSstate);
            if(al_mouse_button_down(&MSstate,1)==1)
            {
                x=al_get_mouse_state_axis(&MSstate,0);
                y=al_get_mouse_state_axis(&MSstate,1);

            }

            while(1)
            {
                al_get_mouse_state(&MSstate);
                al_rest(0.01);
                if(al_mouse_button_down(&MSstate,1)==0)
                {
                    xr=al_get_mouse_state_axis(&MSstate,0);
                    yr=al_get_mouse_state_axis(&MSstate,1);
                    break;
                }

            }
            if(x>=430&&y>=610&&x<=650&&y<=670)
            {
                mode=1;
                break;
        }
    }

/**********************************************************************/

        while(mode==5 && run==1){//操作說明

            al_get_mouse_state(&MSstate);
            if(al_mouse_button_down(&MSstate,1)==1)
            {
                x=al_get_mouse_state_axis(&MSstate,0);
                y=al_get_mouse_state_axis(&MSstate,1);

            }

            while(1)
            {
                al_get_mouse_state(&MSstate);
                al_rest(0.01);
                if(al_mouse_button_down(&MSstate,1)==0)
                {
                    xr=al_get_mouse_state_axis(&MSstate,0);
                    yr=al_get_mouse_state_axis(&MSstate,1);
                    break;
                }

            }
            if(x>=430&&y>=610&&x<=650&&y<=670)
            {
                mode=1;
                break;
        }
    }
    }
    al_stop_timer(timer);


   /***************************************/
    al_destroy_display(display);
    al_destroy_bitmap(duck.bmp);
    al_destroy_bitmap(windows);
    al_destroy_bitmap(B_start);
    al_destroy_bitmap(B_ranking);
    al_destroy_bitmap(B_explain);
    al_destroy_bitmap(B_exit);
    al_destroy_bitmap(P_ranking);
    al_destroy_bitmap(P_explain);

    /*************************************/
    al_destroy_bitmap(DOG1); /* destroy the DOG bitmap */
    al_destroy_bitmap(DOG2);
    al_destroy_bitmap(DOG3);
    al_destroy_bitmap(DOG4);
    al_destroy_bitmap(DOG5);
    al_destroy_bitmap(DOG11); /* destroy the DOG bitmap */
    al_destroy_bitmap(DOG12);
    al_destroy_bitmap(DOG13);
    al_destroy_bitmap(DOG14);
    al_destroy_bitmap(DOG15);
    al_destroy_bitmap(duck1);
    al_destroy_bitmap(duck2);
    al_destroy_bitmap(duck3);
    al_destroy_bitmap(background);
    al_destroy_bitmap(dog_hp1);
    al_destroy_bitmap(dog_hp2);
    al_destroy_bitmap(boom);
    al_destroy_bitmap(cursor_bmp);
    al_destroy_bitmap(tool);

    /*************************************/
    al_destroy_bitmap(shit1);
    al_destroy_bitmap(shit2);
    al_destroy_bitmap(shit3);
    al_destroy_bitmap(shit4);
    al_destroy_bitmap(shit5);
    al_destroy_bitmap(shit6);
    al_destroy_bitmap(shit7);
    al_destroy_bitmap(shit8);
    al_destroy_bitmap(shit9);
    al_destroy_bitmap(shit10);
    al_destroy_bitmap(shit11);
    al_destroy_bitmap(shit12);
    al_destroy_bitmap(shit13);
    al_destroy_bitmap(shit14);
    al_destroy_bitmap(shit15);
    al_destroy_bitmap(hp);

    al_destroy_mouse_cursor(cursor);

    for(i=0;i<=DOG_amount-1;i++){
    al_destroy_bitmap(DOG[i].bmp);}
    for(i=0;i<=shit_amount-1;i++){
    al_destroy_bitmap(SHIT[i].bmp);}
    al_destroy_font( font );
    al_destroy_font( font2 );
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    return 0;
}
