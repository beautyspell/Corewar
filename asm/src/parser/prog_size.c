/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** prog_size
*/

#include "my_str.h"

#include "asm/asm.h"
#include "corewar/op.h"

static void find_for_params(vec_str_t *input, size_t i, header_t *header)
{
    for (size_t idx = 1; idx < input->size; idx++){
        if (input->data[idx]->data[0] == 'r'){
            header->prog_size += 1;
        }
        if (input->data[idx]->data[0] != 'r' &&
            input->data[idx]->data[0] != '%'){
            header->prog_size += 2;
        }
        if (input->data[idx]->data[0] != '%' && OP_NAME[i].size != 0){
            header->prog_size += OP_NAME[i].size;
        }
    }
}

void get_prog_size(str_t *champ, header_t *header)
{
    vec_str_t *input = NULL;
    str_t *tmp = NULL;

    input = str_split(champ, STR(", \t"));
    if (str_compare(input->data[0], STR("live")) != 0 &&
        str_compare(input->data[0], STR("lfork")) != 0 &&
        str_compare(input->data[0], STR("fork")) != 0 &&
        str_compare(input->data[0], STR("zjmp")) != 0){
            header->prog_size += 2;
    } else {
        header->prog_size += 1;
    }
    for (size_t i = 0; i < AFF; i++){
        tmp = str_create(OP_NAME[i].name);
        if (str_compare(input->data[0], tmp) == 0)
            find_for_params(input, i, header);
    }
}
