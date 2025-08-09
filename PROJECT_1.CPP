#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <unistd.h> // For sleep()

using namespace std;

// ANSI color codes for colorful output
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

void printWithDelay(const string &text, int delayMs = 50) {
    for (char c : text) {
        cout << c << flush;
        usleep(delayMs * 1000);
    }
}

void displayWelcome() {
    cout << MAGENTA;
    printWithDelay("🎮 WELCOME TO THE ULTIMATE NUMBER GUESSING GAME! 🎮\n");
    cout << RESET;
    cout << CYAN;
    printWithDelay("🔹 Guess the secret number between 1-100\n");
    printWithDelay("🔹 You'll get hints if your guess is too high or low\n");
    printWithDelay("🔹 The faster you guess, the higher your score!\n\n");
    cout << RESET;
}

int selectDifficulty() {
    int choice;
    cout << YELLOW << "Select Difficulty:\n";
    cout << GREEN << "1. Easy (Unlimited Attempts)\n";
    cout << YELLOW << "2. Medium (15 Attempts)\n";
    cout << RED << "3. Hard (5 Attempts)\n";
    cout << RESET << "Enter choice (1-3): ";
    cin >> choice;
    
    while (choice < 1 || choice > 3) {
        cout << RED << "Invalid choice! Try again: ";
        cin >> choice;
    }
    return choice;
}

int calculateScore(int attempts, int maxAttempts) {
    if (maxAttempts == -1) maxAttempts = 50; // For Easy mode
    return (maxAttempts - attempts + 1) * 10;
}

void playGame() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    int guess, attempts = 0;
    int maxAttempts;
    
    int difficulty = selectDifficulty();
    
    switch (difficulty) {
        case 1: maxAttempts = -1; break; // Unlimited
        case 2: maxAttempts = 15; break;
        case 3: maxAttempts = 5; break;
    }
    
    cout << BLUE << "\n🚀 Game Started! Guess the number (1-100)\n" << RESET;
    
    while (true) {
        cout << "💡 Attempt #" << attempts + 1;
        if (maxAttempts != -1) cout << " (Remaining: " << maxAttempts - attempts << ")";
        cout << "\n👉 Your guess: ";
        
        cin >> guess;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "❌ Invalid input! Enter a number.\n" << RESET;
            continue;
        }
        
        attempts++;
        
        if (guess < secretNumber) {
            cout << YELLOW << "📉 Too low! Try higher.\n" << RESET;
        } else if (guess > secretNumber) {
            cout << YELLOW << "📈 Too high! Try lower.\n" << RESET;
        } else {
            int score = (maxAttempts == -1) ? calculateScore(attempts, 50) : calculateScore(attempts, maxAttempts);
            cout << GREEN << "\n🎉 CONGRATULATIONS! You guessed it in " << attempts << " attempts!\n";
            cout << "🏆 Your Score: " << score << "\n" << RESET;
            break;
        }
        
        if (maxAttempts != -1 && attempts >= maxAttempts) {
            cout << RED << "\n😢 GAME OVER! You ran out of attempts.\n";
            cout << "🔍 The secret number was: " << secretNumber << "\n" << RESET;
            break;
        }
    }
}

int main() {
    char playAgain;
    do {
        displayWelcome();
        playGame();
        
        cout << MAGENTA << "\nPlay again? (y/n): ";
        cin >> playAgain;
        cout << RESET;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << BLUE << "\nThanks for playing! Goodbye! 👋\n" << RESET;
    return 0;
}