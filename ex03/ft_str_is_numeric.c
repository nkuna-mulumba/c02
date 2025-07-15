/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:40:20 by jcongolo          #+#    #+#             */
/*   Updated: 2025/07/15 14:58:25 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_str_is_numeric - Verifica se string contém apenas dígitos numéricos.
    Parâmetro:
        str - ponteiro para a string a ser verificada
    Retorno:
        1 → se string for vazia ou se todos caracteres estiverem entre '0' e '9'
        0 → se houver qualquer caractere que não seja um dígito numérico
*/
int ft_str_is_numeric(char *str)
{
    int i;

    i = 0;
    //Se a string for vazia (primeiro caractere é '\0'), retorna 1
    if (str[i] == '\0')
    {
        return(1);
    }
    //Percorre cada caractere da string
    while (str[i])
    {
        //Se caractere estiver entre '0' e '9', continua
        if (str[i] >= '0' && str[i] <= '9')
        {
            i++;
        }
        //Se caractere não estiver entre '0' e '9', retorna 0
        else
        {
            return(0);
        }
    }
    //Todos caracteres são numéricos, retorna 1
    return(1);
}

/*
    #include <stdio.h>
    #include <unistd.h>
    int main(void)
    {
        char    *str = "";
        int     i = 0;
        while (str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
        write(1, "\n", 1);
        
        int return_function = ft_str_is_numeric(str);
        printf("Value return of function ->[%d]\n", return_function);
        return(0);
    }
*/