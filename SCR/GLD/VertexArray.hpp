#include <functional>
#include <vector>
#include <map>
#include "Vectors.hpp"
#include "Drawable.hpp"

typedef std::vector<std::vector<std::string>>& Map;
#define DRAW_DECLARING_PARAMETER const std::vector<gld::Vector2f>& vertices, std::string color, Map map
typedef std::function<void(DRAW_DECLARING_PARAMETER)> DrawFunc;

namespace gld
{

enum PrimitiveType { POINTS, LINE_STRIP, LINE_LOOP, TRIANGLES, PrTy_SIZE };

DrawFunc drawPoints = [](DRAW_DECLARING_PARAMETER) {

    for (auto& vert : vertices)
        gld::drawPoint(vert, color, map);
};

DrawFunc drawLineStripe = [](DRAW_DECLARING_PARAMETER) {

    for (int i = 1; i < vertices.size(); i++) 
        gld::drawLine(vertices[i-1], vertices[i], color, map);
};

DrawFunc drawLineLoop  = [](DRAW_DECLARING_PARAMETER) {
    
    for (int i = 1; i < vertices.size(); i++) 
        gld::drawLine(vertices[i-1], vertices[i], color, map);

    gld::drawLine(vertices[0], vertices.back(), color, map);
};

DrawFunc drawTriangles = [](DRAW_DECLARING_PARAMETER) {

    int triangles = (int)(vertices.size() / 3);

    for (int i = 0; i < triangles*3; i+=3) {

        MakingLine line1(vertices[i], vertices[i+1]);
        MakingLine line2(vertices[i], vertices[i+2]);

        int steps = line1.steps > line2.steps ? line1.steps : line2.steps;
        line1.setSteps(steps);
        line2.setSteps(steps);

        for (int s = 0; s < steps; s++) {
            line1.updateNextPos();
            line2.updateNextPos();

            gld::drawLine(line1.next_pos, line2.next_pos, color, map);
        }

    }

};

std::map<gld::PrimitiveType, DrawFunc> drawFunc = {
    {gld::POINTS,     drawPoints},
    {gld::LINE_STRIP, drawLineStripe},
    {gld::LINE_LOOP,  drawLineLoop},
    {gld::TRIANGLES,  drawTriangles}
};


class VertexArray : public gld::Drawable, private std::vector<gld::Vector2f> {
private:
    gld::PrimitiveType type = gld::LINE_LOOP;

public:
    using vector::push_back;
    using vector::operator[];
    using vector::begin;
    using vector::end;

    void draw(std::vector<std::vector<std::string>>& map) {
        drawFunc[type](this[0], color, map);
    }

    void setPrimitiveType(gld::PrimitiveType type) {
        this->type = type;
    }
};

}