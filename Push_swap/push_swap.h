/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:15:57 by lnicoter          #+#    #+#             */
/*   Updated: 2023/05/23 10:19:31 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	last_a;
	int	last_b;
}		t_stack;

t_stack	*init(int ac, char **av);
void	fill_stack(int ac, char **av, int i, t_stack *stack);
void	three_sorting(t_stack *stack);
int		ft_sorter(t_stack *stack);
void	tmp_sort(int *tmp_stk, int dim);
int		check_sorted_desc(int *stack, int dim);
int		check_sorted_asc(int *stack, int dim);
int		when_push(t_stack *stack, int dim, int f);
void	print_error(int *stack, t_stack *stack_true);
void	find_dup(int *a, int dim, t_stack *stack);
void	ft_exit(t_stack *stack);
int		ft_isdigit(int c);
int		ft_atoi(char *str, int *stack, t_stack *stack_true);
void	quick_sort_3_a_b(t_stack *stack, int dim);
int		partition(int *pivot, int *stack, int dim);
int		sort_3_b(t_stack *stack, int dim);
int		quick_sort_b(t_stack *stack, int dim, int count_r);
int		quick_sort_a(t_stack *stack, int dim, int count_r);
int		ft_sa(t_stack *stack);
int		ft_sb(t_stack *stack);
int		ft_ss(t_stack *stack);
int		ft_pa(t_stack *stack);
int		ft_pb(t_stack *stack);
int		ft_ra(t_stack *stack);
int		ft_rb(t_stack *stack);
int		ft_rr(t_stack *stack);
int		ft_rra(t_stack *stack);
int		ft_rrb(t_stack *stack);
int		ft_rrr(t_stack *stack);

#endif
