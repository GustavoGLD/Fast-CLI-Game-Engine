#include <functional>
#include <vector>
#include <map>
#include "Vectors.hpp"
#include "Drawable.hpp"

#include "Impl/VertexArrayImpl.hpp"

namespace gld
{

enum PrimitiveType { POINTS, LINE_STRIP, LINE_LOOP, TRIANGLES, PrTy_SIZE };

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