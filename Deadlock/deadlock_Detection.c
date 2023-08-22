#include <stdio.h>
#include <stdlib.h>
int req[10][10], alloc[10][10], avail[10], finish[10], flag = 0;
void main()
{
    int pro, res;
    printf("Enter the process number \n");
    scanf("%d", &pro);
    printf("Enter the resourses types \n");
    scanf("%d", &res);

    printf("Enter the availble matrix \n");
    for (int i = 0; i < res; i++)
    {
        scanf("%d", &avail[i]);
    }
    printf("Enter the allocation graph \n");
    for (int i = 0; i < pro; i++)
    {
        for (int j = 0; j < res; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the request graph \n");
    for (int i = 0; i < pro; i++)
    {
        for (int j = 0; j < res; j++)
        {
            scanf("%d", &req[i][j]);
        }
    }

    for (int i = 0; i < pro; i++)
    {
        flag = 0;
        for (int j = 0; j < res; j++)
        {
            if (alloc[i][j] != 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            finish[i] = 1;
        else
            finish[i] = 0;
    }

    for (int i = 0; i < pro; i++)
    {
        for (int j = 0; j < pro; j++)
        {
            if (finish[j] == 0)
            {
                flag = 0;
                for (int k = 0; k < res; k++)
                {
                    if (req[j][k] > avail[k])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    for (int k = 0; k < res; k++)
                        avail[k] += alloc[j][k];
                    finish[j] = 1;
                }
            }
        }
    }

    flag = 0;
    for (int i = 0; i < pro; i++)
        if (finish[i] == 0)
        {
            flag = 1;
            printf("Deadlock Detected\n");
            break;
        }

    if (flag == 0)
        printf("No Deadlock \n");
}