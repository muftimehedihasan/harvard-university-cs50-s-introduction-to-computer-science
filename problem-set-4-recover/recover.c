
#include <stdio.h>
#include <stdint.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open memory card file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create buffer to read blocks from memory card
    uint8_t buffer[BLOCK_SIZE];

    // File to write JPEGs
    FILE *img = NULL;

    // Counter for JPEG file names
    int img_count = 0;

    // Read blocks from memory card until end of file
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        // Check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If already writing to a JPEG, close it
            if (img != NULL)
            {
                fclose(img);
            }

            // Create new JPEG file
            char filename[8];
            sprintf(filename, "%03i.jpg", img_count++);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create output file.\n");
                fclose(file);
                return 1;
            }

            // Write block to JPEG file
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
        else
        {
            // Continue writing to current JPEG file
            if (img != NULL)
            {
                fwrite(buffer, BLOCK_SIZE, 1, img);
            }
        }
    }

    // Close remaining files
    if (img != NULL)
    {
        fclose(img);
    }

    // Close memory card file
    fclose(file);

    return 0;
}

