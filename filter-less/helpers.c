#include "helpers.h"
#include <math.h>
#include <stdio.h>

void swap(int *a, int *b);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop over all pixels
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            // find avrage of RGB colours
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            // update values to average
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // loop over all pixels
     for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            //compute sepia values
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 *  image[i][j].rgbtGreen + .189 *  image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            printf("%i\n", sepiaBlue);
            // Upper cap colour values to 255
            if ( sepiaRed > 255) {
                sepiaRed = 255;
            }
            if ( sepiaGreen > 255) {
                sepiaGreen = 255;
            }
            if ( sepiaBlue > 255) {
                sepiaBlue = 255;
            }

            // change colour values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // loop over pixels
    for (int i = 0; i < height; i++)
    {
        for(int j =0; j < (width/2); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double red = 0;
            double blue = 0;
            double green = 0;
            double counter = 0;

           for (int s = -1; s < 2; s++)
           {
                for (int m = - 1; m < 2; m++)
                {
                    int d = i + s;
                    int k = j + m;

                    if (d < height && k < width && d >= 0 && k >= 0)
                    {
                    red += copy[d][k].rgbtRed;
                    blue += copy[d][k].rgbtBlue;
                    green += copy[d][k].rgbtGreen;
                    counter ++;
                    }

                }
           }

           image[i][j].rgbtRed = round(red / counter);
           image[i][j].rgbtGreen = round(green / counter);
           image[i][j].rgbtBlue = round(blue / counter);
        }
    }
    return;
}


