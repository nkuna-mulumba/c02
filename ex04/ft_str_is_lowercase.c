/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:00:07 by jcongolo          #+#    #+#             */
/*   Updated: 2025/07/15 15:19:52 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_str_is_lowercase - Verifica se string contém apenas letras minúsculas.
    Parâmetro:
        str - ponteiro para a string que será verificada.
    Retorno:
        1 → se todos caracteres forem minúsculos ou se a string for vazia
        0 → se houver algum caractere que não seja uma letra minúscula
*/
int ft_str_is_lowercase(char *str)
{
    int i;

    i = 0;
    //Verifica se string é vazia
    if (str[i] == '\0')
    {
        return(1);
    }
    //Percorre string caractere por caractere
    while (str[i])
    {
        //Se caractere está no intervalo 'a'–'z' avança
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            i++;
        }
        //Se caractere está fora do intervalo 'a'–'z' return (0)
        else
        {
            return(0);
        }
    }
    //Todos os caracteres foram minúsculos
    return(1);
}

/*
    #include <stdio.h>
    #include <unistd.h>
    int main(void)
    {
        char    *str = "abc";
        int     i = 0;
        while (str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
        write(1, "\n", 1);
        
        int return_function = ft_str_is_lowercase(str);
        printf("Value return of function ->[%d]\n", return_function);
        return(0);
    }
*/