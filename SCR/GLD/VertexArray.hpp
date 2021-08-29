#include <functional>
#include <vector>
#include <map>
#include "Vectors.hpp"
#include "Drawable.hpp"

#define DRAW_DECLARING_PARAMETER const std::vector<gld::Vector2f>& vertices, std::string color, std::vector<std::vector<std::string>>& map
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
        
        float distX = vertices[i+1].x - vertices[i].x;
        float distY = vertices[i+1].y - vertices[i].y;

        int steps = std::abs(distX) > std::abs(distY) ? std::abs(distX) : std::abs(distY);
        steps *= 2;

        float increment_x = distX / steps;
        float increment_y = distY / steps;

        for (int s = 0; s < steps; s++) {
            gld::Vector2f ray1;
            ray1.x = vertices[i].x + (increment_x * s);
            ray1.y = vertices[i].y + (increment_y * s);

            gld::drawPoint(ray1, color, map);
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