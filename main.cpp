
#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>

const double CHAR_COUNT_MULTIPLIER = 2.75; //2.75
const double LONGEST_WORD_MULTIPLIER = 1.25; //1.25
const int MAX_SIZE_WORD_SEARCH = 500; //1000
const int MAX_SIZE_WORD_LIST = 100; //200
const int NUMBER_OF_ORIENTATIONS = 12;
const int MIN_SIZE_ARRAY = 1;

void message(std::string message);
void message(std::string message1, int number, std::string message2);
void message(std::string message1, std::string message2);
int getInput();
std::string getInputString();
char getInputChar();
void chooseMenuOption(int option);
void wordSearchProgramMenu();
void newPuzzleProgram();
void addWordsToArray(std::string words[], int numberOfWords);
int charCountLongestWordf(std::string words[], int numberOfWords);
int charCountAllWordsf(std::string words[], int numberOfWords);
int calculateWordSearchSideLength(int longestWord, int charCount);
int randomNumberGenerator(int range, int adjustment);
char randomLetterGenerator(int number);
void putAsterisksInWordSearch(char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength);
void putRandomLettersInWordSearch(char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength);
void displayWordSearch(const char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, std::string words[], int numberOfWords);
void assignPosition(int sideLength, int& row, int& column);
void canWordBePlacedAtPosition(int orientation[], bool& positionLegal);
void resetElementsInOrientationArray(int orientation[]);
void checkForwardHorizontal(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, int row, int column, int orientation[]);
void checkForwardVertical(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, int row, int column, int orientation[]);
void checkForwardDiagonalLowerLToUpperR(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, int row, int column, int orientation[]);
void checkForwardDiagonalUpperLToLowerR(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, int row, int column, int orientation[]);
void checkBackwardHorizontal(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column, int orientation[]);
void checkBackwardVertical(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column, int orientation[]);
void checkBackwardDiagonalLowerRToUpperL(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column, int orientation[]);
void checkBackwardDiagonalUpperRToLowerL(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, int row, int column, int orientation[]);
void checkAllOrientations(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, int row, int column, int orientation[]);
void assignOrientation(int orientation[], int& orientationValue);
void putWordsInWordSearch(int orientationValue, std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column);
void putForwardHorizontal(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column);
void putForwardVertical(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column);
void putForwardDiagonalLowerLToUpperR(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column);
void putForwardDiagonalUpperLToLowerR(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column);
void putBackwardHorizontal(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column);
void putBackwardVertical(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column);
void putBackwardDiagonalLowerRToUpperL(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column);
void putBackwardDiagonalUpperRToLowerL(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column);
void openWordSearch(std::ofstream& fout, std::string filename);
void openWordSearch(std::ifstream& fin, std::string filename);
void saveWordSearch(char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, std::string words[], int numberOfWords);
void openWordSearchFromUserFilename(std::ifstream& fin);
void displayWordSearch(std::ifstream& fin);
void closeFile(std::ifstream& fin);
void openAndDisplayWordSearch();
void countColumnsInWordSearchFile(std::ifstream& fin, int& columns);
void writeWordSearchGridInFileToArray(std::ifstream& fin, char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], int columns, int& words);
void writeWordsInFileToArray(std::ifstream& fin, std::string wordSearchWordList[MAX_SIZE_WORD_SEARCH], int columns);


void checkForwardHorizontal(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH]);
void checkForwardVertical(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH]);
void checkForwardDiagonalLowerLToUpperR(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH]);
void checkForwardDiagonalUpperLToLowerR(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH]);
void checkBackwardHorizontal(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH]);
void checkBackwardVertical(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH]);
void checkBackwardDiagonalLowerRToUpperL(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH]);
void checkBackwardDiagonalUpperRToLowerL(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH]);



void checkAllOrientations(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH]);


void solveWordSearchFromFile();



int main() {
    wordSearchProgramMenu();

    return 0;
}

void message(std::string message)
{
    std::cout << std::endl << message << std::endl;
}

void message(std::string message1, std::string message2)
{
    std::cout << std::endl << message1 << message2 << std::endl;
}

void message(std::string message1, int number, std::string message2)
{
    std::cout << message1 << number << message2 << std::endl;
}



