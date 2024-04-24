#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "../../includes/json.hpp"

#define funcao auto
#define se if

using namespace std;

class Cmd
{
public:
    template <typename T>
    void imprimir(T text) { std::cout << text << std::endl; }
    string ler(string text)
    {
        Cmd cmd;

        cmd.imprimir(text);

        char tmp[101];
        scanf("%100s", tmp);
        string response = tmp;

        return response;
    }
};

class Network
{
public:
    string get(string url)
    {
        std::string cmd = "curl -s " + url;
        FILE *p = _popen(cmd.c_str(), "r");
        char buffer[2];
        std::string body;
        if (!p)
        {
            return "Error";
        }
        while (fgets(buffer, sizeof(buffer), p))
        {
            body += buffer;
        }
        return body;
    };
};

class Variables
{
public:
    string replace(string variable, string to_be_replaced, string to_replace)
    {
        string response = variable.replace(variable.find(to_be_replaced), to_be_replaced.length(), to_replace);
        return response;
    };
    string concat(string param1, string param2, string param3)
    {
        Console console;
        string response = string(param1).append(param2).append(param3);
        return response;
    };
};

int main()
{
    typedef string caracter;
    typedef int inteiro;

    Console console;
    Variables variables;

    caracter line = "cucucuccuucucuc";

    caracter ponto_virgula = line.substr(line.length() - 1);

    se(ponto_virgula != "{")
    {
        line += ";";
    }

    console.log(line);
}