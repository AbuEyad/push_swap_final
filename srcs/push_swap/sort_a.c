/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:59:57 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/21 13:39:55 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	call_next_sort(t_push_swap *data, int count[3])
{
	return_stack(data, count[RA], count[RB]);
	if (!check_sort_n(data->a, ASC, count[RA]))
		sort_a(data, count[RA]);
	sort_b(data, count[RB]);
	sort_b(data, count[PUSH] - count[RB]);
}

static void	move_stack(t_push_swap *data, int pivot[2], int count[3], int *size)
{
	if (data->a->content > pivot[BIG])
	{
		++count[RA];
		operator("ra", data, 1);
	}
	else
	{
		++count[PUSH];
		operator("pb", data, 1);
		if (data->b->content > pivot[SML])
		{
			if (*size > 0 && data->a->content > pivot[BIG])
			{
				--(*size);
				++count[RA];
				operator("rr", data, 1);
			}
			else
				operator("rb", data, 1);
			++count[RB];
		}
	}
}

static void	switch_sort(t_push_swap *data, int size)
{
	if (size == 3)
		return (sort_three_a(data));
	else if (size == 2 && data->a->content > data->a->next->content)
		return (operator("sa", data, 1));
}

void	sort_a(t_push_swap *data, int size)
{
	int	count[3];
	int	pivot[2];

	if (size <= 3)
		return (switch_sort(data, size));
	if (check_sort_n(data->a, ASC, size))
		return ;
	ft_memset(&count, 0, sizeof(count));
	get_pivot(pivot, data->a, size);
	while (size-- > 0)
		move_stack(data, pivot, count, &size);
	call_next_sort(data, count);
}
