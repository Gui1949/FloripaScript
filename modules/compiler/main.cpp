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
  ifstream myfile(argv[1]);
  ifstream classFile("../model/model.cpp");

  for (int i = 0; i < argc; ++i)
  {
    printf("argv[%d]: %s\n", i, argv[i]);
  }

  if (myfile.is_open())
  {
    int total = 0;

    string program = "";

    while (getline(myfile, line))
    {
      if (line.length() > 0)
      {
        string ponto_virgula = line.substr(line.length() - 1);

        if (ponto_virgula != "{")
        {
          line += ";";
        }

        console.log(line);

        if (line.find("function") == 0)
        {
          int parenteses = line.find("(");
          line = line.replace(parenteses, 1, "= [&console, &variables](");
        }

        program += line + "\n";
      }
    }

    if (classFile.is_open())
    {
      string modelLines = "";
      // try
      // {
      //   program = variables.replace(program, "===", "<<");
      // }
      // catch (exception e)
      // {
      //   console.log("erro");
      // }

      while (getline(classFile, line))
      {
        modelLines += line + "\n";
      }

      string finalLines = variables.replace(modelLines, "// INSERT", program);

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