int getInput()
{
    int input;
    std::cin >> input;
    return input;
}

std::string getInputString()
{
    std::string input;
    std::cin >> input;
    return input;
}

char getInputChar()
{
    char input;
    std::cin >> input;
    return input;
}

void chooseMenuOption(int option)
{
    switch(option)
    {
        case 1:
            newPuzzleProgram();
            break;
        case 2:
            openAndDisplayWordSearch();
            break;
        case 3:
            solveWordSearchFromFile();
            break;
        case 4: // exit
            exit;

    }

}
void wordSearchProgramMenu()
{
    int choice;
    message("Choose an option:");
    message("(1) Create a new puzzle");
    message("(2) Open an existing puzzle");
    message("(3) Solve an existing puzzle");
    message("(4) Exit");

    choice = getInput();
    chooseMenuOption(choice);
}

void newPuzzleProgram()
{
    srand(time(nullptr));
    int numberOfWords, charCountLongestWord, charCountAllWords, sideLength, row, column, orientation[NUMBER_OF_ORIENTATIONS], orientationValue;
    char save;

    message("How many words would you like to include?");
    numberOfWords = getInput();
    std::string words[numberOfWords]; // should this be its own function? Like a create array function? Not sure it needs to be.

    addWordsToArray(words, numberOfWords);
    charCountLongestWord = charCountLongestWordf(words, numberOfWords);
    charCountAllWords = charCountAllWordsf(words, numberOfWords);
    sideLength = calculateWordSearchSideLength(charCountLongestWord, charCountAllWords);

    char wordSearch[sideLength][MAX_SIZE_WORD_SEARCH];

    putAsterisksInWordSearch(wordSearch, sideLength);
    resetElementsInOrientationArray(orientation);

    for(int i = 0; i < numberOfWords; i++)
    {
        bool positionIsLegal = false;
        while(positionIsLegal == false)
        {
            assignPosition(sideLength, row, column);
            checkAllOrientations(words, i, wordSearch, sideLength, row, column, orientation);
            canWordBePlacedAtPosition(orientation, positionIsLegal);
        }
        assignOrientation(orientation, orientationValue);
        putWordsInWordSearch(orientationValue, words, i, wordSearch, row, column);
        resetElementsInOrientationArray(orientation);
    }
//    displayWordSearch(wordSearch, sideLength, words, numberOfWords); // Will need to delete this line.
    putRandomLettersInWordSearch(wordSearch, sideLength);
    std::cout << std::endl << std:: endl;
    displayWordSearch(wordSearch, sideLength, words, numberOfWords);

    message("Would you like to save this puzzle? Y/N");
    save = getInputChar();
    if(toupper(save) == 'Y')
    {
        saveWordSearch(wordSearch, sideLength, words, numberOfWords);
        wordSearchProgramMenu();
    }
    else
        wordSearchProgramMenu();

}

void addWordsToArray(std::string words[], int numberOfWords)
{
    for(int i = 0; i < numberOfWords; i++)
    {
        message("Please enter word ", i + 1, ":");
        words[i] = getInputString();
    }
}

int charCountLongestWordf(std::string words[], int numberOfWords)
{
    int longestWord = 0;
    for(int i = 0; i < numberOfWords; i++)
    {
        if(longestWord < words[i].length())
            longestWord = words[i].length();
    }
    return longestWord;
}

int charCountAllWordsf(std::string words[], int numberOfWords)
{
    int charCount = 0;
    for(int i = 0; i < numberOfWords; i++)
        charCount += words[i].length();

    return charCount;
}

int calculateWordSearchSideLength(int longestWord, int charCount)
{
    int minSideLengthLongestWord = ceil(LONGEST_WORD_MULTIPLIER * longestWord);
    int capacity = CHAR_COUNT_MULTIPLIER * charCount;
    int minSideLengthCapacity = ceil(sqrt(capacity));
    if(minSideLengthLongestWord > minSideLengthCapacity)
        return minSideLengthLongestWord;
    else
        return minSideLengthCapacity;

}

int randomNumberGenerator(int range, int adjustment)
{
    int randomNumber = (rand() % range) + adjustment;
    return randomNumber;
}

