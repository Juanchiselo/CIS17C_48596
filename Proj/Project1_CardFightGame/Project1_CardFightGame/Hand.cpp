#include "Hand.h"

Hand::Hand()
{
	size = 5;

	for (int card = 0; card < size; card++)
		currentHand.push_back(deck.getCard());
}

Hand::~Hand()
{

}

void Hand::replaceCard()
{
	currentHand.erase(currentHand.begin() + chosenCard);
	currentHand.push_back(deck.getCard());
}

void Hand::displayHand()
{
	char upperLeftCorner = 201;
	char upperRightCorner = 187;
	char leftLowerCorner = 200;
	char rightLowerCorner = 188;
	char horizontal = 205;
	char vertical = 186;

	string cards;

	/*cout << leftUpperCorner << horizontal << horizontal << horizontal
		<< horizontal << horizontal << horizontal << rightUpperCorner
		<< "\n" << vertical << "      " << vertical << "\n" << vertical
		<< " A: " << attack << " " << vertical << "\n" << vertical
		<< " D: " << defense << " " << vertical << "\n" << vertical
		<< "      " << vertical << "\n" << leftLowerCorner
		<< horizontal << horizontal << horizontal << horizontal
		<< horizontal << horizontal << rightLowerCorner << endl;*/


	for (int card = 0; card < 5; card++)
	{
		cards += char (201);

		for (int lengthSize = 0; lengthSize < 6; lengthSize++)
		{
			cards += char (205);
		}

		cards += char (187);
		cards += "  ";
	}

	cards += "\n";

	cout << cards;


	/*int count = 0;
	for (auto iterator = currentHand.begin();
		iterator != currentHand.end(); iterator++)
	{
		count++;
		cout << "Card #" << count << ":  " << endl;
		iterator->print();
	}*/
}

Card* Hand::getCard(int chosenCard)
{
	this->chosenCard = chosenCard;

	return &currentHand.at(chosenCard);
}