/*
** ETNA PROJECT, 12/01/2021 by rechau_l and elisab_a
** my_ls
** File description:
**      [...]
*/

#include "../include/my.h"

int decimal_to_octal(int decimalnum)
{
    int octalnum = 0, temp = 1;

    while (decimalnum != 0) {
    	octalnum = octalnum + (decimalnum % 8) * temp;
    	decimalnum = decimalnum / 8;
        temp = temp * 10;
    }

    return octalnum;
}

char* convert_uid_to_user(struct stat stats)
{
    struct passwd *pwd;
    pwd = getpwuid(stats.st_uid);

    if (pwd == NULL) {
        return ("error");
    } else
        return (pwd->pw_name);
}

char* convert_uid_to_group(struct stat stats)
{
    struct group *grp;
    grp = getgrgid(stats.st_gid);

    if (grp == NULL) {
        return ("error");
    } else
        return (grp->gr_name);
}

char* convert_decimal_to_perm(int param)
{
    char *ret = (char *)malloc(sizeof(char) * 4);

    if (param-4 >= 0) {
        ret[0] = 'r';
        param-=4;
    } else
        ret[0] = '-';
    if (param-2 >= 0) {
        ret[1] = 'w';
        param-=2;
    } else
        ret[1] = '-';
    if (param-1 >= 0)
        ret[2] = 'x';
    else
        ret[2] = '-';
    ret[3] = '\0';
    
    return(ret);
}