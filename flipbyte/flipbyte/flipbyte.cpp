#include <iostream>
#include <string>
#include <optional>

std::optional<unsigned int> ParseDecNum(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: flipbyte.exe <input byte>\n";
        return std::nullopt;
    }

    std::string inputString = argv[1];

    size_t pos;
    unsigned int decNum = std::stoi(inputString, &pos);

    if (pos != inputString.length())
    {
        std::cout << "Invalid argument was given\n";
        std::cout << "Usage: flipbyte.exe <input byte>\n";
        return std::nullopt;
    }

    return decNum;
}

unsigned int flipByte(unsigned int &decNum)
{
    unsigned int firstPart = (decNum & 0x0f) << 4;
    unsigned int secondPart = (decNum & 0xf0) >> 4;
    return secondPart | firstPart;
}

int main(int argc, char *argv[])
{
    auto decNum = ParseDecNum(argc, argv);

    if (!decNum)
    {
        return 1;
    }
    
    if (decNum > 255 || decNum < 0)
    {
        std::cout << "The input number not in acceptable range (0-255).\n";
        return 1;
    }

    std::cout << flipByte(decNum.value()) << "\n";
    return 0;
}