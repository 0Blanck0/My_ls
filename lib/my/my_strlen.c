/*
** ETNA PROJECT, 29/09/2020 by rechau_l
** my_strlen
** File description:
**      C day 2 step 2
*/

#include <unistd.h>

int my_strlen(const char *s)
{
    const char *str;

    str = s;
    if (!s)
        return (0);
    while (*str)
        str++;
    return (str-s);
}
