# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:37:55 by filipe            #+#    #+#              #
#    Updated: 2022/12/27 11:30:54 by fialexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/
LIBFT = $(LIBFT_DIRECTORY)libft.a

HEADERS_LIST = pipex.h
HEADERS_DIRECTORY = ./incl/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_LIST = pipex.c childs.c error_management.c free.c
SOURCES_DIRECTORY = ./srcs/
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_DIRECTORY = objs/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

CC = gcc
FLAGS = -Wall -Werror -Wextra -g
LIBRARIES = -L$(LIBFT_DIRECTORY) -lft 
INCLUDES = -I $(HEADERS_DIRECTORY) -I $(LIBFT_HEADERS)

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
CYAN = \033[0;36m
RESET = \033[0m


all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS) $(LIBFT)
	@echo "\n$(GREEN)Starting compile$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) $(LIBRARIES) -o $(NAME)
	@echo "$(CYAN)$(NAME):$(RESET) $(GREEN)object files were created$(RESET)"
	@echo "$(CYAN)$(NAME):$(RESET) $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(CYAN)$(NAME):$(RESET) $(GREEN)$(OBJECTS_DIRECTORY)$(RESET) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS) 
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(CYAN)$(NAME):$(RESET) $(GREEN)Creating $(LIBFT)$(RESET)"
	@make -sC $(LIBFT_DIRECTORY)

clean:
	@make -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(CYAN)$(NAME):$(RESET) $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(CYAN)$(NAME):$(RESET) $(RED)object files deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@make -sC $(LIBFT_DIRECTORY) fclean
	@echo "$(CYAN)$(NAME):$(RESET) $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(CYAN)$(NAME):$(RESET) $(RED)$(NAME) was deleted$(RESET)"

re:
	@make fclean
	@make all

.PHONY	: re fclean clean all