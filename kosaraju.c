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

struct used
    {
        int asc;
        int found;
        int asso;
        char name[25];
    };

void table_fill(int ** two_d, struct connections all[], int *prim, int n, int m);

void print2d(int ** array, int row, int col);

void scc_print(int ** two_d, struct used u_l[], struct connections all[], int *prim, int n, int m, int i, int j);

void final_scc(struct used u_l[], int n, int *keep, int i, int scc_num);

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

   // int *left = (int*)calloc(zero, sizeof(int));

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




    struct used *u_l = (struct used*)calloc(n, sizeof(struct used));



    for (i=0; i <n; i++)
    {
        u_l[i].asc = prim[i];
        u_l[i].found = 0;
        for(j = 0; j <m; j++)
        {
            if(u_l[i].asc == all[j].name_asc)
            {
                strcpy(u_l[i].name, all[j].name);
            }

            if(u_l[i].asc == all[j].points_to_asc)
            {
                strcpy(u_l[i].name, all[j].points_to);
            }
        }
    }

    scc_print(two_d, u_l, all, prim, n,m, 0,1);
    print2d(two_d, n+1, n+1);

    int p;
    for(p=0;p<n;p++)
    {
        printf("used[%d]  =  %d   name = %s       Found = %d     Asso = %d\n", p, u_l[p].asc, u_l[p].name, u_l[p].found, u_l[p].asso);
    }

    int *keep = (int*)calloc(n,sizeof(int));

    int scc_num = 1;

    for(i=0;i<n;i++)
    {
        if(keep[i] == 0)
        {
            if(u_l[i].asso ==0)
            {
                final_scc(u_l, n, keep, i, scc_num);
                scc_num++;
            }
            else
            {
                final_scc(u_l, n, keep, i, scc_num);
                scc_num++;
            }

        }
    }



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

void scc_print(int **two_d,struct used u_l[], struct connections all[], int *prim, int n, int m, int i, int j)
{
    //int flag;

    for(i=0;i<n;i++)
    {
        printf("used[%d]  =  %d    Found = %d\n",i,u_l[i].asc, u_l[i].found);
    }

    for(j = j; j <= n; j++) //going across horizontally start comparing @ [0][1]
    {
        //printf("11\n");
        //flag = 0;
        //u_l[j-1].found = 1;
        for(i = 1; i <= n; i++)//going down that j value [1][1]
        {
            //printf("111\n");
            if(two_d[i][j] == 1)
            {
                printf("Found a 1 @ [%d][%d]\n", i,j);
                //flag  = 1;
                if(u_l[j-1].found == 0)
                {
                    //flag = 1;
                    if(u_l[i-1].found != 1)
                    {
                        u_l[j-1].asso = u_l[i-1].asc;
                        u_l[j-1].found = 1;
                        scc_print(two_d, u_l, all, prim, n,m, i,i);


                    }
                    //break;
                }

                //break;


            }

            else if (i == n)
            {
                u_l[j-1].found = 1;
            }

        }

    }

    int p;
    for(p=0;p<n;p++)
    {
        printf("used[%d]  =  %d    Found = %d     Asso = %d\n",p,u_l[p].asc, u_l[p].found, u_l[p].asso);
    }


}

void final_scc(struct used u_l[], int n, int *keep, int i, int scc_num)
{
    int j;

    //printf("UL SIZE: %d\n", sizeof(u_l)/sizeof(struct used));


    if(keep[i] == 0)
    {
        printf("SCC %d: \n", scc_num);
        keep[i] = 1;
        printf("%s \n",u_l[i].name);
        if(u_l[i].asso !=0)
        {
            //target = u_l[i].asso;
            for(j = 0; j < n; j++)
            {
                if(u_l[j].asc == u_l[i].asso)
                {
                    final_scc(u_l, n, keep, j, scc_num);
                }
            }
            //final_scc(u_l, n, keep, target, scc_num);
        }
        else
        {
            //scc_num++;
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
            printf("%6d", array[i][j]);
        }
        puts("");
    }

}
