#include <iostream>
#include <string>
#include <optional>

std::optional<int> ParseByte(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: flipbyte.exe <input byte>\n";
        return std::nullopt;
    }

    std::string inputString = argv[1];

    size_t pos;
    uint8_t byte;
    int intByte;

    try 
    {
        intByte = std::stoi(inputString, &pos);
        if (intByte > 255 || intByte < 0)
        {
            std::cout << "The input number not in acceptable range (0-255)\n";
            return std::nullopt;
        }
    }
    catch (const std::invalid_argument&)
    {
        pos = std::string::npos;
    }

    if (pos != inputString.length())
    {
        std::cout << "Invalid argument was given\n";
        std::cout << "Usage: flipbyte.exe <input byte>\n";
        return std::nullopt;
    }

    byte = static_cast<uint8_t>(intByte);
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
    const uint8_t maxBit = 7, minBit = 0;
    uint8_t shiftBit, shiftBitMask, shift, result = 0;

    for (uint8_t bit = minBit; bit <= maxBit; ++bit)
    {
        shiftBitMask = 1 << bit;
        shiftBit = byte & shiftBitMask;

        if (bit < (maxBit + 1) / 2)
        {
            shift = maxBit - 2 * bit;
            shiftBit <<= shift;
        }
        else
        {
            shift = 2 * bit - maxBit;
            shiftBit >>= shift;
        }
        result |= shiftBit;
    }

    return result;
}

int main(int argc, char *argv[])
{
    auto byte = ParseByte(argc, argv);

    if (!byte)
    {
        return 1;
    }

    std::cout << static_cast<int>(FlipByte(byte.value())) << "\n";
    return 0;
}