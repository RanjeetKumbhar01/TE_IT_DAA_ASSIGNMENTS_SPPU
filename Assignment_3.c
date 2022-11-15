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

int place(int row, int col)
{
    for (int i = 1; i <= row - 1; i++)
    {
        if (board[i] == col)
        {
            return 0;
        }
        else if (abs(board[i] - col) == abs(i - row))
        {
            return 0;
        }
    }
    return 1;
}

void queen(int row, int n)
{
    for (int col = 1; col <= n; col++)
    {
        if (place(row, col))
        {
            board[row] = col;
            if (row == n)
            {
                print(n);
            }
            else
            {
                queen(row + 1, n);
            }
        }
    }
}

int main()
{
    int n, i, j;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    queen(1, n);
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
