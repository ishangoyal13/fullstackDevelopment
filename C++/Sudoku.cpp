#include<iostream>
using namespace std;
void printSolution(int **grid)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool UsedInRow(int **grid,int row ,int num)
{
    for(int i=0;i<9;i++)
    {
        if(grid[row][i]==num)
        {
            return true;
        }
    }
    return false;
}
bool UsedInColumn(int **grid,int col,int num)
{
    for(int i=0;i<9;i++)
    {
        if(grid[i][col]==num)
        {
            return true;
        }
    }
    return false;
}
bool UsedInBox(int **grid,int row,int col,int num)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(grid[row+i][col+j]==num)
            {
                return true;
            }
        }
    }
    return false;
}
bool isSafe(int **grid,int row,int col,int num)
{
    if(UsedInRow(grid,row,num)==false
       && UsedInBox(grid,row-row%3,col-col%3,num)==false
       && UsedInColumn(grid,col,num)==false && grid[row][col]==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool findUnassignedPosition(int **grid,int &row,int &col)
{
    for(row=0;row<9;row++)
    {
        for(col=0;col<9;col++)
        {
            if(grid[row][col]==0)
            {
                return true;
            }
        }
    }
    return false;
}
bool solveSudokuUtil(int **grid,int row,int col)
{
    if(findUnassignedPosition(grid,row,col)==false)
    {
        return true;
    }
    else
    {
        for(int i=1;i<=9;i++)
        {
            if(isSafe(grid,row,col,i)==true)
            {
                grid[row][col]=i;
                if(solveSudokuUtil(grid,row,col)==true)
                {
                    return true;
                }
                else
                {
                    grid[row][col]=0;
                }
            }
        }
        return false;
    }
}
void solveSudoku(int **grid)
{
    if(solveSudokuUtil(grid,0,0)==true)
    {
        printSolution(grid);
    }
    else
    {
        cout<<"Solution does not exists";
    }
}
int main()
{
    int **grid=new int*[9];
    for(int i=0;i<9;i++)
    {
        grid[i]=new int[9];
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            grid[i][j]=0;
        }
    }
    grid[0][0]=3;
    grid[0][2]=6;
    grid[0][3]=5;
    grid[0][5]=8;
    grid[0][6]=4;

    grid[1][0]=5;
    grid[1][1]=2;

    grid[2][1]=8;
    grid[2][2]=7;
    grid[2][7]=3;
    grid[2][8]=1;

    grid[3][2]=3;
    grid[3][4]=1;
    grid[3][7]=8;

    grid[4][0]=9;
    grid[4][3]=8;
    grid[4][4]=6;
    grid[4][5]=3;
    grid[4][8]=5;

    grid[5][1]=5;
    grid[5][4]=9;
    grid[5][6]=6;

    grid[6][0]=1;
    grid[6][1]=3;
    grid[6][6]=2;
    grid[6][7]=5;

    grid[7][7]=7;
    grid[7][8]=4;

    grid[8][2]=5;
    grid[8][3]=2;
    grid[8][5]=6;
    grid[8][6]=3;
    solveSudoku(grid);
}
