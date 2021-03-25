#include <iostream>
#include <string>
#include <regex>
#include <optional>

struct Args
{
    std::string searchString;
    std::string replaceString;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: replace.exe <search-string> <replace-string>\n";
        return std::nullopt;
    }

    Args args;
    args.searchString = argv[1];
    args.replaceString = argv[2];

    return args;
}

std::string FindAndReplace(std::string const& subject, std::string const& search, std::string const& replace)
{
    std::string newSubject = subject;
    newSubject = std::regex_replace(newSubject, std::regex(search), replace);
    return newSubject;
}

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);

    if (!args)
    {
        return 1;
    }
    std::string one;
    std::getline(std::cin, one)

    std::cout << FindAndReplace("The quick brdogown dog fox jumps over the lazy dog", "dog", "cat");

    return 0;
}