#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name?\n"); //get name
    printf("hello, %s\n", name); // say hello
}
