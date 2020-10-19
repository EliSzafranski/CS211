#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> towers[3];

    int n;
    cout << "Enter the number of rings you would like to move: "; 
    cin >> n; 
    cout << endl; 

    bool even = false; 
    int from = 0, candidate = 1, to, move = 0;  
    if(n % 2 == 0){
        to = 2; 
        even = true; 
    }
    else to = 1; 
    
    // Fill the towers, and pad the bottos of each stack 
    for(int i = n + 1; i > 0; i--){
        towers[0].push_back(i);
    }
    towers[1].push_back(n+1);
    towers[2].push_back(n+1); 


    while(towers[1].size() < n+1){
        cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";
        towers[to].push_back(towers[from].back()); //add ring to the new tower
        towers[from].pop_back(); //remove the ring from old tower

        
        // The next from tower is the tower with the smallest value on it (and was not the most recent to tower)
        if(towers[(to + 1) % 3].back() <  towers[(to + 2) % 3].back()) from = ((to + 1) % 3);
        else from = ((to + 2) % 3); 

        candidate = towers[from].back(); 

        if(even){
            if(towers[from].back() < towers[(from +2) % 3].back()) to = ((from + 2) % 3);
            else to = ((from + 1) % 3);
        }
        else{
            if(towers[from].back() < towers[(from + 1) % 3].back()) to = ((from + 1) % 3);
            else to = ((from + 2) % 3); 
        }
    }
}