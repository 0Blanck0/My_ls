/*
** ETNA PROJECT, 12/01/2021 by rechau_l and elisab_a
** my_ls
** File description:
**      [...]
*/

#include "../include/my.h"

void my_display_no_flags (linked_list_t *list)
{
	linked_list_t *elem = list;

	while (elem->next) {
		if (elem->name[0] != '.') {
			my_putstr(elem->name);
			my_putstr("\n");
		}
		elem = elem->next;
	}
}

void l_flag_check(linked_list_t *elem, int *flag_tab) 
{
	if (flag_tab[0] == 1) {
		my_putstr(elem->permissions);
		my_putstr(" ");
		my_putnbr(elem->nb_links);
		my_putstr(" ");
		my_putstr(elem->owner);
		my_putstr(" ");
		my_putstr(elem->group);
		my_putstr(" ");
		my_putnbr(elem->size);
		my_putstr(" ");
		my_putstr(elem->creation_time);
		my_putstr(" ");
	}
}

void my_display_l (linked_list_t *list, int *flag_tab)
{
	linked_list_t *elem = list;

	while (elem->next) {
		if ((elem->name[0] != '.' || flag_tab[5] == 1) && flag_tab[6] != 1) {
			l_flag_check(elem, flag_tab);
			my_putstr(elem->name);
			my_putstr("\n");
		} else if (flag_tab[6] == 1 && elem->name[1] != '.' && my_strcmp(elem->name, ".") > 0) {
			l_flag_check(elem, flag_tab);
			my_putstr(elem->name);
			my_putstr("\n");
		}
		elem = elem->next;
	}
}
