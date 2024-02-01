#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DATA_BLOCK 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }


    // initial variables
    // Flag to keep treack of jpegs
    bool found_jpg = false;
    // Create buffer of 512 bytes for block of data
    uint8_t *buffer = malloc(sizeof(uint8_t) * DATA_BLOCK);
    // JPEG counter
    int jpg_counter = 0;
    // file name string
    char jpg_name[8];
    // output file
    FILE *newImg = NULL;

    // While there's still data left to read from the memory card
    while(fread(buffer, 1, DATA_BLOCK, card) == DATA_BLOCK)
    {
            // If it is start of new JPEG.
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                //Close previous file if one was open.
                if (found_jpg)
                {
                    fclose(newImg);
                }
                else
                {
                    found_jpg = true;
                }

                //Open new JPEG file
                sprintf(jpg_name, "%03i.jpg", jpg_counter);
                newImg = fopen(jpg_name, "w");
                if (newImg == NULL)
                {
                    fclose(card);
                    printf("Could not create %s\n", jpg_name);
                    return 3;
                }
                jpg_counter++;

                // Write data to new JPEG file
                fwrite(buffer, DATA_BLOCK, 1, newImg);
            }
            else if(found_jpg)
            {
                // if already found JPEG, keep writing to same JPEG
                fwrite(buffer, DATA_BLOCK, 1, newImg);
            }

    }
    //Close remaining files.
    fclose(card);
    if (found_jpg)
    {
    fclose(newImg);
    }
    free(buffer);
    return 0;

}
