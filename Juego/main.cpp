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
    Mix_Chunk *tiro, *recarga;

    SDL_Init(SDL_INIT_EVERYTHING);
    pantalla = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Billy Manos Rapidas", "juego");

    Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);

    atexit(Mix_CloseAudio);


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
    int vidas=3, vidaEne=3;
    objetos suelo, flecha, enemigo, vida[3], vidaEnemigo[4];
    pj personaje;
    archivo ran;
    int dificultad=1;
    int moviendo, j=0, anim=0;
    const int iniBal=700;
    int bal=iniBal;
    bool eventoEsc, random=true, modo=false;
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
    vidaEnemigo[0].cargar("Imagenes/VidaEnemigoVacia.bmp");
    vidaEnemigo[1].cargar("Imagenes/VidaEnemigo1.bmp");
    vidaEnemigo[2].cargar("Imagenes/VidaEnemigo2.bmp");
    vidaEnemigo[3].cargar("Imagenes/VidaEnemigoLlena.bmp");

    for(int i=0; i<4; i++)
        vidaEnemigo[i].posicionar(iniBal, 390);

    vida[0].posicionar(20, 20);
    vida[1].posicionar(46, 20);
    vida[2].posicionar(72, 20);

    personaje.cargar("Imagenes/PersonajeDer.png");
    suelo.cargar("Imagenes/Piso.bmp");
    flecha.cargar("Imagenes/Flecha 2.png");
    enemigo.cargar("Imagenes/Enemigo.png");
    flecha.posicionar(720, 470);
    enemigo.posicionar(iniBal, 420);
    personaje.posicionar(100, 450);
    personaje.velocidad(3);
    flecha.pintarColorFondo(255,255,255);

    ran.random(dificultad);

    tiro = Mix_LoadWAV("Sonidos/Tiro.wav");
    recarga = Mix_LoadWAV("Sonidos/Recarga.wav");

    int der=0, canal;
    bool primerTiro=true;

    personaje.animacion(200);

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

        if(modo==true){
            if(primerTiro)
                canal = Mix_PlayChannel(-1, tiro, 0);
            personaje.animacion(0);
            objetos bala;
            bala.cargar("Imagenes/Bala.png");
            ran.mostrarRand(pantalla);
            if(ran.estado(pantalla, palabra)==1){
                strcpy(palabra, " ");
                ran.setPlabra(ran.getReserva());
            }

            personaje.posicionar(50, 420);
            bala.mostrar(pantalla);
            enemigo.mostrar(pantalla);
            bala.posicionar(bal-=2, 450);

            primerTiro=false;

            if(vidaEne==3){
                vidaEnemigo[3].mostrar(pantalla);
            }else if(vidaEne==2){
                vidaEnemigo[2].pintarColorFondo(180, 120, 80);
                vidaEnemigo[2].mostrar(pantalla);
            }else if(vidaEne==1){
                vidaEnemigo[1].pintarColorFondo(180, 120, 80);
                vidaEnemigo[1].mostrar(pantalla);
            }

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
                    vidaEne=3;
                    for(int i=0; i<3; i++){
                        vida[i].cargar("Imagenes/CorazonLleno.bmp");
                    }
                    modo=false;
                    primerTiro=true;
                    personaje.velocidad(3);
                }
                bal=iniBal;
                canal = Mix_PlayChannel(-1, tiro, 0);
            }
        }

        if(ran.estado(pantalla, palabra)==2){
            vidaEne--;
            strcpy(palabra, " ");
            ran.random(dificultad);
            if(vidaEne==0){
                random=false;
                personaje.velocidad(3);
                modo=false;
                bal=iniBal;
                vidaEne=3;
                primerTiro=true;
            }
        }

        if(random==false){
            flecha.mostrar(pantalla);
            escribirEnPantalla("CONTINUAR", pantalla, 685, 450);
        }

        if(moviendo==1 && personaje.getPosX()>350 && random==false){
            suelo.posicionar(j-=3, 400);
        }

        if(suelo.getPosX() ==-801){
            strcpy(palabra, " ");
            ran.random(dificultad);
            random=true;
            modo=false;
        }

        eventoEsc=SDL_PollEvent(&tecla);

        if(tecla.type==SDL_QUIT){
            tuto=false;
        }

        if(tecla.type == SDL_KEYDOWN || tecla.type == SDL_KEYUP){
            if(tecla.key.keysym.sym == SDLK_ESCAPE){
                tuto=false;
            }

            if(random==true){
                if(tecla.key.keysym.sym == SDLK_RETURN){
                    modo=true;
                    personaje.velocidad(0);
                }
            }

            moviendo=personaje.mover(random);

            if(modo==true){
                if(tecla.type == SDL_KEYDOWN){
                    if(random){
                        while(eventoEsc){
                            eventoEsc=escribir(tecla, palabra);
                        }
                    }
                }
            }
        }
        if(modo==false){
            if(moviendo==1){
                if(der%2==0){
                    personaje.animacion(0);
                }else if(der%15==0){
                    personaje.animacion(50);
                }
            }else if(moviendo==2){
                if(der%2==0){
                    personaje.animacion(150);
                }else if(der%15==0){
                    personaje.animacion(100);
                }
            }else if(moviendo==3){
                personaje.animacion(300);
            }else if(moviendo==4){
                if(der%2==0){
                    personaje.animacion(200);
                }else if(der%15==0){
                    personaje.animacion(250);
                }
            }
        }

        der++;

        SDL_Flip(pantalla);
        frameTime=SDL_GetTicks()-frameStart;
        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }

    Mix_FreeChunk(tiro);
    Mix_FreeChunk(recarga);

    return 0;
}
