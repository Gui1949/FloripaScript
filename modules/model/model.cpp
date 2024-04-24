#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

#define funcao auto
#define se if
#define enquanto while

using namespace std;

class Console
{
public:
    template <typename T>
    void imprimir(T text) { std::cout << text << std::endl; }
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
        Console cmd;
        string response = string(param1).append(param2).append(param3);
        return response;
    };
};

int main()
{
    typedef string caracter;
    typedef int inteiro;
    Console cmd;
    Variables variables;

    // INSERT
}