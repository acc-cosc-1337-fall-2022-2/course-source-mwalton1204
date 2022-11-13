#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

int main()
{
    //Class object initialization
    TicTacToe game;
    TicTacToeManager manager;

    //Variable initialization
    string first_player;
    string play_again;
    int position;
    bool invalid;
    vector<int> legal_pos{1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Instructions
    cout<< "Tic Tac Toe\n\n";
    cout<< "Legal Positions:\n"
           "1|2|3\n"
           "4|5|6\n"
           "7|8|9\n\n";

    //Main game loop
    do
    {
        cout << "Player 1: Please choose X or O\n";
        cin >> first_player;

        //Verify that first player selects X or O
        if(first_player == "X" || first_player == "O")
        {
            game.start_game(first_player);

            //Loop while players select positions until game over
            while (!game.game_over())
            {
                cout<<game;
                cin>>game;
            }

            //Display final game board and save game state
            cout<<game;
            manager.save_games(game);

            //Update and display score
            int o, x, t;
            manager.get_winner_total(o, x, t);
            cout<<"\nO Wins: "<<o<<"\n";
            cout<<"X Wins: "<<x<<"\n";
            cout<<"Ties: "<<t<<"\n";

            //Output winner
            string winner = game.get_winner();
            if (winner == "X") {
                cout << "\nThe winner is " << winner << "!\n";
            } else if (winner == "O") {
                cout << "\nThe winner is " << winner << "!\n";
            } else if (winner == "C") {
                cout << "\nThe game has ended in a tie!\n";
            }
        }

        //Ask if user would like to play again
        cout<<"Would you like to play again?";
        cin>>play_again;

        //End loop if player finished
        if(play_again == "N" || play_again == "n")
        {
            break;
        }
    }
    while(play_again != "N");

    cout<<manager;

    return 0;
}