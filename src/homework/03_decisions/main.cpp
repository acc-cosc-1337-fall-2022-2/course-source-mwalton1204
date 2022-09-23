//write include statements
#include <iostream>
#include "decisions.h"

using std::cin, std::cout, std::string;

int main() 
{
    int selection;
    int grade;
    string letter_grade;

    //display menu
    cout<<"MAIN MENU\n";
    cout<<"1 - Letter grade using if\n";
    cout<<"2 - Letter grade using switch\n";
    cout<<"3 - Exit\n\n";

    //get user selection
    cout<<"Enter a selection:";
    cin>>selection;

    //run selected function
    if (selection == 1)
    {
        cout<<"Enter a grade between 0-100:";
        cin>>grade;

        letter_grade = get_letter_grade_using_if(grade);

        cout<<"The letter grade is: "<<letter_grade;
    }
    else if (selection == 2)
    {
        cout<<"Enter a grade between 0-100:";
        cin>>grade;

        letter_grade = get_letter_grade_using_switch(grade);

        cout<<"The letter grade is: "<<letter_grade;
    }
    else
    {
        exit(0);
    }

	return 0;
}