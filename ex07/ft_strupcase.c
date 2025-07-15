/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:53:04 by jcongolo          #+#    #+#             */
/*   Updated: 2025/07/15 16:24:34 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_strupcase - Coloca todas letras da string em maiúsculo.
    Parâmetro:
        str - ponteiro para a string a ser modificada
    Retorno:
        Ponteiro original str, com letras minúsculas convertidas para maiúsculas
*/
char    *ft_strupcase(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - ('a' - 'A');
        }
        i++;
    }
    return(str);
}

/*
    #include <unistd.h>
    int main(void)
    {
        char    str[] = "abcd";
        int     i = 0;
        while (str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
        write(1, "\n", 1);
        
        ft_strupcase(str);
        
        i = 0;
        while (str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
        write(1, "\n", 1);
        return(0);
    }
*/