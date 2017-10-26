#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED

class pj{
    private:
        SDL_Surface* personaje;
        SDL_Rect pos;
    public:
        pj(){personaje = NULL;}
        void cargar(){personaje=SDL_LoadBMP("Personaje.bmp");}
        void posicionar(float x=0, float y=0){
            pos.x=x;
            pos.y=y;
        }
        void mostrar(SDL_Surface* pantalla){SDL_BlitSurface(personaje, NULL, pantalla, &pos);}
        ~pj(){SDL_FreeSurface(personaje);}
        void mover();
};

void pj::mover(){
    Uint8 *tecla;
    tecla=SDL_GetKeyState(NULL);
    if(tecla[SDLK_RIGHT]==1)
        pos.x += 1;
    if(tecla[SDLK_LEFT]==1)
        pos.x -= 1;
}

#endif // PERSONAJE_H_INCLUDED
