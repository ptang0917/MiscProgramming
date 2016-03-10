#include <iostream>
#include <string>

using namespace std;

int charactersMatch(char c, string word) {
	int match;
	for(int i = 0; i < word.size(); i++){
		if(word.at(i) == c && match == 0){
			//cout << "letter " << c << endl;
			//cout << "letter 2 " << word.at(i) << endl;
			match++;
		}
		else if(word.at(i) == c && match > 0){
			break;
		}
		
	}
	return match;
}

int main(){
	string s1;
	cout << "Enter the first word " << endl;
	cin >> s1;

	cout << "Enter the second word " << endl;
	string s2;
	cin >> s2;
	int count;
	int i = 0;
	bool notanagram;
	if(s1.size() == s2.size()){
		for(int i = 0; i < s1.size(); i++){
			count += charactersMatch(s1.at(i), s2); 
			
		}
		if(count == s1.size()){
			cout << s1 << " and " << s2 << " are  anagrams  " << endl;

		}
		else {
			cout << s1 << " and " << s2 << " are not anagrams  " << endl;
		}
		
	}
	else {
		cout << s1 << " and " << s2 << " are not anagrams as they don't have the same amount of characters " << endl;
	}

	return 0;
}
