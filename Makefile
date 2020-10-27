# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iltafah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 12:39:16 by iltafah           #+#    #+#              #
#    Updated: 2020/10/27 14:30:37 by iltafah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAGS = -Wall -Wextra -Werror

SRC = ./Mandatory_file/GNL/get_next_line.c \
./Mandatory_file/GNL/get_next_line_utils.c \
./Mandatory_file/drawing_functions/draw_cell_and_floor.c \
./Mandatory_file/drawing_functions/drawing_sprite.c \
./Mandatory_file/drawing_functions/drawing_walls.c \
./Mandatory_file/initializing_functions/initialize.c \
./Mandatory_file/initializing_functions/second_initialize.c \
./Mandatory_file/initializing_functions/set_positions.c \
./Mandatory_file/movement_functions/movement_functions_1.c \
./Mandatory_file/movement_functions/movement_functions_2.c \
./Mandatory_file/my_string_functions/first_string_manipulating.c \
./Mandatory_file/my_string_functions/second_string_manipulating.c \
./Mandatory_file/my_string_functions/third_string_manipulating.c \
./Mandatory_file/read_file/file_handling.c \
./Mandatory_file/read_file/file_handling_utils.c \
./Mandatory_file/read_file/ft_split.c \
./Mandatory_file/read_file/handel_file_error.c \
./Mandatory_file/read_file/map_handling.c \
./Mandatory_file/screenshot_functions/screenshot.c \
./Mandatory_file/textures_functions/load_textures.c \
./Mandatory_file/textures_functions/texture_calculation.c \
./Mandatory_file/main.c \
./Mandatory_file/game_manager.c \
./Mandatory_file/check_errors.c

B_SRC = ./file_bonus/GNL_bonus/get_next_line_bonus.c \
./file_bonus/GNL_bonus/get_next_line_utils_bonus.c \
./file_bonus/drawing_functions_bonus/draw_cell_and_floor_bonus.c \
./file_bonus/drawing_functions_bonus/drawing_sprite_bonus.c \
./file_bonus/drawing_functions_bonus/drawing_walls_bonus.c \
./file_bonus/initializing_functions_bonus/initialize_bonus.c \
./file_bonus/initializing_functions_bonus/second_initialize_bonus.c \
./file_bonus/initializing_functions_bonus/set_positions_bonus.c \
./file_bonus/movement_functions_bonus/movement_functions_1_bonus.c \
./file_bonus/movement_functions_bonus/movement_functions_2_bonus.c \
./file_bonus/my_string_functions_bonus/first_string_manipulating_bonus.c \
./file_bonus/my_string_functions_bonus/second_string_manipulating_bonus.c \
./file_bonus/my_string_functions_bonus/third_string_manipulating_bonus.c \
./file_bonus/read_file_bonus/file_handling_bonus.c \
./file_bonus/read_file_bonus/file_handling_utils_bonus.c \
./file_bonus/read_file_bonus/ft_split_bonus.c \
./file_bonus/read_file_bonus/handel_file_error_bonus.c \
./file_bonus/read_file_bonus/map_handling_bonus.c \
./file_bonus/screenshot_functions_bonus/screenshot_bonus.c \
./file_bonus/textures_functions_bonus/load_textures_bonus.c \
./file_bonus/textures_functions_bonus/texture_calculation_bonus.c \
./file_bonus/main_bonus.c \
./file_bonus/game_manager_bonus.c \
./file_bonus/check_errors_bonus.c

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -o $@ $^ -lmlx -framework OpenGL -framework AppKit

bonus : $(B_OBJ)
	@gcc -o $(NAME) $^ -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	@gcc $(FLAGS) -o $@ -c $^

clean :
		@rm -f $(OBJ) $(B_OBJ)

fclean : clean
		@rm -f $(NAME)

re : fclean all
