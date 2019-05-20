#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "geometricfigure.h"
#include "sculptor.h"
/**
 * @brief The putEllipsoid class
 */
class putEllipsoid : public GeometricFigure{
protected:
    int _xcenter,_ycenter,_zcenter,_rx,_ry,_rz;
    float r_,g_,b_,alpha_;
public:
    /**
     * @brief putEllipsoid
     */
    putEllipsoid(int xcenter,int ycenter,int zcenter,int rx,int ry,int rz,float _r,float _g,float _b,float alpha);
    ~putEllipsoid();
    void draw(Sculptor &des);
};

#endif // PUTELLIPSOID_H
