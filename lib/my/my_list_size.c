/*
** ETNA PROJECT, 08/10/2020 by elisab_a
** my_list_size.c
** File description:
**      [...]
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

int my_list_size(const linked_list_t *list)
{
    int i = 0;
    const linked_list_t *list2 = list;
    
    while(list2 != NULL){
        i++;
        list2 = list2->next;
    }

    return i;
}
