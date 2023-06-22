/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:45:20 by kzerri            #+#    #+#             */
/*   Updated: 2023/06/22 22:00:39 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	check_death(t_philo *philos)
{
	int		i;
	t_data	*data;

	data = philos->data;
	while (1)
	{
		i = -1;
		while (++i < data->nbr_philos)
		{
			pthread_mutex_lock(&data->meal);
			if (current_time() - philos[i].last_meals >= \
				(unsigned long)data->time_to_die)
			{
				ft_print(philos + i, "has died", 1);
				return ;
			}
			pthread_mutex_unlock(&data->meal);
		}
		if (data->nbr_t_philo_m_eat != -1 && check_meals(philos))
			break ;
	}
}
