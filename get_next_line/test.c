#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    // Abrir el archivo "1char.txt"
    fd = open("1char.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return (1);
    }

    // Leer y mostrar la línea
    line = get_next_line(fd);
    if (line)
    {
        printf("Línea leída: %s\n", line);
        free(line);
    }
    else
    {
        printf("No se leyó ninguna línea\n");
    }

    // Cerrar el archivo
    close(fd);
    return (0);
}
