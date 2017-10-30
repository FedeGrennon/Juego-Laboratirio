#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>

#include "Varios.h"
#include "Personaje.h"
#include "Escenario.h"
#include "Texto.h"

int main(int argc, char** argv){
    SDL_Surface* pantalla = NULL;
    objetos suelo;
    pj personaje;
    cadena txt;
    bool gameloop=true;
    bool colPiso;

    SDL_Init(SDL_INIT_EVERYTHING);
    pantalla = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE| SDL_DOUBLEBUF);

    suelo.cargar("Imagenes/Piso.bmp");
    personaje.cargar("Imagenes/Personaje1.bmp");
    suelo.posicionar(0,450);
    personaje.posicionar(100, 150);
    personaje.velocidad(1, 1);

    txt.cargar("Tipografias/Letra.ttf", 20);
    txt.escribirCadena(" ");
    txt.colorRelleno(0,0,0);
    txt.colorFondo(0,0,0);
    txt.renderizar();
    txt.posicion(20, 20);

    while(gameloop==true){
        gameloop=salir();
        pintarPantalla(pantalla, 110, 190, 250);

        txt.pintarColorFondo(0,0,0);
        txt.mostrar(pantalla);
        personaje.mostrar(pantalla);
        suelo.mostrar(pantalla);

        personaje.mover();
        colPiso=personaje.colision(suelo.getRect());
        personaje.gravedad(colPiso);

        if(colPiso==true){
             txt.escribirCadena("colisiono Piso");
             txt.renderizar();
        }else{
            txt.escribirCadena("NO colisiono");
            txt.renderizar();
        }

        SDL_Flip(pantalla);
    }

    return 0;
}
