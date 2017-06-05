#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include"System.h"
#include"Polynomial.cpp"
using namespace std;

int System::a = 1;

void System::print_mainMenu(void){
    cout << left << setw(30) << "1.enter a polynomial" << "2.Addition\n";
    cout << setw(30) << "3.Subtraction" << "4.Multiply\n";
    cout << setw(30) << "5.Add an particular point" << setw(15) << "6.Show all polynomials\n";
    cout <<setw(30) << "7.Help" << "0.Quit\n";
}

void System::print_inputOrder() { cout << "Please input an order" << endl;}
void System::print_inputPolynomial() {cout << "Please input a polynomial\n";}
void System::print_errorInput( void ) {cout << "Error!\n" << endl;}

//print the proper form of the polynomial
void System::print_result( string a ) {
    cout << "Result: ";
    int n = a.size();
    for( int i = 0; i < n/2; ++i) {
       cout << a[2*i];
       if(a[2*i+1] != '0') {
          cout << "x" << "^" << a[2*i+1];
       }
       if( i != n/2 -1) cout << "+";
    }
    cout << endl;
  }

void System::print_help() {
     cout << "Enter a polynomial:\n";
     cout << left << setw(50)<<"You can enter a polynomial, the input must be like '(2,1)(3,4)'. Any other inputs are forbidden.\n";
     cout << setw(50) << "You are allowed to name your polynomial. Thus you can use a simple name to represent a polynomial.\n";
     cout << "The other functions keep the similar rules.\n";
     cout << "I would be happy if it is of any help.\n";
     cout << "Thanks.\n";
     }

void System::print_all() {
  for( int i = 0; i < yyy.getNumber(); ++i) {
      cout << left << setw(10) << i << setw(10) << yyy.getName(i);
      print_result(yyy.getPolynomial(i));
      cout << "\n";
  }
}
void System::print_end() { cout << "Thanks for using.\n";}
void System::print_save() { cout << "Do you want to save? Enter y/n.\n";}
void System::print_enterName() { cout << "Enter a name for your polynomial\n";}
void System::print_success() { cout << "Successful!\n";}

//judge whether to save
bool System::judge_save( string s) {
    if(s[0] == 'y') return true;
    else return false;
    }

//save the special form polynomial like p = (1,2)
bool System::special_save( string s ) {
  int i = 0;
  string p;
  string name;
  while(s[i] != '=') {
    name += s[i];
    ++i;
  }
  for( int j = i+1; j < s.size(); ++j ) {
    p += s[j];
  }
  bool judge = judge_input(p);//judge the form
  if( judge) {
    Sort(p);
    save(p, name);
    return true;
  }
  else return false;
}

// judge the order, if the order is right, return coresponding number
int System::judge_order( string s ) {
    if( isdigit(s[0])) return s[0] - '0';
    else return 10;
}

//judge the form of the polynomial
bool System::judge_input( string s ) {
    if(s[0] != '(') {
          for( int i = 0; i < yyy.number; ++i) {
              if( s == yyy.getName(i) ) return true;
          }
          return false;
    }
    else {
      int size = s.size();
      if( size % 5 == 0 ){
          for( int i = 0; i < size/5; ++i) {
              if(s[5*i] != '(') return false;
              if(!isdigit(s[5*i+1])) return false;
              if(s[5*i + 2] != ',') return false;
              if( !isdigit(s[5*i+3]) ) return false;
              if(s[5*i+4] != ')') return false;
          }
     }
     else return false;
    }
  }

  //save the polynomial
void System::save( string s, string name ) {
      yyy.setPolynomial( s);
      yyy.setName(name);
      ++yyy.number;
}

//change the form "(1,2)" into "12"
void System::input_Change( string &s) {
  for( int i = 0; i < yyy.number; ++i) {
      if( s == yyy.getName(i) ) s = yyy.getPolynomial(i);
  }
}

