#ifndef NIVELES_H_INCLUDED
#define NIVELES_H_INCLUDED

#include "Imagenes.h"
#include "Personaje.h"
#include "Enemigos.h"

int presentacion(SDL_Surface* pantalla, SDL_Event tecla){
    imagen present;
    float anim=0, velAnim=1.4;
    const int FPS=60;
    const int frameDelay=1000/FPS;
    Uint32 frameStart;
    int frameTime;

    present.cargar("Imagenes/Presentacion.png");
    present.posicion(110, 25);
    present.espacioMuestral(580, 550);

    while(presentacion){
        frameStart=SDL_GetTicks();
        SDL_FillRect(pantalla, 0, SDL_MapRGB(pantalla->format, 0, 0, 0));

        present.pintarColorFondo(0, 0, 1);
        present.mostrar(pantalla);

        if(anim==0 && anim<velAnim){
            present.espacioMuestral(580, 550);
        }else if(anim>velAnim && anim<velAnim*2){
            present.espacioMuestral(580, 550, 580);
        }else if(anim>velAnim*2 && anim<velAnim*4){
            present.espacioMuestral(580, 550, 1160);
        }else if(anim>velAnim*4 && anim<velAnim*5){
            present.espacioMuestral(580, 550, 1740);
        }else if(anim>velAnim*5 && anim<velAnim*6){
            present.espacioMuestral(580, 550, 2320);
        }else if(anim>velAnim*6 && anim<velAnim*7){
            present.espacioMuestral(580, 550, 0, 550);
        }else if(anim>velAnim*7 && anim<velAnim*8){
            present.espacioMuestral(580, 550, 580, 550);
        }else if(anim>velAnim*9 && anim<velAnim*20){
            present.espacioMuestral(580, 550, 1160, 550);
        }else if(anim>velAnim*20){
            present.espacioMuestral(580, 550, 1740, 550);
        }

        anim+=0.5;

        if(anim>70.0)
            return 2;

        SDL_PollEvent(&tecla);

        if(tecla.type==SDL_QUIT){
            return 0;
        }

        SDL_Flip(pantalla);
        frameTime=SDL_GetTicks()-frameStart;
        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }

}

