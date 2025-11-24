#include<iostream>
using namespace std;

//Hollow Square Pattern

/*

*****
*   *
*   *
*   *
*****

*/ 

class Solution {
public:
  void printHollowSquare(int n) {
    // Implement the pattern printing logic here
    for (int row = 1; row <= n; row++) {
      if (row == 1 || row == n) {
        for (int colm = 1; colm <= n; colm++) {
          cout << "* ";
        }
      }
      else{
      cout << "* ";
      for (int colm = 1; colm <= (n - 2);colm++) {
        cout << "  ";
      }
      cout << "* ";
      }
      cout<<endl;
    }
 
  }
};