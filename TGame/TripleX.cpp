#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty)
{
    //Printing welcome messages
    cout << "\nYou're a secret agent trying to break into a level " << Difficulty;
    cout << " secret server room...\nYou need to enter correct code to continue...\n";
}

bool PlayGame(int Difficulty)
{

    PrintIntroduction(Difficulty);

    //rand() % Difficulty + 1 <-- This returns a random value between 0 and Difficulty
    int CodeA = rand() % Difficulty + 1 ; 
    int CodeB = rand() % Difficulty + 1 ;
    int CodeC = rand() % Difficulty + 1 ;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProd = CodeA * CodeB * CodeC;

    cout << "\n+ There are three numbers in the code\n";
    cout << "+ The codes add-up to: " << CodeSum;
    cout << "\n+ The product of codes is: " << CodeProd << "\n";

    // Store player guess
    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (CodeSum == GuessSum && CodeProd == GuessProduct)
    {
        cout << "\n*** Moving onto the next level ***\n";
        return true;
    }
    else
    {
        cout << "\n*** Retry the current level ***\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); //Creating new random sequence based on time of day
    
    const int MaxDifficulty = 10;
    int LevelDifficulty = 1;

    while ( LevelDifficulty <= MaxDifficulty ) // Loop game until all levels completed!
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();  //Clears any errors
        cin.ignore(); //Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    cout << "\n*** Congratulations! You're truly a master hacker ***\n";
    return 0;
}