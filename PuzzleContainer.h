// CS201-HW3
// Eylül Badem - 22003079
// 27.04.2022

#include "PuzzleRow.h"

class PuzzleContainer
{
private:
    PuzzleRow *rowLists;
    int height;
    int width;

public:
    PuzzleContainer(int h, int w);
    ~PuzzleContainer();
    PuzzleRow *getRow(int index);
    bool insertRow(int index);
    bool removeRow(int index);
    bool addPiece(int row, int col, char shape);
    bool removePiece(int row, int col);
    int getHeight();
    int getWidth();
    void showPiece(int row, int col);
    void displayContainer();
    void showColumn(int col);
    void showRow(int row);
    void findPiece(char shape);
};