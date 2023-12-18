#include <iostream>
#include "box.h"

int main()
{
    Box box1(1.0, 2.0, 3.0);
    std::cout << "Volume of box1: " << box1.getVolume() << std::endl;

    return 0;
}
