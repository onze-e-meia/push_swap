# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 16:03:51 by tforster          #+#    #+#              #
#    Updated: 2024/04/12 18:32:25 by tforster         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GRN = \033[0;32m
YLW = \033[0;33m
BLU = \033[0;34m
MAG = \033[0;35m
CYA = \033[0;36m
WHT = \033[0;37m
RST = \033[0m

NAME	=	libft.a

SRC		=	\
	ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c  ft_isprint.c \
	ft_is_tab.c \
	ft_itoa.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c\
	ft_tolower.c ft_toupper.c

BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

OBJDIR	=	obj
OBJ		=	${SRC:%.c=$(OBJDIR)/%.o}
OBJ_BNS	=	$(SRC_BONUS:%.c=$(OBJDIR)/%.o)

CC = cc
CFLGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ += $(OBJ_BNS)
endif

all: $(NAME)

$(NAME): $(OBJ)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLGS) $(INCLS) -c $< -o $@
	@echo "${GRN}LIBFT => Object $@ DONE${RST}"
	ar rc $(NAME) $@
	@echo "${YLW}LIBFT => Object $@ ADDED to $(NAME) ${RST}"

bonus:
	@$(MAKE) WITH_BONUS=TRUE --no-print-directory

clean:
	rm -rf $(OBJDIR)
	@echo "${RED}CLEAN Objects $(OBJ) DELETED${RST}"

fclean: clean
	rm -rf $(NAME)
	@echo "${RED}FCLEAN Objects $(NAME) DELETED${RST}"

re: fclean all

.PHONY: all bonus clean fclean re
