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
    const int FPS=60;
    const int frameDelay=1000/FPS;
    Uint32 frameStart;
    int frameTime;

    SDL_Init(SDL_INIT_EVERYTHING);
    pantalla = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Billy Manos Rapidas", "juego");

    Mix_OpenAudio(44100, AUDIO_S16, 2, 4096);

    atexit(Mix_CloseAudio);


    ///NIVELES
    bool tuto=false, principal=false, presentacion=true;


    ///PRESENTACION
    pj present;
    int anim=0;

    present.cargar("Imagenes/Presentacion.png");
    present.posicionar(110, 25);
    present.animacion(0, 0, 580, 550);

    while(presentacion){
        frameStart=SDL_GetTicks();
        pintar(pantalla, 51, 51, 51);

        present.pintarColorFondo(51, 51, 51);
        present.mostrar(pantalla);

        if(anim==0 && anim<5){
            present.animacion(0);
        }else if(anim>5 && anim<10){
            present.animacion(580, 0, 580, 550);
        }else if(anim>10 && anim<15){
            present.animacion(1160, 0, 580, 550);
        }else if(anim>15 && anim<20){
            present.animacion(1740, 0, 580, 550);
        }else if(anim>20 && anim<25){
            present.animacion(2320, 0, 580, 550);
        }else if(anim>25 && anim<30){
            present.animacion(0, 550, 580, 550);
        }else if(anim>30 && anim<35){
            present.animacion(580, 550, 580, 550);
        }else if(anim>35 && anim<50){
            present.animacion(1160, 550, 580, 550);
        }else if(anim>50){
            present.animacion(1740, 550, 580, 550);
        }

        anim++;

        if(anim==200){
            presentacion=false;
            principal=true;
        }

        SDL_PollEvent(&tecla);

        if(tecla.type==SDL_QUIT){
            principal=false;
        }

        SDL_Flip(pantalla);
        frameTime=SDL_GetTicks()-frameStart;
        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }


    ///PRINCIPAL
    objetos pri, vol;
    Mix_Music *cancion;
    int canal;
    bool pausarMusica=false;

    cancion = Mix_LoadMUS("Sonidos/TemaPrincipal.mp3");

    pri.cargar("Imagenes/Principal.png");
    pri.posicionar();
    pri.EspacioMuestral(800, 600);
    vol.cargar("Imagenes/Vol.png");
    vol.posicionar(567, 110);
    vol.EspacioMuestral(30, 30);

    SDL_Rect BP;
    BP.x=365;
    BP.y=233;
    BP.w=100;
    BP.h=50;

    SDL_Rect SAL;
    SAL.x=375;
    SAL.y=340;
    SAL.w=100;
    SAL.h=50;

    SDL_Rect VOL;
    VOL.x=567;
    VOL.y=110;
    VOL.w=30;
    VOL.h=30;

    canal=Mix_PlayMusic(cancion, -1);
    Mix_VolumeMusic(20);

    while(principal){
        pri.mostrar(pantalla);
        vol.pintarColorFondo(51, 51, 51);
        vol.mostrar(pantalla);

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
        }

        if(tecla.type==SDL_MOUSEBUTTONDOWN && tecla.button.button==SDL_BUTTON_LEFT){
            x = tecla.button.x;
            y = tecla.button.y;
            if(x>VOL.x && x<VOL.x+VOL.w && y>VOL.y && y<VOL.y+VOL.h){
                if(pausarMusica){
                    vol.EspacioMuestral(30, 30);
                    Mix_ResumeMusic();
                    pausarMusica=false;
                    tecla.type=SDL_MOUSEBUTTONUP;
                }else{
                    vol.EspacioMuestral(30, 30, 30);
                    Mix_PauseMusic();
                    pausarMusica=true;
                    tecla.type=SDL_MOUSEBUTTONUP;
                }
            }
        }


        if(tecla.type==SDL_MOUSEBUTTONUP && tecla.button.button==SDL_BUTTON_LEFT){
            x = tecla.button.x;
            y = tecla.button.y;

            if(x>BP.x && x<BP.x+BP.w && y>BP.y && y<BP.y+BP.h){
                principal=false;
                tuto=true;
            }if(x>SAL.x && x<SAL.x+SAL.w && y>SAL.y && y<SAL.y+SAL.h){
                principal=false;
            }
        }

        SDL_Flip(pantalla);
    }

    Mix_HaltMusic();

    ///TUTORIAL
    int vidas=3, vidaEne=3;
    objetos suelo, flecha, enemigo, vida[3], vidaEnemigo[4];
    pj personaje;
    archivo ran;
    int dificultad=2;
    int moviendo=0, j=0;
    const int iniBal=700;
    int bal=iniBal, balPersonaje=80;
    bool eventoEsc, random=true, modo=false;
    Mix_Chunk *tiro, *recarga;
    char palabra[30];
    strcpy(palabra, " ");

    srand(time(NULL));

    for(int i=0; i<3; i++){
        vida[i].cargar("Imagenes/CorazonLleno.bmp");
        vida[i].EspacioMuestral(25, 22);
    }
    vidaEnemigo[0].cargar("Imagenes/VidaEnemigoVacia.bmp");
    vidaEnemigo[1].cargar("Imagenes/VidaEnemigo1.bmp");
    vidaEnemigo[2].cargar("Imagenes/VidaEnemigo2.bmp");
    vidaEnemigo[3].cargar("Imagenes/VidaEnemigoLlena.bmp");

    for(int i=0; i<4; i++){
        vidaEnemigo[i].posicionar(iniBal, 390);
        vidaEnemigo[i].EspacioMuestral(50, 15);
    }

    vida[0].posicionar(20, 20);
    vida[1].posicionar(46, 20);
    vida[2].posicionar(72, 20);

    personaje.cargar("Imagenes/Personaje.png");
    suelo.cargar("Imagenes/Piso.bmp");
    flecha.cargar("Imagenes/Flecha 2.png");
    enemigo.cargar("Imagenes/Enemigo.png");
    flecha.posicionar(720, 470);
    enemigo.posicionar(iniBal, 420);
    personaje.posicionar(100, 350);
    personaje.velocidad(3);
    flecha.pintarColorFondo(255,255,255);
    suelo.EspacioMuestral(1600, 400);
    flecha.EspacioMuestral(50, 50);
    enemigo.EspacioMuestral(50, 100);

    ran.random(dificultad);

    tiro = Mix_LoadWAV("Sonidos/Tiro.wav");
    recarga = Mix_LoadWAV("Sonidos/Recarga.wav");

    int der=0;
    bool primerTiro=true;

    personaje.animacion(0);

    while(tuto){
        frameStart=SDL_GetTicks();
        pintar(pantalla, 110, 190, 250);

        suelo.posicionar(j, 400);
        suelo.mostrar(pantalla);
        for(int i=0; i<3; i++){
            vida[i].pintarColorFondo(180, 120, 80);
            vida[i].mostrar(pantalla);
        }

        personaje.pintarColorFondo(51, 51, 51);
        personaje.mostrar(pantalla);

        if(modo==true){
            if(primerTiro)
                canal = Mix_PlayChannel(-1, tiro, 0);
            personaje.animacion(0);
            objetos bala;
            bala.cargar("Imagenes/BalaEne.png");
            bala.EspacioMuestral(15,5);
            escribirEnPantalla(ran.getPalabra(), pantalla, bal-20, 425);
            escribirEnPantalla(palabra, pantalla, bal-20, 425);

            personaje.posicionar(50, 420);
            bala.mostrar(pantalla);
            enemigo.mostrar(pantalla);
            bala.posicionar(bal-=5, 450);

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
                    strcpy(palabra, " ");
                    ran.setPlabra(ran.getReserva());
                }else{
                    bal=iniBal;
                    canal = Mix_PlayChannel(-1, tiro, 0);
                    strcpy(palabra, " ");
                    ran.random(dificultad);
                }
            }
        }

        if(ran.estado(pantalla, palabra)==2){
            vidaEne--;
            if(vidaEne==0){
                random=false;
                personaje.velocidad(3);
                modo=false;
                bal=iniBal;
                vidaEne=3;
                primerTiro=true;
            }else{
                if(primerTiro==false)
                    canal = Mix_PlayChannel(-1, tiro, 0);
                strcpy(palabra, " ");
                ran.random(dificultad);
                bal=iniBal;
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
                            if(ran.estado(pantalla, palabra)!=1){
                                if(restricciones(tecla))
                                    eventoEsc=escribir(tecla, palabra);
                                else
                                    eventoEsc=false;
                            }else
                                eventoEsc=false;
                        }
                    }
                }
            }
        }

        if(modo==false){
            if(moviendo==0){
                if(der>100)
                    der=0;
                if(der==0 && der<50){
                    personaje.animacion(0);
                }else if(der>50 && der<100){
                    personaje.animacion(131);
                }
            }else if(moviendo==1){
                if(der>60)
                    der=0;
                if(der==0 && der<10){
                    personaje.animacion(512);
                }else if(der>10 && der<20){
                    personaje.animacion(646);
                }else if(der>20 && der<30){
                    personaje.animacion(512);
                }else if(der>30 && der<40){
                    personaje.animacion(777);
                }else if(der>40 && der<50){
                    personaje.animacion(901);
                }else if(der>50 && der<60){
                    personaje.animacion(777);
                }
            }else if(moviendo==2){
                if(der >60)
                    der=0;
                if(der==0 && der<10){
                    personaje.animacion(0, 200);
                }else if(der>10 && der<20){
                    personaje.animacion(130, 200);
                }else if(der>20 && der<30){
                    personaje.animacion(0, 200);
                }else if(der>30 && der<40){
                    personaje.animacion(261, 200);
                }else if(der>40 && der<50){
                    personaje.animacion(380, 200);
                }else if(der>50 && der<60){
                    personaje.animacion(261, 200);
                }
            }
        }


        der++;

        SDL_Flip(pantalla);
        frameTime=SDL_GetTicks()-frameStart;
        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }

    Mix_FreeMusic(cancion);
    Mix_FreeChunk(tiro);
    Mix_FreeChunk(recarga);

    return 0;
}
