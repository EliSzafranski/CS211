#include <iostream>
#include <cmath>
using namespace std; 

void print(int q[], int size);
bool okay(int q[], int col);

int main(){
    int c = 0; 
    int board[8]; 

    while(c >= 0){
        c++;
        if(c > 7){ 
            print(board, 8);
            c--; 
        }
        else board[c] = -1; 

        while(c >= 0){
            board[c]++; 
            if(board[c] > 7){
                c--; 
                continue; 
            }
            if(okay(board, c)){
                break; 
            }
            else continue; 
        }
    }
    return 0; 
}

bool okay(int q[], int col){
    for(int i = 0; i < col; i++){
        if(q[i] == q[col] || abs(q[col] - q[i]) == col - i) return false;
    }
    return true; 
}

void print(int q[], int size){
    static int numSolutions2 = 0; 
    cout << "Solution #" << ++numSolutions2 << ": ";
     for(int i = 0; i < size; i++){
         cout << q[i];
    } 
    cout << endl; 
    /*cout << ":" << endl; 
    for(int r = 0; r < size; r++){
        for(int c = 0;  c < size; c++){
            if(q[c] == r) cout << 1;
            else cout << "^"; 
        } 
        cout << endl;
    }
     cout << endl ;*/
}