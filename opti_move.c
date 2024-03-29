/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:01:39 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/24 12:53:22 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_moves_rarb(t_list *a, t_list *b, int nb, int stack)
{
	int	i;

	if (stack == 'b')
	{
		i = position(a, nb);
		if (i < find_position_in_b(b, nb))
			i = find_position_in_b(b, nb);
	}
	else
	{
		i = position(b, nb);
		if (i < find_position_in_a(a, nb))
			i = find_position_in_a(a, nb);
	}
	return (i);
}

int	count_moves_rrarrb(t_list *a, t_list *b, int nb, int stack)
{
	int	i;

	i = 0;
	if (stack == 'b')
	{
		if (position(a, nb))
			i = (ft_lstsize(a) - position(a, nb));
		if (find_position_in_b(b, nb) && (i < (ft_lstsize(b)
					- find_position_in_b(b, nb))))
			i = ft_lstsize(b) - find_position_in_b(b, nb);
	}
	else
	{
		if (position(b, nb))
			i = ft_lstsize(b) - position(b, nb);
		if (find_position_in_a(a, nb) && (i < (ft_lstsize(a)
					- find_position_in_a(a, nb))))
			i = ft_lstsize(a) - find_position_in_a(a, nb);
	}
	return (i);
}

int	count_moves_rrarb(t_list *a, t_list *b, int nb, int stack)
{
	int	i;

	i = 0;
	if (position(a, nb) != 0)
		i = (ft_lstsize(a) - position(a, nb));
	if (stack == 'b')
	{
		i = i + find_position_in_b(b, nb);
	}
	else
	{
		i = i + find_position_in_a(b, nb);
	}
	return (i);
}

int	count_moves_rarrb(t_list *a, t_list *b, int nb, int stack)
{
	int	i;

	i = 0;
	if (stack == 'b')
	{
		if (find_position_in_b(b, nb))
			i = ft_lstsize(b) - find_position_in_b(b, nb);
		i = position(a, nb) + i;
	}
	if (stack == 'a')
	{
		if (position(b, nb))
			i = ft_lstsize(b) - position(b, nb);
		i = find_position_in_a(a, nb) + i;
	}
	return (i);
}
