#include <iostream>
#include "X_O_Board_App.h"

using namespace std;
void main_menu(){
    cout<<"You can choose any game from app if you press the number of it :\n";
    cout<<"1- 5 x 5 Tic Tac Toe\n";
    cout<<"2- Four-in-a-row\n";
    cout<<"3- Pyramic Tic-Tac-Toe\n";
    cout<<"4- 3 x 3 Tic Tac Toe\n";
}
void Select_Game(int &choice, Board* &board){
    cin>>choice;
    switch (choice){
        case 1:{
            TicTacToe_Player* PLAYERS[2];
            PLAYERS[0] = new TicTacToe_Player (1, 'x');
            int choice;
            cout << "\nPress 1 if you want to play against another player " ;
            cout << "\nPress 2 if you want a random computer player: ";
            cin >> choice;
            if (choice == 1)
                PLAYERS[1] = new TicTacToe_Player (2, 'o');
            else
                PLAYERS[1] = new TicTacToe_RandomPlayer ('o', 5);
            board = new TicTacToe_Board;
            TicTacToe_GameManager game1(PLAYERS);
            game1.run();
        }break;
        case 2:{
            Connect4_Player*players[2];
            players[0] = new Connect4_Player (1, 'x');
            int choice;
            cout << "\nPress 1 if you want to play against another player";
            cout << "\nPress 2 if you want a random computer player: ";
            cin >> choice;
            if (choice == 1)
                players[1] = new Connect4_Player (2, 'o');
            else
                players[1] = new Connect4_RandomPlayer ('o',6,7);
            board = new Connect4_Board();
            GameManager_connect4 game2(board,players);
            game2.run();
        }break;
        case 3:{
            Pyramic_X_O_Player*players[2];
            players[0] = new Pyramic_X_O_Player (1, 'x');
            int choice;
            cout << "\nPress 1 if you want to play against another player";
            cout << "\nPress 2 if you want a random computer player: ";
            cin >> choice;
            if (choice == 1)
                players[1] = new Pyramic_X_O_Player (2, 'o');
            else
                players[1] = new Pyramic_X_O_RandomPlayer ('o',3);
            board = new Pyramic_X_O_Board();
            Pyramic_X_O_GameManager game3(board,players);
            game3.run();
        }break;
        case 4:
            Player* players[2];
            players[0] = new Player (1, 'x');
            int choice;
            cout << "\nPress 1 if you want to play against another player";
            cout << "\nPress 2 if you want a random computer player: ";
            cin >> choice;
            if (choice == 1)
                players[1] = new Player (2, 'o');
            else
                players[1] = new RandomPlayer ('o',3);
            board = new X_O_Board();
            GameManager game4(board,players);
            game4.run();
            break;
    }

}

int main() {
    int choice1;
    Board* board;
    cout << "Welcome to FCAI X-O Game :)\n";
    main_menu();
    Select_Game(choice1,board);
    system ("pause");
}
