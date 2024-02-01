#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int h;
   do
   {
        h = get_int("Height: ");
   }
   while (h < 1 || h > 8);

   for(int i = 0; i < h; i++)
   {

        for(int l = i + 1; l < h; l++)
        {
            printf(" ");
        }
       for(int j = h - 1 - i ; j < h; j++)
        {
            printf("#");
        }
        printf("\n");
   }
}
