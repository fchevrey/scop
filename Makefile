# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 16:05:39 by fchevrey          #+#    #+#              #
#    Updated: 2019/05/06 18:23:57 by fchevrey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop
DIR_NAME = scop

## Colors ##
PURPLE = [038;2;255;40;255
GREEN = [038;2;82;255;123
CYAN = [038;2;0;255;255
PINK = [038;2;255;0;137
YELLOW = [038;2;252;125;91
ORANGE = [038;2;239;138;5

## Sources ##
SRCS_DIR = srcs

SRCS = main.c ft_error.c ft_exit.c glad.c malloc_failed.c  m4_print.c\
		set_uniform_matrix.c\
		event/main_loop.c event/fill_funar_key_event.c event/ft_keyboard.c\
		event/ft_mouse.c event/resize.c event/change_rotation.c\
		event/change_rotation_speed.c event/change_render_mode.c\
		event/change_textures.c\
		\
		init/add_shader.c init/load_shader.c init/init_data.c\
		init/init_shaders.c init/init_matrix.c init/init_textures.c\
		\
		parser/parse.c parser/fill_funar_parse.c parser/prefix_ok.c\
		parser/compare_prefix.c parser/parse_obj_vertex.c parser/parse_next.c\
		parser/parse_obj_normal.c parser/parse_obj_texture.c \
		parser/parse_obj_face.c parser/read_float_arr.c parser/del_info.c\
		parser/free_elem.c parser/lst_to_arr.c parser/init_info.c\
		parser/float_buf_new.c parser/free_float_buf.c parser/read_face.c\
		parser/init_face_info.c parser/del_face_info.c parser/int_buf_new.c\
		parser/free_int_buf.c parser/create_gl_buffer.c parser/centralize_vertex.c\
		tga/parse_tga.c tga/decode_tga.c tga/load_gl_texture.c\
		\
		rendering/render.c
		#test_rectangle.c test_two_triangle.c test_texts.c test_double_tex.c  \


## Objects ##
OBJS = $(SRCS:.c=.o)
OBJS_DIR = ./objs
OBJS_SUB_DIRS = parser rendering event init tga
OBJS_PRE = $(addprefix $(OBJS_DIR)/, $(OBJS))

## Lib dirs ##
LIB_DIR = ./lib
LIBFT_DIR = $(LIB_DIR)/libft
LIBMYSDL_DIR = $(LIB_DIR)/libmysdl
LIBPT_DIR = $(LIB_DIR)/libpt

## Macros for extern library installation ##
SDL_VER = 2.0.9
GLFW_VER = 3.2.1

MAIN_DIR_PATH = $(shell pwd)
SDL_PATH = $(addprefix $(MAIN_DIR_PATH), /lib/sdl2)
GLFW_PATH = $(addprefix $(MAIN_DIR_PATH), /lib/glfw-$(GLFW_VER))
GLAD_PATH = $(addprefix $(MAIN_DIR_PATH), /lib/glad)

HEADER_DIR = includes/

## Includes ##
INC = -I ./$(HEADER_DIR)

SDL2_INC = $(shell sh ./lib/sdl2/bin/sdl2-config --cflags)

LIB_INCS =	-I $(LIBFT_DIR)/includes/ \
			-I $(LIBMYSDL_DIR)/includes/ \
			-I $(LIBPT_DIR)/includes/ \
			$(SDL2_INC) \
			-I $(GLAD_PATH)/ 

HEADER = defines.h scop.h  parser.h struct.h event.h rendering.h

HEADERS = $(addprefix $(HEADER_DIR), $(HEADER))

INCS = $(INC) $(LIB_INCS)

## FLAGS ##
CC = gcc

SDL2_LFLAGS = $(shell sh ./lib/sdl2/bin/sdl2-config --libs)

LFLAGS =	-L $(LIBFT_DIR) -lft \
			-L $(LIBPT_DIR) -lpt \
			-L $(LIBMYSDL_DIR) -lmysdl \
			-lm \
			$(SDL2_LFLAGS)
	
#			-L $(GLFW_PATH)/lib/ -lGLEW

FRAMEWORK = -framework Carbon -framework OpenGL -framework IOKit -framework CoreVideo
#FRAMEWORK = -framework Carbon -framework OpenGL -framework IOKit -framework CoreVideo -lglfw
#LINUX = -lGL -lGLU -lglut

CFLAGS = -Wall -Wextra -Werror

MESSAGE = "make[1]: Nothing to be done for 'all'"
DONE_MESSAGE = "\033$(GREEN)2m✓\t\033$(GREEN)mDONE !\033[0m\
				\n ========================================\n"

## RULES ##

all: SDL2 LIBFT LIBPT MYSDL print_name $(NAME) print_end

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	@echo "\033$(PURPLE)m⧖	Creating	$@\033[0m"
	@export PKG_CONFIG_PATH=$(PKG_CONFIG_PATH):$(addprefix $(SDL_PATH), /lib/pkgconfig) &&\
	gcc -c -o $@ $< $(CFLAGS) $(INCS)

$(OBJS_DIR):
	@echo "\033$(CYAN)m➼	\033$(CYAN)mCreating $(DIR_NAME)'s objects \
	with flag : \033$(GREEN)m $(CFLAGS)\033[0m"
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(addprefix $(OBJS_DIR)/, $(OBJS_SUB_DIRS))

$(NAME): $(OBJS_DIR) $(OBJS_PRE) $(HEADERS)
	@echo "\033$(GREEN)m➼\t\033$(GREEN)32m Creating $(DIR_NAME)'s executable\033[0m"
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJS_PRE) $(LFLAGS) $(FRAMEWORK)
	@$(eval MESSAGE = $(DONE_MESSAGE))

rm_obj:
	@rm -rf $(OBJS_DIR)
	@echo "\033$(PINK)36m✗	\033[0m\033$(PINK)31m$(DIR_NAME)'s object removed\033[0m"

clean: rm_obj
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBPT_DIR) clean
	@make -C $(LIBMYSDL_DIR) clean

fclean: rm_obj
	@rm -rf $(NAME)
	@echo "\033$(PINK)36m✗	\033[0m\033$(PINK)31m$(NAME) removed\033[0m"
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LIBPT_DIR) fclean
	@make -C $(LIBMYSDL_DIR) fclean

re: fclean all

exe: rm_obj all

rm_SDL2:
	@rm -rf $(SDL2_PATH)
	@echo "\033$(PINK)36m✗	SDL2-$(SDL_VER) removed\033[0m"

re_SDL2: fclean rm_SDL2 all

MODE_DEBUG: change_cflag all

re_MODE_DEBUG: rm_obj MODE_DEBUG

change_cflag:
	@$(eval CFLAGS = -fsanitize=address)

SDL2 :
	@if [ ! -d "./lib/sdl2" ]; then \
		echo "\033$(PINK)m⚠\tSDL2 is not installed ! ...\033[0m"; \
		echo "\033$(CYAN)m➼\tCompiling SDL2-$(SDL_VER) ...\033[0m"; \
		printf "\r\033$(YELLOW)m\tIn 3 ...\033[0m"; sleep 1; \
		printf "\r\033$(YELLOW)m\tIn 2 ...\033[0m"; sleep 1; \
		printf "\r\033$(YELLOW)3m\tIn 1 ...\033[0m"; sleep 1; printf "\n"; \
		curl -OL http://www.libsdl.org/release/SDL2-$(SDL_VER).tar.gz && \
		tar -zxvf SDL2-$(SDL_VER).tar.gz && \
		rm SDL2-$(SDL_VER).tar.gz && \
		mkdir -p $(SDL_PATH) && \
		cd SDL2-$(SDL_VER) && \
			sh configure --prefix=$(SDL_PATH) && \
			make && \
			make install && \
		cd .. && \
		rm -rf SDL2-$(SDL_VER);\
		echo "\033$(GREEN)m✓\tSDl2-$(SDL_VER) installed !\033[0m"; \
	else \
		echo "\033$(GREEN)m✓\tSDl2-$(SDL_VER) already installed\033[0m"; \
	fi

LIBFT:
	@echo "\033[033m➼\t\033[033mCompiling Libft ...\033[0m"
	@make -C $(LIBFT_DIR)

LIBPT:
	@echo "\033[033m➼\t\033[033mCompiling Libpt ...\033[0m"
	@make -C$(LIBPT_DIR)

MYSDL:
	@echo "\033[033m➼\t\033[033mCompiling Libmysdl ...\033[0m"
	@make -C $(LIBMYSDL_DIR)

print_name:
	@echo "\033[033m➼\t\033[033mCompiling $(DIR_NAME) ...\033[0m"

print_end:
	@echo $(MESSAGE)

.PHONY: all clean fclean re rm_obj exe SDL2 VORBIS LIBFT LIBPT MYSDL rm_SDL2 re_SDL2 \
		MODE_DEBUG re_MODE_DEBUG change_cflag print_name print_end FMOD
