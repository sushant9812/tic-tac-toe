#include <iostream>
using namespace std;

char board[3][3];

// Function to initialize the board
void initBoard() {
    char count = '1';
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j] = count++;
}

// Function to display the board
void displayBoard() {
    cout << "\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << " " << board[i][j] << " ";
            if(j<2) cout << "|";
        }
        if(i<2) cout << "\n---+---+---\n";
    }
    cout << "\n\n";
}

// Function to check winner
char checkWinner() {
    // Rows and Columns
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return board[i][0];
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return board[0][i];
    }
    // Diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return board[0][0];
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return board[0][2];

    return ' '; // No winner yet
}

// Function to check draw
bool isDraw() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]!='X' && board[i][j]!='O') return false;
    return true;
}

// Main game function
void playGame() {
    char player = 'X';
    int move;
    while(true) {
        displayBoard();
        cout << "Player " << player << ", enter the number of the cell: ";
        cin >> move;

        // Validate move
        int row = (move-1)/3;
        int col = (move-1)%3;
        if(move<1 || move>9 || board[row][col]=='X' || board[row][col]=='O') {
            cout << "Invalid move, try again!\n";
            continue;
        }

        board[row][col] = player;

        if(checkWinner() == player) {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }

        if(isDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        // Switch player
        player = (player=='X') ? 'O' : 'X';
    }
}

int main() {
    char choice;
    do {
        initBoard();
        playGame();
        cout << "Play again? (y/n): ";
        cin >> choice;
    } while(choice=='y' || choice=='Y');

    cout << "Thanks for playing!\n";
    return 0;
}
