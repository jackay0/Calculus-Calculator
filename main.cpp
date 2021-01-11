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
      
        
      
       new_one = equation[equation.find(x)-1];
       new_two = equation[equation.find(x)+2]-1;

      std::stringstream num(new_two);
      std::stringstream num_two(new_one);
      int t;
      int u;

      int v;

      num >> t;
      num_two >> u;

      v = (t+1)*(u);
      
      
      std::cout <<  v;
      std::cout << "x^";
      std::cout <<  t;

  }
  else{

    std::cout << "Doesn't contain x, either change the variable letter or it is a whole number...";
  }

  
}