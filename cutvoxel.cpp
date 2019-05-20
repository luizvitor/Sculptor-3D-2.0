#include "cutvoxel.h"

cutVoxel::cutVoxel(int x,int y,int z){
    x0_=x;y0_=y;z0_=z;
}
//Liberar a memória.
cutVoxel::~cutVoxel(){

}
//Função de corte em relação a um voxel.
void cutVoxel::draw(Sculptor &des){
    des.cutVoxel(x0_,y0_,z0_);
}
