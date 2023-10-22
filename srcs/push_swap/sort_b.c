/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:04 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/22 11:37:34 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a(t_push_swap *data, int size)
{
	while (size--)
		operator("pa", data, 1);
}

static void	call_next_sort(t_push_swap *data, int count[3])
{
	if (!check_sort_n(data->a, ASC, count[PUSH] - count[RA]))
		sort_a(data, count[PUSH] - count[RA]);
	return_stack(data, count[RA], count[RB]);
	if (!check_sort_n(data->a, ASC, count[RA]))
		sort_a(data, count[RA]);
	if (!check_sort_n(data->b, DESC, count[RB]))
		sort_b(data, count[RB]);
	else
		push_a(data, count[RB]);
}

static void	move_stack(t_push_swap *data, int pivot[2], int count[3])
{
	if (data->b->content < pivot[SML])
	{
		++count[RB];
		operator("rb", data, 1);
	}
	else
	{
		++count[PUSH];
		operator("pa", data, 1);
		if (data->a->content < pivot[BIG])
		{
			++count[RA];
			operator("ra", data, 1);
		}
	}
}

static void	switch_sort(t_push_swap *data, int size)
{
	if (size == 3)
		return (sort_three_b(data));
	if (size == 2)
	{
		if (data->b->content < data->b->next->content)
			operator("sb", data, 1);
		operator("pa", data, 1);
		return (operator("pa", data, 1));
	}
	if (size == 1)
		return (operator("pa", data, 1));
}

void	sort_b(t_push_swap *data, int size)
{
	int	count[3];
	int	pivot[2];

	if (check_sort_n(data->b, DESC, size))
		return (push_a(data, size));
	if (size <= 3)
		return (switch_sort(data, size));
	ft_memset(&count, 0, sizeof(count));
	get_pivot(pivot, data->b, size);
	while (size-- > 0)
		move_stack(data, pivot, count);
	call_next_sort(data, count);
}
