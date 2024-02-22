/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:08:52 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/22 20:15:33 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PUSH

void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	*a = (*a)->next;
	ft_lstadd_front(b, tmp);
}

void	push_to_b(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	push_to_a(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}
