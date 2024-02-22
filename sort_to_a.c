/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:14:10 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/20 14:18:37 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = cmb_rarb(*stack_b, *stack_a, tmp->content, 'a');
	while (tmp)
	{
		if (i > cmb_rarb(*stack_b, *stack_a, tmp->content, 'a'))
			i = cmb_rarb(*stack_b, *stack_a, tmp->content, 'a');
		if (i > cmb_rrarrb(*stack_a, *stack_b, tmp->content, 'a'))
			i = cmb_rrarrb(*stack_a, *stack_b, tmp->content, 'a');
		if (i > cmb_rarrb(*stack_a, *stack_b, tmp->content, 'a'))
			i = cmb_rarrb(*stack_a, *stack_b, tmp->content, 'a');
		if (i > cmb_rrarb(*stack_a, *stack_b, tmp->content, 'a'))
			i = cmb_rrarb(*stack_a, *stack_b, tmp->content, 'a');
		tmp = tmp->next;
	}
	return (i);
}

void push_sort_a(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	int i;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = sort_to_a(stack_a, stack_b);
		while (i >= 0)
		{
			if (i == cmb_rarb(*stack_b, *stack_a, tmp->content, 'a'))
				i = fais_rarb(stack_a, stack_b, tmp->content, 'a');
			else if (i == cmb_rrarrb(*stack_a, *stack_b, tmp->content, 'a'))
				i = fais_rrarrb(stack_a, stack_b, tmp->content, 'a');
			else if (i == cmb_rarrb(*stack_a, *stack_b, tmp->content, 'a'))
				i = fais_rarrb(stack_a, stack_b, tmp->content, 'a');
			else if (i == cmb_rrarb(*stack_a, *stack_b, tmp->content, 'a'))
				i = fais_rrarb(stack_a, stack_b, tmp->content, 'a');
			tmp = tmp->next;
		}
	}
}