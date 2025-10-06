#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"

struct User
{
    char username[50];
    char password[50];
};

int authenticate()
{
    int choice;
    char username[50],password[50];
    struct User user;

    FILE *file;

    while (1)
    {
        printf("\n1. Sign up");
        printf("\n2. Login");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        if (choice==1)
        {
            printf("Create Username: ");
            scanf("%s",username);

            int exists=0;
            file=fopen("users.txt","r");
            if (file!=NULL)
            {
                while (fscanf(file,"%s %s",user.username,user.password)==2)
                if (strcmp(user.username,username)==0)
                {
                    printf("Username already exists. Try logging in.\n");
                    exists=1;
                    break;
                }
                fclose(file);
            }

            if (exists)
            continue;

            printf("Create Password: ");
            scanf("%s",password);

            file=fopen("users.txt","a");
            if (file==NULL)
            {
                printf("Could not open file for writing.\n");
                exit(1);
            }
            fprintf(file,"%s %s\n",username,password);
            fclose(file);

            printf("Registration successful! Please log in.\n");

        }
        else if (choice==2)
        {
            printf("Enter Username: ");
            scanf("%s",username);
            printf("Enter Password: ");
            scanf("%s",password);

            int found=0;
            file=fopen("users.txt","r");
            if (file==NULL)
            {
                printf("No users registered. Please sign up first.\n");
                continue;
            }

            while (fscanf(file,"%s %s",user.username,user.password)==2)
            {
                if (strcmp(user.username,username)==0 && strcmp(user.password,password)==0)
                {
                    found=1;
                    break;
                }
            }
            fclose(file);

            if (found)
            {
                printf("Login successful!\n");
                return 1;
            }
            else
            printf("Invalid username or password.\n");

        }
        else 
        printf("Invalid choice. Try again.\n");
    }
}

void freeAuth()
{ }