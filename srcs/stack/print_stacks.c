/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:57 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/15 14:27:56 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static t_stack	*print_stack_a(t_stack *stack_a)
{
	int		i;
	char	*tmp;

	tmp = ft_itoa(stack_a->content);
	i = 20 - ft_strlen(tmp);
	while (i--)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd(tmp, 1);
	free(tmp);
	stack_a = stack_a->next;
	return (stack_a);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_putendl_fd("             STACK_A : STACK_B", 1);
	while (stack_a || stack_b)
	{
		if (stack_a)
			stack_a = print_stack_a(stack_a);
		else
			ft_putstr_fd("                    ", 1);
		ft_putstr_fd(" : ", 1);
		if (stack_b)
		{
			ft_putnbr_fd(stack_b->content, 1);
			stack_b = stack_b->next;
		}
		ft_putchar_fd('\n', 1);
	}
}
