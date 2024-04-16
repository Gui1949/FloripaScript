#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "../includes/json.hpp"


#define function auto

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
        template <typename Function>
    void map(json json_parsed, Function func)
    {
        Console console;
        Variables variables;

        int qty = json_parsed.size();
        int i = 0;

        while (i < qty)
        {
            func(json_parsed, i);
            i++;
        }
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
    typedef string let;
    typedef ofstream file;
    Console console;
    Network network;
    Variables variables;
    Json JSON;

    let url = "https://bar-do-jeiz.onrender.com/data";
let response = network.get(url);
json data = JSON.parse(response);

console.log("Puxando todas as Postagens do Bar do Jeiz de colocando em um arquivo .html");

file out("index.html");
let html = "";

function carlos = [&console, &JSON, &variables, &html](json json_parsed, int i){
        html += variables.concat("<h1>",json_parsed[i]["USERNAME"],"</h1>");
        html += variables.concat("<p>", json_parsed[i]["POST_DESC"], "</p>");
        html += variables.concat("<img src='", json_parsed[i]["PIC_LOCAL"], "' />");
        console.log("------------------------------------------------------------------------");
        console.log(" ");
};

JSON.map(data["data"], carlos);

out << html;
out.close();

//TODO: Desobrigar ponto e vírgula | Colocar barra barra como comentário na extensão

}
