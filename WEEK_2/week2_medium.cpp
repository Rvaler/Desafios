#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int main(){

	
	int numberOfFrosh;
	while(cin >> numberOfFrosh) {

		// cin >> numberOfFrosh;
		if (numberOfFrosh == 0)
			break;

		// vector with the choosen courses and the number of times it was choosed by a student
		map<vector<int>, int> choosedCoursesMap;

		for(int k = 0; k < numberOfFrosh; k++){
			vector<int> froshCourses(5, 0);
			for(int j = 0; j < 5; j++){
				cin >> froshCourses[j];
			}
			sort(froshCourses.begin(), froshCourses.end());
			choosedCoursesMap[froshCourses]++;
		}

		// finds the most popular between the options, multiplying the times it appear by the number of most popular that exists 
		int mostPopular = 0;
		int numberOfMostPopular = 0;
		for(map<vector<int>, int>::iterator it = choosedCoursesMap.begin(); it != choosedCoursesMap.end(); it++) {
			if(it->second > mostPopular){
				mostPopular = it->second;
			}
		}

		for(map<vector<int>, int>::iterator it = choosedCoursesMap.begin(); it != choosedCoursesMap.end(); it++) {
			if (it->second == mostPopular){
				numberOfMostPopular++;
			}
		}

		cout << numberOfMostPopular * mostPopular << endl;		
	}
}