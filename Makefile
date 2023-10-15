# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 22:02:23 by habu-zua          #+#    #+#              #
#    Updated: 2023/10/14 19:17:22 by habu-zua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER   = checker
PUSH_SWAP = push_swap
LIBFT     = libft.a
NAME      = $(PUSH_SWAP) $(CHECKER)

SRC_DIR   = srcs
OBJ_DIR   = objs
INCLUDES  = includes
LIBFT_DIR = libft

ST_DIR  = stack
CH_DIR  = checker
PS_DIR  = push_swap

ST_SRCS = $(addprefix $(ST_DIR)/,check_stack_sorted.c create_stack_with_arg.c \
		  operator.c print_stacks.c push.c rotate.c  rrotate.c stack_add_back.c \
		  stack_add_front.c stack_clear.c stack_last.c stack_new.c stack_size.c swap.c)
CH_SRCS = $(addprefix $(CH_DIR)/,exec_instruction.c read_instruction.c)
PS_SRCS = $(addprefix $(PS_DIR)/,check_sort_n.c get_pivot.c return_stack.c\
		  sort_a.c sort_b.c sort_five.c sort_three.c sort_three_a.c \
		  sort_three_b.c stack_sort.c sort_four.c)

CC = cc
CFLAGS = -Wall -Wextra -Werror

CH_OBJS = $(CH_SRCS:%.c=$(OBJ_DIR)/%.o)
PS_OBJS = $(PS_SRCS:%.c=$(OBJ_DIR)/%.o)
ST_OBJS = $(ST_SRCS:%.c=$(OBJ_DIR)/%.o)


all : $(NAME)

$(PUSH_SWAP) :$(PS_OBJS) $(ST_OBJS) $(INCLUDES) $(LIBFT)
	@$(CC) $(CFLAGS) $(ST_OBJS) $(PS_OBJS) -I$(INCLUDES) $(LIBFT_DIR)/$(LIBFT) srcs/push_swap.c -o $@
	@echo "\033[32m$@ is ready\033[0m"

$(CHECKER) : $(CH_OBJS) $(ST_OBJS) $(INCLUDES) 
	@$(CC) $(CFLAGS) $(CH_OBJS) $(ST_OBJS) -I$(INCLUDES) $(LIBFT_DIR)/$(LIBFT) srcs/checker.c -o $@
	@echo "\033[32m$@ is ready\033[0m"

$(PS_OBJS) : $(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(CH_OBJS) : $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c 
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o  $@

$(ST_OBJS) : $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c 
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o  $@

RM = rm
RMFLAGS = -rf


$(LIBFT) :
	@make -C $(LIBFT_DIR)

clean :
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean


fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)
	@make -C $(LIBFT_DIR) fclean


re : fclean all

.PHONY: all clean fclean re test \
	$(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean
