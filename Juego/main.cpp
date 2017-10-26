#include "SDL/SDL.h"
#include "Personaje.h"
#include "Escenario.h"

int main(int argc, char* args[]){
    SDL_Surface* pantalla = NULL;
    SDL_Event tecla;

    piso suelo;
    suelo.posicionar(0,450);

    pj personaje;
    personaje.posicionar(100, 150);

    SDL_Init(SDL_INIT_VIDEO);
    ///SETEAR PANTALLA
    pantalla = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE| SDL_DOUBLEBUF);

    suelo.cargar();
    personaje.cargar();

    while(true){
        SDL_FillRect(pantalla, 0, SDL_MapRGB(pantalla->format, 111, 171, 238));

        personaje.mostrar(pantalla);
        suelo.mostrar(pantalla);

        SDL_Flip(pantalla);

        SDL_PollEvent(&tecla);
        personaje.mover(tecla);
        if(tecla.type == SDL_QUIT)
            break;
    }

    return 0;
}
