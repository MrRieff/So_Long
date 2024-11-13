NAME = libft.a

# Object directory
OBJ_DIR = ../../objs/libft/

LIBFT_DIR = libft/
LIBFT_BONUS_DIR = libft_bonus/

PRINTF_DIR = ft_printf/

GNL_DIR = get_next_line/

# Source files (no folder needed)
LIBFT = $(LIBFT_DIR)ft_atoi.c\
				$(LIBFT_DIR)ft_bzero.c\
				$(LIBFT_DIR)ft_calloc.c\
				$(LIBFT_DIR)ft_isalnum.c\
				$(LIBFT_DIR)ft_isalpha.c\
				$(LIBFT_DIR)ft_isascii.c\
				$(LIBFT_DIR)ft_isdigit.c\
				$(LIBFT_DIR)ft_isprint.c\
				$(LIBFT_DIR)ft_itoa.c\
				$(LIBFT_DIR)ft_memchr.c\
				$(LIBFT_DIR)ft_memcmp.c\
				$(LIBFT_DIR)ft_memcpy.c\
				$(LIBFT_DIR)ft_memmove.c\
				$(LIBFT_DIR)ft_memset.c\
				$(LIBFT_DIR)ft_putchar_fd.c\
				$(LIBFT_DIR)ft_putendl_fd.c\
				$(LIBFT_DIR)ft_putnbr_fd.c\
				$(LIBFT_DIR)ft_putstr_fd.c\
				$(LIBFT_DIR)ft_split.c\
				$(LIBFT_DIR)ft_strchr.c\
				$(LIBFT_DIR)ft_strdup.c\
				$(LIBFT_DIR)ft_striteri.c\
				$(LIBFT_DIR)ft_strjoin.c\
				$(LIBFT_DIR)ft_strlcat.c\
				$(LIBFT_DIR)ft_strlcpy.c\
				$(LIBFT_DIR)ft_strlen.c\
				$(LIBFT_DIR)ft_strmapi.c\
				$(LIBFT_DIR)ft_strncmp.c\
				$(LIBFT_DIR)ft_strnstr.c\
				$(LIBFT_DIR)ft_strrchr.c\
				$(LIBFT_DIR)ft_strtrim.c\
				$(LIBFT_DIR)ft_substr.c\
				$(LIBFT_DIR)ft_tolower.c\
				$(LIBFT_DIR)ft_toupper.c

LIBFT_BONUS = $(LIBFT_BONUS_DIR)ft_lstadd_back.c\
							$(LIBFT_BONUS_DIR)ft_lstadd_front.c\
							$(LIBFT_BONUS_DIR)ft_lstclear.c\
							$(LIBFT_BONUS_DIR)ft_lstdelone.c\
							$(LIBFT_BONUS_DIR)ft_lstiter.c\
							$(LIBFT_BONUS_DIR)ft_lstlast.c\
							$(LIBFT_BONUS_DIR)ft_lstmap.c\
							$(LIBFT_BONUS_DIR)ft_lstnew.c\
							$(LIBFT_BONUS_DIR)ft_lstsize.c

GNL = $(GNL_DIR)get_next_line.c\
			$(GNL_DIR)get_next_line_utils.c\

PRINTF = $(PRINTF_DIR)ft_printf.c\
				 $(PRINTF_DIR)ft_printf_utils.c\
				 $(PRINTF_DIR)ft_printf_utils2.c

# Convert source files to object files
LIBFT_OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(LIBFT))
LIBFT_BONUS_OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(LIBFT_BONUS))

GNL_OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(GNL))

PRINTF_OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(PRINTF))

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(GNL_OBJS) $(LIBFT_BONUS_OBJS) $(PRINTF_OBJS)
	@echo "Creating $(NAME) with objects $(LIBFT_OBJS)"
	@echo "Creating $(NAME) with objects $(LIBFT_BONUS_OBJS)"
	@echo "Creating $(NAME) with objects $(GNL_OBJS)"
	@echo "Creating $(NAME) with objects $(PRINTF_OBJS)"
	@$(AR) $(NAME) $(LIBFT_OBJS) $(GNL_OBJS) $(LIBFT_BONUS_OBJS) $(PRINTF_OBJS)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

#bonus: $(NAME) $(LIBFT_BONUS_OBJS)
#	@echo "Creating $(NAME) with bonus objects $(LIBFT_BONUS_OBJS)"
#	@$(AR) $(NAME) $(LIBFT_BONUS_OBJS)

clean:
	@echo "Cleaning object files..."
	@$(RM) $(LIBFT_OBJS) $(LIBFT_BONUS_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)
	@echo "Object files cleaned."

fclean: clean
	@echo "Cleaning library file..."
	@$(RM) $(NAME)
	@echo "Library file cleaned."

re: fclean all

.PHONY: all clean fclean bonus re
