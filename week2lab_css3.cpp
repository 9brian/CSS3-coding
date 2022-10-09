#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
using namespace std;

string dec_to_bin(int dec);
string bin_to_hex(string bin);
int hex_to_dec(string hex);

int main()
{
  char option;
  int decimal;
  string binary, hexadecimal;

  
  // Segmentation fault if number is too large or too small sometimes?
  // or if binary length isnt divisible by 4?
  cout << "*******************\n";
  cout << " NUMERIC CONVERTER\n";
  cout << "*******************\n";
  cout << "Which numeric base is the value in?" << endl;
  cout << "a. Decimal" << endl;
  cout << "b. Binary" << endl;
  cout << "c. Hexadecimal" << endl;

  cout << "Selection: ";
  cin >> option;

  cout << "What is the value: ";
  if (option == 'A' || option == 'a')
  {
    cin >> decimal;
    binary = dec_to_bin(decimal);
    hexadecimal = bin_to_hex(binary);
  }
  else if (option == 'B' || option == 'b')
  {
    cin >> binary;
    hexadecimal = bin_to_hex(binary);
    decimal = hex_to_dec(hexadecimal);
  }
  else if (option == 'C' || option == 'c')
  {
    cin >> hexadecimal;
    decimal = hex_to_dec(hexadecimal);
    binary = dec_to_bin(decimal);
  }
  else
  {
    cout << "***** BYE! ******" << endl;
    exit(1);
  }

  cout << "*********************\n";
  cout << "\tResults\n";
  cout << "*********************\n";
  cout << "Decimal: " << decimal << endl;
  cout << "Binary: " << binary << endl;
  cout << "Hexadecimal: " << hexadecimal << endl;

  return 0;
}
string dec_to_bin(int dec){
  string s = ""; // I&D
  string rev = ""; // I&D

  while(dec >= 1){
    if (dec % 2 == 0){
      dec = dec/2;
      s = s + "0";
    }
    else{
      dec = dec/2;
      s = s + "1";
    }
  }

  if (s.length() % 2 != 0){
    s = s + "0";
  }

  for(int i=s.length()-1; i>=0; i--){
    rev = rev + s[i];  
  }

  return rev;
}
string bin_to_hex(string bin){
  const int groups = bin.length()/4;
  string arr[groups];
  int count = 0;
  string hexstr="";
  
  map<string,string> table =
  {
    {"0000", "0"}, {"0001", "1"}, {"0010", "2"},
    {"0011", "3"}, {"0100", "4"}, {"0101", "5"},
    {"0110", "6"}, {"0111", "7"}, {"1000", "8"},
    {"1001", "9"}, {"1010", "A"}, {"1011", "B"},
    {"1100", "C"}, {"1101", "D"}, {"1110", "E"},
    {"1111", "F"}
  };
  
  for (int i = 0; i < bin.length(); i++){
    if (i % 4 == 0){
      // cout << bin.substr(i,4) << endl;
      arr[count] = bin.substr(i,4);
      count+=1;
    }
  }

  for (int i = 0; i < groups; i++){
    for (auto itr: table){
      if (itr.first == arr[i]){
         // cout << itr.second << endl;
         hexstr=hexstr + itr.second;
       }
    }
  }
  return hexstr;
}
int hex_to_dec(string hex){

  // Converts hex to decimal form using stoi func
  int base = 16;
  int htd = stoi(hex, 0, base);
  // cout << htd << endl;
  
  return htd;
}