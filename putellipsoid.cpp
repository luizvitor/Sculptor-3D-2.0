#include "putellipsoid.h"

putEllipsoid::putEllipsoid(int xcenter,int ycenter,int zcenter,int rx,int ry,int rz,float _r,float _g,float _b,float alpha){
    _xcenter=xcenter;_ycenter=ycenter;_zcenter=zcenter;_rx=rx;_ry=ry;_rz=rz;
    r_=_r;g_=_g;b_=_b;alpha_=alpha;
}
//Liberar a memória.
putEllipsoid::~putEllipsoid(){

}
//Função para desenhar.
void putEllipsoid::draw(Sculptor &des){
    double rx_=_rx/2.0,ry_=_ry/2.0,rz_=_rz/2.0;
    //Variavel para a distância da esfera em relação a todos os Voxel.
    double dist;
    for(int i=0;i<=(_xcenter+_rx);i++){
        for(int j=0;j<=(_ycenter+_ry);j++){
            for(int k=0;k<=(_zcenter+_rz);k++){
                //Equação do Elipsoide.
                dist=(i-_xcenter/2.0)*(i-_xcenter/2.0)/(rx_*rx_)+
                (j-_ycenter/2.0)*(j-_ycenter/2.0)/(ry_*ry_) +
                (k-_zcenter/2.0)*(k-_zcenter/2.0)/(rz_*rz_);
                //Condição para efetuar o desenho do elipsoide.
                if(dist<=1){
                    des.setColor(r_,g_,b_,alpha_);
                    des.putVoxel(i,j,k);
                }
            }
        }
    }
}
