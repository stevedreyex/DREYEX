#include <fstream>

#include "../src/svg_circle.h"
#include "../src/svg_line.h"
#include "../src/svg_polygon.h"
#include "../src/svg_shape.h"

TEST(SvgTest, ConstructSvgCircle){
    // 建構一個SvgCircle的物件
    double x = 25, y = 15, r = 5;
    SvgCircle circle(x, y, r);

    // 測試SvgCircle 的 toSVG member function回傳結果是否正確
    std::string svg1 = circle.toSVG();
    std::string expect1 = "<circle cx=\"" + std::to_string(x) + "\" cy=\"" + std::to_string(y) + "\" r=\"" + std::to_string(r)
    + "\" stroke-width=\"0.000000\" stroke=\"black\" fill=\"black\"/>";
    EXPECT_EQ(expect1, svg1);

    // 測試改動SVG圖檔的顏色之後，toSVG member function回傳結果是否正確
    std::string strokeColor = "orangered", fillColor = "navy";
    double strokeWidth = 1;
    circle.setFillColor(fillColor);
    circle.setStroke(strokeWidth, strokeColor);
    std::string svg2 = circle.toSVG();
    std::string expect2 = "<circle cx=\"" + std::to_string(x) + "\" cy=\"" + std::to_string(y) + "\" r=\"" + std::to_string(r)
    + "\" stroke-width=\"" + std::to_string(strokeWidth) + "\" stroke=\"orangered\" fill=\"navy\"/>";
    EXPECT_EQ(expect2, svg2);
}

TEST(SvgTest, ConstructSvgLine){
    // 建構一個SvgLine的物件
    double x1 = 25, y1 = 15, x2 = 20, y2 = 20;
    SvgLine line(x1, y1, x2, y2);

    // 測試SvgLine 的 toSVG member function回傳結果是否正確
    std::string svg1 = line.toSVG();
    std::string expect1 = "<line x1=\"" + std::to_string(x1) + "\" y1=\"" + std::to_string(y1)
    + "\" x2=\"" + std::to_string(x2) + "\" y2=\"" + std::to_string(y2)
    + "\" stroke-width=\"0.000000\" stroke=\"black\" fill=\"black\"/>";
    EXPECT_EQ(expect1, svg1);

    // 測試改動SVG圖檔的顏色之後，toSVG member function回傳結果是否正確
    std::string strokeColor = "orangered", fillColor = "navy";
    double strokeWidth = 1;
    line.setFillColor(fillColor);
    line.setStroke(strokeWidth, strokeColor);
    std::string svg2 = line.toSVG();
    std::string expect2 = "<line x1=\"" + std::to_string(x1) + "\" y1=\"" + std::to_string(y1)
    + "\" x2=\"" + std::to_string(x2) + "\" y2=\"" + std::to_string(y2)
    + "\" stroke-width=\"" + std::to_string(strokeWidth) + "\" stroke=\"" + strokeColor + "\" fill=\"" + fillColor + "\"/>";
    EXPECT_EQ(expect2, svg2);
}

TEST(SvgTest, ConstructSvgPolygon){
    // 建構一個SvgPolygon的物件
    std::vector<double *> v;
    double p1[2] = {5, 5};
    double p2[2] = {10, 5};
    double p3[2] = {10, 10};
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    SvgPolygon polygon(v);

    // 測試SvgPolygon 的 toSVG member function回傳結果是否正確
    std::string svg1 = polygon.toSVG();
    std::string expect1 = "<polygon points=\"" + std::to_string(p1[0]) + " " + std::to_string(p1[1]) + " "
    + std::to_string(p2[0]) + " " + std::to_string(p2[1]) + " " + std::to_string(p3[0]) + " " + std::to_string(p3[1])
    + "\" stroke-width=\"0.000000\" stroke=\"black\" fill=\"black\"/>";
    EXPECT_EQ(expect1, svg1);

    // 測試改動SVG圖檔的顏色之後，toSVG member function回傳結果是否正確
    std::string strokeColor = "orangered", fillColor = "navy";
    double strokeWidth = 1;
    polygon.setFillColor(fillColor);
    polygon.setStroke(strokeWidth, strokeColor);
    std::string svg2 = polygon.toSVG();
    std::string expect2 = "<polygon points=\"" + std::to_string(p1[0]) + " " + std::to_string(p1[1]) + " "
    + std::to_string(p2[0]) + " " + std::to_string(p2[1]) + " " + std::to_string(p3[0]) + " " + std::to_string(p3[1])
    + "\" stroke-width=\"" + std::to_string(strokeWidth) + "\" stroke=\"" + strokeColor + "\" fill=\"" + fillColor + "\"/>";
    EXPECT_EQ(expect2, svg2);
}

