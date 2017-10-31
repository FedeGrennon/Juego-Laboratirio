#ifndef VARIOS_H_INCLUDED
#define VARIOS_H_INCLUDED

#include "Personaje.h"

using namespace std;

void pintarPantalla(SDL_Surface* pantalla, int rojo, int verde, int azul){
    SDL_FillRect(pantalla, 0, SDL_MapRGB(pantalla->format, rojo, verde, azul));
}

#endif // VARIOS_H_INCLUDED
