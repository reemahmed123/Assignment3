#ifndef A3_TASK2_3_B_20221044_20221063_20221142_X_H
#define A3_TASK2_3_B_20221044_20221063_20221142_X_H
#include <iostream>
#include <string>

using namespace std;
class Board
{
protected:
    int n_rows, n_cols;
    char **board;
    int n_moves = 0;

public:
    virtual bool update_board(int x, int y, char symbol) = 0;
    virtual bool is_winner() = 0;
    virtual bool is_draw() = 0;
    virtual void display_board() = 0;
    virtual bool game_is_over() = 0;
};
class Player {
protected:
    string name;
    char symbol;
public:
    Player(char symbol);
    Player(int order, char symbol);
    virtual void get_move(int& x, int& y) ;
    string to_string();
    char get_symbol();
};
class X_O_Board:public Board {
public:
    X_O_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};
class TicTacToe_Board:public Board{
public:
    TicTacToe_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    bool is_valid(int x, int y);
};
class Connect4_Board:public Board {
public:
    Connect4_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};
class Pyramic_X_O_Board:public Board{

// ganna mohamed
// this is the new form I will use
//   1
// 2 3 4
//5 6 7 8 9

public:
    Pyramic_X_O_Board();
    bool  update_board (int x, int y, char mark);
    void  display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};
class TicTacToe_Player:public Player{
public:
    TicTacToe_Player(char symbol);
    TicTacToe_Player(int order, char symbol);
    void get_move(int &x, int &y);
    string to_string();
    char get_symbol();

};
class Connect4_Player:public Player{
public:
    Connect4_Player(char symbol);
    Connect4_Player(int order, char symbol);
    void get_move(int &x, int &y);
    string to_string();
    char get_symbol();
};
class Pyramic_X_O_Player:public Player{
public:
    Pyramic_X_O_Player(char symbol);
    Pyramic_X_O_Player(int order, char symbol);
    void get_move(int &x, int &y);
    string to_string();
    char get_symbol();
};
class RandomPlayer: public Player {
protected:
    int dimension;
public:
    // Take a symbol and pass it to parent
    RandomPlayer (char symbol, int dimension);
    // Generate a random move
    void get_move(int& x, int& y);
};
class TicTacToe_RandomPlayer:public TicTacToe_Player {
protected:
    int dimension;
public:
    // Take a symbol and pass it to parent
    TicTacToe_RandomPlayer(char symbol1, int dimension);
    void get_move(int &x, int &y);

};
class Connect4_RandomPlayer:public Connect4_Player{
protected:
    int Dimension1;
    int Dimension2;
public:
    // Take a symbol and pass it to parent
    Connect4_RandomPlayer (char symbol, int dimension1, int dimension2);
    // Generate a random move
    void get_move(int &x, int &y);
};
class Pyramic_X_O_RandomPlayer:public Pyramic_X_O_Player{
protected:
    int dimension;
public:
    // Take a symbol and pass it to parent
    Pyramic_X_O_RandomPlayer(char symbol1, int dimension);
    void get_move (int& x, int& y);
};
class GameManager {
private:
    Board* boardPtr;
    Player* players[2];
public:
    GameManager(Board*, Player* playerPtr[2]);
    void run();

};
class TicTacToe_GameManager{
private:
    TicTacToe_Player* players[2];
public:
    TicTacToe_GameManager(TicTacToe_Player* playerPtr[2]);
    void run();

};
class GameManager_connect4 {
private:
    Board* boardPtr;
    Connect4_Player* players[2];
public:
    GameManager_connect4(Board* bPtr, Connect4_Player* playerPtr[2]);
    void run();
};
class Pyramic_X_O_GameManager{
private:
    Board* boardPtr;
    Pyramic_X_O_Player* players[2];
public:
    Pyramic_X_O_GameManager(Board* bPtr, Pyramic_X_O_Player* playerPtr[2]);
    void run();
};
#endif
