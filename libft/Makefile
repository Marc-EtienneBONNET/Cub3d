# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 15:47:27 by mbonnet           #+#    #+#              #
#    Updated: 2020/12/09 13:03:13 by mbonnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memset.c		\
	   ft_putstr.c		\
	   ft_bzero.c		\
	   ft_memcpy.c		\
	   ft_memccpy.c		\
	   ft_memmove.c 	\
	   ft_memchr.c		\
	   ft_memcmp.c		\
	   ft_strlen.c		\
	   ft_isalpha.c 	\
	   ft_isdigit.c		\
	   ft_isalnum.c		\
	   ft_isascii.c		\
	   ft_isprint.c		\
	   ft_toupper.c		\
	   ft_tolower.c		\
	   ft_strchr.c		\
	   ft_strrchr.c		\
	   ft_strncmp.c		\
	   ft_strlcpy.c		\
	   ft_strlcat.c		\
	   ft_strnstr.c		\
	   ft_atoi.c		\
	   ft_calloc.c		\
	   ft_strdup.c		\
	   ft_substr.c		\
	   ft_strjoin.c 	\
	   ft_strtrim.c		\
	   ft_split.c		\
	   ft_itoa.c		\
	   ft_strmapi.c		\
	   ft_putchar_fd.c	\
	   ft_putstr_fd.c	\
	   ft_putendl_fd.c	\
	   ft_putnbr_fd.c   \
	   get_next_line.c  \
	   	get_next_line_2.c  \
	   get_next_line_utils.c  \
		ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstmap.c

NAME = libft.a

OBJS = $(SRCS:.c=.o)


CC = clang

CC_FLAGS = -c -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(SRCS) libft.h $(CC_FLAGS)
	ar r $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJSB)
	$(CC) $(SRCS) $(SRCSB) $(CC_FLAGS)
	ar r $(NAME) $(OBJSB)
