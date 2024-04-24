/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:54 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/24 16:15:38 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

//libairies
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# include "../libs/Libft/libft.h"

// Colors
# define COLOR_BLACK "\033[0;30m" // Black
# define COLOR_RED "\033[0;91m" // Red
# define COLOR_GREEN "\033[0;32m" // Green
# define COLOR_YELLOW "\033[0;33m" // Yellow
# define COLOR_BLUE "\033[0;34m" // Blue
# define COLOR_PURPLE "\033[0;35m" // Purple
# define COLOR_CYAN "\033[0;36m" // Cyan
# define COLOR_WHITE "\033[0m" // White
# define TEXT_BOLD "\033[1m" // Bold text
# define TEXT_RESET "\033[0m" // Reset text attributes

# define PUSH_SWAP_H
# define TRUE		1
# define FALSE		0
# define SUCCESS	0
# define FAIL		1

typedef struct s_element
{
    int value;
	int	simplified_value;
    struct s_element *next;
    struct s_element *prev;
} t_element;


// parsing
void	create_stack(t_element **stack_a, t_element *temp, char **argv, int i);
int	    init_stack(t_element **stack_a, int argc, char **argv, int stack_len);
void    store_string_arg(char **argv, t_element **stack_a);
void    store_tab_arg(char **argv, t_element **stack_a);
void	simplify_value(t_element **stack_a, int stack_len);

//utils
void	is_int(char **argv, int i);
int	    is_sorted(t_element **stack_a, int stack_len);
int		check_for_duplicates(t_element **stack);
int	    get_stack_len(t_element **stack_a);

// Opérations
void	swap(t_element **tail, char instruction);
void	rotate(t_element **stack, char instruction);
void	reverse_rotate(t_element **stack, char instruction);
void	push(t_element **src, t_element **dst, char instruction);
void	dst_not_empty(t_element **dst, t_element *node);
void    swap_both(t_element **stack_a, t_element **stack_b);
void    rotate_both(t_element **stack_a, t_element **stack_b);
void    reverse_rotate_both(t_element **stack_a, t_element **stack_b);

// little sort
void	little_sort(t_element *stack, int argc);
void	find_min_and_pos(int *min1, int *min2, int *position, t_element *stack_a);
void	three_int_sort(t_element *stack);
void	four_int_sort(t_element *stack_a);
void	five_int_sort(t_element *stack);

// radix sort
int find_largest_bit(t_element **stack_a, int stack_len);
// int rotate_count(t_element **stack_a, int bit_position, int stack_len);
void radix_sort(t_element **stack_a, int stack_len);

// Opérations
void	swap(t_element **tail, char instruction);
void	rotate(t_element **stack, char instruction);
void	reverse_rotate(t_element **stack, char instruction);
void	push(t_element **src, t_element **dst, char instruction);
void	dst_not_empty(t_element **dst, t_element *node);

// Colors
# define COLOR_BLACK "\033[0;30m" // Black
# define COLOR_RED "\033[0;91m" // Red
# define COLOR_GREEN "\033[0;32m" // Green
# define COLOR_YELLOW "\033[0;33m" // Yellow
# define COLOR_BLUE "\033[0;34m" // Blue
# define COLOR_PURPLE "\033[0;35m" // Purple
# define COLOR_CYAN "\033[0;36m" // Cyan
# define COLOR_WHITE "\033[0m" // White
# define TEXT_BOLD "\033[1m" // Bold text
# define TEXT_RESET "\033[0m" // Reset text attributes

#endif