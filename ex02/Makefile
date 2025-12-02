# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 12:20:17 by aimokhta          #+#    #+#              #
#    Updated: 2025/12/02 21:59:20 by aimokhta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

CC = c++

#compilation flags
CFLAG = -Wall -Werror -Wextra -std=c++98 -g -O0 #-fsanitize=address
# -g3 -O3 -O0 -fsanitize=address -fsanitize-recover=leak
# valgrind --leak-check=full --show-leak-kinds=all
# -g = gives error messages for debugging, needed by gdb / valgrind / helgrind

# INC_DIR = include
# INC = -I$(INC_DIR)
SRC_DIR = src

SRC =	main.cpp

OBJ_FOLDER = obj_files

# patsubst : pattern substitution function
# create a list of .o files in the object folder
OBJ_SRC = $(patsubst %.cpp, $(OBJ_FOLDER)/%.o, $(SRC))

# color
GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m  	#white

all: $(NAME)

$(NAME) : $(OBJ_SRC)
	$(CC) $(CFLAG) $(OBJ_SRC) -o $(NAME)
	@echo "${GREEN}----------COMPILED DONE----------\n${RESET}"

$(OBJ_FOLDER)/%.o : %.cpp
	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAG) $(INC) -c $< -o $@
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -rf $(OBJ_FOLDER)
	@echo "${GREEN}----------CLEANED----------\n${RESET}"

fclean : clean
	rm -f $(NAME)
	@echo "${GREEN}----------FULLY REMOVE----------\n${RESET}"

re : fclean all

.PHONY : all clean fclean re