/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casa <casa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:53:04 by jcongolo          #+#    #+#             */
/*   Updated: 2026/05/19 21:37:42 by casa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_strupcase - Coloca todas letras da string em maiúsculo.
    Parâmetro:
        str - ponteiro para a string a ser modificada
    Retorno:
        Ponteiro original str, com letras minúsculas convertidas para maiúsculas
*/
#include <unistd.h>
#include <stdio.h>

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

/*
    Implementar ft_strlowcase
    Converte todas as letras para minúsculas.
    Mesma lógica, mas invertida.
*/
int ft_is_uppercase_char(char c)
{
    if (c < 'A' || c > 'Z')
    {
        return(0);
    }
    return(1);
}
char    *ft_strlowcase(char *str)
{
    int i;

    if (!str || str[0] == '\0')
    {
        return(NULL);
    }
    
    i = 0;
    while (str[i])
    {
        if (ft_is_uppercase_char(str[i]) == 1)
        {
            str[i] = str[i] + ('a' - 'A');
        }
        i++;
    }
    return(str);
}
/*
    int main(void)
    {
        char str[] = "MULUMBA wa tshipamba";
        
        printf("Before: %s\n", str);
        ft_strlowcase(str);
        printf("After: %s\n", str);
        return(0);
    }
*/

/*
    Implementar ft_strcapitalize
    Primeira letra de cada palavra em maiúscula, restantes em minúscula.
    Excelente para treinar condições e estados.
*/
int ft_is_lowercase_char(char c)
{
    if (c < 'a' || c > 'z')
    {
        return(0);
    }
    return(1);
}
int ft_is_delimit(char c)
{
    if (c == ' ' || c == '\t')
    {
        return(1);
    }
    else
    {
        return(0);
    }    
}
char    ft_to_uppercase_char(char c)
{
    if (ft_is_lowercase_char(c) == 1)
    {
        c = c - ('a' - 'A');
    }
    return(c);
}
char    ft_to_lowercase_char(char c)
{
    if (ft_is_uppercase_char(c) == 1)
    {
        c = c + ('a' - 'A');
    }
    return(c);
}

char    *ft_strcapitalize(char *str)
{
    int i;

    if (!str || str[0] == '\0')
    {
        return(NULL);
    }
    i = 0;
    // Capitaliza primeira letra
    if (ft_is_lowercase_char(str[i]) == 1)
    {
        str[i] = ft_to_uppercase_char(str[i]);
    }
    i++;
    while (str[i])
    {
        //Capitaliza letra após delimitador
        if ((ft_is_delimit(str[i]) == 1) && (ft_is_lowercase_char(str[i + 1]) == 1))
        {
            str[i + 1] = ft_to_uppercase_char(str[ i + 1]);
        }
        //Converte maiúsculas internas para minúsculas
        else if ((ft_is_uppercase_char(str[i]) == 1) && (ft_is_delimit(str[i - 1]) == 0))
        {
            str[i] = ft_to_lowercase_char(str[i]);
        }
        i++;
    }
    return(str);
}
/*
    int main(void)
    {
        //Abcd->OK, abcd->OK, ABCD->OK, AbcD->, aBCd->OK
        //Ab cd->OK , aB CD->OK, AB cd->OK, ABC D->OK, a BCD->OK
        char str[] = "MuLUmba wA TshiPaMBA";
        printf("Before: %s\n", str);
        ft_strcapitalize(str);
        printf("After: %s\n", str);
        return(0);
    }
*/

/*
    Implementar ft_str_is_uppercase
    Retorna 1 se todos os caracteres forem 'A'–'Z'.
*/
int ft_str_is_uppercase(char *str)
{
    int i;

    if (!str || str[0] == '\0')
    {
        return(0);
    }
    i = 0;
    while (str[i])
    {
        if (ft_is_uppercase_char(str[i]) == 0)
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
        char *str = "";
        if (ft_str_is_uppercase(str) == 1)
        {
            printf("IS UPPERCASE_STR.\n");
        }
        else
        {
            printf("NO IS.\n");
        }
        return(0);
    }
*/

/*
    Implementar ft_str_togglecase
    Troca maiúsculas ↔ minúsculas.
    Treina lógica condicional dupla.
*/
//Implementaçao 1:
char    *ft_str_togglecase(char *str)
{
    int i;

    if (!str || str[0] == '\0')
    {
        return(NULL);
    }
    i = 0;
    while (str[i])
    {
        if (ft_is_uppercase_char(str[i]) == 1)
        {
            str[i] = ft_to_lowercase_char(str[i]);
        }
        else if (ft_is_lowercase_char(str[i]) == 1)
        {
            str[i] = ft_to_uppercase_char(str[i]);
        }
        i++;
    }
    return(str);
}
//Implementaçao 2:
/*
    void    ft_str_togglecase(char *str)
    {
        int i;

        if (!str || str[0] == '\0')
        {
            return;
        }
        i = 0;
        while (str[i])
        {
            if (ft_is_uppercase_char(str[i]) == 1)
            {
                str[i] = ft_to_lowercase_char(str[i]);
            }
            else if (ft_is_lowercase_char(str[i]) == 1)
            {
                str[i] = ft_to_uppercase_char(str[i]);
            }
            i++;
        }
    }
*/
/*
    int main(void)
    {
        char str[] = "MULUMBA wa TSHIpambaBA";
        printf("Before: %s\n", str);
        ft_str_togglecase(str);
        printf("After: %s\n", str);
        return(0);
    }
*/

/*
    Implementar ft_str_to_ascii_range
    Substitui qualquer caractere fora de ' '–'~' por '?'.
    Treina validação de intervalos ASCII.
*/
int ft_is_ascii_char(char c)
{
    if (c < ' ' || c > '~')
    {
        return(0);
    }
    return(1);
}
char    ft_replace_char(char c)
{
    if (ft_is_ascii_char(c) == 0)
    {
        c = '?';
    }
    return(c);
}
//IMPELEMNTAÇAO 1
char    *ft_str_to_ascii_range(char *str)
{
    int i;
    
    if (!str || str[0] == '\0')
    {
        return(NULL);
    }
    i = 0;
    while (str[i])
    {
        str[i] = ft_replace_char(str[i]);
        i++;
    }
    return(str);
}
//IMPELEMNTAÇAO 2
/*
    void    ft_str_to_ascii_range(char *str)
    {
        int i;
        
        if (!str || str[0] == '\0')
        {
            return;
        }
        i = 0;
        while (str[i])
        {
            str[i] = ft_replace_char(str[i]);
            i++;
        }
    }
*/
/*
    int main(void)
    {
        char str[] = "MULUMBA wa TSHIpambaBA";
        printf("Before: %s\n", str);
        ft_str_to_ascii_range(str);
        printf("After: %s\n", str);
        return(0);
    }
*/