#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "../../includes/json.hpp"

#define function auto

using namespace std;
//using json = nlohmann::json;

class Console
{
public:
    template <typename T>
    void log(T text) { std::cout << text << std::endl; }
    string input(string text)
    {
        Console console;

        console.log(text);

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
    }
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
    let string = "";

    function carlos = [&console, &JSON, &variables, &string](json json_parsed, int i)
    {
        string += variables.concat("<h1>",json_parsed[i]["USERNAME"],"</h1>");
        string += variables.concat("<p>", json_parsed[i]["POST_DESC"], "</p>");
        string += variables.concat("<img src='", json_parsed[i]["PIC_LOCAL"], "' />");
        console.log("------------------------------------------------------------------------");
        console.log(" ");
    };

    // JSON.map(data["data"], carlos);

    // out << string;
    // out.close();

}

// {
    
//     typedef string let;
//     Console console;
//     Network network;
//     Variables variables;
//     Json JSON;

//     let url = "https://bar-do-jeiz.onrender.com/data";

//     let response = network.get(url);

//     json data = JSON.parse(response);

//     let teste = "CARLITO";

//     teste = variables.replace(teste, "CAR", "CARL");

//     function carlos = [&console, &JSON, &variables](json json_parsed, int i)
//     {
//         console.log(variables.concat("Username: ", json_parsed[i]["USERNAME"]));
//         console.log(variables.concat("Postagem: ", json_parsed[i]["POST_DESC"]));
//         console.log("------------------------------------------------------------------------");
//         console.log(" ");
//     };

//     JSON.map(data["data"], carlos);

//     let nome = console.input("Insira o nome:");
//     let sobrenome = console.input("Insira o sobrenome:");

//     let final = nome + " " + sobrenome;

//     console.log(final);
// }
