#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct connections
    {
        char name[25];
        char points_to[25];
        int name_asc;
        int points_to_asc;
    };

void table_fill(int ** two_d, struct connections all[], int *prim, int n, int m);

void print2d(int ** array, int row, int col);

int main()
{
    int n,m; //n = # of vertices m = # of edges

    scanf("%d %d", &n, &m);

    int i;

    struct connections *all = (struct connections*)calloc(m, sizeof(struct connections));

    char head[25], tail[25];

    for(i=0; i < m ; i++)
    {
        scanf("%s %s", head, tail);

        strcpy(all[i].name,head);
        strcpy(all[i].points_to,tail);

        int j=0;

        all[i].name_asc = 0;

        while(head[j] != NULL)
        {
            all[i].name_asc += head[j];
            j++;
        }

        all[i].points_to_asc = 0;

        j = 0;

        while(tail[j] != NULL)
        {
            all[i].points_to_asc += tail[j];
            j++;
        }


    }

    printf("1\n");


    int *prim = (int*)calloc(n, sizeof(int));

    for(i = 0; i < m; i++)
    {
        if(all[i].name_asc != prim[i])
        {
            prim[i] = all[i].name_asc;
        }

        else if (all[i].points_to_asc != prim[i])
        {
            prim[i] = all[i].points_to_asc;
        }
    }

    int j;

    for(i=0; i <n; i++)
    {
        for(j=i+1; j < n;j++)
        {
            if(prim[i] == prim[j])
            {
                prim[j] = 0;
            }
        }
    }

    int zero = 0;

    for(i =0; i <n; i++)
    {
        if(prim[i] == 0)
        {
            zero++;
        }
    }

     for(i = 0; i < n; i++)
    {
        printf("i = %d, prim = %d \n", i, prim[i]);
    }

    int *left = (int*)calloc(zero, sizeof(int));

    printf("2\n");
    for(i =0; i < m; i++)
    {
        j = 0;
        int flag = 0;
        while(j<n)
        {
            if(prim[j] == all[i].name_asc)
            {
                flag = 1;
            }
            j++;
        }

        if(!flag)
        {
            for(j = 0; j<n; j++)
            {
                if(prim[j] == 0)
                {
                    prim[j] = all[i].name_asc;
                    break;
                }
            }
        }
    }

    printf("3\n");


    for(i = 0; i < n; i++)
    {
        printf("i = %d, prim = %d \n", i, prim[i]);
    }

    for(i =0; i < m; i++)
    {
        j = 0;
        int flag = 0;
        while(j<n)
        {
            if(prim[j] == all[i].points_to_asc)
            {
                flag = 1;
            }
            j++;
        }

        if(!flag)
        {
            for(j = 0; j<n; j++)
            {
                if(prim[j] == 0)
                {
                    prim[j] = all[i].points_to_asc;
                    break;
                }
            }
        }
    }

    printf("4\n");

    for(i = 0; i < n; i++)
    {
        printf("i = %d, prim = %d \n", i, prim[i]);
    }




    for(i = 0; i < m; i++)
    {
        printf("i: %d, Name: %s, Points to: %s, Head_Ascii: %d, Tail Ascii: %d \n", i+1, all[i].name, all[i].points_to, all[i].name_asc, all[i].points_to_asc);
    }

    //int sq = n++;

    printf("5\n");

    int **two_d = (int**)calloc(n+1, sizeof(int*));
    for(i = 0; i < n+1; i++)
    {
        two_d[i] = (int*)calloc(n+1, sizeof(int));
    }

    printf("6\n");

    print2d(two_d, n+1, n+1);

    printf("gg1\n");




    table_fill(two_d, all, prim, n, m);



    print2d(two_d, n+1, n+1);
    printf("gg\n");

    return 0;
}

void table_fill(int ** two_d, struct connections all[], int *prim, int n, int m)
{
    int i,j;
    printf("7\n");
    for(i = 0; i < n; i++)
    {
        two_d[i+1][0] = prim[i]; //vertical initial
    }

    for(i = 0; i < n; i++)
    {
        two_d[0][i+1] = prim[i]; //horizontal initial
    }

    for(i = 1; i <= n; i++) //in vertical of table starts two_d[1][0]
    {
        for(j = 0; j<m; j++)//two_d[i][0] == struct array[i]
        {
            if(all[j].name_asc == two_d[i][0])
            {
                int k;
                for (k = 1; k <= n; k++)
                {
                    if(all[j].points_to_asc == two_d[0][k])
                    {
                        two_d[i][k] = 1;
                    }
                }
            }
        }
    }


}

void print2d(int ** array, int row, int col)
{
    int i,j;

    printf("8");
    printf("\n");

    for (i = 0; i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%15d", array[i][j]);
        }
        puts("");
    }

}
