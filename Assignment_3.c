/*

    @Ranjeetkumbhar01
    Assignment_3

***************************/
#include <stdio.h>
#include <math.h>

int board[20], count;
void print(int n)
{
    printf("\n\nSolution: %d: \n\n", ++count);

    for (int i = 1; i <= n; i++)
    {
        printf("\t%d", i);
    }

    for (int i = 1; i <= n; i++)
    {   
        printf("\n\n%d",i);
        for (int j = 1; j <= n; j++)
        {
            if (board[i] == j)
            {
                printf("\tQ");
            }
            else
            {

                printf("\t-");
            }
        }
    }
}

int place(int row, int column)
{

    for (int i = 1; i <= row - 1; ++i)
    {
        // checking column and digonal conflicts
        if ((board[i] == column) || (abs(board[i] - column) == abs(i - row)))
            return 0;
    }

    return 1; // no conflicts
}

void queen(int row, int n)//recursive backtracking algorithm
{

    for (int column = 1; column <= n; ++column)
    {
        if (place(row, column))
        {
            board[row] = column; // no conflicts so place queen
            if (row == n)        // dead end
                print(n);        // printing the board configuration
            else                 // try queen with next position
                queen(row + 1, n);
        }
    }
}
void r_queen(int row, int n)//iterative backtracking algorithm
{

    while (row != 0)
    {
        board[row]++;
        if (board[row] <= n)
        {
            if (place(row, board[row]))
            {
                if (row == n)
                {
                    print(n);
                }
                else
                {
                    row++;
                }
            }
        }
        else
        {
            board[row] = 0;
            row--;
        }
    }
}
int main()
{
    int n, i, j;
    void queen(int row, int n);//recursive backtracking algorithm
    void r_queen(int row, int n);//iterative backtracking algorithm
    printf("Enter number of queens: ");
    scanf("%d", &n);
    queen(1, n);
    // r_queen(1, n);
    
    return 0;
}


/*


Enter number of queens: 5


Solution: 1: 

        1       2       3       4       5

1       Q       -       -       -       -

2       -       -       Q       -       -

3       -       -       -       -       Q

4       -       Q       -       -       -

5       -       -       -       Q       -

Solution: 2: 

        1       2       3       4       5

1       Q       -       -       -       -

2       -       -       -       Q       -

3       -       Q       -       -       -

4       -       -       -       -       Q

5       -       -       Q       -       -

Solution: 3:

        1       2       3       4       5

1       -       Q       -       -       -

2       -       -       -       Q       -

3       Q       -       -       -       -

4       -       -       Q       -       -

5       -       -       -       -       Q

Solution: 4:

        1       2       3       4       5

1       -       Q       -       -       -

2       -       -       -       -       Q

3       -       -       Q       -       -

4       Q       -       -       -       -

5       -       -       -       Q       -

Solution: 5:

        1       2       3       4       5

1       -       -       Q       -       -

2       Q       -       -       -       -

3       -       -       -       Q       -

4       -       Q       -       -       -

5       -       -       -       -       Q

Solution: 6:

        1       2       3       4       5

1       -       -       Q       -       -

2       -       -       -       -       Q

3       -       Q       -       -       -

4       -       -       -       Q       -

5       Q       -       -       -       -

Solution: 7:

        1       2       3       4       5

1       -       -       -       Q       -

2       Q       -       -       -       -

3       -       -       Q       -       -

4       -       -       -       -       Q

5       -       Q       -       -       -

Solution: 8:

        1       2       3       4       5

1       -       -       -       Q       -

2       -       Q       -       -       -

3       -       -       -       -       Q

4       -       -       Q       -       -

5       Q       -       -       -       -

Solution: 9:

        1       2       3       4       5

1       -       -       -       -       Q

2       -       Q       -       -       -

3       -       -       -       Q       -

4       Q       -       -       -       -

5       -       -       Q       -       -

Solution: 10:

        1       2       3       4       5

1       -       -       -       -       Q

2       -       -       Q       -       -

3       Q       -       -       -       -

4       -       -       -       Q       -

5       -       Q       -       -       -*/
