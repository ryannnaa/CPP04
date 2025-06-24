CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

NAME := a.out

SRCS := main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS := ${SRCS:.cpp=.o}
DEPS := ${OBJS:.o=.d}

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o $@

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@
	
-include ${DEPS}

clean:
	rm -rf ${OBJS} ${DEPS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re