/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:14:10 by ahenault          #+#    #+#             */
/*   Updated: 2024/03/06 19:01:17 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = count_moves_rarb(*stack_b, *stack_a, tmp->content, 'a');
	while (tmp)
	{
		if (i > count_moves_rarb(*stack_b, *stack_a, tmp->content, 'a'))
			i = count_moves_rarb(*stack_b, *stack_a, tmp->content, 'a');
		if (i > count_moves_rrarrb(*stack_a, *stack_b, tmp->content, 'a'))
			i = count_moves_rrarrb(*stack_a, *stack_b, tmp->content, 'a');
		if (i > count_moves_rarrb(*stack_a, *stack_b, tmp->content, 'a'))
			i = count_moves_rarrb(*stack_a, *stack_b, tmp->content, 'a');
		if (i > count_moves_rrarb(*stack_a, *stack_b, tmp->content, 'a'))
			i = count_moves_rrarb(*stack_a, *stack_b, tmp->content, 'a');
		tmp = tmp->next;
	}
	return (i);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	int i;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = sort_to_a(stack_a, stack_b);
		while (i >= 0)
		{
			if (i == count_moves_rarb(*stack_b, *stack_a, tmp->content, 'a'))
				i = do_rarb(stack_a, stack_b, tmp->content, 'a');
			else if (i == count_moves_rrarrb(*stack_a, *stack_b, tmp->content,
					'a'))
				i = do_rrarrb(stack_a, stack_b, tmp->content, 'a');
			else if (i == count_moves_rarrb(*stack_a, *stack_b, tmp->content,
					'a'))
				i = do_rarrb(stack_a, stack_b, tmp->content, 'a');
			else if (i == count_moves_rrarb(*stack_a, *stack_b, tmp->content,
					'a'))
				i = do_rrarb(stack_a, stack_b, tmp->content, 'a');
			tmp = tmp->next;
		}
	}
}