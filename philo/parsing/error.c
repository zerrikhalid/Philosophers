/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:46:44 by kzerri            #+#    #+#             */
/*   Updated: 2023/06/20 22:02:39 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	error(int key)
{
	if (key == 0)
	{
		printf("Bad Arguments: Your arguments should be between 1 and MAX_INT\n");
		return (1);
	}
	printf("your arguments should be as bellow :\n");
	printf("------------------------------------\n");
	printf("arg 1: <number_of_philosophers>\n");
	printf("arg 2: <time_to_die (in milliseconds)>\n");
	printf("arg 3: <time_to_eat (in milliseconds)>\n");
	printf("arg 4: <time_to_sleep (in milliseconds)>\n");
	printf("arg 5: <number_of_times_each_philosopher_must_eat (optional argument)>\n");
	return (1);
}
