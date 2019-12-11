# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmousset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 15:35:26 by jmousset          #+#    #+#              #
#    Updated: 2019/12/11 22:29:53 by pasosa-s         ###   ########.fr        #
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

HDR = wolf3d.h\
	  colors.h\
	  controls.h

SRCS = main.c\
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
	   end_game.c

OBJ_DIR = ./obj

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

OBJ = $(addprefix $(OBJ_DIR)/,$(OBJS))

DEP = $(addprefix $(OBJ_DIR)/,$(DEPS))

all: mkdir $(NAME)

mkdir:
	@mkdir -p $(OBJ_DIR)

$(NAME): $(LIB) $(OBJ) Makefile $(HDR)
	@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB) -L $(MLX_PATH) $(MLX_FLAGS)
	@echo "$(YELLOW)./$(NAME)  $(GREEN)ready   ✅ $(RESET)"

-include $(DEP)

$(OBJ_DIR)/%.o : ./%.c Makefile $(HDR)
	@gcc $(FLAGS) -I $(LIB_PATH) -MMD -MP -c $< -o $@

$(LIB) : force
	@make -C $(LIB_PATH)

force :

clean:
	@rm -f $(OBJ)
	@echo "$(YELLOW).o        $(RED)deleted 💯 $(RESET)"
	@rm -f $(DEP)
	@echo "$(YELLOW).d        $(RED)deleted 💯 $(RESET)"
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "$(YELLOW)./$(NAME)  $(RED)deleted 💯 $(RESET)"

re: fclean all

.SILENT:

.PHONY: all mkdir force clean fclean re
