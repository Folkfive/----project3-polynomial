#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include"Polynomial.h"
using namespace std;

#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include"Polynomial.h"
using namespace std;

int Polynomial::number = 0;

void Polynomial::add( string p1, string p2) {
    temp.clear();//clear the temp
    int n1 = p1.size() / 2;
    int n2 = p2.size() / 2;
    temp = string(p1);
    for( int i = 0; i < n2; ++i) {
        int x = 1;
        for( int j = 0; j < n1; ++j) {
            if( p2[2*i+1] == p1[2*j+1] ) {
                temp[2*j] =  temp[2*j] - '0' +  p2[2*i];//change string to int
                x = 0;
            }
        }
        if(x) {
            temp += p2[2*i];
            temp += p2[2*i+1];
        }
    }
    sort1(temp);
}

//subtract two polynomials
void Polynomial::subtract( string p1, string p2) {
    int n1 = p1.size() / 2;
    int n2 = p2.size() / 2;
    temp = string(p1);
    for( int i = 0; i < n2; ++i) {
          int x = 1;// to judge whether the ratios are equal.
          for( int j = 0; j < n1; ++j) {
              if( p2[2*i+1] == p1[2*j+1] ) {
                  temp[2*j] =  temp[2*j] - p2[2*i] + '0';
                  x = 0;
              }
          }
          if(x) {
              temp += p2[2*i];
              temp += p2[2*i+1];
          }
      }
    sort1(temp);
  }

void Polynomial::mutiple( string p1, int k) {
  int n = p1.size() / 2;
  for( int i = 0; i < n; ++i) {
      temp += (p1[2*i] - '0') * k + '0';
      temp += p1[2*i+1];
  }
}

//get the result of an particular point
int Polynomial::special( string s, int a ) {
    int size = s.size() / 2;
    int sum = 0;
    for( int i = 0; i < size; ++i) {
        sum += (s[2*i] - '0') * pow(a, s[2*i+1] -'0' );
    }
    return sum;
  }

//sort the pairs according the exponent
void Polynomial::sort1(string &s) {
  string str1;
  string k, // ratio
         z; // exponent
  int n = s.size() / 2;
  for( int i = 0; i < n; ++i) {
      string temp;
      temp = s[2*i];
      k[i] = temp[0] ;
      temp = s[2*i+1];
      z[i] = temp[0] ;
  }
  for( int i = 0; i < n; ++i) {
      for( int j = 0; j < n - i - 1; ++j) {
          if( z[j] < z[ j+1 ]) {
              int temp = z[j];
              z[j] = z[j+1];
              z[j+1] = temp;
              temp = k[j];
              k[j] = k[j+1];
              k[j+1] = temp;
          }
      }
  }
  s.clear();
  for( int i = 0; i < n; ++i) {
    s += (k[i]);
    s += (z[i]);
  }
}



void Polynomial::setName( string n) { polynomialName[number] = n;}
void Polynomial::setPolynomial( string s) { polynomial[number] = s;}
void Polynomial::setTemp(string s) { temp = s;}

string Polynomial::getName( int i) { return polynomialName[i];}
string Polynomial::getPolynomial( int i) { return polynomial[i];}
string Polynomial::getTemp() { return temp;}
 int Polynomial::getNumber() {return number;}
