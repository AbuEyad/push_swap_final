/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:21 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/21 13:44:55 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	type_a(t_push_swap *data)
{
	if (data->b->content > data->b->next->next->content)
	{
		operator("pa", data, 1);
		operator("sb", data, 1);
		operator("pa", data, 1);
		return (operator("pa", data, 1));
	}
	operator("pa", data, 1);
	operator("sb", data, 1);
	operator("pa", data, 1);
	operator("sa", data, 1);
	operator("pa", data, 1);
}

static void	type_b(t_push_swap *data)
{
	operator("pa", data, 1);
	operator("ra", data, 1);
	operator("sb", data, 1);
	operator("pa", data, 1);
	operator("pa", data, 1);
	operator("rra", data, 1);
}

static void	type_c(t_push_swap *data)
{
	operator("sb", data, 1);
	operator("pa", data, 1);
	operator("pa", data, 1);
	operator("pa", data, 1);
}

static void	type_d(t_push_swap *data)
{
	operator("pa", data, 1);
	operator("ra", data, 1);
	operator("pa", data, 1);
	operator("pa", data, 1);
	operator("rra", data, 1);
}

void	sort_three_b(t_push_swap *data)
{
	if (check_sort_n(data->b, DESC, 3))
	{
		operator("pa", data, 1);
		operator("pa", data, 1);
		return (operator("pa", data, 1));
	}
	if (data->b->content > data->b->next->content && \
		data->b->next->content < data->b->next->next->content)
		return (type_a(data));
	if (data->b->content < data->b->next->content && \
		data->b->next->content < data->b->next->next->content)
		return (type_b(data));
	if (data->b->content < data->b->next->content && \
		data->b->next->content > data->b->next->next->content)
	{
		if (data->b->content > data->b->next->next->content)
			return (type_c(data));
		return (type_d(data));
	}
}
