/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:01:39 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/22 19:08:21 by ahenault         ###   ########.fr       */
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
		if (i < position_voulue_dans_b(b, nb))
			i = position_voulue_dans_b(b, nb);
	}
	else
	{
		if (i < position_voulue_dans_a(b, nb))
			i = position_voulue_dans_a(b, nb);
	}
	return (i);
}

int	cmb_rrarrb(t_list *a, t_list *b, int nb, int who)
{
	int	i;

	i = (ft_lstsize(a) - position(a, nb));
	if (who == 'b')
	{
		if (i < (ft_lstsize(b) - position_voulue_dans_b(b, nb)))
			i = ft_lstsize(b) - position_voulue_dans_b(b, nb);
	}
	else
	{
		if (i < (ft_lstsize(b) - position_voulue_dans_a(b, nb)))
			i = ft_lstsize(b) - position_voulue_dans_a(b, nb);
	}
	return (i);
}

int	cmb_rrarb(t_list *a, t_list *b, int nb, int who)
{
	int	i;

	i = (ft_lstsize(a) - position(a, nb));
	if (who == 'b')
	{
		i = i + position_voulue_dans_b(b, nb);
	}
	else
	{
		i = i + position_voulue_dans_a(b, nb);
	}
	return (i);
}

int	cmb_rarrb(t_list *a, t_list *b, int nb, int who)
{
	int	i;

	i = 0;
	if (who == 'b')
	{
		if (position_voulue_dans_b(b, nb))
			i = ft_lstsize(b) - position_voulue_dans_b(b, nb);
		i = position(a, nb) + i;
	}
	if (who == 'a')
	{
		if (position(b, nb))
			i = ft_lstsize(b) - position(b, nb);
		i = position_voulue_dans_a(a, nb) + i;
	}
	return (i);
}
