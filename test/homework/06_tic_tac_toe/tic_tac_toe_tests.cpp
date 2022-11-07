#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X")
{
    TicTacToe game;
    string first_player = "X";
    game.start_game(first_player);

    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
    TicTacToe game;
    string first_player = "O";
    game.start_game(first_player);

    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test game over if 9 slots are selected")
{
    TicTacToe game;
    string first_player = "X";
    game.start_game(first_player);

    game.mark_board(2);
    game.game_over();
    game.mark_board(1);
    game.game_over();
    game.mark_board(5);
    game.game_over();
    game.mark_board(3);
    game.game_over();
    game.mark_board(6);
    game.game_over();
    game.mark_board(4);
    game.game_over();
    game.mark_board(7);
    game.game_over();
    game.mark_board(8);
    game.game_over();
    game.mark_board(9);
    game.game_over();

    string winner = game.get_winner();

    REQUIRE(winner == "C");
}

TEST_CASE("Test win by first column")
{
    TicTacToe game;
    string first_player = "X";
    game.start_game(first_player);

    game.mark_board(1);//x-position
    game.game_over();
    game.mark_board(2);
    game.game_over();
    game.mark_board(4);//x-position
    game.game_over();
    game.mark_board(2);
    game.game_over();
    game.mark_board(7);//x-position
    game.game_over();

    string winner = game.get_winner();

    REQUIRE(game.game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by second column")
{
    TicTacToe game;
    string first_player = "X";
    game.start_game(first_player);

    game.mark_board(2);//x-position
    game.game_over();
    game.mark_board(1);
    game.game_over();
    game.mark_board(5);//x-position
    game.game_over();
    game.mark_board(1);
    game.game_over();
    game.mark_board(8);//x-position
    game.game_over();

    string winner = game.get_winner();

    REQUIRE(game.game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by third column")
{
    TicTacToe game;
    string first_player = "X";
    game.start_game(first_player);

    game.mark_board(3);//x-position
    game.mark_board(2);
    game.mark_board(6);//x-position
    game.mark_board(2);
    game.mark_board(9);//x-position
    game.game_over();

    string winner = game.get_winner();

    REQUIRE(game.game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by first row")
{
    TicTacToe game;
    string first_player = "X";
    game.start_game(first_player);

    game.mark_board(1);//x-position
    game.game_over();
    game.mark_board(4);
    game.game_over();
    game.mark_board(2);//x-position
    game.game_over();
    game.mark_board(4);
    game.game_over();
    game.mark_board(3);//x-position
    game.game_over();

    string winner = game.get_winner();

    REQUIRE(game.game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by second row")
{
    TicTacToe game;
    string first_player = "X";
    game.start_game(first_player);

    game.mark_board(4);//x-position
    game.game_over();
    game.mark_board(2);
    game.game_over();
    game.mark_board(5);//x-position
    game.game_over();
    game.mark_board(2);
    game.game_over();
    game.mark_board(6);//x-position
    game.game_over();

    string winner = game.get_winner();

    REQUIRE(game.game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by third row")
{
    TicTacToe game;
    string first_player = "X";
    game.start_game(first_player);

    game.mark_board(7);//x-position
    game.game_over();
    game.mark_board(2);
    game.game_over();
    game.mark_board(8);//x-position
    game.game_over();
    game.mark_board(2);
    game.game_over();
    game.mark_board(9);//x-position
    game.game_over();

    string winner = game.get_winner();

    REQUIRE(game.game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win diagonally from top left")
{
    TicTacToe game;
    string first_player = "X";
    game.start_game(first_player);

    game.mark_board(1);//x-position
    game.game_over();
    game.mark_board(2);
    game.game_over();
    game.mark_board(5);//x-position
    game.game_over();
    game.mark_board(2);
    game.game_over();
    game.mark_board(9);//x-position
    game.game_over();

    string winner = game.get_winner();

    REQUIRE(game.game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win diagonally from bottom left")
{
    TicTacToe game;
    string first_player = "X";
    game.start_game(first_player);

    game.mark_board(7);//x-position
    game.game_over();
    game.mark_board(2);
    game.game_over();
    game.mark_board(5);//x-position
    game.game_over();
    game.mark_board(2);
    game.game_over();
    game.mark_board(3);//x-position
    game.game_over();

    string winner = game.get_winner();

    REQUIRE(game.game_over() == true);
    REQUIRE(winner == "X");
}

