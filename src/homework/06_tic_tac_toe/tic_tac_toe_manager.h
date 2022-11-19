#include "tic_tac_toe.h"

#ifndef TicTacToeManager_H
#define TicTacToeManager_H
class TicTacToeManager
{

friend ostream& operator<<(ostream& out, const TicTacToeManager& manager);

public:
    void save_games(unique_ptr<TicTacToe>& b);
    void get_winner_total(int& o, int& x, int& t);

private:
    void update_winner_count(string winner);

    int x_win = 0;
    int o_win = 0;
    int ties = 0;
    vector<unique_ptr<TicTacToe>> games;

};
#endif