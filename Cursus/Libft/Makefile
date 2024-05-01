# Nombre librería
NAME := libft.a

# Compilador
CC := cc

# Creación librería
AR := ar

# Archivos .c necesarios
FT_FILES := ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c

# Archivos objeto
#OBJ := $(patsubst %.c,%.o,$(FT_FILES))
OBJ := $(FT_FILES:%.c=%.o)

# Flags compilador
CC_FLAGS := -Wall -Wextra -Werror

# Flags librería
AR_FLAGS := -csr

# Archivo include solamente para TEST
INCLUDES := libft.h

# Creación librería
all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(AR_FLAGS) $(NAME) $?

# Creación archivos objeto 
%.o: %.c
	$(CC) $(CC_FLAGS) -c -o $@ $<

# Clean
clean :
	rm -f $(OBJ)

# FClean
fclean : clean 
	rm -f $(NAME)

# FClean y rehacer todo
re : fclean all

# Test con main.c
test : all
	$(CC) $(CC_FLAGS) -I $(INCLUDES) -o $@ main.c $(NAME)

# Targets sin archivo
.PHONY: all clean fclean re test
