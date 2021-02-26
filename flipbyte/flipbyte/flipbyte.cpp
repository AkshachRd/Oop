#include <iostream>
#include <string>
#include <optional>

std::optional<int> ParseDecNum(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: flipbyte.exe <input byte>";
        return std::nullopt;
    }

    std::string inputString = argv[1];

    size_t pos;
    uint8_t byte;
    try 
    {
        byte = static_cast<uint8_t>(std::stoi(inputString, &pos));
    }
    catch (const std::invalid_argument&)
    {
        pos = std::string::npos;
    }

    if (pos != inputString.length())
    {
        std::cout << "Invalid argument was given\n";
        std::cout << "Usage: flipbyte.exe <input byte>";
        return std::nullopt;
    }

    return byte;
}

/*

ABCDEFGH
EFGHABCD меняем сосендние 4-ки битов
GHEFCDAB меняем сосендние пары битов
HGFEDCBA меняем сосендние пары биты
*/


uint8_t FlipByte(uint8_t byte)
{
    uint8_t result = 0;
    uint8_t n;
    for (int i = 0; i <= 7; ++i)
    {
        n = byte & (1 << i);
        if (i < 4)
        {
            n = n << (7 - 2 * i);
        }
        else
        {
            n = n >> (2 * i - 7);
        }
        result |= n;
    }
    return result;
}

int main(int argc, char *argv[])
{
    auto byte = ParseDecNum(argc, argv);

    if (!byte)
    {
        return 1;
    }
    
    if (byte > 255 || byte < 0)
    {
        std::cout << "The input number not in acceptable range (0-255).";
        return 1;
    }

    std::cout << static_cast<int>(FlipByte(byte.value())) << "\n";
    return 0;
}