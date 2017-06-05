#include<string>
#include<iomanip>
#include<cmath>
#include"System.cpp"

using namespace std;

int main() {
  System xxx; //create a system class
  while( xxx.a ) {
    xxx.print_mainMenu();//print main menu
    xxx.print_inputOrder(); // print function list
    string order;
    cin >> order; //read the order
    int order1 = xxx.judge_order( order ); // judge the order
    if( order1 < 8 ) xxx.callFunction( order1);
    else xxx.print_errorInput();
  }
  xxx.print_end();
  return 0;
}
