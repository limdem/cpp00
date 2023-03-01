#include <fstream>
#include <string>
#include <iostream>
int main(int argc, char *argv[])
{
    std::ifstream fin1;
    std::string line1;
    std::ifstream fin2;
    std::string line2;

    fin1.open("19920104_091532.log");
    if (!fin1)
        return (1);
    fin2.open(argv[1]);
    if (!fin2)
        return (1);
    while (std::getline(fin1, line1))
    {
        line1 = line1.substr(17);
        std::cout << "line1: " << line1 << std::endl;
        while (std::getline(fin2, line2))
        {
            line2 = line2.substr(17);
            std::cout << "line2: " << line2 << std::endl;
            if (line1.compare(line2))
            {
                std::cout << "KO" << std::endl;
                return (1);
            }
            else
                break ;
        }
    }
    std::cout << "OK" << std::endl;
    return (0);
}