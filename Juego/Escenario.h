#ifndef ESCENARIO_H_INCLUDED
#define ESCENARIO_H_INCLUDED
#include "Personaje.h"


class piso{
    private:
        SDL_Surface* suelo;
        SDL_Rect pos;
    public:
        piso(){suelo = NULL;}
        void cargar(){suelo=SDL_LoadBMP("Piso.bmp");}
        void posicionar(int x=0, int y=0){
            pos.x=x;
            pos.y=y;
        }
        void mostrar(SDL_Surface* pantalla){SDL_BlitSurface(suelo, NULL, pantalla, &pos);}
        ~piso(){SDL_FreeSurface(suelo);}
};

#endif // ESCENARIO_H_INCLUDED
