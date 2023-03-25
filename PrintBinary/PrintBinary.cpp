#include <iostream>
#include <string>

void PrintBinary(int n)
{
    const int size = sizeof(n) * 8;
    std::string bits(size, '0');

    for (int i = size - 1; i >= 0; i--)
    {
        bits[i] = '0' + (n & 1);
        n >>= 1;
    }

    std::cout << bits << std::endl;
}