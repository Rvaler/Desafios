#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

vector<int> initialBoard, newBoard;
vector<vector <int> > solutions;

void calculateMoves(int testCase){

	int minorValue = 99;
	for(int k = 0; k < solutions.size(); k++){
		int moves = 0;
		for(int i = 0; i < 8; i++){
			if(solutions[k][i] != initialBoard[i]){
				moves++;
			}
		}
		minorValue = min(minorValue, moves);
	}
	cout << "Case " << testCase << ": "<< minorValue << endl;
}

bool place(int row, int col){
	for(int k = 0; k < col; k++){
		if(row == newBoard[k]){
			return false;
		}
		if(abs(row - newBoard[k]) == abs(col - k)){
			return false;
		}
	}
	return true;
}

void backtrack(int col){
	for(int i = 0; i < 8; i++){
		if(place(i, col)){
			newBoard[col] = i;
			if(col < 7){
				backtrack(col + 1);
			}else{
				solutions.push_back(newBoard);
			}
		}
	}
}

int main(){

	int position, testCase = 1;;
	while(cin >> position){

		solutions.clear();
		newBoard.clear();
		initialBoard.resize(8);
		newBoard.resize(8);

		initialBoard[0] = position - 1;
		for(int i = 1; i < 8; i++){
			cin >> position ;
			initialBoard[i] = position - 1;
		}

		backtrack(0);
		calculateMoves(testCase);
		
		testCase++;
	}

}