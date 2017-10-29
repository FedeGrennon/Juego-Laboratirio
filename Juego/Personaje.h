#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED

class pj{
    private:
        SDL_Surface* personaje;
        SDL_Rect pos;
    public:
        pj(){personaje = NULL;}
        void cargar(char* imagen){personaje=IMG_Load(imagen);}
        void posicionar(float x=0, float y=0){
            pos.x=x;
            pos.y=y;
            pos.w=personaje->w;
            pos.h=personaje->h;
        }
        void mostrar(SDL_Surface* pantalla){SDL_BlitSurface(personaje, NULL, pantalla, &pos);}
        void mover();
        bool colision(SDL_Rect objAcolisionar);
        void gravedad(bool col);
        ~pj(){SDL_FreeSurface(personaje);}
};

void pj::mover(){
    SDL_Event tec;
    Uint8 *tecla;
    tecla=SDL_GetKeyState(NULL);

    SDL_PollEvent(&tec);

    if(tecla[SDLK_RIGHT]==1)
        pos.x += 1;
    if(tecla[SDLK_LEFT]==1)
        pos.x -= 1;
    if(tecla[SDLK_UP]==1)
        pos.y -= 1;
    /*if(tecla[SDLK_DOWN]==1)
        pos.y += 1;*/
}

bool pj::colision(SDL_Rect objAcolisionar){
    int w1, h1, x1, y1, w2, h2, x2, y2;
    w1=pos.w;
    h1=pos.h;
    x1=pos.x;
    y1=pos.y;
    w2=pos.w;
    h2=pos.h;
    x2=pos.x;
    y2=pos.y;

    if (((x1+w1)>x2) && ((y1+h1)>y2) && ((x2+w2)>x1) && ((y2+h2)>y1))
        return true;
    else
        return false;
}

void pj::gravedad(bool col){
    if(col == true)
        pos.y += 1;
    else
        pos.y =0;
}

#endif // PERSONAJE_H_INCLUDED
