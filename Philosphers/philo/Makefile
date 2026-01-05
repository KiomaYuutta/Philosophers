NAME = philo

SOURCES = philo.c checkers/main_check.c checkers/checks1.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
LIBS = -pthread

all: $(NAME)

$(NAME): $(OBJECTS) philo.h
	ar r philo.a philo.h $(OBJECTS)
	cc $(CFLAGS) philo.a -o philo $(LIBS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) philo.a

re: fclean all

.PHONY: all clean fclean re