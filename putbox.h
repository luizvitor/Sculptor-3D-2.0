#ifndef PUTBOX_H
#define PUTBOX_H

#include "geometricfigure.h"
#include "sculptor.h"
/**
 * @brief The putBox class
 */
class putBox : public GeometricFigure
{
protected:
    int x1_,y1_,z1_,x0_,y0_,z0_;
    float r_,g_,b_,alpha_;
public:
    /**
     * @brief putBox
     */
    putBox(int x0,int y0,int z0,int x1,int y1,int z1,float _r,float _g,float _b,float alpha);
    ~putBox();
    void draw(Sculptor &des);
};

#endif // PUTBOX_H
