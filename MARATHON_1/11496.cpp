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

	while(true) {
		int numberOfSamples;
		cin >> numberOfSamples;	

		if (numberOfSamples == 0){
			break;
		}
		
		vector<int> magnitudes;
		magnitudes.resize(numberOfSamples);
		for(int k= 0; k < numberOfSamples; k++){
			int magnitude;
			cin >> magnitude;
			magnitudes[k] = magnitude;
		}
		int numberOfPeacks = 0;
		for(int k = 0; k < numberOfSamples; k++){
			int magnitudeBefore;
			int magnitudeAfter;
			int currentMagnitude = magnitudes[k];
			if(k == 0){
				magnitudeBefore = magnitudes[magnitudes.size() - 1];
			}else{
				magnitudeBefore = magnitudes[k - 1];
			}
			if(k == magnitudes.size() - 1){
				magnitudeAfter = magnitudes[0];
			}else{
				magnitudeAfter = magnitudes[k + 1];
			}
			
			if((magnitudeBefore < currentMagnitude && magnitudeAfter < currentMagnitude) ||
				(magnitudeBefore > currentMagnitude && magnitudeAfter > currentMagnitude) ) {
				numberOfPeacks++;
			}
		}
		cout << numberOfPeacks << endl;
	}
}