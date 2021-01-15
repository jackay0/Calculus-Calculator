#include <iostream>
#include <sstream> 
#include <algorithm>
#include <vector>
#include <string>

std::string new_one;
std::string new_two;
std::string x = "x";

int coefficient;
int exponent;

int new_coefficient;
int new_exponent;

void antiderivative(std::string equation)
{

  if(equation.find(x) == std::string::npos){
  std::cout << equation;
  std::cout << "x";
  }
  
  
  
  if(equation.find(x) != std::string::npos)
  {
      
        
    //RETRIEVES COEFFICIENT AND EXPONENT
    new_one = equation[equation.find(x)-1];
    for(int i = 2; equation[equation.find(x)-i]; i++)
    {
      new_one=equation[equation.find(x)-i]+new_one;
    }
      new_two = equation[equation.find(x)+2];
       
       
    //CONVERTS THEM INTO INTS
    std::stringstream num(new_two);
    std::stringstream num_two(new_one);
      
      num >> exponent;
      num_two >> coefficient;
      
  }
  //FINAL MATH
  new_exponent = exponent+1;
  new_coefficient = coefficient/new_exponent;
  std::cout << new_coefficient;
  std::cout << "x^";
  std::cout << new_exponent;
  
  std::cout << " + C";
}