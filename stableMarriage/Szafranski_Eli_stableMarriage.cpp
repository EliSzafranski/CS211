#include <iostream>

using namespace std; 

bool ok (int q[], int col);
void print (int q[], int size);

int main(){
    int q[3];
    int c = 0; 
    q[c] = 0;
    while( c >= 0){
        c++; 
        if(c > 2){
            print(q, 3);
            c--; 
        }
        else q[c] = -1;

        while(c >= 0){
            q[c]++;
            if(q[c] > 2){
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
    static int mp[3][3] = {
        {0,2,1}, //Man 0's preference, he likes (from most to least): W0, W2, W1
        {0,2,1}, //Man 1's preference, he likes (from most to least): W0, W2, W1
        {1,2,0}  //Man 2's preference , he likes (from most to least): W2, W0, W1
    };
    static int wp[3][3] = {
        {2,1,0}, //Woman 0's preference, she likes (from most to least): M2, M1, M0
        {0,1,2}, //Woman 1's preference, she likes (from most to least): M0, M1, M2
        {2,0,1}  //Woman 2's preference, she likes (from most to least): M1, M2, M0 
    };

    //the row test, each person can only be in one marriage at a time
    for(int i = 0; i < col; i++){
        if(q[col] == q[i]) return false; 
    }

    for(int i = 0; i < col; i++){
        //if WC's rating of another man (Mi) is lower (i.e she likes him more) than her current husband (wp[q[col]][col]), 
        //&& the man she likes also likes WC more than his current partner (Wi), then the marriage is unstable
        if(wp[q[col]][i] < wp[q[col]][col] && mp[i][q[col]] < mp[i][q[i]]) return false; 

        // if MC's rating of another woman is lower than that of his current wife (i.e he likes Wi more than his current wife)
        //AND that woman likes MC more than her current husband, then the marriage is unstable 
        if(mp[col][q[i]] < mp[col][q[col]] && wp[i][col] < wp[i][i]) return false; 
    }
    return true; 
}

void print(int q[], int size) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	for(int i = 0; i < size; i++){
        cout<< i << "\t" << q[i] <<"\n"; 
    }
}
