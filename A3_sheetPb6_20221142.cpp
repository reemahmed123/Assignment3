#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;
class Universe {
private:
    vector<vector<bool>> cells;
    int rows;
    int cols;
public:
    Universe(int rows, int cols): rows(rows), cols(cols), cells(rows, vector<bool>(cols, false)) {}
    void initialize(){
        srand(time(NULL));
        for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cells[i][j] = (rand() % 2 == 0);
        }
        }
    }
    int count_neighbors(int row, int col){
        int count = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                int newRow = (row + i + rows) % rows;
                int newCol = (col + j + cols) % cols;
                if (cells[newRow][newCol]) count++;
            }
        }
        return count;
    }

    void next_generation(){
        vector<vector<bool>> newCells(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int liveNeighbors = count_neighbors(i, j);
                if (cells[i][j] && (liveNeighbors == 2 || liveNeighbors == 3)){
                    newCells[i][j] = true;
                }
                else if (!cells[i][j] && liveNeighbors == 3) {
                    newCells[i][j] = true;
                } else{
                    newCells[i][j] = false;
                }
            }
        }
        cells = newCells;
    }
    void row_line() const {
        for (int i = 0; i < cols; i++) {
            cout << "--";
        }
        cout<<endl;
    }
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << (cells[i][j] ? 1 : 0);
            }
            cout << endl;
        }

    }
    void run(int num_generations){
        for (int i = 0; i < num_generations; i++) {
            display();
            row_line();
            next_generation();

        }
    }


};

int main() {
    Universe universe(15, 35);
    universe.initialize();
    universe.run(3);
    return 0;
}