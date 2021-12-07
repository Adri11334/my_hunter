/*
** EPITECH PROJECT, 2021
** myls
** File description:
** print of a certain color
*/

void my_printf(char *str, ...);

void write_white(char *str)
{
    my_printf("\033[0;37m%s\033[0;37m", str);
}

void write_blue(char *str)
{
    my_printf("\033[34m%s\033[0;37m", str);
}

void write_green(char *str)
{
    my_printf("\033[32m%s\033[0;37m", str);
}