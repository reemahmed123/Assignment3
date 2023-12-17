#include"../include/BoardGame_Classes.hpp"
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;

// ganna mohamed
// this is the new form i will use
//   1
// 2 3 4
//5 6 7 8 9


Pyramic_X_O_Board::Pyramic_X_O_Board() {
    n_rows = 3, n_cols = 5 ;
    board = new char*;
    board[0] = new char[9] ;
    for (int i = 0; i < 9; i++) { // only one array of size 9
            board[0][i] = 0; //first[0] for the char pointer and [i] for refering the array
    }

}

bool Pyramic_X_O_Board:: update_board (int x, int y, char mark) {
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
void Pyramic_X_O_Board :: display_board(){
    cout << "        " <<"|00|" <<board[0][0] << endl ;
    cout << "    "<<"|01|" <<board[0][1] <<"|02|" <<board[0][2] <<"|03|" <<board[0][3] << endl ;
    cout <<"|04|" <<board[0][4] <<"|05|" <<board[0][5] <<"|06|" <<board[0][6] <<"|07|" <<board[0][7]<<"|08|" <<board[0][8] <<endl ;

}
bool Pyramic_X_O_Board::is_winner(){
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
bool Pyramic_X_O_Board::is_draw(){
    return (n_moves == 9 && !is_winner());
}
bool Pyramic_X_O_Board::game_is_over(){
    return n_moves >= 9;
}