//FCFS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int chp, tracks;
    printf("Enter value of chp :");
    scanf("%d", &chp);
    printf("Enter no. of tracks :");
    scanf("%d", &tracks);

    int request[tracks];
    int tr_tracks[tracks];

    printf("Enter elements of request : ");

    for(int i=0; i<tracks; i++)
    {
        scanf("%d", &request[i]);

    }

    int count=0;

    for(int i=0; i<tracks; i++)
    {
        tr_tracks[i]=abs(request[i]-chp);
        count+=tr_tracks[i];
        chp=request[i];
    }

    printf("Next track to be traveled\t\t\t\tNo. of tracks travelled\n");

    for(int i=0; i<tracks; i++)
    {
        printf("        %d                 \t\t\t\t          %d         \n", request[i], tr_tracks[i]);
    }

    printf("Sum : %d", count);

    return 0;

}