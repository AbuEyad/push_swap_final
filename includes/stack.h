/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:15:18 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/15 13:05:43 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../lib/inc/libft.h"

# define VISUAL_SPEED	100000

# define FT_INT_MAX 	2147483647
# define FT_INT_MIN 	-2147483648

# define OP		1
# define VISUAL	2

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				content;
}				t_stack;

typedef struct s_push_swap
{
	t_stack		*a;
	t_stack		*b;
	int			visualizer;
}				t_push_swap;

t_stack	*create_stack(int argc, char *argv[]);

void	push(t_stack **from, t_stack **to);
void	swap(t_stack *stack);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);

void	print_stacks(t_stack *stack_a, t_stack *stack_b);
int		check_stack_sorted(t_stack *stack_a, t_stack *stack_b);
t_stack	*stack_new(int content);
void	stack_add_front(t_stack **lst, t_stack *new_list);
void	stack_add_back(t_stack **lst, t_stack *new_list);

int		stack_size(t_stack *lst);
t_stack	*stack_last(t_stack *lst);

void	stack_clear(t_stack **lst);
void	operator(char *op, t_push_swap *data);

#endif
