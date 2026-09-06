/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casa <casa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:31:54 by jcongolo          #+#    #+#             */
/*   Updated: 2026/09/06 20:00:13 by casa             ###   ########.fr       */
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
#include <stdlib.h>
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
int ft_is_alphabet(char c)
{
    if (ft_is_lower_char(c) || ft_is_uppercase_char(c))
    {
        return(1);
    }
    return(0);
}
char    ft_to_uppercase_char(char c)
{
    if (ft_is_lower_char(c))
    {
        c = c - ('a' - 'A');
    }
    return(c);
}
char    ft_to_lowercase_char(char c)
{
    if (ft_is_uppercase_char(c))
    {
        c = c + ('a' - 'A');
    }
    return(c);
}
char    *ft_str_to_lower(char *str)
{
    int i;
    
    if (!str || str[0] == '\0')
    {
        return(NULL);
    }
    i = 0;
    while (str[i])
    {
        str[i] = ft_to_lowercase_char(str[i]);
        i++;
    }
    return(str);
}
/*
    Retorna 1 se o caractere NÃO for letra nem dígito.
    Usado para identificar delimitadores entre palavras.
*/
int ft_is_delimit(char c)
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
    Capitaliza a palavra:
    - primeira letra maiúscula
    - restantes minúsculas
*/
char    *ft_capitalize_word(char *word)
{
    int i;
    
    if (!word || word[0] == '\0')
    {
        return(NULL);
    }
    i = 0;
    word[i] = ft_to_uppercase_char(word[i]);
    i++;
    while (word[i])
    {
        word[i] = ft_to_lowercase_char(word[i]);
        i++;
    }
    return(word);
}
/*
    Verifica se a palavra é considerada "pequena" segundo o enunciado:
    Palavras pequenas: a, e, o, de, da, do.
    A função normaliza a palavra para minúsculas antes de comparar.
*/
int ft_is_small_word(char *word)
{
    int i;

    if (!word || word[0] == '\0')
    {
        return(0);
    }
    i = 0;    
    while (word[i])
    {
        word[i] = ft_to_lowercase_char(word[i]);
        i++;
    }
    if ((word[0] == 'a' && word[1] == '\0')
            || (word[0] == 'e' && word[1] == '\0')
            || (word[0] == 'o' && word[1] == '\0'))
    {
        return(1);
    }
    else if ((word[0] == 'd' && word[1] == 'a' && word[2] == '\0')
            || (word[0] == 'd' && word[1] == 'e' && word[2] == '\0')
            || (word[0] == 'd' && word[1] == 'o' && word[2] == '\0'))
    {
        return(1);
    }
    return(0);
}
/*
    ft_extract_word Copia caracteres da palavra de 'src' para 'dst'
    até encontrar um delimitador.
    Atualiza o índice 'i' para apontar após a palavra.
*/
void    ft_extract_word(char *src, char *dst, int *i)
{
    int j;

    if (!src || src[0] == '\0')
    {
        return;
    }
    j = 0;
    while (src[*i] && !ft_is_delimit(src[*i]))
    {
        dst[j] = src[*i];
        j++;
        (*i)++;
    }
    dst[j] = '\0';
}
/*
    ft_len_word Mede o tamanho da palavra começando no índice 'i'
    até encontrar um delimitador.
*/
int ft_len_word(char *str, int i)
{
    int len;

    if (!str || str[0] == '\0')
    {
        return(0);
    }
    len = 0;
    while (str[i] && !ft_is_delimit(str[i]))
    {
        i++;
        len++;
    }
    return(len);
}
char    *ft_calloc_buffer(int len)
{
    char    *str;

    str = calloc(len + 1, sizeof(char));
    if (!str)
    {
        return(NULL);
    }
    str[0] = '\0';
    return(str);
}
/*
    ft_copy_word Copia a palavra isolada (src) para a string original (dst)
    usando o índice de escrita 'i'.
*/
void    ft_copy_word(char *src, char *dst, int *i)
{
    int j;

    if (!src || src[0] == '\0')
    {
        return;
    }
    j = 0;
    while (src[j])
    {
        dst[*i] = src[j]; 
        j++;
        (*i)++;
    }
}
/*
    ft_skip_delimiters avança o índice até encontrar uma letra.
    Ignora delimitadores como espaço, ponto, hífen, underscore, etc.
*/
int    ft_skip_delimiters(char *str, int i)
{
    while (str[i] && ft_is_delimit(str[i]))
    {
        (i)++;
    }
    return(i);
}
/*
    ft_process_word aplica a regra do enunciado:
    - palavras pequenas ficam minúsculas
    - restantes são capitalizadas
    Depois copia a palavra processada para a string original.
*/
void    ft_process_word(char *str_extract, char *str, int *y)
{
    if (ft_is_small_word(str_extract))
    {
        ft_copy_word(str_extract, str, y);        
    }
    else
    {
        ft_capitalize_word(str_extract);
        ft_copy_word(str_extract, str, y);
    }
}
/*
    Funçao principal ft_str_to_title_case
    Converte a string para Title Case segundo o enunciado:
    - Palavras pequenas (“de”, “da”, “do”, “a”, “e”, “o”) ficam minúsculas
    - Restantes são capitalizadas

    Fluxo:
        1) Normaliza toda a string para minúsculas
        2) Avança delimitadores
        3) Mede o tamanho da palavra
        4) Extrai a palavra para um buffer temporário
        5) Processa a palavra (capitaliza ou mantém minúscula)
        6) Copia a palavra processada de volta para a string original
*/
char    *ft_str_to_title_case(char *str)
{
    int i;
    int y;
    int len_extract;
    char *str_extract;
    
    if (!str || str[0] == '\0')
    {
        return(NULL);
    }
    ft_str_to_lower(str);
    i = 0;
    y = 0;
    len_extract = 0;
    while (str[i])
    {
        // Avança até encontrar uma letra (pula delimitadores)
        i = ft_skip_delimiters(str, i);
        if (!str[i])
        {
            break;
        }
        y = i;
        len_extract = ft_len_word(str, i);
        str_extract = ft_calloc_buffer(len_extract);       
        ft_extract_word(str, str_extract, &i);
        ft_process_word(str_extract, str, &y);
        free(str_extract);
    }
    str[i] = '\0';
    return(str);
}

/*
    int main(void)
    {
        // char str[] = "Juliao de Angola_JULIAO DE ANGOLA:juliao De angola-juliao DE E Angola DO";
        // char str[] = "Juliao,,,de,,,Angola";
        char str[] = "juliao de angola";
        // char str[] = "Juliao   -   de   -   Angola";  
        printf("Befor: %s.\n", str);   
        ft_str_to_title_case(str);
        printf("After: %s.\n", str);
        return(0);
    }
*/

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