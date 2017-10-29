#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>

#include "Varios.h"
#include "Personaje.h"
#include "Escenario.h"
#include "Texto.h"

using namespace std;

int main(int argc, char** argv){
    SDL_Surface* pantalla = NULL;
    objetos suelo;
    pj personaje;
    cadena txt;
    bool gameloop=true;

    SDL_Init(SDL_INIT_EVERYTHING);
    pantalla = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE| SDL_DOUBLEBUF);

    suelo.cargar("Imagenes/Piso.bmp");
    personaje.cargar("Imagenes/Personaje.bmp");
    suelo.posicionar(0,450);
    personaje.posicionar(100, 150);

    txt.cargar("Tipografias/Letra.ttf", 20);
    txt.escribirCadena("HOLA");
    txt.colorRelleno(0,0,0);
    txt.colorFondo(0,0,0);
    txt.renderizar();
    txt.posicion(20, 20);

    while(gameloop==true){
        pintarPantalla(pantalla, 110, 190, 250);

        txt.pintarColorFondo();
        txt.mostrar(pantalla);
        personaje.mostrar(pantalla);
        suelo.mostrar(pantalla);

        personaje.mover();

        SDL_Flip(pantalla);

        gameloop=salir();
    }

    return 0;
}
