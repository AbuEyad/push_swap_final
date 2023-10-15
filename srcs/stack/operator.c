/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:00:52 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/03 22:00:54 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	operator(char *op, t_push_swap *data)
{
	if (!ft_strcmp(op, "ra") || !ft_strcmp(op, "rr"))
		rotate(&data->a);
	if (!ft_strcmp(op, "rb") || !ft_strcmp(op, "rr"))
		rotate(&data->b);
	if (!ft_strcmp(op, "rra") || !ft_strcmp(op, "rrr"))
		rrotate(&data->a);
	if (!ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrr"))
		rrotate(&data->b);
	if (!ft_strcmp(op, "pa"))
		push(&data->b, &data->a);
	if (!ft_strcmp(op, "pb"))
		push(&data->a, &data->b);
	if (!ft_strcmp(op, "sa") || !ft_strcmp(op, "ss"))
		swap(data->a);
	if (!ft_strcmp(op, "sb") || !ft_strcmp(op, "ss"))
		swap(data->b);
	if (data->visualizer == VISUAL)
	{
		system("clear");
		print_stacks(data->a, data->b);
		usleep(VISUAL_SPEED);
	}
	if (data->visualizer == OP)
		ft_putendl_fd(op, 1);
}
