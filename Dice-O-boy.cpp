// Dice-O-boy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://docs.google.com/document/d/1fbzjFrFoBk8_dTZ0ruqXzXztXHU3Z5bRwgoz1Njffk4/edit


#include <iostream>
#include <iomanip>
#include "Dice.h"
//#include "Dice.cpp" // why do i have to do this
using namespace std;

int main()
{
//    aiko aikoStruct;
//    pip piperStruct;
//    aikoStruct.cuteness = 5;
//    piperStruct.age = 97;
//    piperStruct.weight = 97;
//    aikoStruct.kills = 102;
//    Dice d(piperStruct, aikoStruct);
//    d.setCuteness(9342);
    

    
    
    
    
    
    cout << "WELCOME TO THE DICE LOOPY Loop .?...";
    int choice = -11111;
    Dice d6(6);
    Dice d14(14);
    Dice d9(9);
    while(choice != 0){
        cout << "\n\nChoose from the following options (0 to exit) :" << endl
             << "1. roll" << endl
             << "2. rollLikeTheDevil" << endl
             << "3. blackjack" << endl
             << "4. gamblesAndGiggles" << endl
             << "5. lotsOSlots" << endl
			 << "6. lotsOSlots plus" << endl
        << "\nEnter your choice : ";
        cin >> choice;

        if(choice == 1)
            cout << "\nYou rolled a *" << d6.roll() << "*" << endl;
        else if (choice == 2)
        {
            int numRolls; bool upDown; char c;
            cout << "\n# rolls : ";
            cin >> numRolls;
            cout << "\nround up or down (u/d) : ";
            cin >> c;
            c == 'u' ? upDown = true : upDown = false;
            cout << "\nafter rolling " << numRolls << " times, a six was rolled " << d6.rollLikeTheDevil(numRolls, upDown) << "% of the time" << endl;
        }
        else if(choice == 3)
            d14.blackJack() ? cout << "\nWINININININININININ\n" : cout << "\n23neeshneeshneeshneeshneeshneeshneesh8u2ifhweknds;klc/;f;wjDLFJSDLKFSJADF\n";
        else if(choice == 4)
            d6.gamblesAndGiggles();
        else if(choice == 5)
            d9.lotsOSlots();
		else
		{
			int w, run;
			cout << "\nwager : " << endl;
			cin >> w;
			cout << "how many times to run : " << endl;
			cin >> run;
			d9.lotsOSlots(w, run);
		}







    }
    cout << "************************\n************************\n************************";
    
}
