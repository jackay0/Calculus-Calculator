#include <iostream>
#include <sstream> 
#include <algorithm>
#include <vector>
#include <string>
#include <math.h> 

double plug_riemann(std::string equation, std::string num)
{
  double y;
   for(int i = count_operators_mvt(equation)+1; i !=0; i--)
  {
   int index = equation.find("x");
   
   if(equation.find("x") != std::string::npos)
    {
      
      //replaces the 'x' with the desired
      equation.replace(index, 1, num);

      double temp_one_num; 
      std::string temp_one;
      double temp_two_num; 
      std::string temp_two;
      temp_one = equation[index-1];
      temp_two = equation[index];
      std::stringstream one(temp_one);
      std::stringstream two(temp_two);
      one >> temp_one_num;
      two >> temp_two_num;
        
       
      std::string power;
      double exponent;
      power = equation[index+2];
      std::stringstream gr(power);
      gr >> exponent;
           



      temp_two_num = pow(temp_two_num,exponent);
        
        
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
  
  return y;
}







void riemann(std::string equation, int lower, int upper, int sub, int lrm)
{
  double length = (upper-lower)/sub;
  double totaly;

  if(lrm==1)
  {
    for(double i = lower+length; i <= upper; i=i+length)
    {
      std::string str = std::to_string(i);
      
      std::string str_new = str.substr(0,1);
    
      
      

      totaly = totaly + plug_riemann(equation,str_new);
  
    }
    
    
  }
  if(lrm==2){
    for(int i = lower; i < upper; i=i+length)
    {
      std::string str = std::to_string(i);
      
      std::string str_new = str.substr(0,1);
    
      totaly = totaly + plug_riemann(equation,str_new);

    }
  
  
  
  }
  if(lrm==3){
    for(int i = lower; i < upper; i = i+length)
    {
      
      std::string str = std::to_string((i+(i+length))/2);

      std::string str_new = str.substr(0,1);
      

      totaly = totaly + plug_riemann(equation,str_new);

      
      
    }
 
 
 
  
  }


std::cout << length*totaly;

}