/*
** ETNA PROJECT, 12/01/2021 by rechau_l and elisab_a
** my_ls
** File description:
**      [...]
*/

#include "../include/my.h"

int get_nb_dir(int argc, char **argv)
{
    int dir_count = 0;

    for (int i = 1; i < argc; i++) {
        struct stat st;
        if (stat(argv[i], &st) != 0) 
          continue;
        if (S_ISDIR(st.st_mode))
            dir_count += 1;
    }

    return(dir_count);
}

void my_ls_no_dir(int *flags_tab)
{
    char buff[PATH_MAX];

    linked_list_t *list;
    getcwd(buff, sizeof(buff));

    if (flags_tab[3] == 1) {
        my_putstr(".\n");
    } else {
        list = my_create_list(buff);
        flags_tab[2] ? my_reverse_sort(list) : my_sort(list);
        my_display_l (list, flags_tab);
    }
}

int main(int argc, char **argv)
{
    int *flags_tab;
    linked_list_t *list;
    int cpt = 1;
    struct stat st;
    int nb_dir = get_nb_dir(argc, argv);
    flags_tab = my_get_flags(argv); 

    if (nb_dir == 0)
        my_ls_no_dir(flags_tab);
    else {
        while (argv[cpt]) { 
            if (argv[cpt][0] != '-'){
                if (flags_tab[3] == 1) {
                    my_putstr(argv[cpt]);
                    my_putchar('\n');
                } else {
                    stat(argv[cpt],&st);
                    list = my_create_list(argv[cpt]);
                    flags_tab[2] ? my_reverse_sort(list) : my_sort(list);
                    my_display_l (list, flags_tab);
                } 
            }

            cpt++;
        }
    }

    return (0);
}