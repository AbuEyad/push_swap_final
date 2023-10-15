/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:13:37 by habu-zua          #+#    #+#             */
/*   Updated: 2023/10/03 20:13:49 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "stack.h"

t_list	*read_instruction(void);
int		exec_instruction(t_list *instructions, t_push_swap *data);

#endif
