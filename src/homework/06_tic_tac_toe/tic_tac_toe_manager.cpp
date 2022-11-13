#include"tic_tac_toe_manager.h"

//friend functions
ostream& operator<<(ostream& out, const TicTacToeManager& manager)
{
    for(int i = 0; i < manager.games.size(); i++)
    {
        out<<"\nGame "<<i + 1<<"\n"<<manager.games[i];
    }

    out<<"\nFinal Scores:\n";
    out<<"O Wins: "<<manager.o_win<<"\n";
    out<<"X Wins: "<<manager.x_win<<"\n";
    out<<"Ties: "<<manager.ties<<"\n";

    return out;
}

//public functions
void TicTacToeManager::save_games(TicTacToe b)
{
    games.push_back(b);
    string winner = b.get_winner();
    update_winner_count(winner);
}
void TicTacToeManager::get_winner_total(int& o, int& x, int& t)
{
    x = x_win;
    o = o_win;
    t = ties;
}

//private functions
void TicTacToeManager::update_winner_count(string winner)
{
    if (winner == "X")
    {
        x_win += 1;
    }
    else if(winner == "O")
    {
        o_win += 1;
    }
    else
    {
        ties += 1;
    }
}