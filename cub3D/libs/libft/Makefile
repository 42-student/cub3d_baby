# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smargine <smargine@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 19:48:23 by smargine          #+#    #+#              #
#    Updated: 2023/09/25 13:37:18 by smargine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
		ft_tolower.c ft_toupper.c get_next_line.c get_next_line_utils.c \
		ft_atof.c

BONUSSRC = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
			ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c 

OBJ = $(SRC:.c=.o)

BONUSOBJ = $(BONUSSRC:.c=.o)

HEADER = libft.h

CC = cc

RM = rm -rf

AR = ar rc

RN = ranlib

CFLAG = -Wall -Wextra -Werror

.c.o:
		$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) $(HEADER)
							$(AR) $(NAME) $(OBJ)
							$(RN) $(NAME)

all: $(NAME) bonus

bonus: $(BONUSOBJ) $(HEADER)
								$(AR) $(NAME) $(BONUSOBJ)
								$(RN) $(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) $(BONUSOBJ)

fclean: clean
				$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
