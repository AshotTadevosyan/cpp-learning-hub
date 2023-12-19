#include <iostream>
#include <random>
#include <set>

int Random()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(75, 90);

    return dis(gen);
}

int main()
{
    std::set<int> s;

    const int count = 15;

    for (size_t i = 0; i < count; i++)
    {
        s.insert(Random());
    }

    for (std::set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        std::cout << *it << " ";
    }
    
    return 0;
}
