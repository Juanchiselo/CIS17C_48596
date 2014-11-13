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
	string output;
	
	for (int line = 1; line <= 35; line++)
	{
		if (line % 6 == 0)
			output += "\n";
		if (line < 6)
			output += "Card #" + to_string(line) + "   ";
		if (line < 12)
		{
			output += char(201);
			for (int lengthSize = 0; lengthSize < 6; lengthSize++)
				output += char(205);
			output += char(187);
			output += "  ";
		}
		if (line < 18 || line < )
		{
			output += char(186);
			output += "      ";
			output += char(186);
			output += "  ";
		}
		if (line < 24)
		{
			output += char(186);
			output += " A: " + to_string(currentHand.at(card - 1).getAttack());
			output += " ";
			output += char(186);
			output += "  ";
		}
		if (line < 30)
		{
			output += char(186);
			output += " D: " + to_string(currentHand.at(card - 1).getDefense());
			output += " ";
			output += char(186);
			output += "  ";
		}
	}
	
	for (int card = 1; card <= 5; card++)
	{
		cards += char(186);
		cards += "      ";
		cards += char(186);
		cards += "  ";
	}

	cards += "\n";

	for (int card = 1; card <= 5; card++)
	{
		cards += char(200);

		for (int lengthSize = 0; lengthSize < 6; lengthSize++)
		{
			cards += char(205);
		}

		cards += char(188);
		cards += "  ";
	}
	cards += "\n";

	cout << cards;
}

Card* Hand::getCard(int chosenCard)
{
	this->chosenCard = chosenCard;

	return &currentHand.at(chosenCard);
}