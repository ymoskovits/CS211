/*******************************
* Name: Julian Moskovits
* Description: Takes input in the form of a string representing the order in which members of a team finish a race.
*	For example: ABBAAB represents the case when 3 runners on team A came in 1st, 4th, and 5th place.
*	The team's score is the average of its members' finishing positions.
*	The program outputs the results of the race.
*******************************/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int play();

int minElement(int []);

void consoleStats(int [], float);

int numberOfTeams(int []);

bool evenTeams(int []);

int main()
{
	while(true){
		switch (play()){
			case 0:
				break;
			case -1:
				cout << "Not valid input, try again." << endl;
				break;
			case -2:
				cout << "You entered results with uneven teams, try again." << endl;
				break;
			case -3:
				return 0;
		}
	}
}

int play(){
	int teams[91] = {0};										//This array will hold the scores of each team(letter).
	string results;
	int counter[91] = {0};										//This array will hold the number of players on each team.
	char validNames[91] = {0};
	
	cout << "Please enter the results (type \"done\" to exit): ";
	cin >> results;

	if (results == "done"){
		return -3;
	}
	
	for (int i = 0; i < results.length(); ++i){
		if (results[i] < 'A' || results[i] > 'Z'){
			return -1;									//This is an error when an invalid character was part of the string.
		}
		teams[results[i]] += i + 1;								//The total points are entered into the elements for each team. PRE DIVISION!!!	
		counter[results[i]]++;									
	}


	if (evenTeams(counter) == 0){
		return -2;										//This is an error when teams have uneven numbers of runners.
	}

	//for (int i = 65; i <= 90; ++i){
	//	cout << (char)i << ".\t" << teams[i] << "\t" << counter[i] << endl;
	//}
	int numOfTeams = numberOfTeams(counter);
	int menPerTeam = results.length() / numOfTeams;

	cout << "There are " << numOfTeams << " teams in the race." << endl;
	cout << "There are " << menPerTeam << " runners on each team." << endl;

	consoleStats(teams, menPerTeam);								//Uses this function to log the existing teams and their divided scores.

	char winner = minElement(teams);

	float winScore = teams[winner] / (float)menPerTeam;

	cout << "The winning team is team " << winner << ", with a score of " << winScore << "." << endl;

		return 0;
}



int numberOfTeams(int x[]){
	int count = 0;
	for (int i = 65; i < 91; ++i){
		if (x[i] > 0){
			count++;
		}
	}
		return count;
}



bool evenTeams(int x[]){
	int expected = 0;
	for (int i = 65; i < 91; ++i){									//This loop finds the first existing team and records the num of players.
		if (x[i] == 0){
			continue;
		}
		if (x[i] > 0){
			expected = x[i];
			break;
		}
	}

	for (int i = 65; i < 91; ++i){									//This loop confirms whetehr all existing teams have the same number of players.
		if (x[i] == 0 || x[i] == expected){
			continue;
		}
		else{
			return false;
		}
	}
		return true;
}



void consoleStats(int getScores[], float players){
	cout << "Team \t Score" << endl;
	
	for (int i = 65; i < 91; ++i){
		if (getScores[i] > 0){
			cout << (char)i << "\t" << getScores[i] / players << endl;
		}
	}
}



int minElement(int x[]){
	int low = 0;
	for (int i = 65; i < 91; ++i){
		if (x[i] > 0){
			low = i;
			break;
		}
	}
	
	for (int i = 65; i < 91; ++i){
		if (x[i] > 0){
			if (x[i] < x[low]){
				low = i;
			}
		}
	}
	
	return low;
}
