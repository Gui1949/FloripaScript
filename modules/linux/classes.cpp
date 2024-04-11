#include <cmath>
#include <iostream>
#include <string>

#define function auto

using namespace std;

class Console
{
public:
    template <typename T>
    void log(T text) { std::cout << text << std::endl; }
};

// class Network
// {
// public:
//     string get(string url)
//     {
//         std::string cmd = "curl -s " + url;
//         FILE *p = _popen(cmd.c_str(), "r");
//         char buffer[2];
//         std::string body;
//         if (!p)
//         {
//             return "Error";
//         }
//         while (fgets(buffer, sizeof(buffer), p))
//         {
//             body += buffer;
//         }
//         return body;
//     };
// };

class Variables
{
public:
    string replace(string variable, string to_be_replaced, string to_replace)
    {
        string response = variable.replace(variable.find(to_be_replaced), to_be_replaced.length(), to_replace);
        return response;
    };
    string concat(string param1, string param2)
    {
        Console console;
        string response = string(param1).append(param2);
        return response;
    };
};

// class Json
// {
// public:
//     json parse(string json_string)
//     {
//         json data = json::parse(json_string);
//         return data;
//     };

//     template <typename Function>
//     void map(json json_parsed, Function func)
//     {
//         Console console;
//         Variables variables;

//         int qty = json_parsed.size();
//         int i = 0;

//         while (i < qty)
//         {
//             func(json_parsed, i);
//             i++;
//         }
//     }
// };

int main()
{
    Console console;

    function carlos = [&console](string texto){
        console.log(texto);
    };

    carlos("CUCETA");

}