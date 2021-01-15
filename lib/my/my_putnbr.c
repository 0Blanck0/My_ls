/*
** ETNA PROJECT, 29/09/2020 by rechau_l
** my_putnbr
** File description:
**      day 1 step 8
*/

void my_putchar(char c);

void my_putnbr(int n)
{
    unsigned int nb;

    nb = n;
    if (n < 0) {
        nb = -n;
        my_putchar('-');
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
    else {
        my_putchar (nb + 48);
    }
}
