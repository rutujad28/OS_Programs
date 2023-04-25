// SSTF

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    int visited[tracks];

    printf("Enter elements of request: ");
    for (int i = 0; i < tracks; i++)
    {
        scanf("%d", &request[i]);
        visited[i] = 0;
    }

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

    return 0;
}
