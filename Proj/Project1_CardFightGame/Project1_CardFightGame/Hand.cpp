#include "Hand.h"

Hand::Hand()
{
	deck = new Deck(200);

	size = 5;

	for (int card = 0; card < size; card++)
		currentHand.push_back(deck->getCard());
}

Hand::~Hand()
{

}

void Hand::replaceCard()
{
	currentHand.erase(currentHand.begin() + chosenCard);
	currentHand.push_back(deck->getCard());
}

void Hand::displayHand()
{
	string output;
	int card = 0;
	
	for (int line = 1; line <= 42; line++)
	{
		if (line % 6 == 0)
			output += "\n";
		if (line < 6)
			output += "Card #" + to_string(line) + "   ";
		if (line > 6 && line < 12)
		{
			output += char(201);
			for (int lengthSize = 0; lengthSize < 6; lengthSize++)
				output += char(205);
			output += char(187);
			output += "  ";
		}
		if ((line > 12 && line < 18) || (line > 30 && line < 36))
		{
			output += char(186);
			output += "      ";
			output += char(186);
			output += "  ";
		}
		if (line > 18 && line < 24)
		{
			card++;
			output += char(186);

			if (currentHand.at(card - 1).getItemCard())
				output += " Item";
			else
				output += " A: " + to_string(currentHand.at(card - 1).getAttack());
			output += " ";
			output += char(186);
			output += "  ";
		}
		if (line > 24 && line < 30)
		{
			card++;
			output += char(186);
			if (currentHand.at(card - 6).getItemCard())
				output += " Card";
			else
				output += " D: " + to_string(currentHand.at(card - 6).getDefense());
			output += " ";
			output += char(186);
			output += "  ";
		}
		if (line > 36 && line < 42)
		{
			output += char(200);
			for (int lengthSize = 0; lengthSize < 6; lengthSize++)
				output += char(205);
			output += char(188);
			output += "  ";
		}
	}

	cout << output;
}

Card* Hand::getCard(int chosenCard)
{
	this->chosenCard = chosenCard;

	return &currentHand.at(chosenCard);
}