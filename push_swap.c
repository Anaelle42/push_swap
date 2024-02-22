/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:48:12 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/20 14:47:39 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (parse_parameters(argc, argv, &stack_a) == 1)
	{
		ft_lstclear(&stack_a);
		return (0);
	}
	algo(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}

// printf("pile a :\n");
// while (stack_a)
// {
// 	printf("%i ", (int)(size_t)stack_a->content);
// 	stack_a = stack_a->next;
// }
// printf("\n\npile b :\n");
// while (stack_b)
// {
// 	printf("%i ", (int)(size_t)stack_b->content);
// 	stack_b = stack_b->next;
// }

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
