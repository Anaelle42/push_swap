/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:03:49 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/08 19:11:07 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ROTATE

void	rotate(t_list **a)
{
	t_list	*tmp;

	if (!a)
		return ;
	tmp = ft_lstlast(*a);
	(tmp)->next = *a;
	*a = (*a)->next;
	tmp->next->next = NULL;
}

// void	rotate(t_list **a)
// {
// 	t_list	*tmp;

// 	if (!a)
// 		return ;
// 	tmp = *a;
// 	*a = ft_lstlast(*a);
// 	(*a)->next = tmp;
// 	*a = tmp->next;
// 	tmp->next = NULL;
// }

void	rotate_a(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **a)
{
	rotate(a);
	write(1, "rb\n", 3);
}

void	rotate_all(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
