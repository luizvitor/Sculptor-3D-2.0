#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "geometricfigure.h"
#include "sculptor.h"
/**
 * @brief The putSphere class
 */
class putSphere : public GeometricFigure
{
protected:
    int _xcenter,_ycenter,_zcenter,_radius;
    float r_,g_,b_,alpha_;
public:
    /**
     * @brief putSphere
     */
    putSphere(int xcenter,int ycenter,int zcenter,int radius,float _r,float _g,float _b,float alpha);
    ~putSphere();
    void draw(Sculptor &des);
};

#endif // PUTSPHERE_H
