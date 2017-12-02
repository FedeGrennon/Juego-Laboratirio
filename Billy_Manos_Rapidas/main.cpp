#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Niveles.h"

int main(int argc, char** argv){
    SDL_Surface* pantalla = NULL;

    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
        exit(10);

    pantalla = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Billy Manos Rapidas", "juego");
    if(pantalla==NULL)
        exit(10);

    Mix_OpenAudio(44100, AUDIO_S16, 2, 4096);

    atexit(Mix_CloseAudio);

    SDL_Event tecla;
    int menuOpcion=2;
    int volMusic=128, volSFX=128, dificultad=1;

    while(true){
        if(menuOpcion==1)
            menuOpcion=presentacion(pantalla, tecla);

        if(menuOpcion==2)
            menuOpcion=menuPrincipal(pantalla, tecla, volMusic, volSFX, dificultad);

        if(menuOpcion==3)
            menuOpcion=tutorial(pantalla, tecla, volMusic, volSFX);

        if(menuOpcion==0)
            return 0;

        SDL_PollEvent(&tecla);

        if(tecla.type==SDL_QUIT)
            return 0;

        SDL_Flip(pantalla);
    }


    return 0;
}
