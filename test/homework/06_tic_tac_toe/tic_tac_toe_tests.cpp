#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over if 9 slots are selected")
{
    TicTacToe game;
    string first_player = "X";

    game.start_game(first_player);

    for(int i = 0; i<9; i++)
    {
        game.mark_board(i+1);

        if(i != 8)
        {REQUIRE(game.game_over() == false);}
        else
        {REQUIRE(game.game_over() == true);}
    }
}