#include <cmath>
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <type_traits>

#define HEIGHT 40
#define WIDTH  80

namespace gld 
{

template<typename T>
struct Vector2 {
    T x;
    T y;

    Vector2() {
    
    }

    Vector2(T x, T y) {
        this->x = x;
        this->y = y;
    }
};

typedef Vector2<float> Vector2f;
typedef Vector2<int>   Vector2i;

void drawPoint(gld::Vector2f position, char filling, std::vector<std::vector<char>>& map) {
    if (position.y < 0) return;
    if (position.x < 0) return;
    if (position.y > map.size() -1)    return;
    if (position.x > map[0].size() -1) return;

    map[(int)position.y][(int)position.x] = filling;
}

void drawLine(gld::Vector2f vert1, gld::Vector2f vert2,  char filling, std::vector<std::vector<char>>& map) {
    float distX = std::abs(vert1.x - vert2.x);
    float distY = std::abs(vert1.y - vert2.y);

    int steps = distX > distY ? distX : distY;

    float increment_x = distX / steps;
    float increment_y = distY / steps;
        

    for (int i = 0; i < steps; i++) {
        gld::Vector2f new_pos;
        new_pos.x = vert1.x + (increment_x * i);
        new_pos.y = vert1.y + (increment_y * i);

        gld::drawPoint(new_pos, filling, map);
    }
}

class Drawable {
public:
    char filling = '@';

    virtual void draw(std::vector<std::vector<char>>& map) = 0;
    virtual void setFillChar(char filling) {
        this->filling = filling;
    }
};

class Window {
private:
    unsigned int height, width;
public:
    std::vector<std::vector<char>> map;

public:
    Window(gld::Vector2f size) {
        this->height = size.y;
        this->width  = size.x;
    }

    Window(unsigned int height,unsigned int width) {
        this->height = height;
        this->width  = width;
    }

    void clear(char backgroud = '.') {
        map.clear();

        for (int y = 0; y < height; y++) {
            std::vector<char> new_line;
            for (int x = 0; x < width; x++) {
                new_line.push_back(backgroud);
            }
            map.push_back(new_line);
        }
    }
    
    void draw(gld::Drawable& drawable) {
        drawable.draw(map);
    }

    void display() {
        system("clear");
        std::string buffer;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                buffer +=  map[y][x];
                //buffer += ' ';
            }
            buffer += "\n";
        }

        printf("%s", buffer.c_str());
    }
};

class Point : public Drawable {
public:
    gld::Vector2f position;

    void draw(std::vector<std::vector<char>>& map) {
        if (position.y < 0) return;
        if (position.x < 0) return;
        if (position.y > map.size() -1)    return;
        if (position.x > map[0].size() -1) return;

        map[(int)position.y][(int)position.x] = filling;
    }
    
    Point() {
        //nothing
    }

    Point(gld::Vector2f position) {
        this->position = position;
    }

    Point(float posX, float posY) {
        position.x = posX;
        position.y = posY;
    }
};

class Line : public Drawable {
public:
    gld::Vector2f vert1, vert2;

    void draw(std::vector<std::vector<char>>& map) {
        float distX = std::abs(vert1.x - vert2.x);
        float distY = std::abs(vert1.y - vert2.y);

        int steps = distX > distY ? distX : distY;

        float increment_x = distX / steps;
        float increment_y = distY / steps;
        

        for (int i = 0; i < steps; i++) {
            gld::Vector2f new_pos;
            new_pos.x = vert1.x + (increment_x * i);
            new_pos.y = vert1.y + (increment_y * i);

            gld::drawPoint(new_pos, filling, map);
        }
    }

};

class Rectangle : public Drawable {
public:
    gld::Vector2f position, size;
    float angle;
    
    Rectangle() {
        position = gld::Vector2f(0.0f, 0.0f);
    }

    Rectangle(gld::Vector2f size) {
        this->size = size;
    }
    
    Rectangle(float width, float height) {
        this->size = gld::Vector2f(width, height);
    }

    void draw(std::vector<std::vector<char>>& map) {
        //gld::Vector2f direction;
        float distX = std::sin(angle * M_PI/180.0f) * size.y;
        float distY = std::cos(angle * M_PI/180.0f) * size.y;
        //float distX = std::abs(direction.x - position.x);
        //float distY = std::abs(direction.y - position.y);

        int steps = std::abs(distX) > std::abs(distY) ? std::abs(distX) : std::abs(distY);
        steps *= 5;

        float increment_x = distX / steps;
        float increment_y = distY / steps;

        float incr_vet_x =  std::cos(angle * M_PI/180.0f) * size.x;
        float incr_vet_y = (std::sin(angle * M_PI/180.0f) * size.x) / 2;
    
        std::cout << incr_vet_x << "\t" << incr_vet_y << "\n";
        for (int i = 0; i < steps; i++) {
            gld::Vector2f ray, rayDir;
            ray.x = position.x + (increment_x * i);
            ray.y = position.y + (increment_y * i);
            
            rayDir.x = ray.x + incr_vet_x;
            rayDir.y = ray.y + incr_vet_y;

            gld::drawLine(ray, rayDir, filling, map);
        }       
    }
};

}

int main() {

    gld::Window window(40, 160);
    gld::Rectangle rectangle(30, 15);
    rectangle.position.x = 50;
    rectangle.position.y = 15;

    while (true) {
        rectangle.angle += 0.5;

        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
