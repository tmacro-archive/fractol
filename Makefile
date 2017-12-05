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

NAME	= fractol
CC		= gcc
CFLAGS	= -Wall -Werror -g #-fsanitize=address
OBJDIR	= build
SRCDIR	= src
INC		= -I./include/ -I./mcrlx/include/ -I./libft/includes/ -I./minilibx/
LIB		= -L./mcrlx/ -lmcrlx -L./libft/ -lft -L./minilibx -lmlx
MODULES	= libft minilibx mcrlx

.PHONY = all clean fclean re deps

FILES += $(wildcard $(SRCDIR)/*.c)

OBJ = $(FILES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
SRC = $(FILES)

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

$(NAME): deps $(OBJ)
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