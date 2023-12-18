#ifndef BOX_H
#define BOX_H

#include <iostream>

class Box
{
private:
    double length;
    double width;
    double height;

public:
    Box(double l, double w, double h);
    double getVolume();
    void setLength(double l);
    void setBreadth(double b);
    void setHeight(double h);
    double getLength();
    double getBreadth();
    double getHeight();
    ~Box();
};

Box::Box(double l, double w, double h) : length(l), width(w), height(h)
{
    std::cout << "Box constructor called." << std::endl;
}

Box::~Box()
{
    std::cout << "Box destructor called." << std::endl;
}

double Box::getVolume()
{
    return length * width * height;
}

void Box::setLength(double l)
{
    length = l;
}

void Box::setBreadth(double b)
{
    width = b;
}

void Box::setHeight(double h)
{
    height = h;
}

double Box::getLength()
{
    return length;
}

double Box::getBreadth()
{
    return width;
}

double Box::getHeight()
{
    return height;
}

#endif // BOX_H
