/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:31:54 by jcongolo          #+#    #+#             */
/*   Updated: 2025/07/15 17:33:38 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_strcapitalize - Coloca primeira letra de cada palavra em maiúscula
                      e o restante em minúscula.
    Uma palavra é definida como uma sequência de caracteres alfanuméricos.
    Parâmetro:
        str - ponteiro para a string a ser modificada
    Retorno:
        Ponteiro original str, com capitalização aplicada
*/
char    *ft_strcapitalize(char *str)
{
    int i;
    int new_word;

    i = 0;
    new_word = 1;
    while (str[i])
    {
        //Se for letra minúscula
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (new_word == 1)
            {
                str[i] = str[i] - ('a' - 'A');
            }
            new_word = 0;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') //Se for letra maiúscula
        {
            if (new_word == 0)
            {
                str[i] = str[i] + ('a' - 'A');
            }
            new_word = 0;
        }
        else if (str[i] >= '0' && str[i] <= '9')//Se for número
        {
            new_word = 0;
        }
        else//Qualquer símbolo inicia nova palavra
        {
            new_word = 1;
        }
        i++;
    }
    return(str);
}


/*
    #include <unistd.h>
    int main(void)
    {
        char    str[] = "eu que";//EU QUE; eU qUe; EU que; eu QuE;
        int     i = 0;
        while (str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
        write(1, "\n", 1);
        
        ft_strcapitalize(str);
        
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
