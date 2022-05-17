#include <iostream>
#include <string>
#include <stdexcept>

const double pi = 3.141592;

class Circle{
public:
    Circle();
    Circle(double r);

    double getradius() const { return radius; }
    void setradius(double m_radius) { radius = m_radius; }
    double circumference() const { return 2 * radius * pi; }
    double circlearea() const { return pi * radius * radius; }
    double doubleradius() const { return radius * 2; }

    virtual std::string Info(){
        return "Radius of Circle: " + std::to_string(radius)               + "\n"
               "Circumreference: "  + std::to_string(circumference()) + "\n"
               "Circle Area: "      + std::to_string(circlearea())    + "\n"
               "Double Radius: "    + std::to_string(doubleradius());
    }

    friend std::ostream& operator << (std::ostream &os, const Circle &c);
    friend std::istream& operator >> (std::istream &is, Circle &c);

private:
    double radius;
};

Circle::Circle() :
    radius(1)
{}

Circle::Circle(double radius) :
    radius(radius)
{
    if(radius <= 0)
        throw std::invalid_argument("Wrong Radius. Circle cannot be create. ");
}

std::ostream& operator << (std::ostream &os, const Circle &c)
{
    return os << "Radius of Circle: " << c.radius << "\nCircumreference: " << c.circumference() << "\nCircle Area: "
              << c.circlearea() << "\nDouble Radius: " << c.doubleradius() << std::endl;
}

std::istream& operator >> (std::istream &is, Circle &c)
{
    double tmp_radius;
    std::cout << "Radius: ", is >> tmp_radius;

    while(tmp_radius <= 0 ) {
        std::cout << "Wrong Radius. Try again." << std::endl;
        std::cout << "Radius: ", is >> tmp_radius;
    }

    c.radius = tmp_radius;
    return is;
}

class ColoredCircle : public Circle{
public:
    ColoredCircle();

    ColoredCircle(double r, std::string c);

    friend std::ostream& operator << (std::ostream &os, const ColoredCircle &cc);
    friend std::istream& operator >> (std::istream &is, ColoredCircle &cc);

private:
    std::string color;
};

ColoredCircle::ColoredCircle() :
    color("Blue")
{}

ColoredCircle::ColoredCircle(double r, std::string c) :
    Circle(r), color(c)
{
    if(r <= 0)
        throw std::invalid_argument("Wrong Radius. Circle cannot be create. ");
}

std::ostream& operator << (std::ostream &os, const ColoredCircle &cc)
{
    return os << "Radius: " << cc.getradius() << "\nColor: " << cc.color << "\nCircumreference: " << cc.circumference()
              << "\nColored Circle area: " << cc.circlearea() << "\nDouble Radius: " << cc.doubleradius() << std::endl;
}

std::istream& operator >> (std::istream &is, ColoredCircle &cc)
{
    double tmp_radius;

    std::cout << "Enter Color: ", is >> cc.color;
    std::cout << "Enter Radius: ", is >> tmp_radius;

    while(tmp_radius <= 0 ) {
        std::cout << "Wrong Radius. Try again." << std::endl;
        std::cout << "Radius: ", is >> tmp_radius;
    }

    cc.setradius(tmp_radius);

    return is;
}

int main(){
    Circle col;
    ColoredCircle colcir;
    try{
        std::cin >> col;
        std::cout << col << std::endl;
        std::cin >> colcir;
        std::cout << colcir << std::endl;

    } catch (std::exception& ex){
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}
