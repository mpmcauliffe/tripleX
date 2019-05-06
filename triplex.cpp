
/**
 * Simple math game . . .
 *      if you get the wrong answer you die
 **/

#include <iostream>;
#include <ctime>;


void printIntro(int difficulty) {
    std::cout << "\n\nYou are a secret agent breaking into level " << difficulty << std::endl;
    std::cout << "Secure server room...\nEnter the correct code to continue...\n\n"; 
}


bool playGame(int difficulty) {
    printIntro(difficulty);

    const int codeA = rand() % difficulty + difficulty;
    const int codeB = rand() % difficulty + difficulty;
    const int codeC = rand() % difficulty + difficulty;

    const int codeSum = codeA + codeB + codeC;
    const int codeProduct = codeA * codeB * codeC;

    std::cout << "+ There are 3 numbers in the code\n" 
              << "+ The code adds up to " << codeSum << "\n"
              << "+ The codes multiply to " << codeProduct << std::endl;

    int guessA, guessB, guessC;
    std::cin >> guessA >> guessB >> guessC;

    int guessSum = guessA + guessB + guessC;
    int guessProduct = guessA * guessB * guessC;


    if (guessSum == codeSum && guessProduct == codeProduct) {
        std::cout << "\n *** Well done agent! You have extracted a file! keep going! ***";
        return true;
    } else {
        std::cout << "\n *** You are wrong so you died! Have fun in hell. ***";
        return false;
    }
}


int main() {
    srand(time(NULL));

    int levelDifficulty = 1;
    int const maxDifficulty = 5;

    while (levelDifficulty <= maxDifficulty) {
        bool isLevelComplete = playGame(levelDifficulty);

        std::cin.clear();
        std::cin.ignore();

        if (isLevelComplete) { ++levelDifficulty; }
    }

    std::cout << "\n *** Great work agent! You got all the files! ***" << std::endl;

    return 0;
}
