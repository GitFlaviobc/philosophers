NAME = philo

OBJ_DIR = obj/
SRC_DIR = src/
HEADER = includes/philosophers.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
THREAD = -pthread

IFLAGS = -Iincludes

OBJ	=	$(OBJ_DIR)main.o $(OBJ_DIR)ft_dinner.o \
		$(OBJ_DIR)ft_parser.o $(OBJ_DIR)ft_philo_actions.o \
		$(OBJ_DIR)ft_philo_eat.o $(OBJ_DIR)ft_prepare_dinner.o \
		$(OBJ_DIR)ft_prints.o $(OBJ_DIR)ft_get_print.o \
		$(OBJ_DIR)ft_time_control.o $(OBJ_DIR)ft_utils.o \
		$(OBJ_DIR)ft_threads.o $(OBJ_DIR)ft_end_dinner.o \

all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJ)
			$(CC) $(CFLAGS) $(THREAD) $(OBJ) -o $@

bonus: all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -c $(IFLAGS) -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re