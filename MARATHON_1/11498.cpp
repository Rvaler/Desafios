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
		int numberOfQueries, n, m, x, y;;
		cin >> numberOfQueries;		

		if(numberOfQueries == 0){
			break;
		}
		cin >> n >> m;
		for(int k = 0; k < numberOfQueries; k++){
			cin >> x >> y;
			if( (n == x || m == y) ){
				cout << "divisa" << endl;
			}else if(x < n && y > m){
				cout << "NO" << endl;
			}else if(x > n && y > m){
				cout << "NE" << endl;
			}else if(x < n && y < m){
				cout << "SO" << endl;
			}else{
				cout << "SE" << endl;
			}
		}
	}
}