char randomLetterGenerator(int number)
{
    switch(number)
    {
        case 1:
            return 'A';
        case 2:
            return 'B';
        case 3:
            return 'C';
        case 4:
            return 'D';
        case 5:
            return 'E';
        case 6:
            return 'F';
        case 7:
            return 'G';
        case 8:
            return 'H';
        case 9:
            return 'I';
        case 10:
            return 'J';
        case 11:
            return 'K';
        case 12:
            return 'L';
        case 13:
            return 'M';
        case 14:
            return 'N';
        case 15:
            return 'O';
        case 16:
            return 'P';
        case 17:
            return 'Q';
        case 18:
            return 'R';
        case 19:
            return 'S';
        case 20:
            return 'T';
        case 21:
            return 'U';
        case 22:
            return 'V';
        case 23:
            return 'W';
        case 24:
            return 'X';
        case 25:
            return 'Y';
        case 26:
            return 'Z';
    }
}

void putAsterisksInWordSearch(char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength)
{

    for(int i = 0; i < sideLength; i++)
        for(int j = 0; j < sideLength; j++)
        {
            wordSearch[i][j] = '*';
        }
}

void putRandomLettersInWordSearch(char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength)
{
    int number;
    for(int i = 0; i < sideLength; i++)
        for(int j = 0; j < sideLength; j++)
        {
            if(wordSearch[i][j] == '*')
            {
                number = randomNumberGenerator(26, 1);
                wordSearch[i][j] = randomLetterGenerator(number);
            }
        }
}

void displayWordSearch(const char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, std::string words[], int numberOfWords)
{
    int i, j;
    for(i = 0; i < sideLength; i++)
    {
        for (j = 0; j < sideLength; j++)
        {
            std::cout << wordSearch[i][j] << " ";
        }
        if(j == sideLength)
            std::cout << std::endl;
    }

    std::cout << std::endl;

    for(int i = 0; i < numberOfWords; i++)
    {
        for (int j = 0; j < words[i].length(); j++)
        {
            char letter = toupper(words[i][j]);
            std::cout << letter;
        }
        std::cout << std::endl;
    }

}

void assignPosition(int sideLength, int& row, int& column)
{
    row = randomNumberGenerator(sideLength, 0);
    column = randomNumberGenerator(sideLength, 0);
}

void canWordBePlacedAtPosition(int orientation[], bool& positionLegal)
{
    int count = 0;
    for(int i = 0; i < NUMBER_OF_ORIENTATIONS; i++)
        if(orientation[i] != -1)
            count++;
    if(count > 0)
        positionLegal = true;
    else
        positionLegal = false;
}

void resetElementsInOrientationArray(int orientation[])
{
    for(int i = 0; i < NUMBER_OF_ORIENTATIONS; i++)
        orientation[i] = -1;
}

void checkForwardHorizontal(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, int row, int column, int orientation[])
{
    int count = 0;
    if(column + (words[index].length() - 1) <= sideLength)
    {
        for(int n = 0; n < words[index].length(); n++)
        {
            if(wordSearch[row][column] == '*' || wordSearch[row][column] == words[index][n])
                count++;
            column++;
        }


        if(count == words[index].length())
        {
            orientation[0] = 0;
            orientation[1] = 1;
        }
    }
}

void checkForwardVertical(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, int row, int column, int orientation[])
{
    int count = 0;
    if(row + (words[index].length() - 1) <= sideLength)
    {
        for(int n = 0; n < words[index].length(); n++)
        {
            if(wordSearch[row][column] == '*' || wordSearch[row][column] == words[index][n])
                count++;
            row++;
        }

        if(count == words[index].length())
        {
            orientation[2] = 2;
            orientation[3] = 3;
        }
    }
}

void checkForwardDiagonalLowerLToUpperR(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, int row, int column, int orientation[])
{
    int count = 0;
    if(row - (words[index].length() - 1) >= 0 && column + (words[index].length() - 1) <= sideLength)
    {
        for(int n = 0; n < words[index].length(); n++)
        {
            if(wordSearch[row][column] == '*' || wordSearch[row][column] == words[index][n])
                count++;
            row--;
            column++;
        }

        if(count == words[index].length())
        {
            orientation[4] = 4;
            orientation[5] = 5;
        }
    }
}

