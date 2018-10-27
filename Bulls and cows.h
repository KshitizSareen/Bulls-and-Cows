#include<iostream>
#include<vector>
#include<string>
using namespace std;
#ifndef BULLA_AND_COWS_H_INCLUDED
#define BULLA_AND_COWS_H_INCLUDED

class BullsandCows{
    public:
    	void PlayGame();
        void UI();
        void Random(int diffNumber);
        void InsertWords();
        void chooseDifficulty(int diffNUmber);
        void Input(string guessWord);
        void Compare(string guessWord);
       	void Output();
    private:
        vector<string> wordsEasy;
        vector<string> wordsMedium;
        vector<string> wordsHard;
        string word;
        string guessWord;
        int diffNumber;
        int bulls=0,cows=0;
        int tries=0;
        int playAgain;

};


#endif // BULLA_AND_COWS_H_INCLUDED
