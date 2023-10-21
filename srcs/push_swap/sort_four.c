/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:17:52 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/21 13:41:41 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_four(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	tmp = stack;
	min = tmp->content;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

void	sort_four(t_push_swap *data)
{
	int		i;
	int		min;

	if (check_sort_n(data->a, ASC, 4))
		return ;
	min = get_min_four(data->a);
	i = 0;
	while (i++ < 4)
	{
		if (data->a->content == min)
			operator("pb", data, 1);
		else
			operator("ra", data, 1);
	}
	if (!check_sort_n(data->a, ASC, 3))
		sort_three(data);
	operator("pa", data, 1);
}
