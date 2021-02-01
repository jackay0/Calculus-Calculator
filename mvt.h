#include <iostream>
#include <sstream> 
#include <algorithm>
#include <vector>
#include <string>
#include <math.h> 

int count_operators_mvt(std::string s) 
{
  int count = 0;
  
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '+' ||s[i] == '-') count++;

  return count;
}
int count_digits_mvt(int x) 
{
  int length = 1;

  while ( x /= 10 )
  {
    length++;
  }
  return length;
}
std::string get_operator_mvt(std::string s)
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
void mvt(std::string equationx1, std::string from, std::string to)
{
  
  //THE OTHER INSTANCE WHERE X2 IS PLUGGED IN
  std::string equationx2 = equationx1;
  
  //THE OUTPUTS
  double x_one;
  double x_two;
  double y_one;
  double y_two;
  
  double num;

  //DENOMINATOR STUFF
  std::string x = "x";
  std::stringstream x1(from);
  std::stringstream x2(to);
   x1 >> x_one;
   x2 >> x_two;
   double denominator = x_two - x_one;
   
   
   double numerator;
   size_t index;
  for(int i = count_operators_mvt(equationx1)+1; i !=0; i--)
  {
   index = equationx1.find(x);
   int multiplier;
   if(equationx1.find(x) != std::string::npos)
    {
      //finds if it is negative
      if(equationx1[index-2]=='-')
      {
        multiplier = -1;
      }
      else{
        multiplier = 1;
      }
      equationx1.replace(index, 1, from);

      if(equationx1[index-1]){
        double coef = equationx1[index-1]*multiplier;
        double power;
        double temp_one_num; 
        std::string temp_one;
        double temp_two_num; 
        std::string temp_two;
        int i;
        temp_one = equationx1[index-1];
        temp_two = equationx1[index];
        std::stringstream one(temp_one);
        std::stringstream two(temp_two);
        one >> temp_one_num;
        two >> temp_two_num;

        //finds the exponent
        
        if(equationx1[index+2]/1)
        {
          std::string power;
          double exponent;
          power = equationx1[index+2];
          std::stringstream gr(power);
          gr >> exponent;
          
          temp_one_num = pow(temp_one_num,exponent);
        }
        
        if(get_operator_mvt(equationx1)==" + ")
        {
        y_one = y_one + temp_one_num*temp_two_num;
        }
        if(get_operator_mvt(equationx1)==" - ")
        {
        y_one = y_one - temp_one_num*temp_two_num;
        }
        else{
          y_one = temp_one_num*temp_two_num;
        }
        
      } 
      
      equationx2.replace(index, 1, to);
      int multiplier;
      if(equationx2[index-1]){
        //finds if it is negative
        if(equationx1[index-2]=='-')
        {
         multiplier = -1;
         }
        else{
          multiplier = 1;
        }
        double coef = equationx2[index-1]*multiplier;
        
        double temp_one_num; 
        std::string temp_one;
        double temp_two_num; 
        std::string temp_two;
        
        temp_one = equationx2[index-1];
        temp_two = equationx2[index];
        std::stringstream one(temp_one);
        std::stringstream two(temp_two);
        one >> temp_one_num;
        two >> temp_two_num;
        //finds exponent
        if(equationx1[index+2])
        {
          std::string power;
          double exponent;
          power = equationx2[index+2];
          std::stringstream gr(power);
          gr >> exponent;
          
          temp_two_num = pow(temp_two_num,exponent);
          
        }
        
        if(get_operator_mvt(equationx2)==" + ")
        {
        y_two = y_two + temp_one_num*temp_two_num;
        }
        if(get_operator_mvt(equationx2)==" - ")
        {
        y_two = y_two - temp_one_num*temp_two_num;
        }
        else{
          y_two = temp_one_num*temp_two_num;
        }
        
      } 
    
      
    }
      
    
  }
  num = (y_two-y_one)/(x_two-x_one);
  std::cout << num;
}