void checkForwardDiagonalUpperLToLowerR(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, int row, int column, int orientation[])
{
    int count = 0;
    if(row + (words[index].length() - 1) <= sideLength && column + (words[index].length() - 1) <= sideLength)
    {
        for(int n = 0; n < words[index].length(); n++)
        {
            if(wordSearch[row][column] == '*' || wordSearch[row][column] == words[index][n])
                count++;
            row++;
            column++;
        }

        if(count == words[index].length())
        {
            orientation[6] = 6;
            orientation[7] = 7;
        }
    }
}

void checkBackwardHorizontal(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column, int orientation[])
{
    int count = 0;
    if(column - (words[index].length() - 1) >= 0)
    {
        for(int n = 0; n < words[index].length(); n++)
        {
            if(wordSearch[row][column] == '*' || wordSearch[row][column] == words[index][n])
                count++;
            column--;
        }

        if(count == words[index].length())
        {
            orientation[8] = 8;
        }
    }
}

void checkBackwardVertical(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column, int orientation[])
{
    int count = 0;
    if(row - (words[index].length() - 1) >= 0)
    {
        for(int n = 0; n < words[index].length(); n++)
        {
            if(wordSearch[row][column] == '*' || wordSearch[row][column] == words[index][n])
                count++;
            row--;
        }

        if(count == words[index].length())
            orientation[9] = 9;
    }
}

void checkBackwardDiagonalLowerRToUpperL(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column, int orientation[])
{
    int count = 0;
    if(row - (words[index].length() - 1) >= 0 && column - (words[index].length() - 1) >= 0)
    {
        for(int n = 0; n < words[index].length(); n++)
        {
            if(wordSearch[row][column] == '*' || wordSearch[row][column] == words[index][n])
                count++;
            row--;
            column--;
        }

        if(count == words[index].length())
        {
            orientation[10] = 10;
        }
    }
}

void checkBackwardDiagonalUpperRToLowerL(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, int row, int column, int orientation[])
{
    int count = 0;
    if(row + (words[index].length() - 1) <= sideLength && column - (words[index].length() - 1) >= 0)
    {
        for(int n = 0; n < words[index].length(); n++)
        {
            if(wordSearch[row][column] == '*' || wordSearch[row][column] == words[index][n])
                count++;
            row++;
            column--;
        }

        if(count == words[index].length())
        {
            orientation[11] = 11;
        }
    }
}

void checkAllOrientations(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, int row, int column, int orientation[])
{
    checkForwardHorizontal(words, index, wordSearch, sideLength, row, column, orientation);
    checkForwardVertical(words, index, wordSearch, sideLength, row, column, orientation);
    checkForwardDiagonalLowerLToUpperR(words, index, wordSearch, sideLength, row, column, orientation);
    checkForwardDiagonalUpperLToLowerR(words, index, wordSearch, sideLength, row, column, orientation);
    checkBackwardHorizontal(words, index, wordSearch, row, column, orientation);
    checkBackwardVertical(words, index, wordSearch, row, column, orientation);
    checkBackwardDiagonalLowerRToUpperL(words, index, wordSearch, row, column, orientation);
    checkBackwardDiagonalUpperRToLowerL(words, index, wordSearch, sideLength, row, column, orientation);
}

void assignOrientation(int orientation[], int& orientationValue)
{
    int count = 0;
    while(count == 0)
    {
        orientationValue = randomNumberGenerator(12, 0);
        for(int i = 0; i < NUMBER_OF_ORIENTATIONS; i++)
            if(orientation[i] == orientationValue)
                count++;
    }
}

void putWordsInWordSearch(int orientationValue, std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column)
{
    switch(orientationValue)
    {
        case 0:
        case 1:
            putForwardHorizontal(words, index, wordSearch, row, column);
            break;
        case 2:
        case 3:
            putForwardVertical(words, index, wordSearch, row, column);
            break;
        case 4:
        case 5:
            putForwardDiagonalLowerLToUpperR(words, index, wordSearch, row, column);
            break;
        case 6:
        case 7:
            putForwardDiagonalUpperLToLowerR(words, index, wordSearch, row, column);
            break;
        case 8:
            putBackwardHorizontal(words, index, wordSearch, row, column);
            break;
        case 9:
            putBackwardVertical(words, index, wordSearch, row, column);
            break;
        case 10:
            putBackwardDiagonalLowerRToUpperL(words, index, wordSearch, row, column);
            break;
        case 11:
            putBackwardDiagonalUpperRToLowerL(words, index, wordSearch, row, column);
            break;
    }
}

