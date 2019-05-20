#ifndef CUTBOX_H
#define CUTBOX_H

#include "geometricfigure.h"
#include "sculptor.h"
/**
 * @brief The cutBox class
 */
class cutBox : public GeometricFigure
{
protected:
    int x1_,y1_,z1_,x0_,y0_,z0_;
public:
    /**
     * @brief cutBox
     */
    cutBox(int x0,int y0,int z0,int x1,int y1,int z1);
    ~cutBox();
    /**
     * @brief draw
     */
    void draw(Sculptor &des);
};

#endif // CUTBOX_H
