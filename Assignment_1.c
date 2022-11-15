/*

    @Ranjeetkumbhar01
    Assignment_1

***************************/
#include <stdio.h>
// finding the max out of two number
int max(int i, int j)
{
    if (i > j)
        return i;
    else
        return j;
}

void Sort1(int w[], int p[], int n)
{ // ascending order
    int temp1 = 0, temp2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (w[i] <= w[j])
            {
                temp1 = w[i];
                w[i] = w[j];
                w[j] = temp1;

                temp2 = p[i];
                p[i] = p[j];
                p[j] = temp2;
            }
        }
    }
}

// Sorting the Item in Descending Order
void sort(float arr[], float w[], float p[], int no_Item)
{
    for (int i = 0; i < no_Item; i++)
    {
        for (int j = 0; j < no_Item; j++)
        {
            if (arr[i] >= arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                int temp1 = p[i];
                p[i] = p[j];
                p[j] = temp1;

                int temp2 = w[i];
                w[i] = w[j];
                w[j] = temp2;
            }
        }
    }
}
// algorithm
int Knapsack_0_1(int weight[], int profit[], int N, int W)
{
    int knap[N + 1][W + 1]; // store the profit values

    // umber of roww
    for (int i = 0; i < N + 1; i++)
    {
        // number of column
        for (int wt = 0; wt < W + 1; wt++)
        {
            if (i == 0 || wt == 0)
            {
                knap[i][wt] = 0;
            }
            else if (weight[i - 1] <= wt)
            {
                knap[i][wt] = max(knap[i - 1][wt], knap[i - 1][wt - weight[i - 1]] + profit[i - 1]);
            }
            else
            {
                knap[i][wt] = knap[i - 1][wt];
            }
        }
    }

    return knap[N][W];
}

void f_kanpsack()
{
    printf("\nEnter The Capacity Of the Bag:");
    int W; // capacity of bag
    scanf("%d", &W);

    printf("Enter The Number Of Items:");
    int no_Item;
    scanf("%d", &no_Item);

    // defining the required array
    float weight[no_Item], profit[no_Item];
    float r[no_Item];

    // taking the weight and profit of each item
    printf("Enter the Weight and Profit Of Each Item");
    for (int i = 0; i < no_Item; i++)
    {
        printf("\n\n\tItem %d", i + 1);
        printf("\n\tWeight:");
        scanf("%f", &weight[i]);
        printf("\n\tProfit:");
        scanf("%f", &profit[i]);
        r[i] = (profit[i] / weight[i]);
    }

    // Sorting the Item according to their profit/weight ratio
    sort(r, weight, profit, no_Item);

    int total_pro = 0, i = 0;
    // filling the sack with item
    while (W > 0)
    {
        // if weight of item is less than capacity then add complete item
        if (W >= weight[i])
        {
            printf("\n profit %f added completly", profit[i]);
            W -= weight[i];
            total_pro += profit[i];
        }
        // if weight of item is greater than capacity then add the equal weight of reaming capacity
        else
        {
            float temp = (profit[i] * (W / weight[i]));
            total_pro += temp;
            W = 0;
        }
        i++;
    }
    printf("\ntotal Profit : %d", total_pro);
}

int main()
{

    int choice = 0;
    do
    {
        printf("\n-----------------------------------------");
        printf("\n     	Assignment No : 1");
        printf("\n\t1:Fractional Knapsack\n\t2:0/1 Knapsack\n\t3:Exit\n");
        printf("\n\tEnter Choice:");
        scanf("%d", &choice);
        printf("\n-----------------------------------------");
        switch (choice)
        {
        case 1:
            f_kanpsack();
            break;
        case 2:
        {
            printf("\nEnter the Weight Of KnapSack:");
            int W = 0;
            scanf("%d", &W);
            printf("\nEnter Number Of Item:");
            int N;
            scanf("%d", &N);
            printf("\nEnter the profit and weight of each item");
            int weight[N], profit[N];
            for (int i = 0; i < N; i++)
            {
                printf("\nItem %d", i + 1);
                printf("\n\tProfit:");
                scanf("%d", &profit[i]);
                printf("\n\tweight:");
                scanf("%d", &weight[i]);
            }
            Sort1(weight, profit, N); // ascending order

            printf("\nTotal Capacity : %d", Knapsack_0_1(weight, profit, N, W));
        }
        break;
        case 3:
            return 0;
        }

    } while (choice != 3);
}

/*
-----------------------------------------
        Assignment No : 1
        1:Fractional Knapsack
        2:0/1 Knapsack
        3:Exit

        Enter Choice:1

-----------------------------------------
Enter The Capacity Of the Bag:50
Enter The Number Of Items:3
Enter the Weight and Profit Of Each Item

        Item 1
        Weight:10

        Profit:60


        Item 2
        Weight:20

        Profit:100


        Item 3
        Weight:30

        Profit:120

 profit 60.000000 added completly
 profit 100.000000 added completly
total Profit : 240
-----------------------------------------
        Assignment No : 1
        1:Fractional Knapsack
        2:0/1 Knapsack
        3:Exit

        Enter Choice:2

-----------------------------------------
Enter the Weight Of KnapSack:50

Enter Number Of Item:3

Enter the profit and weight of each item
Item 1
        Profit:60

        weight:10

Item 2
        Profit:100

        weight:20

Item 3
        Profit:120

        weight:30

Total Capacity : 220
-----------------------------------------
        Assignment No : 1
        1:Fractional Knapsack
        2:0/1 Knapsack
        3:Exit

        Enter Choice:3

-----------------------------------------*/
