#include <iostream>
#include <sstream> 
#include <algorithm>
#include <vector>
#include <string>
#include "derivative.h"
#include "antiderivative.h"
#include "mvt.h"
int main() 
{
 
 //STUFF
  std::string equation;
  std::string from;
  std::string to;
  int answer;
  
  
  std::cout << "1. Derivatives 2. Antiderivatives 3. Mean Value Theorem 4. Continuity";
  std::cin >> answer;


  if(answer==1)
  {
  std::cout << "f(x)=?\n";
  std::cin >> equation;
  derivative(equation);
  }
   if(answer==2)
  {
  std::cout << "f(x)=?\n";
  std::cin >> equation;
  antiderivative(equation);
  }

  if(answer==3)
  {
    std::cout << "f(x)=?\n";
    std::cin >> equation;
    std::cout << "From:";
    std::cin >> from;
    std::cout << "To:";
    std::cin >> to;
    mvt(equation,from,to);
  }

}