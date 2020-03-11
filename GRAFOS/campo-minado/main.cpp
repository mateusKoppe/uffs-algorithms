#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct field {
    bool isBomb = false;
    bool isOpened = false;
    int bombsAround = 0;
};

class board {
    public:
        int rows, columns, bombsAmount;
        vector<vector<field>> fields;

        void generate () {
            fields.assign(rows, vector<field>(columns, field()));
            while (!generateBombs()) {
                cout << "The field size doest support this amount of bombs, enter again please.\n"
                    << "Bombs: ";
                cin >> bombsAmount;
            }
            calcBombs();
        }

        int getSize () {
            return rows * columns;
        }

        void render () {
            cout << "\n  ";

            for (int i = 1; i <= columns; i++) {
                cout << i << " ";
            }
            cout << "\n";
            for (int y = 0; y < rows; y++) {
                cout << y + 1 << " "; 
                for (int x = 0; x < columns; x++) {
                    renderField(y, x);
                }
                cout << "\n";
            }
        }

        void start () {
            generate();
            render();
            receiveInput();
        }

        void receiveInput () {
            int targetX, targetY;
            cout << "Enter the cordenate:\n"
                << "x: ";
            cin >> targetX;
            cout << "y: ";
            cin >> targetY;
            targetY--;
            targetX--;
            openField(targetY, targetX);
            render();
            receiveInput();
        }

    private:
        bool generateBombs () {
            if (bombsAmount >= getSize()) {
                return false;
            }

            srand((unsigned)time(NULL));

            int bombsInMap = 0;
            while (bombsInMap < bombsAmount) {
                int y = rand() % rows;
                int x = rand() % columns;
                if (fields[y][x].isBomb) {
                    continue;
                }
                fields[y][x].isBomb = true;
                bombsInMap++;
            }

            return true;
        }

        void calcBombs () {
            for (int y = 0; y < rows; y++) {
                for (int x = 0; x < columns; x++) {
                    fields[y][x].bombsAround = getBombsAroundField(y, x);
                }
            }
        }

        int getBombsAroundField (int fieldY, int fieldX) {
            vector<int> range = {-1, 0, 1};
            int bombsAround = 0;
            field actualField = fields[fieldY][fieldX];
            for (int y : range) {
                for (int x : range) {
                    int targetX = x + fieldX;
                    int targetY = y + fieldY;
                    if (targetY < 0 || targetX < 0 || targetY >= rows || targetX >= columns) continue;
                    if ((y == 0 && x == 0)) continue;
                    field targetField = fields[targetY][targetX];
                    if (targetField.isBomb) {
                        bombsAround++;
                    }
                }
            }
            return bombsAround;
        }

        void renderField (int y, int x) {
            if (!fields[y][x].isOpened) {
                cout << "= ";
            } else if (fields[y][x].isBomb) {
                cout << "B ";    
            } else { 
                cout << fields[y][x].bombsAround << " ";
            }
        }

        void openField (int fieldY, int fieldX) {
            fields[fieldY][fieldX].isOpened = true;
            vector<int> range = {-1, 0, 1};
            for (int y : range) {
                for (int x : range) {
                    int targetX = x + fieldX;
                    int targetY = y + fieldY;
                    if (targetY < 0 || targetX < 0 || targetY >= rows || targetX >= columns) continue;
                    if ((y == x || y == x * -1)) continue;
                    field *targetField = &fields[targetY][targetX];
                    if (targetField->isBomb || targetField->isOpened) continue;
                }
            }
        }
};

int main () {
    board gameBoard;

    cout << "Rows: ";
    cin >> gameBoard.rows;
    cout << "Columns: ";
    cin >> gameBoard.columns;
    cout << "Bombs: ";
    cin >> gameBoard.bombsAmount;

    gameBoard.start();
}