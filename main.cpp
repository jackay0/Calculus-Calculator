#include <iostream>
#include <sstream> 
#include <algorithm>
#include <vector>
#include <string>
#include "derivative.h"

int main() 
{
 
 //STUFF
  std::string equation;
  int answer;
  
  
  std::cout << "1. Derivatives 2. Antiderivatives";
  std::cin >> answer;


  if(answer==1)
  {
  std::cout << "f(x)=?\n";
  std::cin >> equation;
  derivative(equation);
  }




}