#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

TEST_CASE("Verify Test Configuration", "verification") {
    REQUIRE(true == true);
}

TEST_CASE("Test first player set to X")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("X");
    REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("O");
    REQUIRE(game->get_player() == "O");
}



TEST_CASE("Test game over if 9 slots are selected")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
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

    REQUIRE(game->get_winner() == "C");
}

TEST_CASE("Test win by first column")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("X");

    game->mark_board(1);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(4);
    game->game_over();
    game->mark_board(5);
    game->game_over();
    game->mark_board(7);
    game->game_over();

    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second column")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("X");

    game->mark_board(2);
    game->game_over();
    game->mark_board(1);
    game->game_over();
    game->mark_board(5);
    game->game_over();
    game->mark_board(3);
    game->game_over();
    game->mark_board(8);
    game->game_over();

    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third column")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("X");

    game->mark_board(3);
    game->game_over();
    game->mark_board(1);
    game->game_over();
    game->mark_board(6);
    game->game_over();
    game->mark_board(4);
    game->game_over();
    game->mark_board(9);
    game->game_over();

    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by first row")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("X");

    game->mark_board(1);
    game->game_over();
    game->mark_board(4);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(5);
    game->game_over();
    game->mark_board(3);
    game->game_over();

    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second row")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("X");

    game->mark_board(4);
    game->game_over();
    game->mark_board(1);
    game->game_over();
    game->mark_board(5);
    game->game_over();
    game->mark_board(3);
    game->game_over();
    game->mark_board(6);
    game->game_over();

    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third row")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("X");

    game->mark_board(7);
    game->game_over();
    game->mark_board(1);
    game->game_over();
    game->mark_board(8);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(9);

    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by diagonal from top left")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("X");

    game->mark_board(1);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(5);
    game->game_over();
    game->mark_board(4);
    game->game_over();
    game->mark_board(9);
    game->game_over();

    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by diagonal from bottom left")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("X");

    game->mark_board(7);
    game->game_over();
    game->mark_board(2);
    game->game_over();
    game->mark_board(5);
    game->game_over();
    game->mark_board(4);
    game->game_over();
    game->mark_board(3);
    game->game_over();

    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Verify TicTacToeManager class with 3 played games")
{
    unique_ptr<TicTacToe> game1 = make_unique<TicTacToe3>();
    TicTacToeManager manager;
    int x_wins = 0;
    int o_wins = 0;
    int ties = 0;

    game1->start_game("X");


    game1->mark_board(3);
    game1->game_over();
    game1->mark_board(2);
    game1->game_over();
    game1->mark_board(5);
    game1->game_over();
    game1->mark_board(4);
    game1->game_over();
    game1->mark_board(7);

    game1->game_over();
    manager.save_games(game1);

    unique_ptr<TicTacToe> game2 = make_unique<TicTacToe3>();

    game2->start_game("O");

    game2->mark_board(3);
    game2->game_over();
    game2->mark_board(2);
    game2->game_over();
    game2->mark_board(5);
    game2->game_over();
    game2->mark_board(4);
    game2->game_over();
    game2->mark_board(7);

    game2->game_over();
    manager.save_games(game2);

    unique_ptr<TicTacToe> game3 = make_unique<TicTacToe3>();

    game3->start_game("X");

    game3->mark_board(2);
    game3->game_over();
    game3->mark_board(1);
    game3->game_over();
    game3->mark_board(5);
    game3->game_over();
    game3->mark_board(3);
    game3->game_over();
    game3->mark_board(6);
    game3->game_over();
    game3->mark_board(4);
    game3->game_over();
    game3->mark_board(7);
    game3->game_over();
    game3->mark_board(8);
    game3->game_over();
    game3->mark_board(9);

    game3->game_over();
    manager.save_games(game3);

    manager.get_winner_total(x_wins, o_wins, ties);

    REQUIRE(x_wins == 1);
    REQUIRE(o_wins == 1);
    REQUIRE(ties == 1);

}

TEST_CASE("Test first column winner for 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    game->start_game("X");

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

    REQUIRE(game->game_over()==true);
    REQUIRE(game->get_winner() == "X");

}

TEST_CASE("Test second column winner for 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    game->start_game("X");

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

    REQUIRE(game->game_over()==true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test third column winner for 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    game->start_game("X");

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

    REQUIRE(game->game_over()==true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test fourth column winner for 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    game->start_game("X");

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

    REQUIRE(game->game_over()==true);
    REQUIRE(game->get_winner() == "X");
}
TEST_CASE("Test first row winner for 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    game->start_game("X");

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

    REQUIRE(game->game_over()==true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test second row winner for 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    game->start_game("X");

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

    REQUIRE(game->game_over()==true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test third row winner for 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    game->start_game("X");

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

    REQUIRE(game->game_over()==true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test fourth row winner for 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    game->start_game("X");

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

    REQUIRE(game->game_over()==true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test top left diagonal winner for 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    game->start_game("X");

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

    REQUIRE(game->game_over()==true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test bottom left diagonal winner for 4x4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
    game->start_game("X");

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

    REQUIRE(game->game_over()==true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Verify TicTacToeManager class with 3 played games for 4x4")
{
    unique_ptr<TicTacToe> game1 = make_unique<TicTacToe4>();
    TicTacToeManager manager;
    int x_wins = 0;
    int o_wins = 0;
    int ties = 0;

    game1->start_game("X");


    game1->mark_board(1);
    game1->game_over();
    game1->mark_board(2);
    game1->game_over();
    game1->mark_board(5);
    game1->game_over();
    game1->mark_board(6);
    game1->game_over();
    game1->mark_board(9);
    game1->game_over();
    game1->mark_board(10);
    game1->game_over();
    game1->mark_board(13);
    game1->game_over();

    manager.save_games(game1);

    unique_ptr<TicTacToe> game2 = make_unique<TicTacToe4>();

    game2->start_game("O");

    game2->mark_board(1);
    game2->game_over();
    game2->mark_board(2);
    game2->game_over();
    game2->mark_board(5);
    game2->game_over();
    game2->mark_board(6);
    game2->game_over();
    game2->mark_board(9);
    game2->game_over();
    game2->mark_board(10);
    game2->game_over();
    game2->mark_board(13);
    game2->game_over();

    manager.save_games(game2);

    unique_ptr<TicTacToe> game3 = make_unique<TicTacToe4>();

    game3->start_game("X");

    game3->mark_board(1);
    game3->game_over();
    game3->mark_board(2);
    game3->game_over();
    game3->mark_board(3);
    game3->game_over();
    game3->mark_board(4);
    game3->game_over();
    game3->mark_board(6);
    game3->game_over();
    game3->mark_board(5);
    game3->game_over();
    game3->mark_board(7);
    game3->game_over();
    game3->mark_board(10);
    game3->game_over();
    game3->mark_board(8);
    game3->game_over();
    game3->mark_board(12);
    game3->game_over();
    game3->mark_board(9);
    game3->game_over();
    game3->mark_board(13);
    game3->game_over();
    game3->mark_board(11);
    game3->game_over();
    game3->mark_board(15);
    game3->game_over();
    game3->mark_board(14);
    game3->game_over();
    game3->mark_board(16);
    game3->game_over();

    game3->game_over();
    manager.save_games(game3);

    manager.get_winner_total(x_wins, o_wins, ties);

    REQUIRE(x_wins == 1);
    REQUIRE(o_wins == 1);
    REQUIRE(ties == 1);

}