/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casa <casa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:22:16 by jcongolo          #+#    #+#             */
/*   Updated: 2026/03/21 21:53:41 by casa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_str_is_uppercase - Verifica se string contém apenas letras maiúsculas.
    Parâmetro:
        str - ponteiro para a string que será analisada
    Retorno:
        1 → se todos caracteres forem letras maiúsculas ou se string estiver vazia
        0 → se houver qualquer caractere que não seja uma letra maiúscula
    Observações:
        - A função assume que 'str' é um ponteiro válido
        - Não utiliza nenhuma função externa
*/
#include <stdio.h>
#include <unistd.h>

int ft_str_is_uppercase(char *str)
{
    int i;

    i = 0;
    //Retorna 1 se string estiver vazia
    if (str[i] == '\0')
    {
        return(1);//String vazia → retorna 1
    }
    //Percorre string caractere por caractere
    while (str[i])
    {
        //Verifica se caractere está no intervalo de letras maiúsculas
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            i++; //Avança para próximo caractere
        }
        else
        {
            return(0);//Se não for maiúsculo, retorna 0 imediatamente
        }
    }
    return(1);//Todos caracteres são maiúsculos
}

/*
    int main(void)
    {
        char    *str = "ABC";
        int     i = 0;
        while (str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
        write(1, "\n", 1);
        
        int return_function = ft_str_is_uppercase(str);
        printf("Value return of function ->[%d]\n", return_function);
        return(0);
    }
*/

/*
    ft_str_is_lowercase
    Retorna 1 se a string tiver apenas 'a' a 'z'.
*/
int ft_is_lower_char(char c)
{
    if (c < 'a' || c > 'z')
    {
        return(0);
    }
    return(1);
}
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
        if (ft_is_lower_char(str[i]) == 0)
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
        char *test = "Abcd";
        if (ft_str_is_lowercase(test) == 1)
        {
            printf("IS LOWER STRING\n");
        }
        else
        {
            printf("no..\n");
        }   
        return(0);
    }
*/

/*
    ft_str_is_alpha
    Retorna 1 se a string tiver apenas letras (maiúsculas ou minúsculas).
*/
int ft_is_alpha_char(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
int    ft_str_is_alpha(char *str)
{
    int i;
    if (!str || str[0] == '\0')
    {
        return(0);
    }
    i = 0;
    while (str[i])
    {
        if (ft_is_alpha_char(str[i]) == 0)
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
        char *test = "[abcAA\\Zz";
        if (ft_str_is_alpha(test) == 1)
        {
            printf("IS ALPHA STRING\n");
        }
        else
        {
            printf("no..\n");
        }   
        return(0);
    }
*/

/*
    ft_str_is_numeric
    Retorna 1 se a string tiver apenas dígitos '0' a '9'.
*/
int ft_is_digit_char(char c)
{
    if (c < '0' || c > '9')
    {
        return(0);
    }
    return(1);
}
int    ft_str_is_numeric(char *str)
{
    int i;
    
    if (!str || str[0] == '\0')
    {
        return(0);
    }
    i = 0;
    while (str[i])
    {
        if (ft_is_digit_char(str[i]) == 0)
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
        char *test = "19";
        if (ft_str_is_numeric(test) == 1)
        {
            printf("IS ALPHA NUMERIC\n");
        }
        else
        {
            printf("no..\n");
        }   
        return(0);
    }
*/

/*
    ft_str_is_printable
    Retorna 1 se todos os caracteres forem imprimíveis (ASCII 32 a 126).
*/
int ft_is_printabel_char(char c)
{
    if (c < ' ' || c > '~')
    {
        return(0);
    }
    return(1);
}
int    ft_str_is_printable(char *str)
{
    int i;

    if (!str || str[0] == '\0')
    {
        return(0);
    }
    
    i = 0;
    while (str[i])
    {
        if (ft_is_printabel_char(str[i]) == 0)
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
        char *test = "\0";
        if (ft_str_is_printable(test) == 1)
        {
            printf("IS PRINTABLE\n");
        }
        else
        {
            printf("no..\n");
        }   
        return(0);
    }
*/

/*
    ft_str_is_hexadecimal
    Retorna 1 se todos os caracteres forem válidos em hexadecimal (0–9, A–F, a–f).
*/
int ft_is_hexadecimal_char(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
int    ft_str_is_hexadecimal(char *str)
{
    int i;
    
    if (!str || str[0] == '\0')
    {
        return(0);
    }
    
    i = 0;
    while (str[i])
    {
        if (ft_is_hexadecimal_char(str[i]) == 0)
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
        char *test = "A";
        if (ft_str_is_hexadecimal(test) == 1)
        {
            printf("IS HEXADECIMAL\n");
        }
        else
        {
            printf("no..\n");
        }   
        return(0);
    }
*/