/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:51:37 by kzerri            #+#    #+#             */
/*   Updated: 2023/06/20 22:24:27 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    ft_sleep(unsigned long time)
{
	unsigned long start;

	start = current_time();
	while(current_time() - start < time)
		usleep(50);
}
