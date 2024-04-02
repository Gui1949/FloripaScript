#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Console
{
public:
    template <typename T>
    void log(T text) { std::cout << text << std::endl; }
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

int main()
{
    typedef string let;
    Console console;
    Network network;

    let url = "https://bar-do-jeiz.onrender.com/data";

    let response = network.get(url);

    console.log(response);
}