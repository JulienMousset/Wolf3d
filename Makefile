# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmousset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 15:35:26 by jmousset          #+#    #+#              #
#    Updated: 2019/11/14 18:15:52 by pasosa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIB_PATH = ./libft/

LIB = ./libft/libft.a

MLX_PATH = ./minilibx/

HDR = wolf3d.h\
	  colors.h\
	  controls.h

SRCS = main.c\
	   wolf3d.c\
	   parsing.c\
	   parsing_2.c\
	   ray_casting.c\
	   draw.c\
	   controls.c\
	   misc.c\
	   menu.c\
	   get_time.c\
	   mouse.c\
	   place_player.c\
	   minimap.c \
	   load_textures.c \
	   draw_sky.c

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(LIB) $(OBJS) Makefile $(HDR)
	@gcc $(FLAGS) $(OBJS) -o $(NAME) $(LIB) -L $(MLX_PATH) $(MLX_FLAGS)
	@echo "$(YELLOW)./$(NAME)  $(GREEN)ready   ✅ "

-include $(DEPS)

./%.o : ./%.c Makefile $(HDR)
	@gcc $(FLAGS) -I $(LIB_PATH) -MMD -MP -c $< -o $@

$(LIB) : force
	@make -C $(LIB_PATH)

force :

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW).o        $(RED)deleted 💯 "
	@rm -f $(DEPS)
	@echo "$(YELLOW).d        $(RED)deleted 💯 "
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "$(YELLOW)./$(NAME)  $(RED)deleted 💯 "

re: fclean all

.SILENT:

.PHONY: all clean fclean re
