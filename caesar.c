#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*Unencrypted text is generally called plaintext.
Encrypted text is generally called ciphertext.
And the secret used is called a key. */

/*
1. get plaintext
2. convert string to int
3. keep uppercase, lowercase to convert
4. keep space and , . !
5. add key
6. printf ciphertext by c = (p + k)%26
7. newline
   */
bool check_digit(string s);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string s = argv[1];
        if (check_digit(s))
        {
            int k = atoi(s);
            string ptext = get_string("plaintext:  ");
            printf("ciphertext: ");

            for (int i = 0; i < strlen(ptext); i++)
            {
                if (isalpha(ptext[i]))  // A-Z, a-z
                {
                    if (isupper(ptext[i]))  // A-Z
                    {
                        char x = ((ptext[i] + k - 'A') % 26) +'A';
                        printf("%c", x);
                    }
                    else if (islower(ptext[i])) // a-z
                    {
                        char y = ((ptext[i] + k - 'a') % 26 + 'a');
                        printf("%c", y);
                    }
                }
                else
                {
                    printf("%c", ptext[i]);
                }

            }

            printf("\n");
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;

    }

    return 0;

}

//function to check digit
bool check_digit(string s)
{
    bool status = true;
    int a = 0, c = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]))
        {
            c++;
        }
        if (isalnum(s[i]))
        {
            a++;
        }
    }
    //printf("c = %i\na = %i\n", c, a);
    if (a == c)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}