void putForwardHorizontal(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column)
{
    int n = 0;
    while(n < words[index].length())
    {
        wordSearch[row][column] = toupper(words[index][n]);
        column++;
        n++;
    }
}

void putForwardVertical(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column)
{
    int n = 0;
    while(n < words[index].length())
    {
        wordSearch[row][column] = toupper(words[index][n]);
        row++;
        n++;
    }
}

void putForwardDiagonalLowerLToUpperR(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column)
{
    int n = 0;
    while(n < words[index].length())
    {
        wordSearch[row][column] = toupper(words[index][n]);
        row--;
        column++;
        n++;
    }
}

void putForwardDiagonalUpperLToLowerR(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column)
{
    int n = 0;
    while(n < words[index].length())
    {
        wordSearch[row][column] = toupper(words[index][n]);
        row++;
        column++;
        n++;
    }
}

void putBackwardHorizontal(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column)
{
    int n = 0;
    while(n < words[index].length())
    {
        wordSearch[row][column] = toupper(words[index][n]);
        column--;
        n++;
    }
}

void putBackwardVertical(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column)
{
    int n = 0;
    while(n < words[index].length())
    {
        wordSearch[row][column] = toupper(words[index][n]);
        row--;
        n++;
    }
}

void putBackwardDiagonalLowerRToUpperL(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column)
{
    int n = 0;
    while(n < words[index].length())
    {
        wordSearch[row][column] = toupper(words[index][n]);
        row--;
        column--;
        n++;
    }
}

void putBackwardDiagonalUpperRToLowerL(std::string words[], int index, char wordSearch[][MAX_SIZE_WORD_SEARCH], int row, int column)
{
    int n = 0;
    while(n < words[index].length())
    {
        wordSearch[row][column] = toupper(words[index][n]);
        row++;
        column--;
        n++;
    }
}

void openWordSearch(std::ofstream& fout, std::string filename)
{
    fout.open(filename);
    if(fout.fail())
    {
        std::cout << "Output file opening failed.\n";
        exit(1);
    }
}

void openWordSearch(std::ifstream& fin, std::string filename)
{
    fin.open(filename);
    if(fin.fail())
    {
        std::cout << "Input file opening failed.\n";
        exit(2);
    }
}

void saveWordSearch(char wordSearch[][MAX_SIZE_WORD_SEARCH], int sideLength, std::string words[], int numberOfWords)
{
    std::ofstream fout;
    std::string filename;
    message("Please enter filename: ");
    filename = getInputString();
    openWordSearch(fout, filename);

    int i, j;
    for(i = 0; i < sideLength; i++)
    {
        for (j = 0; j < sideLength; j++)
        {
            fout << wordSearch[i][j] << " ";
        }
        if(j == sideLength)
            fout << std::endl;
    }

    fout << std::endl;

    for(int i = 0; i < numberOfWords; i++)
    {
        for (int j = 0; j < words[i].length(); j++)
        {
            char letter = toupper(words[i][j]);
            fout << letter;
        }
        fout << std::endl;
    }
    message(filename, " successfully saved.");

}

void openWordSearchFromUserFilename(std::ifstream& fin)
{
    std::string filename;
    message("Please enter filename: ");
    filename = getInputString();
    openWordSearch(fin, filename);
}

void displayWordSearch(std::ifstream& fin)
{
    char symbol;

    std::cout << std::endl;
    while(!fin.eof())
    {
        fin.get(symbol);
        std::cout << symbol;
    }
}

void closeFile(std::ifstream& fin)
{
    fin.close();
}

void openAndDisplayWordSearch()
{
    std::ifstream fin;
    openWordSearchFromUserFilename(fin);
    displayWordSearch(fin);
    closeFile(fin);
    wordSearchProgramMenu();
}

void countColumnsInWordSearchFile(std::ifstream& fin, int& columns)
{
    char symbol;

    do{
        fin.get(symbol);
        if(symbol != ' ' && symbol != '\n')
            columns++;
    } while(symbol != '\n');
}

