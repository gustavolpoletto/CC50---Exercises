#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for ( int i = 0; i < height ; i++)
    {
        for ( int j = 0 ; j < width ; j++)
        {
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;

            int gray = round((blue + green + red) / 3.0);

            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed= gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for ( int i = 0; i < height ; i++)
    {
        for ( int j = 0 ; j < width ; j++)
        {
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;

            int sepiaRed = round(0.393*red + 0.769*green + 0.189*blue);
            int sepiaGreen = round(0.349*red + 0.686*green + 0.168*blue);
            int sepiaBlue = round(0.272*red + 0.534*green + 0.131*blue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed= sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for ( int i = 0; i < height ; i++)
    {
        for ( int j = 0 ; j < width / 2 ; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for ( int i = 0; i < height ; i++)
    {
        for ( int j = 0 ; j < width ; j++)
        {
            int red = 0;
            int green = 0;
            int blue = 0;
            int count = 0;

            for ( int n = -1; n <= 1; n++)
            {
                for ( int m = -1 ; m <= 1 ; m++)
                {
                    if(n + i >= 0 && n + i <= height - 1 && m + j >= 0 && m + j <= width - 1)
                    {
                        red += image[i + n][j + m].rgbtRed;
                        green += image[i + n][j + m].rgbtGreen;
                        blue += image[i + n][j + m].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round((float)red / count);
            image[i][j].rgbtGreen = round((float)green / count);
            image[i][j].rgbtBlue = round((float)blue / count);
        }
    }
}
