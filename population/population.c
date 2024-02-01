#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Llama starting population: ");
    }

    while (start < 9);
    // TODO: Prompt for end size

    int goal;
    do
    {
        goal = get_int("Llama population goal: ");
    }
    while (goal < start);

    // TODO: Calculate number of years until we reach threshold
    int year = 0;

    while (start < goal)
    {
        start = start + (start / 3) - (start / 4);
        year++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", year);
}
