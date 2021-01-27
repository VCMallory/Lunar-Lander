
#include"activegame.h"

void main1(ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_EVENT* event, int* onEmpezar, ALLEGRO_BITMAP** nave, ALLEGRO_BITMAP** empezarbackground, ALLEGRO_KEYBOARD_STATE* keystate)
{

    ALLEGRO_TIMER* timer;

    //for images
    ALLEGRO_BITMAP* menuBackground = NULL;
    ALLEGRO_BITMAP* onClickEmpezar = NULL;
    ALLEGRO_BITMAP* onClickSalir = NULL;

    timer = al_create_timer(1.0 / 60.0);
    int running;
    ALLEGRO_MOUSE_STATE mousepos;
   

    float fuel = 8000;
   

    menuBackground = al_load_bitmap("resources/background/difficult2.png");
    onClickEmpezar = al_load_bitmap("resources/background/difficult1.png");
    onClickSalir = al_load_bitmap("resources/background/difficult.png");

    *onEmpezar = 1;
    float mouseposx = 0;
    float mouseposy = 0;
    al_start_timer(timer);
    while (*onEmpezar == 1) {
        al_wait_for_event(*queue, event);
        al_get_mouse_state(&mousepos);
        al_draw_bitmap(*empezarbackground, 0, 0, 0);
        //if the exit x is touched, it comes out
        if (event->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            *onEmpezar = 0;
        }

        //exits the game if the exit button is touched
        if ((event->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) && (mouseposx > 127 && mouseposx < 670 && mouseposy > 290 && mouseposy < 380)) {
            fuel = 5000;
            activegame(&*queue, &*event, &*onEmpezar, &*nave, &*empezarbackground, &*keystate, &fuel);
        }

        //the game starts
        if ((event->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) && (mouseposx > 127 && mouseposx < 670 && mouseposy > 175 && mouseposy < 264)) {
            fuel = 8000;
            activegame(&*queue, &*event, &*onEmpezar, &*nave, &*empezarbackground, &*keystate, &fuel);
        }

        //mouse position
        if (event->type == ALLEGRO_EVENT_MOUSE_AXES) {
            mouseposx = event->mouse.x;
            mouseposy = event->mouse.y;
        }

       

        if (event->type == ALLEGRO_EVENT_TIMER) {

            if (mouseposx > 127 && mouseposx < 670 && mouseposy > 175 && mouseposy < 264) {
                al_draw_bitmap(onClickEmpezar, 0, 0, 0);
            }
            else if (mouseposx > 127 && mouseposx < 670 && mouseposy > 290 && mouseposy < 380) {
                al_draw_bitmap(onClickSalir, 0, 0, 0);
            }
            else {
                al_draw_bitmap(menuBackground, 0, 0, 0);
            }

            al_flip_display();

        }
    }

    //Free memories
   
    al_destroy_timer(timer);
    al_destroy_bitmap(menuBackground);
    al_destroy_bitmap(onClickEmpezar);
    al_destroy_bitmap(onClickSalir);

}