/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:46:55 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/23 18:07:31 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = count_moves_rarb(*stack_a, *stack_b, tmp->content, 'b');
	while (tmp)
	{
		if (i > count_moves_rarb(*stack_a, *stack_b, tmp->content, 'b'))
			i = count_moves_rarb(*stack_a, *stack_b, tmp->content, 'b');
		if (i > count_moves_rrarrb(*stack_a, *stack_b, tmp->content, 'b'))
			i = count_moves_rrarrb(*stack_a, *stack_b, tmp->content, 'b');
		if (i > count_moves_rarrb(*stack_a, *stack_b, tmp->content, 'b'))
			i = count_moves_rarrb(*stack_a, *stack_b, tmp->content, 'b');
		if (i > count_moves_rrarb(*stack_a, *stack_b, tmp->content, 'b'))
			i = count_moves_rrarb(*stack_a, *stack_b, tmp->content, 'b');
		tmp = tmp->next;
	}
	return (i);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;

	while (ft_lstsize(*stack_a) > 3)
	{
		tmp = *stack_a;
		i = sort_to_b(stack_a, stack_b);
		while (i >= 0)
		{
			if (i == count_moves_rarb(*stack_a, *stack_b, tmp->content, 'b'))
				i = do_rarb(stack_a, stack_b, tmp->content, 'b');
			else if (i == count_moves_rrarrb(*stack_a, *stack_b, tmp->content,
					'b'))
				i = do_rrarrb(stack_a, stack_b, tmp->content, 'b');
			else if (i == count_moves_rarrb(*stack_a, *stack_b, tmp->content,
					'b'))
				i = do_rarrb(stack_a, stack_b, tmp->content, 'b');
			else if (i == count_moves_rrarb(*stack_a, *stack_b, tmp->content,
					'b'))
				i = do_rrarb(stack_a, stack_b, tmp->content, 'b');
			tmp = tmp->next;
		}
	}
}
