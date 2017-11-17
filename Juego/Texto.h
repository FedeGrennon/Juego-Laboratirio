#ifndef TEXTO_H_INCLUDED
#define TEXTO_H_INCLUDED

#include "Personaje.h"

const char* rutaArchivoNormal="Archivos/palabrasNor.dat";
const char* rutaArchivoDificil="Archivos/palabrasDif.dat";
const int posxPalabraRandom=600;
const int posyPalabraRandom=20;

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
        void colorRelleno(int rojo, int verde, int azul){fgcolor.r=rojo;  fgcolor.g=verde; fgcolor.b=azul;}
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

bool restricciones(SDL_Event tecla){
    if(tecla.key.keysym.sym != SDLK_RIGHT)
    if(tecla.key.keysym.sym != SDLK_LEFT)
    if(tecla.key.keysym.sym != SDLK_UP)
    if(tecla.key.keysym.sym != SDLK_DOWN)
    if(tecla.key.keysym.sym != SDLK_CLEAR)
    if(tecla.key.keysym.sym != SDLK_RETURN)
    if(tecla.key.keysym.sym != SDLK_PAUSE)
    if(tecla.key.keysym.sym != SDLK_ESCAPE)
    if(tecla.key.keysym.sym != SDLK_EXCLAIM)
    if(tecla.key.keysym.sym != SDLK_QUOTEDBL)
    if(tecla.key.keysym.sym != SDLK_HASH)
    if(tecla.key.keysym.sym != SDLK_DOLLAR)
    if(tecla.key.keysym.sym != SDLK_AMPERSAND)
    if(tecla.key.keysym.sym != SDLK_QUOTE)
    if(tecla.key.keysym.sym != SDLK_LEFTPAREN)
    if(tecla.key.keysym.sym != SDLK_RIGHTPAREN)
    if(tecla.key.keysym.sym != SDLK_ASTERISK)
    if(tecla.key.keysym.sym != SDLK_PLUS)
    if(tecla.key.keysym.sym != SDLK_COMMA)
    if(tecla.key.keysym.sym != SDLK_MINUS)
    if(tecla.key.keysym.sym != SDLK_PERIOD)
    if(tecla.key.keysym.sym != SDLK_SLASH)
    if(tecla.key.keysym.sym != SDLK_COLON)
    if(tecla.key.keysym.sym != SDLK_SEMICOLON)
    if(tecla.key.keysym.sym != SDLK_LESS)
    if(tecla.key.keysym.sym != SDLK_EQUALS)
    if(tecla.key.keysym.sym != SDLK_GREATER)
    if(tecla.key.keysym.sym != SDLK_QUESTION)
    if(tecla.key.keysym.sym != SDLK_AT)
    if(tecla.key.keysym.sym != SDLK_LEFTBRACKET)
    if(tecla.key.keysym.sym != SDLK_BACKSLASH)
    if(tecla.key.keysym.sym != SDLK_RIGHTBRACKET)
    if(tecla.key.keysym.sym != SDLK_CARET)
    if(tecla.key.keysym.sym != SDLK_UNDERSCORE)
    if(tecla.key.keysym.sym != SDLK_BACKQUOTE)
    if(tecla.key.keysym.sym != SDLK_DELETE)
    if(tecla.key.keysym.sym != SDLK_KP_PERIOD)
    if(tecla.key.keysym.sym != SDLK_KP_DIVIDE)
    if(tecla.key.keysym.sym != SDLK_KP_MULTIPLY)
    if(tecla.key.keysym.sym != SDLK_KP_MINUS)
    if(tecla.key.keysym.sym != SDLK_KP_PLUS)
    if(tecla.key.keysym.sym != SDLK_KP_ENTER)
    if(tecla.key.keysym.sym != SDLK_KP_EQUALS)
    if(tecla.key.keysym.sym != SDLK_INSERT)
    if(tecla.key.keysym.sym != SDLK_HOME)
    if(tecla.key.keysym.sym != SDLK_END)
    if(tecla.key.keysym.sym != SDLK_PAGEUP)
    if(tecla.key.keysym.sym != SDLK_PAGEDOWN)
    if(tecla.key.keysym.sym != SDLK_F1)
    if(tecla.key.keysym.sym != SDLK_F2)
    if(tecla.key.keysym.sym != SDLK_F3)
    if(tecla.key.keysym.sym != SDLK_F4)
    if(tecla.key.keysym.sym != SDLK_F5)
    if(tecla.key.keysym.sym != SDLK_F6)
    if(tecla.key.keysym.sym != SDLK_F7)
    if(tecla.key.keysym.sym != SDLK_F8)
    if(tecla.key.keysym.sym != SDLK_F9)
    if(tecla.key.keysym.sym != SDLK_F10)
    if(tecla.key.keysym.sym != SDLK_F11)
    if(tecla.key.keysym.sym != SDLK_F12)
    if(tecla.key.keysym.sym != SDLK_F13)
    if(tecla.key.keysym.sym != SDLK_F14)
    if(tecla.key.keysym.sym != SDLK_F15)
    if(tecla.key.keysym.sym != SDLK_NUMLOCK)
    if(tecla.key.keysym.sym != SDLK_CAPSLOCK)
    if(tecla.key.keysym.sym != SDLK_SCROLLOCK)
    if(tecla.key.keysym.sym != SDLK_RSHIFT)
    if(tecla.key.keysym.sym != SDLK_LSHIFT)
    if(tecla.key.keysym.sym != SDLK_RCTRL)
    if(tecla.key.keysym.sym != SDLK_LCTRL)
    if(tecla.key.keysym.sym != SDLK_RALT)
    if(tecla.key.keysym.sym != SDLK_LALT)
    if(tecla.key.keysym.sym != SDLK_RMETA)
    if(tecla.key.keysym.sym != SDLK_LMETA)
    if(tecla.key.keysym.sym != SDLK_LSUPER)
    if(tecla.key.keysym.sym != SDLK_RSUPER)
    if(tecla.key.keysym.sym != SDLK_MODE)
    if(tecla.key.keysym.sym != SDLK_HELP)
    if(tecla.key.keysym.sym != SDLK_PRINT)
    if(tecla.key.keysym.sym != SDLK_SYSREQ)
    if(tecla.key.keysym.sym != SDLK_BREAK)
    if(tecla.key.keysym.sym != SDLK_MENU)
    if(tecla.key.keysym.sym != SDLK_POWER)
    if(tecla.key.keysym.sym != SDLK_EURO)
    if(tecla.key.keysym.sym != SDLK_TAB)
    if(tecla.key.keysym.sym != SDLK_BACKSPACE)
    if(tecla.key.keysym.sym != SDLK_SPACE)
    if(tecla.key.keysym.sym != SDLK_KP0)
    if(tecla.key.keysym.sym != SDLK_KP1)
    if(tecla.key.keysym.sym != SDLK_KP2)
    if(tecla.key.keysym.sym != SDLK_KP3)
    if(tecla.key.keysym.sym != SDLK_KP4)
    if(tecla.key.keysym.sym != SDLK_KP5)
    if(tecla.key.keysym.sym != SDLK_KP6)
    if(tecla.key.keysym.sym != SDLK_KP7)
    if(tecla.key.keysym.sym != SDLK_KP8)
    if(tecla.key.keysym.sym != SDLK_KP9)
        return true;

    return false;
}

