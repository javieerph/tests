#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("1char.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return (1);
    }

    // Leer línea por línea hasta que get_next_line devuelva NULL
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Línea leída: %s\n", line);
        free(line); // Liberar la memoria después de cada lectura
    }

    close(fd);
    return (0);
}

