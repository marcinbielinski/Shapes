#include <iostream>
#include <vector>
#include <memory>

class Shape {
public:
    Shape(){
        std::cout << "Shape Base constructor" << std::endl;
    };
    virtual ~Shape() {
        std::cout << "Shape Base destructor" << std::endl;
    };
    virtual void printMe() = 0;
    virtual double calcArea() = 0;
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : r(radius) {
        name = __func__;
        std::cout << "Circle Derived constructor" << std::endl;
    };
    ~Circle() override {
        std::cout << "Circle Derived destructor" << std::endl;
    };
    void printMe() override {
        std::cout << "My name is: " << name << " and my area is: " << calcArea() << std::endl;
    };
    double calcArea() override {
        return Pi*r*r;
    };
protected:
    double r;
    const double Pi = 3.14;
    const char* name;
};

class Rectangle : public Shape {
public:
    Rectangle(double height, double width) : a(height), b(width) {
        name = __func__;
        std::cout << "Rectangle Derived constructor" << std::endl;
    };
    ~Rectangle() override {
        std::cout << "Rectangle Derived destructor" << std::endl;
    };
    void printMe() override {
        std::cout << "My name is: " << name << " and my area is: " << calcArea() << std::endl;
    };
    double calcArea() override {
        return a*b;
    };
protected:
    double a;
    double b;
    const char* name;
};

class Triangle : public Shape {
public:
    Triangle(double side, double height) : a(side), h(height) {
        name = __func__;
        std::cout << "Triangle Derived constructor" << std::endl;
    };
    ~Triangle() override {
        std::cout << "Triangle Derived destructor" << std::endl;
    };
    void printMe() override {
        std::cout << "My name is: " << name << " and my area is: " << calcArea() << std::endl;
    };
    double calcArea() override {
        return (a*h)/2;
    };
protected:
    double a;
    double h;
    const char* name;
};

int main() {
    std::vector<std::shared_ptr<Shape>> vec;
    std::shared_ptr<Shape> circ1 = std::make_unique<Circle>(10);
    std::shared_ptr<Shape> rect1 = std::make_unique<Rectangle>(5, 10);
    std::shared_ptr<Shape> tria1 = std::make_unique<Triangle>(10, 5);

    vec.push_back(circ1);
    vec.push_back(rect1);
    vec.push_back(tria1);

    for (auto& elem : vec)
    {
        elem -> printMe();
    }

    std::vector<Shape*> vec2;

    Shape* circ2 = new Circle(20);
    Shape* rect2 = new Rectangle(10, 20);
    Shape* tria2 = new Triangle(20, 10);

    vec2.push_back(circ2);
    vec2.push_back(rect2);
    vec2.push_back(tria2);

    for (auto& elem : vec2)
    {
        elem -> printMe();
    }

    for (auto& elem : vec2)
    {
        std::cout << "I am being deleted manually :(" << std::endl;
        delete elem;
    }

    std::vector<Shape*> vec3;

    Circle* circ3 = new Circle(40);
    Rectangle* rect3 = new Rectangle(20, 40);
    Triangle* tria3 = new Triangle(40, 20);

    vec3.push_back(circ3);
    vec3.push_back(rect3);
    vec3.push_back(tria3);

    for (auto elem : vec3)
    {
        elem -> printMe();
    }

    for (auto& elem : vec2)
    {
        std::cout << "I am being deleted manually :(" << std::endl;
        delete elem;
    }

    return 0;
}
