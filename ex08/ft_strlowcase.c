/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casa <casa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:24:42 by jcongolo          #+#    #+#             */
/*   Updated: 2026/05/24 01:49:41 by casa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_strlowcase - Converte todas letras maiúsculas da string em minúsculas.
    Parâmetro:
        str - Ponteiro para a string a ser modificada
    Retorno:
        O próprio ponteiro str, com letras convertidas
*/
    #include <unistd.h>
    #include <stdio.h>
    
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

/*
    ft_strupcase — converte minúsculas em maiúsculas
*/
int ft_is_lowercase_char(char c)
{
    if (c < 'a' || c > 'z')
    {
        return(0);
    }
    return(1);
}
char    ft_to_uppercase_char(char c)
{
    if (ft_is_lowercase_char(c) == 1)
    {
        c = c - ('a' - 'A');
    }
    return(c);
}
char    *ft_strupcase(char *str)
{
    int i;

    if (!str || str[0] == '\0')
    {
        return(NULL);
    }
    i = 0;
    while (str[i])
    {
        str[i] = ft_to_uppercase_char(str[i]);
        i++;
    }
    return(str);
}
/*
    int main(void)
    {
        char str[] = "abcdezZ";
        
        printf("Before -> %s\n", str);
        ft_strupcase(str);
        printf("After -> %s\n", str);
        return(0);
    }
*/

/*
    ft_strtogglecase — troca maiúsculas ↔ minúsculas
*/
int ft_is_uppercase_char(char c)
{
    if (c < 'A' || c > 'Z')
    {
        return(0);
    }
    return(1);
}
char    ft_to_lowercase_char(char c)
{
    if (ft_is_uppercase_char(c) == 1)
    {
        c = c + ('a' - 'A');
    }
    return(c);
}
char    *ft_strtogglecase(char *str)
{
    int i;
    
    if (!str || str[0] == '\0')
    {
        return(NULL);
    }
    i = 0;
    while (str[i])
    {
        if (ft_is_lowercase_char(str[i]) == 1)
        {
            str[i] = ft_to_uppercase_char(str[i]);
        }
        else if (ft_is_uppercase_char(str[i]) == 1)
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
        char str[] = "abcDEF";
        
        printf("Before -> %s\n", str);
        ft_strtogglecase(str);
        printf("After -> %s\n", str);
        return(0);
    }
*/

/*
    ft_strcapitalize — primeira letr0a maiúscula, resto minúscula
*/
int ft_is_digit_char(char c)
{
    if (c < '0' || c > '9')
    {
        return(0);
    }
    return(1);
}
int ft_is_alphanumeric(char c)
{
    if ((ft_is_digit_char(c) == 1) || (ft_is_uppercase_char(c) == 1) || (ft_is_lowercase_char(c) == 1))
    {
        return(1);
    }
    return(0);
}
char    *ft_strcapitalize(char *str)
{
    int i;

    i = 0;
    if (!str || str[0] == '\0')
    {
        return(NULL);
    }
    if (ft_is_lowercase_char(str[i]) == 1)
    {
        str[i] = ft_to_uppercase_char(str[i]);
    }
    i++;
    while (str[i])
    {
        if ((ft_is_lowercase_char(str[i]) == 1) && (ft_is_alphanumeric(str[i - 1]) == 0))
        {
            str[i] = ft_to_uppercase_char(str[i]);
        }
        else if ((ft_is_uppercase_char(str[i]) == 1) && (ft_is_alphanumeric(str[i - 1]) == 1))
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
        char str[] = "12muLUmba\"wA tshiPaMBA";
        
        printf("Before -> %s\n", str);
        ft_strcapitalize(str);
        printf("After -> %s\n", str);
        return(0);
    }
    // !  OK
    // "  OK
    // #  OK
    // $  OK
    // %  OK
    // &  OK
    // '  OK
    // (  OK
    // )  OK
    // *  OK
    // +  OK
    // ,  OK
    // -  OK
    // .  OK
    // {  OK
    // }  OK
    // <  OK
    // |  OK
    // =  OK
    // >  OK
    // ~  OK
*/

/*
    ft_str_is_lowercase — verifica se todos os caracteres são minúsculos
*/
int ft_str_is_lowercase(char *str)
{
    int i;
    
    if (!str || str[0] == '\0')
    {
        return(0);
    }
    i = 0;
    while (str[i])
    {
        if (!ft_is_lowercase_char(str[i]))
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
        char str[] = "abcdef";
        
        if (ft_str_is_lowercase(str))
        {
            printf("YES lowercase\n");
        }
        else
        {
            printf("No is\n");
        }
        return(0);
    }
*/

/*
    ft_str_to_ascii_range — substitui caracteres fora do intervalo ASCII imprimível
*/
int ft_is_print_ascii_char(char c)
{
    if (c < ' ' || c > '~')
    {
        return(0);
    }
    return(1);
}
char    ft_replace_char(char c)
{
    if (!ft_is_print_ascii_char(c))
    {
        c = '*';
    }
    return(c);
}
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
/*
    int main(void)
    {
        char str[] = "9";
        
        printf("Before -> %s\n", str);
        ft_str_to_ascii_range(str);
        printf("After -> %s\n", str);
        return(0);
    }
*/