#include <iostream>
using namespace std;

char board[10][10] = { {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                       {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                       {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                       {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                       {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                       {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                       {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                       {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                       {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                       {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}};

int xVal = 0;
int yVal = 0;
int gameRunning = 1;

void generateBoard();
void doMove(char dir);
void drawBoard();
void updateGameStatus(int currX, int currY);

void generateBoard(){
    srand(time(0));

    //puts the player in a fixed place on the board
    board[0][0] = 'G';

    //puts the treasure in a fixed place on the board
    board[9][9] = 'X';

    // generates three traps in random places on the board
    for (int k = 0; k < 3; k++){
        int randX = 1 + rand() % 9;
        int randY = 1 + rand() % 9;

        while (board[randX][randY] != '-') {
             randX = 1 + rand() % 9;
             randY = 1 + rand() % 9;
        }
        board[randX][randY] = 'T';
    }
    drawBoard();
}

void drawBoard(){
    // displays the board on the console
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}


void doMove(char dir){
    switch(dir){
        case 'w':
        case 'W':
            board[xVal][yVal] = '-';
            xVal--;
            updateGameStatus(xVal, yVal);

            board[xVal][yVal] = 'G';
            drawBoard();
            break;
        case 's':
        case 'S':
            board[xVal][yVal] = '-';
            xVal++;
            updateGameStatus(xVal, yVal);
            board[xVal][yVal] = 'G';
            drawBoard();
            break;
        case 'a':
        case 'A':
            board[xVal][yVal] = '-';
            yVal--;
            updateGameStatus(xVal, yVal);
            board[xVal][yVal] = 'G';
            drawBoard();
            break;
        case 'd':
        case 'D':
            board[xVal][yVal] = '-';
            yVal++;
            updateGameStatus(xVal, yVal);
            board[xVal][yVal] = 'G';
            drawBoard();
            break;
        default:
            cout << "Enter valid character please!" << endl;
    }
}

void updateGameStatus(int currX, int currY){
    if (board[currX][currY] == 'T'){
        gameRunning = -1;
    } else if (board[currX][currY] == 'X') {
        gameRunning = 0;
    } else {
        gameRunning = 1;
    }
}

int main() {
     char move;

     cout << endl;
     cout << "~ WELCOME TO DUNGEON CRAWL! ~" << endl;
     cout << endl;

     generateBoard();

     cout << endl;
     cout << "Use the WASD keys to move one space up, left, down, and right, respectively. " << endl;
     cout << "Your player marker is G. Avoid the traps (T) and get to the treasure (X)" << endl;

     while (gameRunning == 1){
         cout << "What's your move?" << endl;
         cin >> move;

         if (move == 'W' || move == 'w'){
             if (xVal-1 < 0){
                 cout << "Hey! You're off the board! Please enter a different key... " << endl;
                 drawBoard();
                 cin >> move;
                 doMove(move);
             } else {
                 doMove(move);
             }
         } else if (move == 'S' || move == 's'){
             if (xVal+1 > 9){
                 cout << "Hey! You're off the board! Please enter a different key... " << endl;
                 drawBoard();
                 cin >> move;
                 doMove(move);
             }  else {
                 doMove(move);
             }
         }  else if (move == 'A' || move == 'a'){
             if (yVal-1 < 0){
                 cout << "Hey! You're off the board! Please enter a different key... " << endl;
                 drawBoard();
                 cin >> move;
                 doMove(move);
             }  else {
                 doMove(move);
             }
         } else if (move == 'D' || move == 'd'){
             if (yVal+1 > 9){
                 cout << "Hey! You're off the board! Please enter a different key... " << endl;
                 drawBoard();
                 cin >> move;
                 doMove(move);
             }  else {
                 doMove(move);
             }
         } else{
             cout << "Enter valid character please!" << endl;
         }
     }

     if (gameRunning == -1){
         cout << "You're dead! Sorry..." << endl;
     } else if (gameRunning == 0){
         cout << "You've won! Yaaaay!" << endl;
     }

}
