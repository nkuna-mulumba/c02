/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casa <casa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:00:07 by jcongolo          #+#    #+#             */
/*   Updated: 2026/03/08 23:06:43 by casa             ###   ########.fr       */
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
#include <stdio.h>
#include <unistd.h>
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

/*
   ft_str_is_vowel
   Cria uma função que retorna 1 se a string contiver apenas vogais (a, e, i, o, u).
   Retorna 0 se houver qualquer caractere que não seja vogal.
*/
int ft_char_vowel_lower(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
int    ft_str_is_vowel(char *str)
{
    int i;
    
    if (!str || str[0] == '\0')
    {
        return(0);
    }
    i = 0;
    while (str[i])
    {
        if(ft_char_vowel_lower(str[i]) == 0)
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
        char    *str = "v";

        if (ft_str_is_vowel(str) == 1)
        {
            printf("Yes is vowel.\n");
        }
        else
        {
            printf("NOOOO\n");
        }   
        return(0);
    }
*/

/*
   ft_str_is_binary
   Cria uma função que retorna 1 se a string contiver apenas os caracteres '0' e '1'.
   Retorna 0 se houver qualquer caractere fora desse conjunto.
*/
/*
    O sistema binário usa apenas: 0,1
    Binário = dígitos de 0 até 1
    (apenas dois símbolos → por isso chama‑se base 2)
*/
int ft_is_binary_digit(char c)
{
    if (c == '0' || c == '1')
    {
        return(1);
    }
    else
    {
        return(0);
    }
    
}
int    ft_str_is_binary(char *binary)
{
    int i;

    if (!binary || binary[0] == '\0')
    {
        return(0);
    }  
    i = 0;
    while (binary[i])
    {
        if (ft_is_binary_digit(binary[i]) == 0)
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
        char *bin = "@A";
        if (ft_str_is_binary(bin) == 1)
        {
            printf("YES IS BINARY\n");
        }
        else
        {
            printf("no is binary\n");
        }
        return(0);
    }
*/

/*
   ft_str_is_octal
   Cria uma função que retorna 1 se a string contiver apenas dígitos octais (0–7).
   Retorna 0 se houver qualquer caractere fora desse intervalo.
*/
/*
    O sistema octal usa: 0, 1, 2, 3, 4, 5, 6, 7
    Octal = dígitos de 0 até 7
    (oito símbolos → por isso chama‑se base 8)
*/
int ft_is_octal_digit(char c)
{
    if (c >= '0' && c <= '7')
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
int    ft_str_is_octal(char *octals)
{
    int i;

    if (!octals || octals[0] == '\0')
    {
        return(0);
    }
    i = 0;
    while (octals[i])
    {
        if (ft_is_octal_digit(octals[i]) == 0)
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
        char *oct = "019";
        
        if (ft_str_is_octal(oct) == 1)
        {
            printf("OK IS OCTAl DIGIT\n");
        }
        else
        {
            printf("no is\n");
        }    
        return(0);
    }
*/

/*
   ft_str_is_space
   Cria uma função que retorna 1 se a string contiver apenas espaços (' ').
   Retorna 0 se houver qualquer caractere diferente de espaço.
*/
int ft_is_space_digit(char c)
{
    if (c < ' ' || c > ' ')
    {
        return(0);
    }
    return(1);
}
int    ft_str_is_space(char *space)
{
    int i;
    
    if (!space || space[0] == '\0')
    {
        return(0);
    }
    i = 0;
    while (space[i])
    {
        if (ft_is_space_digit(space[i]) == 0)
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
        char *space = " ";
        
        if (ft_str_is_space(space) == 1)
        {
            printf("OK IS SPACE DIGIT\n");
        }
        else
        {
            printf("no is\n");
        }    
        return(0);
    }
*/

/*
   ft_str_is_ascii
   Cria uma função que retorna 1 se a string contiver apenas caracteres ASCII (0–127).
   Retorna 0 se houver qualquer caractere fora desse intervalo.
*/
int ft_is_ascii(char c)
{
    if (c < 0 || c > 127)
    {
        return(0);
    }
    return(1);
}
int    ft_str_is_ascii(char *ascii)
{
    int i;
    
    if (!ascii)
    {
        return(0);
    }
    
    i = 0;
    while (ascii[i])
    {
        if (ft_is_ascii(ascii[i]) == 0)
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
        char *space = "á";
        
        if (ft_str_is_ascii(space) == 1)
        {
            printf("OK IS ASCII\n");
        }
        else
        {
            printf("no is\n");
        }    
        return(0);
    }
*/