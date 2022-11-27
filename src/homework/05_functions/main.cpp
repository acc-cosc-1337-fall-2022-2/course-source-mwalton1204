#include "func.h"

int main()
{
    char repeat = 'Y';

    while(repeat == 'Y' || repeat == 'y') {
        //Menu
        int selection = 0;

        cout << "1 - Get GC Content\n"
                "2 - Get DNA Complement\n"
                "3 - Exit\n\n"
                "Make a Selection:";

        cin >> selection;

        if (selection == 3) //Exit
        {
            exit(0);
        }

        //Get user input
        string dna;
        cout << "\n\nEnter a DNA string:";
        cin >> dna;

        //capitalize user input
        for (char &i: dna) {
            i = toupper(i);
        }

        if (selection == 1) //Get GC Content
        {
            cout << get_gc_content(dna);
            cout<<"\nWould you like to perform another function? (y/n)";
            cin>>repeat;

        } else if (selection == 2) //Get DNA Complement
        {
            cout << get_dna_complement(dna);
            cout<<"\nWould you like to perform another function? (y/n)";
            cin>>repeat;
        }

    }

	return 0;
}