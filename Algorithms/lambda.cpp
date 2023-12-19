#include <iostream>


int sum (int a, int b)
{
    return a + b;
}

int main() 
{

    // Using the function

    int (*sum_ptr)(int, int) = sum;

    int result = sum_ptr(5, 3);

    auto sum_lambda = [](int a, int b) { return a + b; };
}