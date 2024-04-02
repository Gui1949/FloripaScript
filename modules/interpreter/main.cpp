#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <numeric>
using namespace std;

int main(int argc, char *argv[])
{
  string line;
  ifstream file("../../main.fls");

  if (file.is_open())
  {

    int total = 0;

    while (getline(file, line))
    {
      string expression = line;
      string newExpression;

      string consoleLogReplace = "console.log(";
      string quoteReplace = "\"";
      string parentReplace = ")";
      string semiColonReplace = ";";

      int pos = 0;
      int index;

      // Console Log

      while ((index = line.find(consoleLogReplace, pos)) != string::npos)
      {
        newExpression = line.replace(line.find(consoleLogReplace), consoleLogReplace.length(), "");
        newExpression = newExpression.replace(newExpression.find(quoteReplace), quoteReplace.length(), "");
        newExpression = newExpression.replace(newExpression.find(quoteReplace), quoteReplace.length(), "");
        newExpression = newExpression.replace(newExpression.find(parentReplace), parentReplace.length(), "");
        pos = index + 1;
        cout << newExpression << '\n';
      }

      // Let declaration

      string letDeclaration = "let";
      std::string equalSign = "=";
      pos = 0;

      while ((index = line.find(letDeclaration, pos)) != string::npos)
      {
        newExpression = line.replace(line.find(letDeclaration), letDeclaration.length(), "");
        newExpression = newExpression.replace(newExpression.find(semiColonReplace), semiColonReplace.length(), "");

        pos = index + 1;
      }

      std::string token;
      pos = 0;

      // Number storing and sum

      while ((index = newExpression.find(equalSign)) != std::string::npos)
      {
        token = newExpression.substr(0, index);
        newExpression.erase(0, index + equalSign.length());
        pos = index + 1;
        total += std::stoi(newExpression);
      }

      string sumFunction = "sum()";
      pos = 0;

      while ((index = expression.find(sumFunction, pos)) != std::string::npos)
      {
        pos = index + 1;
        std::cout << total << std::endl;
      }
    }
    file.close();
  }

  else
    cout << "Unable to open file";
}