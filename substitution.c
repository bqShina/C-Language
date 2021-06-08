#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* 26-character key
get key
check key (key is a string, key is letters, 26 letters, no repeat)
get plaintext
encipher
print ciphertext
*/
bool check_alpha(string s);
bool check_repeat(string s);

int main(int argc, string argv[])
{
    if (argc == 2)   //key
    {
        string key = argv[1];

        if (strlen(key) == 26)  //26-character key
        {
            if (check_alpha(key))  //key only includes letters
            {
                if (check_repeat(key))
                {
                    string ptext = get_string("plaintext:  ");    //get plaintext
                    printf("ciphertext: ");
                    for (int i = 0; i < strlen(ptext); i++)       //encipher
                    {
                        char ch = ptext[i], ctext;

                        if (isalpha(ch))
                        {
                            char chp = toupper(ch);
                            int n = chp - 'A';
                            char cc = key[n];
                            ctext = islower(ch) ? tolower(cc) : cc;
                            printf("%c", ctext);
                        }
                        else
                        {
                            printf("%c", ch);
                        }

                    }
                    printf("\n");

                }
                else
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
            else
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }

        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

    }
    else
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    return 0;
}

bool check_alpha(string s)
{
    bool status = true;
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isalpha(s[i]))
        {
            status = false;
        }
    }
    return status;
}

bool check_repeat(string s)
{
    bool status = true;
    for (int i = 0; i < strlen(s); i++)
    {
        if (islower(s[i]))
        {
            s[i] = toupper(s[i]);
        }

        for (int j = i + 1; j < strlen(s); j++)
        {
            if (islower(s[j]))
            {
                s[j] = toupper(s[j]);
            }
            if (s[i] == s[j])
            {
                status = false;
            }
        }
    }
    return status;
}
