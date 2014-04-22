/**
*
* ceasar.c
*
* Kaleb Riley
*
* This programs encrypts a given plain tex.
*/

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define UPPER 65
#define LOWER 96
#define ENALPHA 26

string cipher(string s, int k);

int main(int argc, char* argv[])
{
    // check for correct amount of arguments
    if (argc != 2)
    {   
        return 1;
    }
    
    // set key
    int key = atoi(argv[1]);
    
    // ask for plain text
    string message = GetString();
    
    // cipher plain text and print ciphered text
    printf("%s\n", cipher(message, key));
    
}

// cipher takes a message and a key and rotates the message by the key
string cipher(string s, int k)
{
    
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            {
                s[i] = (s[i] - UPPER) + (k % ENALPHA) + UPPER;       
            }
            else
            {
                s[i] = (s[i] - LOWER) + (k % ENALPHA) + LOWER;
            }
        }
    }
    
    return s;
}
