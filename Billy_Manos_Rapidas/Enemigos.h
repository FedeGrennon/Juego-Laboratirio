#ifndef ENEMIGOS_H_INCLUDED
#define ENEMIGOS_H_INCLUDED

class enemigo:public imagen{
    public:
        void eneAnimDisparando(float&, float);
};

void enemigo::eneAnimDisparando(float &APS, float TDA=5){
    int w=217 , h=193;

    if(APS >4*TDA)
        APS=0;
    if(APS==0 && APS<TDA){
        espacioMuestral(w, h);
    }else if(APS>TDA && APS<2*TDA){
        espacioMuestral(w, h, 247);
    }else if(APS>2*TDA && APS<3*TDA){
        espacioMuestral(w, h, 494);
    }else if(APS>3*TDA && APS<4*TDA){
        espacioMuestral(w, h, 247);
    }

    APS+=0.5;
}


#endif // ENEMIGOS_H_INCLUDED
