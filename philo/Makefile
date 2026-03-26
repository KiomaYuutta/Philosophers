NAME 	= philo

SOURCES = philo.c start_sim.c setvars.c checkers/main_check.c \
checkers/checks1.c checkers/checks_utils.c routine_stuff/routines.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS 	= -Wall -Wextra -Werror

LIBS 	= -pthread



all: $(NAME)

$(NAME): $(OBJECTS) philo.h
	@ar r philo.a philo.h $(OBJECTS)
	cc $(CFLAGS) philo.a -o philo $(LIBS)
	@printf "\033[1;32mPHILOSOPHERS SUCCESSFULLY COMPILED!\033[0m\n"

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) philo.a
	@printf "\033[1;31mPHILOSOPHERS SUCCESSFULLY REMOVED!\033[0m\n"


re: fclean all



.PHONY: all clean fclean re
