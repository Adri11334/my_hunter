/*
** EPITECH PROJECT, 2021
** lib
** File description:
** reandom int gen (4 december 2021)
*/

#include <stdlib.h>

float random_number(float min, float max)
{
    float scale = rand() / (float) RAND_MAX;
    return min + scale * ( max - min );
}
