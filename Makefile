# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 22:02:23 by habu-zua          #+#    #+#              #
#    Updated: 2023/10/22 11:32:31 by habu-zua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER   = checker
PUSH_SWAP = push_swap
LIB       = lib.a
NAME      = $(PUSH_SWAP)

SRC_DIR   = srcs
OBJ_DIR   = objs
INCLUDES  = includes
LIB_DIR   = lib

ST_DIR  = stack
CH_DIR  = checker
PS_DIR  = push_swap

ST_SRCS = stack/check_stack_sorted.c stack/create_stack.c stack/operator.c \
		  stack/push.c stack/rotate.c  stack/rrotate.c stack/stack_add_back.c \
		  stack/stack_add_front.c stack/stack_clear.c stack/stack_last.c\
		  stack/stack_new.c stack/stack_size.c stack/swap.c
CH_SRCS = checker/exec_operation.c checker/read_operation.c
PS_SRCS = push_swap/check_sort_n.c push_swap/get_pivot.c push_swap/return_stack.c\
		  push_swap/sort_a.c push_swap/sort_b.c push_swap/sort_five.c \
		  push_swap/sort_three.c push_swap/sort_three_a.c push_swap/sort_three_b.c\
		  push_swap/stack_sort.c push_swap/sort_four.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

CH_OBJS = $(CH_SRCS:%.c=$(OBJ_DIR)/%.o)
PS_OBJS = $(PS_SRCS:%.c=$(OBJ_DIR)/%.o)
ST_OBJS = $(ST_SRCS:%.c=$(OBJ_DIR)/%.o)


all : $(NAME)

$(PUSH_SWAP) :$(PS_OBJS) $(ST_OBJS) $(INCLUDES) $(LIB)
	@$(CC) $(CFLAGS) $(ST_OBJS) $(PS_OBJS) -I$(INCLUDES) $(LIB_DIR)/$(LIB) srcs/push_swap.c -o $@
	@echo "\033[32m$@ is ready\033[0m"

bonus : $(CHECKER)

$(CHECKER) : $(CH_OBJS) $(ST_OBJS) $(INCLUDES) $(LIB)
	@$(CC) $(CFLAGS) $(CH_OBJS) $(ST_OBJS) -I$(INCLUDES) srcs/checker.c $(LIB_DIR)/$(LIB)  -o $@
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


$(LIB) :
	@make -C $(LIB_DIR)

clean :
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	@make -C $(LIB_DIR) clean


fclean : clean
	@$(RM) $(RMFLAGS) $(NAME) $(CHECKER)
	@make -C $(LIB_DIR) fclean


re : fclean all

.PHONY: all clean fclean re test \
	$(LIB) $(LIB)_clean $(LIB)_fclean
