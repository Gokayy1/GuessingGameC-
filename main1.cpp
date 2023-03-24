#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;


void playNumberGuessingGame();
void playAlphabetGuessingGame();
void displayHighScores();
void displayCredits();
void updateHighScores(string playerName, int score);

int main()
{
    int choice;
    bool exitMenu = false;

    
    do
    {
        cout << "Welcome to the guessing game menu. Please select an option:" << endl;
        cout << "1. Number Guessing Game\n2. Alphabet Guessing Game\n3. High Scores\n4. Credits\n5. Exit\n";
        cin >> choice;

        switch (choice)
        {
            case 1:
                playNumberGuessingGame();
                break;
            case 2:
                playAlphabetGuessingGame();
                break;
            case 3:
                displayHighScores();
                break;
            case 4:
                displayCredits();
                break;
            case 5:
			    exitMenu = true;
                break;
            default:
                cout << "Invalid option. Please select again." << endl;
                break;
        }

    } while (!exitMenu);

    cout << "Thanks for playing!" << endl;

    return 0;
}


void playNumberGuessingGame()
{
    int choice, num, guess, tries, max;
    bool playAgain;
    string playerName;

    cout << "Enter your name: ";
    cin >> playerName;

    do
    {
        
        cout << "Choose difficulty level:" << endl;
        cout << "1. Easy (1-16)\n2. Medium (1-21)\n3. Hard (1-41)\n";
        cin >> choice;

        
        switch (choice)
        {
            case 1:
                max = 16;
                break;
            case 2:
                max = 21;
                break;
            case 3:
                max = 41;
                break;
            default:
                max = 16;
                break;
        }

        
        srand(time(0));
        num = rand() % max + 1;

       
        guess = 0;
        tries = 0;

       
        cout << "I'm thinking of a number between 1 and " << max << "." << endl;

        do
        {
            cout << "Guess the number: ";
            cin >> guess;
            tries++;

            if (guess > num && choice==1)
            {
                cout << "Too high! Try again." << endl;
            }
            else if (guess < num && choice==1)
            {
                cout << "Too low! Try again." << endl;
            }
            if (guess != num)
            {
            	cout << "Wrong! Try again " << tries << " tries!" << endl;
			}
            else
            {
                cout << "Congratulations, you guessed the number in " << tries << " tries!" << endl;
                updateHighScores(playerName, tries);
            }

        } while (guess != num);

        
        cout << "Do you want to play again? (1 for yes, 0 for no): ";
        cin >> playAgain;

    } while (playAgain);
}


void playAlphabetGuessingGame()
{
    int choice, max, num, tries;
    char guess;
    bool playAgain;
    string playerName;

    cout << "Enter your name: ";
    cin >> playerName;

    do
    {
        
        cout << "Choose difficulty level:" << endl;
         cout << "1. Easy (A-J)\n2. Medium (A-Z)\n3. Hard (A-Z, lowercase)\n";
    cin >> choice;

    
    switch (choice)
    {
        case 1:
            max = 10;
            break;
        case 2:
            max = 26;
            break;
        case 3:
            max = 26;
            break;
        default:
            max = 10;
            break;
    }

    
    srand(time(0));
    num = rand() % max;

    if (choice == 1)
    {
        num += 'A'; 
    }
    else
    {
        num += 'a'; 
    }

  
    guess = '\0';
    tries = 0;

   
    cout << "I'm thinking of a letter between A and ";
    if (choice == 1)
    {
        cout << "J." << endl;
    }
    else
    {
        cout << "Z." << endl;
    }

    do
    {
        cout << "Guess the letter: ";
        cin >> guess;
        tries++;

        if (guess > num)
        {
            cout << "Too high! Try again." << endl;
        }
        else if (guess < num)
        {
            cout << "Too low! Try again." << endl;
        }
        else
        {
            cout << "Congratulations, you guessed the letter in " << tries << " tries!" << endl;
            updateHighScores(playerName, tries);
        }

    } while (guess != num);

    
    cout << "Do you want to play again? (1 for yes, 0 for no): ";
    cin >> playAgain;

} while (playAgain);
}
void displayCredits()
{
    cout << "---------------------------------------------" << endl;
    cout << "       Guessing Game Credits" << endl;
    cout << "---------------------------------------------" << endl;
    cout << " 1. Eren Geçer - 210209051" << endl;
    cout << " 2. Gökay Yener - 200209051" << endl;
    cout << " 3. Yener Can Taþ - 200209047" << endl;
    cout << " 4. Zeynep Albayrak - 200209039" << endl;
    cout << " 5. Ayça Nur Menteþ - 200209060" << endl;
    cout << " 6. Okan Toga - 210209034" << endl;
    cout << " 7. Cemre Çiçek - 200209005" << endl;
    cout << "---------------------------------------------" << endl;
}


void displayHighScores()
{
ifstream infile("highscores.txt");
string name;
int score;
if (!infile)
{
    cout << "No high scores to display." << endl;
}
else
{
    cout << "High Scores:" << endl;
    cout << "Name\tScore" << endl;

    while (infile >> name >> score)
    {
        cout << name << "\t" << score << endl;
    }

    infile.close();
}
}


void updateHighScores(string playerName, int score)
{
ofstream outfile("highscores.txt", ios::app);
outfile << playerName << " " << score << endl;

outfile.close();
}
