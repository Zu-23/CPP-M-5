NAME 	= RPN

SRC		= main.cpp RPN.cpp

CC 		=	c++

FLAGS	= -std=c++98 -Wall -Wextra -Werror 

OBJS 	= $(SRC:.cpp=.o)

LIB		= RPN.hpp
$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.cpp $(LIB)
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re