#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
string path[NUM_ROWS][NUM_COLS];

// Returns the cost of the shortest path from the left to the square in row i, column j.
int calculateCost(int i, int j) {
   static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
                                            {6,1,8,2,7,4},
                                            {5,9,3,9,9,5},
                                            {8,4,1,3,2,6},
                                            {3,7,2,8,6,4}};
   // Declare the cost matrix.
   static int cost[NUM_ROWS][NUM_COLS] = {0}; 

   // If the cost has already been calculated, return it. (esseitally like a base case)
   if(cost[i][j] != 0) return cost[i][j]; 
   // Check for the base case. 
   // If we are in the first column (column 0), then we return that value
   if (j == 0) {
      path[i][j] = to_string(i);
      return weight[i][j];
   }
   
   // Calculate the costs of the 3 adjacent squares by calling the function recursively.
   int up = calculateCost((i+ NUM_ROWS - 1) % NUM_ROWS, j-1); 
   int left = calculateCost(i, j-1); 
   int down = calculateCost((i+1) % NUM_ROWS, j-1);

   // Find the minimum of the 3 costs.
   int minCost = min(min(up, left), down); 

   // Update the path matrix (store the path to the current square in path[i][j]):
   // If up is the minimum, get the shortest path to the up-left square from the path matrix and concatenate it with the current row.
   if(up == minCost) path[i][j] = path[(i + NUM_ROWS -1) % NUM_ROWS][j-1] + to_string(i);
   // If left is the minimum...
   else if(left == minCost) path[i][j] = path[i][j-1] + to_string(i);
   // If down is the minimum...
   else if (down == minCost) path[i][j] = path[(i+1) % NUM_ROWS][j-1] + to_string(i); 

   // Calculate the cost of the current square, store the correct number in the cost matrix, and return the cost.
   cost[i][j] = weight[i][j] + minCost; 
   return cost[i][j]; 
}


int main() {
   int minRow = 0;
   int minValue = calculateCost(0, NUM_COLS-1); 
   // Call the calculateCost function once for each square in the rightmost column of the grid.
   // Check which one has the lowest cost and store the row number in minRow.
   for(int i = 0; i < NUM_ROWS; i++){
       int tempMin = calculateCost(i, NUM_COLS-1);
       if (tempMin < minValue){
           minValue = tempMin; 
           minRow = i;  
       }
   }
   cout << "The length of the shortest path is " << calculateCost(minRow, NUM_COLS-1);
   cout << ".\nThe rows of the path from left to right are " << path[minRow][NUM_COLS-1] << ".\n";

   return 0;
}