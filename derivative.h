#include <iostream>
#include <sstream> 
#include <algorithm>
#include <vector>
#include <string>

int count_operators(std::string s) 
{
  int count = 0;

  for (int i = 0; i < s.size(); i++)
    if (s[i] == '+' ||s[i] == '-') count++;

  return count;
}

int count_digits(int x) 
{
  int length = 1;

  while ( x /= 10 )
  {
    length++;
  }
  return length;
}

std::string get_operator(std::string s)
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
void derivative(std::string equation) {
  //OPERATORS
  std::string addition = "+";
  std::string subtraction = "-";
  std::string multiplication = "/";
  std::string division = "*";
  std::string right_paranthesis = "(";
  std::string left_paranthesis = ")";
 
 //DERIVATIVE STUFF
  //std::string equation;
  std::string new_one;
  std::string new_two;
  std::string x = "x";
  
  

for(int i = count_operators(equation)+2; i !=0; i--)
{
      int expo;
      int multiplier;
      int coef;

  if(equation.find(x) != std::string::npos)
  {
      
        
      //there is a bug where if the number ends in 0, its inherent value is 0 so it is treated like it is nonexstent.
       new_one = equation[equation.find(x)-1];
       for(int i = 2; equation[equation.find(x)-i]; i++)
       {
        new_one=equation[equation.find(x)-i]+new_one;
       }
       
       
      
      
      new_two = equation[equation.find(x)+2]-1;
      
      std::stringstream num(new_two);
      std::stringstream num_two(new_one);
      

      num >> expo;
      num_two >> multiplier;

      coef = (expo+1)*(multiplier);
      
      
      std::cout <<  coef;
      std::cout << "x^";
      std::cout <<  expo;
      std::cout << get_operator(equation);
      
      

  }
  
  else
  {

    std::cout << "...";
    }
 
  //keeps loop going until there are no more operators
  std::string temp = equation.substr(0,count_digits(coef)+2);
  
   equation = equation.erase(0 , temp.length());

  //std::cout << "\n" + equation;
}
}