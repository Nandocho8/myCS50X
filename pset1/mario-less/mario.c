#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // define height
    int height;
    // prompt height
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //

    // for each row
    for (int i = 1; i <= height; i++)
    {
        // for each column point
        for (int k = height - i; k > 0; k--)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        // for each column hash

        printf("\n");
    }
}