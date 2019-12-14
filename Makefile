# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmousset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 15:35:26 by jmousset          #+#    #+#              #
#    Updated: 2019/12/14 18:38:31 by jmousset         ###   ########.fr        #
#    Updated: 2019/12/12 20:01:25 by jmousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

MLX_PATH = ./minilibx/
LIB_PATH = ./libft/
LIB = ./libft/libft.a

HDR_PATH = ./inc
HDR_NAME = *.h
HDR = $(addprefix $(HDR_PATH)/,$(HDR_NAME))

SRC_PATH = ./src
SRC_NAME = main.c\
		   wolf3d.c\
		   set_values.c\
		   parsing.c\
		   parsing_2.c\
		   ray_casting.c\
		   draw.c\
		   floor_and_ceiling.c\
		   controls.c\
		   controls_2.c\
		   misc.c\
		   misc2.c\
		   text_gui.c\
		   gui.c\
		   menu.c\
		   mouse.c\
		   minimap.c\
		   compass.c\
		   load_textures.c\
		   load_sprites.c\
		   draw_sky.c\
		   sprites.c\
		   create_threads.c\
		   items.c\
		   items2.c\
		   gain_item.c\
		   end_game.c
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = ./obj
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
DEP_NAME = $(SRC_NAME:.c=.d)

all: mkdir $(NAME)

mkdir:
	@mkdir -p $(OBJ_PATH)

$(NAME): $(LIB) $(OBJ) Makefile $(HDR)
	@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB) -L $(MLX_PATH) $(MLX_FLAGS)
	@echo "$(YELLOW)./$(NAME)  $(GREEN)ready   ✅ $(RESET)"

-include $(DEP)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c Makefile $(HDR)
	@gcc $(FLAGS) -I $(LIB_PATH) -MMD -MP -c $< -o $@

$(LIB) : force
	@make -C $(LIB_PATH)

force :

clean:
	@rm -f $(OBJ)
	@echo "$(YELLOW).o        $(RED)deleted 💯 $(RESET)"
	@rm -f $(DEP)
	@echo "$(YELLOW).d        $(RED)deleted 💯 $(RESET)"
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "$(YELLOW)./$(NAME)  $(RED)deleted 💯 $(RESET)"

re: fclean all

.SILENT:

.PHONY: all mkdir force clean fclean re
