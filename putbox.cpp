#include "putbox.h"

putBox::putBox(int x0,int y0,int z0,int x1,int y1,int z1,float _r,float _g,float _b,float alpha){
    x0_=x0;y0_=y0;z0_=z0;
    x1_=x1;y1_=y1;z1_=z1;
    r_=_r;g_=_g;b_=_b;alpha_=alpha;
}
//Liberar a memória.
putBox::~putBox(){

}
//Função para desenhar.
/**
 * @brief putBox::draw
 * */
void putBox::draw(Sculptor &des){
    for(int i=x0_;i<x1_;i++){
        for(int j=y0_;j<y1_;j++){
            for(int k=z0_;k<z1_;k++){
                des.setColor(r_,g_,b_,alpha_);
                des.putVoxel(i,j,k);
            }
        }
    }
}
