#ifndef ESCENARIO_H_INCLUDED
#define ESCENARIO_H_INCLUDED
#include "Personaje.h"

class objetos{
     protected:
        SDL_Surface* objeto;
        SDL_Rect pos, muestra;
    public:
        objetos(){
            objeto = NULL;
        }
        void cargar(char* imagen){objeto=IMG_Load(imagen);}
        void posicionar(int x=0, int y=0){
            pos.x=x;
            pos.y=y;
            pos.w=objeto->w;
            pos.h=objeto->h;
        }
        void EspacioMuestral(int w, int h, int x=0, int y=0){
            muestra.x=x;
            muestra.y=y;
            muestra.w=w;
            muestra.h=h;
        }
        void mostrar(SDL_Surface* pantalla){SDL_BlitSurface(objeto, &muestra, pantalla, &pos);}
        void pintarColorFondo(int rojo=0, int verde=0, int azul=0){SDL_SetColorKey(objeto, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(objeto->format,rojo,verde,azul));}
        SDL_Rect getRect(){return pos;}
        int getPosX(){return pos.x;}
        int getPosY(){return pos.y;}
        int getW(){return pos.w;}
        int getH(){return pos.h;}
        SDL_Surface* getSurface(){return objeto;}
        ~objetos(){SDL_FreeSurface(objeto);}
};

bool colision(SDL_Rect obj1, SDL_Rect obj2){
    int w1, h1, x1, y1, w2, h2, x2, y2;
    w1=obj1.w;
    h1=obj1.w;
    x1=obj1.w;
    y1=obj1.w;

    w2=obj2.w;
    h2=obj2.h;
    x2=obj2.x;
    y2=obj2.y;

    if((x1+w1)>x2 && ((y1+h1)>y2) && ((x2+w2)>x1) && ((y2+h2)>y1))
        return true;
    else
        return false;
}


#endif // ESCENARIO_H_INCLUDED
