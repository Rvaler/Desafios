#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector< vector<int> > newMaze;
vector< vector<int> > visitsMaze;

int robotLinePosition;
int robotColPosition;
char currentDirection; // E - east, W - west, N - north, S - south

int mazeHeight, mazeWidth;


int charToInt(char a) {
	return a - '0';
}

void printMaze() {
	for(int a = 0; a < mazeHeight + 2; a++){
		for(int b = 0; b < mazeWidth + 2; b++){
			cout << newMaze[a][b] << " " ;
		}
		cout << endl;
	}
}

void printVisitsResult(){
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for(int k = 0; k < mazeHeight; k++){
		for(int l = 0; l < mazeWidth; l++){
			if(newMaze[k+1][l+1] != 1){
				switch (visitsMaze[k][l]){
				case 0:
					a++;
					break;
				case 1:
					b++;
					break;
				case 2:
					c++;
					break;
				case 3:
					d++;
					break;
				case 4:
					e++;
					break;
				}
			}
		}
	}
	// cout << "RESULTADOS: " << a << " " << b << " " << c << " " << d << " " << e << endl;
	cout << setfill(' ') << setw(3) << a;
    cout << setfill(' ') << setw(3) << b;
    cout << setfill(' ') << setw(3) << c;
    cout << setfill(' ') << setw(3) << d;
    cout << setfill(' ') << setw(3) << e << endl;
}

void walkRobot(char currentDirection){
	// cout << "andou na direcao " << currentDirection << endl;

	visitsMaze[robotLinePosition - 1][robotColPosition - 1]++;
	switch (currentDirection){
		case 'E':
			robotColPosition++;
			break;
		case 'W':
			robotColPosition--;
			break;
		case 'N':
			robotLinePosition--;
			break;
		case 'S':
			robotLinePosition++;
			break;
		default:
			break;
	}

	// visitsMaze[robotLinePosition - 1][robotColPosition - 1]++;
	// cout << "Robot Line " << robotLinePosition << endl;
	// cout << "Robot Col " << robotColPosition << endl;
}

void turnLeft(){
	switch (currentDirection){
		case 'E':
			currentDirection = 'N';
			break;
		case 'N':
			currentDirection = 'W';
			break;
		case 'S':
			currentDirection = 'E';
			break;
		case 'W':
			currentDirection = 'S';
			break;
	}
}

void turnRight(){
	switch (currentDirection){
		case 'E':
			currentDirection = 'S';
			break;
		case 'N':
			currentDirection = 'E';
			break;
		case 'S':
			currentDirection = 'W';
			break;
		case 'W':
			currentDirection = 'N';
			break;
	}
}

bool canMoveForward(){

	int line, col;
	line = robotLinePosition;
	col = robotColPosition;
	switch (currentDirection){
		case 'E':
			col++;
			break;
		case 'N':
			line--;
			break;
		case 'S':
			line++;
			break;
		case 'W':
			col--;
			break;
	}
	return (newMaze[line][col] == 0);
}

bool wallOnRight(){

	int line, col;
	line = robotLinePosition;
	col = robotColPosition;
	switch (currentDirection){
		case 'E':
			line++;
			break;
		case 'N':
			col++;
			break;
		case 'S':
			col--;
			break;
		case 'W':
			line--;
			break;
	}
	return (newMaze[line][col] == 1);
}

int main(){
	
	while(true){

		cin >> mazeHeight >> mazeWidth;

		// cout << "Height " << mazeHeight << endl;
		// cout << "Width " << mazeWidth << endl;

		// maze with borders
		newMaze.resize(mazeHeight + 2);
		for(int k = 0; k < mazeHeight + 2; k++){
			newMaze[k].resize(mazeWidth + 2);
		}

		visitsMaze.resize(mazeHeight);
		for(int k = 0; k < mazeHeight; k++){
			visitsMaze[k].resize(mazeWidth);
		}

		for(int k = 0; k < mazeHeight; k++){
			for(int l = 0; l < mazeWidth; l++){
				visitsMaze[k][l] = 0;
			}
		}

		if(mazeWidth == 0 && mazeHeight == 0){ break; }

		for(int k = 0; k < mazeHeight + 2; k++){
			newMaze[k][0] = 1;
			newMaze[k][mazeWidth + 1] = 1;
		}
		for(int k = 0; k < mazeWidth + 2; k++){
			newMaze[0][k] = 1;
			newMaze[mazeHeight + 1][k] = 1;
		}


		for(int k = 1; k <= mazeHeight; k++) {
			char line[mazeWidth];
			scanf("%s", line);
			for(int l = 0; l < mazeWidth; l++) {
				newMaze[k][l + 1] = charToInt(line[l]);
			}
		}
		
		// printMaze();
		//set robot in the south west corner turned to east direction
		currentDirection = 'E';
		robotColPosition = 1;
		robotLinePosition = mazeHeight;
		// visitsMaze[robotLinePosition][robotColPosition]++;

		// cout << "Robot Line " << robotLinePosition << endl;
		// cout << "Robot Col " << robotColPosition << endl;

		
		do
        {
            do
            {
                if (wallOnRight())
                {
                    if (!canMoveForward())
                    {
                        turnLeft();
                    }
                }
                else
                {
                    turnRight();
                }
            }
            while(!canMoveForward());

            walkRobot(currentDirection);
        }
        while (robotLinePosition != mazeHeight || robotColPosition != 1);
        printVisitsResult();

        // printVisitsResult();
	}

	return 0;
}