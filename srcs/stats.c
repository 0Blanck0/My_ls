/*
** ETNA PROJECT, 12/01/2021 by rechau_l and elisab_a
** my_ls
** File description:
**      [...]
*/

#include "../include/my.h"

/**
 * Function to check id is a directory
 */
int is_directory(struct stat stats)
{
    int perm_int = stats.st_mode;
    int perm_parse = decimal_to_octal(perm_int)/10000;

    if (perm_parse == 4)
        return 1;
    else
        return 0;
}

/**
 * Function to get all permissions for file or directory
 */
int get_file_permissions(struct stat stats)
{
    int perm_int = stats.st_mode;
    perm_int = decimal_to_octal(perm_int);
    int perm_parse = perm_int/10000;
    perm_int = perm_int - (perm_parse*10000);
    return perm_int;
}
