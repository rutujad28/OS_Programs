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
    int min, time = 0, index, ex = 0;

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

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                int temp;

                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    int complete = 0, t = 0, minm = 9999;
    int prt = -1;
    int k = 0;

    while (complete < n)
    {
        prt = -1;
        minm = 9999;

        // Find the process with the highest priority among the arrived processes
        for (int i = 0; i < n; i++)
        {
            if ((at[i] <= t) && (pr[i] < minm) && rt[i] > 0)
            {
                minm = pr[i];
                prt = i;
            }
        }

        if (prt == -1)
        {
            t++;
            continue;
        }

        // Decrement the remaining time
        t++;
        rt[prt]--;

        if (rt[prt] == 0)
        {
            ft[prt] = t;

            // Calculate waiting time
            tt[prt] = ft[prt] - at[prt];
            wt[prt] = tt[prt] - bt[prt];

            complete++;
        }

        gid[k] = pid[prt];
        gt[k] = t;
        k++;
    }

    // Display the solution
    printf("Process\tArrival Time\tBurst Time\tPriority\tFinish Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pid[i], at[i], bt[i], pr[i], ft[i], tt[i], wt[i]);
}
// Display the Gantt chart
printf("\nGantt Chart:\n");
for (int i = 0; i < k; i++)
{
    printf("| P%d ", gid[i]);
}
printf("|\n");
for (int i = 0; i < k; i++)
{
    printf("%d    ", gt[i]);
}
printf("%d\n", t);

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
