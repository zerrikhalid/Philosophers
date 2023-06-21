/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:38:06 by kzerri            #+#    #+#             */
/*   Updated: 2023/06/21 17:04:36 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_print(t_philo *ph, char *msg, int flag)
{
	t_data *data;

	data = ph->data;
	pthread_mutex_lock(&data->print);
	printf("%lu  %d %s\n", current_time()  - data->start_time, ph->philo_id + 1, msg);
	if(!flag)
		pthread_mutex_unlock(&data->print);
}
