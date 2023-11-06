NAME		=	pipex

OBJ_DIR		=	obj

SRCS_DIR	=	srcs

SRCS		=	$(wildcard $(SRCS_DIR)/*.c)

OBJS		=	$(patsubst $(SRCS_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

FLAGS		=	-Wall -Wextra -Werror -g

INC			=	-I includes

RM			=	rm -rf

GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED			= \033[38;5;196m
RESET 		= \033[0m

LIBFT_DIR	=	Libft

LIBFT		=	libft.a

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(dir @)
	cc $(FLAGS) $(INC) -c $< -o $@
	echo "[$(GREEN)compiling$(RESET)]: $<"

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cc $(FLAGS) $(INC) $(OBJS) $(LIBFT_DIR)/$(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean:
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re