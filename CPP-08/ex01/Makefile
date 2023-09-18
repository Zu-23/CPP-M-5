NAME 	= Span

SRC		= main.cpp Span.cpp

CC 		=	c++

FLAGS	= -std=c++98 -Wall -Wextra -Werror 

OBJS 	= $(SRC:.cpp=.o)

LIB		= Span.hpp
$(NAME): $(OBJS) $(LIB)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME) $(OBJS)

%.o: %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re