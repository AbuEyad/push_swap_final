/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:59:48 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/21 13:47:39 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	return_stack(t_push_swap *data, int ra_cnt, int rb_cnt)
{
	while (ra_cnt > 0 || rb_cnt > 0)
	{
		if (ra_cnt > 0 && rb_cnt > 0)
			operator("rrr", data, 1);
		else if (ra_cnt > 0)
			operator("rra", data, 1);
		else if (rb_cnt > 0)
			operator("rrb", data, 1);
		--ra_cnt;
		--rb_cnt;
	}
}
