//Program to make and manage a Teachers' Students Database Management System

#include <stdio.h>
#include <stdlib.h>

void append(FILE *fileptr, int enrNo, char name[20], char branch[10], char batch[10], int marks);
void read(FILE *fileptr);

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./mgmt filename.csv\n");
        exit(1);
    }

    FILE *fileptr = fopen(argv[1], "a+");

    int action;
    int enrNo, marks;
    char name[20], branch[10], batch[10];

    printf("Enter the action you want to perform form the following menu:\n");
    printf("1. Append a new entry\n");
    printf("2. Read entries\n");
    scanf("%d", &action);

    switch(action)
    {
        case 1: printf("Enter enrolment no, name, branch, batch and marks of student seperated by space:\n");
                scanf("%d %s %s %s %d", &enrNo, name, branch, batch, &marks);
                append(fileptr, enrNo, name, branch, batch, marks);
                break;
        case 2: printf("Displaying the entries:\n");
                read(fileptr);
    }

    fclose(fileptr);
}

// //Function to open a new file
// FILE *build()
// {
//     FILE *fileptr = fopen("management.csv", "a+");

//     return fileptr;
// }

//Append to a file
void append(FILE *fileptr, int enrNo, char name[20], char branch[10], char batch[10], int marks)
{
    fprintf(fileptr, "%d %s %s %s %d\n", enrNo, name, branch, batch, marks);
}
//Read the file
void read(FILE *fileptr)
{
    int end;
    int enrNo, marks;
    char name[20], branch[10], batch[10];

    while(1)
    {
        end = fscanf(fileptr, "%d %s %s %s %d", &enrNo, name, branch, batch, &marks);

        if(end < 0)
        {
            printf("Entries over\n");
            break;
        }
        printf("Enrollment No: %d\nName: %s\nBranch: %s\nBatch: %s\nMarks: %d\n", enrNo, name, branch, batch, marks);
    }
}