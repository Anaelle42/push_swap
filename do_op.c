/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:52:15 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/24 12:51:20 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_rrarrb(t_list **a, t_list **b, int n, int stack)
{
	if (stack == 'b')
	{
		while (((*a)->content != n) && (find_position_in_b(*b, n) != 0))
			rr_all(a, b);
		while ((*a)->content != n)
			rr_a(a);
		while (find_position_in_b(*b, n) != 0)
			rr_b(b);
		push_to_b(a, b);
	}
	else
	{
		while (((*b)->content != n) && (find_position_in_a(*a, n) != 0))
			rr_all(a, b);
		while ((*b)->content != n)
			rr_b(b);
		while (find_position_in_a(*a, n) != 0)
			rr_a(a);
		push_to_a(b, a);
	}
	return (-1);
}

int	do_rarb(t_list **a, t_list **b, int n, int stack)
{
	if (stack == 'b')
	{
		while (((*a)->content != n) && (find_position_in_b(*b, n) != 0))
			rotate_all(a, b);
		while ((*a)->content != n)
			rotate_a(a);
		while (find_position_in_b(*b, n) != 0)
			rotate_b(b);
		push_to_b(a, b);
	}
	else
	{
		while (((*b)->content != n) && (find_position_in_a(*a, n) != 0))
			rotate_all(a, b);
		while ((*b)->content != n)
			rotate_b(b);
		while (find_position_in_a(*a, n) != 0)
			rotate_a(a);
		push_to_a(b, a);
	}
	return (-1);
}

int	do_rarrb(t_list **a, t_list **b, int n, int stack)
{
	if (stack == 'b')
	{
		while ((*a)->content != n)
			rotate_a(a);
		while (find_position_in_b(*b, n) != 0)
			rr_b(b);
		push_to_b(a, b);
	}
	else
	{
		while (find_position_in_a(*a, n) != 0)
			rotate_a(a);
		while ((*b)->content != n)
			rr_b(b);
		push_to_a(b, a);
	}
	return (-1);
}

int	do_rrarb(t_list **a, t_list **b, int n, int stack)
{
	if (stack == 'b')
	{
		while ((*a)->content != n)
			rr_a(a);
		while (find_position_in_b(*b, n) != 0)
			rotate_b(b);
		push_to_b(a, b);
	}
	else
	{
		while (find_position_in_a(*a, n) != 0)
			rr_a(a);
		while ((*b)->content != n)
			rotate_b(b);
		push_to_a(b, a);
	}
	return (-1);
}
