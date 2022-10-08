//Tic Tac Toe game between 2 players or player vs computer
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkSpaces();
void Player1Move();
void Player2Move();
void AiMove();
char checkWinner();
void printWinner(char);

int main(){
    char winner = ' ';
    char response;
    int option;
    printf("Chose 2 for ai, choose 1 for person\n");
    scanf("%d", &option);
    switch (option){
        case 1:
    }
    do
    {
        winner = ' ';
        response = ' ';
        resetBoard();

        while (winner == ' ' && checkSpaces() != 0){
            printBoard();
            Player1Move();
            winner = checkWinner();
            if (winner != ' ' || checkSpaces() == 0){
                break;
            }
            AiMove();
            winner = checkWinner();
            if (winner != ' ' || checkSpaces() == 0){
                break;
            }
        }
        printBoard();
        printWinner(winner);
        printf("\n PLay again? (Y/N): ");
        scanf("%c");
        scanf("%c", &response);
        response = toupper(response);
    } while (response == 'Y');
    
    
    
    // prompt user for game they wish to play

    //read information from console

    //if they chose to play vs a bot, choose the bot layout

    //if they chose to play vs a real human, choose the human layout.

    //each time a player makes a move, display the board and what they picked

    //keep going until a winner or a tie

    //once someone ties or wins, stop the game and declare the winner

    
    return 0;
}

void resetBoard(){
    for(int i = 0; i < 3; i++){
        for (int j = 0; j <3; j++){
            board[i][j] = ' ';
        }
    }
}
void printBoard(){
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n--- | --- | ---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n--- | --- | ---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    


}
int checkSpaces(){
    int open = 9;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j <3; j++){
            if (board[i][j] != ' '){
                open--;
            }
        }
    }
    return open;
}
void Player1Move(){
    int row;
    int column;
    do{
        printf("Enter row 1-3: ");
        scanf("%d", &row);
        row--;
        printf("Enter column 1-3: ");
        scanf("%d", &column);
        column--;
        if (board[row][column] != ' '){
            printf("Invalid \n");
        }
        else{
            board[row][column] = PLAYER1;
            break;
        }
    } while (board[row][column] != ' ');
    
}
void Player2Move(){

}
void AiMove(){
    srand(time(0));
    int row;
    int column;
    if (checkSpaces() > 0){
        do
        {
            row = rand() % 3;
            column = rand() % 3;
        } while (board[row][column] != ' ');

        board[row][column] = COMPUTER;
        
    }
    else{
        printWinner(' ');
    }
}
void printWinner(char winner){
    if (winner == PLAYER1){
        printf("You win");
    }
    else if (winner == COMPUTER){
        printf("lose");
    }
    else{
        printf("tie");
    }
}
char checkWinner(){
    //row
    for (int i = 0; i < 3; i++){
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }
    //column
    for (int i = 0; i < 3; i++){
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }
    //diagonal
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][0] == board[2][0]){
        return board[0][0];
    }
    return ' ';
}
