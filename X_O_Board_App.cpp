#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "X_O_Board_App.h"
using namespace std;
short count_x, count_o;


Player::Player(int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name ;
    this->symbol = symbol;

}
void Player::get_move (int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}

// Give player info as a string
string Player::to_string(){
    return "Player: " + name ;
}

// Get symbol used by player
char Player::get_symbol() {
    return symbol;
}

Player::Player(char symbol) {
    this->symbol = symbol;
}


TicTacToe_Board::TicTacToe_Board() {
    n_rows = n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool TicTacToe_Board::update_board(int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void TicTacToe_Board::display_board() {
    {
        for (int i : {0, 1, 2, 3, 4})
        {
            cout << "\n| ";
            for (int j : {0, 1, 2, 3, 4})
            {
                cout << setw(2) << board[i][j] << " |";
            }
            cout << "\n----------------------";
        }
        cout << endl;
    }
}

bool TicTacToe_Board::is_winner(){
    if (n_moves == 24)
    {
        for (int i : {0, 1, 2, 3, 4})
        {
            for (int j : {1, 2, 3})
            {
                if (board[i][j] == board[i][j - 1] && board[i][j] == board[i][j + 1])
                {
                    if (board[i][j] == 'X')
                        count_x++;
                    else if (board[i][j] == 'O')
                        count_o++;
                }
            }
        }
        for (int i : {1, 2, 3})
        {
            for (int j : {0, 1, 2, 3, 4})
            {
                if (board[i][j] == board[i - 1][j] && board[i][j] == board[i + 1][j])
                {
                    if (board[i][j] == 'X')
                        count_x++;
                    else if (board[i][j] == 'O')
                        count_o++;
                }
            }
        }
        for (int i : {1, 2, 3})
        {
            for (int j : {1, 2, 3})
            {
                for (int k : {1})
                {
                    if (board[i][j] == board[i - k][j - k] && board[i][j] == board[i + k][j + k])
                    {
                        if (board[i][j] == 'X')
                            count_x++;
                        else if (board[i][j] == 'O')
                            count_o++;
                    }
                    if (board[i][j] == board[i - k][j + k] && board[i][j] == board[i + k][j - k])
                    {
                        if (board[i][j] == 'X')
                            count_x++;
                        else if (board[i][j] == 'O')
                            count_o++;
                    }
                }
            }
        }
        if (count_x != count_o)
            return true;

        return false;

    }

}

bool TicTacToe_Board::is_draw(){
    return (n_moves == 24 && !is_winner());
}

bool TicTacToe_Board::game_is_over() {
    return n_moves >= 24;
}

bool TicTacToe_Board::is_valid(int x, int y){
    if(board[x][y] == 0){
        return true;
    } else
        return false;
}


Pyramic_X_O_Board::Pyramic_X_O_Board() {
    n_rows = 3, n_cols = 5 ;
    board = new char*;
    board[0] = new char[9] ;
    for (int i = 0; i < 9; i++) { // only one array of size 9
        board[0][i] = 0; //first[0] for the char pointer and [i] for refering the array
    }

}

bool Pyramic_X_O_Board::update_board(int x, int y, char mark){
    // Only update if move is valid
    if (x != 0 || !(y >= 0 && y <= 8)) { // iwant the user to enter num from 0 to 8
        return false;
    }

    if ( board[x][y] == 0 ){
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }

    return false;
}

void Pyramic_X_O_Board::display_board() {

    cout << "        " <<"|00|" <<board[0][0] << endl ;
    cout << "    "<<"|01|" <<board[0][1] <<"|02|" <<board[0][2] <<"|03|" <<board[0][3] << endl ;
    cout <<"|04|" <<board[0][4] <<"|05|" <<board[0][5] <<"|06|" <<board[0][6] <<"|07|" <<board[0][7]<<"|08|" <<board[0][8] <<endl ;


}

bool Pyramic_X_O_Board::is_winner() {
    if(board[0][0] == board[0][2] && board[0][2] == board[0][6] && board[0][0]  != 0 )
        return true;
    else if(board[0][1] == board[0][2] && board[0][2] == board[0][3] && board[0][1]  != 0 )
        return true;
    else if(board[0][4] == board[0][5] && board[0][5] == board[0][6] && board[0][4]  != 0 )
        return true;
    else if(board[0][5] == board[0][6] && board[0][6] == board[0][7] && board[0][5]  != 0 )
        return true;
    else if(board[0][6] == board[0][7] && board[0][7] == board[0][8] && board[0][6]  != 0 )
        return true;
    else if(board[0][0] == board[0][3] && board[0][3] == board[0][8] && board[0][0]  != 0 )
        return true;
    else if(board[0][0] == board[0][1] && board[0][1] == board[0][4] && board[0][0]  != 0 )
        return true;
    else
        return false;

}

bool Pyramic_X_O_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool Pyramic_X_O_Board::game_is_over() {
    return n_moves >= 9;
}

TicTacToe_Player::TicTacToe_Player(char symbol) : Player(symbol) {}

TicTacToe_Player::TicTacToe_Player(int order, char symbol) : Player(order, symbol) {

}

void TicTacToe_Player::get_move(int &x, int &y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

string TicTacToe_Player::to_string() {
    return name;
}

char TicTacToe_Player::get_symbol() {
    return symbol;
}

Pyramic_X_O_Player::Pyramic_X_O_Player(char symbol) : Player(symbol) {}

Pyramic_X_O_Player::Pyramic_X_O_Player(int order, char symbol) : Player(order, symbol) {}

void Pyramic_X_O_Player::get_move(int &x, int &y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}

string Pyramic_X_O_Player::to_string() {
    return name;
}

char Pyramic_X_O_Player::get_symbol() {
    return symbol;
}

TicTacToe_RandomPlayer::TicTacToe_RandomPlayer(char symbol1, int dimension) : TicTacToe_Player(symbol1) {
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

void TicTacToe_RandomPlayer::get_move(int &x, int &y) {
    x = (int) (rand() / (RAND_MAX + 1.0) * dimension);
    y = (int) (rand() / (RAND_MAX + 1.0) * dimension);
}

Pyramic_X_O_RandomPlayer::Pyramic_X_O_RandomPlayer(char symbol1, int dimension): Pyramic_X_O_Player(symbol1) {
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

void Pyramic_X_O_RandomPlayer::get_move(int &x, int &y) {
    x = 0;
    y = (int) (rand()/(RAND_MAX + 1.0) * 9);
}

TicTacToe_GameManager::TicTacToe_GameManager(TicTacToe_Player **playerPtr) {
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void TicTacToe_GameManager::run() {
    TicTacToe_Board x1;
    while (!x1.game_is_over()) {
        for (int i = 1; i <= 12; i++) {
            int x, y;
            for (int i = 0; i < 2; i++) {
                x1.display_board();
                cout << players[i]->get_symbol() << ": turn";
                players[i]->get_move(x, y);
                if(x1.is_valid(x,y)) {
                    x1.update_board(x, y, players[i]->get_symbol());
                } else{
                    while (!x1.is_valid(x,y)){
                        players[i]->get_move(x, y);
                    }
                    x1.update_board(x, y, players[i]->get_symbol());
                }
            }
        }


    }
    x1.display_board();
    x1.is_winner();
    if (count_x > count_o)
    {
        cout << players[0]->to_string() << " wins\n";
        return;
    }
    else if (count_x < count_o)
    {
        cout << players[1]->to_string() << " wins\n";
        return;
    }
    else if (x1.is_draw())
    {
        cout << "Draw!\n";
        return;
    }

}

Pyramic_X_O_GameManager::Pyramic_X_O_GameManager(Board *bPtr, Pyramic_X_O_Player **playerPtr) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void Pyramic_X_O_GameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}

Connect4_Board::Connect4_Board() {
    n_rows =6;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool Connect4_Board::update_board(int x, int y, char mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= n_rows || y < 0 || y >= n_cols) && (board[x][y] == 0)) {
        for(int i=0;i<i<n_rows;i++){
            if(board[5-i][y]==0){
                board[5-i][y] = toupper(mark);
                n_moves++;
                return true;
            }
        }
    }
    else
        return false;
}

void Connect4_Board::display_board() {
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n----------------------------------------------------------";
    }
    cout << endl;
}

bool Connect4_Board::is_winner() {
    // Check for a horizontal win
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j <= n_cols - 4; j++) {
            if (board[i][j] !=0 && board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
                return true;
            }
        }
    }

// Check for a vertical win
    for (int i = 0; i <= n_rows - 4; i++) {
        for (int j = 0; j < n_cols; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j]) {
                return true;
            }
        }
    }
