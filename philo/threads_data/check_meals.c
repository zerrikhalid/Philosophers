/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_meals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:39:40 by kzerri            #+#    #+#             */
/*   Updated: 2023/06/20 21:44:09 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_meals(t_philo *philos)
{
	t_data *data;
	int i;
	int count;

	data = philos->data;
	i = -1;
	count = 0;
	while (++i < data->nbr_philos)
	{
		pthread_mutex_lock(&data->meal);
		if (philos[i].nbr_of_meals >= data->nbr_t_philo_m_eat)
			count++;
		pthread_mutex_unlock(&data->meal);
	}
	if (count == data->nbr_philos)
		return (1);
	return (0);
}
