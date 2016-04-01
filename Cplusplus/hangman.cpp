#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <stdlib.h>
#include <ctime>
using namespace std;
vector<char> hangmanword;





void HangManWord(char c, int x, string keyword) {
	
	for (int i = 0; i < keyword.size(); i++) {
		
		if (x == i) {
			hangmanword.at(i) = c;
		}
		
	}
	
	
		
	
}
void checkHangmanWord() {
	for (int i = 0; i < hangmanword.size(); i++) {
		cout << hangmanword.at(i); 
		
		
	}
	cout << " " << endl;

}

bool checkVictory() {
	int charcount = 0;
	vector<char> hangmanword;
	for (int i = 0; i < hangmanword.size(); i++) {
		if (hangmanword.at(i) != '_') {
			charcount++;
		}
	}
	if (charcount == hangmanword.size()) {
		return true;
	}
	else {
		return false;
	}
}

bool LettersMatch(char s, string s2) {
	int count = 0;
	for (int i = 0; i < s2.size(); i++) {
		if (s == s2.at(i)) {
			count++;
			HangManWord(s, i, s2);
		}
		
	}
	if (count > 0) {
		return true;
	}
	else {
		return false;
	}
}
int get_random(int s) //random number function
{
	int low = 1;
	  //setting the high and low limit of the random number
	return low + (rand() % (s - low)); // returning the random number value based on the high and ow limi that was being set up
}

void set_up_random()
{
	srand(time(0)); //NOT sure what it does :S 
}


int main() {
	set_up_random();
	vector <string> wordbank = { "xecloud", "wafflefries", "gosu", "meteos", "faker", "doublelift", "lemonnation", "rush", "sneaky", "yellowstar", "marin"};
	vector <string> body = { "head", "left arm", "right arm" , "body", "left leg", "right leg" };
	int randomnumber = get_random(wordbank.size());
	string keyword = wordbank.at(randomnumber);
	char s; 
	int choice = 100;
	int bodyparts = 0;
	int keywordsize = keyword.size();
	for (int i = 0; i < keywordsize; i++) {
		hangmanword.push_back('_');
	}
	cout << "select the following option" << endl;
	cout << "1 Choose a letter " << endl;
	cout << "2) Ask for a hint " << endl;
	cout << "3) Check body status " << endl;
	cout << "4) Give up " << endl;
	cout << "5) Check keyword status" << endl;
	cout << "6) Quit " << endl;
	while (choice > 0 || bodyparts != body.size() || checkVictory() == false) {
		cin >> choice;
		if (choice == 1) {
			cout << "Enter the letter " << endl;
			cin >> s;
			if (!LettersMatch(s, keyword)) {
				cout << "wrong" << endl;
				bodyparts++;
			}
			else {
				cout << "correct" << endl;
			}
		}
		else if (choice == 2) {
			cout << "This word has " << keywordsize << " letters " << endl;
		}
		else if (choice == 3) {
			cout << "You currently have " << endl;
			for (int i = 0; i < bodyparts; i++) {
				cout << body.at(i) << endl;
			}
		}
		else if (choice == 4) {
			cout << "The keyword is " << keyword << endl;
			cout << "ggwp" << endl;
		}
		else if (choice == 5) {
			checkHangmanWord();
			checkVictory();
			if (checkVictory() == true) {
				cout << "Congrats you found the secret word" << endl;
				break;
			}
		}
		else if (choice == 6) {
			cout << "Thank you come again " << endl;
			exit(0);
		}
		else {
			if (bodyparts == body.size()) {
				cout << "You Lose" << endl;

				break;
			}
			
		}
	}
	cin.get();
	return 0;

}
