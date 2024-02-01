#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool correctkey(string s);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    // get prompt for key
    if (argc == 2 && correctkey(argv[1]))
    {
        // atoi
        int key = atoi(argv[1]);

        // get plain text
        string plain = get_string("Plaintext: \n");

        printf("ciphertext: ");

        for (int i = 0; i < strlen(plain); i++)
        {
            char cifer = rotate(plain[i], key);

            printf("%c", cifer);
        }

        printf("\n");
    }
    else
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }
}

bool correctkey(string s)
{
    int i;
    char c;
    for (i = 0; i < strlen(s); i++)
    {
        c = s[i];
        if (isdigit(c) == 0)
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int key)
{
    char ct;
    if (isalpha(c))
    {
        if (islower(c))
        {
            c = c - 97;
            int f = (c + key) % 26;
            ct = f + 97;
        }
        else
        {
            c = c - 65;
            int f = (c + key) % 26;
            ct = f + 65;
        }
    }
    else
    {
        return c;
    }

    return ct;
}
