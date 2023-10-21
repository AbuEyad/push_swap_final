/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:26 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/21 13:44:27 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_a(t_push_swap *data)
{
	operator("ra", data, 1);
	operator("sa", data, 1);
}

static void	case_b(t_push_swap *data)
{
	operator("sa", data, 1);
	operator("ra", data, 1);
}

void	sort_three(t_push_swap *data)
{
	if (check_sort_n(data->a, ASC, 3))
		return ;
	if (data->a->content < data->a->next->content && \
		data->a->next->content > data->a->next->next->content && \
		data->a->content > data->a->next->next->content)
		return (operator("rra", data, 1));
	if (data->a->content > data->a->next->content && \
		data->a->next->content < data->a->next->next->content && \
		data->a->content < data->a->next->next->content)
		return (operator("sa", data, 1));
	if (data->a->content > data->a->next->content && \
		data->a->next->content < data->a->next->next->content && \
		data->a->content > data->a->next->next->content)
		return (operator("ra", data, 1));
	if (data->a->content > data->a->next->content && \
		data->a->next->content > data->a->next->next->content)
		return (case_a(data));
	if (data->a->content < data->a->next->content && \
		data->a->next->content > data->a->next->next->content && \
		data->a->content < data->a->next->next->content)
		return (case_b(data));
}
