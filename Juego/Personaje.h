#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED

class pj{
    private:
        SDL_Surface* personaje;
        SDL_Rect pos;
        int velX, velY;
    public:
        pj(){personaje = NULL;}
        void velocidad(int x, int y){velX=x; velY=y;}
        SDL_Rect getRect(){return pos;}
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
        pos.x += velX;
    if(tecla[SDLK_LEFT]==1)
        pos.x -= velX;
    if(tecla[SDLK_UP]==1)
        pos.y -= velY+1;
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

    if(((x1+w1)>x2) && ((y1+h1)>y2) && ((x2+w2)>x1) && ((y2+h2)>y1))
        return true;
    else
        return false;
}

void pj::gravedad(bool col){
    if(col==false)
        pos.y += velY;
}

#endif // PERSONAJE_H_INCLUDED
