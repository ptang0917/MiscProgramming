#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
const int cardDeckNum = 52;

class Card {
public:
	Card(string cardFace, string cardSuit);
	string print() const;
	Card();
private:
	string face;
	string suit;

};

Card::Card() {

}

Card::Card(string cardFace, string cardSuit) {
	face = cardFace;
	suit = cardSuit;
}

string Card::print() const {
	string singlecard = face + suit;
	return singlecard;
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

int main() {
	Deck deck;
	Card CurrentCard;
	cout << "Printing Deck" << endl;
	deck.printDeck();
	cout << "   " << endl;
	cout << "Shuffle" << endl;
	deck.Shuffle();
	cout << endl << endl;
	

	cout << "Print Deck " << endl;
	deck.printDeck();
	cout << endl << endl;

	cout << "Shuffle" << endl;
	deck.Shuffle();
	cout << endl << endl;


	 deck.printDeck();
	 cout << endl << endl;

	 deck.Shuffle();

	cout << "Dealing Card" << endl;
	cout << "               " << endl;
	for (int i = 0; i < 52; i++) {
		CurrentCard = deck.dealCard();
		cout << CurrentCard.print() << endl;

	}
	//system("PAUSE");
	return 0;
}

