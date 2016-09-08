#include <iostream>
#include <algorithm>

using namespace std;
#define MAXBUDGET 500000;

int main(){
	int numOfParticipants, budget, numOfHotels, numOfWeeks;
	while(cin >> numOfParticipants >> budget >> numOfHotels >> numOfWeeks){

		int bestPrice = MAXBUDGET;
		int foundHotel = 0;
		for(int i = 0; i < numOfHotels; i++) {
			int hotelPrice = 0, availableBeds = 0;
			cin >> hotelPrice;
			
			for(int j = 0; j < numOfWeeks; j++) {
				cin >> availableBeds;
				
				if (availableBeds >= numOfParticipants && numOfParticipants*hotelPrice < bestPrice && numOfParticipants*hotelPrice < budget) {
					foundHotel = 1;
					bestPrice = numOfParticipants * hotelPrice;
				}
			}
		}
		if (foundHotel){
			cout << bestPrice << endl;
		} else {
			cout << "stay home" << endl;
		}	
	}		
	return 0;
}
