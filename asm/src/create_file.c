/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** create_file
*/

#include <stdio.h>

#include <fcntl.h>
#include <unistd.h>

#include "corewar/corewar.h"
#include "corewar/op.h"
#include "my_str.h"

str_t *convert_file(char const *filepath)
{
    str_t *new_file = str_create(filepath);
    const str_t *original = str_create(".s");
    const str_t *final = str_create(".cor");

    str_replace(&new_file, original, final);
    return new_file;
}

void write_file(header_t *header, char const *filepath)
{
    str_t *new_file = convert_file(filepath);
    int fd = open(new_file->data, O_CREAT | O_WRONLY);

    if (fd == -1){
        write(2, "Error: Can't open file\n", 24);
        return;
    } else {
        write(fd, header, sizeof(header_t));
    }
    close(fd);
}
