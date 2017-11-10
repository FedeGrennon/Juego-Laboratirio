#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>

class cadena{
    private:
        SDL_Color bgcolor,fgcolor;
        SDL_Rect rectangulo;
        SDL_Surface *ttext;
        TTF_Font *fuente;
        char texto[100];

    public:
        cadena(){
            TTF_Init();
            atexit(TTF_Quit);
        }

        void cargar(char* tipografia, int tamFuente){fuente = TTF_OpenFont(tipografia,tamFuente);}
        void escribirCadena(char* a){strcpy(texto, a);}
        void colorRelleno(int rojo=0, int verde=0, int azul=0){fgcolor.r=rojo;  fgcolor.g=verde; fgcolor.b=azul;}
        void colorFondo(int rojo=0, int verde=0, int azul=0){bgcolor.r=rojo;  bgcolor.g=verde; bgcolor.b=azul;}
        void renderizar(){
            ttext = TTF_RenderText_Shaded(fuente,texto,fgcolor,bgcolor);
        }
        void posicion(int x, int y){
            rectangulo.y=y;
            rectangulo.x=x;
        }
        void pintarColorFondo(int rojo=0, int verde=0, int azul=0){SDL_SetColorKey(ttext,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(ttext->format,rojo,verde,azul));}
        void mostrar(SDL_Surface* pantalla){SDL_BlitSurface(ttext,NULL,pantalla,&rectangulo);}

        ~cadena(){
            TTF_CloseFont(fuente);
            SDL_FreeSurface(ttext);
        }
};

bool escribir(char* palabra, int j){
    Uint8* tecla;
    tecla=SDL_GetKeyState(NULL);

    for(int i=97; i<=122; i++){
        if(tecla[i]){
            palabra[j]=i;
            palabra[j+1]='\0';
            return true;
        }
    }
    return false;
}



int main(int argc, char** argv){
    char palabra[20];
    strcpy(palabra, " ");
    SDL_Surface* pantalla;
    Uint8* tecla;
    SDL_Event t;
    cadena txt;
    int j=0;
    bool a;


    tecla=SDL_GetKeyState(NULL);

    txt.cargar("Letra.ttf", 20);

    SDL_Init(SDL_INIT_EVERYTHING);
    pantalla = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

    while (true){
        SDL_FillRect(pantalla, 0, SDL_MapRGB(pantalla->format, 110, 190, 250));

        txt.colorRelleno();
        txt.colorFondo(110, 190, 250);
        txt.posicion(100, 100);
        txt.escribirCadena(palabra);
        txt.renderizar();
        txt.mostrar(pantalla);


        SDL_PollEvent(&t);
        if(t.type == SDL_KEYDOWN){
            a=escribir(palabra, j);
            if(a){
                t.type=SDL_KEYUP;
                j++;
                if(j>=20){
                    j=0;
                }
            }

            if(tecla[SDLK_ESCAPE]==1)
                return 0;
        }

        SDL_Flip(pantalla);
    }

    return 0;
}
