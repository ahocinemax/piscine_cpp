#------------------------------------#
#             COMPILATION            #
#------------------------------------#

NAME		=	PmergeMe
CC			=	c++
INCLUDE		=	-I$(HEAD_DIR)
FLAGS		=	-Wall -Wextra -Werror -std=c++98 -g3

#------------------------------------#
#               SOURCES              #
#------------------------------------#

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILE))
SRC_DIR		=	srcs/
SRC_FILE	=	main.cpp \
				PmergeMe.cpp

#------------------------------------#
#              INCLUDES              #
#------------------------------------#

HEAD_DIR 	=	includes/

#------------------------------------#
#               OBJECTS              #
#------------------------------------#

OBJS 		=	$(addprefix $(OBJ_DIR), $(OBJ))
OBJ_DIR 	=	obj/
OBJ 		=	$(SRC_FILE:.cpp=.o)

#------------------------------------#
#               COLORS               #
#------------------------------------#

NONE		= '\033[0m'
BLUE		= '\033[31m'
GREEN		= '\033[32m'
YELLOW		= '\033[33m'
GRAY		= '\033[2;37m'
CURSIVE		= '\033[3m'

#------------------------------------#
#               RULES                #
#------------------------------------#

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@echo $(CURSIVE)$(GRAY)"Object files created" $(NONE)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			@echo $(CURSIVE)$(GREEN)"$(NAME) executable compiled" $(NONE)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADER)
			mkdir -p $(OBJ_DIR)
			$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@ -I$(HEAD_DIR)

clean	:
			@rm -f $(OBJS)
			@echo $(YELLOW)"Cleaning object files." $(NONE)

fclean	:	clean
			@rm -rf $(NAME) $(OBJ_DIR)
			@echo $(BLUE)"Cleaning $(NAME) executable." $(NONE)

re		:	fclean all

.PHONY	:	all clean fclean re
