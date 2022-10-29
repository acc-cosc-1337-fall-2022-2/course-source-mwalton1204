#import "tic_tac_toe.h"

int main() 
{
    TicTacToe game;

    string first_player;
    char end = 'N';
    int position;

    cout<< "Tic Tac Toe\n\n";
    cout<< "Legal Positions:\n"
           "1|2|3\n"
           "4|5|6\n"
           "7|8|9\n\n";

    do
    {
        cout<<"Player 1: Choose X or O\n";
        cin>>first_player;

        game.start_game(first_player);

        while (!game.game_over()) {
            game.display_board();
            cout << "Player "<<game.get_player()<<", select a position 1-9";
            cin >> position;
            game.mark_board(position);
        }

        game.display_board();
        cout<<"\nWould you like to exit? (Y/N)";
        cin>>end;
    }
    while(end != 'Y');

    return 0;
}