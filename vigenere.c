/**
*
* viginere.c
*
* Kaleb Riley
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define UPPER 65
#define LOWER 97

int main(int argc, char* argv[])
{
    // check for correct argument count
    if (argc != 2)
    {
        return 1;
    }
    
    // prompt user for plain text
    string message = GetString();
    
    // set key
    string key = argv[1];
    
    int klen = strlen(key);
    
    // upper case key
    for (int i = 0; i < klen; i++)
    {
        key[i] = toupper(key[i]) - UPPER;
    }
    
    // cipher text
    for (int i = 0, j = 0, n = strlen(message); i < n; i++)
    {
        // checks if character is an alphabet
        if (isalpha(message[i]))
        {
            // checks if character is upper or lower case
            if (isupper(message[i]))
            {
                message[i] = (((message[i] - UPPER) + key[j]) % 26) + UPPER;
            }
            else
            {
                message[i] = (((message[i] - LOWER) + key[j]) % 26) + LOWER;
            }
            j = (j + 1) % klen;
        }
    } 
    
    // print text
    printf("%s\n", message);
    
    
}
