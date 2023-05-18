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
    int gid[100];
    int gt[100];
    int n;
    int rt[15];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process id of all the processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pid[i]);
    }

    printf("Enter arrival time of all the processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("Enter burst time of all the processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter priority of all the processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pr[i]);
    }

    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
    }
    int complete = 0, t = 0, minm = 9999;
    int shortest = -1;

    int k = 0;

    while (complete < n) {
        shortest=-1;
        minm = 9999;
        while(shortest==-1){
        for (int j = 0; j < n; j++) {
             if ((at[j] <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
             }
          }
          if (shortest==-1) {
             t++;
             continue;
          }
          else break;
        }

        rt[shortest]--;

        t++;

        if (rt[shortest] == 0) {
                //seq[complete] = shortest;
                //t++;
                ft[shortest] = t;

                // Calculate waiting time
                tt[shortest]=ft[shortest]-at[shortest];
                wt[shortest]=tt[shortest]-bt[shortest];

                //printf("p[shortest].ft = %d p[shortest].tat=%d p[shortest].wt = %d\n", p[shortest].ft, p[shortest].tat, p[shortest].wt);
                complete++;
             }

             gid[k] = pid[shortest];
             gt[k] = t;
             k++;

       }

printf("Process ID\tArrival Time\tBurst Time\tPriority\tFinish Time\tTurnaround Time\tWaiting Time\n");

for (int i = 0; i < n; i++)
{
    printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], pr[i], ft[i], tt[i], wt[i]);
}

// Display the Gantt chart

printf("\nGantt Chart:\n");
printf("| ");
for (int i = 0; i < k; i++)
{
    printf("P%d | ", gid[i]);
}

// printf("\nGantt Chart:\n\n");
// for (int i = 0; i < n; i++)
// {
//     printf("|\tP%d\t|", pid[i]);
// }

printf("\nGantt Chart:\n");
int current_process = gid[0];
int current_time = gt[0];
printf("|0 ");
for (int i = 0; i < k; i++)
{
    if (current_process != gid[i])
    {
        printf("| %d ", current_time);
        current_process = gid[i];
    }
    printf("P%d ", current_process);
    current_time = gt[i];
}
printf("| %d |\n", current_time);


printf("\n");

printf("\nAverage Waiting Time: ");
float tot_wt = 0;
for (int i = 0; i < n; i++)
{
    tot_wt = tot_wt + wt[i];
}
printf("%.2f\n", tot_wt / n);

printf("Average Turnaround Time: ");
float tot_tt = 0;
for (int i = 0; i < n; i++)
{
    tot_tt = tot_tt + tt[i];
}
printf("%.2f\n", tot_tt / n);

return 0;
}
