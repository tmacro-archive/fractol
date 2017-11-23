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

NAME   = libmcrlx.a
CC     = gcc
CFLAGS = -Wall -Werror -g -fsanitize=address
ECHO   = @/bin/echo 
OBJDIR = build
SRCDIR = src
INC    = -I include -I ../minilibx -I ../libft/includes/

.PHONY = all clean fclean re

FILES += $(wildcard $(SRCDIR)/*.c)

OBJ = $(FILES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
SRC = $(FILES)

all: $(NAME)

$(OBJ): | build

build:
	@mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(ECHO) -n ":: :: Building libmcrlx..."
	@ar rcs $(NAME) $(OBJ)
	$(ECHO) "Done"

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	

re: fclean $(NAME)

