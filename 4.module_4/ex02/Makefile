NAME	=	Ideas

SRC		=	srcs/WrongAnimal.cpp \
			srcs/WrongCat.cpp \
			srcs/Animal.cpp \
			srcs/Brain.cpp \
			srcs/main.cpp \
			srcs/Dog.cpp \
			srcs/Cat.cpp

FLAGS	=	-Wall -Werror -Wextra -std=c++98 -g3

CC		=	c++

OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)
	@printf "\e[36msuccessfully\e[0m\e[33m compiled \e[92m!\e[0m\e[?25h\n"

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
	@printf "\e[?25l\e[JCreated \e[92m$(notdir $@)\e[0m\r"

clean:
	@rm -f $(OBJ)
	@printf "All object files [\033[31mX\033[0m]\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(NAME) [\033[31mX\033[0m]\n"

re : fclean all

.PHONY: all re clean fclean 