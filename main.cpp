#include <iostream>
#include <sstream> 
#include <algorithm>
#include <vector>
#include <string>
#include "derivative.h"
#include "antiderivative.h"
#include "mvt.h"
#include "continuity.h"
int answer;

int main() 
{
 
 //STUFF
  std::string equation;
  std::string equation_two;
    double min;
    double max;
  std::string from;
  std::string to;
  
  
  
  std::cout << "1. Derivatives 2. Antiderivatives 3. Mean Value Theorem 4. Continuity 5. Riemann Sum";
  std::cin >> answer;

  //Derivatives
  if(answer==1)
  {
  std::cout << "f(x)=?\n";
  std::cin >> equation;
  derivative(equation);
  }
  //Antiderivatives
  if(answer==2)
  {
  std::cout << "f(x)=?\n";
  std::cin >> equation;
  antiderivative(equation);
  }
  //Mean Value Theorem
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
  //Continuity
  if(answer==4)
  {
    std::cout << "f(x)=?\n";
    std::cin >> equation;
    std::cout << "g(x)=?\n";
    std::cin >> equation_two;
    std::cout << "x > _?  x <= _?";
    std::cin >> x;
    continuity(equation, equation_two,x);
  }
}

int get_answer()
{
return answer;

}


