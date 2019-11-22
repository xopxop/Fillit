/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:22:34 by dthan             #+#    #+#             */
/*   Updated: 2019/11/22 19:26:19 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int x)
{
	int start;
	int mid;
	int end;
	int ans;

	start = 1;
	end = x;
    if (x == 0 || x == 1)  
       return (x);    
    while (start <= end)  
    {         
        mid = (start + end) / 2; 
        if (mid * mid == x) 
            return (mid); 
        if (mid * mid < x)  
        { 
            start = mid + 1; 
            ans = mid; 
        }  
            end = mid - 1;         
    } 
    return (ans); 
}
