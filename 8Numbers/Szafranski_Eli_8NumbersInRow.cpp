#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int col);
void print (int q[], int size);

int main(){
    int q[8];
    int c = 0; 
    q[c] = 1;

    while(c >= 0){
        c++; 
        if(c > 7){
            print(q, 8);
            c--;
        }
        else q[c] = 0; 

        while(c >= 0){
            q[c]++;
            if(q[c] > 8){
                c--;
                continue;
            }
            if(ok(q, c)) break; 
            else continue; 
        }
    }
    return 0; 
}

bool ok(int q[], int col){
    static int checkList[8][5] = {
		{-1},
		{0,-1},
		{1,-1},
		{0,1,2,-1},
		{1,2,3,-1},
		{2,4,-1},
		{0,3,4,-1},
		{3,4,5,6,-1},
	};
    for(int i = 0; i < col; i++){
        if(q[i] == q[col]) return false;
    }
    int i = 0; 
    while(checkList[col][i] != -1){
        if(abs(q[checkList[col][i]] - q[col]) == 1) return false; 
        i++;
    }
    return true;
}

void print(int cross[], int cap) {
	static int count = 0;
	cout << " Soultion number: " << ++count << endl;
	cout << " " << cross[1] << cross[2] << endl;
	cout << cross[0] << cross[3] << cross[4] << cross[5] << endl;
	cout << " " << cross[6] << cross[7] << endl;
	return;
}


