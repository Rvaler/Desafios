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

	
	string line;
	int counter = 1;
	while(cin >> line){
		if (line == "end"){
			break;
		}

		// int bla = 'A' - 'B';
		// cout << bla << endl;
		vector<stack<char> > containerStacks;
		for(int k = 0; k < line.length(); k++){

			bool foundStackToPut = false;
			char container = line[k];
			int difference = 99;
			int choosedStack = -1;
			for(int v = 0; v < containerStacks.size(); v++){
				// cout << containerStacks[v].top() << " - " << container << " = " << containerStacks[v].top() - container << endl;
				if( (containerStacks[v].top() - container) < difference && (containerStacks[v].top() - container) >= 0){
					foundStackToPut = true;
					difference = containerStacks[v].top() - container;
					// cout << difference << endl;
					choosedStack = v;
				}
			}
			if(!foundStackToPut){
				containerStacks.resize(containerStacks.size() + 1);
				containerStacks[containerStacks.size() - 1].push(container);
			}else{
				containerStacks[choosedStack].push(container);
			}
		}
		cout << "Case " << counter << ": " << containerStacks.size() << endl;
		counter++;
	}

}