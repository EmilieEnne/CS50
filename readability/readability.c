#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int cnt_let(string text);
int cnt_wrd(string text);
int cnt_snt(string text);

int main(void)
{
    // get text from user
    string text = get_string("Text: ");

    // get number of letters in text
    float let = cnt_let(text);

    // get number of words
    float wrd = cnt_wrd(text);

    // get number of sentences
    float snt = cnt_snt(text);

    // put score through formula
    float l = (let / wrd) * 100;
    float s = (snt / wrd) * 100;
    int lvl = round(0.0588 * l - 0.296 * s - 15.8);

    // output readability level
    if (lvl < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (lvl > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", lvl);
    }
}

int cnt_let(string text)
{
    int score = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            score += 1;
        }
    }

    return score;
}

int cnt_wrd(string text)
{
    int score = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            score += 1;
        }
    }

    return score + 1;
}

int cnt_snt(string text)
{
    int score = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.')
        {
            score += 1;
        }
        else if (text[i] == '!')
        {
            score += 1;
        }
        else if (text[i] == '?')
        {
            score += 1;
        }
    }

    return score;
}