// Check for a diagonal win (from top left to bottom right)
    for (int i = 0; i <= n_rows - 4; i++) {
        for (int j = 0; j <= n_cols - 4; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]) {
                return true;
            }
        }
    }

// Check for a diagonal win (from top right to bottom left)
    for (int i = 3; i < n_rows ; i++) {
        for (int j = 0; j <= n_cols-4; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i - 1][j + 1] &&
                board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3]) {
                return true;
            }
        }
    }

    return false; // No winner
}

bool Connect4_Board::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool Connect4_Board::game_is_over() {
    return n_moves >= 42;
}

Connect4_Player::Connect4_Player(char symbol) : Player(symbol) {}

Connect4_Player::Connect4_Player(int order, char symbol) : Player(order, symbol) {}

void Connect4_Player::get_move(int &x, int &y) {
    cout << "\nPlease enter your move x (0 to 5) and y (0 to 6) separated by spaces: ";
    cin >> x >> y;
}

string Connect4_Player::to_string() {
    return name;
}

char Connect4_Player::get_symbol() {
    return symbol;
}

GameManager_connect4::GameManager_connect4(Board *bPtr, Connect4_Player **playerPtr) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager_connect4::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}


X_O_Board::X_O_Board() {
    n_rows = n_cols = 3;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool X_O_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void X_O_Board::display_board() {
    for (int i: {0,1,2}) {
        cout << "\n| ";
        for (int j: {0,1,2}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool X_O_Board::is_winner() {
    char row_win[3], col_win[3], diag_win[2];
    for (int i:{0,1,2}) {
        row_win[i] = board[i][0] & board[i][1] & board[i][2];
        col_win[i] = board[0][i] & board[1][i] & board[2][i];
    }
    diag_win[0] = board[0][0] & board[1][1] & board[2][2];
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];

    for (int i:{0,1,2}) {
        if ( (row_win[i] && (row_win[i] == board[i][0])) ||
             (col_win[i] && (col_win[i] == board[0][i])) )
        {return true;}
    }
    if ((diag_win[0] && diag_win[0] == board[1][1]) ||
        (diag_win[1] && diag_win[1] == board[1][1]))
    {return true;}
    return false;
}

// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool X_O_Board::game_is_over () {
    return n_moves >= 9;
}
RandomPlayer::RandomPlayer (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPlayer::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}
GameManager::GameManager(Board* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}

Connect4_RandomPlayer::Connect4_RandomPlayer(char symbol, int dimension1, int dimension2): Connect4_Player(symbol) {
    this->Dimension1= dimension1;
    this->Dimension2= dimension2;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

void Connect4_RandomPlayer::get_move(int &x, int &y) {
    x = (int) (rand() / (RAND_MAX + 1.0) * Dimension1);
    y = (int) (rand() / (RAND_MAX + 1.0) * Dimension2);
}
