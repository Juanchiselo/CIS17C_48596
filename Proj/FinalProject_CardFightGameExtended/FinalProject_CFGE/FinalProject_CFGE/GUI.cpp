/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#include "GUI.h"
#include "GameManager.h"

GUI::GUI()
{
}

GUI::~GUI()
{
}

string GUI::drawTopBox(int horizontalSize)
{
	graphic = "";
	graphic += upperLeftCorner;
	for (int x = 0; x < horizontalSize; x++)
		graphic += horizontal;
	graphic += upperRightCorner;

	return graphic;
}

string GUI::drawBottomBox(int horizontalSize)
{
	graphic = "";
	graphic += lowerLeftCorner;
	for (int x = 0; x < horizontalSize; x++)
		graphic += horizontal;
	graphic += lowerRightCorner;

	return graphic;
}

void GUI::drawStats()
{
	cout << drawTopBox(46) << endl;

	for (int i = 1; i < 4; i++)
	{
		cout << char(186);
		cout << "     ";
		if (i == 1)
		{
			cout << GameManager::getInstance()->getPlayers().at(0)->getCharacter()->getName()
				<< "           "
				<< GameManager::getInstance()->getPlayers().at(1)->getCharacter()->getName();
		}
		if (i == 2)
		{
			cout << "Health: " << GameManager::getInstance()->getPlayers().at(0)->getCharacter()->getHealth()
				<< "            "
				<< "Health: " << GameManager::getInstance()->getPlayers().at(1)->getCharacter()->getHealth();
		}
		if (i == 3)
		{
			cout << "Energy: " << GameManager::getInstance()->getPlayers().at(0)->getCharacter()->getEnergy()
				<< "            "
				<< "Energy: " << GameManager::getInstance()->getPlayers().at(1)->getCharacter()->getEnergy();
		}
		cout << "       ";
		cout << char(186) << endl;
	}

	cout << drawBottomBox(46) << "\n\n";
}

void GUI::drawChosenCards()
{
	string output;

	output += "\nPlayer chose card:     ";
	output += "Enemy chose card:\n";

	for (int line = 0; line <= 12; line++)
	{
		if (line % 2 == 1)
			output += "\n     ";
		if (line % 2 == 0)
			output += "             ";

		if (line == 1 || line == 2)
		{
			output += drawTopBox(6);
			output += "  ";
		}
		if (line == 3 || line == 4 || line == 9 || line == 10)
		{
			output += char(186);
			output += "      ";
			output += char(186);
			output += "  ";
		}
		if (line == 5 || line == 6)
		{
			output += char(186);
			if (line == 5)
			{
				if (GameManager::getInstance()->getPlayers().at(0)->getChosenCard()->isItemCard())
					output += " Item";
				else
					output += " A: " + to_string(GameManager::getInstance()
					->getPlayers().at(0)->getChosenCard()->getAttack());
			}
			else
			{
				if (GameManager::getInstance()->getPlayers().at(1)->getChosenCard()->isItemCard())
					output += " Item";
				else
					output += " A: " + to_string(GameManager::getInstance()->
					getPlayers().at(1)->getChosenCard()->getAttack());
			}
			output += " ";
			output += char(186);
			output += "  ";
		}
		if (line == 7 || line == 8)
		{
			output += char(186);
			if (line == 7)
			{
				if (GameManager::getInstance()->getPlayers().at(0)->getChosenCard()->isItemCard())
					output += " Card";
				else
					output += " D: " + to_string(GameManager::getInstance()
					->getPlayers().at(0)->getChosenCard()->getDefense());
			}
			else
			{
				if (GameManager::getInstance()->getPlayers().at(1)->getChosenCard()->isItemCard())
					output += " Card";
				else
					output += " D: " + to_string(GameManager::getInstance()
					->getPlayers().at(1)->getChosenCard()->getDefense());
			}

			output += " ";
			output += char(186);
			output += "  ";
		}
		if (line == 11 || line == 12)
		{
			output += drawBottomBox(6);
			output += "  ";
		}
	}

	cout << output << endl;
}

void GUI::drawHandCards(deque<Card>* hand)
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

			if (hand->at(card - 1).isItemCard())
				output += " Item";
			else
				output += " A: " + to_string(hand->at(card - 1).getAttack());
			output += " ";
			output += char(186);
			output += "  ";
		}
		if (line > 24 && line < 30)
		{
			card++;
			output += char(186);
			if (hand->at(card - 6).isItemCard())
				output += " Card";
			else
				output += " D: " + to_string(hand->at(card - 6).getDefense());
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

// Displays the game banner.
void GUI::displayBanner()
{
	cout << "===========================================================================\n"
		<< "                    ULTIMATE CARD FIGHT GAME\n"
		<< "===========================================================================\n" << endl;
}