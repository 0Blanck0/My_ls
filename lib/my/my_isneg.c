/*
** ETNA PROJECT, 29/09/2020 by rechau_l
** my_isneg
** File description:
**      day 1 step 4
*/

#include <unistd.h>

void my_putchar(char c);

void my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
}
