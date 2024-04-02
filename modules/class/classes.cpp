#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Console
{
public:
    void log(string text) { std::cout << text << std::endl; }
};

int main()
{
    Console console;
    string const cu = "carlito";
    console.log(cu);
}