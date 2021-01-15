/*
** ETNA PROJECT, 12/01/2021 by rechau_l and elisab_a
** my_ls
** File description:
**      [...]
*/

#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char *my_get_permissions(struct stat my_stats)
{
	int perm = get_file_permissions(my_stats);
	int owner = perm/100;
    int user = perm/10 - (owner*10);
    int other = perm - ((perm/10)*10);
	char *ret = (char *)malloc(sizeof(char) * 10);
	int i = 0;

	while (i < 10) {
		ret[i] = 0;
		i++;
	}

	ret[0] = is_directory(my_stats) ? 'd' : '-';
	ret = my_strcat(ret, convert_decimal_to_perm(owner));
	ret = my_strcat(ret, convert_decimal_to_perm(user));
	ret = my_strcat(ret, convert_decimal_to_perm(other));
  	ret[10] = '\0';
	
    return (ret);
}

linked_list_t *get_file_data(struct dirent *my_file, linked_list_t *list)
{
	linked_list_t *elem = malloc(sizeof(linked_list_t));
	struct stat my_stats;
    struct tm *time = { 0 };
    char buf[512];

	stat(my_file->d_name ,&my_stats);
	elem->name = my_strdup(my_file->d_name);

	time = localtime(&my_stats.st_ctime);
	strftime(buf, MAX_SIZE, "%b %d %H:%M", time);
	elem->creation_time = my_strdup(buf);

	strftime(buf, MAX_SIZE, "%y/%m/%d/%H:%M:%S", time);
	elem->edit_timestamp = my_strdup(buf);

	time = localtime(&my_stats.st_ctime);
	strftime(buf, MAX_SIZE, "%b %d %H:%M", time);
	elem->modification_time = my_strdup(buf);

	elem->permissions = my_get_permissions(my_stats);
	elem->nb_links = my_stats.st_nlink;
	elem->size = my_stats.st_size;
	elem->owner = convert_uid_to_user(my_stats);
	elem->group = convert_uid_to_group(my_stats);
	elem->next = list;

	return (elem);
}

linked_list_t *my_create_list(char *path)
{
	linked_list_t *list = malloc(sizeof(linked_list_t));
	DIR *my_dir = opendir(path);
	struct dirent *my_file;

    while ((my_file = readdir(my_dir)) != NULL) {
    	list = get_file_data(my_file, list);
    }

	return (list);
}