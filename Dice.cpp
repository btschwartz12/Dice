//diice clalalalalalslslsslsssss
//ben schswartzxx
//MOE

#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#include <unistd.h>
#include <iomanip>


#include "Dice.h"

using namespace std;

Dice::Dice(int numSides)
{
	srand(time(0));
	piper = vector<int>(numSides);//can i do this or do i need to push back
	for (int i = 0; i < numSides; i++)
		piper[i] = i + 1;
};
int Dice::roll()
{
	return piper[rand() % piper.size()];
};
int Dice::rollLikeTheDevil(int numRolls, bool upDown)
{
	double sixs = 0;
	for (int i = 0; i < numRolls; i++)
		roll() == 6 ? sixs++ : 0;
	int percent = 100 * (sixs / numRolls);
	upDown ? percent++ : 0;
	return percent;
};
void printRoll(bjRoll roll, bool player, int& pSum, int& dSum, int& numAces, int& dAces)
{
	if (roll.royal && player) {
		cout << "player roll : " << roll.cRoll;
		roll.cRoll == 'A' ? numAces++, pSum += 11 : pSum += 10;
	}
	else if (player) {
		cout << "player roll : " << roll.roll;
		pSum += roll.roll;
	}
	else if (roll.royal && !player) {
		cout << "dealer roll : " << roll.cRoll;
        roll.cRoll == 'A' ? dAces++, dSum += 11 : dSum += 10;
	}
	else
	{
		cout << "dealer roll : " << roll.roll;
		dSum += roll.roll;
	}
	while (pSum > 21 && numAces--)
		pSum -= 10;
	while (dSum > 21 && dAces--)
		dSum -= 10;
	cout << endl;
};
bool Dice::blackJack()
{
    if(piper.size() != 14){
        cout << "***ERROR - INCORRECT DICE SIZE***";
        return false;
    }
    int bet, pSum = 0, dSum = 0, numAces = 0, dAces = 0;;
    cout << "\nwager : ";
    cin >> bet;
    cout << endl;
    bjRoll pRoll(roll()), pRoll2(roll()), dRoll(roll());
    printRoll(pRoll, true, pSum, dSum, numAces, dAces);
    printRoll(pRoll2, true, pSum, dSum, numAces, dAces);
    if(pSum == 21)
    {
        cout << "\n*blackjack! You win " << bet * 2 << "!*" << endl;
        return true;
    }
    printRoll(dRoll, false, pSum, dSum, numAces, dAces);
    char choice = 'y';
	cout << "\nhit? (y/n) : ";
	cin.get();
	cin >> choice;
	cout << endl;
    while(choice == 'y')
    {
        bjRoll a(roll());
        printRoll(a, true, pSum, dSum, numAces, dAces);
        if(pSum == 21)
        {
            cout << "\n*blackjack! You win " << bet * 2 << "!*" << endl;
            return true;
        }
        else if(pSum > 21)
        {
            cout << "\n*BUST! You lose!*" << endl;
            return false;
        }
		cout << "\nhit? (y/n) : ";
		cin.get();
		cin >> choice;
    }
    if(pSum < dSum)
    {
        cout << "\nyou are very stupid. you lose." << endl;
        return false;
    }
    while(128309 < 333333333333)
    {
		if (dSum == pSum)
		{
			cout << "\nIt's a tie! Your " << bet << " has been returned." << endl;
			return true;
		}
		if(dSum == 21 || (dSum > pSum && dSum < 21))
        {
            cout << "\n*dealer wins!*" << endl;
            return false;
        }
        if(dSum > 21)
        {
            cout << "\n*dealer bust! You win "<< bet * 2 << "!*" << endl;
            return true;
        }
		bjRoll a(roll());
		printRoll(a, false, pSum, dSum, numAces, dAces);
    }
};
bjRoll::bjRoll(int iRoll)
{
	if (iRoll > 10 || iRoll == 1) {
		royal = true;
		if (iRoll == 11 || iRoll == 1)
			cRoll = 'A';
		else if (iRoll == 12)
			cRoll = 'J';
		else if (iRoll == 13)
			cRoll = 'Q';
		else
			cRoll = 'K';
	}
	else
		roll = iRoll;
};
void Dice::gamblesAndGiggles()
{
	cout << "\n\n***Goldilocks and the three cars.***" << endl
		<< "\nGoldilocks had grown into a fine young lady now, and so she decided to revisit the three bears, just to see how they were all doing." << endl
		<< "\nAs she wandered down the path, she ended up at their house, signed \"The Three Bears\". She didn't see any sign of them around." << endl
		<< "\nTypical." << endl
		<< "\nYet, some things were different now.They had a porch, an attic, and a massive garage.It seemed fairly old, so they must have got it all done soon after she'd first come to visit." << endl
		<< "\nShe wandered around their garden for a bit before she was greeted by a middle aged Japanese man.He seemed to be wearing attire meant for gardening." << endl
		<< "\nShe asked him what he was doing there, and out of his mouth came some broken english, \"I... do work... for bears.\" all while he gestured exaggeratedly." << endl
		<< "\nShe didn't want to fluster him any more than she already had, so she decided to calm him down and asked him where they were. He seemed to have no idea, \nto what she could gather, so she asked him if he'd show her around." << endl
		<< "\nHe seemed to understand every word she said, and affirmed accordingly before pointing to the door." << endl
		<< "\n\"I'd like to see the garage, please. I want to see what kind of cars bears would drive.\" she smirked. Agreeing excitedly, he led her to the garage, \nbefore opening it to reveal three cars in the dark.\n He fumbled for the lights, and as they came on, three Nissans distinctly lay before her."
		<< "\nRaising an eyebrow, she examined the cars from a distance.One was blue, another, a deep red, and the final one was caked in dust." << endl
		<< "\n\"Nissans, huh. That's not what I would have expected. But then again, what other bears do I know who can drive.\" she thought to herself."
		<< "\nThe number plates seemed slightly faded, but there were things distinctly written on them." << endl
		<< "\n\"Do they have names?\" she shot in the dark, not knowing how else to ask what they said without being awkward. \"Yes! Name... I name cars... bear ask me... give name\" the man's \nenthusiasm and pride knew no bound now, she could see." << endl
		<< "\n\"Oh really, what are they called?\"" << endl
		<< "\n\"They are... uh... number... like 1... 2... 3...\"" << endl
		<< "\n\"One, Two, and Three?\" she pointed at the blue, red, and dusty one from right to left." << endl
		<< "\n\"Oh no! No... Japanese numbers... icchi... nii... san...\"" << endl
		<< "\n\"So, Icchi, Nii, and San then?\"" << endl
		<< "\n\"No! No. Number like... Icchi... Icchi Ni...\"" << endl
		<< "\n\"So, one, one two, and one two three. Huh. Nice.\" she cut him off, feeling like the conversation was getting a tad bit repetitive." << endl
		<< "\nShe walked closer to the cars, noticing how each one was decorated to fit a designated driver." << endl
		<< "\nThe red car was definitely Daddy Bear's, with all that flannel and the axes in the back seat." << endl
		<< "\nBaby Bear's car was the blue one, completely modded to be as loud as possible. The tacky fuzzy dice didn't help." << endl
		<< "\n\"Why's this one covered in dust? Hasn't been used in a bit, huh.\" she saw what seemed to be Mama Bear's car." << endl
		<< "\n\"Oh, that car bad car. Car have insect.\" he said, concerned." << endl
		<< "\n\"Insects? Ew. What kind of insects?\"" << endl
		<< "\n\"Small... black... bite. Uh.... flea! Yes, flea!\"" << endl
		<< "\n\"Fleas? How bad could it possibly be that you don't use a car again?\" she whispered to herself. \"Couldn't you get it cleaned?\"" << endl
		<< "\n\"I try. Mama Bear say no. Say that name fit now.\"" << endl
		<< "\n\"The name fits now? How?\"" << endl
		<< "\n\"That car, called Icchi Ni San.\"\n" << endl;
};
void clear_screen()
{
for(int i=0;i<23;i++)
    cout << endl;
}
void Dice::lotsOSlots()
{
  if(piper.size() != 9)
      return;
    int bet, winnings = 0; char again = 'y';
    while(again == 'y')
    {
        cout << "\nwager : ";
        cin >> bet;
		cout << endl;
        int n1, n2, n3;
        for(int i = 0; i < 75; i++)
        {
            if (i < 35) n1 = roll();
			if (i < 55) n2 = roll();
			n3 = roll();
            clear_screen();
			cout << "|" << n1 << "| |" << n2 << "| |" << n3 << "|" << endl;
        }
        if(n1 == 7 && n2 == 7 && n3 == 7)
        {
            cout << "\n*****\n****\n***\n**\n*JACKPOT!\n**\n***\n****\n*****";
            winnings += bet * 4;
        }
        else if(n1 == n2 == n3)//can i do this
        {
            cout << "\nCongratulations! You win!" << endl;
            winnings += bet * 3;
        }
        else if(n1 == n2 || n2 == n3 || n1 == n3)
        {
            cout << "\n(something funny and cheerful) here's your money back, plus a dollar." << endl;
            winnings += bet + 1;
        }
        else
        {
            cout << "\nyou failed." << endl;
            winnings -= bet;
        }
        cout << "\n**********\ncurrent winnings : " << winnings << "\n**********" << endl;
        cout << "would you like to play again? (y/n) " << endl;
        cin >> again;
    }
    cout << "\n\n\nYou achieved a GRAND total of " << winnings << " dollars. nice" << endl;
};
void Dice::lotsOSlots(int wager, int timesRun)
{
  if(piper.size() != 9)
      return;
    int count = 0, winnings = 0;
    for(int i = 0; i < timesRun; i++)
    {
        int n1 = roll(), n2 = roll(), n3 = roll();
        if(n1 == 7 && n2 == 7 && n3 == 7)
        {
            count++;
            winnings += wager * 4;
        }
        else if(n1 == n2 == n3)//can i do this
        {
            count++;
            winnings += wager * 3;
        }
        else if(n1 == n2 || n2 == n3 || n1 == n3)
            winnings += wager + 1;
        else
            winnings -= wager;
    }
    cout << "\ntriplets : " << count << endl;
    cout << "\n\n\nYou achieved a GRAND total of " << winnings << " dollars. nice\n" << endl;
};
