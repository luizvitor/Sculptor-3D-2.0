#include "cutsphere.h"

cutSphere::cutSphere(int xcenter,int ycenter,int zcenter,int radius){
    _xcenter=xcenter;_ycenter=ycenter;_zcenter=zcenter;_radius=radius;
}
//Liberar a memória.
cutSphere::~cutSphere(){

}
//Função para executar um corte no formato de esferá.
void cutSphere::draw(Sculptor &des){
    double rd=_radius/2.0;
    //Variavel para a distância da esfera em relação a todos os Voxel.
    double dist;
    for(int i=0;i<(_xcenter+_radius);i++){
        for(int j=0;j<(_ycenter+_radius);j++){
            for(int k=0;k<(_zcenter+_radius);k++){
                //Equação da esfera.
                dist=(i-_xcenter/2.0)*(i-_xcenter/2.0)/(rd*rd)+
                          (j-_ycenter/2.0)*(j-_ycenter/2.0)/(rd*rd)+
                          (k-_zcenter/2.0)*(k-_zcenter/2.0)/(rd*rd);
                //Condição para efetuar o desenho da esfera.
                if(dist<=1.0){
                    des.cutVoxel(i,j,k);
                }
            }
        }
    }
}
