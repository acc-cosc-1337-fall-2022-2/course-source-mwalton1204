#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    string first_player = "X";
    game->start_game(first_player);

    REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    string first_player = "O";
    game->start_game(first_player);

    REQUIRE(game->get_player() == "O");
}


//3x3 tests

TEST_CASE("Test game over if 9 slots are selected")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(2);
    game->game_over();
    game->mark_board(1);
    game->game_over();
    game->mark_board(5);
    game->game_over();
    game->mark_board(3);
    game->game_over();
    game->mark_board(6);
    game->game_over();
    game->mark_board(4);
    game->game_over();
    game->mark_board(7);
    game->game_over();
    game->mark_board(8);
    game->game_over();
    game->mark_board(9);
    game->game_over();

    string winner = game->get_winner();

    REQUIRE(winner == "C");
}

TEST_CASE("Test win by first column")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(1);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(4);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(7);//x-position
    game->game_over();

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by second column")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(2);//x-position
    game->game_over();
    game->mark_board(1);
    game->game_over();
    game->mark_board(5);//x-position
    game->game_over();
    game->mark_board(1);
    game->game_over();
    game->mark_board(8);//x-position
    game->game_over();

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by third column")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(3);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(6);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(9);//x-position
    game->game_over();

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by first row")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(1);//x-position
    game->game_over();
    game->mark_board(4);
    game->game_over();
    game->mark_board(2);//x-position
    game->game_over();
    game->mark_board(4);
    game->game_over();
    game->mark_board(3);//x-position
    game->game_over();

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by second row")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(4);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(5);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(6);//x-position
    game->game_over();

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by third row")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(7);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(8);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(9);//x-position
    game->game_over();

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win diagonally from top left")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(1);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(5);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(9);//x-position
    game->game_over();

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win diagonally from bottom left")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(7);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(5);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(3);//x-position
    game->game_over();

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test TicTacToe manager get winner total function")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    TicTacToeManager manager;
    int o, x, t;

    game->start_game("X");

    game->mark_board(7);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(5);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(3);//x-position
    game->game_over();

    manager.save_games(game);

    game->start_game("O");

    game->mark_board(7);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(5);//x-position
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(3);//x-position
    game->game_over();

    manager.save_games(game);

    game->start_game("X");

    game->mark_board(2);
    game->game_over();
    game->mark_board(1);
    game->game_over();
    game->mark_board(5);
    game->game_over();
    game->mark_board(3);
    game->game_over();
    game->mark_board(6);
    game->game_over();
    game->mark_board(4);
    game->game_over();
    game->mark_board(7);
    game->game_over();
    game->mark_board(8);
    game->game_over();
    game->mark_board(9);
    game->game_over();

    manager.save_games(game);

    manager.get_winner_total(o, x, t);

    REQUIRE(x == 1);
    REQUIRE(o == 1);
    REQUIRE(t == 1);
}


//4x4 tests

TEST_CASE("Test game over if 16 slots are selected")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(1);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(3);
    game->game_over();
    game->mark_board(4);
    game->game_over();
    game->mark_board(6);
    game->game_over();
    game->mark_board(5);
    game->game_over();
    game->mark_board(7);
    game->game_over();
    game->mark_board(10);
    game->game_over();
    game->mark_board(8);
    game->game_over();
    game->mark_board(12);
    game->game_over();
    game->mark_board(9);
    game->game_over();
    game->mark_board(13);
    game->game_over();
    game->mark_board(11);
    game->game_over();
    game->mark_board(15);
    game->game_over();
    game->mark_board(14);
    game->game_over();
    game->mark_board(16);
    game->game_over();

    string winner = game->get_winner();

    REQUIRE(winner == "C");
}

