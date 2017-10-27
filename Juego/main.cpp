#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>

#include "Personaje.h"
#include "Escenario.h"
#include "Texto.h"

int main(int argc, char** argv){
    SDL_Surface* pantalla = NULL;
    SDL_Event tecla;
    piso suelo;
    pj personaje;
    cadena txt;

    SDL_Init(SDL_INIT_VIDEO);
    pantalla = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE| SDL_DOUBLEBUF);

    suelo.posicionar(0,450);
    personaje.posicionar(100, 150);
    suelo.cargar();
    personaje.cargar();

    txt.cargar(20);
    txt.escribirCadena("HOLA QUE ONDA");
    txt.colorRelleno(0,0,0);
    txt.colorFondo(0,0,0);
    txt.renderizar();
    txt.posicion(20, 20);

    while(true){
        SDL_FillRect(pantalla, 0, SDL_MapRGB(pantalla->format, 111, 171, 238));

        txt.pintarColorFondo();
        txt.mostrar(pantalla);

        personaje.mostrar(pantalla);
        suelo.mostrar(pantalla);

        SDL_Flip(pantalla);

        SDL_PollEvent(&tecla);
        personaje.mover();

        if(tecla.type == SDL_QUIT)
            break;
    }

    return 0;
}
