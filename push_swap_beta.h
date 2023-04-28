/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_beta.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:29:01 by lnicoter          #+#    #+#             */
/*   Updated: 2023/04/26 02:41:08 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_BETA_H
#define PUSH_SWAP_BETA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>
#include "./libft/libft.h"

typedef struct s_node
{
	int				data; //dato effettivo del nodo
	struct s_node	*next;
}	t_node;

//utils
void	list_insert(t_node **first, int data);
void	list_display(t_node *p);
int		find_data_list(t_node **first, int find);
int		find_dup(t_node *a, int ac);
void	check_one_arg(char *argv, t_node **stack_a, int argc);
int		min_finder_a(t_node *stack_a);
int		max_finder_a(t_node *stack_a);
void	ft_error(char *type);
void	check_all(t_node **stack_a, int ac, char **av);
int		list_size(t_node *stack);
int		lets_try(t_node **stack_a, t_node **stack_b);

//sorting
void	three_sorting(t_node **stack_a);
void	sort_five_num(t_node **stack_a, t_node **stack_b);

//moves
void	ft_pb(t_node **psa, t_node **psb);
void	ft_pa(t_node **psa, t_node **psb);
void	ft_sa(t_node **stack_a);
void	ft_sb(t_node **stack_a);
void	ft_ss(t_node **stack_a, t_node **stack_b);
void	ft_ra(t_node **stack_a);
void	ft_rb(t_node **stack_b);
void	ft_rr(t_node **stack_a, t_node **stack_b);
void	ft_rra(t_node **stack_a);
void	ft_rrb(t_node **stack_b);
void	ft_rrr(t_node **stack_a, t_node **stack_b);
# endif
