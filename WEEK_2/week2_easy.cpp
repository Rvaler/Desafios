#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main(){

	int numberOfIntegers = 0;
	int lineSum = 0;
	int topHeapSum = 0;

	while(cin >> numberOfIntegers && numberOfIntegers != 0){

		priority_queue<int, vector<int>, greater<int> > pq;

		// inserting numbers in heap
		for(int k = 0; k < numberOfIntegers; k++){
			int value;
			cin >> value;
			pq.push(value);
		}

		lineSum = 0;
		topHeapSum = 0;

		while(pq.size() >= 2){

			int firstValue = pq.top();
			pq.pop();
			int secondValue = pq.top();
			pq.pop();
		
			topHeapSum = (firstValue + secondValue);
			lineSum += topHeapSum;

			pq.push(topHeapSum);
		}

		cout << lineSum << endl;
	}
}