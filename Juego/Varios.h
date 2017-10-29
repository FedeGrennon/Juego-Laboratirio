#ifndef VARIOS_H_INCLUDED
#define VARIOS_H_INCLUDED

bool salir(){
    SDL_Event tecla;

    SDL_PollEvent(&tecla);

    if(tecla.type == SDL_QUIT){
        return false;
    }
    if(tecla.type == SDL_KEYDOWN){
        if(tecla.key.keysym.sym == SDLK_ESCAPE)
            return false;
    }

    return true;
}

void pintarPantalla(SDL_Surface* pantalla, int rojo, int verde, int azul){
    SDL_FillRect(pantalla, 0, SDL_MapRGB(pantalla->format, rojo, verde, azul));
}

#endif // VARIOS_H_INCLUDED
