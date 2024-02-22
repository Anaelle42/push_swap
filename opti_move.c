/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:01:39 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/22 20:21:25 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// who == list
// count_moves
int	cmb_rarb(t_list *a, t_list *b, int nb, int who)
{
	int	i;

	i = position(a, nb);
	if (who == 'b')
	{
		if (i < find_position_in_b(b, nb))
			i = find_position_in_b(b, nb);
	}
	else
	{
		if (i < find_position_in_a(b, nb))
			i = find_position_in_a(b, nb);
	}
	return (i);
}

int	cmb_rrarrb(t_list *a, t_list *b, int nb, int who)
{
	int	i;

	i = (ft_lstsize(a) - position(a, nb));
	if (who == 'b')
	{
		if (i < (ft_lstsize(b) - find_position_in_b(b, nb)))
			i = ft_lstsize(b) - find_position_in_b(b, nb);
	}
	else
	{
		if (i < (ft_lstsize(b) - find_position_in_a(b, nb)))
			i = ft_lstsize(b) - find_position_in_a(b, nb);
	}
	return (i);
}

int	cmb_rrarb(t_list *a, t_list *b, int nb, int who)
{
	int	i;

	i = (ft_lstsize(a) - position(a, nb));
	if (who == 'b')
	{
		i = i + find_position_in_b(b, nb);
	}
	else
	{
		i = i + find_position_in_a(b, nb);
	}
	return (i);
}

int	cmb_rarrb(t_list *a, t_list *b, int nb, int who)
{
	int	i;

	i = 0;
	if (who == 'b')
	{
		if (find_position_in_b(b, nb))
			i = ft_lstsize(b) - find_position_in_b(b, nb);
		i = position(a, nb) + i;
	}
	if (who == 'a')
	{
		if (position(b, nb))
			i = ft_lstsize(b) - position(b, nb);
		i = find_position_in_a(a, nb) + i;
	}
	return (i);
}
