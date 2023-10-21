/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:07:49 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/21 13:42:32 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	type_a(t_push_swap *data)
{
	if (data->a->content < data->a->next->next->content)
		return (operator("sa", data, 1));
	operator("sa", data, 1);
	operator("ra", data, 1);
	operator("sa", data, 1);
	operator("rra", data, 1);
}

static void	type_b(t_push_swap *data)
{
	operator("sa", data, 1);
	operator("ra", data, 1);
	operator("sa", data, 1);
	operator("rra", data, 1);
	operator("sa", data, 1);
}

static void	type_c(t_push_swap *data)
{
	operator("ra", data, 1);
	operator("sa", data, 1);
	operator("rra", data, 1);
	operator("sa", data, 1);
}

static void	type_d(t_push_swap *data)
{
	operator("ra", data, 1);
	operator("sa", data, 1);
	operator("rra", data, 1);
}

void	sort_three_a(t_push_swap *data)
{
	if (check_sort_n(data->a, ASC, 3))
		return ;
	if (data->a->content > data->a->next->content && \
		data->a->next->content < data->a->next->next->content)
		return (type_a(data));
	if (data->a->content > data->a->next->content && \
		data->a->next->content > data->a->next->next->content)
		return (type_b(data));
	if (data->a->content < data->a->next->content && \
		data->a->next->content > data->a->next->next->content)
	{
		if (data->a->content > data->a->next->next->content)
			return (type_c(data));
		return (type_d(data));
	}
}
