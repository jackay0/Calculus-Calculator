#include <iostream>
#include <sstream> 
#include <algorithm>
#include <vector>
#include <string>

int count_operators_mvt(std::string s) 
{
  int count = 0;
  
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '+' ||s[i] == '-') count++;

  return count;
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
  
  //DENOMINATOR STUFF
  std::string x = "x";
  std::stringstream x1(from);
  std::stringstream x2(to);
   x1 >> x_one;
   x2 >> x_two;
   double denominator = x_two - x_one;
   
   
   double numerator;

   if(equationx1.find(x) != std::string::npos)
    {
      size_t index = equationx1.find(x);


      equationx1.replace(index, 1, from);

      if(equationx1[index-1]){
        double temp_one_num; 
        std::string temp_one;
        double temp_two_num; 
        std::string temp_two;
        
        temp_one = equationx1[index-1];
        temp_two = equationx1[index];
        std::stringstream one(temp_one);
        std::stringstream two(temp_two);
        one >> temp_one_num;
        two >> temp_two_num;

        y_one = temp_one_num*temp_two_num;
      } 

      equationx2.replace(index, 1, to);
      
      if(equationx2[index-1]){
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

        y_two = temp_one_num*temp_two_num;
      } 
    
      std::cout << (y_two-y_one)/(x_two-x_one);
    }
    





}