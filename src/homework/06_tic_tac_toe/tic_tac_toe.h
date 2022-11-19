#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>
#include<memory>

using std::string;
using std::vector;
using std::cout, std::cin;
using std::istream, std::ostream;
using std::count;
using std::unique_ptr, std::make_unique;
using std::move;

#ifndef TicTacToe_H
#define TicTacToe_H
class TicTacToe
{
friend ostream& operator<<(ostream& out, const TicTacToe& game);
friend istream& operator>>(istream& in, TicTacToe& game);

public:
    TicTacToe(int size);
    bool game_over();
    void start_game(string first_player);
    void mark_board(int position);
    string get_player() const;
    string get_winner();


protected:
    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();
    vector<string> pegs;

private:
    void set_next_player();
    bool check_board_full();
    void clear_board();
    void set_winner();

    string player;
    string winner;

};
#endif

