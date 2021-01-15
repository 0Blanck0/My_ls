/*
** ETNA PROJECT, 12/01/2021 by rechau_l and elisab_a
** my.h
** File description:
**      headers for my_ls
*/

#ifndef MY_H_

#define MY_H_
#define MAX_SIZE 80
#define PATH_MAX 256

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>


typedef struct linked_list {
    char *name;
    char *creation_time;
    char *modification_time;
    char *edit_timestamp;
    char *permissions;
    char type;
    int nb_links;
    int nb_sym_links;
    char *owner;
    char *group;
    int size;
    struct linked_list *next;
}       linked_list_t;


// Lib functions
void my_putchar(char c);
void my_putstr(const char *str);
int my_strlen(const char *str);
int my_getnbr(const char *str);
void my_putnbr(int nb);
void my_isneg(int nb);
void my_swap(int *a, int *b);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, int n);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, int n);
char *my_strcat(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, int nb);
char *my_strstr(char *str, const char *to_find);
char *my_strdup(const char *src);
char **my_str_to_word_array(const char *str);
char *my_strchr(const char *s, int c);
char *my_readline(void);

// Stats functions
void printFileProperties(struct stat stats);
int is_directory(struct stat stats);
int get_file_permissions(struct stat stats);

// Convert function
int decimal_to_octal(int decimalnum);
char* convert_uid_to_user(struct stat stats);
char* convert_uid_to_group(struct stat stats);
char* convert_decimal_to_perm(int perm);

// Flags function
int *my_get_flags(char **flags);
int my_get_nb_flags(char **argv);


// List functions
linked_list_t *my_create_list(char *path);

// Display functions
void my_display_l (linked_list_t *list, int *flag_tab);
void my_display_no_flags (linked_list_t *list);

// Sort
linked_list_t *my_sort(linked_list_t *list);
linked_list_t *my_reverse_sort(linked_list_t *list);
linked_list_t *my_sort_time(linked_list_t *list);
void my_lst_swap(linked_list_t *a, linked_list_t *b);

#endif