# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yomoon <yomoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 11:21:07 by yomoon            #+#    #+#              #
#    Updated: 2021/02/19 17:51:31 by yomoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

LIBFT		=	./libft/libft.a

CC			=	gcc
INCS		=	-Ilibft -Imlx -Iincludes
INCLIB		=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Llibft -lft
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	srcs/bmp.c srcs/check_map.c srcs/main.c srcs/get_next_line.c srcs/move_player.c\
				srcs/parse.c srcs/parse_cub.c srcs/parse_cub_sub.c srcs/parse_map.c srcs/parse_map_sub.c\
				srcs/raycasting.c srcs/raycasting_sub.c srcs/set_info.c srcs/sprite_raycasting.c\
				srcs/sprite_raycasting_sub.c srcs/start_game.c srcs/texture.c srcs/utils.c
BONUS		=	bonus/bmp.c bonus/check_map.c bonus/main.c bonus/get_next_line.c bonus/move_player.c\
				bonus/parse.c bonus/parse_cub.c bonus/parse_cub_sub.c bonus/parse_map.c bonus/parse_map_sub.c\
				bonus/raycasting.c bonus/raycasting_sub.c bonus/set_info.c bonus/sprite_raycasting.c\
				bonus/sprite_raycasting_sub.c bonus/start_game.c bonus/texture.c bonus/utils.c bonus/floor_raycasting.c
OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS:.c=.o)

.c.o : $(SRCS)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(NAME) : $(OBJS)
	@make -C ./libft/
	@$(CC) $(CFLAGS) $(INCS) $(INCLIB) $(SRCS) -o $@

all : $(NAME)

bonus : $(BONUS_OBJS)
	@make -C ./libft/
	@$(CC) $(CFLAGS) $(INCS) $(INCLIB) $(BONUS) -o $(NAME)

clean :
	@rm -f $(OBJS) $(BONUS_OBJS)
	@make clean -C ./libft/

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re : fclean all

.PHONY : all clean fclean re libft