TEST(SvgTest, makeSvgOutput){
    std::vector<SvgShape *> shapes;     // 作為呼叫makeSvgOutpu用的引數
    // 加入一個SvgCircle
    double x = 25, y = 15, r = 5;
    shapes.push_back(new SvgCircle(x, y, r));
    // 加入一個SvgLine
    double x1 = 25, y1 = 15, x2 = 20, y2 = 20;
    shapes.push_back(new SvgLine(x1, y1, x2, y2));
    // 加入一個SvgPolygon
    std::vector<double *> v;
    double p1[2] = {5, 5};
    double p2[2] = {10, 5};
    double p3[2] = {10, 10};
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    shapes.push_back(new SvgPolygon(v));

    // 測試所有Shape同時輸出成Svg格式的結果
    std::string svgOutput1 = makeSvgOutput(1500, 1500, shapes);
    std::string expect1 = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"1500\" height=\"1500\" viewBox=\"0 0 100 100\"><circle cx=\"25.000000\" cy=\"15.000000\" r=\"5.000000\" stroke-width=\"0.000000\" stroke=\"black\" fill=\"black\"/><line x1=\"25.000000\" y1=\"15.000000\" x2=\"20.000000\" y2=\"20.000000\" stroke-width=\"0.000000\" stroke=\"black\" fill=\"black\"/><polygon points=\"5.000000 5.000000 10.000000 5.000000 10.000000 10.000000\" stroke-width=\"0.000000\" stroke=\"black\" fill=\"black\"/></svg>";
    EXPECT_EQ(expect1, svgOutput1);

    // 測試所有 Shape 設定過顏色後回傳是否正確
    std::string strokeColor = "orangered", fillColor = "navy";
    double strokeWidth = 1;
    for (auto iterator = shapes.begin(); iterator != shapes.end(); iterator++){
        setSvgShapeStyle((*iterator), strokeWidth, strokeColor, fillColor);
    }
    std::string svgOutput2 = makeSvgOutput(1500, 1500, shapes);
    std::string expect2 = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"1500\" height=\"1500\" viewBox=\"0 0 100 100\"><circle cx=\"25.000000\" cy=\"15.000000\" r=\"5.000000\" stroke-width=\"1.000000\" stroke=\"orangered\" fill=\"navy\"/><line x1=\"25.000000\" y1=\"15.000000\" x2=\"20.000000\" y2=\"20.000000\" stroke-width=\"1.000000\" stroke=\"orangered\" fill=\"navy\"/><polygon points=\"5.000000 5.000000 10.000000 5.000000 10.000000 10.000000\" stroke-width=\"1.000000\" stroke=\"orangered\" fill=\"navy\"/></svg>";
    EXPECT_EQ(expect2, svgOutput2);

    // 將heap空間釋放
    for (auto iterator = shapes.begin(); iterator != shapes.end(); iterator++){
        delete (*iterator);
    }
}

TEST (ConvexPolygon, RegularConvexPolygon){
    std::vector<SvgShape *> shapes;     // 作為呼叫makeSvgOutpu用的引數

    // 加入一個SvgCircle
    double x = 50, y = 50, r = 10;
    shapes.push_back(new SvgCircle(x, y, r));

    // 加入一個SvgPolygon
    std::vector<double *> v;
    double p1[2] = {20, 20};
    double p2[2] = {30, 20};
    double p3[2] = {20, 30};
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    shapes.push_back(new SvgPolygon(v));

    // 加入一個SvgLine
    double x1 = 25, y1 = 25, x2 = 50, y2 = 50;
    shapes.push_back(new SvgLine(x1, y1, x2, y2));

    // 更改所有shape的style
    std::string strokeColor = "orangered", fillColor = "navy";
    double strokeWidth = 1;
    for (auto iterator = shapes.begin(); iterator != shapes.end(); iterator++){
        setSvgShapeStyle((*iterator), strokeWidth, strokeColor, fillColor);
    }
    std::ofstream ofs("Shapes.svg");
    ofs << makeSvgOutput(1500, 1500, shapes);
    ofs.close();

    // 將heap空間釋放
    for (auto iterator = shapes.begin(); iterator != shapes.end(); iterator++){
        delete (*iterator);
    }
}
