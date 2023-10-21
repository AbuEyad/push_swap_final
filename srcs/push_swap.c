/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:02:13 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/21 16:22:27 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_push_swap	data;

	if (argc < 2)
		return (0);
	ft_memset(&data, 0, sizeof(data));
	data.a = create_stack(argc, argv);
	data.b = NULL;
	stack_sort(&data);
	stack_clear(&data.a);
	stack_clear(&data.b);
	return (0);
}
