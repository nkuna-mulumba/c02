/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucongol <jucongol@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-14 18:23:20 by jucongol          #+#    #+#             */
/*   Updated: 2025-07-14 18:23:20 by jucongol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    int i;
    
    i = 0;
    while(src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    while(i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return(dest);
}
/*
    #include <unistd.h>
    int main(void)
    {
        char    dest[10];
        char    *src = "Hola mundo";
        int     n = 4;

        ft_strncpy(dest, src, n);//Hola

        int i = 0;
        while(dest[i])
        {
            write(1, &dest[i], 1);
            i++;
        }
        write(1, "\n", 1);
        return(0);
    }
*/