//according to different orders calling coresponding functions.
void System::callFunction( int a) {
  switch (a) {
  //quit the program
  case 0: quit(); break;

  //input polynomials and save them
  case 1:{
    print_inputPolynomial();//?????????
    string a;
    cin >> a;
    if( a[0] != '(') {
        if( !special_save(a)) {
            print_errorInput();
            break;
        }
        else print_success();
    }
    else  {
      bool x = judge_input(a);
      if( x ) {
          print_save();
          string a1;
          cin >> a1;
          bool a2 = judge_save(a1);
          if( a2 ) {
              string name;
              print_enterName();
              cin >> name;
              Sort(a);
              save(a, name);
              print_success();
          }
      }
    }
  }
  break;

  //Addition
  case 2: {
    print_inputPolynomial();
            string a;
            cin >> a; // read the first polynomial
            bool a1 = judge_input(a); //judge the form
            if(a1) {
              if(a[0] != '(') input_Change(a);
              print_inputPolynomial();
              string a2;
              cin >> a2; // read the second polynomial
              bool a3 = judge_input(a2); // judge the the form
              if(a3) {
                  if( a2[0] != '(' ) input_Change(a2);
              }
              else {
                  print_errorInput();
                  break;
              }
              //Sort(a);
              //Sort(a2);
              yyy.add(a, a2);
              print_result(yyy.getTemp());
              print_save();//ask whether to save
              string b;
              cin >> b;
              bool b1 = judge_save(b);
              if( b1 ) {
                  print_enterName();
                  string name;
                  cin >> name;
                  save(yyy.getTemp(), name);
              }
            }
            else {
              print_errorInput();
              break;
            }
  break;
  }

  //Subtraction
   case 3: {
    print_inputPolynomial();
            string a;
            cin >> a; //read the first polynomial
            bool a1 = judge_input(a); //judge the form
            if(a1) {
              if(a[0] != '(') input_Change(a);
              print_inputPolynomial();
              string a2;
              cin >> a2; // read the second polynomial
              bool a3 = judge_input(a2); //judge the form
              if(a3) {
                  if( a2[0] != '(' ) input_Change(a2);
              }
              else {
                  print_errorInput();
                  break;
              }
              //Sort(a);
              //Sort(a2);
              yyy.subtract(a, a2);
              print_result(yyy.getTemp());
              print_save();
              string b;
              cin >> b;
              bool b1 = judge_save(b);
              if( b1 ) {
                  print_enterName();
                  string name;
                  cin >> name;
                  save(yyy.getTemp(), name);
              }
            }
            else {
              print_errorInput();
              break;
            }
  break;
  }

  // mutiplication
  case 4:{
      print_inputPolynomial();
      string p1;
      cin >> p1; //read the polynomial
      bool judgeP1 = judge_input(p1); // judge the form
      if(judgeP1) {
          if( p1[0] != '(') input_Change(p1);
          cout << "Please enter a number\n";
          int n;
          cin >> n; // read the number
          Sort(p1);
          yyy.mutiple(p1, n); // calculate
          print_result(yyy.getTemp()); // print the result
          print_success();
          print_save();
          string orderSave;
          cin >> orderSave;
          bool judgeOrderSave = judge_save(orderSave);
          if( judgeOrderSave) {
              print_enterName();
              string name;
              cin >> name;
              save(yyy.getTemp(), name);
              print_success();
          }
      }
      else {
          print_errorInput();
          break;
      }
  break;
  }

  // calculate a particular point
   case 5:{
      print_inputPolynomial();
      string p1;
      cin >> p1; //read the polynomial
      bool judgeP1 = judge_input(p1); //judge the form
      if(judgeP1) {
          if( p1[0] != '(') input_Change(p1);
          cout << "Please enter a number\n";
          int n;
          cin >> n;//read the number
          Sort(p1);
          int result = yyy.special(p1, n);
          cout << "The result is " << result << endl;
      }
      else {
          print_errorInput();
          break;
      }
    break;
    }

    //print all the stored polynomials
    case 6:{
      print_all();
    break;
    }

    //print help list
    case 7:{
      print_help();
    break;
    }
  }
}

void System::quit() { a = 0;}

//sort the input polynomials
void System::Sort(string &s) {
  string str1;
  string k, //ratio
         z; // exponent
  int n = s.size() / 5;
  for( int i = 0; i < n; ++i) {
        string temp;
        temp = s[5*i +1];
        k[i] = temp[0] ;
        temp = s[5*i+3];
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
