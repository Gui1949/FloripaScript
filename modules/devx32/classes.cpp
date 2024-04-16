#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <numeric>
#include <windows.h>

#define function auto

using namespace std;

class Console
{
public:
    template <typename T>
    void log(T text) { std::cout << text << std::endl; }
    void pause() { system("pause"); }
    void sleep(int time) {
         Console console;
         
         console.log("Sleeping...");
         
         Sleep(time); 
    }
    string read(string text)
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
        std::string cmd = "ie " + url;
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
    typedef string let;
    typedef ofstream out_file;
    typedef ifstream file;
    Console console;
    Network network;
    Variables variables;
    
    network.get("http://169.254.39.199:8180/data");    
    
    console.sleep(30);
    
    file myfile("data.json");
    
    string line;
    
    if (myfile.is_open())
       {
        int total = 0;       

        string program = "";

        while (getline(myfile, line)){
              program = program + line + "\n";
              }
              
        console.log(program);
        }
   
    console.pause();
    

}
