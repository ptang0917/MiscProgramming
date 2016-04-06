#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <stdlib.h>
#include <ctime>
using namespace std;
vector<char> hangmanword;
int globalcount;

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



bool LetterAlready(char letter, vector<char> hangmanword) {
	bool existed;
	for (int i = 0; i < hangmanword.size(); i++) {
		if (letter == hangmanword.at(i)) {
			
			existed = true;
			break;
		}
	}
	if (existed == true) {
		return existed;
	}
	else {
		return false;
	}
}




bool LettersMatch(char s, string s2) {
	int count = 0;
	bool exist = false;
	
	for (int i = 0; i < s2.size(); i++) {
	
	 
		if (s == s2.at(i)) {
			count++;
			HangManWord(s, i, s2);
			
		}
		
		
		

	}
	if (count > 0) {
		globalcount = count;
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
	vector <string> wordbank = { "xeclouyd", "wafflefries", "gosu", "meteos", "faker", "doublelift", "lemonnation", "rush", "sneaky", "yellowstar", "marin" , "chidoto", "kimyxiaoyue", "lollipopzozo"};
	vector <string> body = { "head", "left arm", "right arm" , "body", "left leg", "right leg" };
	int choice = 100;
	int bodyparts = 0;
	int lettercount = 0;
	char answer;
	int randomnumber = 0; 
	
	char s;
	std::cout << "Do you want to play the guessing game press Y or y for yes or press N or n for no ? " << std::endl;
	std::cin >> answer;
	
	
	while (answer == 'y' || answer == 'Y') {
		randomnumber = get_random(wordbank.size());
		string keyword = wordbank.at(randomnumber);
		int keywordsize = keyword.size();
		for (int i = 0; i < keywordsize; i++) {
			hangmanword.push_back('_');
		}
		cout << "select the following option" << endl;
		cout << "1) Choose a letter " << endl;
		cout << "2) Ask for a hint " << endl;
		cout << "3) Check body status " << endl;
		cout << "4) Give up " << endl;
		cout << "5) Check keyword status" << endl;
		cout << "6) Quit " << endl;
		while (choice > 0) {
			cin >> choice;
			if (choice == 1) {
				cout << "Enter the letter " << endl;
				cin >> s;
				if (LettersMatch(s, keyword) == false) {
					cout << "wrong" << endl;
					bodyparts++;
					cout << "you have " << " " ;
					for (int i = 0; i < bodyparts; i++) {
						cout << body.at(i) << endl;
					}
					if (bodyparts == body.size()) {
						cout << "GG you lose" << endl;
					}
				}

				else if (LettersMatch(s, keyword) == true) {
					cout << "correct" << endl;
					lettercount += globalcount;
					
					cout << "Lettercount " << lettercount << " Keywordsize " << hangmanword.size() << endl;
					if (lettercount == hangmanword.size()) {
						cout << "Congrats you won" << "The hangman word is " << keyword << endl;
						
						break;
					}

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

				/*if (checkVictory() == true) {
					cout << "Congrats you found the secret word" << endl;
					break;
				}*/
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
		std::cout << "Would you like to play again press Y or y for yes and N or n for no ? " << std::endl;
		std::cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			lettercount = 0;
			bodyparts = 0;
			for (int i = 0; i < hangmanword.size(); i++) {
				hangmanword.clear();
			}
			cout << hangmanword.size() << endl;
			continue; //takes the user back to the start of the game where a new random number is set up
		}
		else if (answer == 'n' || answer == 'N') {
			break;  //exits the game when the user decides to quit
		}
	}
	cin.get();
	return 0;

}
