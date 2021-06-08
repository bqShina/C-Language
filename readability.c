#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)  /*count the number of letters, words and sentences
and index = 0.0588 * L - 0.296 * S - 15.8   L = averageLetter (100) S = Average sentence  */
{
    //get text
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    //printf("letters = %i, words = %i, sentences = %i\n", letters, words, sentences);

    float L = (letters * 100.0f) / words, S = (sentences * 100.0f) / words;

    // printf("L = %f, S = %f", L, S);

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index >= 1 || index < 16)
    {
        printf("Grade %i\n", index);
    }

    return 0;
}
// count letters function
int count_letters(string s)
{
    int letters = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        char a = s[i];
        
        if (isalpha(a))
        {
           letters++;
        }
    }
    
    return letters;
}
// count words
int count_words(string s)
{
    int words = 1;

    for (int i = 0; i < strlen(s); i++)
    {
        char a = s[i];
        
        if (isspace(a))
        {
           words++;
        }
    }
    
    return words;
}
//count sentences
int count_sentences(string s)
{
    int sentences = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        char a = s[i];
        
        if (a == '.' || a == '!' || a == '?')
        {
           sentences++;
        }
    }
    
    return sentences;
}
