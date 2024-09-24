# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 17:10:45 by kael-ala          #+#    #+#              #
#    Updated: 2024/09/24 17:55:18 by kael-ala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
FLAGS = -Wall -Wextra -Werror -g  -fsanitize=thread
RM = rm -f

M_FILES = ./src/main.c ./src/utilities.c ./src/helpers.c ./src/routine.c ./src/routine_utils.c ./src/parsing_utils.c ./utils/tax_collector.c ./utils/getterssetters.c ./utils/getterssetters2.c ./utils/utils.c


M_OBJ = $(M_FILES:.c=.o)

all : $(NAME)

$(NAME) :  $(P_OBJ) $(M_OBJ)
	$(CC) $(FLAGS) $^ -o $(NAME)

$(M_OBJ) : ./includes/philosophers.h

%.o : %.c $(INCS)
	$(CC) $(FLAGS) -c $< -o $@
clean:
	$(RM) $(P_OBJ) $(M_OBJ) $(B_OBJ)
fclean: clean
	$(RM) $(P_OBJ) $(M_OBJ) $(B_OBJ) $(NAME) $(BNAME)
re: fclean all