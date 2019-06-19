#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long long cardNumber;
    int multiply = 0;
    int totalSum = 0;
    long long x; // x is just used to put the numbers in an array
    int count;
    int count2 = 0;

    do
    {
        // ask user for his/her credit card number
        cardNumber = get_long("Enter your card number here: ");
        long long n = cardNumber;
        count = 0; // number of digits in the number

        // check how many digits the int has
        while(n > 0)
        {
            n /= 10;
            count++;
        }

    } while (count != 13 && count < 15 && count > 16); // deny when it doesn't has 13,15 or 16 digits

    int numberArray[count];
    int productSum[2];
    x = cardNumber;

    for(int i = 0; i < count; i++)
    {
        numberArray[i] = x % 10;
        x /= 10;
    }

    for(int i = 0; i < count; i += 2)
    {
        multiply = numberArray[i] *2;

        // check how many digits the int has
        while(multiply > 0)
        {
            multiply /= 10;
            count2++;
        }
        
        // for loop to add up the digits form multiply
        for(int j = 0; j < count2; j++)
        {
            productSum[j] = count2 % 10;
            count2 /= 10;
            totalSum += productSum[j];
        }
    }

    for(int i = 1; i < count; i += 2)
    {
        multiply = numberArray[i];
        totalSum += multiply;
    }

    //Check the first numbers to know what brand it is
    if (totalSum % 10 == 0)
    {
        if (cardNumber / 10000000000000 == 34 || cardNumber / 10000000000000 == 37)
        {
        printf("AMEX\n");
        }

        else if (cardNumber / 100000000000000 == 52 || cardNumber / 100000000000000 == 53 || cardNumber / 100000000000000 == 54 || cardNumber / 100000000000000 == 55)
        {
            printf("MASTERCARD\n");
        }

        else if (cardNumber / 1000000000000 == 4 || cardNumber / 1000000000000000 == 4)
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }

    return 0;
}