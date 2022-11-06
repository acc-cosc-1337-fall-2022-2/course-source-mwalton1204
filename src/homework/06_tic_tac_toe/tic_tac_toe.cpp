//cpp
#include"tic_tac_toe.h"


//public
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

void TicTacToe::display_board() const
{
    for(int i = 0; i<9; i++)
    {
        if(i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7)
        {cout<<pegs[i]<<"|";}
        if(i == 2 || i == 5 || i == 8)
        {cout<<pegs[i]<<"\n";}
    }
}

string TicTacToe::get_winner()
{
    return winner;
}


//private
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

bool TicTacToe::check_column_win()
{
    bool is_col_win;

    if(pegs[0] == pegs[3] && pegs[3] == pegs[6] && pegs[0] != " ")
    {
        is_col_win = true;
    }
    else if(pegs[1] == pegs[4] && pegs[4] == pegs[7] && pegs[1] != " ")
    {
        is_col_win = true;
    }
    else if(pegs[2] == pegs[5] && pegs[5] == pegs[8] && pegs[2] != " ")
    {
        is_col_win = true;
    }
    else
    {
        is_col_win = false;
    }

    return is_col_win;
}

bool TicTacToe::check_row_win()
{
    bool is_row_win;

    if(pegs[0] == pegs[1] && pegs[1] == pegs[2] && pegs[0] != " ")
    {
        is_row_win = true;
    }
    else if(pegs[3] == pegs[4] && pegs[4] == pegs[5] && pegs[3] != " ")
    {
        is_row_win = true;
    }
    else if(pegs[6] == pegs[7] && pegs[7] == pegs[8] && pegs[6] != " ")
    {
        is_row_win = true;
    }
    else
    {
        is_row_win = false;
    }

    return is_row_win;
}

bool TicTacToe::check_diagonal_win()
{
    bool is_diagonal_win;

    if(pegs[0] == pegs[4] && pegs[4] == pegs[8] && pegs[0] != " ")
    {
        is_diagonal_win = true;
    }
    else if(pegs[2] == pegs[4] && pegs[4] == pegs[6] && pegs[2] != " ")
    {
        is_diagonal_win = true;
    }
    else
    {
        is_diagonal_win = false;
    }

    return is_diagonal_win;
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

//