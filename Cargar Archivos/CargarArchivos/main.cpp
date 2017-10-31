#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;


class Archivo{
    private:
        char Palabra[20];
    public:
        int cargarpalabra(){
            int dif;
            cout << "Elija la dificultad (1:Normal/2:Dificil): ";
            cin >> dif;
                if (dif == 1){
                    cout << "Ingresar palabra de 6 letras maximo: ";
                    cin >> Palabra;
                    return dif;
                }else{
                    cout << "Ingresar palabra de mas de 6 letras minimo: ";
                    cin >> Palabra;
                    return dif;
                }
        }

        void mostrar(int dificultad){
           if (dificultad == 1){
                cout << "Dificultad normal, palabra: ";
                cout << Palabra;
            }else{
                cout << "Dificultad dificil, palabra: ";
                cout << Palabra;
            }
        }

        bool GuardarEnDiscoNormal();
        bool LeerEnDiscoNormal(int pos);
        int cantidadNormal();

        bool GuardarEnDiscoDificil();
        bool LeerEnDiscoDificil(int pos);
        int cantidadDificil();

};

bool Archivo::GuardarEnDiscoNormal(){
        FILE *p;
        p=fopen("palabrasNor.dat","ab");
        if(p==NULL)
            return false;
        fwrite(this,sizeof *this,1,p);
        fclose(p);
        return true;
}

bool Archivo::LeerEnDiscoNormal(int pos){
        bool x;
        FILE *p;
        p=fopen("palabrasNor.dat","rb");
        if(p==NULL)
            return false;

        fseek(p,pos*sizeof *this,0);

        x=fread(this,sizeof *this,1,p);
        fclose(p);
        return x;
}

int Archivo::cantidadNormal(){
    FILE *p;
    p=fopen("palabrasNor.dat","rb");
    if(p==NULL)
        return -1;
    fseek(p,0,2);
    long tam = ftell(p);
    int cant = tam/sizeof *this;
    fclose(p);
    return cant;

}


bool Archivo::GuardarEnDiscoDificil(){
        FILE *p;
        p=fopen("palabrasDif.dat","ab");
        if(p==NULL)
            return false;
        fwrite(this,sizeof *this,1,p);
        fclose(p);
        return true;
}

bool Archivo::LeerEnDiscoDificil(int pos){
        bool x;
        FILE *p;
        p=fopen("palabrasDif.dat","rb");
        if(p==NULL)
            return false;

        fseek(p,pos*sizeof *this,0);

        x=fread(this,sizeof *this,1,p);
        fclose(p);
        return x;
}

int Archivo::cantidadDificil(){
    FILE *p;
    p=fopen("palabrasDif.dat","rb");
    if(p==NULL)
        return -1;
    fseek(p,0,2);
    long tam = ftell(p);
    int cant = tam/sizeof *this;
    fclose(p);
    return cant;

}



int main(){
    Archivo obj;
    int tam;
    int op;
    int dif;

    cout << "1-CARGAR PALABRA." << endl;
    cout << "2-MOSTRAR ARCHIVO." << endl;

    cout << "INGRESE OPCION: ";
    cin >> op;
    if(op==1){
        dif=obj.cargarpalabra();
        if(dif==1)
            obj.GuardarEnDiscoNormal();
        else
            obj.GuardarEnDiscoDificil();

    }else{
        cout << "1-MOSTRAR FACIL." << endl;
        cout << "2-MOSTRAR DIFICIL." << endl;

        cout << "INGRESE OPCION: ";
        cin >> op;

        if(op==1){
            tam = obj.cantidadNormal();
            for(int i=0; i<tam; i++){
                obj.LeerEnDiscoNormal(i);
                obj.mostrar(op);
                cout << endl;
            }
        }else{
            tam = obj.cantidadDificil();
            for(int i=0; i<tam; i++){
                obj.LeerEnDiscoDificil(i);
                obj.mostrar(op);
                cout << endl;
            }
        }
    }

    return 0;
}
