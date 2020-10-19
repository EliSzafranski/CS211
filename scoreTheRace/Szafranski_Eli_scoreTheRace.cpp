#include <iostream>
using namespace std; 
bool allEqual(int a[], int size);

int main(){
  while(true){
    string runners; 
    cout << "Enter the race outcome: ";
    cin >> runners; 

    if(runners == "done" || runners == "Done") return 0; 
   
    int numRunners = 0;
    int numTeams = 0; 
    double totalScore[26] = {};
    int numPlayers[26] = {};

    
    //parses the string for information
    for(int i = 0; i < runners.length(); i++){
        int index = runners[i] - 65; //changes the letter to an index number

        if(numPlayers[index] == 0) numTeams++; 

        numPlayers[index]++; // increments the total number of players per team

        totalScore[index]+= (i + 1); //totals the score of each team by adding (index + 1)
    }

    //ensures all teams are equal
    if(allEqual(numPlayers, 26) == false){
      cout << "The teams don't have the same number of runners.\n";
      continue; 
    }

   
    for(int i = 0; i < 26; i++){
        if(numPlayers[i] != 0){
            numRunners = numPlayers[i];
            break;
        } 
    }

    cout << "There are " << numTeams << " teams.\n";
    cout << "Each team has " << numRunners << " runners.\n";

    double newScores[26] = {}; //holds the scores of only the participating teams
    int bestTeam[26] = {}; //holds all letters in integer form of only the participating teams
    int count = 0; 
    for (int i = 0; i < 26; i++){ 
      if(totalScore[i] != 0){
        cout << char(i + 65) << ": " << totalScore[i]/numPlayers[i] << endl;  //Prints out score and letter of the participating team
        newScores[count] = totalScore[i]/numPlayers[i]; //records the total score of the teams that competed 
        bestTeam[count] = i; //takes in the letters of the teams that competed; the indexes coresopond the score of the other array
        count++; 
      } 
    }

    double lowestScore = newScores[0];
    char winner = char(bestTeam[0]+65);

    //iterates through the new arrays to find the lowest score, and which team has the lowest score
    for(int i = 0; i < count -1; i++){ 
      if(newScores[i+1] < lowestScore){
        lowestScore = newScores[i+1];
        winner = char(bestTeam[i+1] + 'A'); 
      }
    }
    cout << "The winning team is team " << winner << " with a score of " << lowestScore << ".\n";
  }
  return 0; 
}

//checks how many runners are on each team, and ensures they are all equal 
bool allEqual(int a[], int size){
  int newArray[26] = {};
  int count = 0; 
  for (int i = 0; i < size; i++){
    if(a[i] != 0){
     newArray[count] = a[i];
     count++;
    }
  }
  for(int i = 0; i < count - 1; i++){
    if(newArray[i] != newArray[i + 1]) return false; 
  }
  return true; 
}