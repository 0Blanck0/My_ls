/*
** ETNA PROJECT, 30/09/2020 by rechau_l
** my_strcpy
** File description:
**      copies a string to dest
*/

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return (dest);
}
