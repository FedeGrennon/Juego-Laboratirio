#ifndef IMAGENES_H_INCLUDED
#define IMAGENES_H_INCLUDED

class imagen{
    protected:
        SDL_Surface *img;
        SDL_Rect pos, muestral;
    public:
        imagen(){img=NULL;}
        void cargar(char* imagen){img=IMG_Load(imagen);}
        void posicion(int, int);
        void espacioMuestral(int, int, int, int);
        void mostrar(SDL_Surface* pantalla){SDL_BlitSurface(img, &muestral, pantalla, &pos);}
        void pintarColorFondo(int rojo=244, int verde=207, int azul=126){SDL_SetColorKey(img, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(img->format,rojo,verde,azul));}
        ~imagen(){SDL_FreeSurface(img);}
};

void imagen::posicion(int x=0, int y=0){
    pos.x=x;
    pos.y=y;
    pos.w=img->w;
    pos.h=img->h;
}

void imagen::espacioMuestral(int w, int h, int x=0, int y=0){
    muestral.x=x;
    muestral.y=y;
    muestral.w=w;
    muestral.h=h;
}

#endif // IMAGENES_H_INCLUDED