void writeWordSearchGridInFileToArray(std::ifstream& fin, char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], int columns, int& words)
{
    int rows = 0, j = 0;
    char symbol, gettingRidOfNewLines[MIN_SIZE_ARRAY][MIN_SIZE_ARRAY], gettingRidOfSpaces[MIN_SIZE_ARRAY][MIN_SIZE_ARRAY];
    while(!fin.eof())
    {
        while(rows <= columns)
        {
            fin.get(symbol);
            if(symbol == '\n')
            {
                gettingRidOfNewLines[0][0] = symbol;
                j = 0;
                rows++;
            }
            else if(symbol == ' ')
                gettingRidOfSpaces[0][0] = symbol;
            else
            {
                wordSearchFromFile[rows][j] = symbol;
                j++;
            }
        }
        fin.get(symbol);
        if(symbol == '\n')       //counts number of words in list. Should this be its own function?
            words++;

    }
}

void writeWordsInFileToArray(std::ifstream& fin, std::string wordSearchWordList[MAX_SIZE_WORD_SEARCH], int columns)
{
    char symbol;
    int rows = 0, i = 0;
    std::string next;
    while(rows <= columns)
    {
        fin.get(symbol);
        if(symbol == '\n')
            rows++;
    }

    while(fin >> next)
    {
        wordSearchWordList[i] = next;
        i++;
    }
}

void checkForwardHorizontal(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH])
{
    int i = 0, j = 0, n = 0, m = 0;

    while(i < columns && j < columns && n <= words && m < wordSearchWordList[n].length())
    {
        if(wordSearchFromFile[i][j] == wordSearchWordList[n][m] && (j - m + (wordSearchWordList[n].length() - 1) <= columns))
        {
            {
                j++; // increase column by 1
                m++; // increase character in word by 1
            }
        }

        else
        {
            j = j - m + 1; // reset column to the next one starting j
            m = 0; // reset character in word to 0
        }

        if(m == wordSearchWordList[n].length() - 1)
        {
            for(int x = 0; x < wordSearchWordList[n].length(); x++)
            {
                wordSearchSolution[i][j] = wordSearchFromFile[i][j];
                j--;
            }
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }

        if(i == columns - 1 && j == columns)
        {
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }

        if(j == columns)
        {
            i++; // increase row by 1;
            j = 0; // reset column to 0;
        }
    }
}

void checkForwardHorizontal2(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH])
{
    int i = 0, j = 0, n = 0, m = 0;



}

void checkForwardVertical(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH])
{
    int i = 0, j = 0, n = 0, m = 0;

    while(i < columns && j < columns && n <= words && m < wordSearchWordList[n].length())
    {
        if(wordSearchFromFile[i][j] == wordSearchWordList[n][m] && (i - m + (wordSearchWordList[n].length() - 1) <= columns))
        {
            {
                i++; // increase row by 1
                m++; // increase word character by 1
            }
        }

        else
        {
            j++; // increase column by 1
            i -= m; // reset row
            m = 0; // reset word character to 0
        }

        if(m == wordSearchWordList[n].length() - 1)
        {
            for(int x = 0; x < wordSearchWordList[n].length(); x++)
            {
                wordSearchSolution[i][j] = wordSearchFromFile[i][j];
                i--;
            }
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }

        if(i == columns - 1 && j == columns)
        {
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }

        if(j == columns)
        {
            i++; // increase row by 1;
            j = 0; // reset column to 0;
        }
    }
}

void checkForwardDiagonalLowerLToUpperR(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH])
{
    int i = 0, j = 0, n = 0, m = 0;

    while(i < columns && j < columns && n <= words && m < wordSearchWordList[n].length())
    {

        if(wordSearchFromFile[i][j] == wordSearchWordList[n][m] && (i + m - (wordSearchWordList[n].length() - 1) >= 0 && j - m + (wordSearchWordList[n].length() - 1) <= columns))
        {
            i--; // decrease row by 1
            j++; // increase column by 1
            m++; // increase word character by 1
        }

        else
        {
            i += m; // reset row
            j = j - m + 1; // reset column
            m = 0; // reset word character to 0
        }

        if(i == columns - 1 && j == columns)
        {
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }

        if(j == columns)
        {
            i++; // increase row by 1;
            j = 0; // reset column to 0;
        }

        if(m == wordSearchWordList[n].length() - 1)
        {
            for(int x = 0; x < wordSearchWordList[n].length(); x++)
            {
                wordSearchSolution[i][j] = wordSearchFromFile[i][j];
                i++;
                j--;
            }
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }
    }
}

