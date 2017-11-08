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
    if(tecla.key.keysym.sym != SDLK_RIGHT)return true;
    else if(tecla.key.keysym.sym != SDLK_LEFT)return true;
    else if(tecla.key.keysym.sym != SDLK_UP)return true;
    else if(tecla.key.keysym.sym != SDLK_DOWN)return true;
    else if(tecla.key.keysym.sym != SDLK_CLEAR)return true;
    else if(tecla.key.keysym.sym != SDLK_RETURN)return true;
    else if(tecla.key.keysym.sym != SDLK_PAUSE)return true;
    else if(tecla.key.keysym.sym != SDLK_ESCAPE)return true;
    else if(tecla.key.keysym.sym != SDLK_EXCLAIM)return true;
    else if(tecla.key.keysym.sym != SDLK_QUOTEDBL)return true;
    else if(tecla.key.keysym.sym != SDLK_HASH)return true;
    else if(tecla.key.keysym.sym != SDLK_DOLLAR)return true;
    else if(tecla.key.keysym.sym != SDLK_AMPERSAND)return true;
    else if(tecla.key.keysym.sym != SDLK_QUOTE)return true;
    else if(tecla.key.keysym.sym != SDLK_LEFTPAREN)return true;
    else if(tecla.key.keysym.sym != SDLK_RIGHTPAREN)return true;
    else if(tecla.key.keysym.sym != SDLK_ASTERISK)return true;
    else if(tecla.key.keysym.sym != SDLK_PLUS)return true;
    else if(tecla.key.keysym.sym != SDLK_COMMA)return true;
    else if(tecla.key.keysym.sym != SDLK_MINUS)return true;
    else if(tecla.key.keysym.sym != SDLK_PERIOD)return true;
    else if(tecla.key.keysym.sym != SDLK_SLASH)return true;
    else if(tecla.key.keysym.sym != SDLK_COLON)return true;
    else if(tecla.key.keysym.sym != SDLK_SEMICOLON)return true;
    else if(tecla.key.keysym.sym != SDLK_LESS)return true;
    else if(tecla.key.keysym.sym != SDLK_EQUALS)return true;
    else if(tecla.key.keysym.sym != SDLK_GREATER)return true;
    else if(tecla.key.keysym.sym != SDLK_QUESTION)return true;
    else if(tecla.key.keysym.sym != SDLK_AT)return true;
    else if(tecla.key.keysym.sym != SDLK_LEFTBRACKET)return true;
    else if(tecla.key.keysym.sym != SDLK_BACKSLASH)return true;
    else if(tecla.key.keysym.sym != SDLK_RIGHTBRACKET)return true;
    else if(tecla.key.keysym.sym != SDLK_CARET)return true;
    else if(tecla.key.keysym.sym != SDLK_UNDERSCORE)return true;
    else if(tecla.key.keysym.sym != SDLK_BACKQUOTE)return true;
    else if(tecla.key.keysym.sym != SDLK_DELETE)return true;
    else if(tecla.key.keysym.sym != SDLK_KP_PERIOD)return true;
    else if(tecla.key.keysym.sym != SDLK_KP_DIVIDE)return true;
    else if(tecla.key.keysym.sym != SDLK_KP_MULTIPLY)return true;
    else if(tecla.key.keysym.sym != SDLK_KP_MINUS)return true;
    else if(tecla.key.keysym.sym != SDLK_KP_PLUS)return true;
    else if(tecla.key.keysym.sym != SDLK_KP_ENTER)return true;
    else if(tecla.key.keysym.sym != SDLK_KP_EQUALS)return true;
    else if(tecla.key.keysym.sym != SDLK_INSERT)return true;
    else if(tecla.key.keysym.sym != SDLK_HOME)return true;
    else if(tecla.key.keysym.sym != SDLK_END)return true;
    else if(tecla.key.keysym.sym != SDLK_PAGEUP)return true;
    else if(tecla.key.keysym.sym != SDLK_PAGEDOWN)return true;
    else if(tecla.key.keysym.sym != SDLK_F1)return true;
    else if(tecla.key.keysym.sym != SDLK_F2)return true;
    else if(tecla.key.keysym.sym != SDLK_F3)return true;
    else if(tecla.key.keysym.sym != SDLK_F4)return true;
    else if(tecla.key.keysym.sym != SDLK_F5)return true;
    else if(tecla.key.keysym.sym != SDLK_F6)return true;
    else if(tecla.key.keysym.sym != SDLK_F7)return true;
    else if(tecla.key.keysym.sym != SDLK_F8)return true;
    else if(tecla.key.keysym.sym != SDLK_F9)return true;
    else if(tecla.key.keysym.sym != SDLK_F10)return true;
    else if(tecla.key.keysym.sym != SDLK_F11)return true;
    else if(tecla.key.keysym.sym != SDLK_F12)return true;
    else if(tecla.key.keysym.sym != SDLK_F13)return true;
    else if(tecla.key.keysym.sym != SDLK_F14)return true;
    else if(tecla.key.keysym.sym != SDLK_F15)return true;
    else if(tecla.key.keysym.sym != SDLK_NUMLOCK)return true;
    else if(tecla.key.keysym.sym != SDLK_CAPSLOCK)return true;
    else if(tecla.key.keysym.sym != SDLK_SCROLLOCK)return true;
    else if(tecla.key.keysym.sym != SDLK_RSHIFT)return true;
    else if(tecla.key.keysym.sym != SDLK_LSHIFT)return true;
    else if(tecla.key.keysym.sym != SDLK_RCTRL)return true;
    else if(tecla.key.keysym.sym != SDLK_LCTRL)return true;
    else if(tecla.key.keysym.sym != SDLK_RALT)return true;
    else if(tecla.key.keysym.sym != SDLK_LALT)return true;
    else if(tecla.key.keysym.sym != SDLK_RMETA)return true;
    else if(tecla.key.keysym.sym != SDLK_LMETA)return true;
    else if(tecla.key.keysym.sym != SDLK_LSUPER)return true;
    else if(tecla.key.keysym.sym != SDLK_RSUPER)return true;
    else if(tecla.key.keysym.sym != SDLK_MODE)return true;
    else if(tecla.key.keysym.sym != SDLK_HELP)return true;
    else if(tecla.key.keysym.sym != SDLK_PRINT)return true;
    else if(tecla.key.keysym.sym != SDLK_SYSREQ)return true;
    else if(tecla.key.keysym.sym != SDLK_BREAK)return true;
    else if(tecla.key.keysym.sym != SDLK_MENU)return true;
    else if(tecla.key.keysym.sym != SDLK_POWER)return true;
    else if(tecla.key.keysym.sym != SDLK_EURO)return true;
    else if(tecla.key.keysym.sym != SDLK_TAB)return true;
    else if(tecla.key.keysym.sym != SDLK_BACKSPACE)return true;
    else return false;
}


