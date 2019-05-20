//Bibliotecas.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
//As class criadas para o desenvolvimento de qualquer desenho, que respeite as condições de execução.
#include "geometricfigure.h"
#include "sculptor.h"
#include "putvoxel.h"
#include "putbox.h"
#include "putsphere.h"
#include "putellipsoid.h"
#include "cutvoxel.h"
#include "cutbox.h"
#include "cutsphere.h"
#include "cutellipsoid.h"

using namespace std;
//Função principal. Aonde da o inicio da leitura do arquivo e desenho.
int main(){
    ifstream fin;
    string s;
    //Arquivos para armazenarem as informações do desenho principal.
    string arqOFF="arqOFF";
    string arqVECT="arqVECT";
    stringstream aux;
    //Objeto do tipo Sculptor. tela branca para o desenho.
    Sculptor *figs = nullptr;
    //Vetor responsável por armazenar os comandos do desenho.
    vector<GeometricFigure*>fig;

    //Arquivo que contém as informações sobre o desenho.
    fin.open("C:/Users/luquinha/Documents/C&T/PA/programas/C++/teste/file/teste_2.txt");
    //Se o arquivo for aberto ele continuará.
    if(!fin.is_open()){
        exit(0);
    }
    //While responsável por ler e identificar os comando do arquivo.
    while(fin.good()){
        getline(fin,s);
        aux.clear();
        aux.str(s);
        aux>>s;
        //Dimensões do objeto do tipo Sculptor.
        if(s.compare("dim")==0){
            int x,y,z;
            aux>>x>>y>>z;
            figs= new Sculptor(x,y,z);
        }
        //As demais condições são para o processo do desenho.
        else if(s.compare("putvoxel")==0){
            int x0,y0,z0;
            float r,g,b,alpha;
            aux>>x0>>y0>>z0>>r>>g>>b>>alpha;
            fig.push_back(new putVoxel(x0,y0,z0,r,g,b,alpha));
        }
        else if(s.compare("putbox")==0){
            int x0,y0,z0,x1,y1,z1;
            float r,g,b,alpha;
            aux>>x0>>y0>>z0>>x1>>y1>>z1>>r>>g>>b>>alpha;
            fig.push_back(new putBox(x0,y0,z0,x1,y1,z1,r,g,b,alpha));
        }
        else if(s.compare("putsphere")==0){
            int x0,y0,z0,radius;
            float r,g,b,alpha;
            aux>>x0>>y0>>z0>>radius>>r>>g>>b>>alpha;
            fig.push_back(new putSphere(x0,y0,z0,radius,r,g,b,alpha));
        }
        else if(s.compare("putellipsoid")==0){
            int x0,y0,z0,rx,ry,rz;
            float r,g,b,alpha;
            aux>>x0>>y0>>z0>>rx>>ry>>rz>>r>>g>>b>>alpha;
            fig.push_back(new putEllipsoid(x0,y0,z0,rx,ry,rz,r,g,b,alpha));
        }
        else if(s.compare("cutvoxel")==0){
            int x0,y0,z0;
            aux>>x0>>y0>>z0;
            fig.push_back(new cutVoxel(x0,y0,z0));
        }
        else if(s.compare("cutbox")==0){
            int x0,y0,z0,x1,y1,z1;
            aux>>x0>>y0>>z0>>x1>>y1>>z1;
            fig.push_back(new cutBox(x0,y0,z0,x1,y1,z1));
        }
        else if(s.compare("cutsphere")==0){
            int x0,y0,z0,radius;
            aux>>x0>>y0>>z0>>radius;
            fig.push_back(new cutSphere(x0,y0,z0,radius));
        }
        else if(s.compare("cutellipsoid")==0){
            int x0,y0,z0,rx,ry,rz;
            aux>>x0>>y0>>z0>>rx>>ry>>rz;
            fig.push_back(new cutEllipsoid(x0,y0,z0,rx,ry,rz));
        }
    }
    //Aplicar todas as funções de desenho lidas.
    for(int i=0; i<fig.size(); i++){
        fig[i]->draw(*figs);
    }
    //Salvar o desenho em arquivo OFF e VECT.
    figs->writeOFF(arqOFF);
    figs->writeVECT(arqVECT);
    //Liberar a memória.
    figs->~Sculptor();
    return 0;
}
