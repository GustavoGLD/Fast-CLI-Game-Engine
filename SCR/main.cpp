#include <iostream>
#include "GLD/GLD.hpp"

int main() {

    gld::Window window(160, 39);

    gld::VertexArray vertices;
    vertices.setPrimitiveType(gld::TRIANGLES);
    vertices.push_back(gld::Vector2f(2.0f, 2.0f));
    vertices.push_back(gld::Vector2f(45.0f, 30.0f));
    vertices.push_back(gld::Vector2f(130.0f, 25.0f));

    while (true) {
        float Cos = std::cos(window.getTime() * 2) / 2 + 0.5f;
        float Sin = std::sin(window.getTime() * 2) / 2 + 0.5f;

        vertices.setFillColor(255, 255, 0);

        window.clear();
        window.draw(vertices);
        window.display();

        std::cout << "FPS: " << 1 / window.getDeltaTime() << "\n";
    }

    return 0;
}