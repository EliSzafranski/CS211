#include <iostream>
#include <cmath>
using namespace std; 

bool ok(int q[], int c, int n){
    for(int i = 0; i < c; i++){
        if((q[c] / n) - (q[i] / n) == abs((q[c] % n) - (q[i] % n)))
            return false;  
    }
    return true;
}

int kBishops(int n, int k){
    int*  board = new int[k];
    int box = 0;
    int solutions = 0;
    board[box] = 0; 

    while(box >= 0){
        box++;

        if(box >= k){ 
            solutions++; 
            box--; 
        }
        else board[box] = board[box-1]; 

        while(box >= 0){
            board[box]++; 
            if(board[box] >= (n*n)){
                box--; 
                continue; 
            }
            if(ok(board, box, n)){
                break; 
            }
            else continue; 
        }    
    }
    delete [] board; 

    return solutions; 
}



int main(){
    for(int size = 1; size <= 8; size++){
        for(int bish = 1; bish <= size; bish++){
            cout << "For the " << bish << " bishop problem on a " << size << " by " << size << " board there are " << kBishops(size, bish) << " soluions.\n";
        }
    }
    return 0; 
}
