# LIB NAME
NAME := libft.a

# SYSTEM COMPILER
CC := cc

# ARCHIVER
AR := ar

# .c FILES
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
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \


# .o FILES
OBJ := $(FT_FILES:%.c=%.o)

# BONUS .c FILES
FT_BONUS = \
ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c\
ft_lstmap_bonus.c

# BONUS .o FILES
OBJ_BONUS := $(FT_BONUS:%.c=%.o)

# FLAGS
CC_FLAGS := -Wall -Wextra -Werror

AR_FLAGS := -csr

# TARGETS
all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(AR_FLAGS) $(NAME) $?

%.o: %.c
	$(CC) $(CC_FLAGS) -c -o $@ $<

clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean 
	rm -f $(NAME)

re : fclean all

bonus : $(OBJ_BONUS)
	$(AR) $(AR_FLAGS) $(NAME) $(NAME_BONUS) $?

# NO FILE TARGETS
.PHONY: all clean fclean re bonus