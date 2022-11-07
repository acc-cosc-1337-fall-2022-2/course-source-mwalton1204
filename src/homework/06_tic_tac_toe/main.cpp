#include "tic_tac_toe.h"

int main()
{
    TicTacToe game;

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
            while (!game.game_over()) {
                game.display_board();
                cout << "Player " << game.get_player() << ", select a position 1-9";
                cin >> position;
                game.mark_board(position);
                }

            game.display_board();
            string winner = game.get_winner();

            //Output winner
            if (winner == "X") {
                cout << "\nThe winner is " << winner << "!\n";
            } else if (winner == "O") {
                cout << "\nThe winner is " << winner << "!\n";
            } else if (winner == "C") {
                cout << "\nThe game has ended in a tie!\n";
            }

        //Ask if user would like to play again
        cout<<"Would you like to play again?";
        cin>>play_again;
        }
    }
    while(play_again != "N" || play_again != "n");

    return 0;
}