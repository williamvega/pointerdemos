
#include <iostream>
using namespace std;

int main() {
  int x = 25;
  int* p = &x; // read as int pointer p assigned reference to x (this reference is a memeory address)
  cout << "cout << p :" << p << endl;
  cout << "cout << *p :" << *p << endl;
  cout << "cout << &*p :" << &*p << endl;

  int* y = &x;
  int z = *y;
  cout << "cout << y:" << y << endl;
  cout << "cout << z:" << z << endl;

  int a = 5;
  int* b = &a;
  *b = 10;
  cout << a << endl; // this should be 10
}
