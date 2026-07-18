/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casa <casa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:31:54 by jcongolo          #+#    #+#             */
/*   Updated: 2026/06/13 19:20:57 by casa             ###   ########.fr       */
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
#include <stdio.h>

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

/*
    ft_str_to_title_case
    Transformar a string para formato de título:
    Palavras pequenas (“de”, “da”, “do”, “a”, “e”, “o”) ficam minúsculas
    Restantes capitalizam
*/
int ft_is_digit_char(char c)
{
    if (c < '0' || c > '9')
    {
        return(0);
    }
    return(1);
}
int ft_is_uppercase_char(char c)
{
    if (c < 'A' || c > 'Z')
    {
        return(0);
    }
    return(1);
}
int ft_is_lower_char(char c)
{
    if (c < 'a' || c > 'z')
    {
        return(0);
    }
    return(1);
}
int ft_is_saparat(char c)
{
    if (ft_is_digit_char(c)
        || ft_is_uppercase_char(c)
        || ft_is_lower_char(c))
    {
        return(0);
    }
    return(1);
}
/*
    ft_str_to_title_case
    Transformar a string para formato de título:
    Palavras pequenas (“de”, “da”, “do”, “a”, “e”, “o”) ficam minúsculas
    Restantes capitalizam
*/
/*
    int ft_is_small_word(char *str)
    {
        int i;
        int small_word;

        i = 0;
        small_word = 0;
        while (str[i])
        {
            if ((str[i] == ' '
                    && str[i + 1] == 'd' && str[i + 2] == 'e'
                    && str[i + 3] == ' ')
                || (str[i] == 'd' && str[i + 1] == 'e'
                    && str[i + 2] == ' '))
            {
                small_word++;
            }
            i++;
        }
        return(small_word); //Numero de palavras pequenas encontrado numa frase
    }
*/

char    *ft_str_to_title_case(char str)
{
    
    return();
}
int main(void)
{
    char *str = "abc   de";
    if (ft_is_swoll_word(str) == 1)
    {
        printf("YES the sentence has a SMALL word.\n");
    }
    else
    {
        printf("NOOO the sentence no has a small word.\n");
    }
    return(0);
}
// char    *ft_str_to_title_case(char *str)
// {
//     int i;
    
//     if (!str || str[0] == '\0')
//     {
//         return(NULL);
//     }
//     i = 0;
//     while (str[i])
//     {
//         if (condition)
//         {
//             /* code */
//         }
//         i++;
//     }
//     return(str);
// }

/*
    ft_str_reverse_words
    Inverter apenas as palavras, mantendo os delimitadores no mesmo lugar.
    Ex.: "Joao-da-Silva" → "oaoJ-ad-avliS"
*/

/*
    ft_str_clean_symbols
    Remover todos os símbolos não alfanuméricos, mas manter espaços.
    Ex.: "Joao@# Silva!!" → "Joao Silva"
*/

/*
    ft_str_count_words
    Contar quantas palavras existem na string (alfanuméricas).
    Ex.: "Joao-123---Silva" → 3
*/

/*
    ft_str_swapcase
    Trocar maiúsculas ↔ minúsculas.
    Ex.: "AbC12xY" → "aBc12Xy"
*/