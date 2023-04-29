// Disc Scheduling Algorithms

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fcfs(int chp, int tracks, int request[], int tr_tracks[])
{
    int count = 0;

    for (int i = 0; i < tracks; i++)
    {
        tr_tracks[i] = abs(request[i] - chp);
        count += tr_tracks[i];
        chp = request[i];
    }

    printf("Next track to be traveled\t\t\t\tNo. of tracks travelled\n");

    for (int i = 0; i < tracks; i++)
    {
        printf("        %d                 \t\t\t\t          %d         \n", request[i], tr_tracks[i]);
    }

    printf("Sum : %d", count);
}

void sstf(int chp, int tracks, int request[], int next_request[], int tr_tracks[], int visited[])
{
    // SSTF algorithm
    int current_track = chp;
    for (int i = 0; i < tracks; i++)
    {
        int min_distance = __INT_MAX__;
        int min_index = -1;
        for (int j = 0; j < tracks; j++)
        {
            if (visited[j] == 0)
            {
                int distance = abs(current_track - request[j]);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    min_index = j;
                }
            }
        }
        visited[min_index] = 1;
        tr_tracks[i] = min_distance;
        current_track = request[min_index];
        next_request[i] = request[min_index];
    }

    int count = 0;

    for (int i = 0; i < tracks; i++)
    {
        count += tr_tracks[i];
    }

    printf("Next track to be traveled\t\t\t\tNo. of tracks travelled\n");

    for (int i = 0; i < tracks; i++)
    {
        printf("        %d                 \t\t\t\t          %d         \n", next_request[i], tr_tracks[i]);
    }

    printf("Sum : %d", count);
}

void scan(int chp, int tracks, int request[], int next_request[], int tr_tracks[], int clk[], int aclk[], int clk_count, int aclk_count)
{
    // Sort the requests in ascending order
    for (int i = 0; i < clk_count - 1; i++)
    {
        for (int j = i + 1; j < clk_count; j++)
        {
            if (clk[i] > clk[j])
            {
                int temp = clk[i];
                clk[i] = clk[j];
                clk[j] = temp;
            }
        }
    }

    // Sort the requests in descending order
    for (int i = 0; i < aclk_count - 1; i++)
    {
        for (int j = i + 1; j < aclk_count; j++)
        {
            if (aclk[i] < aclk[j])
            {
                int temp = aclk[i];
                aclk[i] = aclk[j];
                aclk[j] = temp;
            }
        }
    }

    for (int i = 0; i < clk_count; i++)
    {
        next_request[i] = clk[i];
        tr_tracks[i] = abs(chp - next_request[i]);
        chp = next_request[i];
    }

    int j = 0;
    for (int i = clk_count; i < clk_count + aclk_count; i++)
    {
        next_request[i] = aclk[j];
        tr_tracks[i] = abs(chp - next_request[i]);
        chp = next_request[i];
        j += 1;
    }

    int count = 0;

    for (int i = 0; i < tracks; i++)
    {
        count += tr_tracks[i];
    }

    printf("Next track to be traveled\t\t\t\tNo. of tracks travelled\n");

    for (int i = 0; i < tracks; i++)
    {
        printf("        %d                 \t\t\t\t          %d         \n", next_request[i], tr_tracks[i]);
    }

    printf("Sum : %d", count);
}

void cscan(int chp, int tracks, int request[], int next_request[], int tr_tracks[], int clk[], int aclk[], int clk_count, int aclk_count)
{
    // Sort the requests in ascending order
    for (int i = 0; i < clk_count - 1; i++)
    {
        for (int j = i + 1; j < clk_count; j++)
        {
            if (clk[i] > clk[j])
            {
                int temp = clk[i];
                clk[i] = clk[j];
                clk[j] = temp;
            }
        }
    }

    // Sort the requests in descending order
    for (int i = 0; i < aclk_count - 1; i++)
    {
        for (int j = i + 1; j < aclk_count; j++)
        {
            if (aclk[i] < aclk[j])
            {
                int temp = aclk[i];
                aclk[i] = aclk[j];
                aclk[j] = temp;
            }
        }
    }

    for (int i = 0; i < clk_count; i++)
    {
        next_request[i] = clk[i];
        tr_tracks[i] = abs(chp - next_request[i]);
        chp = next_request[i];
    }

    int j = aclk_count - 1;
    for (int i = clk_count; i < clk_count + aclk_count; i++)
    {
        next_request[i] = aclk[j];
        tr_tracks[i] = abs(chp - next_request[i]);
        chp = next_request[i];
        j -= 1;
    }

    int count = 0;

    for (int i = 0; i < tracks; i++)
    {
        count += tr_tracks[i];
    }

    printf("Next track to be traveled\t\t\t\tNo. of tracks travelled\n");

    for (int i = 0; i < tracks; i++)
    {
        printf("        %d                 \t\t\t\t          %d         \n", next_request[i], tr_tracks[i]);
    }

    printf("Sum : %d", count);
}

int main()
{
    int chp, tracks;
    printf("Enter value of chp: ");
    scanf("%d", &chp);
    printf("Enter no. of tracks: ");
    scanf("%d", &tracks);

    int request[tracks];
    int next_request[tracks];
    int tr_tracks[tracks];
    int clk[tracks];
    int aclk[tracks];
    int visited[tracks];
    int clk_count = 0;
    int aclk_count = 0;
    int temp;

    printf("Enter elements of request: ");
    for (int i = 0; i < tracks; i++)
    {
        scanf("%d", &request[i]);
        visited[i] = 0;
        if (request[i] > chp)
        {
            clk[clk_count] = request[i];
            clk_count += 1;
        }
        else
        {
            aclk[aclk_count] = request[i];
            aclk_count += 1;
        }
    }
    int choice;
    do
    {
        printf("\n\nMENU\n1. fcfs\n2. sstf\n3. scan\n4. cscan\n5. exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nfcfs\n");
            fcfs(chp, tracks, request, tr_tracks);
            break;
        case 2:
            printf("\n\nsstf\n");
            sstf(chp, tracks, request, next_request, tr_tracks, visited);
            break;
        case 3:
            printf("\n\nscan\n");
            scan(chp, tracks, request, next_request, tr_tracks, clk, aclk, clk_count, aclk_count);
            break;
        case 4:
            printf("\ncscan\n");
            cscan(chp, tracks, request, next_request, tr_tracks, clk, aclk, clk_count, aclk_count);
            break;
        case 5:
            printf("\nExit\n");
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 5);
    

    return 0;
}