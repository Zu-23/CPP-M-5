NAME 	:=	Array
CC 		:=	c++ -Wall -Werror -Wextra -std=c++98
SRC		:= main.cpp
OBJ		:= $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME) $(OBJS)

%.o: %.c
	(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re%