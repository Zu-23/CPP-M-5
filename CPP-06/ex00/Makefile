CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
SRCS = ScalarConverter.cpp main.cpp
OBJS = $(SRC:.c=.o)
RM = rm -rf
NAME = convert

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all