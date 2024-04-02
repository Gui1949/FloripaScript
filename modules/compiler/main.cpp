#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <numeric>
using namespace std;

int main(int argc, char *argv[])
{
  string line;
  ifstream myfile("../../main.fls");

  if (myfile.is_open()){

    int total = 0;

    while (getline(myfile, line))
    {
      string program = "";
      program = program + "#include <cmath>\n";
      program = program + "#include <iostream>\n";
      program = program + "#include <string>\n";
      program = program + "using namespace std;\n";
      program = program + "class Console{public:void log(string text){std::cout << text << std::endl;}};\n";
      program = program + "int main()\n";
      program = program + "{\n";
      program = program + "Console console;\n";
      program = program + line;
      program = program + "}";

      ofstream out("../../out/compiled.cpp");
      out << program;
      out.close();
    }
    myfile.close();
  }
  else cout << "Unable to open file";
}