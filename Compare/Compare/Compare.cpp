#include <iostream>
#include <fstream>
#include <optional>
#include <string>

struct Args
{
    std::string firstFileName;
    std::string secondFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: Compare.exe <file1> <file2>\n";
        return std::nullopt;
    }

    Args args;
    args.firstFileName = argv[1];
    args.secondFileName = argv[2];

    return args;
}

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);

    if (!args)
    {
        return 1;
    }

    //Открытие файлов для чтения
    std::ifstream firstFile;
    firstFile.open(args->firstFileName);

    if (!firstFile.is_open())
    {
        std::cout << "Failed to open '" << args->firstFileName << "' for reading\n";
        return 1;
    }

    std::ifstream secondFile;
    secondFile.open(args->secondFileName);
    if (!secondFile.is_open())
    {
        std::cout << "Failed to open '" << args->secondFileName << "' for reading\n";
        return 1;
    }

    //Сравнение файло построчно
    std::string str1;
    std::string str2;
    int i = 1;
    while (getline(firstFile, str1) && getline(secondFile, str2))
    {
        if (str1 != str2)
        {
            std::cout << "Files are different. Line number is " << i << "\n";
            return 1;
        }
        ++i;
    }

    //Обработка ошибок чтения файлов
    if (firstFile.bad())
    {
        std::cout << "Falied to read data from file1\n";
        return 1;
    }
    if (secondFile.bad())
    {
        std::cout << "Falied to read data from file2\n";
        return 1;
    }

    std::cout << "Files are equal\n";
    return 0;
}