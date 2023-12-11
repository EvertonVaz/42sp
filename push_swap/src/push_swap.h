/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:07:03 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/11 16:27:46 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "unistd.h"
# include "stdlib.h"


# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	int				current_pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	stack_fill(t_stack *stack);
void	stack_init(t_stack **stack_a, char **argv);
int		stack_len(t_stack *lst);
t_stack	*find_last_node(t_stack *head);
int		swap(t_stack **head);
int		push_move(t_stack **src, t_stack **dest);
int		rotate(t_stack **stack);
int		reverse_rotate(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	free_list(t_stack *head);
void	find_index(t_stack **stack_a, char **argv);
void	find_current_pos(t_stack *stack);
void	find_target_pos(t_stack **stack_a, t_stack **stack_b);
void	find_cost(t_stack *stack_a, t_stack *stack_b);
void	calculate_cost(int len, t_stack *stack, char cost_name, int current_pos);
void	bubble_sort(char **argv);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
void	sort_3(t_stack **stack);
int		total_cost(t_stack *stack);
t_stack	*get_min_cost(t_stack *stack);
void	moves_ra(t_stack **stack, int cost);
void	moves_rb(t_stack **stack, int cost);
void	moves_rrr(t_stack **stack_a, t_stack **stack_b);
void	send_to_a(t_stack **stack_b, t_stack **stack_a);
void	push_swap(t_stack **stack_a, t_stack **stack_b);

#endif