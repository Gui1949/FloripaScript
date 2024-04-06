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

class Variables
{
public:
    string replace(string variable, string to_be_replaced, string to_replace)
    {
        string response = variable.replace(variable.find(to_be_replaced), to_be_replaced.length(), to_replace);
        return response;
    };
};

int main()
{
    typedef string let;
    Console console;
    Network network;
    Variables variables;
    Json JSON;

    let url = "https://bar-do-jeiz.onrender.com/data";

    let response = network.get(url);

    json data = JSON.parse(response);

    let teste = "CARLITO";

    teste = variables.replace(teste, "CAR", "CARL");

    auto carlos = [&console, &JSON](json data)
    {
        console.log("Exibindo os 5 primeiros posts do Bar do Jeiz");

        console.log(data["data"][0].size());

        

        return 0;
    };

    carlos(data);
}