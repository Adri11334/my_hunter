/*
** EPITECH PROJECT, 2021
** my hunter
** File description:
** utils functions
*/

#include "my_hunter.h"

element_t *get_object(elements_t *objects, char *name)
{
    elements_t *temp_current = malloc(sizeof(elements_t));
    temp_current = objects;
    while (temp_current->next != NULL) {
        if (temp_current->obj->name == name)
            return temp_current->obj;
        temp_current = temp_current->next;
    }
    return temp_current->obj;
}

char **string_division(char *str, char key, int *array_length)
{
    int str_len = 0;
    int letter_index = 0;
    char **words_array = malloc(sizeof(char*) * 2);

    *array_length = 0;
    while (str[str_len] != '\0')
        ++str_len;
    words_array[*array_length] = malloc(sizeof(char) * str_len);
    for (int i = 0; i < str_len; i++) {
        if (str[i] != key) {
            words_array[*array_length][letter_index] = str[i];
            letter_index++;
        } else {
            words_array[*array_length][letter_index] = '\0';
            letter_index = 0;
            (*array_length)++;
            words_array[*array_length] = malloc(sizeof(char) * str_len);
        }
    }
    return words_array;
}
