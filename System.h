#ifndef SYSTEM_H
#define SYSTEM_H
#include<string>
#include"Polynomial.h"

using namespace std;

class System{
public:
  static int a; // if a = 0, the program will be finished.
  void print_mainMenu(void);
  void print_inputOrder();
  void print_inputPolynomial();
  void print_errorInput( void );
  //print the proper form of the polynomial
  void print_result( string a ) ;

  void print_help() ;
  void print_all() ;
  void print_end() ;
  void print_save() ;
  void print_enterName() ;
  void print_success() ;

  //judge whether to save
  bool judge_save( string s) ;

  //save the special form polynomial like p = (1,2)
  bool special_save( string s );

  // judge the order, if the order is right, return coresponding number
  int judge_order( string s ) ;

  //judge the form of the polynomial
  bool judge_input( string s ) ;

    //save the polynomial
  void save( string s, string name ) ;
  //change the form "(1,2)" into "12"
  void input_Change( string &s) ;

  //according to different orders calling coresponding functions.
  void callFunction( int a) ;
  void quit();

//sort the input polynomials
  void Sort(string &s) ;
private:
  Polynomial yyy;
};

#endif


