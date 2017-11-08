#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <windows.h>
#include <time.h>

#include "Varios.h"
#include "Personaje.h"
#include "Escenario.h"
#include "Texto.h"

using namespace std;

int main(int argc, char** argv){
    ///GENERAL
    SDL_Surface* pantalla = NULL;
    SDL_Event tecla;

    SDL_Init(SDL_INIT_EVERYTHING);
    pantalla = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Billy Manos Rapidas", "juego");

    ///NIVELES
    bool tuto=false, principal=true;

    ///PRINCIPAL
    SDL_Rect BP;
    BP.x=400;
    BP.y=200;
    BP.w=100;
    BP.h=50;

    SDL_Rect SAL;
    SAL.x=400;
    SAL.y=300;
    SAL.w=100;
    SAL.h=50;

    SDL_Rect PC;
    PC.x=400;
    PC.y=100;
    PC.w=100;
    PC.h=50;

    SDL_Rect PN;
    PN.x=250;
    PN.y=100;
    PN.w=100;
    PN.h=50;

    while(principal){
        SDL_FillRect(pantalla, &SAL, SDL_MapRGB(pantalla->format, 150, 0, 0));
        SDL_FillRect(pantalla, &BP, SDL_MapRGB(pantalla->format, 150, 0, 0));
        SDL_FillRect(pantalla, &PC, SDL_MapRGB(pantalla->format, 150, 0, 0));
        SDL_FillRect(pantalla, &PN, SDL_MapRGB(pantalla->format, 150, 0, 0));
        int x, y;

        SDL_PollEvent(&tecla);

        if(tecla.type==SDL_QUIT){
            principal=false;
        }

        if(tecla.type == SDL_KEYDOWN || tecla.type == SDL_KEYUP){
            if(tecla.key.keysym.sym == SDLK_ESCAPE){
                principal=false;
            }
        }

        if(tecla.type==SDL_MOUSEMOTION){
            x = tecla.button.x;
            y = tecla.button.y;

            if(x>BP.x && x<BP.x+BP.w && y>BP.y && y<BP.y+BP.h){
                SDL_FillRect(pantalla, &BP, SDL_MapRGB(pantalla->format, 100, 0, 0));
            }
            if(x>SAL.x && x<SAL.x+SAL.w && y>SAL.y && y<SAL.y+SAL.h){
                SDL_FillRect(pantalla, &SAL, SDL_MapRGB(pantalla->format, 100, 0, 0));
            }
            if(x>PC.x && x<PC.x+PC.w && y>PC.y && y<PC.y+PC.h){
                SDL_FillRect(pantalla, &PC, SDL_MapRGB(pantalla->format, 100, 0, 0));
            }
            if(x>PN.x && x<PN.x+PN.w && y>PN.y && y<PN.y+PN.h){
                SDL_FillRect(pantalla, &PN, SDL_MapRGB(pantalla->format, 100, 0, 0));
            }
        }

        if(tecla.type==SDL_MOUSEBUTTONDOWN){
            x = tecla.button.x;
            y = tecla.button.y;

            if(x>BP.x && x<BP.x+BP.w && y>BP.y && y<BP.y+BP.h){
                SDL_FillRect(pantalla, &BP, SDL_MapRGB(pantalla->format, 50, 0, 0));
            }
            if(x>SAL.x && x<SAL.x+SAL.w && y>SAL.y && y<SAL.y+SAL.h){
                SDL_FillRect(pantalla, &SAL, SDL_MapRGB(pantalla->format, 50, 0, 0));
            }
            if(x>PC.x && x<PC.x+PC.w && y>PC.y && y<PC.y+PC.h){
                SDL_FillRect(pantalla, &PC, SDL_MapRGB(pantalla->format, 50, 0, 0));
            }
            if(x>PN.x && x<PN.x+PN.w && y>PN.y && y<PN.y+PN.h){
                SDL_FillRect(pantalla, &PN, SDL_MapRGB(pantalla->format, 50, 0, 0));
            }
        }


        if(tecla.type==SDL_MOUSEBUTTONUP){
            x = tecla.button.x;
            y = tecla.button.y;

            if(x>BP.x && x<BP.x+BP.w && y>BP.y && y<BP.y+BP.h){
                principal=false;
                tuto=true;
            }if(x>SAL.x && x<SAL.x+SAL.w && y>SAL.y && y<SAL.y+SAL.h){
                principal=false;
            }
            if(x>PC.x && x<PC.x+PC.w && y>PC.y && y<PC.y+PC.h){
                pantalla=SDL_SetVideoMode(800,600,32,SDL_FULLSCREEN);
            }
            if(x>PN.x && x<PN.x+PN.w && y>PN.y && y<PN.y+PN.h){
                pantalla=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
            }
        }

        SDL_Flip(pantalla);
    }

    ///TUTORIAL
    int vidas=3;
    objetos suelo, flecha, caja, enemigo, vida[3];
    pj personaje;
    archivo ran;
    int dificultad=1;
    int moviendo, j=0;
    const int iniBal=700;
    int bal=iniBal;
    bool eventoEsc, random=true, algo=false;
    char palabra[30];
    strcpy(palabra, " ");

    srand(time(NULL));

    const int FPS=60;
    const int frameDelay=1000/FPS;
    Uint32 frameStart;
    int frameTime;

    for(int i=0; i<3; i++){
        vida[i].cargar("Imagenes/CorazonLleno.bmp");
    }

    vida[0].posicionar(20, 20);
    vida[1].posicionar(46, 20);
    vida[2].posicionar(72, 20);

    personaje.cargar("Imagenes/Personaje1.bmp");
    suelo.cargar("Imagenes/Piso.bmp");
    flecha.cargar("Imagenes/Flecha 2.png");
    caja.cargar("Imagenes/Caja.png");
    enemigo.cargar("Imagenes/Enemigo.png");
    flecha.posicionar(720, 470);
    caja.posicionar(400, 450);
    enemigo.posicionar(iniBal, 420);
    personaje.posicionar(100, 420);
    personaje.velocidad(3);
    flecha.pintarColorFondo(255,255,255);

    ran.random(dificultad);

    while(tuto){
        frameStart=SDL_GetTicks();
        pintar(pantalla, 110, 190, 250);

        suelo.posicionar(j, 400);
        suelo.mostrar(pantalla);
        for(int i=0; i<3; i++){
            vida[i].pintarColorFondo(180, 120, 80);
            vida[i].mostrar(pantalla);
        }

        personaje.mostrar(pantalla);
        escribirEnPantalla(palabra, pantalla, posxPalabraRandom, posyPalabraRandom);

        if(algo==true){
            objetos bala;
            bala.cargar("Imagenes/Bala.png");
            ran.mostrarRand(pantalla);
            if(ran.estado(pantalla, palabra)==1){
                strcpy(palabra, " ");
                ran.random(dificultad);
            }
            personaje.posicionar(50, 420);
            bala.mostrar(pantalla);
            enemigo.mostrar(pantalla);
            bala.posicionar(bal-=5, 450);

            if(personaje.colision(bala.getRect())==true){
                if(vidas==3){
                    vida[2].cargar("Imagenes/CorazonVacio.bmp");
                    vidas--;
                }else if(vidas==2){
                    vida[1].cargar("Imagenes/CorazonVacio.bmp");
                    vidas--;
                }else if(vidas==1){
                    vida[0].cargar("Imagenes/CorazonVacio.bmp");
                    vidas--;
                }

                if(vidas==0){
                    vidas=3;
                    for(int i=0; i<3; i++){
                        vida[i].cargar("Imagenes/CorazonLleno.bmp");
                    }
                    algo=false;
                    personaje.velocidad(3);
                }

                bal=iniBal;
            }
        }

        if(ran.estado(pantalla, palabra)==2){
            flecha.mostrar(pantalla);
            escribirEnPantalla("CONTINUAR", pantalla, 685, 450);
            random=false;
            personaje.velocidad(3);
            algo=false;
            bal=iniBal;
        }

        if(moviendo==1 && personaje.getPosX()>350 && random==false){
            suelo.posicionar(j-=3, 400);
        }

        if(suelo.getPosX() ==-801){
            strcpy(palabra, " ");
            ran.random(dificultad);
            caja.posicionar(500, 450);
            random=true;
            algo=false;
        }

        if(personaje.colision(caja.getRect())){
            algo=true;
            personaje.velocidad(0);
        }


        eventoEsc=SDL_PollEvent(&tecla);

        if(tecla.type==SDL_QUIT){
            tuto=false;
        }

        if(tecla.type == SDL_KEYDOWN || tecla.type == SDL_KEYUP){
            if(tecla.key.keysym.sym == SDLK_ESCAPE){
                tuto=false;
            }

            moviendo=personaje.mover(random);


            if(algo==true){
                if(tecla.type == SDL_KEYDOWN){
                    if(random){
                        while(eventoEsc){
                            eventoEsc=escribir(tecla, palabra);
                        }
                    }
                }
            }

        }

        SDL_Flip(pantalla);
        frameTime=SDL_GetTicks()-frameStart;
        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }

    return 0;
}
