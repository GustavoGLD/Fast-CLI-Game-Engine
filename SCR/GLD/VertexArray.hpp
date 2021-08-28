#include <functional>
#include <vector>
#include "Vectors.hpp"
#include "Drawable.hpp"

namespace gld
{

enum PrimitiveType { POINTS, LINE_STRIP, LINE_LOOP, TRIANGLES, PrTy_SIZE };

void drawPoints(std::vector<gld::Vector2f> vertices, 
                std::string color, 
                std::vector<std::vector<std::string>>& map) {

    for (auto& vert : vertices)
        gld::drawPoint(vert, color, map);
}
void drawLineStripe(std::vector<gld::Vector2f> vertices, 
                  std::string color, 
                  std::vector<std::vector<std::string>>& map) {

    for (int i = 1; i < vertices.size(); i++) 
        gld::drawLine(vertices[i-1], vertices[i], color, map);
}

void drawLineLoop(std::vector<gld::Vector2f> vertices, 
                  std::string color, 
                  std::vector<std::vector<std::string>>& map) {
    
    for (int i = 1; i < vertices.size(); i++) 
        gld::drawLine(vertices[i-1], vertices[i], color, map);

    gld::drawLine(vertices[0], vertices.back(), color, map);
}

void drawTriangles(std::vector<gld::Vector2f> vertices, 
                  std::string color, 
                  std::vector<std::vector<std::string>>& map) {

}

void (*drawing[PrTy_SIZE])(std::vector<gld::Vector2f> vertices, std::string color, std::vector<std::vector<std::string>>& map) {
    &drawPoints,
    &drawLineStripe,
    &drawLineLoop,
    &drawTriangles
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
        drawing[type](this[0], color, map);
    }

    void setPrimitiveType(gld::PrimitiveType type) {
        this->type = type;
    }
};

}