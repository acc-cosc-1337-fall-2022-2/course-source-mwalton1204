//write include statements
#include "dna.h"

int main() 
{
    int selection = 0; //initialize variables
    int num1, num2;

    do {
        cout << "1 - Find a Factorial\n"; //print menu options
        cout << "2 - Find a Greatest Common Divisor\n";
        cout << "3 - Exit\n";

        cout << "Make a selection:";
        cin >> selection; //take user menu selection

        if (selection == 1) //call get_factorial function
        {
            cout << "Please enter a number:";
            cin >> num1;

            cout << "The value of " << num1 << " factorial is " << get_factorial(num1) << "\n\n";

            cout << "1 - Return to Main Menu\n"; //ask user if they want to repeat process
            cout << "2 - Exit\n";

            cout << "What would you like to do?";
            cin >> selection;
            cout<<"\n";

            if (selection == 1)
            {
                selection = 0;
            }
            else
            {
                exit(0);
            }
        }
        else if (selection == 2) //call get_greatest_common_divisor function
        {
            cout << "Please enter a number:";
            cin >> num1;
            cout << "Please enter another number";
            cin >> num2;

            cout << "The greatest common divisor between " << num1 << " and " << num2 << " is "
                 << get_greatest_common_divisor(num1, num2) << "\n\n";

            cout << "1 - Return to Main Menu\n"; //ask user if they want to repeat process
            cout << "2 - Exit\n";

            cout << "What would you like to do?";
            cin >> selection;
            cout<<"\n";

            if (selection == 1)
            {
                selection = 0;
            }
            else
            {
                exit(0);
            }
        }
        else if (selection == 3) //exit program on selection 3
        {
            exit(0);
        }
        else //repeat request for menu selection on invalid input
        {
            cout << "Invalid Menu Selection\n\n";
            selection = 0;
        }
    }
    while(selection == 0);
	return 0;
}