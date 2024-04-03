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

  if (myfile.is_open())
  {

    int total = 0;

    string program = "";
    program = program + "#include <cmath>\n";
    program = program + "#include <iostream>\n";
    program = program + "#include <string>\n";
    program = program + "#include \"../includes/json.hpp\"\n";
    program = program + "using namespace std;\n";
    program = program + "using json = nlohmann::json;\n";
    program = program + "class Console\n";
    program = program + "{\n";
    program = program + "public:\n";
    program = program + "template <typename T>\n";
    program = program + "void log(T text) { std::cout << text << std::endl; }\n";
    program = program + "};\n";
    program = program + "class Network\
    {\
    public:\
      string get(string url)\
      {\
        std::string cmd = \"curl -s \" + url;\
        FILE *p = _popen(cmd.c_str(), \"r\");\
        char buffer[2];\
        std::string body;\
        if (!p)\
        {\
          return \"Error\";\
        }\
        while (fgets(buffer, sizeof(buffer), p))\
        {\
          body += buffer;\
        }\
        return body;\
      };\
    };\
    class Json\
    {\
    public:\
      json parse(string json_string)\
      {\
        json data = json::parse(json_string);\
        return data;\
      };\
    };\
    \n ";
    program = program + "int main()\n";
    program = program + "{\n";
    program = program + "typedef string let; \n";
    program = program + "Console console;\n";
    program = program + "Network network;\n";
    program = program + "Json JSON;\n";

    while (getline(myfile, line))
    {
      program = program + line + "\n";
    }

    program = program + "}";

    ofstream out("../../out/compiled.cpp");
    out << program;
    out.close();

    myfile.close();
  }
  else
    cout << "Unable to open file";
}