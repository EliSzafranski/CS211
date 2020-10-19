#include <iostream>
#include<cmath>
using namespace std; 

int nQueens(int n);
bool okay(int q[], int col);

int main(){
    int n = 12; 
    for(int i = 1; i <= n; i++){
        cout << "There are " << nQueens(i) << " solutions to the " << i << " queens problem.\n";
    }
    return 0; 
}

bool okay(int q[], int col){
    for(int i = 0; i < col; i++){
        if(q[i] == q[col] || abs(q[col] - q[i]) == col - i) return false;
    }
    return true; 
}

int nQueens(int n){
    int* board= new int[n];
    int c = 0;
    int solutions = 0;
    board[c] = 0; 

    while(c >= 0){
        c++;
        if(c >= n){ 
            solutions++; 
            c--; 
        }
        else board[c] = -1; 

        while(c >= 0){
            board[c]++; 
            if(board[c] >= n){
                c--; 
                continue; 
            }
            if(okay(board, c)){
                break; 
            }
            else continue; 
        }    
        
    }
    delete [] board; 

    return solutions; 
}