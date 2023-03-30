# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 13:54:56 by abeaudet          #+#    #+#              #
#    Updated: 2023/03/29 20:37:42 by abeaudet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

#includes
LIB_PATH = includes/libft
LIBFT = $(LIB_PATH)/libft.a
MLX_PATH = includes/MLX42
MLX = $(MLX_PATH)/libmlx42.a $(MLX_PATH)/lib/lib-x86_64/libglfw3.a
MLX_FLAGS = -framework Cocoa -framework OpenGl -framework IOKit

#source files
S = srcs/
SRCS_FILES = 	parsing.c\
				read.c\
				get_next_line.c\
				get_next_line_utils.c\
				so_long.c\
				controls.c\
				images.c\
				utils.c\
				simulate.c\

SRCS = $(addprefix $S, $(SRCS_FILES))

OBJS = $(SRCS:%.c=%.o)

O = /objs
$O%.o: $S%
	@$(CC) $(CFLAGS) -c $< -o $@

# BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
SFLAGS = -fsanitize=address

all: libinit make_mlx $(NAME)

$(NAME):  $(OBJS)
	@$(CC) -o $@ $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS)
			
libinit: 
		@echo "$R creation de la libft...$W"
		@$(MAKE) -s -C ./includes/libft
		@echo "$G libft created!$W"

COMMIT = $(shell date "+%d %B %T")
git:
	@git add .
	@git commit -m "$(COMMIT)"
	@git push

make_mlx: 
		@echo "$R Creating minilibx...$W"
		@$(MAKE) -s -C ./includes/MLX42
		@echo "$G minilibx created!$W"

clean:
	@rm -f $(OBJS)
	@echo "$B Cleaning complete.$W"
	
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./includes/libft
	@$(MAKE) fclean -C ./includes/MLX42
	
re: fclean all

# COLORS
R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
C = $(shell tput -Txterm setaf 6)
W = $(shell tput -Txterm setaf 7)