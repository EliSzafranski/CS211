#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
string path[NUM_ROWS][NUM_COLS];

// Calculates the cost of every square and fills in the cost matrix.
void calculateCosts() {
   static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
                                            {6,1,8,2,7,4},
                                            {5,9,3,9,9,5},
                                            {8,4,1,3,2,6},
                                            {3,7,2,8,6,4}};
   // Declare the cost matrix.
   static int cost[NUM_ROWS][NUM_COLS] = {0}; 

   // Copy the leftmost column of the weight matrix to the cost matrix, and initialize the leftmost column of the path matrix.
   for(int i = 0; i < NUM_ROWS; i++){
       cost[i][0] = weight[i][0]; 
   }

    
   // For each remaining column,
   for(int col = 1; col < NUM_COLS; col++){
       for(int row = 0; row < NUM_ROWS; row++){
           // Calculate the cost of each square in the column (non-recursively),
           int left = cost[row ][col-1];
           int down = cost[(row + 1) % NUM_ROWS][col - 1]; 
           int up = cost[(row + NUM_ROWS - 1) % NUM_ROWS][col - 1]; 

           // and store the correct number in the cost matrix and the correct string in the path matrix.
           int minCost = min(min(up, down), left); 
           
           // If up is the minimum, get the shortest path to the up-left square from the path matrix and concatenate it with the current row.
           if(up == minCost) path[row][col] = path[(row + NUM_ROWS -1) % NUM_ROWS][col-1] + to_string(row);
           // If left is the minimum...
           else if(left == minCost) path[row][col] = path[row][col-1] + to_string(row);
           // If down is the minimum...
           else if (down == minCost) path[row][col] = path[(row+1) % NUM_ROWS][col-1] + to_string(row);
           
           // Update the path matrix (store the path to the current square in path[i][j]):
           cost[row][col] = weight[row][col] + minCost; 

       }
   }
      
      


   int minRow = 0;
   int minValue = cost[0][NUM_COLS - 1];
   // Check which square in the rightmost column has the lowest cost.  Store the row number of that square in minRow.
   for(int row = 0; row < NUM_ROWS; row++){
       if(cost[row][NUM_COLS - 1] < minValue){
           minValue = cost[row][NUM_COLS - 1]; 
           minRow = row; 
       }
   }

   
   cout << "The length of the shortest path is " << cost[minRow][NUM_COLS-1];
   cout << ".\nThe rows of the path from left to right are " << path[minRow][NUM_COLS-1] << ".\n";
}

int main() {
   calculateCosts();

   return 0;
}