bool escribir(SDL_Event tecla, char* palabra){
    char* letra;
    if(restricciones(tecla)==true){
        if(tecla.key.keysym.sym == SDLK_SPACE)
            letra[0]=' ';
        else if(tecla.key.keysym.sym==SDLK_KP0)
            letra[0]='0';
        else if(tecla.key.keysym.sym==SDLK_KP1)
            letra[0]='1';
        else if(tecla.key.keysym.sym==SDLK_KP2)
            letra[0]='2';
        else if(tecla.key.keysym.sym==SDLK_KP3)
            letra[0]='3';
        else if(tecla.key.keysym.sym==SDLK_KP4)
            letra[0]='4';
        else if(tecla.key.keysym.sym==SDLK_KP5)
            letra[0]='5';
        else if(tecla.key.keysym.sym==SDLK_KP6)
            letra[0]='6';
        else if(tecla.key.keysym.sym==SDLK_KP7)
            letra[0]='7';
        else if(tecla.key.keysym.sym==SDLK_KP8)
            letra[0]='8';
        else if(tecla.key.keysym.sym==SDLK_KP9)
            letra[0]='9';
        else if(tecla.key.keysym.sym){
            letra=SDL_GetKeyName(tecla.key.keysym.sym);
        }
    }
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
    public:
        bool LeerEnDiscoNormal(int pos);
        bool LeerEnDiscoDificil(int pos);
        int cantidadNormal();
        int cantidadDificil();
        void random(int dificultad);
        void mostrarRand(SDL_Surface* pantalla);
        int estado(SDL_Surface* pantalla, char* verif);
        char getLetra(int pos){return palabra[0];}
        void setPlabra(char* pal){strcpy(palabra, pal);}
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

void archivo::mostrarRand(SDL_Surface* pantalla){
    escribirEnPantalla(palabra, pantalla, posxPalabraRandom, posyPalabraRandom);
}

int archivo::estado(SDL_Surface* pantalla, char* verif){
    int tamPalabara, tamVerfi, aux;

    tamVerfi=strlen(verif); //=1
    tamPalabara=strlen(palabra); //=5

    aux=tamVerfi-1; //=0
    ///NO HAYA ERROR CON LA PALABRA QUE AL PRINCIPIO ES UN ESPACIO
    if(verif[0]==' ')
        return 0;
    ///RETORNA 2 CUANDO LA PALABRA SE COMPLETO
    if(palabra[tamPalabara-1]=='.' || palabra[0]==' ' /*|| strcmp(palabra, " ")==1*/){
        return 2;
    }else if(palabra[aux]==verif[aux]){
        palabra[aux]='.';
        verif[aux]='.';
        ///RETORNA 0 CUANDO LA LETRA ES CORRECTA
        return 0;
    }else{
        ///RETORNA 1 CUANDO SE CONFUNDE
        return 1;
    }
}

#endif // TEXTO_H_INCLUDED

