#ifndef CSVREADER_H
#define CSVREADER_H

#include <QString>
#include <fstream>
#include <vector>
#include<string>

#include<algorithm>
#include<occupation.h>


class CSVReader
{
    std::ifstream fin;

public:
    CSVReader(const QString& filename );
    ~CSVReader();

    bool is_open() const { return  fin.is_open(); };

    std::vector<std::string> split(const std::string &str, char delim)
{
std::vector<std::string> tokens;

if (!str.empty())
{
size_t start = 0, end;
do {
end = str.find(delim, start); // поменял местами метод push_back и присвоение новой велечины end
tokens.push_back(str.substr(start, (end - start)));
start = end + 1;
} while (end != std::string::npos);
}

return tokens;
}
    std::vector<Occupation> readAll();

};



#endif // CSVREADER_H
