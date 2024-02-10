/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:35:02 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/08 15:22:45 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SWAP

void	swap(t_list **a)
{
	t_list	*tmp;

	if (!a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	swap_a(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **a)
{
	swap(a);
	write(1, "sb\n", 3);
}

void	swap_all(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

// swap_a(&liste_a);
// swap_b(&liste_b);
// swap_all(&liste_a, &liste_b);
// rotate_a(&liste_a);
// rotate_b(&liste_b);
// rotate_all(&liste_a, &liste_b);
// rr_a(&liste_a);
// rr_b(&liste_b);
// rr_all(&liste_a, &liste_b);
// push_to_b(&liste_a, &liste_b);
// push_to_a(&liste_a, &liste_b);