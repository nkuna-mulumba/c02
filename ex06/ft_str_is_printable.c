/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:32:32 by jcongolo          #+#    #+#             */
/*   Updated: 2025/07/15 15:45:34 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_str_is_printable - Verifica se a string contém apenas caracteres imprimíveis.

    Parâmetro:
        str - ponteiro para a string a ser analisada

    Retorno:
        1 → se todos os caracteres estiverem no intervalo imprimível (ASCII 32 a 126)
        0 → se houver qualquer caractere fora desse intervalo
*/
int ft_str_is_printable(char *str)
{
    int i;
    
    i = 0;
    //Retorna 1 se string for vazia
    if (str[i] == '\0')
    {
        return(1);
    }
    //Percorre cada caractere da string
    while (str[i])
    {
        //Verifica caracter está no intervalo de caracteres imprimíveis
        if (str[i] >= ' ' && str[i] <= '~')
        {
            i++;//Avança
        }
        //caso nao, retorna (0) directamente
        else
        {
            return(0);
        }
    }
    //Todos caracteres são imprimíveis
    return(1);
}


/*
    #include <stdio.h>
    #include <unistd.h>
    int main(void)
    {
        char    *str = ".?-a [1";
        int     i = 0;
        while (str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
        write(1, "\n", 1);
        
        int return_function = ft_str_is_printable(str);
        printf("Value return of function ->[%d]\n", return_function);
        return(0);
    }
*/