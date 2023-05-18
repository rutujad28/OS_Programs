/*
 * FCFS Scheduling Program in C
 */

#include <stdio.h>
int main()
{
    int pid[15];
    int at[15];
    int bt[15];
    int pr[15];
    int ft[15];
    int tt[15];
    int wt[15];
    int n;

    printf("\nFCFS Scheduling \n\n");
    printf("Enter the number of processes: ");
    scanf("%d",&n);
 
    printf("Enter process id of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pid[i]);
    }

    printf("Enter arrival time of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
 
    printf("Enter burst time of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }

    printf("Enter priority of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pr[i]);
    }

    for(int j=0;j<n;j++){
        ft[0]=bt[0];
        tt[0]=ft[0]+at[0];
        wt[0]=tt[0]-bt[0];
        for(int i=1; i<n; i++){
            if(at[i]>at[i+1]){

                int temp;
                
                temp = pr[i];
                pr[i] = pr[i+1];
                pr[i+1] = temp;

                temp = at[i];
                at[i] = at[i+1];
                at[i+1] = temp;

                temp = bt[i];
                bt[i] = bt[i+1];
                bt[i+1] = temp;

                temp = pid[i];
                pid[i] = pid[i+1];
                pid[i+1] = temp;

            }
            else
            pr[i]=pr[i];
        }

        ft[j]=bt[j]+ft[j-1];
        tt[j]=ft[j]-at[j];
        wt[j]=ft[j]-at[j]-bt[j];
}

 
    printf("Process ID     Arrival Time     Burst Time     Priority     Finish Time     TurnAround Time     Waiting Time\n");
    
    for(int i=0; i<n; i++)
    {
        printf("P%d\t\t", pid[i]);
        printf("%d\t\t", at[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", pr[i]);

        //calculating and printing finish time of each process
        printf("%d\t\t", ft[i]);
        

        //calculating and printing turnaround time of each process
        printf("%d\t\t", tt[i]);
        

        //calculating and printing waiting time of each process
        printf("%d\t\t", wt[i]);

        printf("\n");       
        
    } 

    printf("\nGantt Chart:\n\n");
    for(int i=0; i<n; i++){
        printf("|\tP%d\t|", pid[i]); 
    } 

    printf("\n");
    printf("0");
    for(int i=0; i<n; i++){
        printf("\t\t%d", ft[i]); 
    }

    printf("\nAverage Waiting Time:");
        float tot_wt=0;
        for(int i=0; i<n; i++){
            tot_wt=tot_wt+wt[i];
        }
        printf("%f\n", tot_wt/n);

    printf("\nAverage TurnAround Time:");
        float tot_tt=0;
        for(int i=0; i<n; i++){
            tot_tt=tot_tt+tt[i];
        }
        printf("%f\n", tot_tt/n);

}