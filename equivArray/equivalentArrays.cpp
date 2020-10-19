#include <iostream>
using namespace std;

bool equivalent(int a[], int b[], int size);

int main(){
  int a1[] = {1,2,3,4,5};
  int a2[] = {3,5,4,1,2};
  cout << equivalent(a1, a2, 5) << endl; //0

  int b1[] = {1,2,3};
  int b2[] = {2,3,3};
  cout << equivalent(b1, b2, 3) << endl; //0

  int c1[] = {2,3,4,1};
  int c2[] = {1,4,3,2};
  cout << equivalent(c1, c2, 4) << endl; //0

  int d1[] = {3,2,3,1};
  int d2[] = {3,1,3,2};
  cout << equivalent(d1, d2, 4) << endl; //1

  int e1[] = {1,1,1,1,2};
  int e2[] = {1,1,1,2,1};
  cout << equivalent(e1, e2, 5) << endl; //1

  int f1[] = {1,2,3,4};
  int f2[] = {4,3,1,2};
  cout << equivalent(f1, f2, 5) << endl; //0

  int g1[] = {2,3,6,1};
  int g2[] = {6,1,2,3};
  cout << equivalent(g1, g2, 4) << endl; //1

  int h1[] = {4,4,5,3,2,8,7,9,0};
  int h2[] = {8,7,9,0,4,4,5,3,2};
  cout << equivalent(h1, h2, 9) << endl; //1

  return 0; 
}

bool equivalent(int a[], int b[], int size){
  bool stillTrue;
  for (int offset = 0; offset < size; offset++){
    stillTrue = true;
    for(int i = 0; i < size; i++){
      if(b[(i + offset) % size] != a[i]){
        stillTrue = false; 
        break; 
        }
    }
    if(stillTrue){
      return true;
    }
  }
  return false;
}