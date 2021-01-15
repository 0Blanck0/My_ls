/*
** ETNA PROJECT, 15/01/2021 by rechau_l and elisab_a
** my_ls
** File description:
**      [...]
*/


#include "../include/my.h"

void my_lst_swap_str(linked_list_t *a, linked_list_t *b)
{
    char *str_tmp;

    str_tmp = a->name;
    a->name = b->name;
    b->name = str_tmp;
    str_tmp = a->creation_time;
    a->creation_time = b->creation_time;
    b->creation_time = str_tmp;
    str_tmp = a->modification_time;
    a->modification_time = b->modification_time;
    b->modification_time = str_tmp;
    str_tmp = a->edit_timestamp;
    a->edit_timestamp = b->edit_timestamp;
    b->edit_timestamp = str_tmp;
    str_tmp = a->permissions;
    a->permissions = b->permissions;
    b->permissions = str_tmp;
}

void my_lst_swap_int(linked_list_t *a, linked_list_t *b)
{
    int int_tmp;

    int_tmp = a->nb_links;
    a->nb_links = b->nb_links;
    b->nb_links = int_tmp;
    int_tmp = a->size;
    a->size = b->size;
    b->size = int_tmp;
}

void my_lst_swap_char(linked_list_t *a, linked_list_t *b)
{
    char char_tmp;

    char_tmp = a->type;
    a->type = b->type;
    b->type = char_tmp;
}

void my_lst_swap(linked_list_t *a, linked_list_t *b)
{
    my_lst_swap_str(a, b);
    my_lst_swap_int(a, b);
    my_lst_swap_char(a, b);
}

