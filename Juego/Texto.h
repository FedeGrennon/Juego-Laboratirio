#ifndef TEXTO_H_INCLUDED
#define TEXTO_H_INCLUDED

class cadena{
    private:
        SDL_Color bgcolor,fgcolor;
        SDL_Rect rectangulo;
        SDL_Surface *ttext;
        TTF_Font *fuente;
        char* texto;
        char* msg;

    public:
        cadena(){
            TTF_Init();
            atexit(TTF_Quit);
        }

        void cargar(char* tipografia, int tamFuente){fuente = TTF_OpenFont(tipografia,tamFuente);}
        void escribirCadena(char* a){strcpy(texto, a);}
        void colorRelleno(int rojo, int verde, int azul){fgcolor.r=rojo;  fgcolor.g=verde; fgcolor.b=azul;}
        void colorFondo(int rojo, int verde, int azul){bgcolor.r=rojo;  bgcolor.g=verde; bgcolor.b=azul;}
        void renderizar(){
            sprintf(msg,"%s",texto);
            ttext = TTF_RenderText_Shaded(fuente,msg,fgcolor,bgcolor);
        }
        void posicion(int x, int y){
            rectangulo.y=y;
            rectangulo.x=x;
        }
        void pintarColorFondo(){SDL_SetColorKey(ttext,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(ttext->format,bgcolor.r,bgcolor.g,bgcolor.b));}
        void mostrar(SDL_Surface* pantalla){SDL_BlitSurface(ttext,NULL,pantalla,&rectangulo);}

        ~cadena(){
            TTF_CloseFont(fuente);
            SDL_FreeSurface(ttext);
        }
};


#endif // TEXTO_H_INCLUDED
