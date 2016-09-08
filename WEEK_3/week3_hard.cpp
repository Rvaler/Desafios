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

	int number_sets;
	cin >> number_sets;

	for(int k = 0; k < number_sets; k++){

		int number_stations, carrier_capacity, max_cargo_platformB;
		cin >> number_stations >> carrier_capacity >> max_cargo_platformB;

		stack<int> carrier;
		int currentCarrierLoad = 0;
		vector<queue<int> > platforms_B_queues;
		platforms_B_queues.resize(number_stations);

		for(int l = 0; l < number_stations; l++){
			int number_cargos, cargo_destination;
			cin >> number_cargos;
			for(int c = 0; c < number_cargos; c++){
				cin >> cargo_destination;
				platforms_B_queues[l].push(cargo_destination);
			}
		}


		int timeSpent = -2;	
		bool distributeFinished = false;
		for(int p = 0; !distributeFinished; p++){
			timeSpent += 2;
			int currentStationNumber = (p % number_stations) + 1;

			//unload session
			bool isUnloading = true;
			while(!carrier.empty() && isUnloading){
				int package = carrier.top();
				if(package == currentStationNumber){
					carrier.pop();
					timeSpent++;
				}else if(platforms_B_queues[p % number_stations].size() < max_cargo_platformB){
					carrier.pop();
					platforms_B_queues[p % number_stations].push(package);
					timeSpent++;
				}else{
					isUnloading = false;
				}
			}

			//load session
			while(carrier.size() < carrier_capacity && platforms_B_queues[p % number_stations].size() > 0){
				int package = platforms_B_queues[p % number_stations].front();
				platforms_B_queues[p % number_stations].pop();
				carrier.push(package);
				timeSpent++;
			}

			//check if distribute is over
			distributeFinished = true;
			if(carrier.size() > 0){
				distributeFinished = false;
			}
			for(int k = 0; k < number_stations && distributeFinished == true; k++){
				if(platforms_B_queues[k].size() > 0){
					distributeFinished = false;
				}
			}
		}

		cout << timeSpent << endl;

	}
}