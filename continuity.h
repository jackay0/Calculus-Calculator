#include <iostream>
#include <sstream> 
#include <algorithm>
#include <vector>
#include <string>
#include <bits/stdc++.h>





double plug(std::string equation, std::string x)
{
  double y;
   for(int i = count_operators_mvt(equation)+1; i !=0; i--)
  {
   int index = equation.find(x);
   int multiplier;
   
   if(equation.find(x) != std::string::npos)
    {
      //finds if it is negative
      if(equation[index-2]=='-')
      {
        multiplier = -1;
      }
      else{
        multiplier = 1;
      }
      equation.replace(index, 1, x);

      if(equation[index-1]){
        double coef = equation[index-1]*multiplier;
        double power;
        double temp_one_num; 
        std::string temp_one;
        double temp_two_num; 
        std::string temp_two;
        int i;
        temp_one = equation[index-1];
        temp_two = equation[index];
        std::stringstream one(temp_one);
        std::stringstream two(temp_two);
        one >> temp_one_num;
        two >> temp_two_num;

        //finds the exponent
        
        if(equation[index+2]/1)
        {
          std::string power;
          double exponent;
          power = equation[index+2];
          std::stringstream gr(power);
          gr >> exponent;
          
          temp_one_num = pow(temp_one_num,exponent);
        }
        
        if(get_operator_mvt(equation)==" + ")
        {
        y = y+ temp_one_num*temp_two_num;
        }
        if(get_operator_mvt(equation)==" - ")
        {
        y = y - temp_one_num*temp_two_num;
        }
        else{
          y = temp_one_num*temp_two_num;
        }
        
      } 
      
    }
    else{
      double number;
      std::stringstream r(equation);
        r >> number;
        y = number;
    }
  
  }
  
  return y;
}


//SOLVING
void continuity(std::string equation_one, std::string equation_two, std::string value)
{
  double y_one = plug(equation_one,value);
  double y_two = plug(equation_two,value);

  if(y_two = y_one)
  {
    std::cout<< "Continuous";

  }
  else{

    std::cout<< "NOT Continuous";
 }

  std::string eq_one = derivative(equation_one);
  std::string eq_two = derivative(equation_two);

  std::string e_one = "";

  for (auto x : eq_one) 
    {
        if (x == ' ')
        {
            e_one = e_one + "";
        }
        else {
            e_one = e_one + x;
        }
    }
  std::string e_two = "";

  for (auto x : eq_two) 
    {
        if (x == ' ')
        {
            e_two = e_two + "";
        }
        else {
            e_two = e_two + x;
        }
    }  


  double dy_one = plug(e_one,value);
  double dy_two = plug(e_two,value);



  if(dy_one == dy_two)
  {
      std::cout << "It is Differentiable";


  }
  else{
    std::cout<< dy_one;
    std::cout << dy_two;
    std::cout << "It is NOT Differentiable";

  }
}



