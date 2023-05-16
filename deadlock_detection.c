// Banker's Algorithm  
#include <stdio.h>  
int main()  
{   
  
    int n, m, i, j, k;  

    printf("Enter number of processes : ");
    scanf("%d", &n);

    printf("Enter number of resources : ");
    scanf("%d", &m);

    int alloc[n][m]; 

    printf("Enter Allocation Matrix :\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &alloc[i][j]);
        }
    } 
  
    int req[n][m];

    printf("Enter Request Matrix :\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &req[i][j]);
        }
    } 
  
    int avail[m];

    printf("Enter Available Resources :");
    for(int i=0; i<m;i++){
        scanf("%d", &avail[i]);
    }  


    // f[n] array is used to keep track of the state of each process (i.e., waiting or executed) 
    // and to determine whether the system is in a safe state or not.

    int f[n], ans[n], ind = 0;  
    for (k = 0; k < n; k++)  
    {  
        f[k] = 0;  
    }  

    int y = 0;  
    for (k = 0; k < m; k++)  
    {  
        for (i = 0; i < n; i++)  
        {  
            if (f[i] == 0)  
            {  
                int flag = 0;  
                for (j = 0; j < m; j++)  
                {  
                    if (req[i][j] > avail[j])  
                    {  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (flag == 0)  
                {  
                    ans[ind++] = i;  
                    for (y = 0; y < m; y++){ 
                        avail[y] += alloc[i][y];  
                    }
                    f[i] = 1;  
                }  
            }  
        }  
    }  
    
    int flag = 1;  
    for (int i = 0; i < n; i++)  
    {  
        if (f[i] == 0)  
        {  
            flag = 0;  
            printf("Deadlock will occur");  
            break;  
        }  
    }  
    if (flag == 1)  
    {  
        printf("Deadlock will not occur\n");
        printf("Following is the SAFE Sequence\n");  
        for (i = 0; i < n - 1; i++){
            printf(" P%d ->", ans[i]);
            }  
        printf(" P%d", ans[n - 1]);  
    }  
    return (0);  
} 
