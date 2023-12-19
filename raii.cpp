#include <iostream>

class RAII 
{
public:
RAII() 
{
    std::cout << "Resource is acquired" << std::endl;
}

RAII(const RAII&) = delete;

RAII& operator=(const RAII&) = delete;

~RAII() 
{
    std::cout << "Resource is released" << std::endl;
}
};

int main()
{
    RAII raii;

    RAII raii2;

    return 0;
}
