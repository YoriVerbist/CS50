#include "helpers.h"

#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int average = round((image[y][x].rgbtRed + image[y][x].rgbtGreen + image[y][x].rgbtBlue) / 3.0);
            image[y][x].rgbtRed = average;
            image[y][x].rgbtGreen = average;
            image[y][x].rgbtBlue = average;
        }
    }
    
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int sepiaRed = round(0.393 * image[y][x].rgbtRed + 0.769 * image[y][x].rgbtGreen + 0.189 * image[y][x].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            int sepiaGreen = round(0.349 * image[y][x].rgbtRed + 0.686 * image[y][x].rgbtGreen + 0.168 * image[y][x].rgbtBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            int sepiaBlue = round(0.272 * image[y][x].rgbtRed + 0.534 * image[y][x].rgbtGreen + 0.131 * image[y][x].rgbtBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[y][x].rgbtRed = sepiaRed;
            image[y][x].rgbtGreen = sepiaGreen;
            image[y][x].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            tmp[y][width - x - 1] = image[y][x];
        }
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            image[y][x] = tmp[y][x];
        }
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            float pixels = 0;
            int averageRed = 0;
            int averageGreen = 0;
            int averageBlue = 0;

            if (y == 0 && x == 0) // Top left
            {
                averageRed = image[y][x].rgbtRed + image[y + 1][x + 1].rgbtRed + image[y][x + 1].rgbtRed + image[y + 1][x].rgbtRed;
                averageBlue = image[y][x].rgbtBlue + image[y + 1][x + 1].rgbtBlue + image[y][x + 1].rgbtBlue + image[y + 1][x].rgbtBlue;
                averageGreen = image[y][x].rgbtGreen + image[y + 1][x + 1].rgbtGreen + image[y][x + 1].rgbtGreen + image[y + 1][x].rgbtGreen;
                pixels = 4,0;
            }
            else if (x == 0 && y != 0 && y != height - 1) // Left column
            {
                averageRed = image[y][x].rgbtRed + image[y + 1][x + 1].rgbtRed + image[y][x + 1].rgbtRed + image[y + 1][x].rgbtRed + image[y - 1][x].rgbtRed + image[y - 1][x + 1].rgbtRed;
                averageBlue = image[y][x].rgbtBlue + image[y + 1][x + 1].rgbtBlue + image[y][x + 1].rgbtBlue + image[y + 1][x].rgbtBlue + image[y - 1][x].rgbtBlue + image[y - 1][x + 1].rgbtBlue;
                averageGreen = image[y][x].rgbtGreen + image[y + 1][x + 1].rgbtGreen + image[y][x + 1].rgbtGreen + image[y + 1][x].rgbtGreen + image[y - 1][x].rgbtGreen + image[y - 1][x + 1].rgbtGreen;
                pixels = 6,0;
            }
            else if (y == 0 && x != 0 && x != width - 1) // Top row
            {
                averageRed = image[y][x].rgbtRed + image[y + 1][x + 1].rgbtRed + image[y][x + 1].rgbtRed + image[y + 1][x].rgbtRed + image[y][x - 1].rgbtRed + image[y + 1][x - 1].rgbtRed;
                averageBlue = image[y][x].rgbtBlue + image[y + 1][x + 1].rgbtBlue + image[y][x + 1].rgbtBlue + image[y + 1][x].rgbtBlue + image[y][x - 1].rgbtBlue + image[y + 1][x - 1].rgbtBlue;
                averageGreen = image[y][x].rgbtGreen + image[y + 1][x + 1].rgbtGreen + image[y][x + 1].rgbtGreen + image[y + 1][x].rgbtGreen + image[y][x - 1].rgbtGreen + image[y + 1][x - 1].rgbtGreen;
                pixels = 6,0;
            }
            else if (y == height - 1 && x == 0) // left bottom corner
            {
                averageRed = image[y][x].rgbtRed + image[y - 1][x + 1].rgbtRed + image[y][x + 1].rgbtRed + image[y - 1][x].rgbtRed;
                averageBlue = image[y][x].rgbtBlue + image[y - 1][x + 1].rgbtBlue + image[y][x + 1].rgbtBlue + image[y - 1][x].rgbtBlue;
                averageGreen = image[y][x].rgbtGreen + image[y - 1][x + 1].rgbtGreen + image[y][x + 1].rgbtGreen + image[y - 1][x].rgbtGreen;
                pixels = 4,0;
            }
            else if (y == height - 1 && x != 0 && x != width - 1) // Bottom row
            {
                averageRed = image[y][x].rgbtRed + image[y - 1][x - 1].rgbtRed + image[y][x + 1].rgbtRed + image[y - 1][x].rgbtRed + image[y][x - 1].rgbtRed + image[y - 1][x + 1].rgbtRed;
                averageBlue = image[y][x].rgbtBlue + image[y - 1][x - 1].rgbtBlue + image[y][x + 1].rgbtBlue + image[y - 1][x].rgbtBlue + image[y][x - 1].rgbtBlue + image[y - 1][x + 1].rgbtBlue;
                averageGreen = image[y][x].rgbtGreen + image[y - 1][x - 1].rgbtGreen + image[y][x + 1].rgbtGreen + image[y - 1][x].rgbtGreen + image[y][x - 1].rgbtGreen + image[y - 1][x + 1].rgbtGreen;
                pixels = 6,0;
            }
            else if (y == height - 1 && x == width - 1) // Right bottom corner
            {
                averageRed = image[y][x].rgbtRed + image[y - 1][x - 1].rgbtRed + image[y][x - 1].rgbtRed + image[y - 1][x].rgbtRed;
                averageBlue = image[y][x].rgbtBlue + image[y - 1][x - 1].rgbtBlue + image[y][x - 1].rgbtBlue + image[y - 1][x].rgbtBlue;
                averageGreen = image[y][x].rgbtGreen + image[y - 1][x - 1].rgbtGreen + image[y][x - 1].rgbtGreen + image[y - 1][x].rgbtGreen;
                pixels = 4,0;
            }
            else if (x == width - 1 && y != 0 && y != height - 1) // Right column
            {
                averageRed = image[y][x].rgbtRed + image[y - 1][x - 1].rgbtRed + image[y][x - 1].rgbtRed + image[y + 1][x].rgbtRed + image[y - 1][x].rgbtRed + image[y + 1][x - 1].rgbtRed;
                averageBlue = image[y][x].rgbtBlue + image[y - 1][x - 1].rgbtBlue + image[y][x - 1].rgbtBlue + image[y + 1][x].rgbtBlue + image[y - 1][x].rgbtBlue + image[y + 1][x - 1].rgbtBlue;
                averageGreen = image[y][x].rgbtGreen + image[y - 1][x - 1].rgbtGreen + image[y][x - 1].rgbtGreen + image[y + 1][x].rgbtGreen + image[y - 1][x].rgbtGreen + image[y + 1][x - 1].rgbtGreen;
                pixels = 6,0;
            }
            else if (x == width - 1 && y == 0) // Top right corner
            {
                averageRed = image[y][x].rgbtRed + image[y + 1][x - 1].rgbtRed + image[y][x - 1].rgbtRed + image[y + 1][x].rgbtRed;
                averageBlue = image[y][x].rgbtBlue + image[y + 1][x - 1].rgbtBlue + image[y][x - 1].rgbtBlue + image[y + 1][x].rgbtBlue;
                averageGreen = image[y][x].rgbtGreen + image[y + 1][x - 1].rgbtGreen + image[y][x - 1].rgbtGreen + image[y + 1][x].rgbtGreen;
                pixels = 4,0;
            }
            // Middle pixels
            else {
                for (int k = -1; k < 2; k++)
                {
                    for (int l = -1; l < 2; l++)
                    {
                        averageRed += image[y + k][x + l].rgbtRed;
                        averageGreen += image[y + k][x + l].rgbtGreen;
                        averageBlue += image[y + k][x + l].rgbtBlue;
                        pixels += 1,0;
                    }
                }
            }
            
            averageRed = round(averageRed / pixels);
            averageGreen = round(averageGreen / pixels);
            averageBlue = round(averageBlue / pixels);
            
            tmp[y][x].rgbtRed = averageRed;
            tmp[y][x].rgbtGreen = averageGreen;
            tmp[y][x].rgbtBlue = averageBlue;
        }
        
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            image[y][x] = tmp[y][x];
        }
    }
    
    return;
}