# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 14:43:16 by mkhoza            #+#    #+#              #
#    Updated: 2019/07/23 10:07:21 by mkhoza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
NAME_LINK = libft_malloc.so

PATH_SRC = ./src/

PATH_INC = ./inc

# PATH_INC_LIBFT = ./libft/includes/

# INCLUDES = -I $(PATH_INC) -I $(PATH_INC_LIBFT)
INCLUDES = -I $(PATH_INC)

CC = cc

ifeq ($(DEBUG),yes)
	CFLAGS = $(INCLUDES) -g -fPIC
	LDFLAGS = -shared
else
	CFLAGS = -Wall -Wextra -Werror $(INCLUDES) -fPIC
	LDFLAGS = -shared
endif

# LIBS = -L libft/ -lft

SRC = malloc.c \
	realloc.c \
	free.c \
	block_initialisation.c \
	block_creation.c \
	zone_initialisation.c \
	zone_creation.c \
	zone_deletion.c \
	show_alloc_mem.c \
	ft_puthexa.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_putchar.c \
	ft_memset.c \
	ft_bzero.c \
	calloc.c \
	reallocf.c


OBJ = $(addprefix $(PATH_SRC), $(SRC:.c=.o))

.PHONY: clean fclean re test

all: $(NAME)

$(NAME): $(OBJ)
	# make -C libft/
	# $(CC) $(OBJ) -o $(NAME) $(LIBS) $(LDFLAGS)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
	ln -s $(NAME) $(NAME_LINK)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_LINK)

re: fclean all
