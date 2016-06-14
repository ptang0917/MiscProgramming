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
	int numofPlayers = 4;
	int cardDealt = 0;
	int options = 0;
	int bet = 0;
	int pot = 0;
	int player1Money = 10000;
	int player2Money = 10000;
	int player3Money = 10000;
	int player4Money = 10000;
	int Pokerround = 1;
	int turnPassed = 0;

	string playerCard;
	string singleCard;

	

	/*cout << "Printing Deck" << endl;
	deck.printDeck();
	cout << "   " << endl;
	cout << "Shuffle" << endl;*/
	deck.Shuffle();
	cout << endl << endl;



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
			playerCard = gameDeck.top();
			playerHand3.push_back(playerCard);
			gameDeck.pop();
			playerCard = gameDeck.top();
			playerHand4.push_back(playerCard);
			gameDeck.pop();

		}

	

	cout << "Player's Hand" << endl;
	for (int i = 0; i < playerHand1.size(); i++) {
		cout << playerHand1.at(i) << endl;

	}

	while (Pokerround != 4) {
		cout << "Option 1  Call" << endl;
		cout << "Option 2  Raise" << endl;
		cout << "Option 3  Fold" << endl;
		cout << "Option 4  View current pot" << endl;
		cout << "Option 5  View current balace" << endl;
		cout << "Option 6  Check" << endl;
		if (Pokerround == 1) {
			if (options == 1) {

				player1Money -= 100;
				pot += 100;
			}
			else if (options == 2) {
				cout << "Enter your bet" << endl;
				cin >> bet;
				pot += bet;
				player1Money -= bet;
			}
			else if (options == 3) {
				break;
			}
			else if (options == 4) {
				cout << "Current pot:  " << pot << endl;
			}
			else if (options == 5) {
				cout << "Your current balance: " << player1Money << endl;
			}
			else if (options == 6) {
				Pokerround++;
			}
		}

		else if (Pokerround == 2) {
			 vector<string> 
		}
		

	}

	
	
	//cout << "Option 1: Call " << endl;
	//cout << "Option 2: Raise " << endl;
	//cout << "Option 3: Fold "

	return 0;
}