void checkForwardDiagonalUpperLToLowerR(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH])
{
    int i = 0, j = 0, n = 0, m = 0;

    while(i < columns && j < columns && n <= words && m < wordSearchWordList[n].length())
    {
        if(wordSearchFromFile[i][j] == wordSearchWordList[n][m] && (i - m + (wordSearchWordList[n].length() - 1) <= columns && j - m + (wordSearchWordList[n].length() - 1) <= columns))
        {
            i++; // increase row by 1
            j++; // increase column by 1
            m++; // increase word character by 1
        }

        else
        {
            i -= m; // reset row
            j = j - m + 1; // reset column
            m = 0; // reset word character to 0
        }

        if(i == columns - 1 && j == columns)
        {
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }

        if(j == columns)
        {
            i++; // increase row by 1;
            j = 0; // reset column to 0;
        }

        if(m == wordSearchWordList[n].length() - 1)
        {
            for(int x = 0; x < wordSearchWordList[n].length(); x++)
            {
                wordSearchSolution[i][j] = wordSearchFromFile[i][j];
                i--;
                j--;
            }
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }
    }
}

void checkBackwardHorizontal(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH])
{
    int i = 0, j = 0, n = 0, m = 0;

    while(i < columns && j < columns && n <= words && m < wordSearchWordList[n].length())
    {
        if(wordSearchFromFile[i][j] == wordSearchWordList[n][m] && j + m - (wordSearchWordList[n].length() - 1) >= 0)
        {
            j--; // decrease column by 1
            m++; // increase word character by 1
        }

        else
        {
            j = j + m + 1; // reset column
            m = 0; // reset word character to 0
        }

        if(i == columns - 1 && j == columns)
        {
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }

        if(j == columns)
        {
            i++; // increase row by 1;
            j = 0; // reset column to 0;
        }

        if(m == wordSearchWordList[n].length() - 1)
        {
            for(int x = 0; x < wordSearchWordList[n].length(); x++)
            {
                wordSearchSolution[i][j] = wordSearchFromFile[i][j];
                j++;
            }
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }
    }
}

void checkBackwardVertical(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH])
{
    int i = 0, j = 0, n = 0, m = 0;

    while(i < columns && j < columns && n <= words && m < wordSearchWordList[n].length())
    {
        if(wordSearchFromFile[i][j] == wordSearchWordList[n][m] && i + m - (wordSearchWordList[n].length() - 1) >= 0)
        {
            i--; // decrease row by 1
            m++; // increase word character by 1
        }

        else
        {
            i += m; // reset row
            j++; // increase column
            m = 0; // reset word character to 0
        }

        if(i == columns - 1 && j == columns)
        {
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }

        if(j == columns)
        {
            i++; // increase row by 1;
            j = 0; // reset column to 0;
        }

        if(m == wordSearchWordList[n].length() - 1)
        {
            for(int x = 0; x < wordSearchWordList[n].length(); x++)
            {
                wordSearchSolution[i][j] = wordSearchFromFile[i][j];
                i++;
            }
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }
    }
}

void checkBackwardDiagonalLowerRToUpperL(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH])
{
    int i = 0, j = 0, n = 0, m = 0;

    while(i < columns && j < columns && n <= words && m < wordSearchWordList[n].length())
    {
        if(wordSearchFromFile[i][j] == wordSearchWordList[n][m] && (i + m - (wordSearchWordList[n].length() - 1) >= 0 && j + m - (wordSearchWordList[n].length() - 1) >= 0))
        {
            i--; // decrease row by 1
            j--; // decrease column by 1
            m++; // increase word character by 1
        }

        else
        {
            i += m; // reset row
            j = j + m + 1; // reset column and add 1
            m = 0; // reset word character to 0
        }

        if(i == columns - 1 && j == columns)
        {
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }

        if(j == columns)
        {
            i++; // increase row by 1;
            j = 0; // reset column to 0;
        }

        if(m == wordSearchWordList[n].length() - 1)
        {
            for(int x = 0; x < wordSearchWordList[n].length(); x++)
            {
                wordSearchSolution[i][j] = wordSearchFromFile[i][j];
                i++;
                j++;
            }
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }
    }
}

