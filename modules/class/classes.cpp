#include <cmath>
#include <iostream>
#include <string>
#include "../../includes/json.hpp"
using namespace std;
using json = nlohmann::json;

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

class Json
{
public:
    json parse(string json_string)
    {
        json data = json::parse(json_string);
        return data;
    };
};

int main()
{
    typedef string let;
    Console console;
    Network network;
    Json JSON;

    let url = "https://bar-do-jeiz.onrender.com/data";

    let response = network.get(url);

    json data = JSON.parse(response);

    int i = 0;

    int tamanho = data["data"].size();

    while (i < tamanho)
    {
        console.log(data["data"][i]["POST_DESC"]);
        i++;
    }
}