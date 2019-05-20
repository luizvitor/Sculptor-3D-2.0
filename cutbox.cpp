#include "cutbox.h"

cutBox::cutBox(int x0,int y0,int z0,int x1,int y1,int z1){
    x0_=x0;y0_=y0;z0_=z0;
    x1_=x1;y1_=y1;z1_=z1;
}
//Liberar a memória.
cutBox::~cutBox(){

}
//Função para executar um corte no formato de caixa.
void cutBox::draw(Sculptor &des){
    for(int i=x0_;i<x1_;i++){
        for(int j=y0_;j<y1_;j++){
            for(int k=z0_;k<z1_;k++){
                des.cutVoxel(i,j,k);
            }
        }
    }
}
