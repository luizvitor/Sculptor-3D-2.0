#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "geometricfigure.h"
/**
 * @brief The cutVoxel class
 */
class cutVoxel : public GeometricFigure
{
protected:
    int x0_,y0_,z0_;
public:
    /**
     * @brief cutVoxel
     */
    cutVoxel(int x,int y,int z);
    ~cutVoxel();
    void draw(Sculptor &des);
};

#endif // CUTVOXEL_H
