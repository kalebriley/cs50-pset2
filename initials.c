/*
*
* initials.c
*
* Kaleb Riley
*
* This programs asked the user to input his/her name
* and returns the initials.
*
**/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    string name;
    
    // get a name from the user
    do
    {
        name = GetString();
    }
    while (strlen(name) < 1);

    // declares an intitial boolean sets it to true
    bool initial = true;
    
    // prints char if it is an initial
    for(int i = 0, n = strlen(name);i < n;i++)
    {
        if (initial == true)
        {
            printf("%c", toupper(name[i]));
        }
        
        if (isalpha(name[i]))
        {
            initial = false;
        }
        else
        {
            initial = true;
        }
    }
    printf("\n");
        
}

