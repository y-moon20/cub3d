# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/11 10:11:19 by yomoon            #+#    #+#              #
#    Updated: 2021/02/19 18:20:10 by yomoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I.
NAME		=	libft.a
SRCS		=	ft_strchr.c ft_atoi.c ft_strdup.c ft_bzero.c ft_strjoin.c ft_calloc.c ft_strlcat.c \
				ft_isalnum.c ft_memccpy.c ft_strlcpy.c ft_isalpha.c ft_memchr.c ft_strlen.c ft_isascii.c \
				ft_memcmp.c ft_strmapi.c ft_isdigit.c ft_memcpy.c ft_strncmp.c ft_isprint.c ft_memmove.c \
				ft_strnstr.c ft_itoa.c ft_memset.c ft_strrchr.c ft_putchar_err.c ft_strtrim.c ft_split.c \
				ft_substr.c ft_tolower.c ft_putstr_err.c ft_toupper.c ft_strndup.c \
				ft_lstnew.c ft_lstlast.c ft_lstsize.c ft_lstmap.c ft_lstiter.c ft_lstadd_back.c \
				ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c
OBJS		=	$(SRCS:.c=.o)
AR			=	ar
ARFLAGS		=	-rcs

.c.o : $(SRCS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all : $(NAME)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
