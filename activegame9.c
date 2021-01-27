#include"activegame.h"

void activegame9(ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_EVENT* event, int* onEmpezar, ALLEGRO_BITMAP** nave, ALLEGRO_BITMAP** empezarbackground, ALLEGRO_KEYBOARD_STATE* keystate, float* fuel, int* score)
{
    ALLEGRO_TIMER* gametime;
    ALLEGRO_FONT* displayFuel;
    ALLEGRO_FONT* displayVelocity;
    ALLEGRO_BITMAP* plataforma3 = NULL;
    ALLEGRO_FONT* displayPausa;

    displayFuel = al_load_font("resources/fonts/AbyssinicaSIL-R.ttf", 12, 0);
    displayPausa = al_load_font("resources/fonts/AbyssinicaSIL-R.ttf", 12, 0);
    displayVelocity = al_load_font("resources/fonts/AbyssinicaSIL-R.ttf", 12, 0);

    plataforma3 = al_load_bitmap("resources/background/plataforma9.png");

    gametime = al_create_timer(1.0 / 60.0);


    *onEmpezar = 1;
    float x = 10.0;
    float y = 30.0;
    float v = 0;
    float cont = 0.0;
    float cont2 = 0.0;
    float fuel1 = *fuel;
    al_start_timer(gametime);
    while (*onEmpezar == 1) {
        al_wait_for_event(*queue, event);
        al_get_keyboard_state(keystate);
        al_draw_bitmap(*empezarbackground, 0, 0, 0);

        if (al_key_down(keystate, ALLEGRO_KEY_RIGHT)) {
            x += 0.8;
            *fuel -= 2;
        }
        if (al_key_down(keystate, ALLEGRO_KEY_LEFT)) {
            x -= 0.8;
            *fuel -= 2;
        }

        if (!(al_key_down(keystate, ALLEGRO_KEY_SPACE))) {
            cont = cont + (1.0 / 60.0);
            v = velocidad(&v, &cont, 0.2);
            y = y + gravedad(0.1, &v, &cont);
            cont2 = (0.4) * cont;
        }
        else if ((al_key_down(keystate, ALLEGRO_KEY_SPACE))) {
            cont2 = cont2 + (1.0 / 60.0);
            v = velocidad(&v, &cont2, -0.3);
            y = y + gravedad(-0.15, &v, &cont2);
            cont = (0.4) * cont2;
            *fuel -= 6;
        }

        if (al_key_down(keystate, ALLEGRO_KEY_P)) {
            *onEmpezar = pausa(&*empezarbackground, &*queue, &*event, &*keystate);
        }

        if (*fuel < 0) {
            *onEmpezar = 0;
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }

        if (event->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            *onEmpezar = 0;
        }

        if (y > (1.423 * x) + 353 && x < 78 && x > 0) {
            *onEmpezar = 0;/*MISSES*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 464 && x > 78 && x < 92) {
            *onEmpezar = 0;/*MISSES*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 378 && x > 92 && x < 185) {
            *onEmpezar = 0;/*MISSES*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 438 && x > 185 && x < 189) {
            *onEmpezar = 0;/*MISSES*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 375 && x > 200 && x < 297) {
            *onEmpezar = 0;/*MISSES*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 412 && x > 297 && x < 390) {
            *onEmpezar = 0;/*MISSES*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 348 && x > 390 && x < 469) {
            *onEmpezar = 0;/*MISSES*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 348 && y < 411 && x > 469 && x < 560) {
            *onEmpezar = 0;/*MISSES*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 512 && x > 560 && x < 579) {
            *onEmpezar = 0;/*MISSES*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 430 && x > 579 && x < 668) {
            *onEmpezar = 0;/*MISSES*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 467 && x > 668 && x < 679) {
            *onEmpezar = 0;/*MISSES*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 402 && x > 679 && x < 800) {
            *onEmpezar = 0;/*MISSES*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }

       
        if (y > 435 && x > 189 && x < 235 && v < 0.6) {
            *score = *score + 200;
            *onEmpezar = 0;/*WINS*/
            activegame7(&*queue, &*event, &*onEmpezar, &*nave, &*empezarbackground, &*keystate, &*fuel, &*score);
        }
        if (y > 506 && x > 484 && x < 538 && v < 0.6) {
            *score = *score + 400;
            *onEmpezar = 0;/*WINS*/
            activegame7(&*queue, &*event, &*onEmpezar, &*nave, &*empezarbackground, &*keystate, &*fuel, &*score);
        }

        //---------------Contrary to winning---------------------
        
        if (y > 435 && x > 189 && x < 235 && v >= 0.6) {
            *onEmpezar = 0;/*WIN*/
            activegame7(&*queue, &*event, &*onEmpezar, &*nave, &*empezarbackground, &*keystate, &*fuel, &*score);
        }
        if (y > 506 && x > 484 && x < 538 && v >= 0.6) {
            *onEmpezar = 0;/*WIN*/
            activegame7(&*queue, &*event, &*onEmpezar, &*nave, &*empezarbackground, &*keystate, &*fuel, &*score);
        }

        //if you exit the game screen
        if (x < 0 || x > 765) {
            *onEmpezar = 0;
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }

        if (event->type == ALLEGRO_EVENT_TIMER) {
            al_draw_text(displayFuel, al_map_rgb(255, 255, 255), 198, 440, 0, "200");
            al_draw_text(displayFuel, al_map_rgb(255, 255, 255), 688, 471, 0, "300");

            al_draw_textf(displayFuel, al_map_rgb(255, 255, 225), 20, 20, 0, "Score: %d", *score);
            al_draw_textf(displayFuel, al_map_rgb(255, 255, 225), 20, 30, 0, "Fuel: %f", *fuel);
            al_draw_textf(displayVelocity, al_map_rgb(255, 255, 225), 20, 40, 0, "Speed: %.2f", v);

            al_draw_textf(displayFuel, al_map_rgb(255, 255, 225), 500, 20, 0, "All Fuel: %f", fuel1);
            al_draw_textf(displayFuel, al_map_rgb(255, 255, 225), 500, 30, 0, "Level Speed: %.2f", v / 2);
            al_draw_textf(displayVelocity, al_map_rgb(255, 255, 225), 500, 40, 0, "Vertical Speed: %.2f", v / 3);

            al_draw_textf(displayPausa, al_map_rgb(255, 255, 255), 780, 20, ALLEGRO_ALIGN_RIGHT, "Press P to pause");
            al_draw_bitmap(plataforma3, 0, 333, 0); /*PLATFORM 2*/
            al_draw_bitmap(*nave, x, y, 0);
            al_flip_display();
        }
    }

    al_destroy_timer(gametime);
    al_destroy_font(displayFuel);
    al_destroy_font(displayVelocity);
    al_destroy_font(displayPausa);
    al_destroy_bitmap(plataforma3);
}