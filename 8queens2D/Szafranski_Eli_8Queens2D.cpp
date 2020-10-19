#include <iostream>
using namespace std; 

int main() {
  int queen[8][8] = {0}; 
  int r = 0, c = 0; 
  queen[r][c] = 1;
  

  nextCol: 
    c++;
    if(c > 7) goto print; 
    r = -1; 
  
  nextRow:
    r++;  
    
    if(r > 7) goto backtrack; 

    for(int i = 0; i < c; i++){
      if(queen[r][i] == 1) goto nextRow; 
    }
    for(int i = 1; i <= r && i <= c; i++){
      if(queen[r-i][c-i] == 1){
        goto nextRow; 
      }
    }
    for(int i = 1; i <= c && i + r < 8; i++){
      if(queen[r+i][c-i] == 1){
        goto nextRow;
      }
    }
    queen[r][c] = 1;
    goto nextCol;

  backtrack:
    c--;
    if (c == -1) return 0;
    for(int i = 0; i < 8; i++){
      if(queen[i][c] == 1){
        queen[i][c] = 0;
        r = i;
        goto nextRow; 
      }
    }
     

  print:
    static int numSolutions = 0; 
    cout << "Solution number: " << ++numSolutions << endl; 
    for(int i = 0; i < 8; i++){
      for(int x = 0; x < 8; x++){
        cout << queen[i][x]; 
      }
      cout << endl; 
    } 
    cout << endl; 
    goto backtrack; 
}