TEST_CASE("Test win by first column 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(1);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(5);
    game->game_over();
    game->mark_board(3);
    game->game_over();
    game->mark_board(9);
    game->game_over();
    game->mark_board(4);
    game->game_over();
    game->mark_board(13);

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by second column 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(2);
    game->game_over();
    game->mark_board(1);
    game->game_over();
    game->mark_board(6);
    game->game_over();
    game->mark_board(3);
    game->game_over();
    game->mark_board(10);
    game->game_over();
    game->mark_board(4);
    game->game_over();
    game->mark_board(14);

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by third column 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(3);
    game->game_over();
    game->mark_board(1);
    game->game_over();
    game->mark_board(7);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(11);
    game->game_over();
    game->mark_board(4);
    game->game_over();
    game->mark_board(15);

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by fourth column 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(4);
    game->game_over();
    game->mark_board(1);
    game->game_over();
    game->mark_board(8);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(12);
    game->game_over();
    game->mark_board(3);
    game->game_over();
    game->mark_board(16);

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by first row 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(1);
    game->game_over();
    game->mark_board(5);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(6);
    game->game_over();
    game->mark_board(3);
    game->game_over();
    game->mark_board(7);
    game->game_over();
    game->mark_board(4);

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by second row 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(5);
    game->game_over();
    game->mark_board(1);
    game->game_over();
    game->mark_board(6);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(7);
    game->game_over();
    game->mark_board(3);
    game->game_over();
    game->mark_board(8);

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by third row 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(9);
    game->game_over();
    game->mark_board(1);
    game->game_over();
    game->mark_board(10);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(11);
    game->game_over();
    game->mark_board(3);
    game->game_over();
    game->mark_board(12);

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win by fourth row 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(13);
    game->game_over();
    game->mark_board(1);
    game->game_over();
    game->mark_board(14);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(15);
    game->game_over();
    game->mark_board(3);
    game->game_over();
    game->mark_board(16);

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win diagonally from top left 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(1);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(6);
    game->game_over();
    game->mark_board(3);
    game->game_over();
    game->mark_board(11);
    game->game_over();
    game->mark_board(4);
    game->game_over();
    game->mark_board(16);

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test win diagonally from bottom left 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    string first_player = "X";
    game->start_game(first_player);

    game->mark_board(4);
    game->game_over();
    game->mark_board(1);
    game->game_over();
    game->mark_board(7);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(10);
    game->game_over();
    game->mark_board(3);
    game->game_over();
    game->mark_board(13);

    string winner = game->get_winner();

    REQUIRE(game->game_over() == true);
    REQUIRE(winner == "X");
}

TEST_CASE("Test TicTacToe manager get winner total function 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    TicTacToeManager manager;
    int o, x, t;

    game->start_game("X");

    game->mark_board(1);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(5);
    game->game_over();
    game->mark_board(6);
    game->game_over();
    game->mark_board(9);
    game->game_over();
    game->mark_board(10);
    game->game_over();
    game->mark_board(13);
    game->game_over();

    manager.save_games(game);

    game->start_game("O");

    game->mark_board(1);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(5);
    game->game_over();
    game->mark_board(6);
    game->game_over();
    game->mark_board(9);
    game->game_over();
    game->mark_board(10);
    game->game_over();
    game->mark_board(13);
    game->game_over();

    manager.save_games(game);

    game->start_game("X");

    game->mark_board(1);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(3);
    game->game_over();
    game->mark_board(4);
    game->game_over();
    game->mark_board(6);
    game->game_over();
    game->mark_board(5);
    game->game_over();
    game->mark_board(7);
    game->game_over();
    game->mark_board(10);
    game->game_over();
    game->mark_board(8);
    game->game_over();
    game->mark_board(12);
    game->game_over();
    game->mark_board(9);
    game->game_over();
    game->mark_board(13);
    game->game_over();
    game->mark_board(11);
    game->game_over();
    game->mark_board(15);
    game->game_over();
    game->mark_board(14);
    game->game_over();
    game->mark_board(16);
    game->game_over();

    manager.save_games(game);

    manager.get_winner_total(o, x, t);

    REQUIRE(x == 1);
    REQUIRE(o == 1);
    REQUIRE(t == 1);
}
