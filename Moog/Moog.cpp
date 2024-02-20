#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Spacecraft {
public:
    int speed; // Holds the spacecraft's speed. Initialized in the constructor.
    string direction; // Holds the current direction.

    Spacecraft() : speed(0), direction("Forward") {}

    void increaseSpeed() {
        speed += 10;
        cout << "Increasing speed. Current speed: " << speed << " units." << endl;
    }

    void decreaseSpeed() {
        if (speed > 0) {
            speed -= 10;
            cout << "Decreasing speed. Current speed: " << speed << " units." << endl;
        } else {
            cout << "Speed is already at minimum." << endl;
        }
    }

    void turnLeft() {
        direction = "Left";
        cout << "Turning left." << endl;
    }

    void turnRight() {
        direction = "Right";
        cout << "Turning right." << endl;
    }

    void displayStatus() {
        cout << "Current status -- Speed: " << speed << " units, Direction: " << direction << "." << endl;
    }
};

int main() {
    // Initial message
    vector<string> msg {"Hello", "Moog Management,", "I am excited for the opportunity! I took today to build out a C++ application to further demonstrate my technical skills, willingness to adapt and learn quickly, and my commitment to earing a career with Moog"};
    for (const string& word : msg) {
        cout << word << " ";
    }
    cout << "\n\n";

    // Spacecraft simulation
    Spacecraft spacecraft;
    char input;
    cout << "Spacecraft Thruster Control System" << endl;
    cout << "Controls: W (increase speed), S (decrease speed), A (turn left), D (turn right), Q (quit)" << endl;

    while (true) {
        cout << "Enter command: ";
        cin >> input;
        input = tolower(input);

        switch (input) {
            case 'w':
                spacecraft.increaseSpeed();
                break;
            case 's':
                spacecraft.decreaseSpeed();
                break;
            case 'a':
                spacecraft.turnLeft();
                break;
            case 'd':
                spacecraft.turnRight();
                break;
            case 'q':
                cout << "Exiting control system." << endl;
                return 0;
            default:
                cout << "Invalid command. Please use W, S, A, D, or Q." << endl;
                break;
        }

        spacecraft.displayStatus();
    }
}
