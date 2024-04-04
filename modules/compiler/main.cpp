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

int main(int argc, char *argv[])
{
  Variables variables;
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
      typedef void (*vFunctionCall)(int args);\
      void fields(json json_parsed, string obj_name, string final_name)\
      {\
        Console console;\
        int i = 0;\
        int size = json_parsed[obj_name].size();\
        while (i < size)\
        {\
          console.log(json_parsed[obj_name][i][final_name]);\
          i++;\
        }\
      };\
      void top(json json_parsed, string obj_name, int top_values)\
      {\
        Console console;\
        int i = 1;\
        int size = json_parsed[obj_name].size();\
        while (i < top_values)\
        {\
          console.log(json_parsed[obj_name][i]);\
          i++;\
        }\
      }\
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
  program = variables.replace(program, "[]", "[&console, &JSON]");
  ofstream out("../../out/compiled.cpp");
  out << program;
  out.close();

  myfile.close();
}
else cout << "Unable to open file";
}