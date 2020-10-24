#include <iostream>
#include <ctime>

void PlayIntroduction(int level) {
    std::cout << "\n\nYou're a secret agent breaking into a secure server room in level " << level << std::endl;
    std::cout << "You need to enter the correct codes to continue...\n";
}

bool PlayGame(int level) {
    PlayIntroduction(level);
    int CodeA = rand() % level + level;
    int CodeB = rand() % level + level;
    int CodeC = rand() % level + level;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "There are 3 numbers in the code...\n";
    std::cout << "The codes add-up to: " << CodeSum << std::endl;
    std::cout << "The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;

    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (CodeSum == GuessSum && CodeProduct == GuessProduct) { 
        std::cout << "Well done agent! You extract a file, kepp going!\n"; 
        return true;   
    }
    else { 
        std::cout << "Careful agent, wrong code try again!\n";
        return false;
    }
}

int main() 
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int MaxLevel = 10;

    while (LevelDifficulty <= MaxLevel) 
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "*** Well done agent! You hack the server! ";
    return 0;
}