void checkBackwardDiagonalUpperRToLowerL(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH])
{
    int i = 0, j = 0, n = 0, m = 0;

    while(i < columns && j < columns && n <= words && m < wordSearchWordList[n].length())
    {
        if(wordSearchFromFile[i][j] == wordSearchWordList[n][m] && (i - m + (wordSearchWordList[n].length() - 1) <= columns && j + m - (wordSearchWordList[n].length() - 1) >= 0))
        {
            i++; // increase row by 1
            j--; // decrease column by 1
            m++; // increase word character by 1
        }

        else
        {
            i -= m; // reset row
            j = j + m + 1; // reset column and add 1
            m = 0; // reset word character to 0
        }

        if(i == columns - 1 && j == columns)
        {
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }

        if(j == columns)
        {
            i++; // increase row by 1;
            j = 0; // reset column to 0;
        }

        if(m == wordSearchWordList[n].length() - 1)
        {
            for(int x = 0; x < wordSearchWordList[n].length(); x++)
            {
                wordSearchSolution[i][j] = wordSearchFromFile[i][j];
                i--;
                j++;
            }
            n++; // move on to the next word
            i = 0; // reset row
            j = 0; // reset column
            m = 0; // reset word character to 0
        }
    }
}

void checkAllOrientations(char wordSearchFromFile[][MAX_SIZE_WORD_SEARCH], std::string wordSearchWordList[MAX_SIZE_WORD_LIST], int words, int columns, char wordSearchSolution[][MAX_SIZE_WORD_SEARCH])
{
    checkForwardHorizontal(wordSearchFromFile, wordSearchWordList, words, columns, wordSearchSolution);
    checkForwardVertical(wordSearchFromFile, wordSearchWordList, words, columns, wordSearchSolution);
    checkForwardDiagonalLowerLToUpperR(wordSearchFromFile, wordSearchWordList, words, columns, wordSearchSolution);
    checkForwardDiagonalUpperLToLowerR(wordSearchFromFile, wordSearchWordList, words, columns, wordSearchSolution);
    checkBackwardHorizontal(wordSearchFromFile, wordSearchWordList, words, columns, wordSearchSolution);
    checkBackwardVertical(wordSearchFromFile, wordSearchWordList, words, columns, wordSearchSolution);
    checkBackwardDiagonalLowerRToUpperL(wordSearchFromFile, wordSearchWordList, words, columns, wordSearchSolution);
    checkBackwardDiagonalUpperRToLowerL(wordSearchFromFile, wordSearchWordList, words, columns, wordSearchSolution);
}

void solveWordSearchFromFile()
{
    int i = 0, j = 0, columns = 0, rows = 0, words = -1;
    std::ifstream fin;
    std::string filename, next, wordSearchWordList[MAX_SIZE_WORD_LIST];
    char symbol, wordSearchFromFile[MAX_SIZE_WORD_SEARCH][MAX_SIZE_WORD_SEARCH], wordSearchSolution[MAX_SIZE_WORD_SEARCH][MAX_SIZE_WORD_SEARCH];
    message("Please enter filename: ");
    filename = getInputString();

    openWordSearch(fin, filename);
    countColumnsInWordSearchFile(fin, columns);
    closeFile(fin);

    openWordSearch(fin, filename);
    writeWordSearchGridInFileToArray(fin, wordSearchFromFile, columns, words);
    closeFile(fin);

    openWordSearch(fin, filename);
    writeWordsInFileToArray(fin, wordSearchWordList, columns);
    closeFile(fin);

    putAsterisksInWordSearch(wordSearchSolution, columns);

    checkAllOrientations(wordSearchFromFile, wordSearchWordList, words, columns, wordSearchSolution);

    displayWordSearch(wordSearchSolution, columns, wordSearchWordList, words);

    wordSearchProgramMenu();
}
