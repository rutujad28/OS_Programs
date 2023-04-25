// SCAN

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
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
    int clk_count=0;
    int aclk_count=0;
    int temp;

    printf("Enter elements of request: ");
    for (int i = 0; i < tracks; i++) {
        scanf("%d", &request[i]);
        if(request[i]>chp)
        {
            clk[clk_count]=request[i];
            clk_count+=1;
        }
        else
        {
            aclk[aclk_count]=request[i];
            aclk_count+=1;
        }
    }

        // Sort the requests in ascending order
    for (int i = 0; i < clk_count - 1; i++) {
        for (int j = i + 1; j < clk_count; j++) {
            if (clk[i] > clk[j]) {
                int temp = clk[i];
                clk[i] = clk[j];
                clk[j] = temp;
            }
        }
    }

    // Sort the requests in descending order
    for (int i = 0; i < aclk_count - 1; i++) {
        for (int j = i + 1; j < aclk_count; j++) {
            if (aclk[i] < aclk[j]) {
                int temp = aclk[i];
                aclk[i] = aclk[j];
                aclk[j] = temp;
            }
        }
    }


    for(int i=0; i<clk_count; i++)
    {
        next_request[i]=clk[i];
        tr_tracks[i]=abs(chp-next_request[i]);
        chp=next_request[i];
    }

    int j=0;
    for(int i=clk_count; i<clk_count+aclk_count; i++)
    {
        next_request[i]=aclk[j];
        tr_tracks[i]=abs(chp-next_request[i]);
        chp=next_request[i];
        j+=1;
    }
    


    int count=0;

    for(int i=0; i<tracks; i++)
    {
        count+=tr_tracks[i];
    }

        printf("Next track to be traveled\t\t\t\tNo. of tracks travelled\n");

    for(int i=0; i<tracks; i++)
    {
        printf("        %d                 \t\t\t\t          %d         \n", next_request[i], tr_tracks[i]);
    }

    printf("Sum : %d", count);

    return 0;
}
