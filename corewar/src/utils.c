/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** vm utils
*/

#include "corewar/instructions.h"

int swap_endian(int val)
{
    return (
        (val & 0x000000ff) << 24 | (val & 0x0000ff00) << 8 |
        (val & 0x00ff0000) >> 8 | (val & 0xff000000) >> 24
    );
}

u_char get_bits(u_char byte, int start, int count)
{
    return ((1 << count) - 1) & (byte >> start);
}
