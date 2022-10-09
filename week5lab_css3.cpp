#include<iostream>
using namespace std;
 
int main() 
{
  int bin_int[7], check[3], p1, p2, p4; 
  int error = 0;
  string bin, b;
  cout << "Enter a binary value to check for error: ";
  cin >> bin;
  cout << endl;

  // Store into array to manipulate
  for (int i = 0; i < 7; i++){
    b = bin[i];
    int num = stoi(b);
    bin_int[i] = num;
  }

  // Check if each parity checker is even/odd
  p1 = (bin_int[0] + bin_int[2] + bin_int[4] + bin_int[6])%2;
  p2 = (bin_int[1] + bin_int[2] + bin_int[5] + bin_int[6])%2;
  p4 = (bin_int[3] + bin_int[4] + bin_int[5] + bin_int[6])%2;

  // Assign checkers to check array
  check[0] = p1;
  check[1] = p2;
  check[2] = p4;
  
  // Check for error
  for(int i = 0; i < 3; i++){
    if (check[i] == 1){
      if (i == 2){
        error = error + (i + 2);
      }
      else{
        error = error + (i + 1);
      }
    }
  }

  // If no error
  if (error == 0){
    cout << "Your code is correct. The number sent was: ";
    cout << (bin_int[2]*8 + bin_int[4]*4 + bin_int[5]*2 + bin_int[6]*1);
  }
  else{ // If error exists
    cout << "Your code has an error at bit: "<< error << endl;
    cout << "The corrected code is: ";

    // Replace error bit
    if (bin_int[error-1] == 0){
      bin_int[error-1] = 1;
    }
    else{
      bin_int[error-1] = 0;
    }

    // Print new corrected bin
    for(int i = 0; i < 7; i++){
      cout << bin_int[i];
    }
    
    // Decimal num with bin multiply
    cout << "\nThe decimal number sent was: ";
    cout << (bin_int[6] + bin_int[5]*2 
      + bin_int[4]*4 + bin_int[2]*8) << endl;
  }
  return 0;
}