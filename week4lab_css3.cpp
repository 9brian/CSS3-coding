#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
string decToBin(int num); // Function
void end_print(int num, string sign_mag, string exponent, string significand);

int main()
{
  int num, ogNum; // I&D
  string sign_num; // I&D
  
  cout << "Enter an Integer Value: \n";
  cin >> num;
  ogNum = num; // Printable, before conversions
  
  
  if (num > 0) // Check if num is positive
  {
    sign_num = "0";
    
  }
  else // Check if num is negative
  {
    sign_num = "1";
    num = abs(num); // converting negative to positive
  }
  
  string binary = decToBin(num); // Convert base 10 to base 2
  
  if (binary.length() > 8) // Bin too large checker
  {
    cout << "Sorry, " << num << " is too large to store in our system.";
    return 0;
  }
  
  string significand = binary; // I&D, significand
  int exponent = binary.length(); 
  
  exponent = exponent + 15; // Dec exp + bias
  string bias_exp = decToBin(exponent); // Convert exp to base 2
  
  while (bias_exp.length() != 5) // Exp should be 5 bits long
    bias_exp = "0" + bias_exp;
  
  while (significand.length() != 8) // Signigicant should be 8 bits long
    significand = significand + "0";

  end_print(ogNum, sign_num, bias_exp, significand);
  return 0;
}
string decToBin(int num)
{
  string binary = "";
  string rev = "";
  while (num)
  {
    if (num %2 != 0){
      rev.append("1");
    }
    else if (num %2 == 0){
      rev.append("0");
    }
    num = num / 2;
  }

  for(int i=rev.length()-1; i>=0; i--){
    binary = binary + rev[i];  
  }
  return binary;
}
void end_print(int num, string sign_mag, string exponent, string significand){
  cout << "Here is how " << num << " is stored as a floating-point in memory: \n";
  cout << "------------------------------\n";
  cout << "|  " << sign_mag << "  |  " << exponent << "  |  " << significand << "  | \n";
  cout << "------------------------------";
}