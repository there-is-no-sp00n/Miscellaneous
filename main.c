// Driver to handle operations in 2320 Lab 3, Spr 2017
#include <stdlib.h>
#include <stdio.h>
#include "RB.h"

int main()
{
int op,key,rank,i;

i =0;

int *tombstone;
tombstone = (int*)calloc(i, sizeof(int));
int *recycled;
int *live;
STinit();  // Initialize red-black tree
verifyRBproperties();

scanf("%d",&op);
while (op)
{
  switch (op)
  {
    case 1:
      scanf("%d",&key);
      printf("1 %d\n",key);
      STinsert(key);
      break;
    case 2:
      scanf("%d",&key);
      printf("2 %d\n",key);
      rank = STinvSelect(key);
      if (rank != -1)
      {
          i++;
          tombstone = realloc(tombstone, i * sizeof(int));
          tombstone[i - 1] = rank;
      }

      int j = 0;
      while(j < i)//(sizeof(tombstone)/4) )
      {
          printf("%d \n", tombstone[j]);
          j++;
      }
    //  STdelete(key);
      break;
    case 3:
      scanf("%d",&key);
      printf("3 %d\n",key);
      rank=STinvSelect(key);
      if (rank==(-1))
        printf("Key %d is not in tree\n",key);
      else
        printf("Key %d has rank %d\n",key,rank);
      break;
    case 4:
        getLive(i);
      scanf("%d",&rank);
      printf("4 %d\n",rank);
      if (rank<1 || rank>getLive(i))
        printf("rank %d range error\n",rank);
      else if (rank != 0 || rank <= getLive(i))
      {
          int a = 0;
          for(a = 0; a < i; a++)
          {
              if (tombstone[a] == rank)
              {
                  printf("The number with rank %d has been tombstoned! \n", rank);
                  a = 0;
                  break;
              }
          }

          if(a)
              {
                  printf("rank %d has key %d\n",rank,key(STselect(rank)));
                  break;
              }
      }

      break;
   // case 5:
   //   printf("5\n");
   //   printf("Live %d Dead %d Recycled %d\n",
   //     getLive(i),getDead(i),getRecycled());
   //   break;
    case 6:
      printf("6\n");
      if (getDead(i))
        removeDead(tombstone, live);
      break;
    case 7:
      printf("7\n");
      STprintTree();
      break;
    case 8:
      printf("8\n");
      if (verifyRBproperties())
        printf("clean\n");
      else
        printf("corrupt\n");
      break;
    default:
      printf("Bad operation %d\n",op);
  }
  //fflush(stdout);  // In case output is going to a fifo
  scanf("%d",&op);
}
printf("0\n");
}
