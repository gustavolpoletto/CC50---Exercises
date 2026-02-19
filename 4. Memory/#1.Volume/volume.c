// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

// BYTE & 2BYTE structure
typedef uint8_t BYTE;
typedef int16_t Double_Byte;


int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    //Copy header from input file to output file

    BYTE buffer;

    for (int i = 0 ; i < HEADER_SIZE ; i++)
    {
        fread(&buffer, sizeof(BYTE), 1, input);
        fwrite(&buffer, sizeof(BYTE), 1, output);
    }

    //Read samples from input file and write updated data to output file

    Double_Byte Bytes;

    while(fread(&Bytes, sizeof(Double_Byte), 1, input) == 1)
    {
        Bytes = Bytes * factor;
        fwrite(&Bytes, sizeof(Double_Byte), 1, output);
    }


    // Close files
    fclose(input);
    fclose(output);
}
