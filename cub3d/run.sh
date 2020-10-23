
#clang *.c GNL/*.c my_string_functions/*.c read_file/*.c -lmlx -lXext -lX11 -lm && \
#./a.out my_map.cub #--save


gcc *.c GNL/*.c my_string_functions/*.c read_file/*.c drawing_functions/*.c initializing_functions/*.c movement_functions/*.c screenshot_functions/*.c textures_functions/*.c -lmlx -framework OpenGL -framework AppKit 

