#ifndef TEXTO_H_INCLUDED
#define TEXTO_H_INCLUDED

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
        void colorFondo(int rojo, int verde, int azul){bgcolor.r=rojo;  bgcolor.g=verde; bgcolor.b=azul;}
        void renderizar(){
            ttext = TTF_RenderText_Shaded(fuente,texto,fgcolor,bgcolor);
        }
        void posicion(int x, int y){
            rectangulo.y=y;
            rectangulo.x=x;
        }
        void pintarColorFondo(int rojo, int verde, int azul){SDL_SetColorKey(ttext,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(ttext->format,rojo,verde,azul));}
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
    if(tecla.key.keysym.sym != SDLK_DOWN)
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
        return true;

    return false;
}

bool escribir(SDL_Event tecla, char* palabra){
    char* letra;
    if(restricciones(tecla)==true){
        if(tecla.key.keysym.sym==SDLK_SPACE)
            strcat(palabra, " ");
        else if(tecla.key.keysym.sym==SDLK_KP0)
            strcat(palabra, "0");
        else if(tecla.key.keysym.sym==SDLK_KP1)
            strcat(palabra, "1");
        else if(tecla.key.keysym.sym==SDLK_KP2)
            strcat(palabra, "2");
        else if(tecla.key.keysym.sym==SDLK_KP3)
            strcat(palabra, "3");
        else if(tecla.key.keysym.sym==SDLK_KP4)
            strcat(palabra, "4");
        else if(tecla.key.keysym.sym==SDLK_KP5)
            strcat(palabra, "5");
        else if(tecla.key.keysym.sym==SDLK_KP6)
            strcat(palabra, "6");
        else if(tecla.key.keysym.sym==SDLK_KP7)
            strcat(palabra, "7");
        else if(tecla.key.keysym.sym==SDLK_KP8)
            strcat(palabra, "8");
        else if(tecla.key.keysym.sym==SDLK_KP9)
            strcat(palabra, "9");
        else if(tecla.key.keysym.sym)
            letra=SDL_GetKeyName(tecla.key.keysym.sym);
    }

    strcat(palabra, letra);

    return false;
}

#endif // TEXTO_H_INCLUDED
