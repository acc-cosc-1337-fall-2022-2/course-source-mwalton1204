#include "tic_tac_toe_3.h"

TicTacToe3::TicTacToe3() : TicTacToe(3){}

bool TicTacToe3::check_column_win()
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

bool TicTacToe3::check_row_win()
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

bool TicTacToe3::check_diagonal_win()
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
