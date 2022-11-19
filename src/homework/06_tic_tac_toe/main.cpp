#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

int main()
{
//class object initialization
    unique_ptr<TicTacToe> game;
    TicTacToeManager manager;

//variable initialization
    string first_player;
    char play_again;
    bool game_on = true;
    bool play_again_invalid_input;
    int o, x, t;

//instructions
    cout<< "Tic Tac Toe\n\n";
    cout<< "Legal Positions:\n"
           "1|2|3\n"
           "4|5|6\n"
           "7|8|9\n\n";

//main game loop
    do
    {

//prompt user for game type
        int game_type = 0;
        do{
            cout<<"Select game type:\n"
                  "1. 3x3\n"
                  "2. 4x4\n";
            cin>> game_type;
        }while(game_type != 1 && game_type != 2);

//set game type to 3x3 or 4x4
        if(game_type == 1)
        {
            game = make_unique<TicTacToe3>();
        }
        else if(game_type == 2)
        {
            game = make_unique<TicTacToe4>();
        }

//prompt first player for X or O
        cout << "Player 1: Please choose X or O\n";
        cin >> first_player;

//verify valid selection
        if(first_player == "X" || first_player == "O") {

//start game
            game->start_game(first_player);

//alternate turns until game over
            while (!game->game_over()) {
                cout<<*game;
                cin>>*game;
            }

//display final game board, save game and update score
            cout<<*game;

            manager.save_games(reinterpret_cast<unique_ptr<struct TicTacToe> &>(*game));

//display winner
            string winner = game->get_winner();
            if (winner == "X" || winner == "O") {
                cout << "\nThe winner is " << winner << "!\n";
            } else if (winner == "C") {
                cout << "\nThe game has ended in a tie!\n";
            }

//display current score totals
            manager.get_winner_total(o, x, t);
            cout<<"\nCurrent Score Totals:";
            cout<<"\nO Wins: "<<o<<"\n";
            cout<<"X Wins: "<<x<<"\n";
            cout<<"Ties: "<<t<<"\n";

//prompt user to repeat or exit
            do {
                cout << "\nWould you like to play again? (Y/N)";
                cin >> play_again;
                if (play_again == 'N' || play_again == 'n') {
                    play_again_invalid_input = false;
                    game_on = false;
                }
                else if (play_again == 'Y' || play_again == 'y') {
                    play_again_invalid_input = false;
                }
                else {
                    play_again_invalid_input = true;
                    cout << "Invalid Input. Try Again.\n";
                }
            } while (play_again_invalid_input);
        }
        else {
            cout<<"Invalid Input. Try Again.\n";
        }
    }
    while(game_on);

//display played games and score totals
    cout << manager;

    return 0;
}