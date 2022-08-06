// CS201-HW3
// Eylül Badem - 22003079
// 27.04.2022

#include "PuzzleContainer.h"

PuzzleContainer::PuzzleContainer(int h, int w)
{
    PuzzleRow *temp;
    rowLists = new PuzzleRow[h];

    for (int i = 0; i < h; i++)
    {
        temp = new PuzzleRow(w, i);
        rowLists[i] = *temp;
        if (i > 0)
        {
            rowLists[i - 1].setNext(temp);
        }
    }
    height = h;
    width = w;
}
PuzzleContainer::~PuzzleContainer()
{
    // delete[] rowLists;
}
PuzzleRow *PuzzleContainer::getRow(int index)
{
    return NULL;
}
bool PuzzleContainer::PuzzleContainer::insertRow(int index)
{
    return true;
}
bool PuzzleContainer::removeRow(int index)
{
    return true;
}
bool PuzzleContainer::addPiece(int row, int col, char shape)
{

    if (row > height || col > width || col <= 0 || row <= 0)
    {
        cout << "(" << row << "," << col << ")"
             << " is out of frame, it cannot be added." << endl;
        return false;
    }
    if (rowLists[row - 1].getPiece(col - 1) != (char)255)
    {
        cout << "(" << row << "," << col << ")"
             << " has been already occupied, it cannot be added." << endl;
        return false;
    }

    PuzzleRow temp;
    int down, up, right, left;
    int checkDown, checkUp, checkRight, checkLeft;

    temp.shapeConverter(shape, down, up, right, left);

    if (row > 1 && rowLists[row - 2].getPiece(col - 1) != (char)255)
    {
        rowLists[row - 2].shapeConverter(rowLists[row - 2].getPiece(col - 1), checkDown, checkUp, checkRight, checkLeft);
        if ((checkDown == 1 && up != 0) || (checkDown == 0 && up != 1))
        {
            cout << "Shape doesn't fit into "
                 << "(" << row << "," << col << "),"
                 << " it cannot be added" << endl;
            return false;
        }
    }

    if (row < height && rowLists[row].getPiece(col - 1) != (char)255)
    {
        rowLists[row].shapeConverter(rowLists[row].getPiece(col - 1), checkDown, checkUp, checkRight, checkLeft);
        if ((checkUp == 1 && down != 0) || (checkUp == 0 && down != 1))
        {
            cout << "Shape doesn't fit into "
                 << "(" << row << "," << col << "),"
                 << " it cannot be added" << endl;
            return false;
        }
    }

    rowLists[row - 1].insert(col - 1, shape);
    return true;
}
bool PuzzleContainer::removePiece(int row, int col)
{
    if (row > height || col > width || col <= 0 || row <= 0)
    {
        cout << "(" << row << "," << col << ")"
             << " is out of frame, it cannot be removed." << endl;
        return false;
    }
    if (rowLists[row - 1].getPiece(col - 1) == (char)255)
    {
        cout << "There is no piece on "
             << "(" << row << "," << col << "),"
             << " it cannot be removed." << endl;
        return false;
    }
    rowLists[row - 1].remove(col - 1);
    return true;
}
int PuzzleContainer::getHeight()
{
    return height;
}
int PuzzleContainer::getWidth()
{
    return width;
}
void PuzzleContainer::showPiece(int row, int col)
{
    if (row > height || col > width || col <= 0 || row <= 0)
    {
        cout << "(" << row << "," << col << ")"
             << " is out of frame, it cannot be added." << endl;
        return;
    }
    if (rowLists[row - 1].getPiece(col - 1) == (char)255)
    {
        cout << "There is no piece on "
             << "(" << row << "," << col << "),"
             << " it cannot be shown." << endl;
        return;
    }
    int down, up, right, left;
    rowLists[row - 1].shapeConverter(rowLists[row - 1].getPiece(col - 1), down, up, right, left);
    cout << "Piece on "
         << "(" << row << "," << col << ")"
         << " as following:" << endl;

    cout << "Down: ";
    switch (down)
    {
        case 0:
            cout << "Hole";
            break;
        case 1:
            cout << "Knob";
            break;
        case 2:
            cout << "Border";
            break;
    }
    cout << endl;
    cout << "Up: ";
    switch (up)
    {
        case 0:
            cout << "Hole";
            break;
        case 1:
            cout << "Knob";
            break;
        case 2:
            cout << "Border";
            break;
    }
    cout << endl;
    cout << "Right: ";
    switch (right)
    {
        case 0:
            cout << "Hole";
            break;
        case 1:
            cout << "Knob";
            break;
        case 2:
            cout << "Border";
            break;
    }
    cout << endl;
    cout << "Left: ";
    switch (left)
    {
        case 0:
            cout << "Hole";
            break;
        case 1:
            cout << "Knob";
            break;
        case 2:
            cout << "Border";
            break;
    }
    cout << endl;
}
void PuzzleContainer::displayContainer()
{
    cout << "Container " << height << "x" << width << endl;
    cout << "  ";
    for (int i = 0; i < width; i++)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < height; i++)
    {
        cout << i + 1 << " ";
        rowLists[i].printRow();
    }
}
void PuzzleContainer::showColumn(int col)
{
    if (col <= width && col > 0)
    {
        int count = 0;
        cout << "Column " << col << ": " << endl;
        while (count < height)
        {
            if (rowLists[count].getPiece(col - 1) == (char)255)
            {
                cout << "O " << endl;
            }
            else
            {
                cout << "X " << endl;
            }
            count++;
        }
    }
    else
    {
        cout << "Column " << col << " is out of border" << endl;
    }
}
void PuzzleContainer::showRow(int row)
{
    if (row != 0 && row - 1 < height)
    {
        cout << "Row " << row << ": " << endl;
        rowLists[row - 1].printRow();
    }
    else
    {
        cout << "Row " << row << " is out of border" << endl;
    }
}
void PuzzleContainer::findPiece(char shape)
{
    int down = 0;
    int up = 0;
    int right = 0;
    int left = 0;
    PuzzleRow temp;
    temp.shapeConverter(shape, down, up, right, left);
    int found = -1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (rowLists[i].getPiece(j) == shape)
            {
                found = 0;
                cout << "(" << i + 1 << "," << j + 1 << "), ";
            }
        }
    }
    if (found == -1)
    {
        // lot not found throw an exception
        cout << "There is no piece that has shape" << endl;
    }
    else
    {
        cout << " contain the piece that has shape" << endl;
    }
    cout << "Down: ";
    switch (down)
    {
        case 0:
            cout << "Hole";
            break;
        case 1:
            cout << "Knob";
            break;
        case 2:
            cout << "Border";
            break;
    }
    cout << endl;
    cout << "Up: ";
    switch (up)
    {
        case 0:
            cout << "Hole";
            break;
        case 1:
            cout << "Knob";
            break;
        case 2:
            cout << "Border";
            break;
    }
    cout << endl;
    cout << "Right: ";
    switch (right)
    {
        case 0:
            cout << "Hole";
            break;
        case 1:
            cout << "Knob";
            break;
        case 2:
            cout << "Border";
            break;
    }
    cout << endl;
    cout << "Left: ";
    switch (left)
    {
        case 0:
            cout << "Hole";
            break;
        case 1:
            cout << "Knob";
            break;
        case 2:
            cout << "Border";
            break;
    }
    cout << endl;
}