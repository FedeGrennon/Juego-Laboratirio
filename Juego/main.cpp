#include <SDL/SDL.h>
#include "Personaje.h"
#include "Escenario.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv){
    SDL_Surface* pantalla = NULL;
    SDL_Surface* asd = NULL;
    SDL_Event tecla;

    piso suelo;
    suelo.posicionar(0,450);

    pj personaje;
    personaje.posicionar(100, 150);

    SDL_Color bgcolor,fgcolor;
    SDL_Rect rectangulo;
    SDL_Surface *ttext;
    TTF_Font *fuente;
    const char texto[14]="Hola Mundo...";
    char msg[14];

    TTF_Init();
    fuente = TTF_OpenFont("Letra.ttf",20);

    SDL_Init(SDL_INIT_VIDEO);
    pantalla = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE| SDL_DOUBLEBUF);

    atexit(TTF_Quit);

    fgcolor.r=200;  fgcolor.g=200;  fgcolor.b=10;
    bgcolor.r=255;  bgcolor.g=0;  bgcolor.b=0;

    sprintf(msg,"%s",texto);
    ttext = TTF_RenderText_Shaded(fuente,msg,fgcolor,bgcolor);
    rectangulo.y=100;
    rectangulo.x=100;
    rectangulo.w=ttext->w;
    rectangulo.h=ttext->h;

    suelo.cargar();
    personaje.cargar();

    while(true){
        SDL_FillRect(pantalla, 0, SDL_MapRGB(pantalla->format, 111, 171, 238));

        SDL_SetColorKey(ttext,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(ttext->format,255,0,0));

        SDL_BlitSurface(ttext,NULL,pantalla,&rectangulo);


        personaje.mostrar(pantalla);
        suelo.mostrar(pantalla);

        SDL_Flip(pantalla);

        SDL_PollEvent(&tecla);
        personaje.mover();
        if(tecla.type == SDL_QUIT)
            break;
    }

    TTF_CloseFont(fuente);
    SDL_FreeSurface(ttext);

    return 0;
}
