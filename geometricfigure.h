#ifndef GEOMETRICFIGURE_H
#define GEOMETRICFIGURE_H

#include <sculptor.h>
/**
 * @brief The GeometricFigure class
 */
class GeometricFigure
{
public:
    /**
     * @brief GeometricFigure
     */
    GeometricFigure();
    virtual ~GeometricFigure();
    /**
     * @brief draw
     */
    virtual void draw(Sculptor &des)=0;
};

#endif // GEOMETRICFIGURE_H
