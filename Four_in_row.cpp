#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>

using namespace std;
class Board {
protected:
int n_rows, n_cols;
char** board;
int n_moves = 0;

public:
virtual bool update_board (int x, int y, char symbol) = 0;
virtual bool is_winner() = 0;
virtual bool is_draw() = 0;
virtual void display_board() = 0;
virtual bool game_is_over() = 0;
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
class X_O_Board:public Board {
public:
X_O_Board ();
bool update_board (int x, int y, char mark);
void display_board();
bool is_winner();
bool is_draw();
bool game_is_over();
};
class Player {
protected:
string name;
char symbol;
public:
Player (char symbol); // Needed for computer players
Player (int order, char symbol);
virtual void get_move(int& x, int& y);
// Give player info as a string
string to_string();
// Get symbol used by player
char get_symbol();
};

class RandomPlayer: public Player {
protected:
int dimension;
public:
RandomPlayer (char symbol, int dimension);
// Generate a random move
void get_move(int& x, int& y);
};

///////////////////////////////////////////
class GameManager {
private:
Board* boardPtr;
Player* players[2];
public:
GameManager(Board*, Player* playerPtr[2]);
void run();

};

// Set the board
Connect4_Board::Connect4_Board (){
n_rows =6;
n_cols = 7;
board = new char*[n_rows];
for (int i = 0; i < n_rows; i++) {
board [i] = new char[n_cols];
for (int j = 0; j < n_cols; j++)
board[i][j] = 0;
}
}

// Return true if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Connect4_Board::update_board (int x, int y, char mark){
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
// Display the board and the pieces on it
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

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
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

bool Connect4_Board::game_is_over () {
return n_moves >= 42;
}GameManager::GameManager(Board* bPtr, Player* playerPtr[2] ) {
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
}Player::Player(char symbol) {
this->symbol = symbol;
}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
Player::Player (int order, char symbol) {
cout << "Welcome player " << order << endl;
cout << "Please enter your name: ";
cin >> name;
this->symbol = symbol;
}

void Player::get_move (int& x, int& y) {
cout << "\nPlease enter your move x (0 to 5) and y (0 to 6) separated by spaces: ";
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
X_O_Board::X_O_Board () {
n_rows = n_cols = 3;
board = new char*[n_rows];
for (int i = 0; i < n_rows; i++) {
board [i] = new char[n_cols];
for (int j = 0; j < n_cols; j++)
board[i][j] = 0;
}
}

// Return true if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
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
void main_menue(){
cout<<"You can choose any game from app if you press the number of it :\n";
cout<<"0- X_O Game\n";
cout<<"2- Connect4_Game\n";
}
void Select_Game(int &choice, Board* &board){
    cin>>choice;
    switch (choice){
    case 0:
    cout << "Welcome to FCAI X-O Game. :)\n";
    board=new X_O_Board();
        break;
    
    case 2:
    cout << "Welcome to FCAI Connect4 Game. :)\n";
    board=new Connect4_Board();
        break;
    
    }
}
int main(){
    int choice1,choice2;
    Board* board;
    Player* players[2];
    players[0] = new Player (1, 'x');
    main_menue();
    Select_Game(choice1,board);
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice2;
    if (choice2 != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    GameManager x_o_game (board, players);
    x_o_game.run();
    system ("pause");
    }