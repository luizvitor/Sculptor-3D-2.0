#include "cutellipsoid.h"

cutEllipsoid::cutEllipsoid(int xcenter,int ycenter,int zcenter,int rx,int ry,int rz)
{
    xcenter_=xcenter;ycenter_=ycenter;zcenter_=zcenter;
    _rx=rx;_ry=ry;_rz=rz;
}
//Liberar a memória.
cutEllipsoid::~cutEllipsoid()
{

}
//Função para executar um corte no formato de elispsoide.
void cutEllipsoid::draw(Sculptor &fig)
{
    double rx_=_rx/2.0,ry_=_ry/2.0,rz_=_rz/2.0;
    //Variavel para a distância da esfera em relação a todos os Voxel.
    double dist;
    for(int i=0;i<(xcenter_+_rx);i++){
        for(int j=0;j<(ycenter_+_ry);j++){
            for(int k=0;k<(zcenter_+_rz);k++){
                //Equação do Elipsoide.
                dist=(i-xcenter_/2.0)*(i-xcenter_/2.0)/(rx_*rx_)+
                (j-ycenter_/2.0)*(j-ycenter_/2.0)/(ry_*ry_)+
                (k-zcenter_/2.0)*(k-zcenter_/2.0)/(rz_*rz_);
                //Condição para efetuar o desenho do elipsoide.
                if(dist<=1){
                    fig.cutVoxel(i,j,k);
                }
            }
        }
    }
}
