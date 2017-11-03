#ifndef ESCENARIO_H_INCLUDED
#define ESCENARIO_H_INCLUDED
#include "Personaje.h"

class objetos{
     private:
        SDL_Surface* objeto;
        SDL_Rect pos;
    public:
        objetos(){objeto = NULL;}
        void cargar(char* imagen){objeto=IMG_Load(imagen);}
        void posicionar(int x=0, int y=0){
            pos.x=x;
            pos.y=y;
            pos.w=objeto->w;
            pos.h=objeto->h;
        }
        void mostrar(SDL_Surface* pantalla){SDL_BlitSurface(objeto, NULL, pantalla, &pos);}
        void pintarColorFondo(int rojo=0, int verde=0, int azul=0){SDL_SetColorKey(objeto, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(objeto->format,rojo,verde,azul));}
        SDL_Rect getRect(){return pos;}
        ~objetos(){SDL_FreeSurface(objeto);}
};
#endif // ESCENARIO_H_INCLUDED
