# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 14:23:38 by tforster          #+#    #+#              #
#    Updated: 2024/05/02 20:19:22 by tforster         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		=	\033[0;31m
GRN		=	\033[0;32m
YLW		=	\033[0;33m
BLU		=	\033[0;34m
MAG		=	\033[0;35m
CYA		=	\033[0;36m
WHT		=	\033[0;37m
RST		=	\033[0m

NAME	=	push_swap

FILES	=	\
	push_swap.c error.c \
	doubly_linked.c doubly_utils.c \
	sort.c quick_sort.c quick_utils.c quick_utils_b.c \
	mov_swap.c mov_rotate.c mov_push.c \


SRCDIR	=	src
SRC		=	$(FILES:%.c=$(SRCDIR)%.o)

OBJDIR	=	obj
OBJ		=	${FILES:%.c=$(OBJDIR)/%.o}

CC		=	cc -g3
CFLGS	=	-Wextra -Wall -Werror

LIBFT	=	./libs/libft

INCLUDE	=	-I ./include -I $(LIBFT)
LIBS	=	$(LIBFT)/libft.a

all: $(NAME)

$(NAME): $(LIBS) $(OBJ)
	$(CC) $(CFLGS) $(OBJ) $(LIBS) $(INCLUDE) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLGS) $(INCLUDE) -c $< -o $@
	@echo "${GRN}Compile $@ DONE${RST}"

$(LIBS):
	@make -C $(LIBFT)
	# @make -C $(PF_PF)

clean:
	@rm -rf $(OBJDIR)
	@echo "${RED}CLEAN:	Objects $(OBJ) DELETED${RST}"

fclean: clean
	@make fclean -sC $(LIBFT)
	@echo "${RED}CLEAN:	Lib $(LIBFT) DELETED${RST}"
	@rm -rf $(NAME)
	@echo "${RED}FCLEAN $(NAME) DELETED${RST}"

re: clean all

.PHONY: all, clean, fclean, re
