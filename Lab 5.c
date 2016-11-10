#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    char first_name[20];
    char last_name[20];
    float score;
    int zip;
    struct person *next;
};

struct person *head = NULL;

int stdnt_num;

void print_all();
void add_rec();
void del_rec();
void search_zip();
void score_range();
void sort_score();
void median();
void out();


int main ()
{
    int i;


    while (stdnt_num < 5)
    {
        printf("How many students?\n");
        scanf("%d", &stdnt_num);
        if (stdnt_num < 5)
        {
            printf("Number of students must at least 5\n\n");
        }
    }



    for (i = 0; i< stdnt_num; i++)
    {
        struct person *temp = (struct person*)malloc(sizeof(struct person));

        printf("What is student's first name?\n");
        scanf("%s", temp->first_name);

        printf("What is student's last name?\n");
        scanf("%s", temp->last_name);

        printf("What is the student's score?\n");
        scanf("%f", &temp->score);

        printf("What is the student's zip-code?\n");
        scanf("%d", &temp->zip);

        temp->next = head;
        head = temp;

    }

    int choice;

    while (choice != 0)
    {

        printf("\nPress 1 to print all entries\n");
        printf("Press 2 to add new record(s)\n");
        printf("Press 3 to delete record(s)\n");
        printf("Press 4 to search by zip-code\n");
        printf("Press 5 to search by score range\n");
        printf("Press 6 to find median score\n");
        printf("Press 0 to exit the program\n");

        printf("What is your choice?\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            print_all();
        }

        if (choice == 2)
        {
            add_rec();
        }

        if (choice == 3)
        {
            del_rec();
        }

        if (choice == 4)
        {
            search_zip();
        }

        if (choice == 5)
        {
            score_range();
        }

        if (choice == 6)
        {
            median();
        }

        if (choice == 0)
        {
            out();
        }
    }

//    print_all();




   return 0;
}

void print_all()
{
    struct person *temp;

    temp =head;

    while(temp != NULL)
    {
        printf("First Name: %s     Last Name: %s    Score: %.2f     Zip-Code: %d\n", temp->first_name, temp->last_name, temp->score, temp->zip);
        temp = temp->next;
    }

    //printf("\n STUDENT NUM == %d\n",stdnt_num);
}

void add_rec()
{
    int i, add;

    printf("How many new records are you adding?\n");
    scanf("%d", &add);

    stdnt_num += add;

    for (i = 0; i < add; i++)
    {
        struct person *temp = (struct person*)malloc(sizeof(struct person));

        printf("What is the student's first name?\n");
        scanf("%s", temp->first_name);

        printf("What is the student's last name?\n");
        scanf("%s", temp->last_name);

        printf("What is the student's score?\n");
        scanf("%f", &temp->score);

        printf("What is the student's zip-code?\n");
        scanf("%d", &temp->zip);

        temp->next = head;
        head = temp;
    }
}

void del_rec()
{
    char target[20];
    int counter = 0;

    struct person *right, *left, *temp;

    printf("What is your target last name?\n");
    scanf("%s", target);

    left = head;
    right = left->next;

    while (right != NULL)
    {
        counter++;
        if(strcmp(target, left->last_name) == 0)
        {
            temp = left;
            head = left = right;
            right = right->next;
            free(temp);
            stdnt_num--;
            continue;
        }

        else if (strcmp(target, right->last_name) == 0)
        {
            temp = right;
            left->next = right->next;
            right = right->next;
            free(temp);
            stdnt_num--;
        }

        else
        {
            left = right;
            right = right->next;
        }
    }

}

void search_zip()
{
    struct person *temp;

    temp = head;

    int target;

    printf("What is your target zip-code?\n");
    scanf("%d", &target);

    while (temp != NULL)
    {
        if (target == temp->zip)
        {
            printf("First Name: %s     Last Name: %s    Score: %.2f     Zip-Code: %d\n", temp->first_name, temp->last_name, temp->score, temp->zip);
        }

        temp = temp->next;
    }
}

void sort_score()
{
    struct person *left, *mid, *right;

    int i,change = 0, counter = 0;



    for (i = 0; i < stdnt_num -1; i++)
    {
       counter = 0;

       left = mid = head;
       right = mid->next;

       while (right != NULL)
       {
           counter++;

           if (((mid->score) < (right->score)))
           {
               change++;
               if (mid == head)
               {
                   //printf("\n ONE \n");
                   left = head = mid->next;
                   mid->next = right->next;
                   right->next = mid;
               }


               else
                {
                   //printf("\n TWO \n");
                   left->next = right;
                   mid->next = right->next;
                   right->next = mid;
                }



            }


            if (right == NULL)
            {
                break;
            }

            if (counter == 1 && change == 0)
            {
                //printf("CASE 1\n");
                mid = mid->next;
                right = right->next;
            }

            else if (counter == 1 && change > 0)
            {
                //printf("CASE 2\n");
                right = mid->next;
            }

            else if (counter > 1 && change == 0)
            {
                //printf("CASE 3\n");
                left = left->next;
                mid = mid->next;
                right = right->next;
            }

            else if (counter > 1 && change > 0)
            {
                //printf("CASE 4\n");
                left = left->next;
                right = mid->next;
            }



            change = 0;


        }
    }
}

void median()
{
    sort_score();

    struct person *temp = head;

    int i,median, above = 0, mid = stdnt_num/2;

    for(i =0; i < mid-1; i++)
    {
        temp = temp->next;
    }

    median = temp->score;

    temp = head;

    while(temp != NULL)
    {
        if(temp->score > median)
        {
            above++;
        }

        temp = temp->next;
    }

    printf("\nThe median score is %d and there are %d number(s) above it.\n", median, above);

}

void score_range()
{
    struct person *temp = head;

    int min, max;

    printf("What is your max score?\n");
    scanf("%d", &max);

    printf("What is your min score?\n");
    scanf("%d", &min);

    sort_score();

    while(temp != NULL)
    {
        if(temp->score >= min && temp->score <= max)
        {
            printf("First Name: %s     Last Name: %s    Score: %.2f     Zip-Code: %d\n", temp->first_name, temp->last_name, temp->score, temp->zip);
        }
        temp = temp->next;
    }
}

void out()
{
    printf("\n ** YOU HAVE EXITED THE PROGRAM. GOOD-BYE! **\n");
}
