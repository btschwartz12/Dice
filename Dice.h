//Dice headddededdededededee
//ben schwarztzt
//yesd

#pragma once
#include <vector>
#include <string>
using namespace std;


struct pip
{
    int age;
    int weight;
    string name;
//    piper(int a, int w, string s)
//    {
//        age = a;
//        weight = w;
//        name = s;
//    }
};
struct aiko
{
    int cuteness;
    int kills;
    string name;
//    aiko(int c, int k, string s)
//    {
//        cuteness = c;
//        kills = k;
//        name = s;
//    }
};
class Dice
{
public:
    Dice(int numSides);
    Dice(pip p, aiko a) { pips = p; aikoBoy = a; };
    int roll();
    int rollLikeTheDevil(int numRolls, bool upDown);
    bool blackJack();
    void gamblesAndGiggles();
    void lotsOSlots();
    void lotsOSlots(int wager, int timesRun);
    pip getPip() { return pips; };
    aiko getAiko() { return aikoBoy; };
    void setCuteness(int n) { aikoBoy.cuteness = n; };
private:
    vector<int> piper;
    pip pips;
    aiko aikoBoy;
    
};
class bjRoll
{
public:
    bool royal = false;
    int roll = 0;
    char cRoll = 'X';
    bjRoll(int iRoll);
};

