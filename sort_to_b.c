/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:46:55 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/22 20:19:26 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = cmb_rarb(*stack_a, *stack_b, tmp->content, 'b');
	while (tmp)
	{
		if (i > cmb_rarb(*stack_a, *stack_b, tmp->content, 'b'))
			i = cmb_rarb(*stack_a, *stack_b, tmp->content, 'b');
		if (i > cmb_rrarrb(*stack_a, *stack_b, tmp->content, 'b'))
			i = cmb_rrarrb(*stack_a, *stack_b, tmp->content, 'b');
		if (i > cmb_rarrb(*stack_a, *stack_b, tmp->content, 'b'))
			i = cmb_rarrb(*stack_a, *stack_b, tmp->content, 'b');
		if (i > cmb_rrarb(*stack_a, *stack_b, tmp->content, 'b'))
			i = cmb_rrarb(*stack_a, *stack_b, tmp->content, 'b');
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
			if (i == cmb_rarb(*stack_a, *stack_b, tmp->content, 'b'))
				i = fais_rarb(stack_a, stack_b, tmp->content, 'b');
			else if (i == cmb_rrarrb(*stack_a, *stack_b, tmp->content, 'b'))
				i = fais_rrarrb(stack_a, stack_b, tmp->content, 'b');
			else if (i == cmb_rarrb(*stack_a, *stack_b, tmp->content, 'b'))
				i = fais_rarrb(stack_a, stack_b, tmp->content, 'b');
			else if (i == cmb_rrarb(*stack_a, *stack_b, tmp->content, 'b'))
				i = fais_rrarb(stack_a, stack_b, tmp->content, 'b');
			tmp = tmp->next;
		}
	}
}
