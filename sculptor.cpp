#include "sculptor.h"
#include <cmath>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
//Alocação da Matriz 3D.
Sculptor::Sculptor(int _nx,int _ny,int _nz){
    nl=_nx;nc=_ny;np=_nz;
    if(nl<=0||nc<=0||np<=0){
        nl=nc=np=0;
    }
    v=new Voxel**[np];
    if(v==nullptr){
        cout<<"Erro na alocação."<<endl;
        exit(0);
    }
    v[0]=new Voxel*[np*nc];
    if(v[0]==nullptr){
        cout<<"Erro na alocação."<<endl;
        exit(0);
    }
    v[0][0]=new Voxel[nl*nc*np];
    if(v[0][0]==nullptr){
        cout<<"Erro na alocação."<<endl;
        exit(0);
    }
    for(int i=1;i<np;i++){
        v[i]=v[i-1]+nc;
    }
    for(int i=1;i<(np*nc);i++){
        v[0][i]=v[0][i-1]+nl;
    }
}
//Liberar a memória utilizada.
Sculptor::~Sculptor(){
    if(nl==0||nc==0||np==0){
        return;
    }
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}
//Atribuir as cores.
void Sculptor::setColor(float _r, float _g, float _b, float alpha){
    //Verificação das cores utilizadas.
    if((_r<=255||_r>=0)||(_g<=255||_g>=0)||(_b<=255||_b>=0)||(alpha<=1||alpha>=0)){
        r=_r;g=_g;b=_b;a=alpha;
    }
    else {
        cout<<"Cores invalidas"<<endl;
        exit(1);
    }
}
//Criar um Voxel.
void Sculptor::putVoxel(int x,int y,int z){
    //Verificação das dimensões atribuida.
    if(x<0 || x>nl || y<0 || y>nc || z<0 || z>np){
        cout <<"Dimensoes erradas, digite novamente"<<endl;
        exit(1);
    }
    //Atribuições das cores para o Voxel selecionado.
    else{
        v[x][y][z].isOn=true;
        v[x][y][z].red=r;
        v[x][y][z].blue=b;
        v[x][y][z].green=g;
        v[x][y][z].alpha=a;
    }
}
//Cortar um Voxel.
void Sculptor::cutVoxel(int x,int y,int z){
    //Verificação das dimensões atribuida.
    if(x<0 || x>nl || y<0 || y>nc || z<0 || z>np){
        cout <<"Dimensoes erradas, digite novamente"<<endl;
        exit(1);
    }
    //Utilizando o isOn para efetuar o corte.
    else{
        v[x][y][z].isOn=false;
    }
}
void Sculptor::writeOFF(string filename){
    //Variavel para efetuar as funções de fluxos.
    ofstream fout2;
    //Contador para o número de vertices.
    int Nvertices=0;
    //Contador para o número de faces.
    int Nfaces=0;
    //Variavel auxiliar na execução e determinação de cada face para cada Voxel.
    int aux=0;
    //Abrindo arquivo.
    fout2.open("C:/Users/luquinha/Documents/C&T/PA/programas/C++/teste/file/"+filename+".off");
    //Condição para determinar se o arquivo foi aberto.
    if(fout2.is_open()){
        cout << "arquivo OFF foi aberto\n";
    }
    else{
        cout << "arquivo OFF nao foi aberto\n";
        exit(1);
    }
    //Primeira linha do arquivo. Linha de reconhecimento.
    fout2<<"OFF"<<endl;
    //Contar a quantidade de vertices e faces. Obs.: isOn deve ser verdadeiro.
    for(int i=0;i<nl;i++){
        for(int j=0;j<nc;j++){
            for(int k=0;k<np;k++){
                if(v[i][j][k].isOn){
                    Nvertices=Nvertices+8;
                    Nfaces=Nfaces+6;
                }
            }
        }
    }
    //Segunda linha do arquivo. Linha para mostra quantidade de vertices e faces.
    fout2<<Nvertices<<" "<<Nfaces<<" "<<0<<endl;
    //Dimensionamento de cada vertice em relação a cada Voxel com isOn true. Obs.: dimensão de cada Voxel 1.
    for(int i=0;i<nl;i++){
        for(int j=0;j<nc;j++){
            for(int k=0;k<np;k++){
                if(v[i][j][k].isOn){
                        fout2<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                        fout2<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                        fout2<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                        fout2<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                        fout2<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                        fout2<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                        fout2<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                        fout2<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                }
            }
        }
    }
    //Dimensionar cada face de cada Voxel e atribuindo as cores correspondente.
    for(int i=0;i<nl;i++){
        for(int j=0;j<nc;j++){
            for(int k=0;k<np;k++){
                if(v[i][j][k].isOn){
                    fout2<<4<<" "<<aux+0<<" "<<aux+3<<" "<<aux+2<<" "<<aux+1<<" "<<v[i][j][k].red<<" "
                    <<v[i][j][k].green<<" "<<v[i][j][k].blue<<" "<<v[i][j][k].alpha<<endl;
                    fout2<<4<<" "<<aux+4<<" "<<aux+5<<" "<<aux+6<<" "<<aux+7<<" "<<v[i][j][k].red<<" "
                    <<v[i][j][k].green<<" "<<v[i][j][k].blue<<" "<<v[i][j][k].alpha<<endl;
                    fout2<<4<<" "<<aux+0<<" "<<aux+1<<" "<<aux+5<<" "<<aux+4<<" "<<v[i][j][k].red<<" "
                    <<v[i][j][k].green<<" "<<v[i][j][k].blue<<" "<<v[i][j][k].alpha<<endl;
                    fout2<<4<<" "<<aux+0<<" "<<aux+4<<" "<<aux+7<<" "<<aux+3<<" "<<v[i][j][k].red<<" "
                    <<v[i][j][k].green<<" "<<v[i][j][k].blue<<" "<<v[i][j][k].alpha<<endl;
                    fout2<<4<<" "<<aux+3<<" "<<aux+7<<" "<<aux+6<<" "<<aux+2<<" "<<v[i][j][k].red<<" "
                    <<v[i][j][k].green<<" "<<v[i][j][k].blue<<" "<<v[i][j][k].alpha<<endl;
                    fout2<<4<<" "<<aux+1<<" "<<aux+2<<" "<<aux+6<<" "<<aux+5<<" "<<v[i][j][k].red<<" "
                    <<v[i][j][k].green<<" "<<v[i][j][k].blue<<" "<<v[i][j][k].alpha<<endl;
                    aux=aux+8;
                }
            }
        }
    }
    //Condição para apresentar o fim do arquivo.
    if(fout2.is_open()){
        cout << "arquivo OFF salvo"<<endl;
    }

}
//Criar arquivo para armazenar quantidades de poligonos,vertices e posições.
void Sculptor::writeVECT(string filename){
    //Variavel para efetuar as funções de fluxos.
    ofstream fout;
    //Contador.
    int cont=0;
    //Abrindo arquivo.
    fout.open("C:/Users/luquinha/Documents/C&T/PA/programas/C++/teste/file/"+filename+".vect");
    //Condição para determinar se o arquivo foi aberto.
    if(fout.is_open()){
        cout << "arquivo VECT foi aberto\n";
    }
    else{
        cout << "arquivo VECT nao foi aberto\n";
        exit(1);
    }
    //Primeira linha do arquivo. Linha de reconhecimento.
    fout<<"VECT"<<endl;
    //Contagem de cada Voxel com isOn true.
    for(int i=0;i<nl;i++){
        for(int j=0;j<nc;j++){
            for(int k=0;k<np;k++){
                if(v[i][j][k].isOn){
                    cont=cont+1;
                }
            }
        }
    }
    fout<<cont<<" "<<cont<<" "<<cont<<endl;
    for(int i=1;i<cont-1;i++){
        fout<<1<<" ";
    }
    fout<<1<<endl;
    for(int i=1;i<cont-1;i++){
        fout<<1<<" ";
    }
    fout<<1<<endl;
    //Linha do arquivo para salvar quais Voxels estão com isOn true.
    for(int i=0;i<nl;i++){
        for(int j=0;j<nc;j++){
            for(int k=0;k<np;k++){
                if(v[i][j][k].isOn){
                    fout<<i<<" "<<j<<" "<<k<<endl;
                }
            }
        }
    }
    //Linha do arquivo para salvar as cores de cada Voxel.
    for(int i=0;i<nl;i++){
        for(int j=0;j<nc;j++){
            for(int k=0;k<np;k++){
                if(v[i][j][k].isOn){
                    fout<<v[i][j][k].red<<" "<<v[i][j][k].green<<" "<<v[i][j][k].blue<<" "<<v[i][j][k].alpha<<endl;
                }
            }
        }
    }
    //Condição para apresentar o fim do arquivo.
    if(fout.is_open()){
        cout << "arquivo VECT salvo"<<endl;
    }
}
