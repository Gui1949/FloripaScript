#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <numeric>
using namespace std;

class Variables
{
public:
  string replace(string variable, string to_be_replaced, string to_replace)
  {
    string response = variable.replace(variable.find(to_be_replaced), to_be_replaced.length(), to_replace);
    return response;
  };
};

class Console
{
public:
    template <typename T>
    void log(T text) { std::cout << text << std::endl; }
};

int main(int argc, char *argv[])
{
  Variables variables;
  Console console;
  string line;
  ifstream myfile("../../main.fls");
  ifstream classFile("../model/model.cpp");

  if (myfile.is_open())
  {
    int total = 0;

    string program = "";

    while (getline(myfile, line))
    {
      program = program + line + "\n";
    }

    if (classFile.is_open())
    {

      string modelLines = "";
      program = variables.replace(program, "[]", "[&console, &JSON, &variables]");

      while (getline(classFile, line))
      {
        modelLines += line + "\n";
        console.log(modelLines);
      }

      string finalLines = variables.replace(modelLines, "//INSERT", program);

      ofstream out("../../out/compiled.cpp");
      out << finalLines;
      out.close();
      myfile.close();
      classFile.close();
    }
  }
  else
    cout << "Unable to open file";
}