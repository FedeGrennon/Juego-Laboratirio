#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED

class personaje:public imagen{
    private:
        int vel;
    public:
        void velocidad(int velocidad){vel=velocidad;}
        bool mover(float&);
        void animDer(float&, float);
        void animIzq(float&, float);
        void animQuietoDer(float&, float);
        void animQuietoIzq(float&, float);
        void animDisparandoIni(float&, float);
        void animDisparandoLoop(float&, float);
};

bool personaje::mover(float &APS){
    static int aux=1;
    Uint8 *tecla;
    tecla=SDL_GetKeyState(NULL);

    if(tecla[SDLK_RIGHT] && pos.x < 700){
        pos.x += vel;
        if(tecla[SDLK_UP] && pos.y > 250)
            pos.y -= vel;
        if(tecla[SDLK_DOWN] && pos.y < 400)
            pos.y += vel;
        animDer(APS, 5);
        aux=1;
    }

    else if(tecla[SDLK_LEFT]){
        pos.x -= vel;
        if(tecla[SDLK_UP] && pos.y > 250)
            pos.y -= vel;
        if(tecla[SDLK_DOWN] && pos.y < 400)
            pos.y += vel;
        animIzq(APS, 5);
        aux=2;
    }

    else if(tecla[SDLK_UP]  && pos.y > 250){
        pos.y -= vel;
        if(aux==1)
            animDer(APS, 5);

        if(aux==2)
            animIzq(APS, 5);
    }

    else if(tecla[SDLK_DOWN] && pos.y < 400){
        pos.y += vel;
        if(aux==1)
            animDer(APS, 5);

        if(aux==2)
            animIzq(APS, 5);
    }

    if(aux==1)
        animQuietoDer(APS, 5);

    if(aux==2)
        animQuietoIzq(APS, 5);
}

void personaje::animDer(float &APS, float TDA=5){
    int w=100 , h=200;

    if(APS>4*TDA)
        APS=0;
    if(APS==0 && APS<TDA){
        espacioMuestral(w, h, 526);
    }else if(APS>TDA && APS<2*TDA){
        espacioMuestral(w, h, 662);
    }else if(APS>2*TDA && APS<3*TDA){
        espacioMuestral(w, h, 799);
    }else if(APS>3*TDA && APS<4*TDA){
        espacioMuestral(w, h, 935);
    }

    APS+=0.5;
}

void personaje::animIzq(float &APS, float TDA=5){
    int w=100 , h=200;

    if(APS >4*TDA)
        APS=0;
    if(APS==0 && APS<1*TDA){
        espacioMuestral(w, h, 0, 231);
    }else if(APS>1*TDA && APS<2*TDA){
        espacioMuestral(w, h, 126, 231);
    }else if(APS>2*TDA && APS<3*TDA){
        espacioMuestral(w, h, 262, 231);
    }else if(APS>3*TDA && APS<4*TDA){
        espacioMuestral(w, h, 388, 231);
    }

    APS+=0.5;
}

void personaje::animQuietoDer(float &APS, float TDA=5){
    int w=100 , h=200;

    if(APS>10*TDA)
        APS=0;
    if(APS==0 && APS<5*TDA){
        espacioMuestral(w, h);
    }else if(APS>5*TDA && APS<10*TDA){
        espacioMuestral(w, h, 126);
    }

    APS+=0.5;
}

void personaje::animQuietoIzq(float &APS, float TDA=5){
    int w=100 , h=200;

    if(APS>10*TDA)
        APS=0;
    if(APS==0 && APS<5*TDA){
        espacioMuestral(w, h, 262);
    }else if(APS>5*TDA && APS<10*TDA){
        espacioMuestral(w, h, 388);
    }

    APS+=0.5;
}

void personaje::animDisparandoIni(float &APS, float TDA=5){
    int w=100 , h=200;

    if(APS>20*TDA)
        APS=0;
    if(APS==0 && APS<5*TDA){
        espacioMuestral(w, h, 526, 231);
    }else if(APS>5*TDA && APS<10*TDA){
        espacioMuestral(w, h, 662, 231);
    }else if(APS>5*TDA && APS<15*TDA){
        espacioMuestral(w, h, 799, 231);
    }else if(APS>5*TDA && APS<20*TDA){
        espacioMuestral(w, h, 930, 231);
    }

    APS+=0.5;
}


#endif // PERSONAJE_H_INCLUDED
