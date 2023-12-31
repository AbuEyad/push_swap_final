/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:10 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/21 13:41:25 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *stack)
{
	int		i;
	int		*array;

	ft_malloc((void **)&array, sizeof(int) * (5 + 1));
	i = 0;
	while (stack)
	{
		array[i++] = stack->content;
		stack = stack->next;
	}
	return (array);
}

static int	get_pivoit_five(t_stack *stack)
{
	int		pivot;
	int		iv[2];
	int		*array;
	int		tmp;

	array = stack_to_array(stack);
	iv[0] = 0;
	while (iv[0] < 4)
	{
		iv[1] = iv[0] + 1;
		while (iv[1] < 5)
		{
			if (array[iv[0]] < array[iv[1]])
			{
				tmp = array[iv[0]];
				array[iv[0]] = array[iv[1]];
				array[iv[1]] = tmp;
			}
			++iv[1];
		}
		++iv[0];
	}
	pivot = array[2];
	free(array);
	return (pivot);
}

void	sort_five(t_push_swap *data)
{
	int		i;
	int		pivot;

	if (check_sort_n(data->a, ASC, 5))
		return ;
	pivot = get_pivoit_five(data->a);
	i = 0;
	while (i++ < 5)
	{
		if (data->a->content < pivot)
			operator("pb", data, 1);
		else
			operator("ra", data, 1);
	}
	sort_three(data);
	if (data->b->content < data->b->next->content)
		operator("sb", data, 1);
	operator("pa", data, 1);
	operator("pa", data, 1);
}
