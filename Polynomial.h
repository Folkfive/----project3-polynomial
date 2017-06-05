#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<string>
using namespace std;
class Polynomial {
public:
  static int number;// the number of stored polynomials

  //add two polynomials
  void add( string p1, string p2);

  //subtract two polynomials
  void subtract( string p1, string p2);

  void mutiple( string p1, int k);

  //get the result of an particular point
  int special( string s, int a );

  //sort the pairs according the exponent
  void sort1(string &s);

  void setName( string n);
  void setPolynomial( string s);
  void setTemp(string s);

  string getName( int i);
  string getPolynomial( int i);
  string getTemp();
  static int getNumber();

private:
  string polynomialName[20];// the name of the polynomials
  string polynomial[20]; // the makeup of the polynomials
  string temp;// store polynomial temperoly
};

#endif
