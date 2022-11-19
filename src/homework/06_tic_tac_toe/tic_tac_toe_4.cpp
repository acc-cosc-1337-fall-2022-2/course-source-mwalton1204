#include "tic_tac_toe_4.h"

TicTacToe4::TicTacToe4() : TicTacToe(4){}

bool TicTacToe4::check_column_win()
{
    bool is_col_win;

    if(pegs[0] == pegs[4] && pegs[4] == pegs[8] && pegs[8] == pegs[12] && pegs[0] != " ")
    {
        is_col_win = true;
    }
    else if(pegs[1] == pegs[5] && pegs[5] == pegs[9] && pegs[9] == pegs[13] && pegs[1] != " ")
    {
        is_col_win = true;
    }
    else if(pegs[2] == pegs[6] && pegs[6] == pegs[10] && pegs[10] == pegs[14] && pegs[2] != " ")
    {
        is_col_win = true;
    }
    else if(pegs[3] == pegs[7] && pegs[7] == pegs[11] && pegs[11] == pegs[15] && pegs[3] != " ")
    {
        is_col_win = true;
    }
    else
    {
        is_col_win = false;
    }

    return is_col_win;
}

bool TicTacToe4::check_row_win()
{
    bool is_row_win;

    if(pegs[0] == pegs[1] && pegs[1] == pegs[2] && pegs[2] == pegs[3] && pegs[0] != " ")
    {
        is_row_win = true;
    }
    else if(pegs[4] == pegs[5] && pegs[5] == pegs[6] && pegs[6] == pegs[7] && pegs[4] != " ")
    {
        is_row_win = true;
    }
    else if(pegs[8] == pegs[9] && pegs[9] == pegs[10] && pegs[10] == pegs[11] && pegs[8] != " ")
    {
        is_row_win = true;
    }
    else if(pegs[12] == pegs[13] && pegs[13] == pegs[14] && pegs[14] == pegs[15] && pegs[12] != " ")
    {
        is_row_win = true;
    }
    else
    {
        is_row_win = false;
    }

    return is_row_win;
}

bool TicTacToe4::check_diagonal_win()
{
    bool is_diagonal_win;

    if(pegs[0] == pegs[5] && pegs[5] == pegs[10] && pegs[10] == pegs[15] && pegs[0] != " ")
    {
        is_diagonal_win = true;
    }
    else if(pegs[3] == pegs[6] && pegs[6] == pegs[9] && pegs[9] == pegs[12] && pegs[3] != " ")
    {
        is_diagonal_win = true;
    }
    else
    {
        is_diagonal_win = false;
    }

    return is_diagonal_win;
}
