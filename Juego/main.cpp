#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <windows.h>
#include <time.h>

#include "Varios.h"
#include "Personaje.h"
#include "Escenario.h"
#include "Texto.h"

using namespace std;

int main(int argc, char** argv){
    SDL_Surface* pantalla = NULL;
    objetos suelo, flecha;
    pj personaje;
    archivo ran;
    SDL_Event tecla;
    int dificultad=1;
    bool gameloop=true;
    bool eventoEsc, random=true;
    char palabra[30];
    strcpy(palabra, " ");

    srand(time(NULL));

    const int FPS=60;
    const int frameDelay=1000/FPS;
    Uint32 frameStart;
    int frameTime;

    SDL_Init(SDL_INIT_EVERYTHING);
    pantalla = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

    personaje.cargar("Imagenes/Personaje1.bmp");
    suelo.cargar("Imagenes/Escenario 1.png");
    flecha.cargar("Imagenes/Flecha 2.png");
    suelo.posicionar();
    flecha.posicionar(720, 470);
    personaje.posicionar(100, 420);
    personaje.velocidad(3);
    flecha.pintarColorFondo(255,255,255);

    ran.random(dificultad);

    while(gameloop==true){
        frameStart=SDL_GetTicks();
        pintarPantalla(pantalla, 110, 190, 250);
        suelo.mostrar(pantalla);

        eventoEsc=SDL_PollEvent(&tecla);

        if(tecla.type==SDL_QUIT)
            gameloop=false;

        if(tecla.type == SDL_KEYDOWN || tecla.type == SDL_KEYUP){
            if(tecla.key.keysym.sym == SDLK_ESCAPE)
                gameloop=false;
            personaje.mover();
            if(tecla.type == SDL_KEYDOWN){
                if(random){
                    while(eventoEsc){
                        eventoEsc=escribir(tecla, palabra);
                    }
                }
            }
        }

        ran.mostrarRand(pantalla);
        if(ran.estado(pantalla, palabra)==1){
            strcpy(palabra, " ");
            ran.random(dificultad);
        }else if(ran.estado(pantalla, palabra)==2){
            ran.serPlabra(" ");
            strcpy(palabra, "  ");
            flecha.mostrar(pantalla);
            escribirEnPantalla("CONTINUAR", pantalla, 685, 450);
            random=false;
        }
        personaje.mostrar(pantalla);
        escribirEnPantalla(palabra, pantalla, posxPalabraRandom, posyPalabraRandom);

        SDL_Flip(pantalla);

        frameTime=SDL_GetTicks()-frameStart;
        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }

    return 0;
}
