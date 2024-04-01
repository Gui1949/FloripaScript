#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main( int argc, char *argv[] )
{
  string line;
  ifstream myfile ("../../main.fls");
  if (myfile.is_open())
  {
    while (getline(myfile,line)){
    string newExpression;

    string consoleLogReplace = "console.log(";
    string quoteReplace = "\"";
    string parentReplace = ")";
    string semiColonReplace = ";";
    
    int pos = 0;
    int index;

    while((index = line.find(consoleLogReplace, pos)) != string::npos){
      newExpression = line.replace(line.find(consoleLogReplace),consoleLogReplace.length(),"");
      newExpression = newExpression.replace(newExpression.find(quoteReplace),quoteReplace.length(),"");
      newExpression = newExpression.replace(newExpression.find(quoteReplace),quoteReplace.length(),"");
      newExpression = newExpression.replace(newExpression.find(parentReplace),parentReplace.length(),"");
      newExpression = newExpression.replace(newExpression.find(semiColonReplace),semiColonReplace.length(),"");
      pos = index + 1;
      cout << newExpression << '\n';
    }

    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
}