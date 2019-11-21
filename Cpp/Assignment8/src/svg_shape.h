#ifndef  SVG_SHAPE_H
#define SVG_SHAPE_H
#include <string>

class SvgShape {
public:
    SvgShape()
    {
      _strokeWidth = 0.0;
      _strokeColor = "black";
      _fillColor = "black";
    }
    void setFillColor(std::string fillColor)
    {
      _fillColor = fillColor;
    }
    void setStroke(double strokeWidth, std::string strokeColor)
    {
      _strokeColor = strokeColor;
      _strokeWidth = strokeWidth;
    }
    virtual std::string toSVG() const = 0;
protected:
    double stroke_width() const
    {
      return _strokeWidth;
    }
    std::string stroke_color() const
    {
      return _strokeColor;
    }
    std::string fill_color() const
    {
      return _fillColor;
    }
private:
    double _strokeWidth;
    std::string _fillColor, _strokeColor;
};
void setSvgShapeStyle(SvgShape * shape, double strokeWidth, std::string strokeColor, std::string fillColor)
{
  shape->setStroke(strokeWidth, strokeColor);
  shape->setFillColor(fillColor);
}
std::string makeSvgOutput(int width, int height, std::vector<SvgShape *> const & shape)
{
  std::string svg_xmls = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" + std::to_string(width) + "\" height=\"" + std::to_string(height) + "\" viewBox=\"0 0 100 100\">";
  std::string svg_members;
  for (auto iterator = shape.begin(); iterator != shape.end(); iterator++)
  {
      svg_members += (*iterator)->toSVG();
  }
  std::string temp = (svg_xmls + svg_members + "</svg>") ;
  return temp;
}

#endif