int menuPrincipal(SDL_Surface* pantalla, SDL_Event tecla, int &volMusic, int &volSFX, int &difi){
    imagen botJugar, botOpc, botSalir, imgPrincipal, flecha, volumen, titulo;
    int x, y, canalMus=1, canalSon=0;
    Mix_Music *cancion;
    Mix_Chunk *tiro, *latigo;
    bool pausarMusica=false, principal=true, opciones=false, eleccion=false;
    static bool pc=false;

    cancion = Mix_LoadMUS("Musica/TemaPrincipal.mp3");
    tiro = Mix_LoadWAV("Sonidos/Tiro.wav");
    latigo = Mix_LoadWAV("Sonidos/latigo.wav");

    imgPrincipal.cargar("Imagenes/Principal.png");
    imgPrincipal.posicion();
    imgPrincipal.espacioMuestral(800, 600);

    flecha.cargar("Imagenes/Herradura.png");
    flecha.espacioMuestral(40, 40);

    titulo.cargar("Imagenes/Titulo.png");
    titulo.posicion(255,122);
    titulo.espacioMuestral(330, 112);

    botJugar.cargar("Imagenes/botJugar.png");
    botJugar.posicion(334,228);
    botJugar.espacioMuestral(166, 66);

    botOpc.cargar("Imagenes/botOpciones.png");
    botOpc.posicion(305,279);
    botOpc.espacioMuestral(240, 76);

    botSalir.cargar("Imagenes/botSalir.png");
    botSalir.posicion(356,341);
    botSalir.espacioMuestral(150, 63);

    SDL_Rect play;
    play.x=334;
    play.y=228;
    play.w=166;
    play.h=66;

    SDL_Rect opc;
    opc.x=305;
    opc.y=279;
    opc.w=240;
    opc.h=76;

    SDL_Rect salir;
    salir.x=356;
    salir.y=341;
    salir.w=150;
    salir.h=63;

    canalMus=Mix_PlayMusic(cancion, -1);
    Mix_VolumeMusic(volMusic);

    while(principal){
        imgPrincipal.mostrar(pantalla);

        titulo.pintarColorFondo();
        titulo.mostrar(pantalla);

        botJugar.pintarColorFondo();
        botJugar.mostrar(pantalla);
        botJugar.espacioMuestral(166, 66);

        botOpc.pintarColorFondo();
        botOpc.mostrar(pantalla);
        botOpc.espacioMuestral(240, 76);

        botSalir.pintarColorFondo();
        botSalir.mostrar(pantalla);
        botSalir.espacioMuestral(150, 63);

        SDL_PollEvent(&tecla);

        if(tecla.type==SDL_QUIT){
            Mix_HaltMusic();
            Mix_FreeMusic(cancion);
            Mix_FreeChunk(tiro);
            Mix_FreeChunk(latigo);
            return 0;
        }

        if(tecla.type == SDL_KEYDOWN || tecla.type == SDL_KEYUP){
            if(tecla.key.keysym.sym == SDLK_ESCAPE){
                Mix_HaltMusic();
                Mix_FreeMusic(cancion);
                Mix_FreeChunk(tiro);
                Mix_FreeChunk(latigo);
                return 0;
            }
        }

        if(tecla.type==SDL_MOUSEMOTION){
            x = tecla.button.x;
            y = tecla.button.y;

            if(x>play.x && x<play.x+play.w && y>play.y && y<play.y+play.h){
                flecha.posicion(295, 250);
                flecha.pintarColorFondo();
                flecha.mostrar(pantalla);
            }
            else if(x>opc.x && x<opc.x+opc.w && y>opc.y && y<opc.y+opc.h){
                flecha.posicion(265, 310);
                flecha.pintarColorFondo();
                flecha.mostrar(pantalla);
            }
            else if(x>salir.x && x<salir.x+salir.w && y>salir.y && y<salir.y+salir.h){
                flecha.posicion(315, 360);
                flecha.pintarColorFondo();
                flecha.mostrar(pantalla);
            }
        }

        if(tecla.type==SDL_MOUSEBUTTONDOWN && tecla.button.button==SDL_BUTTON_LEFT){
            x = tecla.button.x;
            y = tecla.button.y;

            if(x>play.x && x<play.x+play.w && y>play.y && y<play.y+play.h){
                botJugar.espacioMuestral(166, 66, 166);
            }
            else if(x>opc.x && x<opc.x+opc.w && y>opc.y && y<opc.y+opc.h){
                botOpc.espacioMuestral(240, 76, 240);
            }
            else if(x>salir.x && x<salir.x+salir.w && y>salir.y && y<salir.y+salir.h){
                botSalir.espacioMuestral(150, 63, 150);
            }
        }


        if(tecla.type==SDL_MOUSEBUTTONUP){
            x = tecla.button.x;
            y = tecla.button.y;

            if(x>play.x && x<play.x+play.w && y>play.y && y<play.y+play.h){
                tecla.type=SDL_MOUSEMOTION;
                Mix_VolumeChunk(latigo, volSFX);
                Mix_PlayChannel(canalSon, latigo, 0);
                eleccion=true;
                principal=false;
            }
            else if(x>opc.x && x<opc.x+opc.w && y>opc.y && y<opc.y+opc.h){
                Mix_VolumeChunk(latigo, volSFX);
                Mix_PlayChannel(canalSon, latigo, 0);
                principal=false;
                opciones=true;
            }
            else if(x>salir.x && x<salir.x+salir.w && y>salir.y && y<salir.y+salir.h){
                Mix_HaltMusic();
                Mix_FreeChunk(tiro);
                Mix_FreeChunk(latigo);
                Mix_FreeMusic(cancion);
                Mix_FreeChunk(tiro);
                Mix_FreeChunk(latigo);
                return 0;
            }
        }

        SDL_Flip(pantalla);
    }

    imagen botProb, imgvolSFX, imgvolMusica, botPantCompleta, botVolver, vol[2];

    botProb.cargar("Imagenes/botProbar.png");
    botProb.posicion(490,127);
    botProb.espacioMuestral(108, 40);

    imgvolSFX.cargar("Imagenes/volSfx.png");
    imgvolSFX.posicion(248,178);
    imgvolSFX.espacioMuestral(180, 57);

    imgvolMusica.cargar("Imagenes/volMusica.png");
    imgvolMusica.posicion(252,232);
    imgvolMusica.espacioMuestral(246, 64);

    botPantCompleta.cargar("Imagenes/botPantCompleta.png");
    botPantCompleta.posicion(226,281);

    for(int i=0; i<2; i++)
        vol[i].cargar("Imagenes/volumen.png");

    if(volSFX==128){
        vol[0].espacioMuestral(97, 50);
    }else if(volSFX==108){ Mix_FreeChunk(tiro);
                Mix_FreeChunk(latigo);
        vol[0].espacioMuestral(97, 50, 97);
    }else if(volSFX==90){
        vol[0].espacioMuestral(97, 50, 194);
    }else if(volSFX==72){
        vol[0].espacioMuestral(97, 50, 291);
    }else if(volSFX==54){
        vol[0].espacioMuestral(97, 50, 0, 50);
    }else if(volSFX==36){
        vol[0].espacioMuestral(97, 50, 97, 50);
    }else if(volSFX==18){
        vol[0].espacioMuestral(97, 50, 194, 50);
    }else if(volSFX==0){
        vol[0].espacioMuestral(97, 50, 291, 50);
    }

    if(volMusic==128){
        vol[1].espacioMuestral(97, 50);
    }else if(volMusic==108){
        vol[1].espacioMuestral(97, 50, 97);
    }else if(volMusic==90){
        vol[1].espacioMuestral(97, 50, 194);
    }else if(volMusic==72){
        vol[1].espacioMuestral(97, 50, 291);
    }else if(volMusic==54){
        vol[1].espacioMuestral(97, 50, 0, 50);
    }else if(volMusic==36){
        vol[1].espacioMuestral(97, 50, 97, 50);
    }else if(volMusic==18){
        vol[1].espacioMuestral(97, 50, 194, 50);
    }else if(volMusic==0){
        vol[1].espacioMuestral(97, 50, 291, 50);
    }

    vol[0].posicion(437,165);
    vol[1].posicion(505,220);

    if(pc){
        botPantCompleta.espacioMuestral(380, 90, 380);
    }else{
        botPantCompleta.espacioMuestral(380, 90);
    }

    botVolver.cargar("Imagenes/botVolver.png");
    botVolver.posicion(338,353);
    botVolver.espacioMuestral(147, 54);

    botOpc.posicion(247, 108);
    botOpc.espacioMuestral(240, 76);

    SDL_Rect prob;
    prob.x=480;
    prob.y=127;
    prob.w=108;
    prob.h=40;

    SDL_Rect pantComp;
    pantComp.x=542;
    pantComp.y=282;
    pantComp.w=43;
    pantComp.h=42;

    SDL_Rect volver;
    volver.x=338;
    volver.y=353;
    volver.w=147;
    volver.h=54;

    while(opciones){
        imgPrincipal.mostrar(pantalla);

        botProb.pintarColorFondo();
        botProb.mostrar(pantalla);
        botProb.espacioMuestral(108, 40);

        imgvolSFX.pintarColorFondo();
        imgvolSFX.mostrar(pantalla);

        imgvolMusica.pintarColorFondo();
        imgvolMusica.mostrar(pantalla);

        botPantCompleta.pintarColorFondo();
        botPantCompleta.mostrar(pantalla);

        botVolver.pintarColorFondo();
        botVolver.mostrar(pantalla);
        botVolver.espacioMuestral(147, 54);

        vol[0].pintarColorFondo();
        vol[0].mostrar(pantalla);
        vol[1].pintarColorFondo();
        vol[1].mostrar(pantalla);

        botOpc.mostrar(pantalla);

        SDL_PollEvent(&tecla);

        if(tecla.type==SDL_QUIT){
            Mix_HaltMusic();
            Mix_FreeMusic(cancion);
            Mix_FreeChunk(tiro);
            Mix_FreeChunk(latigo);
            return 0;
        }

        if(tecla.type == SDL_KEYDOWN || tecla.type == SDL_KEYUP){
            if(tecla.key.keysym.sym == SDLK_ESCAPE){
                Mix_HaltMusic();
                Mix_FreeMusic(cancion);
                Mix_FreeChunk(tiro);
                Mix_FreeChunk(latigo);
                return 0;
            }
        }

        if(tecla.type==SDL_MOUSEMOTION){
            x = tecla.button.x;
            y = tecla.button.y;

            if(x>prob.x && x<prob.x+prob.w && y>prob.y && y<prob.y+prob.h){
                botProb.espacioMuestral(108, 40, 108);
            }
            else if(x>volver.x && x<volver.x+volver.w && y>volver.y && y<volver.y+volver.h){
                botVolver.espacioMuestral(147, 54, 147);
            }
        }

        if(tecla.type==SDL_MOUSEBUTTONDOWN && tecla.button.button==SDL_BUTTON_LEFT){
            x = tecla.button.x;
            y = tecla.button.y;

            if(x>prob.x && x<prob.x+prob.w && y>prob.y && y<prob.y+prob.h){
                botProb.espacioMuestral(108, 40, 108);
                Mix_VolumeChunk(tiro, volSFX);
                Mix_PlayChannel(canalSon, tiro, 0);
                tecla.type=SDL_MOUSEBUTTONUP;
            }
            else if(x>volver.x && x<volver.x+volver.w && y>volver.y && y<volver.y+volver.h){
                botVolver.espacioMuestral(147, 54, 147);
            }
            else if(x>pantComp.x && x<pantComp.x+pantComp.w && y>pantComp.y && y<pantComp.y+pantComp.h){
                if(pc){
                    botPantCompleta.espacioMuestral(380, 90);
                    pc=false;
                    pantalla = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
                    tecla.type=SDL_MOUSEBUTTONUP;
                }else{
                    botPantCompleta.espacioMuestral(380, 90, 380);
                    pc=true;
                    pantalla = SDL_SetVideoMode(800,600,32,SDL_FULLSCREEN);
                    tecla.type=SDL_MOUSEBUTTONUP;
                }
            }
            if(x>585 && x<597 && y>218 && y<254){
                vol[1].espacioMuestral(97,50);
                volMusic=128;
                Mix_VolumeMusic(volMusic);
            }
            if(x>572 && x<584 && y>220 && y<256){
                vol[1].espacioMuestral(97,50, 97);
                volMusic=108;
                Mix_VolumeMusic(volMusic);
            }
            if(x>559 && x<571 && y>222 && y<258){
                vol[1].espacioMuestral(97,50, 194);
                volMusic=90;
                Mix_VolumeMusic(volMusic);
            }
            if(x>546 && x<558 && y>224 && y<260){
                vol[1].espacioMuestral(97,50, 291);
                volMusic=72;
                Mix_VolumeMusic(volMusic);
            }
            if(x>533 && x<545 && y>226 && y<262){
                vol[1].espacioMuestral(97,50, 0, 50);
                volMusic=54;
                Mix_VolumeMusic(volMusic);
            }
            if(x>520 && x<533 && y>228 && y<264){
                vol[1].espacioMuestral(97,50, 97, 50);
                volMusic=36;
                Mix_VolumeMusic(volMusic);
            }
            if(x>507 && x<520 && y>230 && y<266){
                vol[1].espacioMuestral(97,50, 194, 50);
                volMusic=18;
                Mix_VolumeMusic(volMusic);
            }
            if(x>494 && x<507 && y>232 && y<268){
                vol[1].espacioMuestral(97,50, 291, 50);
                volMusic=0;
                Mix_VolumeMusic(volMusic);
            }

            if(x>585-68 && x<597-68 && y>218-55 && y<254-55){
                vol[0].espacioMuestral(97,50);
                volSFX=128;
            }
            if(x>572-68 && x<584-68 && y>220-55 && y<256-55){
                vol[0].espacioMuestral(97,50, 97);
                volSFX=108;
            }
            if(x>559-68 && x<571-68 && y>222-55 && y<258-55){
                vol[0].espacioMuestral(97,50, 194);
                volSFX=90;
            }
            if(x>546-68 && x<558-68 && y>224-55 && y<260-55){
                vol[0].espacioMuestral(97,50, 291);
                volSFX=72;
            }
            if(x>533-68 && x<545-68 && y>226-55 && y<262-55){
                vol[0].espacioMuestral(97,50, 0, 50);
                volSFX=54;
            }
            if(x>520-68 && x<533-68 && y>228-55 && y<264-55){
                vol[0].espacioMuestral(97,50, 97, 50);
                volSFX=36;
            }
            if(x>507-68 && x<520-68 && y>230-55 && y<266-55){
                vol[0].espacioMuestral(97,50, 194, 50);
                volSFX=18;
            }
            if(x>494-68 && x<507-68 && y>232-55 && y<268-55){
                vol[0].espacioMuestral(97,50, 291, 50);
                volSFX=0;
            }
        }

        if(tecla.type==SDL_MOUSEBUTTONUP){
            x = tecla.button.x;
            y = tecla.button.y;

            if(x>volver.x && x<volver.x+volver.w && y>volver.y && y<volver.y+volver.h){
                Mix_VolumeChunk(latigo, volSFX);
                Mix_PlayChannel(canalSon, latigo, 0);
                return 2;
            }
        }

        SDL_Flip(pantalla);
    }

    imagen botFacil, botDificil, cartDificultad;

    botFacil.cargar("Imagenes/BotFacil.png");
    botFacil.posicion(341, 215);
    botFacil.espacioMuestral(150, 68);

    botDificil.cargar("Imagenes/BotDificil.png");
    botDificil.posicion(337, 280);
    botDificil.espacioMuestral(177, 71);

    cartDificultad.cargar("Imagenes/Dificultad.png");
    cartDificultad.posicion(259, 127);
    cartDificultad.espacioMuestral(300, 86);

    botVolver.espacioMuestral(147, 54);
    botVolver.posicion(422, 353);

    SDL_Rect botFac;
    botFac.x=341;
    botFac.y=215;
    botFac.w=150;
    botFac.h=68;

    SDL_Rect botDif;
    botDif.x=337;
    botDif.y=280;
    botDif.w=177;
    botDif.h=71;

    volver.x=422;
    volver.y=353;

    while(eleccion){
        imgPrincipal.mostrar(pantalla);

        botFacil.pintarColorFondo();
        botFacil.mostrar(pantalla);
        botFacil.espacioMuestral(150, 68);

        botDificil.pintarColorFondo();
        botDificil.mostrar(pantalla);
        botDificil.espacioMuestral(177, 71);

        botVolver.pintarColorFondo();
        botVolver.mostrar(pantalla);
        botVolver.espacioMuestral(147, 54);

        cartDificultad.pintarColorFondo();
        cartDificultad.mostrar(pantalla);

        SDL_PollEvent(&tecla);

        if(tecla.type==SDL_QUIT){
            Mix_HaltMusic();
            Mix_FreeMusic(cancion);
            Mix_FreeChunk(tiro);
            Mix_FreeChunk(latigo);
            return 0;
        }

        if(tecla.type == SDL_KEYDOWN || tecla.type == SDL_KEYUP){
            if(tecla.key.keysym.sym == SDLK_ESCAPE){
                Mix_HaltMusic();
                Mix_FreeMusic(cancion);
                Mix_FreeChunk(tiro);
                Mix_FreeChunk(latigo);
                return 0;
            }
        }

        if(tecla.type==SDL_MOUSEMOTION){
            x = tecla.button.x;
            y = tecla.button.y;

            if(x>botFac.x && x<botFac.x+botFac.w && y>botFac.y && y<botFac.y+botFac.h){
                flecha.posicion(293, 235);
                flecha.pintarColorFondo();
                flecha.mostrar(pantalla);
            }
            else if(x>botDif.x && x<botDif.x+botDif.w && y>botDif.y && y<botDif.y+botDif.h){
                flecha.posicion(297, 302);
                flecha.pintarColorFondo();
                flecha.mostrar(pantalla);
            }
            else if(x>volver.x && x<volver.x+volver.w && y>volver.y && y<volver.y+volver.h){
                botVolver.espacioMuestral(147, 54, 147);
            }
        }

        if(tecla.type==SDL_MOUSEBUTTONDOWN && tecla.button.button==SDL_BUTTON_LEFT){
            x = tecla.button.x;
            y = tecla.button.y;

            if(x>botFac.x && x<botFac.x+botFac.w && y>botFac.y && y<botFac.y+botFac.h){
                botFacil.espacioMuestral(150, 68, 150);
            }
            else if(x>botDif.x && x<botDif.x+botDif.w && y>botDif.y && y<botDif.y+botDif.h){
                botDificil.espacioMuestral(177, 71, 177);
            }
            else if(x>volver.x && x<volver.x+volver.w && y>volver.y && y<volver.y+volver.h){
                botVolver.espacioMuestral(147, 54, 147);
            }
        }

        if(tecla.type==SDL_MOUSEBUTTONUP){
            x = tecla.button.x;
            y = tecla.button.y;

            if(x>botFac.x && x<botFac.x+botFac.w && y>botFac.y && y<botFac.y+botFac.h){
                Mix_VolumeChunk(latigo, volSFX);
                Mix_PlayChannel(canalSon, latigo, 0);
                difi=1;
                Mix_HaltMusic();
                Mix_FreeMusic(cancion);
                Mix_FreeChunk(tiro);
                Mix_FreeChunk(latigo);
                return 3;
            }
            else if(x>botDif.x && x<botDif.x+botDif.w && y>botDif.y && y<botDif.y+botDif.h){
                Mix_VolumeChunk(latigo, volSFX);
                Mix_PlayChannel(canalSon, latigo, 0);
                difi=2;
                Mix_HaltMusic();
                Mix_FreeMusic(cancion);
                Mix_FreeChunk(tiro);
                Mix_FreeChunk(latigo);
                return 3;
            }
            else if(x>volver.x && x<volver.x+volver.w && y>volver.y && y<volver.y+volver.h){
                Mix_VolumeChunk(latigo, volSFX);
                Mix_PlayChannel(canalSon, latigo, 0);
                return 2;
            }
        }

        SDL_Flip(pantalla);
    }

}

