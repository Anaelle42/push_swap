/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:31:51 by ahenault          #+#    #+#             */
/*   Updated: 2024/02/22 20:26:54 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

// operations
void				swap_a(t_list **a);
void				swap_b(t_list **a);
void				swap_all(t_list **a, t_list **b);
void				rr_a(t_list **a);
void				rr_b(t_list **a);
void				rr_all(t_list **a, t_list **b);
void				rotate_a(t_list **a);
void				rotate_b(t_list **a);
void				rotate_all(t_list **a, t_list **b);
void				push_to_b(t_list **a, t_list **b);
void				push_to_a(t_list **a, t_list **b);

// lst
t_list				*ft_lstnew(int content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_lstclear(t_list **lst);

// check
int					parse_parameters(int argc, char **argv, t_list **stack_a);

// algo
void				algo(t_list **a, t_list **b);
int					nbr_min(t_list *a);
int					nbr_max(t_list *a);
int					position(t_list *a, int nb);
int					find_position_in_b(t_list *a, int nb);
int					find_position_in_a(t_list *a, int nb);

void				push_b(t_list **stack_a, t_list **stack_b);
void				push_a(t_list **stack_a, t_list **stack_b);

// nb de coups
int					count_moves_rarb(t_list *a, t_list *b, int nb, int stack);
int					count_moves_rrarrb(t_list *a, t_list *b, int nb, int stack);
int					count_moves_rrarb(t_list *a, t_list *b, int nb, int stack);
int					cmb_rarrb(t_list *a, t_list *b, int nb, int who);

// execute
int					fais_rrarrb(t_list **a, t_list **b, int n, int who);
int					fais_rarb(t_list **a, t_list **b, int n, int who);
int					fais_rrarb(t_list **a, t_list **b, int n, int who);
int					fais_rarrb(t_list **a, t_list **b, int n, int who);
#endif
