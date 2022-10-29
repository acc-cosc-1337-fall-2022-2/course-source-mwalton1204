//cpp
#include"tic_tac_toe.h"

bool TicTacToe::game_over()
{
    return check_board_full();
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