#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

int main()
{
//class object adn variable initialization
    unique_ptr<TicTacToe> game;
    TicTacToeManager manager;

    string first_player;
    bool game_on = true;

//main game loop
    while (game_on)
    {
        int game_type;
        do{
            cout<<"Select game type:\n"
                  "1. 3x3\n"
                  "2. 4x4\n";
            cin>> game_type;
        }while(game_type != 1 && game_type != 2);

        if(game_type == 1)
        {
            game = make_unique<TicTacToe3>();
        }
        else if(game_type == 2)
        {
            game = make_unique<TicTacToe4>();
        }

        cout << "Player 1: Please choose X or O\n";
        cin >> first_player;

        if(first_player == "X" || first_player == "O") {
            game->start_game(first_player);

            do
            {
                cout << *game;
                cin >> *game;
            }
            while (!game->game_over());

            manager.save_games(game);

            int x, o, t;
            manager.get_winner_total(o, x, t);
            cout<<"\nCurrent Score Totals:";
            cout<<"\nO Wins: "<<o<<"\n";
            cout<<"X Wins: "<<x<<"\n";
            cout<<"Ties: "<<t<<"\n\n";

            string play_again;
            cout << "Play again? (Y/N)";
            cin >> play_again;

            if(play_again == "Y" || play_again == "y")
            {
                game_on = true;
            }
            else
            {
                cout<<"Thanks for playing!\n";
                game_on = false;
            }
        }
        else {
            cout<<"Invalid Input. Try Again.\n";
        }
    }

//display played games and score totals
    cout << manager;

    return 0;
}