#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED

#include "Escenario.h"

class pj{
    private:
        SDL_Surface* personaje;
        SDL_Rect pos;
        SDL_Rect anim;
        int vel;
    public:
        pj(){personaje = NULL;}
        void velocidad(int velocidad){vel=velocidad;}
        SDL_Rect getRect(){return pos;}
        void cargar(char* imagen){personaje=IMG_Load(imagen);}
        void posicionar(int x=0, int y=0){
            pos.x=x;
            pos.y=y;
            pos.w=50;
            pos.h=100;
        }
        void animacion(int x=0, int y=0,int w=50, int h=100){
            anim.x = x;
            anim.y = y;
            anim.h = h;
            anim.w = w;
        }
        void mostrar(SDL_Surface* pantalla){
            SDL_BlitSurface(personaje, &anim, pantalla, &pos);
        }
        void pintarColorFondo(int rojo=0, int verde=0, int azul=0){SDL_SetColorKey(personaje, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(personaje->format,rojo,verde,azul));}
        int mover(bool random);
        int getPosX(){return pos.x;}
        int getPosY(){return pos.y;}
        bool colision(SDL_Rect objAcolisionar);
        void animacion();
        ~pj(){SDL_FreeSurface(personaje);}
};

int pj::mover(bool random){
    Uint8* tecla;
    tecla=SDL_GetKeyState(NULL);

    if(tecla[SDLK_RIGHT]==1 && pos.x < 750){
        pos.x += vel;
        if(random==false && pos.x >= 400){
            pos.x+= -vel;
        }
        if(tecla[SDLK_DOWN]==1 && pos.y < 500){
            pos.y += vel;
        }
        if(tecla[SDLK_UP]==1 && pos.y > 350){
            pos.y -= vel;
        }
        return 1;
    }
    if(tecla[SDLK_LEFT]==1 && pos.x > 0){
        pos.x -= vel;
        if(tecla[SDLK_DOWN]==1 && pos.y < 500){
            pos.y += vel;
        }
        if(tecla[SDLK_UP]==1 && pos.y > 350){
            pos.y -= vel;
        }
        return 2;
    }
    if(tecla[SDLK_UP]==1 && pos.y > 350){
        pos.y -= vel;
        return 3;
    }
    if(tecla[SDLK_DOWN]==1 && pos.y < 500){
        pos.y += vel;
        return 4;
    }

    return 0;
}

bool pj::colision(SDL_Rect objAcolisionar){
    int w1, h1, x1, y1, w2, h2, x2, y2;
    w1=pos.w;
    h1=pos.h;
    x1=pos.x;
    y1=pos.y;
    w2=objAcolisionar.w;
    h2=objAcolisionar.h;
    x2=objAcolisionar.x;
    y2=objAcolisionar.y;

    if((x1+w1)>x2 && ((y1+h1)>y2) && ((x2+w2)>x1) && ((y2+h2)>y1))
        return true;
    else
        return false;
}

#endif // PERSONAJE_H_INCLUDED
