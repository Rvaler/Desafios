#include <iostream>

using namespace std;

#define MAX_SQUARE 100

int main(){

	int numTests;
	cin >> numTests;

	for(int i = 0; i < numTests; i++) {

		long numPlayers, numTunnels, numRolls;
		cin >> numPlayers >> numTunnels >> numRolls;

		int tunnels[numTunnels][2];
		int playersPos[numPlayers];

		// initialize players position
		for (int k = 0; k < numPlayers; k++) {
			playersPos[k] = 1;
		}
		// initialize tunnels values
		for (int k = 0; k < numTunnels; k++) {
			cin >> tunnels[k][0];
			cin >> tunnels[k][1];
		}

		int gameOver = 0;
		for(int j = 0; j < numRolls; j++) {
			int diceValue;
			cin >> diceValue;
			if(!gameOver) {

				playersPos[j % numPlayers] += diceValue;
				for (int k = 0; k < numTunnels; k++) {
					if(playersPos[j % numPlayers] == tunnels[k][0]){
						playersPos[j % numPlayers] = tunnels[k][1];
					}		
				}
				if(playersPos[j % numPlayers] >= MAX_SQUARE) {
					playersPos[j % numPlayers] = MAX_SQUARE;
					gameOver = 1;
				}	
			}
		}

		for(int p = 0; p < numPlayers; p++) {
			cout << "Position of player " << (p % numPlayers) + 1 << " is " << playersPos[p % numPlayers] << "." << endl;
		}
	}
	
	return 0;
}