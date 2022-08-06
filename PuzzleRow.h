// CS201-HW3
// Eylül Badem - 22003079
// 27.04.2022

#include <iostream>
using namespace std;

class PuzzleRow
{
private:
    struct PuzzlePiece
    {
        char shape;
        int rowindex;
        int colindex;
        PuzzlePiece *next;
    };
    PuzzlePiece *head;
    PuzzleRow *next;
    int rowindex;
    int maxSize; // equals to puzzleContainer width

public:
    void shapeConverter(char shape, int &down, int &up, int &right, int &left);
    PuzzleRow();
    PuzzleRow(int size, int rowindex);
    ~PuzzleRow();
    int getRowIndex();
    void setNext(PuzzleRow *next);
    PuzzleRow *getNext();
    bool insert(int index, char shape);
    bool remove(int index);
    bool isEmpty();
    char getPiece(int index);
    void printRow();
};