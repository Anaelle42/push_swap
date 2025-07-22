/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:03:22 by ahenault          #+#    #+#             */
/*   Updated: 2025/07/22 21:54:47 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// REVERSE ROTATE

void	reverse_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	tmp->next = *lst;
	last->next = NULL;
	(*lst) = tmp;
}

void	rr_a(t_list **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rr_b(t_list **a)
{
	reverse_rotate(a);
	write(1, "rrb\n", 4);
}

void	rr_all(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
