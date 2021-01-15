/*
** ETNA PROJECT, 30/09/2020 by rechau_l
** my_strstr
** File description:
**      finds needle substring in haystack string
*/

int my_strlen(const char *s)
{
    const char *str;

    str = s;
    if (!s)
        return (0);
    while (*str)
        str++;
    return (str-s);
}

char *my_strstr(char *str, const char *to_find)
{
    int i = 0;
    int j = 0;
    int str_len = my_strlen(str);
    int to_find_len = my_strlen(to_find);

    if (to_find_len == 0)
        return (str);
    if (to_find_len > str_len)
        return (0);
    while (str[i]) {
        j = 0;
        while (str[i + j] == to_find[j]) {
            if (to_find[j + 1] == '\0')
                return (str + i);
            j++;
        }
        i++;
    }
    return (0);
}
