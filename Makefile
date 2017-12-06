# **************************************************************************** #ME
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/05 09:30:29 by tmckinno          #+#    #+#              #
#    Updated: 2017/07/15 14:08:29 by tmckinno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
DEBUG	= false

NAME	= fractol
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
ifeq ($(DEBUG), true)
	CFLAGS += -g -fsanitize=address
endif
OBJDIR	= build
SRCDIR	= src
INC		= -I./include/ -I./mcrlx/include/ -I./libft/includes/ -I./minilibx/
LIB		= -L./mcrlx/ -lmcrlx -L./libft/ -lft -L./minilibx -lmlx
MODULES	= libft minilibx mcrlx

.PHONY = all clean fclean re deps

FILES =	args.c \
		burning_ship.c \
		color.c \
		hooks.c \
		init.c \
		julia.c \
		main.c \
		mandelbrot.c \
		util.c

SRC = $(FILES:%.c=$(SRCDIR)/%.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME) 

$(OBJ): | build

build:
	@mkdir -p $@

deps:
	@for mod in $(MODULES); do \
		make -sC $$mod; \
	done

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ) | deps
	@echo "Building $(NAME) with $(CFLAGS)"
	@$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ) -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@for mod in $(MODULES); do \
		make -sC $$mod clean ; \
	done

fclean:
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)
	@for mod in $(MODULES); do \
		make -sC $$mod fclean; \
	done
	@make -sC minilibx clean
re: fclean $(NAME)