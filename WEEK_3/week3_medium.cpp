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

	set<string> dictionary;

	string line;
	string word;
	string wordAux = "";
	bool isHifenando = false;
	while(!cin.eof() && getline(cin, line)){

		for(int k = 0; k < line.size(); k++){
			if((ispunct(line[k]) && line[k] != '-' )|| isdigit(line[k])) {
				replace(line.begin(), line.end(), line[k], ' ');
			}
		}

		
		istringstream iss(line);
		while(getline(iss, word, ' ')){
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			
			
			if(word.back() != '-' && !isHifenando){
				dictionary.insert(word);
			}else if(isHifenando && word.back() != '-'){
				isHifenando = false;
				wordAux.append(word);
				dictionary.insert(wordAux);
				wordAux = "";
			}else if(isHifenando && word.back() == '-'){
				word.pop_back();
				isHifenando = true;
				wordAux.append(word);
			}else if(!isHifenando && word.back() == '-'){
				word.pop_back();
				isHifenando = true;
				wordAux.append(word);
			} 

		}
	}

	dictionary.erase("");
 	for (set<string>::iterator it = dictionary.begin(); it != dictionary.end(); it++){
 		cout << *it << endl;
	}
	return 0;
}