bool tutorial(SDL_Surface* pantalla, SDL_Event tecla, int volMusic, int volSFX){
    const int FPS=60;
    const int frameDelay=1000/FPS;
    Uint32 frameStart;
    int frameTime;

    personaje pj;
    imagen escenario2;
    enemigo ene;
    float APS=0, APSE=0;
    static bool primer=true, aux=true;

    pj.cargar("Imagenes/Personaje.png");
    pj.posicion(100, 300);
    pj.velocidad(2);

    ene.cargar("Imagenes/Enemigo1.png");
    ene.posicion(500, 300);

    escenario2.cargar("Imagenes/Escenario2.png");
    escenario2.posicion();
    escenario2.espacioMuestral(800, 600);

    while(true){
        frameStart=SDL_GetTicks();
        SDL_FillRect(pantalla, 0, SDL_MapRGB(pantalla->format, 0, 0, 0));

        escenario2.mostrar(pantalla);
        pj.pintarColorFondo();
        pj.mostrar(pantalla);

        ene.pintarColorFondo();
        ene.eneAnimDisparando(APSE);
        ene.mostrar(pantalla);

        if(primer){
            tecla.type = SDL_KEYDOWN;
            tecla.key.keysym.sym = SDLK_RIGHT;
            aux=false;
        }
        if(!aux){
            tecla.type = SDL_KEYUP;
            aux=true;
        }

        SDL_PollEvent(&tecla);

        if(tecla.type==SDL_QUIT){
                return false;
            }

        if(tecla.type == SDL_KEYDOWN || tecla.type == SDL_KEYUP){
            if(tecla.key.keysym.sym == SDLK_ESCAPE){
                return false;
            }

            pj.mover(APS);
        }

        primer=false;
        SDL_Flip(pantalla);
        frameTime=SDL_GetTicks()-frameStart;
        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }
}

#endif // NIVELES_H_INCLUDED
