/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:24:42 by jcongolo          #+#    #+#             */
/*   Updated: 2025/07/15 16:30:22 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_strlowcase - Converte todas letras maiúsculas da string em minúsculas.
    Parâmetro:
        str - Ponteiro para a string a ser modificada
    Retorno:
        O próprio ponteiro str, com letras convertidas
*/
char    *ft_strlowcase(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        //Verifica se caractere é uma letra maiúscula
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A');//Converte para minúscula
        }
        i++;
    }
    return(str);
}

/*
    #include <unistd.h>
    int main(void)
    {
        char    str[] = "ABCD";
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