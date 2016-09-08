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

int main(){

	int numberOfCards;

	while(cin >> numberOfCards){

		if (numberOfCards == 0) {
			break;
		}
	
		deque<int> deck;
		for(int k = 1; k <= numberOfCards; k++){
			deck.push_back(k);
		}

		cout << "Discarded cards:";
		int discardedCard, cardFrontToBottom;
		if (deck.size() < 2){
			cout << endl;
		}else{
			cout << " ";
		}
		while(deck.size() >= 2){
			discardedCard = deck.front();
			deck.pop_front();
			cardFrontToBottom = deck.front();
			deck.pop_front();
			deck.push_back(cardFrontToBottom);
			if(deck.size() == 1){
				cout << discardedCard << endl;
			}else{
				cout << discardedCard << ", ";
			}
		}

		cout << "Remaining card: " << deck.front() << endl;		
	}
}