bool escribir(SDL_Event tecla, char* palabra){
    char* letra;
    if(restricciones(tecla)==true)
        letra=SDL_GetKeyName(tecla.key.keysym.sym);
    ///getkeystate
    if(palabra[0]==' '){
        strcpy(palabra, letra);
    }else
        strcat(palabra, letra);


    return false;
}

void escribirEnPantalla(char* texto, SDL_Surface* pantalla, int posx=0, int posy=0, int rr=0, int gr=0, int br=0, int rf=0, int gf=0, int bf=0){
    cadena txt;

    txt.cargar("Tipografias/Letra.ttf", 20);
    txt.escribirCadena(texto);
    txt.colorRelleno(rr,gr,br);
    txt.colorFondo(rf,gf,bf);
    txt.renderizar();
    txt.posicion(posx, posy);
    txt.pintarColorFondo(rf,gf,bf);
    txt.mostrar(pantalla);
}


class archivo{
    private:
        char palabra[20];
        char reserva[20];
    public:
        bool LeerEnDiscoNormal(int pos);
        bool LeerEnDiscoDificil(int pos);
        int cantidadNormal();
        int cantidadDificil();
        void random(int dificultad);
        void mostrarRand(SDL_Surface* pantalla);
        int estado(SDL_Surface* pantalla, char* verif);
        char getLetra(int pos){return palabra[0];}
        char* getPalabra(){return palabra;}
        void setPlabra(char* pal){strcpy(palabra, pal);}
        char* getReserva(){return reserva;}
};

bool archivo::LeerEnDiscoNormal(int pos){
        bool x;
        FILE *p;
        p=fopen(rutaArchivoNormal,"rb");
        if(p==NULL)
            return false;

        fseek(p,pos*sizeof *this,0);

        x=fread(this,sizeof *this,1,p);
        fclose(p);
        return x;
}

int archivo::cantidadNormal(){
    FILE *p;
    p=fopen(rutaArchivoNormal,"rb");
    if(p==NULL)
        return -1;
    fseek(p,0,2);
    long tam = ftell(p);
    int cant = tam/sizeof *this;
    fclose(p);
    return cant;

}

bool archivo::LeerEnDiscoDificil(int pos){
        bool x;
        FILE *p;
        p=fopen(rutaArchivoDificil,"rb");
        if(p==NULL)
            return false;

        fseek(p,pos*sizeof *this,0);

        x=fread(this,sizeof *this,1,p);
        fclose(p);
        return x;
}

int archivo::cantidadDificil(){
    FILE *p;
    p=fopen(rutaArchivoDificil,"rb");
    if(p==NULL)
        return -1;
    fseek(p,0,2);
    long tam = ftell(p);
    int cant = tam/sizeof *this;
    fclose(p);
    return cant;

}

void archivo::random(int dificultad){
    int tam, numRand;
    if(dificultad==1){
            tam=cantidadNormal();
            numRand=rand()%tam;
            LeerEnDiscoNormal(numRand);
    }else{
            tam=cantidadDificil();
            numRand=rand()%tam;
            LeerEnDiscoDificil(numRand);
    }
}

int archivo::estado(SDL_Surface* pantalla, char* verif){
    int tamPalabara, tamVerfi, aux;

    tamVerfi=strlen(verif); //=1
    tamPalabara=strlen(palabra); //=5

    aux=tamVerfi-1;//=0
    ///NO HAYA ERROR CON LA PALABRA QUE AL PRINCIPIO ES UN ESPACIO
    if(verif[0]==' '){
        return 4;
    }
    ///RETORNA 2 CUANDO LA PALABRA SE COMPLETO
    if(palabra[tamPalabara-1]=='.' || palabra[0]==' '){
        return 2;
    }else if(palabra[aux]==verif[aux]){
        palabra[aux]='.';
        verif[aux]='.';
        ///RETORNA 0 CUANDO LA LETRA ES CORRECTA
        return 0;
    }else{
        ///RETORNA 1 CUANDO SE CONFUNDE
        if(verif[0]=='.')
            verif[aux]='\0';
        else
            verif[aux]=' ';
        return 1;
    }
}

#endif // TEXTO_H_INCLUDED

