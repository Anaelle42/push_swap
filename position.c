/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:41:59 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/22 19:08:29 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nbr_min(t_list *a)
{
	int	min;

	min = a->content;
	while (a)
	{
		if (min > a->content)
			min = a->content;
		a = a->next;
	}
	return (min);
}

int	nbr_max(t_list *a)
{
	int	max;

	max = a->content;
	while (a)
	{
		if (max < a->content)
			max = a->content;
		a = a->next;
	}
	return (max);
}

int	position(t_list *a, int nb)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->content == nb)
			return (i);
		a = a->next;
		i++;
	}
	return (i);
}

// find_position_in_b
int	position_voulue_dans_b(t_list *a, int nb)
{
	t_list	*tmp;
	int		inf;
	int		i;

	tmp = a;
	inf = -2147483648;
	while (a)
	{
		if (a->content < nb && a->content > inf)
		{
			inf = a->content;
		}
		a = a->next;
	}
	if (inf == -2147483648)
		inf = nbr_max(tmp);
	i = position(tmp, inf);
	return (i);
}

// find_position_in_a
int	position_voulue_dans_a(t_list *a, int nb)
{
	t_list	*tmp;
	int		sup;
	int		i;

	tmp = a;
	sup = 2147483647;
	while (a)
	{
		if (a->content > nb && a->content < sup)
		{
			sup = a->content;
		}
		a = a->next;
	}
	if (sup == 2147483647)
		sup = nbr_min(tmp);
	i = position(tmp, sup);
	return (i);
}
