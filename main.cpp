#include <iostream>
#include <sstream> 


int main() {
 
 
 
  std::string equation;
  std::string new_one;
  std::string new_two;
  std::string new_temp;
  std::string x = "x";
  std::string answer;


  std::cout << "f(x)=?\n";
  std::cin >> equation;

  if(equation.find(x) != std::string::npos){
      
        
      //there is a bug where if the number ends in 0, its inherent value is 0 so it is treated like it is nonexstent.
       new_one = equation[equation.find(x)-1];
       for(int i = 2; equation[equation.find(x)-i]; i++)
       {
        new_one=new_one+equation[equation.find(x)-i];
       }
        
      new_two = equation[equation.find(x)+2]-1;

      std::stringstream num(new_two);
      std::stringstream num_two(new_one);
      int expo;
      int multiplier;

      int coef;

      num >> expo;
      num_two >> multiplier;

      coef = (expo+1)*(multiplier);
      
      
      std::cout <<  coef;
      std::cout << "x^";
      std::cout <<  expo;

  }
  else{

    std::cout << "Doesn't contain x, either change the variable letter or it is a whole number...";
  }

  
}