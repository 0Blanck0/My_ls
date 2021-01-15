/*
** ETNA PROJECT, 12/01/2021 by rechau_l and elisab_a
** my_ls
** File description:
**      [...]
*/

#include "../include/my.h"

char *my_strlowcase_custom(char *str)
{
    int i = 0;
    char *dest = my_strdup(str);

    while (dest[i] != '\0') {
        if (dest[i] >= 'A' && dest[i] <= 'Z')
            dest[i] += 32;
			
        i++;
    }

    return (dest);
}

linked_list_t *my_sort(linked_list_t *list)
{
	linked_list_t *begin = list;
	linked_list_t *current;
	char *tmp1;
	char *tmp2;

	current = list;

	while (current->next->name != NULL) {
		tmp1 = my_strlowcase_custom(current->name);
		tmp2 = my_strlowcase_custom(current->next->name);

		if (my_strcmp(tmp1, tmp2) > 0) {
			my_lst_swap(current, current->next);
			current = begin;
		} else
			current = current->next;
	}

	return (begin);
}

linked_list_t *my_reverse_sort(linked_list_t *list)
{
	linked_list_t *begin = list;
	linked_list_t *current;
	char *tmp1;
	char *tmp2;

	current = list;

	while (current->next->name != NULL) {
		tmp1 = my_strlowcase_custom(current->name);
		tmp2 = my_strlowcase_custom(current->next->name);

		if (my_strcmp(tmp1, tmp2) < 0) {
			my_lst_swap(current, current->next);
			current = begin;
		} else
			current = current->next;
	}
	
	return (begin);
}

linked_list_t *my_sort_time(linked_list_t *list)
{
	linked_list_t *begin = list;
	linked_list_t *current;
	char *tmp1;
	char *tmp2;

	current = list;
	while (current->next->name != NULL) {
		tmp1 = my_strlowcase_custom(current->edit_timestamp);
		tmp2 = my_strlowcase_custom(current->next->edit_timestamp);

		if (my_strcmp(tmp1, tmp2) < 0) {
			my_lst_swap(current, current->next);
			current = begin;
		} else
			current = current->next;
	}

	return (begin);
}
