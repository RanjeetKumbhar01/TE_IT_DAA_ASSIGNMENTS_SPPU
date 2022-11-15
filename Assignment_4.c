/*

    @Ranjeetkumbhar01
    Assignment_4

***************************/
#include <stdio.h>
#include <math.h>

int arr[10][10], completed[10], cost = 0, n;
void take_ip()
{
    int i, j;
    printf("Enter number of Cities: ");
    scanf("%d", &n);
    printf("\nEnter Cost Matrix \n");

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter element of %d th row: \n", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
        completed[i] = 0;
    }
}

int least(int c)
{
    int nc = 999, kmin, min = 999;

    for (int i = 0; i < n; i++)
    {
        if ((arr[c][i] != 0) && (completed[i] == 0))
        {
            if (arr[c][i] + arr[i][c] < min)
            {
                min = arr[i][0] + arr[c][i];
                kmin = arr[c][i];
                nc = i;
            }
        }
    }

    if (min != 999)
    {
        cost += kmin;
    }

    return nc;
}

void mincost(int city)
{
    int ncity;
    completed[city] = 1;
    printf("%d--->", city + 1);
    ncity = least(city);

    if (ncity == 999)
    {
        ncity = 0;
        printf("%d", ncity + 1);

        cost += arr[city][ncity];
        return;
    }
    mincost(ncity);
}

int main()
{
    take_ip();
    mincost(0);

    printf("\n\nMinicost is %d: ", cost);
}

/*


Enter number of Cities: 4

Enter Cost Matrix 

Enter element of 1 th row: 
0 10 15 20

Enter element of 2 th row: 
10 0 35 25

Enter element of 3 th row: 
15 35 0 30

Enter element of 4 th row: 
20 25 30 0
1--->2--->3--->4--->1

Minicost is 95: 

*/
