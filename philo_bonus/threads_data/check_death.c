/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:45:20 by kzerri            #+#    #+#             */
/*   Updated: 2023/06/22 22:21:39 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	check_death(t_philo *philos)
{
	t_data	*data;

	data = philos->data;
	while (1)
	{
		sem_wait(data->meal);
		if (current_time() - philos->last_meals >= \
			(unsigned long)data->time_to_die)
		{
			ft_print(philos, "has died", 1);
			return ;
		}
		if (data->nbr_t_philo_m_eat != -1 && \
			philos->nbr_of_meals > data->nbr_t_philo_m_eat)
			break ;
		sem_post(data->meal);
	}
}
