# Nombre del programa
NAME = bsq

# Compilador a utilizar
CC = cc

# Opciones de compilación
CFLAGS = -Wall -Wextra -Werror

# Directorios
SRCDIR = src
OBJDIR = obj
INCDIR = include

# Archivos fuente
FILES = files.c
FT_MAP = ft_map.c
MAIN = main.c
SOLVE = solve.c
UTILS = utils.c

# Lista de archivos objeto
OBJS = $(OBJDIR)/files.o $(OBJDIR)/ft_map.o $(OBJDIR)/main.o $(OBJDIR)/solve.o $(OBJDIR)/utils.o

# Regla por defecto
all: $(NAME)

# Regla para compilar el programa
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regla para compilar los archivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

# Regla para crear el directorio de objetos si no existe
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regla para limpiar los archivos generados
clean:
	rm -rf $(OBJDIR)

# Regla para eliminar el ejecutable y los archivos generados
fclean: clean
	rm -f $(NAME)

# Regla para recompilar el programa
re: fclean all

# Indicar que 'clean', 'fclean', 're' y 'all' no son archivos
.PHONY: clean fclean re all
