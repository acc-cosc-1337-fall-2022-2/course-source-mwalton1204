#include"tic_tac_toe.h"
#include"tic_tac_toe_3.h"
#include"tic_tac_toe_4.h"

//friend functions
ostream& operator<<(ostream& out, const TicTacToe& game)
{
    for(int i = 0; i<game.pegs.size(); i++)
    {
        if(game.pegs.size() == 9) {
            if (i == 2 || i == 5 || i == 8) {
                out << game.pegs[i] << "\n";
            }
            else {
                out << game.pegs[i] << "|";
            }
        }
        else if(game.pegs.size() == 16) {
            if (i == 3 || i == 7 || i == 11 || i == 15) {
                out << game.pegs[i] << "\n";
            }
            else {
                out << game.pegs[i] << "|";
            }
        }
    }

    return out;
}

istream& operator>>(istream& in, TicTacToe& game) {
    int position;
    vector<int> legal_plays;
    bool error = true;

    if(game.pegs.size() == 9) {
        legal_plays = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    }
    else {
        legal_plays = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    }

    while (error) {
        cout << "Player " << game.get_player() << ", select a position 1-"<<legal_plays.size();
        in>>position;
        if (count(legal_plays.begin(), legal_plays.end(), position)) {
            game.mark_board(position);
            error = false;
        } else {
            cout << "\nInvalid Input. Try Again. Booty.\n";
            in.clear();
            in.ignore(INT_MAX, '\n');
        }
    }
    return in;
}

//public functions
TicTacToe::TicTacToe(int size) : pegs(size*size, " ") {}

bool TicTacToe::game_over()
{
    if(check_column_win() || check_row_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    }
    else if(check_board_full())
    {
        winner = "C";
        return true;
    }
    else
    {
        return false;
    }
}

void TicTacToe::start_game(string first_player)
{
    clear_board();
    if(first_player == "X" || first_player == "O")
    {
        player = first_player;
    }
    else
    {
        first_player = 'X';
        player = first_player;
    }
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

string TicTacToe::get_player() const
{
    return player;
}

string TicTacToe::get_winner()
{
    return winner;
}



//protected functions
bool TicTacToe::check_column_win()
{
    return false;
}

bool TicTacToe::check_row_win()
{
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    return false;
}


//private functions
void TicTacToe::set_next_player()
{
    if(player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }
}

bool TicTacToe::check_board_full()
{
    bool board_full;
    if (count(pegs.begin(), pegs.end(), " "))
    {
        board_full = false;
    }
    else
    {
        board_full = true;
    }

    return board_full;
}

void TicTacToe::clear_board()
{
    for(auto& peg: pegs)
    {
        peg = " ";
    }
}

void TicTacToe::set_winner()
{
    if(player == "X")
    {
        winner = "O";
    }
    else
    {
        winner = "X";
    }
}

