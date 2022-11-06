//h//
#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>

using std::string;
using std::vector;
using std::cout, std::cin;
using std::count;

#ifndef TicTacToe_H
#define TicTacToe_H

class TicTacToe
{
public:
    bool game_over();
    void start_game(string first_player);
    void mark_board(int position);
    string get_player() const;
    void display_board() const;

    string get_winner();

private:
    void set_next_player();
    bool check_board_full();
    void clear_board();

    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win();
    void set_winner();

    string player;
    string winner;
    vector<string> pegs{" "," "," "," "," "," "," "," "," "};
};

#endif
