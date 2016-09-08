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

	int numberTestCases;
	cin >> numberTestCases;

	for(int i = 0; i < numberTestCases; i++){

		int numberOfPegs;
		cin >> numberOfPegs;

		vector<stack <int> > pegs;
		pegs.resize(numberOfPegs);

		int counter = 1;
		bool executing = true;
		while(executing) {
			bool found = false;
			for(int k = 0; k < numberOfPegs && !found; k++){
				if(pegs[k].empty()){
					pegs[k].push(counter);
					found = true;
					counter++;
					break;
				}
				double square = sqrt(pegs[k].top() + counter);
				if( square - int(square) == 0){
					pegs[k].push(counter);
					found = true;
					counter++;
					break;
				}
			}
			if(found == false){
				executing = false;
			}
		}

		cout << counter - 1 << endl;

	}
}