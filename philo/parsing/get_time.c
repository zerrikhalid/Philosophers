/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 02:31:39 by kzerri            #+#    #+#             */
/*   Updated: 2023/06/22 21:55:47 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned long	current_time(void)
{
	unsigned long long	initial_time_ms;
	struct timeval		initial_time;

	gettimeofday(&initial_time, NULL);
	initial_time_ms = (initial_time.tv_sec * 1000) + \
		(initial_time.tv_usec / 1000);
	return (initial_time_ms);
}
