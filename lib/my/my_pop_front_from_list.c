/*
** ETNA PROJECT, 08/10/2020 by elisab_a
** my_pop_front_from_list
** File description:
**      [...]
*/

#include <stdlib.h>
#include "../include/my.h"

linked_list_t *my_pop_front_from_list(linked_list_t *list)
{
    list = list->next;
    return list;
}