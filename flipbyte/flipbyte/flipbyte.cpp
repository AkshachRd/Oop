#include <iostream>
#include <string>

unsigned int flipByte(const unsigned int &decNum)
{
    unsigned int firstPart = (decNum & 0x0f) << 4;
    unsigned int secondPart = (decNum & 0xf0) >> 4;
    return secondPart | firstPart;
}

int main(int argc, char *argv[])
{
    size_t pos;
    unsigned int decNum = std::stoi(argv[1], &pos);
    
    if (decNum > 255 || decNum < 0)
    {
        std::cout << "The input number not in acceptable range (0-255).\n";
        return 1;
    }

    std::cout << flipByte(decNum) << "\n";
    return 0;
}