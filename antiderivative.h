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

double new_coefficient;
double new_exponent;
int count_operators_anti(std::string s) 
{
  int count = 0;

  for (int i = 0; i < s.size(); i++)
    if (s[i] == '+' ||s[i] == '-') count++;

  return count;
}

int count_digits_anti(int x) 
{
  int length = 1;

  while ( x /= 10 )
  {
    length++;
  }
  return length;
}

std::string get_operator_anti(std::string s)
{
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '+')
      {
        return " + ";
      }
    if (s[i] == '-')
      {
        return " - ";
      }
  }
  return " ";
}
void antiderivative(std::string equation)
{
for(int i = count_operators_anti(equation)+1; i !=0; i--)
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
  std::cout << get_operator_anti(equation);
  std::string temp = equation.substr(0,count_digits_anti(coefficient)+count_digits_anti(exponent)+2);
  
   equation = equation.erase(0 , temp.length());
}
  std::cout << " C";
}