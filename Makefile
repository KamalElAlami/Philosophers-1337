NAME = philo

CC = cc
FLAGS = -Wall -Wextra -Werror -g #-fsanitize=thread 
RM = rm -f

M_FILES = ./src/main.c ./src/utilities.c ./src/helpers.c ./src/routine.c ./src/routine_utils.c ./src/parsing_utils.c ./utils/tax_collector.c ./utils/getterssetters.c

INCS = ./Libft-1337/libft.h

libft = ./Libft-1337/libft.a

M_OBJ = $(M_FILES:.c=.o)

all : $(NAME)

$(NAME) :  $(P_OBJ) $(M_OBJ) $(libft)
	$(CC) $(FLAGS) $(libft) $^ -o $(NAME)

$(M_OBJ) : ./includes/philosophers.h

%.o : %.c $(INCS)
	$(CC) $(FLAGS) -c $< -o $@
$(libft) :
	make -C ./Libft-1337
	make -C ./Libft-1337 bonus
clean:
	$(RM) $(P_OBJ) $(M_OBJ) $(B_OBJ)
	make -C ./Libft-1337 clean
fclean: clean
	$(RM) $(P_OBJ) $(M_OBJ) $(B_OBJ) $(NAME) $(BNAME)
	make -C ./Libft-1337 fclean
re: fclean all