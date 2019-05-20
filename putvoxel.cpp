#include "putvoxel.h"

putVoxel::putVoxel(int x,int y,int z,float _r,float _g,float _b,float alpha){
    x_=x;y_=y;z_=z;
    r_=_r;g_=_g;b_=_b;alpha_=alpha;
}
//Liberar a memória.
putVoxel::~putVoxel(){

}
//Função para desenhar.
void putVoxel::draw(Sculptor &des){
    des.setColor(r_,g_,b_,alpha_);
    des.putVoxel(x_,y_,z_);
}
