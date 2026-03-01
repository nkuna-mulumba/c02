/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casa <casa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:40:20 by jcongolo          #+#    #+#             */
/*   Updated: 2026/03/02 00:15:28 by casa             ###   ########.fr       */
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
#include <stdio.h>
#include <unistd.h>

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

/*
    ft_str_is_alpha
    Cria uma função que retorna 1 se a string contiver apenas letras (A–Z, a–z).
    Retorna 0 se houver qualquer caractere que não seja uma letra.
*/
int ft_is_char_lower(char c)
{
    if (c < 'a' || c > 'z')
    {
        return(0);
    }
    return(1);
}
int ft_is_char_upper(char c)
{
    if (c < 'A' || c > 'Z')
    {
        return(0);
    }
    return(1);
}
int ft_is_terminator(char c)
{
    if (c != '\0')
    {
        return(0);
    }
    return(1);
}
int     ft_str_is_alpha(char *str)
{
    int i;

    if (!str || ft_is_terminator(str[0]))
    {
        return(0);
    }
    
    i = 0;
    while (str[i])
    {
        if (!ft_is_char_lower(str[i]) && !ft_is_char_upper(str[i]))
        {
            return(0);
        }
        i++;
    }
    return(1);
}
/*
    int main(void)
    {
        char    *str = "aA";
        
        if (ft_str_is_alpha(str) == 1)
        {
            printf("LETTER\n");
        }
        else
        {
            printf("NO IS\n");
        }
        return(0);
    }
*/

/*
    ft_str_is_lowercase
        Cria uma função que retorna 1 se a string contiver apenas letras minúsculas (a–z).
        Retorna 0 se houver qualquer caractere fora desse intervalo.
*/
int    ft_str_is_lowercase(char *str)
{
    int i;
    
    if (!str || ft_is_terminator(str[0]))
    {
        return(0);
    }
    i = 0;
    while (str[i])
    {
        if (!ft_is_char_lower(str[i]))
        {
            return(0);
        }
        i++;
    }
    return(1);
}
/*
    int main(void)
    {
        char    *str = "azG";
        
        if (ft_str_is_lowercase(str) == 1)
        {
            printf("LOWER\n");
        }
        else
        {
            printf("NO IS\n");
        }
        return(0);
    }
*/

/*
    ft_str_is_uppercase
        Cria uma função que retorna 1 se a string contiver apenas letras maiúsculas (A–Z).
        Retorna 0 se houver qualquer caractere fora desse intervalo.
*/
int    ft_str_is_uppercase(char *str)
{
    int i;
    
    if (!str || ft_is_terminator(str[0]))
    {
        return(0);
    }
    i = 0;
    while (str[i])
    {
        if (!ft_is_char_upper(str[i]))
        {
            return(0);
        }
        i++;
    }
    return(1);
}
/*
    int main(void)
    {
        char    *str = "ZAG";
        
        if (ft_str_is_uppercase(str) == 1)
        {
            printf("UPPER STR\n");
        }
        else
        {
            printf("NO IS\n");
        }
        return(0);
    }
*/

/*
    ft_str_is_alnum
        Cria uma função que retorna 1 se a string contiver apenas letras ou dígitos.
        Retorna 0 se houver qualquer caractere que não seja alfanumérico.
*/
int ft_is_char_digit(char c)
{
    if (c < '0' || c > '9')
    {
        return(0);
    }
    return(1);
}
int    ft_str_is_alnum(char *str)
{
    int i;
    
    if (!str || ft_is_terminator(str[0]))
    {
        return(0);
    }
    i = 0;
    while (str[i])
    {
        if (!ft_is_char_upper(str[i]) &&
            !ft_is_char_lower(str[i]) &&
            !ft_is_char_digit(str[i]))
        {
            return(0);
        }
        i++;
    }
    return(1);
}

/*
    int main(void)
    {
        char    *str = "ZAGabc 09";
        
        if (ft_str_is_alnum(str) == 1)
        {
            printf("ALNUM\n");
        }
        else
        {
            printf("NO IS\n");
        }
        return(0);
    }
*/

/*
    ft_str_is_hex
        Cria uma função que retorna 1 se a string contiver apenas caracteres hexadecimais (0–9, A–F, a–f).
        Retorna 0 se houver qualquer caractere fora do conjunto hexadecimal.
*/
int ft_char_hex_lower(char c)
{
    if (c < 'a' || c > 'f')
    {
        return(0);
    }
    return(1);
}
int ft_char_hex_upper(char c)
{
    if (c < 'A' || c > 'F')
    {
        return(0);
    }
    return(1);
}
int     ft_str_is_hex(char *str)
{
    int i;

    if (!str || ft_is_terminator(str[0]))
    {
        return(0);
    }
    
    i = 0;
    while (str[i])
    {
        if (!ft_is_char_digit(str[i]) &&
            !ft_char_hex_upper(str[i]) &&
            !ft_char_hex_lower(str[i]))
        {
            return(0);
        }
        i++;
    }
    return(1);
}

/*
    int main(void)
    {
        char    *str = "Aabc09";
        
        if (ft_str_is_hex(str) == 1)
        {
            printf("HEX-DECIMAL\n");
        }
        else
        {
            printf("NO IS\n");
        }
        return(0);
    }
*/