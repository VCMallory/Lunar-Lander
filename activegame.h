#ifndef JUEGOACTIVO
#define JUEGOACTIVO

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>

    ALLEGRO_EVENT_QUEUE * queue2;
    ALLEGRO_TIMER * timer2;

    float velocidad(float * v_ini, float * t, float g);
    float gravedad(float g, float * v_ini, float * cont);

    void main1(ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_EVENT* event, int* onEmpezar, ALLEGRO_BITMAP** nave, ALLEGRO_BITMAP** empezarbackground, ALLEGRO_KEYBOARD_STATE* keystate);

    void activegame(ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, int * onEmpezar, ALLEGRO_BITMAP ** nave, ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_KEYBOARD_STATE * keystate, float* fuel);
    void activegame2(ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, int * onEmpezar, ALLEGRO_BITMAP ** nave, ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_KEYBOARD_STATE * keystate, float* fuel, int * score);
    void activegame3(ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, int * onEmpezar, ALLEGRO_BITMAP ** nave, ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_KEYBOARD_STATE * keystate, float* fuel, int * score);

    void activegame4(ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_EVENT* event, int* onEmpezar, ALLEGRO_BITMAP** nave, ALLEGRO_BITMAP** empezarbackground, ALLEGRO_KEYBOARD_STATE* keystate, float* fuel, int* score);
    void activegame5(ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_EVENT* event, int* onEmpezar, ALLEGRO_BITMAP** nave, ALLEGRO_BITMAP** empezarbackground, ALLEGRO_KEYBOARD_STATE* keystate, float* fuel, int* score);
    void activegame6(ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_EVENT* event, int* onEmpezar, ALLEGRO_BITMAP** nave, ALLEGRO_BITMAP** empezarbackground, ALLEGRO_KEYBOARD_STATE* keystate, float* fuel, int* score);

    void activegame7(ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_EVENT* event, int* onEmpezar, ALLEGRO_BITMAP** nave, ALLEGRO_BITMAP** empezarbackground, ALLEGRO_KEYBOARD_STATE* keystate, float* fuel, int* score);
    void activegame8(ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_EVENT* event, int* onEmpezar, ALLEGRO_BITMAP** nave, ALLEGRO_BITMAP** empezarbackground, ALLEGRO_KEYBOARD_STATE* keystate, float* fuel, int* score);
    void activegame9(ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_EVENT* event, int* onEmpezar, ALLEGRO_BITMAP** nave, ALLEGRO_BITMAP** empezarbackground, ALLEGRO_KEYBOARD_STATE* keystate, float* fuel, int* score);

    void activegamea(ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_EVENT* event, int* onEmpezar, ALLEGRO_BITMAP** nave, ALLEGRO_BITMAP** empezarbackground, ALLEGRO_KEYBOARD_STATE* keystate, float* fuel, int* score);


    int pause(ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, ALLEGRO_KEYBOARD_STATE* keystate);
    void tolose(ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, ALLEGRO_KEYBOARD_STATE* keystate);
    void win(ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, ALLEGRO_KEYBOARD_STATE* keystate, float* fuel, int * score);

#endif
