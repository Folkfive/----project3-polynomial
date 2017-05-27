````
#include<iostream>
#include<string>
using namespace std;

class Polynomial {
public:
  string add( string p1, string p2) { return p1; }
  string subtract( string p1, string p2) { return p1;}
  string mutiple( string p1, double k) { return p1;}
  //get the result of an particular point
  string special( double a ) { return 0; }
  void store( string name, string p1 ) {}

  void setName( string name) {}
  void setPolynamial( string polynomial) {}
  void setTemp( string polynomial ) {}

  string getName() {}
  string getPolynomial() {}
  string getTemp() {}
  static int getNumber() {return number;}

static int number;// the number of stored polynomials

private:
  string polynomialName[20];// the name of the polynomials
  string polynomial[20]; // the makeup of the polynomials
  string temp;// store polynomial temperoly
};

static int number = 0;

class System{
public:
  int a = 1;
  void print_mainMenu(void){
      cout << left << "1.Enter a polynomial" << "2.Additon"<< endl;
      }
  void print_inputOrder() { cout << "please input" << endl;}
  void print_inputPolynomial() {}
  void print_errorInput( void ) {cout << "erroe" << endl;}
  void save( void ) {
    string order_save;
  cin << order_save;
  int judge_save1 = judge_save( order_save);
  if( judge_save1 ) { ... }
}
  void print_result( string a ) { cout << "result";}
  void print_function() { }
  void print_end() { cout << "thanks\n";}

  bool judge_save( string s) { return }
  int judge_order( string s ) { return 0; }
  bool judge_input( string s ) { return true; }

  void callFunction( int a) {
    switch (a) {
    //退出
    case 0: quit(); break;
    //输入多项式
    case 1:{
      print_inputPolynomial();//给出输入多项式指令
      string a;
      cin >> a;
      int judge_a = judge_input();
      //输入正确
      if(judge_a){...}
      else {
        ...
      }
    }

    //加法
    case 2: {
      print_inputPolynomial(); //给出输入多项式指令
              string a;
              cin >> a;
              if(是代号的话){ ...}
              else{
                int judge_a = judge_input( a );
                //多项式输入正确，读入第二个多项式
                if(judge_a) {
                  string b;
                  print_inputPolynomial(); //输入第二个多项式
                  cin >> b;
                  if(是代号的话) {。。。}
                  else {
                    int judge_b = judge_input( b );
                    //输入正确，进行加法
                    if( judge_b ) {
                      yyy.add( a, b);
                      save();
                    }
                    //输入错误，退出。
                    else {
                      print_errorInput();
                      break;
                    }
                  }

                }
                //多项式输入错误
                else {
                  print_errorInput();
                  break;
                }
            }


    }
    //减法
    case 3:{
      print_inputPolynomial(); //给出输入多项式指令
              string a;
              cin >> a;
              if(是代号的话){ ...}
              else{
                int judge_a = judge_input( a );
                //多项式输入正确，读入第二个多项式
                if(judge_a) {
                  string b;
                  print_inputPolynomial(); //输入第二个多项式
                  cin >> b;
                  if(是代号的话) {。。。}
                  else {
                    int judge_b = judge_input( b );
                    //输入正确，进行减法
                    if( judge_b ) {
                      yyy.subtract( a, b);
                      save();
                    }
                    //输入错误，退出。
                    else {
                      print_errorInput();
                      break;
                    }
                  }

                }
                //多项式输入错误
                else {
                  print_errorInput();
                  break;
                }
            }


    }
    //常数乘法
    case 4:{
      print_inputPolynomial(); //给出输入多项式指令
              string a;
              cin >> a;
              if(是代号的话){ ...}
              else {
                int judge_a = judge_input( a );
                //输入正确，进行乘法
                if( judge_a ) {
                  cout << "please input a const\n";
                  double b;
                  cin >> b;
                  mutiple( a, b);
                  save();//询问是否保存

                }
                //输入错误，退出
                else {
                  print_errorInput();
                  break;
                }
              }
    }
    //特定点的值
    case 5:{
      cout << "please input a const\n";
      double a;
      cin >> a;
      print_input();
      string b;
      cin >> b;
      //是代号
      if(daihao) {...}
      //不是代号
      else {
        int judge = judge_input(b);
        //格式正确
        if( judge ) {

        }
        格式错误
        else {

        }
      }

    }
    //显示所有的多项式
    case 6:{

    }
    //帮助列表
    case 9:{

    }
}

  void quit() { a = 0;}
private:
  Polynomial yyy;
};


int main() {
  System xxx;
  while( xxx.a ) {
    xxx.print_mainMenu();
    xxx.print_input();
    string order;
    cin >> order;
    int order1 = xxx.judge_order( order );
    if( order1 > 9 ) xxx.callFunction( order1);
    else xxx.print_errorInput();
  }
  xxx.print_end();
  return 0;

}
``````
