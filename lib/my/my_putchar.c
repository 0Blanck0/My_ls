/*
** ETNA PROJECT, 02/10/2020 by rechau_l
** my_putchar
** File description:
**      prints a character
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
