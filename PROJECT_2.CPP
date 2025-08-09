#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <windows.h> // For color (Windows only)

using namespace std;

// Function to change console text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Quantum physics jokes
string getQuantumJoke() {
    string jokes[] = {
        "Why don't quantum physicists get hungry? They can always snack on a quantum byte!",
        "Schrödinger's cat walks into the calculator... the result both exists and doesn't!",
        "This calculation collapsed the wave function of my boredom!",
        "According to Heisenberg, you might know the answer but not which operation you used!"
    };
    return jokes[rand() % 4];
}

// Animated ASCII art
void showAnimation() {
    string frames[] = {
        "  ___ \n / _ \\ \n| | | |\n| |_| |\n \\___/ \n",
        "  ____ \n / __ \\ \n| |  | |\n| |__| |\n \\____/ \n",
        "  _____ \n / ___ \\ \n| |   | |\n| |___| |\n \\_____/ \n"
    };
    for(int i=0; i<3; i++) {
        system("cls");
        cout << frames[i];
        Sleep(300);
    }
}

// Secret cheat code detector
bool checkCheatCode(double num1, double num2) {
    if(num1 == 42 && num2 == 42) {
        setColor(10);
        cout << "\n\nULTIMATE ANSWER UNLOCKED: The meaning of life is 42!\n";
        return true;
    }
    if(num1 == 3.14 && num2 == 3.14) {
        setColor(11);
        cout << "\n\nPI MODE ACTIVATED: Everything is circular now!\n";
        return true;
    }
    return false;
}

// Random math fact
void showMathFact() {
    string facts[] = {
        "Did you know? Zero is the only number that can't be represented in Roman numerals!",
        "Fun fact: 111,111,111 × 111,111,111 = 12,345,678,987,654,321",
        "Math trivia: The word 'hundred' comes from 'hundrath' meaning 120, not 100!",
        "Cool fact: 2 and 5 are the only prime numbers that end with 2 or 5!"
    };
    setColor(14);
    cout << "\n" << facts[rand() % 4] << "\n";
    setColor(7);
}

int main() {
    srand(time(0));
    char op;
    double num1, num2;
    bool quantumMode = false;

    setColor(13);
    cout << "=== 🎩✨ QUANTUM QUIRKULATOR ✨🎩 ===\n";
    setColor(7);

    while(true) {
        cout << "\nEnter first number: ";
        cin >> num1;
        
        cout << "Enter second number: ";
        cin >> num2;

        if(checkCheatCode(num1, num2)) {
            showAnimation();
            continue;
        }

        cout << "Choose operation (+, -, *, /, q for quantum mode): ";
        cin >> op;

        // Quantum mode toggle
        if(op == 'q') {
            quantumMode = !quantumMode;
            setColor(quantumMode ? 10 : 12);
            cout << (quantumMode ? 
                "\nQUANTUM MODE ACTIVATED! Results may be uncertain..." :
                "\nClassical physics restored. Boring but reliable.");
            setColor(7);
            continue;
        }

        // Calculate with quantum randomness
        if(quantumMode && (rand() % 5 == 0)) {
            setColor(5);
            cout << "\nQUANTUM FLUCTUATION OCCURRED! ";
            cout << "The observer effect changed your result to: " << rand() % 100 << "!\n";
            setColor(7);
            cout << getQuantumJoke() << "\n";
            continue;
        }

        // Normal calculations
        switch(op) {
            case '+':
                cout << "\nResult: " << num1 + num2;
                if(num1 + num2 == 69) {
                    setColor(6);
                    cout << " (Nice!)";
                    setColor(7);
                }
                break;
            case '-':
                cout << "\nResult: " << num1 - num2;
                break;
            case '*':
                cout << "\nResult: " << num1 * num2;
                break;
            case '/':
                if(num2 != 0) {
                    cout << "\nResult: " << num1 / num2;
                } else {
                    setColor(12);
                    cout << "\nDIVISION BY ZERO CREATED A BLACK HOLE!";
                    setColor(7);
                }
                break;
            default:
                setColor(12);
                cout << "\nInvalid operation! Try +, -, *, / or q";
                setColor(7);
        }

        showMathFact();
        
        cout << "\n\nCalculate again? (y/n): ";
        char choice;
        cin >> choice;
        if(choice != 'y') break;
    }

    setColor(11);
    cout << "\nThanks for using the Quantum Quirkulator!\n";
    cout << "Remember: In an infinite universe, all calculations are possible!\n";
    setColor(7);

    return 0;
}