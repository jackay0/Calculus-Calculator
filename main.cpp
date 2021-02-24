#include <iostream>
#include <sstream> 
#include <algorithm>
#include <vector>
#include <string>
#include "derivative.h"
#include "antiderivative.h"
#include "mvt.h"
#include "continuity.h"
#include "riemann.h"
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
  
  int upper;
  int lower;
  int sub;
  int lrm;
  
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
  //Riemann's Sum
  if(answer==5)
  {
    std::cout << "f(x)=?\n";
    std::cin>>equation;
    std::cout << "Lower Bound?";
    std::cin >> upper;
    std::cout << "Upper Bound?";
    std::cin >> lower;
    std::cout << "Number of subintervals";
    std::cin >> sub;
    std::cout << "1. Right  2. Left  3. Middle";
    std::cin >> lrm;
    riemann(equation,upper,lower,sub,lrm);
  }



}

int get_answer()
{
return answer;

}


