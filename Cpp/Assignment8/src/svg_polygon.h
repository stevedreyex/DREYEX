#ifndef  SVG_POLYGON_H
#define SVG_POLYGON_H
#include <string>
#include "svg_shape.h"

class SvgPolygon : public SvgShape {
public:
    SvgPolygon(std::vector<double *> const & v): _v(v)
    {

    }
    std::string toSVG() const
    {
      std::string temp = "<polygon points=\"" + std::to_string(_v[0][0]) + " " + std::to_string(_v[0][1]) + " "
      + std::to_string(_v[1][0]) + " " + std::to_string(_v[1][1]) + " " + std::to_string(_v[2][0]) + " " + std::to_string(_v[2][1])
      + "\" stroke-width=\"" + std::to_string(this->stroke_width()) + "\" stroke=\"" + this->stroke_color() + "\" fill=\"" + this->fill_color() + "\"/>";
      return temp;
    }
private:
    std::vector<double *> _v;
};

#endif
