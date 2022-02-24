#include "csvreader.h"


CSVReader::CSVReader(const QString& filename)
{
     fin.open(filename.toLatin1().data());
}

CSVReader::~CSVReader()
{
    fin.close();
}
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
 std::vector<Occupation> CSVReader::readAll(){
 std::vector<Occupation> result;

    if (fin.is_open()){
    std::string line;
              while (getline(fin, line))
              {
               auto v = CSVReader::split(line, ';');

               Occupation zan;
               zan.n = std::stoi( v[0]);
               zan.predmet = QString::fromStdString(v[1]);
               zan.tipe = static_cast<TIPE>(std::stoi(v[2]));
               zan.aud = std::stoi(v[3]);

               result.push_back(zan);
              }
}
    return result;
 }
