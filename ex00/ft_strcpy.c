/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:59:47 by jucongol          #+#    #+#             */
/*   Updated: 2025/07/16 13:01:15 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_strcpy - Reimplementação da função strcpy.
    Copia a string 'src' para a memória apontada por 'dest',
    incluindo o caractere nulo de terminação.

    Retorna: ponteiro original de 'dest'
*/
#include <stddef.h>//Header do valor NULL se vaz a usar

char    *ft_strcpy(char *dest, char *src)
{
    int i;

    // Verifica se os ponteiros são válidos
    if(!dest || !src)
    {
        return(NULL);
    }

    i = 0;
    // Copia cada caractere de 'src' para 'dest'
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    // Adiciona o terminador nulo no final de 'dest'
    dest[i] = '\0';
    // Retorna o ponteiro para o início da string copiada
    return(dest);
}

/*
    #include <unistd.h>
    int main(void)
    {
        char    *src = "Hola mundo";
        char    dst [10];
        int     i = 0;
        write(1, "dst antes:-> ", 14);
        while(dst[i])
        {
            write(1, &dst[i], 1);
            i++;
        }
        write(1, "\n", 1);
        
        ft_strcpy(dst, src);
        write(1, "dst depois:-> ", 15);
        i = 0;
        while(dst[i])
        {
            write(1, &dst[i], 1);
            i++;
        }
        write(1, "\n", 1);
        return(0);
    }
*/