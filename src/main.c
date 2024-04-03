/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:44 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/02 16:02:44 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int main(int argc, char **argv)
{
	t_element element;
	if(argc > 1)
	{
		init_struct(&element);
		check_and_store_arg(&element, argv);
		return(0);
	}
	else
	{
		printf(COLOR_RED"Error\n"TEXT_RESET);
		return(0);
	}
}
