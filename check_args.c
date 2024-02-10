/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:48:44 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/08 13:04:54 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// OK que des chiffres + et -
// OK pas de doublons
// Ok pas d'overflow

int	check_numbers(char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
				j++;
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57))
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_doublons(t_list *a)
{
	t_list	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->content == tmp->content)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			tmp = tmp->next;
		}
		a = (a)->next;
	}
	return (0);
}

long int	ft_atol(const char *ptr)
{
	int			i;
	long int	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ptr[i] == 32 || (ptr[i] >= 9 && ptr[i] <= 13))
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		res = res * 10 + ptr[i] - '0';
		i++;
	}
	return (res * sign);
}

void	create_stack(char **argv, t_list **stack_a)
{
	int			i;
	long int	value;
	t_list		*new;

	i = 1;
	while (argv[i])
	{
		value = ft_atol(argv[i]);
		if (value < -2147483648 || value > 2147483647)
		{
			write(2, "Error\n", 6);
			ft_lstclear(stack_a);
			exit(1);
		}
		new = ft_lstnew(value);
		ft_lstadd_back(stack_a, new);
		i++;
	}
}

int	parse_parameters(int argc, char **argv, t_list **stack_a)
{
	if (argc < 2)
		return (1);
	if (check_numbers(argv) == 1)
		return (1);
	if (argc > 2)
		create_stack(argv, stack_a);
	if (check_doublons(*stack_a) == 1)
		return (1);
	return (0);
}
