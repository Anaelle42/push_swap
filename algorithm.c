/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:39:46 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/20 14:56:12 by ubuntu           ###   ########.fr       */
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
			return (1);
	}
	return (0);
}

void	sort_3n(t_list **a)
{
	if (check_sort(*a) == 1)
	{
		if (nbr_min(*a) == (*a)->content)
		{
			swap_a(a);
			rotate_a(a);
		}
		else if (nbr_max(*a) == (*a)->content)
		{
			rotate_a(a);
			if (check_sort(*a) == 1)
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
void	algo(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (check_sort(*stack_a) == 1)
	{
		if (size == 2)
			swap_a(stack_a);
		if (size >= 3)
		{
			if (size > 3)
				push_to_b(stack_a, stack_b);
			if (ft_lstsize(*stack_a) > 3 && check_sort(*stack_a) == 1)
				push_to_b(stack_a, stack_b);
			if (ft_lstsize(*stack_a) > 3 && check_sort(*stack_a) == 1)
				push_sort_b(stack_a, stack_b);
			sort_3n(stack_a);
			push_sort_a(stack_a, stack_b);
			size = nbr_min(*stack_a);
			while ((*stack_a)->content != size)
			{
				if (position(*stack_a, size) > (ft_lstsize(*stack_a) / 2))
					rr_a(stack_a);
				else
					rotate_a(stack_a);
			}
		}
	}
	printf("pile ok en 659 oui\n");
	// if (check_sort(*a) == 1)
	//	printf("c'est trié piouu\n");
}
