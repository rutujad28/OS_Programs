#include <stdio.h>
#define MAX 100

// char pg[MAX]={'\0'};
int arr[MAX];
int pageframes, num, pgfault;

struct queue
{

    int front;
    int last;
    int num;
    int output[MAX];
};

struct queue q;

void enqueue(int insert_item)
{
    if (q.front == -1)
        q.front = 0;
    q.last++;
    q.output[q.last] = insert_item;
}

void dequeue()
{
    if (q.front == -1 || q.front > q.last)
    {
        printf("Empty \n");
    }
    int x = q.output[q.front];
    q.front++;
    // return x;
}

void display()
{

    if (q.front == -1)
        printf("Empty Queue \n");
    else
    {
        for (int i = q.front; i <= q.last; i++)
            printf("%d ", q.output[i]);
    }
}

int fifo()
{

    int pgfault = 0, flag = 0, count = 0;
    for (int i = 0; i < num; i++)
    {
        printf("\n\nCurrent Memory Reference: %d", arr[i]);
        // printf("\nDisplaying Frames Queue: ");
        // display();
        for (int j = q.front; j <= q.last; j++)
        {
            if (arr[i] == q.output[j])
            {
                flag = 1;
                // printf("\nNo pagefault");
                break;
            }
        }
        if (flag == 0)
        {
            pgfault++;
            printf("    Pagefault has occurred");
            if (q.last - q.front == pageframes - 1)
                dequeue();
            enqueue(arr[i]);
            // printf("\nPagefault");
        }

        printf("\nFrames Queue: ");
        display();
        // printf("\nPagefaults: %d", pgfault);
        flag = 0;
    }
    return pgfault;
}

int lru()
{
    int pgfault = 0, flag = 0, count = 0;
    char pg[MAX] = {'\0'};
    for (int i = 0; i < num; i++)
    {
        printf("\n\nCurrent Memory Reference: %d", arr[i]);
        for (int j = 0; j <= pageframes; j++)
        {
            if (arr[i] == (int)pg[j] - 48)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            int p = pageframes + 1;
            pgfault++;
            printf("    Pagefault has occurred");
            for (int j = 0; j < pageframes; j++)
            {
                if (pg[j] == '\0')
                {
                    p = j;
                    break;
                }
            }
            if (p < pageframes)
            {
                pg[p] = (char)(arr[i] + 48);
            }
            else
            {
                int c = 0, dist = -1, found = 0;
                for (int j = 0; j < pageframes; j++)
                {
                    for (int k = i - 1; k >= 0; k--)
                    {
                        // printf("\nj %d, i %d, k %d, arr[k] %d, pg[j] %d", j, i, k, arr[k], pg[j]-48);
                        if (arr[k] == (int)(pg[j] - 48))
                        {
                            found = 1;
                            if (dist <= (i - k))
                            {
                                c = j;
                                dist = i - k;
                                // printf("\n c %d dist %d pg[c] = %c", c, dist, pg[c]);
                            }
                            break;
                        }
                    }
                    if (found == 0)
                    {
                        c = j;
                        break;
                    }
                    found = 0;
                }
                pg[c] = (char)(arr[i] + 48);
            }
        }
        flag = 0;
        printf("\nFrames Queue: \n");
        for (int a = 0; a < pageframes; a++)
        {
            printf("%c ", pg[a]);
        }
    }
    return pgfault;
}

int optimal()
{
    int pgfault = 0, flag = 0, count = 0;
    char pg[MAX] = {'\0'};
    for (int i = 0; i < num; i++)
    {
        printf("\n\nCurrent Memory Reference: %d", arr[i]);
        for (int j = 0; j <= pageframes; j++)
        {
            if (arr[i] == (int)pg[j] - 48)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            int p = pageframes + 1;
            pgfault++;
            printf("    Pagefault has occurred");
            for (int j = 0; j < pageframes; j++)
            {
                if (pg[j] == '\0')
                {
                    p = j;
                    break;
                }
            }
            if (p < pageframes)
            {
                pg[p] = (char)(arr[i] + 48);
            }
            else
            {
                int c = 0, dist = -1, found = 0;
                for (int j = 0; j < pageframes; j++)
                {
                    for (int k = i + 1; k < num; k++)
                    {
                        // printf("\nj %d, i %d, k %d, arr[k] %d, pg[j] %d", j, i, k, arr[k], pg[j]-48);
                        if (arr[k] == (int)(pg[j] - 48))
                        {
                            found = 1;
                            if (dist <= (k - i))
                            {
                                c = j;
                                dist = k - i;
                                // printf("\n c %d dist %d pg[c] = %c", c, dist, pg[c]);
                            }
                            break;
                        }
                    }
                    if (found == 0)
                    {
                        c = j;
                        // printf("Not found c = %d", c);
                        break;
                    }
                    found = 0;
                }
                pg[c] = (char)(arr[i] + 48);
            }
        }
        flag = 0;
        printf("\nFrames Queue: \n");
        for (int a = 0; a < pageframes; a++)
        {
            printf("%c ", pg[a]);
        }
    }
    return pgfault;
}

int main()
{

    printf("Enter number of references for reference string (max 100): ");
    scanf("%d", &num);
    q.num = num;
    q.front = 0;
    q.last = -1;
    printf("\nEnter Reference String (put a space between each reference eg. 1 2 0 7 8): ");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    // fflush(stdin);
    for (int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter number of frames: ");
    scanf("%d", &pageframes);
    int choice;
    do
    {
        printf("\n\nMENU\n1. FIFO\n2. LRU\n3. Optimal\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nFIFO\n");
            pgfault = fifo();
            printf("\nPagefaults: %d", pgfault);
            break;
        case 2:
            printf("\n\nLRU\n");
            pgfault = lru();
            printf("\nPagefaults: %d", pgfault);
            break;
        case 3:
            printf("\n\nOptimal\n");
            pgfault = optimal();
            printf("\nPagefaults: %d", pgfault);
            break;
        case 4:
            printf("\nExit\n");
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 4);
}