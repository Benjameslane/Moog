#include <iostream>
#include <string>

using namespace std;

// I chose to create a Spacecraft class to encapsulate all functionalities related to the spacecraft.
// This way, it's easier to manage and expand the spacecraft's capabilities.
class Spacecraft {
public:
    int speed; // Holds the spacecraft's speed. I initialize this in the constructor.
    string direction; // Holds the current direction. This is more intuitive for controlling the spacecraft.

    // The constructor sets default values. Starting with a speed of 0 and moving forward seemed logical.
    Spacecraft() : speed(0), direction("Forward") {}

    // I implemented this method to increase the spacecraft's speed. Incrementing by 10 units was arbitrary but demonstrates the concept.
    void increaseSpeed() {
        speed += 10;
        cout << "Increasing speed. Current speed: " << speed << " units." << endl;
    }

    // Decreasing the speed required checking that we don't go below 0, ensuring the spacecraft doesn't move backwards.
    void decreaseSpeed() {
        if (speed > 0) {
            speed -= 10;
            cout << "Decreasing speed. Current speed: " << speed << " units." << endl;
        } else {
            cout << "Speed is already at minimum." << endl;
        }
    }

    // Turning left or right simply changes the direction string. This could be expanded into more complex navigation.
    void turnLeft() {
        direction = "Left";
        cout << "Turning left." << endl;
    }

    void turnRight() {
        direction = "Right";
        cout << "Turning right." << endl;
    }

    // Displaying the status after each command helps visualize the effect of our actions, akin to feedback in a real control system.
    void displayStatus() {
        cout << "Current status -- Speed: " << speed << " units, Direction: " << direction << "." << endl;
    }
};

// The main function orchestrates the simulation, taking user input and adjusting the spacecraft accordingly.
int main() {
    Spacecraft spacecraft; // Instantiating the spacecraft seemed a natural first step.
    char input;
    cout << "Spacecraft Thruster Control System" << endl;
    cout << "Controls: W (increase speed), S (decrease speed), A (turn left), D (turn right), Q (quit)" << endl;

    // This loop continuously processes user input, allowing for dynamic control of the spacecraft.
    while (true) {
        cout << "Enter command: ";
        cin >> input;
        input = tolower(input); // Normalizing input to lowercase makes the command processing case-insensitive.

        // A switch statement was ideal here for mapping inputs to actions. It's clear and easy to expand with more commands.
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
                return 0; // Exiting the program on 'q' felt intuitive for quitting.
            default:
                cout << "Invalid command. Please use W, S, A, D, or Q." << endl;
                break;
        }

        // After processing a command, it's important to give feedback, hence displaying the spacecraft's status.
        spacecraft.displayStatus();
    }
}
