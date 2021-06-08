#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num;

    do
    {
        num = get_long("Number: ");
    }
    while (num <= 0);

    long checknuma = num;
    int sum = 0;
    // the sum of the digits that weren't multiplied by 2
    while (checknuma > 0)
    {
        int ld = checknuma % 10;
        sum = sum + ld;
        checknuma = checknuma / 100;

    }

    // multiplied by 2
    long checknumb = num / 10;
    int sumt = 0;
    while (checknumb > 0)
    {
        int sd = checknumb % 10;
        int mt = sd * 2;
        int suml = 0;
        while (mt >= 10)
        {
            int l = mt % 10;
            suml = suml + l;
            mt = mt / 10;
        }
        sumt = sumt + suml + mt;
        checknumb = checknumb / 100;
    }

    // check sum
    int x = sum + sumt;

    if (x % 10 == 0)
    {
        int length = 0;       // check length
        long lennum = num;
        while (lennum > 0)
        {
            lennum = lennum / 10;
            length++;
        }
        long snum = num;
        if (length == 15)    // check Americen Express
        {
            snum = snum / 10000000000000;     // check start 2 digits
            int di = snum % 10;
            if (di == 4 || di == 7)
            {
                snum = snum / 10;
                int dit = snum % 10;
                if (dit == 3)
                {
                    printf("AMEX\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }

        else if (length == 16) // check 16-digit MasterCard and Visa
        {
            snum = snum / 1000000000000000;
            int dig = snum % 10;

            if (dig == 4)
            {
               printf("VISA\n");
            }
            else if (dig == 5)
            {
                long mnum = num;
                mnum = mnum / 100000000000000;
                int dim = mnum % 10;

                if (dim >= 1 && dim <= 5)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
               printf("INVALID\n");
            }
        }

        else if (length == 13) // check Visa
        {
            snum = snum / 1000000000000;
            int dis = snum % 10;
            if (dis == 4)
            {
                printf("VISA\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}
