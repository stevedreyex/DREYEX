#ifndef  SVG_LINE_H
#define SVG_LINE_H
#include <string>
#include "svg_shape.h"

class SvgLine : public SvgShape {
public:
    SvgLine(double x1, double y1, double x2, double y2): _x1(x1), _x2(x2), _y1(y1), _y2(y2)
    {

    }
    std::string toSVG() const
    {
      std::string temp = "<line x1=\"" + std::to_string(_x1) + "\" y1=\"" + std::to_string(_y1)
      + "\" x2=\"" + std::to_string(_x2) + "\" y2=\"" + std::to_string(_y2)
      + "\" stroke-width=\"" + std::to_string(this->stroke_width()) + "\" stroke=\"" + this->stroke_color() + "\" fill=\"" + this->fill_color() + "\"/>";
      return temp;
    }
private:
    double _x1, _y1, _x2, _y2;
};

#endif
