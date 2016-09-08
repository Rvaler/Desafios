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

int main(){

	int numberOfTestCases;
	cin >> numberOfTestCases;

	cin.ignore();
	for(int k = 0; k < numberOfTestCases; k++){
		string teamOutput, judgeOutput;
		getline(cin, teamOutput);
		getline(cin, judgeOutput);

		cout << "Case " << k + 1;
		if(teamOutput.compare(judgeOutput) == 0){
			cout << ": Yes" << endl;
		}else{
			string::iterator end_pos = std::remove(teamOutput.begin(), teamOutput.end(), ' ');
			teamOutput.erase(end_pos, teamOutput.end());
			if(teamOutput.compare(judgeOutput) == 0){
				cout << ": Output Format Error" << endl;
			}else{
				cout << ": Wrong Answer" << endl;
			}
		}
	}

}