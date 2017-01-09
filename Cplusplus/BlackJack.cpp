#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;
int cardDeckNum = 52;

class Card {
public:
	Card(string cardFace, string cardSuit);
	string print() const;
	int magic();
	Card();
private:
	string face;
	string suit;

};

Card::Card() {

}

//Setters???
Card::Card(string cardFace, string cardSuit) {
	face = cardFace;
	suit = cardSuit;
}


//Getters?
string Card::print() const {
	string singlecard = face + suit;
	return singlecard;
}
int Card::magic() {
	return 5;
}


class Deck {
public:
	Deck();
	void Shuffle();
	Card dealCard();
	void printDeck() const;
private:
	Card * deck;
	int CurrentCard;

};

void Deck::printDeck() const {
	cout << left;
	for (int i = 0; i < cardDeckNum; i++) {
		cout << setw(19) << deck[i].print();

		if ((i + 1) % 4 == 0) {
			cout << endl;
		}
	}
}

//Creating a Deck Class
Deck::Deck() {
	string faces[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	string suit[] = { "♠", "♣", "♥", "♦" };
	deck = new Card[cardDeckNum];
	CurrentCard = 0;
	for (int count = 0; count < cardDeckNum; count++) {
		deck[count] = Card(faces[count % 13], suit[count / 13]);

	}
}

void Deck::Shuffle() {
	CurrentCard = 0;
	for (int first = 0; first < cardDeckNum; first++) {
		int second = (rand() + time(0)) % cardDeckNum;
		Card temp = deck[first];
		deck[first] = deck[second];
		deck[second] = temp;
	}
}

Card Deck::dealCard() {
	if (CurrentCard > cardDeckNum) {
		Shuffle();
	}
	if (CurrentCard < cardDeckNum) {
		return (deck[CurrentCard++]);
	}
	return (deck[0]);
}

vector<string> BurnPhase(stack<string> gameDeck) {
	vector<string> burnDeck;
	for (int i = 0; i < 3; i++) {
		gameDeck.pop();
		burnDeck.at(i) = gameDeck.top();
		gameDeck.pop();
	}
	return burnDeck;
}

int get_random() {
	int low = 1;
	int high = 2;
	return low + (rand() % (high - low));
}

void set_up_random() {
	srand(time(0));
}

int get_randomMoney(int high) {
	int low = 1;
	return low + (rand() % (high - low));
}


int calculateScore(string s) {
	int score = 0;
	int acevalue = 0;

		if (s.at(0) == '2') {
			score += 2;
		}
		else if (s.at(0) == '3') {
			score += 3;
		}
		else if (s.at(0) == '4') {
			score += 4;
		}
		else if (s.at(0) == '5') {
			score += 5;
		}
		else if (s.at(0) == '6') {
			score += 6;
		}
		else if (s.at(0) == '7') {
			score += 7;
		}
		else if (s.at(0) == '8') {
			score += 8;
		}
		else if (s.at(0) == '9') {
			score += 9;
		}
		else if (s.at(0) == 'J' || s.at(0) == 'Q' || s.at(0) == 'K') {
			score += 10;
		}
		else if (s.at(0) == '1' && s.at(1) == '0') {
			score += 10;
		}
	
	return score;
}






int main() {
	//Basic Variables
	Deck deck;
	Card CurrentCard;
	stack<string> gameDeck;
	vector<string> playerHand1;
	vector<string> playerHand2;
	vector<string> playerHand3;
	vector<string> playerHand4;

	//Game variables

	//int variables
	//int numofPlayers = 4;
	//int cardDealt = 0;
	int options = 0;
	//int bet = 0;
	//int pot = 0;
	//int player1Money = 10000;
	//int player2Money = 10000;
	//int player3Money = 10000;
	//int player4Money = 10000;
	//int Pokerround = 1;
	//int playerTurn = 0;
	//int turnPassed = 0;
	//int checkAgree = 0;
	int playerscore = 0;
	int playerscore2 = 0;
	int acevalue = 0;
	int choice = 0;

	//string variables
	string playerCard;
	string singleCard;

	//bool variables
	bool inGame = true;
	bool enableCheck;
	bool playerTurnend;
	bool playerLost;


	//Debugging Section

	// cout << "Printing Deck" << endl;
	// deck.printDeck();
	// cout << "   " << endl;
	// cout << "Shuffle" << endl;
	// deck.Shuffle();
	// cout << endl << endl;

	// cout << "Printing Deck After Shuffle" << endl;
	// deck.printDeck();


	// deck.Shuffle();

	// cout << "Printing Deck After Shuffle for the Second Time" << endl;
	// deck.printDeck();

	cout << "Shuffle " << endl;
	deck.Shuffle();
	deck.Shuffle();

	cout << "Dealing Card" << endl;
	cout << "               " << endl;
	for (int i = 0; i < cardDeckNum; i++) {
		CurrentCard = deck.dealCard();
		singleCard = CurrentCard.print();
		gameDeck.push(singleCard);
	}


	for (int i = 0; i < 2; i++) {
		playerCard = gameDeck.top();
		playerHand1.push_back(playerCard);
		gameDeck.pop();
		playerCard = gameDeck.top();
		playerHand2.push_back(playerCard);
		gameDeck.pop();
		// playerCard = gameDeck.top();
		// playerHand3.push_back(playerCard);
		// gameDeck.pop();
		// playerCard = gameDeck.top();
		// playerHand4.push_back(playerCard);
		// gameDeck.pop();

	}



	cout << "Player's Hand" << endl;
	for (int i = 0; i < playerHand1.size(); i++) {
		cout << playerHand1.at(i) << endl;



	}
	if (playerHand1.at(0).at(0) == 'A' || playerHand1.at(1).at(0) == 'A') {
		cout << "Do you want the ace value to be 1 or 11 ?" << endl;
		cin >> acevalue;
		playerscore = acevalue;
		if (playerHand1.at(0).at(0) == 'A') {
			playerscore += calculateScore(playerHand1.at(1));
		}
		else if (playerHand1.at(1).at(0) == 'A') {
			playerscore += calculateScore(playerHand1.at(0));
		}
	}
	else {
		for (int i = 0; i < playerHand1.size(); i++) {
			playerscore += calculateScore(playerHand1.at(i));
		}

	}

	if (playerscore == 21) {
		cout << "Congrats you received blackjack 21~" << endl;
	}





	//Options for human players 

	cout << "Option 1 Hit" << endl;
	cout << "Option 2 Stay" << endl;
	cout << "Option 3 Points" << endl;
	while (options != 2 && playerscore != 21) {
		cin >> options;

		if (options == 1) {
			playerCard = gameDeck.top();
			playerHand1.push_back(playerCard);
			gameDeck.pop();

			for (int i = 0; i < playerHand1.size(); i++) {
				cout << playerHand1.at(i) << endl;
			}
			if (playerCard.at(0) == 'A') {
				cout << "Do you want the ace value to be 1 or 11 ?" << endl;
				cin >> acevalue;
				playerscore += acevalue;
			}
			else {
				playerscore += calculateScore(playerCard);

			}
			
			if (playerscore > 21) {
				cout << "GG you lose " << endl;
				playerLost = true;
				playerTurnend = true;
				break;
			}
			else if (playerscore == 21) {
				cout << "You Score 21 " << endl;
				
				break;
			}

		}

		else if (options == 2) {
			playerTurnend = true;
			break;
		}
		else if (options == 3){
			cout << "Your score is " << playerscore << endl;
		}
	}


	cout << "Your Hand:" << endl;
	for (int i = 0; i < playerHand1.size(); i++) {
		cout << playerHand1.at(i) << endl;
	}
	cout << "Your score is:  " << playerscore << endl;

	if(playerTurnend == true){
		options = 0;
	}



	cout << "Player 2's Hand" << endl;
	cout << "options " << options << endl; //Debugging Purposes
	for (int i = 0; i < playerHand2.size(); i++) {
		cout << playerHand2.at(i) << endl;



	}
	if (playerHand2.at(0).at(0) == 'A' || playerHand2.at(1).at(0) == 'A') {
		choice = get_random();
		if (choice == 1) {
			cout << "Player 2 has set the Ace Value to 1" << endl;
			playerscore2 = 1;
		}
		else if (choice == 2) {
			cout << "Player 2 has set the Ace Value to 11" << endl;
			playerscore2 = 11;
		}

		if (playerHand2.at(0).at(0) == 'A') {
			playerscore += calculateScore(playerHand2.at(1));
		}
		else if (playerHand2.at(1).at(0) == 'A') {
			playerscore += calculateScore(playerHand2.at(0));
		}
	}
	else {
		for (int i = 0; i < playerHand2.size(); i++) {
			playerscore2 += calculateScore(playerHand2.at(i));
		}
		

	}

	cout << "Player 2 score : " << playerscore2 << endl;

	while (options != 2) {
		if ((playerscore2 >= 2 && playerscore2 <= 13) || (playerscore2 <= playerscore || playerLost == true) ) {
			options = 1;
		}
		else if ( (playerscore >= 14  && playerscore2 <= 20) || (playerscore2 >= playerscore || playerLost == true)) {
			options = 2;
		}

		cout << "options" << " " << options << endl;

		if (options == 1) {
			playerCard = gameDeck.top();
			playerHand2.push_back(playerCard);
			gameDeck.pop();

			for (int i = 0; i < playerHand2.size(); i++) {
				cout << playerHand2.at(i) << endl;
			}
			if (playerCard.at(0) == 'A') {
				choice = get_random();
				if (choice == 1) {
					cout << "Player 2 has set the Ace Value to 1" << endl;
					playerscore2 += 1;
				}
				else if (choice == 2) {
					cout << "Player 2 has set the Ace Value to 11" << endl;
					playerscore2 += 11;
				}
			}
			else {
				playerscore2 += calculateScore(playerCard);

			}
			cout << "Player 2 score is:  " << playerscore2 << endl;
			if (playerscore2 > 21) {
				cout << "GG player 2 lose " << endl;
				break;
			}
			else if (playerscore2 == 21) {
				cout << "Player 2 received 21 " << endl;
				break;
			}

		}
		else if (options == 2) {
			break;
		}
		

     
	}


	cout << "Player 2's hand:" << endl;
	for (int i = 0; i < playerHand2.size(); i++) {
		cout << playerHand2.at(i) << endl;
	}
	cout << "Player 2's score:  " << playerscore2 << endl;

	if (playerscore2 > playerscore) {
		if (playerscore2 > 21 && playerscore > 21) {
			cout << "GG you both lose " << endl;
		}
		else if(playerscore2 > 21) {
			cout << "GG you wins " << endl;
		}
		else {
			cout << "GG Player 2 Wins " << endl;
		}
		
	}
	else if (playerscore2 < playerscore) {
		if (playerscore2 > 21 && playerscore > 21) {
			cout << "GG you both lose " << endl;
		}
		else if(playerscore > 21) {
			cout << "GG player 2  wins " << endl;
		}
		else {
			cout << "GG You Win" << endl;
		}
	}

	else if (playerscore2 == playerscore) {
		cout << "GG both players tied " << endl;
	}


	return 0;

}
