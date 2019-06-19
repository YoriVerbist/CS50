#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    float dollars;
    int quaters = 0;
    int dimes = 0;
    int nickles = 0;
    int pennies = 0;


    do
    {
        dollars = get_float("Change owed: ");

    } while (dollars < 0);
    
    int cents = round(dollars * 100);

    while (cents > 0)
    {
        if (cents >= 25)
        {
            quaters++;
            cents -= 25;
        }
        
        else if (cents < 25 && cents >= 10)
        {
            dimes++;
            cents -= 10;
        }

        else if (cents < 10 && cents >= 5)
        {
            nickles++;
            cents -= 5;
        }

        else
        {
            pennies++;
            cents--;
        }
        
    }
        int total = quaters + dimes + nickles + pennies;
        printf("%i\n", total);

    return 0;
}
