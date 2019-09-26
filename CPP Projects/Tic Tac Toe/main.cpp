#include<bits/stdc++.h>
using namespace std;
#define COMPUTER 1
#define HUMAN 2
#define SIDE 3
#define COMPUTERMOVE 'o'
#define HUMANMOVE 'x'
 struct Move
{
    int row, col;
};
char player = 'o', opponent = 'x';
string name;
void showBoard(char board[][SIDE])
{
    printf("\n\n");

    printf("\t\t\t  %c | %c  | %c  \n", board[0][0],
                             board[0][1], board[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", board[1][0],
                             board[1][1], board[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", board[2][0],
                             board[2][1], board[2][2]);

    return;
}
void showInstructions()
{
    printf("\t\t\t  Tic-Tac-Toe\n\n");
    printf("Choose a cell numbered from 0 to 8 as below"
            " and play\n\n");

    printf("\t\t\t  0 | 1  | 2  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  3 | 4  | 5  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  6 | 7  | 8  \n\n");

    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");

    return;
}
void declareWinner(int whoseTurn)
{
    if (whoseTurn == COMPUTER)
        printf("COMPUTER has won\n");
    else
       cout<<name<<" has won\n";
    return;
}
bool rowCrossed(char board[][SIDE])
{
    for (int i=0; i<SIDE; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ')
            return (true);
    }
    return(false);
}
bool columnCrossed(char board[][SIDE])
{
    for (int i=0; i<SIDE; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != ' ')
            return (true);
    }
    return(false);
}
bool diagonalCrossed(char board[][SIDE])
{
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != ' ')
        return(true);

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
         board[0][2] != ' ')
        return(true);

    return(false);
}
bool gameOver(char board[][SIDE])
{
    return(rowCrossed(board) || columnCrossed(board)
            || diagonalCrossed(board) );
}
bool isMovesLeft(char board[3][3])
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]==' ')
                return true;
    return false;
}
int evaluate(char b[3][3])
{
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] &&
            b[row][1]==b[row][2])
        {
            if (b[row][0]==player)
                return +10;
            else if (b[row][0]==opponent)
                return -10;
        }
    }
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] &&
            b[1][col]==b[2][col])
        {
            if (b[0][col]==player)
                return +10;

            else if (b[0][col]==opponent)
                return -10;
        }
    }
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==player)
            return +10;
        else if (b[0][0]==opponent)
            return -10;
    }

    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==player)
            return +10;
        else if (b[0][2]==opponent)
            return -10;
    }
    return 0;
}
int minimax(char board[3][3], int depth, bool isMax)
{
    int score = evaluate(board);
    if (score == 10)
        return score;
    if (score == -10)
        return score;
    if (isMovesLeft(board)==false)
        return 0;
    if (isMax)
    {
        int best = -1000;
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (board[i][j]==' ')
                {
                    board[i][j] = player;
                    best = max( best,
                        minimax(board, depth+1, !isMax) );
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
    else
    {
        int best = 1000;
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (board[i][j]==' ')
                {
                    board[i][j] = opponent;
                    best = min(best,
                           minimax(board, depth+1, !isMax));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}
Move findBestMove(char board[3][3])
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            if (board[i][j]==' ')
            {
                board[i][j] = player;
                if(gameOver(board)==true)
                {
                    board[i][j]=' ';
                    bestMove.row=i;
                    bestMove.col=j;
                    return bestMove;
                }
                int moveVal = minimax(board, 0, false);
                board[i][j] = ' ';
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }


    return bestMove;
}
void playTicTacToe(int whoseTurn)
{
    char board[SIDE][SIDE];
    for(int i=0;i<SIDE;i++)
        for(int j=0;j<SIDE;j++)
            board[i][j]=' ';
    showInstructions();
    int moveIndex = 0, x, y;
    while (gameOver(board) == false &&
            moveIndex != SIDE*SIDE)
    {
        if (whoseTurn == COMPUTER)
        {

            Move troy=findBestMove(board);
            x = troy.row;
            y = troy.col;
            board[x][y] = COMPUTERMOVE;
            printf("COMPUTER has put a %c in cell %d\n",
                    COMPUTERMOVE, x*3+y);
            showBoard(board);
            moveIndex ++;
            whoseTurn = HUMAN;
        }

        else if (whoseTurn == HUMAN)
        {
            int bgy;
            label:cout<<"Enter the cell number where you want to play   ";

            cin>>bgy;
            cout<<endl;
            x=bgy/3;
            y=bgy%3;
            if(bgy>=9)
            {
                cout<<"The cell you selected doesnot exist.\n\nPlease select a valid cell number....(0-8)\n\n";
                goto label;
            }
            else if(board[x][y]!=' ')
            {
                cout<<"The cell you selected is already occupied.Please try again...."<<endl;
                goto label;
            }
            board[x][y] = HUMANMOVE;
            cout<<name<<" has put a "<<HUMANMOVE<<" in cell "<<bgy<<endl;
            showBoard(board);
            moveIndex ++;
            whoseTurn = COMPUTER;
        }
    }
    if (gameOver(board) == false &&
            moveIndex == SIDE * SIDE)
        printf("It's a draw\n");
    else
    {
        if (whoseTurn == COMPUTER)
            whoseTurn = HUMAN;
        else if (whoseTurn == HUMAN)
            whoseTurn = COMPUTER;
        declareWinner(whoseTurn);
    }
    return;
}
int main()
{
    cout<<"WELCOME USER.........ENJOY PLAYING THE GAME---------------\n\n\n_____________ALL THE BEST_____________\n\n\nCreator:- AYUSH SOMANI\n\n";
    cout<<"ENTER YOUR NAME  ";
    cin>>name;
    char WISH='Y';
    while(WISH=='Y'||WISH=='y')
    {
        cout<<"SELECT YOUR TURN.....   1 for first and 2 for second     ";
        int t;
        cin>>t;
        cout<<"\n\n\n\n";
        int whoseturn;
        if(t==1)
            whoseturn=HUMAN;
        else
            whoseturn=COMPUTER;
        playTicTacToe(whoseturn);
        cout<<"\n\n\n\nDO YOU WANT TO CONTINUE\n\n\n\nTYPE Y for yes or any other key to abort   ";
        cin>>WISH;
        cout<<"\n\n\n\n";
    }
    cout<<"THANK YOU FOR PLAYING THE GAME...........\n\nHOPE YOU ENJOYED THE GAME\n\n\n";
    return (0);
}
