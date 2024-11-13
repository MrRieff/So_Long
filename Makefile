# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 13:18:07 by lualbuqu          #+#    #+#              #
#    Updated: 2024/10/16 19:09:19 by lualbuqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME = so_long

# Source Directory
SRC_DIR = src/
PARSER_DIR = $(SRC_DIR)parser/
WINDOW_DIR = $(SRC_DIR)display/
UTILS_DIR = $(SRC_DIR)utils/
ERROR_DIR = $(SRC_DIR)error/
ANIMATION_DIR = $(SRC_DIR)animations/

# Object Directories
OBJ_DIR = objs/
LIBFT_OBJ_DIR = $(OBJ_DIR)libft/
MINILIBX_OBJ_DIR = $(OBJ_DIR)minilibx/

# Libraries
LIB_DIR = libraries/
LIBFT_DIR = $(LIB_DIR)libft/
MINILIBX_DIR = $(LIB_DIR)minilibx/

# Paths
MAIN_DIR = 		$(SRC_DIR)so_long.c

PARSER = 		$(PARSER_DIR)check_map.c\
				$(PARSER_DIR)check_rules.c\
				$(PARSER_DIR)utils_parser.c

WINDOW = 		$(WINDOW_DIR)draw_image.c\
				$(WINDOW_DIR)moves_on_screen.c\
				$(WINDOW_DIR)display.c\
			    $(WINDOW_DIR)hooks.c

ERROR = 		$(ERROR_DIR)errors.c\
				$(ERROR_DIR)free_sprites.c

ANIMATION =		$(ANIMATION_DIR)collectible.c\
				$(ANIMATION_DIR)player.c\
				$(ANIMATION_DIR)utils.c

# Sources (files to add)
SRCS = $(MAIN_DIR) $(PARSER) $(WINDOW) $(ERROR) $(ANIMATION)
OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Compilation flags - -g para gdb (se tiver argumentos "set args $argumento", run para correr)
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

# Link libraries
LINK = -L$(MINILIBX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lm -lXext -lX11

# Remove files
RM = rm -f
RM_F = rm -rf

# Colors for terminal output
RESET = \033[0m
BOLD = \033[1m
YELLOW = \033[33m
RED = \033[31m
GREEN = \033[32m
CYAN = \033[36m

# Create executable from object files and link with libft and minilibx
$(NAME): $(OBJS) $(LIBFT_DIR)libft.a $(MINILIBX_DIR)libmlx.a
	@echo "$(BOLD)$(YELLOW)LINKING OBJECTS...$(RESET)\n"
	@$(CC) $(OBJS) $(LINK) -o $(NAME) || { echo "$(BOLD)$(RED)ERROR: LINKING FAILED$(RESET)"; exit 1; }
	@echo "$(BOLD)$(GREEN)$(NAME) CREATED SUCCESSFULLY$(RESET)\n"

# Command to build all components
all: $(LIBFT_DIR)libft.a $(MINILIBX_DIR)libmlx.a $(NAME)

# Compile individual object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(BOLD)$(YELLOW)COMPILING $<...$(RESET)\n"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Ensure libraries are compiled before building the main program
$(LIBFT_DIR)libft.a:
	@make -C $(LIBFT_DIR) || { echo "$(BOLD)$(RED)ERROR: LIBFT COMPILATION FAILED$(RESET)"; exit 1; }

$(MINILIBX_DIR)libmlx.a:
	@make -C $(MINILIBX_DIR) || { echo "$(BOLD)$(RED)ERROR: MINILIBX COMPILATION FAILED$(RESET)"; exit 1; }

clean:
	@echo "$(BOLD)$(YELLOW)CLEANING OBJECTS...$(RESET)\n"
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean || { echo "$(BOLD)$(RED)ERROR: LIBFT CLEAN FAILED$(RESET)"; exit 1; }
	@make -C $(MINILIBX_DIR) clean || { echo "$(BOLD)$(RED)ERROR: MINILIBX CLEAN FAILED$(RESET)"; exit 1; }
	@echo "$(BOLD)$(CYAN)CLEANED OBJECT FILES$(RESET)\n"

fclean: clean
	@echo "$(BOLD)$(YELLOW)CLEANING ALL FILES...$(RESET)\n"
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean || { echo "$(BOLD)$(RED)ERROR: LIBFT FCLEAN FAILED$(RESET)"; exit 1; }
	@make -C $(MINILIBX_DIR) clean || { echo "$(BOLD)$(RED)ERROR: MINILIBX FCLEAN FAILED$(RESET)"; exit 1; }
	@$(RM_F) $(OBJ_DIR)*
	@echo "$(BOLD)$(CYAN)CLEANED ALL FILES$(RESET)\n"

re: fclean all

bonus: all

.PHONY: all clean fclean re
