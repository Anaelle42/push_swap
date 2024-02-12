/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:39:46 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/12 19:12:56 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list *a)
{
	int	b;

	while (a->next)
	{
		b = (a)->content;
		a = (a)->next;
		if (b > (a->content))
			return (0);
	}
	return (1);
}

void	sort_3n(t_list **a)
{
	if (check_sort(*a) == 0)
	{
		if (nbr_min(*a) == (*a)->content)
		{
			swap_a(a);
			rotate_a(a);
		}
		else if (nbr_max(*a) == (*a)->content)
		{
			rotate_a(a);
			if (check_sort(*a) == 0)
				swap_a(a);
		}
		else
		{
			if (nbr_max(*a) == (*a)->next->content)
				rr_a(a);
			else
				swap_a(a);
		}
	}
}
void	algo(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (check_sort(*a) == 0)
	{
		if (size == 2)
			swap_a(a);
		if (size >= 3)
		{
			if (size > 3)
				push_to_b(a, b);
			if (ft_lstsize(*a) > 3)
				push_to_b(a, b);
			// while (ft_lstsize(*a) > 3)
			{
				push_sort_b(a, b);
			}
			sort_3n(a);
			// while (ft_lstsize(*b) > 0)
			{
				//	push_b(b, a);
			}
			size = nbr_min(*a);
			while ((*a)->content != size)
			{
				if (position(*a, size) > (ft_lstsize(*a) / 2))
					rr_a(a);
				else
					rotate_a(a);
			}
		}
	}
	// if (check_sort(*a) == 1)
	//	printf("c'est trié piouu\n");
}

void	algo_2(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (check_sort(*stack_a) == 0)
	{
		if (size == 2)
			swap_a(stack_a);
		if (size >= 3)
		{
			if (size > 3)
				push_to_b(stack_a, stack_b);
			if ((ft_lstsize(*stack_a) > 3) && check_sort(*stack_a) == 0)
				push_to_b(stack_a, stack_b);
			if ((ft_lstsize(*stack_a) > 3) && check_sort(*stack_a) == 0)
			{
				stack_b = push_sort_b(stack_a, stack_b);
			}
			sort_3n(stack_a);
			stack_a = push_sort_a(stack_a, stack_b);
			size = nbr_min(*stack_a);
			while ((*stack_a)->content != size)
			{
				if (position(*stack_a, size) > (ft_lstsize(*stack_a) / 2))
					rr_a(stack_a);
				else
					rotate_a(stack_a);
			}
		}
		printf("pile ok en 639 ??\n");
		if (check_sort(*stack_a) == 1)
			printf("c'est trié piouu\n");
	}
}
