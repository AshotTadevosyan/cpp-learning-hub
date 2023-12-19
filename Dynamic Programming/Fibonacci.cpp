#include <iostream>

int memoization[1000];

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }

    if (memoization[n] != -1)
    {
        return memoization[n];
    }

    memoization[n] = fibonacci(n - 1) + fibonacci(n - 2);

    return memoization[n];
}

int main(int argc, char** argv)
{
    for (int i = 0; i < 1000; ++i)
    {
        memoization[i] = -1;
    }

    std::cout << fibonacci(10) << std::endl;

    return 0;
}
