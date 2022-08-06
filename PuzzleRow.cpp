// CS201-HW3
// Eylül Badem - 22003079
// 27.04.2022

#include "PuzzleRow.h"

void PuzzleRow::shapeConverter(char shape, int &down, int &up, int &right, int &left)
{
    down = shape % 4;
    up = (shape / 4) % 4;
    right = (shape / 16) % 4;
    left = shape / 64;
}

PuzzleRow::PuzzleRow()
{
}
PuzzleRow::PuzzleRow(int size, int rowindex)
{
    int count = 0;
    PuzzlePiece *newNode = new PuzzlePiece();
    newNode->shape = 255;
    newNode->next = head;
    head = newNode;

    PuzzlePiece *prev = head;
    while (count < size)
    {
        PuzzlePiece *newNode = new PuzzlePiece();
        newNode->shape = 255;
        ;
        prev->next = newNode;
        prev = prev->next;
        count++;
    }

    maxSize = size;
    this->rowindex = rowindex;
}
PuzzleRow::~PuzzleRow()
{
    // PuzzlePiece *current = head;
    // while (current != NULL)
    // {
    //     PuzzlePiece *next = current->next;
    //     delete current;
    //     current = next;
    // }
    // head = NULL;
}
int PuzzleRow::getRowIndex()
{
    return rowindex;
}
void PuzzleRow::setNext(PuzzleRow *next)
{
    this->next = next;
}
PuzzleRow *PuzzleRow::getNext()
{
    return this->next;
}
bool PuzzleRow::insert(int index, char shape)
{
    int down, up, right, left;
    int checkDown, checkUp, checkRight, checkLeft;

    shapeConverter(shape, down, up, right, left);

    if ((this->next == NULL && down != 2) || (this->next != NULL && down == 2))
    {
        cout << "Shape doesn't fit into "
             << "(" << rowindex + 1 << "," << index + 1 << "),"
             << " it cannot be added" << endl;
        return false;
    }
    if ((rowindex == 0 && up != 2) || (rowindex != 0 && up == 2))
    {
        cout << "Shape doesn't fit into "
             << "(" << rowindex + 1 << "," << index + 1 << "),"
             << " it cannot be added" << endl;
        return false;
    }
    if ((index == maxSize - 1 && right != 2) || (index != maxSize - 1 && right == 2))
    {
        cout << "Shape doesn't fit into "
             << "(" << rowindex + 1 << "," << index + 1 << "),"
             << " it cannot be added" << endl;
        return false;
    }
    if ((index == 0 && left != 2) || (index != 0 && left == 2))
    {
        cout << "Shape doesn't fit into "
             << "(" << rowindex + 1 << "," << index + 1 << "),"
             << " it cannot be added" << endl;
        return false;
    }

    shapeConverter(getPiece(index - 1), checkDown, checkUp, checkRight, checkLeft);
    if ((getPiece(index - 1) != (char)255) && ((checkRight == 1 && left != 0) || (checkRight == 0 && left != 1)))
    {
        cout << "Shape doesn't fit into "
             << "(" << rowindex + 1 << "," << index + 1 << "),"
             << " it cannot be added" << endl;
        return false;
    }
    shapeConverter(getPiece(index + 1), checkDown, checkUp, checkRight, checkLeft);
    if ((getPiece(index + 1) != (char)255) && ((checkLeft == 1 && right != 0) || (checkLeft == 0 && right != 1)))
    {
        cout << "Shape doesn't fit into "
             << "(" << rowindex + 1 << "," << index + 1 << "),"
             << " it cannot be added" << endl;
        return false;
    }
    // BASIC INSERTION (WITHOUT CHECKING SHAPES OF ADJACENT TILES)
    // TO TEST IF INSERTION WORKS AT ALL
    // START
    int count = 0;
    PuzzlePiece *temp = head;
    while (count < index)
    {
        temp = temp->next;
        count++;
    }
    temp->shape = shape;
    // END
    // ***WORKS***
    cout << "A piece is added to (" << rowindex + 1 << "," << index + 1 << ")" << endl;
    return true;
}
bool PuzzleRow::remove(int index)
{
    int count = 0;
    PuzzlePiece *temp = head;

    while (count < index)
    {
        temp = temp->next;
        count++;
    }
    temp->shape = (char)255;
    cout << "The piece on "
         << "(" << rowindex + 1 << "," << index + 1 << ")"
         << " is removed" << endl;
    return true;
}
bool PuzzleRow::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}
char PuzzleRow::getPiece(int index)
{
    PuzzlePiece *tempHead = head;
    int count = 0;
    while (count < index)
    {
        tempHead = tempHead->next;
        count++;
    }
    if (tempHead->shape != (char)255)
    {
        return tempHead->shape;
    }

    return 255;
}
void PuzzleRow::printRow()
{
    int count = 0;
    while (count < maxSize)
    {
        if (getPiece(count) == (char)255)
        {
            cout << "O ";
        }
        else
        {
            cout << "X ";
        }
        count++;
    }
    cout << endl;
}
