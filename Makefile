NAME := push_swap
SRC_DIR := src
OBJ_DIR := obj
INCLUDE_DIR := include
LIBFT_DIR := libft
SRCFILES := initialize_stack.c \
			main.c \
			rotate1.c \
			rotate2.c \
			sort.c \
			stack_operation.c \
			swap.c \
			utils.c

CC := cc
CFLAGS := -Wall -Wextra -Werror -I
RM := rm -f
RMDIR := rm -rf

SRCS := $(addprefix $(SRC_DIR)/, $(SRCFILES))
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT := $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE_DIR) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RMDIR) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
