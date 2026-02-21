/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casa <casa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:59:47 by jucongol          #+#    #+#             */
/*   Updated: 2026/02/16 12:59:57 by casa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
    ft_strcpy - Reimplementação da função strcpy.
    Copia a string 'src' para a memória apontada por 'dest',
    incluindo o caractere nulo de terminação.

    Retorna: ponteiro original de 'dest'
*/
#include <stddef.h>//Header do valor NULL se vaz a usar

char    *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    // Copia cada caractere de 'src' para 'dest'
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    // Adiciona o terminador nulo no final de 'dest'
    dest[i] = '\0';
    // Retorna o ponteiro para o início da string copiada
    return(dest);
}

/*
    int main(void)
    {
        char    *src = "Hola mundo";
        char    dst [10];
        int     i = 0;
        write(1, "dst antes:-> ", 14);
        while(dst[i])
        {
            write(1, &dst[i], 1);
            i++;
        }
        write(1, "\n", 1);
        
        ft_strcpy(dst, src);
        write(1, "dst depois:-> ", 15);
        i = 0;
        while(dst[i])
        {
            write(1, &dst[i], 1);
            i++;
        }
        write(1, "\n", 1);
        return(0);
    }
*/

/*
    ft_strreverse(char *str)
    Objetivo: inverter a string original in-place.
    Exemplo: "hello" → "olleh"
    Trabalha com ponteiros, troca de caracteres e controle de índices.
    Reforça lógica de manipulação direta sem criar cópias.
*/
int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        i++;
    }
    return(i);
}
void    ft_strreverse(char *str)
{
    int     i;
    int     len_str;
    char    tmp;

    i = 0;
    len_str = ft_strlen(str);
    while (i < len_str)
    {
        tmp = str[i];
        str[i] = str[len_str - 1];
        str[len_str - 1] = tmp;
        i++;
        len_str--;
    }
}
/*

    int main(void)
    {
        char    word[] = "hello";
        
        write(1, "Before word\n", 12);
        write(1, word, ft_strlen(word));
        write(1, "\n", 1);
        
        write(1, "After word\n", 11);
        ft_strreverse(word);
        write(1, word, ft_strlen(word));
        write(1, "\n", 1);
        return(0);
    }
*/


/*
    ft_strcompress(char *str)
    Objetivo: remover espaços duplicados e compactar a string.
    Exemplo: "a  b    c" → "a b c"
    Exige controle de escrita e leitura no mesmo buffer.
    Treina lógica de filtragem e sobrescrita.
*/
void    ft_strcompress(char *str)
{
    int read_index;
    int flag_space;
    int write_index;
    
    if (!str)
    {
        return;
    }
    read_index = 0;
    write_index = 0;
    flag_space = 0;
    while (str[read_index])
    {
        if (str[read_index] == ' ' || str[read_index] == '\t')
        {
            if (flag_space == 0)
            {
                str[write_index] = ' ';
                write_index++;
                flag_space = 1;
            }
        }
        else
        {
            str[write_index] = str[read_index];
            write_index++;
            flag_space = 0;
        }
        read_index++;
    }
    str[write_index] = '\0';
}
/*

    int main(void)
    {
        char    word[] = "a b      c";
        write(1, "Before word\n", 12);
        write(1, word, ft_strlen(word));
        write(1, "\n", 1);
        
        write(1, "After word\n", 11);
        ft_strcompress(word);
        write(1, word, ft_strlen(word));
        write(1, "\n", 1);
        return(0);
    }
*/


/*
    ft_strstrip(char *str)
    Objetivo: remover espaços em branco no início e fim da string.
    Exemplo: " hello " → "hello"
    Trabalha com deslocamento de ponteiros e realocação.
    Reforça entendimento de limites e terminadores.
*/
char    *ft_strstrip(char *str)
{
    int start_index;
    int end_index;
    int write_index;

    if (!str)
    {
        return(NULL);
    }
    start_index = 0;
    while (str[start_index] == ' ' || str[start_index] == '\t')
    {
        start_index++;
    }
    end_index = ft_strlen(str);
    while (str[end_index - 1] == ' ' || str[end_index - 1] == '\t')
    {
        end_index--;
    }
    write_index = 0;
    while (start_index < end_index)
    {
        str[write_index] = str[start_index];
        write_index++;
        start_index++;
    }
    str[write_index] = '\0';
    return(str);
}
/*

    int main(void)
    {
        char    word[] = " hello   ";
        write(1, "Before word\n", 12);
        write(1, word, ft_strlen(word));
        write(1, "\n", 1);
        
        write(1, "After word\n", 11);
        ft_strstrip(word);
        write(1, word, ft_strlen(word));
        write(1, "\n", 1);
        return(0);
    }
*/

/*
    ft_strcount(char *str, char c)
    Objetivo: contar quantas vezes o caractere c aparece na string.
    Exemplo: "banana", 'a' → 3
    Simples, mas útil para reforçar leitura sequencial e comparação.
*/
int ft_strcount(char *str, char c)
{
    int i;
    int count_c;
    
    if (!str)
    {
        return(0);
    }
    i = 0;
    count_c = 0;
    while (str[i])
    {
        if (str[i] == c)
        {
            count_c++;
        }
        i++;
    }
    return(count_c);
}
/*
    #include <stdio.h>
    int main(void)
    {
        char    word[] = "Banana";
        int    count_charecter;

        count_charecter = 0;
        printf("Befor count : %d\n", count_charecter);
        
        count_charecter = ft_strcount(word, 'a');
        printf("After count : %d\n", count_charecter);
        return(0);
    }
*/

/*
    ft_strreplace(char *str, char find, char replace)
    Objetivo: substituir todas as ocorrências de um caractere por outro.
    Exemplo: "banana", 'a', 'x' → "bxnxnx"
    Treina substituição direta e manipulação segura.
*/
char    *ft_strreplace(char *str, char find, char replace)
{
    int i;
    
    if (!str)
    {
        return(NULL);
    }
    i = 0;
    while (str[i])
    {
        if (str[i] == find)
        {
            str[i] = replace;
        }
        i++;
    }
    return(str);
}
/*

    int main(void)
    {
        char    word[] = "banana";
    
        write(1, "Before word\n", 12);
        write(1, word, ft_strlen(word));
        write(1, "\n", 1);
        
        write(1, "After word\n", 11);
        ft_strreplace(word, 'a', 'x');
        write(1, word, ft_strlen(word));
        write(1, "\n", 1);
        return(0);
    }
*/