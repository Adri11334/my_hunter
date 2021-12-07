/*
** EPITECH PROJECT, 2021
** hunter
** File description:
** test.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_hunter.h"

Test(test_cat_die, test_cat_die)
{
    element_t cat;
    cat.pos.x = 350;
    cat.pos.y = 670;

    cr_assert_eq(cat_die(&cat), 0);
}
