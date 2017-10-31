#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>

#include "Varios.h"
#include "Personaje.h"
#include "Escenario.h"
#include "Texto.h"

using namespace std;

int main(int argc, char** argv){
    SDL_Surface* pantalla = NULL;
    objetos suelo, caja;
    pj personaje;
    cadena txt;
    SDL_Event tecla;
    bool gameloop=true;
    bool eventoEsc;
    char* algo;
    char palabra[30];
    strcpy(palabra, "ESCTIRO: ");

    const int FPS=60;
    const int frameDelay=1000/FPS;
    Uint32 frameStart;
    int frameTime;

    SDL_Init(SDL_INIT_EVERYTHING);
    pantalla = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

    suelo.cargar("Imagenes/Piso.bmp");
    personaje.cargar("Imagenes/Personaje1.bmp");
    suelo.posicionar(0,450);
    personaje.posicionar(100, 350);
    personaje.velocidad(4);

    txt.cargar("Tipografias/Letra.ttf", 20);
    txt.escribirCadena(" ");
    txt.colorRelleno(0,0,0);
    txt.colorFondo(0,0,0);
    txt.renderizar();
    txt.posicion(20, 20);

    while(gameloop==true){
        frameStart=SDL_GetTicks();

        pintarPantalla(pantalla, 110, 190, 250);

        txt.pintarColorFondo(0,0,0);
        txt.mostrar(pantalla);
        personaje.mostrar(pantalla);
        suelo.mostrar(pantalla);

        eventoEsc=SDL_PollEvent(&tecla);

        if(tecla.type==SDL_QUIT){
            gameloop=false;
        }
        if(tecla.type == SDL_KEYDOWN){
            if(tecla.key.keysym.sym == SDLK_ESCAPE)
                gameloop=false;

            personaje.mover();
            while(eventoEsc){
                eventoEsc=escribir(tecla, palabra);
            }
        }

        txt.escribirCadena(palabra);
        txt.renderizar();

        SDL_Flip(pantalla);

        frameTime=SDL_GetTicks()-frameStart;
        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }

    return 0;
}
