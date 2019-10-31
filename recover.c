#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //ensures proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    char *raw = argv[1];
    FILE *fileptr = fopen(raw, "r");

    //check that fileptr doesnt return null value
    if (fileptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", raw);
        return 2;
    }

    unsigned char *buffer = malloc(512);
    int jpgnum = 0;
    FILE *img;

    while (fread(buffer, 512, 1, fileptr))
    {
        //new img found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //closes file
            if (jpgnum > 0)
            {
                fclose(img);
            }
            char fname[7];
            sprintf(fname, "%0.3i.jpg", jpgnum);

            img = fopen(fname, "w");

            //checks for null ptr
            if (img == NULL)
            {
                fclose(fileptr);
                free(buffer);
                return 3;
            }

            //increment to jpg number
            jpgnum++;

        }
        if (!jpgnum)
        {
            continue;
        }
        //write to file
        fwrite(buffer, 512, 1, img);
    }

    fclose(fileptr);
    fclose(img);
    free(buffer);
    return 0;
}
