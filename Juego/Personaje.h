#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED

class pj{
    private:
        SDL_Surface* personaje;
        SDL_Rect pos;
    public:
        pj(){personaje = NULL;}
        void cargar(){personaje=SDL_LoadBMP("Personaje.bmp");}
        void posicionar(int x=0, int y=0){
            pos.x=x;
            pos.y=y;
        }
        void mostrar(SDL_Surface* pantalla){SDL_BlitSurface(personaje, NULL, pantalla, &pos);}
        ~pj(){SDL_FreeSurface(personaje);}
        void mover(SDL_Event tecla);
};

void pj::mover(SDL_Event tecla){
    if (tecla.type == SDL_KEYDOWN){
        switch(tecla.key.keysym.sym){
            case SDLK_LEFT:
                pos.x -= 1;
            break;

            case SDLK_RIGHT:
                pos.x += 1;
            break;
        }
    }
}

#endif // PERSONAJE_H_INCLUDED
