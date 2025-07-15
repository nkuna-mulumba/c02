/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:27:55 by nkuna             #+#    #+#             */
/*   Updated: 2025/07/15 14:46:04 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_str_is_alpha - Verifica se string contém apenas caracteres alfabéticos.
    Parâmetro:
        str - Ponteiro para a string que será analisada.
    Retorno:
        1 → se string for vazia ou contiver apenas letras (maiúsculas ou minúsculas)
        0 → se contiver qualquer outro tipo de caractere (números, símbolos, espaço, etc.)
    Observação:
        A função assume que 'str' é um ponteiro válido (não trata o caso de str == NULL).
*/
int	ft_str_is_alpha(char *str)
{
    int i;

    i = 0;
    //Verifica se string é vazia (primeiro caractere é '\0')
    if (str[i] == '\0')
    {
        return(1);//Uma string vazia é considerada válida
    }
    //Percorre cada caractere da string
    while (str[i])
    {
        //Se for letra minúscula (entre 'a' e 'z'), continua
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            i++;
        }
        //Se for letra maiúscula (entre 'A' e 'Z'), continua
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            i++;
        }
        //Se não for letra, retorna 0 (caractere inválido)
        else
        {
            return(0);
        }
    }
    //Se todos os caracteres forem letras, retorna 1
    return(1);	
}

/*
    #include <stdio.h>
    #include <unistd.h>
    int main(void)
    {
        char    *str = "abcd";
        int     i = 0;
        while (str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
        write(1, "\n", 1);
        
        int     value_fuction = ft_str_is_alpha(str);
        printf("Return of function: ->[%d]\n", value_fuction);
        
        return(0);
    }
*/