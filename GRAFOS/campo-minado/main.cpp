#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct block {
    bool isBomb = false;
};

int rows, columns, bombsAmount;
vector<vector<block>> field;

int main () {
    cout << "Rows: ";
    cin >> rows;
    cout << "Columns: ";
    cin >> columns;
    cout << "Bombs: ";
    cin >> bombsAmount;

    field.assign(rows, vector<block>(columns, block()));

    srand((unsigned)time(NULL));

    for (int i = 0; i < bombsAmount; i++) {
        int y = rand() % rows;
        int x = rand() % columns;
        field[y][x].isBomb = true;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << field[i][j].isBomb << " ";
        }
        cout << "\n";
    }
}