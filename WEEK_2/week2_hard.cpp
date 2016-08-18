#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <queue>
#include <stack>


using namespace std;

void printSolution(int canBeQueue, int canBeStack, int canBePriorityQueue){
	if(canBeStack && !(canBeQueue || canBePriorityQueue)){
		cout << "stack" << endl;
		return;
	}

	if(canBeQueue && !(canBeStack || canBePriorityQueue)){
		cout << "queue" << endl;
		return;
	}

	if(canBePriorityQueue && !(canBeStack || canBeQueue)){
		cout << "priority queue" << endl;
		return;
	}

	if(!(canBeQueue || canBeStack || canBePriorityQueue)){
		cout << "impossible" << endl;
		return;
	}

	cout << "not sure" << endl;
	return;
}

int main(){

	int numberOfCommands;
	int command;
	int value;

	while(!cin.eof() && cin >> numberOfCommands) {

		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;

		int canBeQueue = 1;
		int canBeStack = 1;
		int canBePriorityQueue = 1;

		for(int k = 0; k < numberOfCommands; k++){

			cin >> command >> value;
			
			if (command == 1) {
				if(canBeStack){
					s.push(value);
				}
					
				if(canBeQueue){
					q.push(value);
				}
					
				if(canBePriorityQueue){
					pq.push(value);
				}
					
			}else if(command == 2){

				// QUEUE VERIFICATION
				if(!q.empty() && canBeQueue && value == q.front()){
					q.pop();
				}else{
					canBeQueue = 0;
				}

				// STACK VERIFICATION
				if(!s.empty() && canBeStack && value == s.top()){
					s.pop();
				}else{
					canBeStack = 0;
				}

				// PRIRITY QUEUE VERIFICATION
				if(!pq.empty() && canBePriorityQueue && value == pq.top()){
					pq.pop();
				}else{
					canBePriorityQueue = 0;
				}
			}
		}
		printSolution(canBeQueue, canBeStack, canBePriorityQueue);
	}
	return 0;
}