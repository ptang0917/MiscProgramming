#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;


int main(){
	map<char,int> lettermap1;
	map<char,int> lettermap2;
	string s1;
	cout << "Enter the first word " << endl;
	cin >> s1;

	cout << "Enter the second word " << endl;
	string s2;
	cin >> s2;
	int firstwordmatchcount = 0;
	int secondwordmatchcount = 0;

	for(int i =0; i < s1.size(); i++){
		if(s1.at(i) != ' '){
			lettermap1[s1.at(i)] += 1;
		}
		
	}
	for(int i = 0; i < s2.size(); i++){
		if(s2.at(i) != ' '){
			lettermap2[s2.at(i)] += 1;
		}
		
	}
	if(lettermap2.size() != lettermap1.size()){
		cout << s1 << " and " << s2 << " are not anagrams " << endl;
	}
	else{
		for(auto x: lettermap1){
			if(x.second == lettermap2[x.first]){
				firstwordmatchcount++;
			}
		}
		for(auto y: lettermap2){
			if(y.second == lettermap1[y.first]){
				secondwordmatchcount++;
			}
		}
		if(firstwordmatchcount == secondwordmatchcount){
			cout << s1 << " and " << s2 << " are  anagrams " << endl;
		}
		else{
			cout << s1 << " and " << s2 << " are not  anagrams " << endl;
		}

	}

	return 0;
}
