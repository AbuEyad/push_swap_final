# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 11:36:52 by habu-zua          #+#    #+#              #
#    Updated: 2023/10/15 13:01:16 by habu-zua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	 = lib.a
SRCSDIR	 = srcs
OBJSDIR  = objs
INCLUDES = inc

SRCS  = $(addprefix libft/,ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
		ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_malloc.c ft_split.c ft_strjoin.c ft_strlcpy.c \
		ft_strmapi.c ft_strnstr.c ft_strtrim.c ft_tolower.c ft_strchr.c \
		ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strrchr.c \
		ft_substr.c ft_toupper.c ft_strcmp.c ft_atoi.c ft_itoa.c)
SRCS  += $(addprefix get_next_line/,get_next_line.c get_next_line_utils.c)

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	@ar rcs $(NAME) $(OBJS)	
	@echo "\033[32m$@ is ready\033[0m"

$(OBJS) : $(OBJSDIR)/%.o:$(SRCSDIR)/%.c $(INCLUDES)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o  $@

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re