#ifndef  SVG_CIRCLE_H
#define SVG_CIRCLE_H
#include <string>
#include "svg_shape.h"

class SvgCircle : public SvgShape {
public:
    SvgCircle(double x, double y, double r): _x(x), _y(y), _r(r)
     {

     }
    std::string toSVG() const
    {
      std::string temp = "<circle cx=\"" + std::to_string(_x) + "\" cy=\"" + std::to_string(_y) + "\" r=\"" + std::to_string(_r)
      + "\" stroke-width=\"" + std::to_string(this->stroke_width()) + "\" stroke=\"" + this->stroke_color() + "\" fill=\"" + this->fill_color() + "\"/>";
      return temp;
    }
private:
    double _x, _y, _r;
};

#endif
