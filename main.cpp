#include <iostream>
#include <iomanip>

using namespace std;


//Simple random number generator

unsigned long randState = 12345; //Can be any value
unsigned long nextRandom(){
  randState = randState* 1103515245 + 12345;
  return(randState / 65536) % 32768; // returns a random number between 0 and 32767

}


//Function to simulate a single run of the monty hall paradox
bool montyHall(bool switchChoice){
  //randomly assignes the car to one of the 3 doors
  int carPos = nextRandom() % 3;
  int userChoice = nextRandom() % 3; //user will randomly select a door

  //host will reveal a goat which won't be the car or the user choice!!
  int hostReveal = -1;
  for (int i = 0; i < 3; i++){
    if(i != userChoice && i != carPos){
      hostReveal = i;
      break;
    }
  }

  //if the user switch to another door they have to pick the other remaining door
  int userFinalChoice = userChoice;
  if(switchChoice){
    //the user switches to the remaining unopened door
    for(int i =0; i < 3; i++)
      if(i != userChoice && i != hostReveal){
	userFinalChoice = i;
	break;
      }
  }
  return userFinalChoice == carPos;

}


//function to simulate the trials of the monty hall paradox
void sim( int numIterations, bool switchChoice){
  int wins = 0;
  int losses = 0;

  for (int i = 0; i < numIterations; i++){
    if(montyHall (switchChoice)){
      wins++;
    } else{
      losses++;
    }
  }
  //output the results

  double winProb = static_cast<double>(wins) / numIterations * 100;
  cout << "Total Runs: " << numIterations << endl;
  cout << "Times Won: " << wins << endl;
  cout << "Times Loss; " << losses << endl;
  cout << "Win Percentage: " << fixed << setprecision(2) << winProb << "%" << endl;

}

int main(){
  char userChoice;
  int numIterations;
  cout << "Welcome to the Monty Hall Paradox Paradox Dr. Wang!" << endl;
  cout << "Would you like to stay or switch doors? (s for stay, t for switch) ";
  cin >> userChoice;

  bool switchChoice = (userChoice == 't' || userChoice == 'T');

  cout <<"Enter the number of iterations to simulate: ";
  cin >> numIterations;

  sim(numIterations, switchChoice);
  return 0;
}
