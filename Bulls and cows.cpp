#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<ctime>
#include "Bulls and Cows.h"
using namespace std;

void BullsandCows::InsertWords()
{
    wordsEasy.insert(wordsEasy.begin(),"slope");
    wordsEasy.insert(wordsEasy.begin(),"break");
    wordsEasy.insert(wordsEasy.begin(),"flight");
    wordsEasy.insert(wordsEasy.begin(),"relax");
    wordsEasy.insert(wordsEasy.begin(),"flame");
    wordsMedium.insert(wordsMedium.begin(),"bankruptcy");
    wordsMedium.insert(wordsMedium.begin(),"formidable");
    wordsMedium.insert(wordsMedium.begin(),"greyhounds");
    wordsMedium.insert(wordsMedium.begin(),"slumbering");
    wordsMedium.insert(wordsMedium.begin(),"judgmental");
    wordsMedium.insert(wordsMedium.begin(),"polycentrism");
    wordsHard.insert(wordsHard.begin(),"subordinately");
    wordsHard.insert(wordsHard.begin(),"documentarily");
    wordsHard.insert(wordsHard.begin(),"unmaledictory");
    wordsHard.insert(wordsHard.begin(),"hydromagnetics");
    wordsHard.insert(wordsHard.begin(),"ambidextrously");

}
void BullsandCows::UI()
{
    cout<<"Welcome to Bulls and Cows"<<"\n"<<"Please enter the difficulty number"<<"\n"<<"1) Easy"<<"\n"<<"2) Medium"<<"\n"<<"3) Hard"<<"\n";
    cin>>diffNumber; //THis is the input for difficulty number
    chooseDifficulty(diffNumber);
    cout<<"The isogram length is "<<word.size()<<"\n"<<"Please Enter your Isogram guess "<<"\n";
    cin>>guessWord;
    Input(guessWord);
}
void BullsandCows::chooseDifficulty(int diffNumber)
{
    if(diffNumber==1)
       { 
	   Random(diffNumber);
		return;
		} //Random words for difficulty 1
    else if(diffNumber==2)
       { 
	   Random(diffNumber);
		return;
		}  //Random words for difficulty 2
    else if(diffNumber==3)
        { 
	   Random(diffNumber);
		return;
		}  //Random words for difficulty 3
    else
        cout<<"Please enter a valid number"<<"\n";
        cin>>diffNumber;
        chooseDifficulty(diffNumber);
        return;
}
void BullsandCows::Random(int diffNumber)
{
    srand(time(NULL));
    if(diffNumber==1)
    {
        word=wordsEasy[rand()%wordsEasy.size()];//Choosing an easy word
        return;
    }
    else if(diffNumber==2)
    {
        word=wordsMedium[rand()%wordsMedium.size()];//Choosing a medium word
        return;
	}
    else if(diffNumber==3)
    {
        word=wordsHard[rand()%wordsHard.size()];//Choosing a hard word
        return;
	}
    else
        exit(0);
}
void BullsandCows::Input(string guessWord)
{
	if(guessWord.size()==word.size())//Comparing the size of the guess word and the actual word
    {
	Compare(guessWord);
	return;
	}
    else
    {
    cout<<"Enter a guess of the same size as that of the word to be guessed "<<"\n";
    cin>>guessWord;
    Input(guessWord);
    return;
	}
}
void BullsandCows::Compare(string guessWord)
{
	for(int j=0;j<guessWord.size();j++)
	{
		for(int k=0;k<guessWord.size();k++)
		{
			if(guessWord[j]==word[k] && j==k)
			{
			bulls++; //Increment Bulls
			break;
			}
			else if(guessWord[j]==word[k] && j!=k)
			{
			cows++;//Increment Cows
			break;
			}
		}		
	}
	Output();//THe function for displaying output
	if(bulls==word.size())
	return;
	else
	{
	tries++;
	cin>>guessWord;
	Input(guessWord);
	return;
	}
	if(tries==10)
	return;
	
}
void BullsandCows::Output()
{
	if(bulls==word.size())
	{
	cout<<"You won"<<"\n";
	return;
	}
	if(tries==10)
	{
	cout<<"You lost"<<"\n"<<"The word is "<<word<<"\n";
	return;
	}
	cout<<"Bulls : "<<bulls<<" Cows : "<<cows;
	cout<<"You have "<<10-tries<<" remaining"<<"\n";
	bulls=0;
	cows=0;
	return;
}
void BullsandCows::PlayGame()
{
	InsertWords();//The fuction for Inserting words
	UI();//The function for displaying the UI
	tries=0;
	bulls=0;
	cows=0;
	cout<<"Would you like to play again? "<<"\n"<<"If yes,press 1 else press any number "<<"\n";
	cin>>playAgain;
	if(playAgain==1)
	PlayGame();
	else
	exit(1);
}


int main()
{
	BullsandCows BC;
	BC.PlayGame();
	
}
