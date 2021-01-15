/*
** ETNA PROJECT, 12/01/2021 by rechau_l and elisab_a
** my_ls
** File description:
**      [...]
*/

#include "../include/my.h"

int my_get_nb_flags(char **argv)
{
    int i = 1;
    int ret = 0;

    while (argv[i]) {
        if (argv[i][0] == '-')
            ret++;
        i++;
    }
    
    return (ret);
}

int *fill_flag_tab(char **flags, int *flag_tab, int i)
{
    if (my_strchr(flags[i], 'l'))
        flag_tab[0] = 1;
    if (my_strchr(flags[i], 'R'))
        flag_tab[1] = 1;
    if (my_strchr(flags[i], 'r'))
        flag_tab[2] = 1;
    if (my_strchr(flags[i], 'd'))
        flag_tab[3] = 1;
    if (my_strchr(flags[i], 't'))
        flag_tab[4] = 1;
    if (my_strchr(flags[i], 'a'))
        flag_tab[5] = 1;
    if (my_strchr(flags[i], 'A'))
        flag_tab[6] = 1;
    if (my_strchr(flags[i], 'L'))
        flag_tab[7] = 1;

    return (flag_tab);
}

int *my_get_flags(char **flags)
{
    int *flag_tab = (int *)malloc(sizeof(int) * 8);
    int i = 0;
    int nb_flags_slots = my_get_nb_flags(flags);

    while (flag_tab[i]) {
        flag_tab[i] = 0;
        i++;
    }

    i = 1;

    while (nb_flags_slots) {
        if (flags[i][0] == '-') {
            fill_flag_tab(flags, flag_tab, i);
            nb_flags_slots--;
        }
        i++;
    }

    return (flag_tab);
}