#include "putsphere.h"

putSphere::putSphere(int xcenter,int ycenter,int zcenter,int radius,float _r,float _g,float _b,float alpha){
    _xcenter=xcenter;_ycenter=ycenter;_zcenter=zcenter;_radius=radius;
    r_=_r;g_=_g;b_=_b;alpha_=alpha;
}
//liberar a memória.
putSphere::~putSphere(){

}
//Função para desenhar.
void putSphere::draw(Sculptor &des){
    double rd=_radius/2.0;
    //Variavel para a distância da esfera em relação a todos os Voxel.
    double dist;
    for(int i=0;i<=(_xcenter+_radius);i++){
        for(int j=0;j<=(_ycenter+_radius);j++){
            for(int k=0;k<=(_zcenter+_radius);k++){
                //Equação da esfera.
                dist=(i-_xcenter/2.0)*(i-_xcenter/2.0)/(rd*rd)+
                          (j-_ycenter/2.0)*(j-_ycenter/2.0)/(rd*rd)+
                          (k-_zcenter/2.0)*(k-_zcenter/2.0)/(rd*rd);
                //Condição para efetuar o desenho da esfera.
                if(dist<=1.0){
                    des.setColor(r_,g_,b_,alpha_);
                    des.putVoxel(i,j,k);
                }
            }
        }
    }
}
