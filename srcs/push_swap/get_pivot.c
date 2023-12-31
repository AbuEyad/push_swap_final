/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:59:42 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/22 10:17:44 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	*stack_to_array(t_stack *stack, int n)
{
	int		i;
	int		*array;

	ft_malloc((void **)&array, sizeof(int) * (n + 1));
	i = 0;
	while (i < n)
	{
		array[i] = stack->content;
		stack = stack->next;
		++i;
	}
	return (array);
}

void	get_pivot(int pivot[], t_stack *stack, int n)
{
	int		iv[2];
	int		*array;

	array = stack_to_array(stack, n);
	iv[0] = 0;
	while (iv[0] < n - 1)
	{
		iv[1] = iv[0] + 1;
		while (iv[1] < n)
		{
			if (array[iv[0]] < array[iv[1]])
				swap_int(&array[iv[0]], &array[iv[1]]);
			++iv[1];
		}
		++iv[0];
	}
	pivot[SML] = array[(n * 2) / 3];
	pivot[BIG] = array[n / 3];
	free(array);
}
