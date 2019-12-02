# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmousset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 15:35:26 by jmousset          #+#    #+#              #
#    Updated: 2019/12/02 13:23:04 by jmousset         ###   ########.fr        #
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
	   floor_and_ceiling.c\
	   draw.c\
	   controls.c\
	   controls_2.c\
	   misc.c\
	   text_gui.c\
	   gui.c\
	   menu.c\
	   mouse.c\
	   minimap.c\
	   load_textures.c\
	   load_sprites.c\
	   draw_sky.c\
	   sprites.c\

OBJ_DIR = ./obj

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

OBJ = $(addprefix $(OBJ_DIR)/,$(OBJS))

DEP = $(addprefix $(OBJ_DIR)/,$(DEPS))

all: $(NAME)

$(NAME): $(LIB) $(OBJ) Makefile $(HDR)
	@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB) -L $(MLX_PATH) $(MLX_FLAGS)
	@echo "$(YELLOW)./$(NAME)  $(GREEN)ready   ✅ "

-include $(DEP)

$(OBJ_DIR)/%.o : ./%.c Makefile $(HDR)
	@gcc $(FLAGS) -I $(LIB_PATH) -MMD -MP -c $< -o $@

$(LIB) : force
	@make -C $(LIB_PATH)

force :

clean:
	@rm -f $(OBJ)
	@echo "$(YELLOW).o        $(RED)deleted 💯 "
	@rm -f $(DEP)
	@echo "$(YELLOW).d        $(RED)deleted 💯 "
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "$(YELLOW)./$(NAME)  $(RED)deleted 💯 "

re: fclean all

.SILENT:

.PHONY: all clean fclean re
