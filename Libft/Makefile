# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefille                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 18:45:22 by aahlaqqa          #+#    #+#              #
#    Updated: 2023/11/27 15:13:28 by aahlaqqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = cc
SOURCES =  ft_isalpha.c    ft_memchr.c     ft_putchar_fd.c ft_strchr.c     ft_strlcpy.c    ft_strrchr.c ft_atoi.c       ft_isascii.c    ft_memcmp.c     ft_putendl_fd.c ft_strdup.c     ft_strlen.c     ft_strtrim.c ft_bzero.c      ft_isdigit.c    ft_memcpy.c     ft_putnbr_fd.c  ft_striteri.c   ft_strmapi.c    ft_substr.c ft_calloc.c     ft_isprint.c    ft_memmove.c    ft_putstr_fd.c  ft_strjoin.c    ft_strncmp.c    ft_tolower.c ft_isalnum.c    ft_itoa.c       ft_memset.c     ft_split.c      ft_strlcat.c    ft_strnstr.c    ft_toupper.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJECTS = $(SOURCES:.c=.o)

BONOBJECTS = $(BONUS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS):$(SOURCES)
	$(CC)  $(CFLAGS) -c $(SOURCES)


bonus: $(BONOBJECTS)

$(BONOBJECTS): $(BONUS)
	$(CC) $(CFLAGS) -c $(BONUS)
	ar rcs $(NAME) $(BONOBJECTS)

clean:
	rm -f $(OBJECTS) $(BONOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
