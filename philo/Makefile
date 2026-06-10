NAME = philo

SOURCES = philo.c \
setdata.c \
start_sim.c \
utils.c \
checkers/checks_utils.c \
checkers/checks1.c \
checkers/main_check.c \
clean_mem/clean_mem.c \
logs/log_actions.c \
routine_stuff/forks.c \
routine_stuff/routine.c \


OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
LIBS = -pthread

all: $(NAME)

$(NAME): $(OBJECTS) philo.h
	cc $(CFLAGS) $(OBJECTS) -o philo $(LIBS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re