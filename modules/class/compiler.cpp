#include <stdio.h>
#include <string>
using namespace std;

class Console{
    public: 
    void log(string text){      
        std::string str = text + "\n";
        const char *cstr = str.c_str();
        printf(cstr);
    }
};


 int main(){
    Console console;
    string const cu = "carlito";
    console.log(cu);
}