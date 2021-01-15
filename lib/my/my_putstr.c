/*
** ETNA PROJECT, 29/09/2020 by rechau_l
** my_putstr
** File description:
**      step 1 day 2 C
*/

#include <unistd.h>
#include "../../include/my.h"

void my_putstr(const char *str)
{
    write(1, str, my_strlen(str));
}
