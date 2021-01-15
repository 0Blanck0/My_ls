/*
** ETNA PROJECT, 30/09/2020 by rechau_l
** my_strcat
** File description:
**      concatenate 2 strings
*/

int my_strlen(const char *s)
{
    const char *str;

    str = s;
    while (*str)
        str++;
    return (str - s);
}

char *my_strncat(char *dest, const char *src, int n)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0' && i < n){
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (dest);
}
