//100 500 200 300 600
//212 417 112 426

#include <stdio.h>
#include <stdlib.h>

void firstFit(int in_block[], int in_process[], int block[], int m, int process[], int n, int allocation[])
{

    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
        process[i] = in_process[i];
    }

    for(int i=0; i<m; i++)
    {
        block[i] = in_block[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (block[j] >= process[i])
            {

                allocation[i] = j;

                block[j] -= process[i];

                break;
            }
        }
    }

     printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %i\t\t\t", i + 1);
        printf("%i\t\t\t\t", process[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }

    printf("\nAfter placing processes remaining memory in blocks :\n");

    for (int i = 0; i < m; i++)
    {
        printf("%d\t", block[i]);
    }
}

void nextFit(int in_block[], int in_process[], int block[], int m, int process[], int n, int allocation[])
{
    int j = 0;
    int t = m - 1;

    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
        process[i] = in_process[i];
    }

    for(int i=0; i<m; i++)
    {
        block[i] = in_block[i];
    }

    for (int i = 0; i < n; i++)
    {

        while (j < m)
        {
            if (block[j] >= process[i])
            {

                allocation[i] = j;

                block[j] -= process[i];

                t = (j - 1) % m;
                break;
            }
            if (t == j)
            {
                // sets a new end point
                t = (j - 1) % m;
                // breaks the loop after going through all memory block
                break;
            }
            j = (j + 1) % m;
        }
    }

     printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %i\t\t\t", i + 1);
        printf("%i\t\t\t\t", process[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }

    printf("\nAfter placing processes remaining memory in blocks :\n");

    for (int i = 0; i < m; i++)
    {
        printf("%d\t", block[i]);
    }
}

void bestFit(int in_block[], int in_process[], int block[], int m, int process[], int n, int allocation[])
{
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
        process[i] = in_process[i];
    }

    for(int i=0; i<m; i++)
    {
        block[i] = in_block[i];
    }

    for (int i = 0; i < n; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (block[j] >= process[i])
            {
                if (bestIdx == -1 || block[j] < block[bestIdx])
                {
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            block[bestIdx] -= process[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %i\t\t\t", i + 1);
        printf("%i\t\t\t\t", process[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }

    printf("\nAfter placing processes remaining memory in blocks :\n");

    for (int i = 0; i < m; i++)
    {
        printf("%d\t", block[i]);
    }
}

void worstFit(int in_block[], int in_process[], int block[], int m, int process[], int n, int allocation[])
{
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
        process[i] = in_process[i];
    }

    for(int i=0; i<m; i++)
    {
        block[i] = in_block[i];
    }


    for (int i = 0; i < n; i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (block[j] >= process[i])
            {
                if (worstIdx == -1 || block[j] > block[worstIdx])
                {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            block[worstIdx] -= process[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %i\t\t\t", i + 1);
        printf("%i\t\t\t\t", process[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }

    printf("\nAfter placing processes remaining memory in blocks :\n");

    for (int i = 0; i < m; i++)
    {
        printf("%d\t", block[i]);
    }
}


int main()
{
    int m; // number of blocks in the memory
    int n; // number of processes in the input queue

    printf("Enter number of blocks in memory :");
    scanf("%d", &m);

    printf("Enter number of processes in memory :");
    scanf("%d", &n);

    int block[m];
    int in_block[m];
    int process[n];
    int in_process[n];

    printf("Enter size of %d blocks : ", m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &block[i]);
        in_block[i]=block[i];
    }

    printf("Enter size of %d processes : ", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &process[i]);
        in_process[i]=process[i];
    }

    int allocation[n];

    int choice;
    do
    {
        printf("\nEnter number (firstfit = 1, nextfit = 2, bestfit = 3, worstfit =4 ): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            firstFit(in_block, in_process, block, m, process, n, allocation);
            break;

        case 2:
            nextFit(in_block, in_process, block, m, process, n, allocation);
            break;

        case 3:
            bestFit(in_block, in_process, block, m, process, n, allocation);
            break;

        case 4:
            worstFit(in_block, in_process, block, m, process, n, allocation);
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    } while (choice != 5);

       

    return 0;
}
