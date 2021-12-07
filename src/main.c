/*
** EPITECH PROJECT, 2021
** my hunter
** File description:
** main file
*/

#include "my_hunter.h"

elements_t *request_game_elements()
{
    int elements = 15;
    char **objects = malloc(sizeof(char*) * elements);

    for (int i = 0; i < elements; i++) {
        objects[i] = malloc(sizeof(char) * 34);
        objects[i] = "resource/image/cat.png%normal_cat\0";
    }
    return set_elements(objects, elements);
}

int display_help()
{
    my_printf("\x1B[34mUSAGE\x1B[0m\n\t./nyan_invader\n");
    my_printf("\x1B[34mDESCRIPTION\x1B[0m\n");
    my_printf("\tThis program is a litle game where the goal is to ");
    my_printf("\x1B[31mkill the most of cat as possible.\x1B[0m\n");
    my_printf("\tYou only have 3 life (chance to");
    my_printf(" don't hit a cat).\n");
    my_printf("\tYou will be able to shoot with a single click on your mouse");
    my_printf("\n\n\x1B[35mHave fun !!\x1B[0m\n");
    return 0;
}

int main(int argc, char **argv, char **env)
{
    if (env == NULL)
        return 84;
    int width = (argc == 3) ? my_getnbr(argv[1]) : 1480;
    int height = (argc == 3) ? my_getnbr(argv[2]) : 1000;
    if (argc > 1)
        if (my_strcmp(argv[1], "-h") == 0)
            return display_help();

    elements_t *game_objects = request_game_elements();
    set_window(width, height, game_objects);
    return 0;
}
