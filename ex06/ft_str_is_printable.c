/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casa <casa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:32:32 by jcongolo          #+#    #+#             */
/*   Updated: 2026/04/06 22:28:42 by casa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_str_is_printable - Verifica se a string contém apenas caracteres imprimíveis.

    Parâmetro:
        str - ponteiro para a string a ser analisada

    Retorno:
        1 → se todos os caracteres estiverem no intervalo imprimível (ASCII 32 a 126)
        0 → se houver qualquer caractere fora desse intervalo
*/
#include <stdio.h>
#include <unistd.h>
int ft_str_is_printable(char *str)
{
    int i;
    
    i = 0;
    //Retorna 1 se string for vazia
    if (str[i] == '\0')
    {
        return(1);
    }
    //Percorre cada caractere da string
    while (str[i])
    {
        //Verifica caracter está no intervalo de caracteres imprimíveis
        if (str[i] >= ' ' && str[i] <= '~')
        {
            i++;//Avança
        }
        //caso nao, retorna (0) directamente
        else
        {
            return(0);
        }
    }
    //Todos caracteres são imprimíveis
    return(1);
}
/*
    int main(void)
    {
        char    *str = ".?-a [1";
        int     i = 0;
        while (str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
        write(1, "\n", 1);
        
        int return_function = ft_str_is_printable(str);
        printf("Value return of function ->[%d]\n", return_function);
        return(0);
    }
*/

/*
    ft_str_is_graphic
    Retorna 1 se todos os caracteres forem gráficos (ASCII 33–126).
*/
// Graphic = visível  
// Printable = imprimível (inclui espaço)  
// Todo gráfico é imprimível, mas nem todo imprimível é gráfico.
int ft_is_graphic_char(char c)
{
    if (c < 33 || c > 126)
    {
        return(0);
    }
    return(1);
}
int ft_str_is_graphic(char *str)
{
    int i;

    if (!str || str[0] == '\0')
    {
        return(0);
    }
    
    i = 0;
    while (str[i])
    {
        if (ft_is_graphic_char(str[i]) == 0)
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
        char *graphic_caracter = "ab 12";
        
        if (ft_str_is_graphic(graphic_caracter) == 1)
        {
            printf("IS GRAPHIC\n");
        }
        else
        {
            printf("No is\n");
        }
        return(0);
    }
*/

/*
    ft_str_is_ascii
    Retorna 1 se todos os caracteres forem ASCII (0–127).
*/
// Converte para unsigned char porque bytes acima de 127 podem
// aparecer como negativos.”
int ft_str_is_ascii(unsigned char *str)
{
    unsigned int i;
    
    if (!str)
    {
        return(0);
    }
   
    i = 0;
    while (str[i])
    {
        if (str[i] > 127)
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
        char *ascii_caracter = "233";
        // char ascii_caracter[] = {233}; //Testar byte de caracteres       
        if (ft_str_is_ascii(ascii_caracter) == 1)
        {
            printf("IS ASCII\n");
        }
        else
        {
            printf("No is\n");
        }
        return(0);
    }
*/

/*
    ft_str_is_binary
    Retorna 1 se a string tiver apenas '0' e '1'.
*/
int ft_is_binary_char(char c)
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
int ft_str_is_binary(char *str)
{
    int i;

    if(!str || str[0] == '\0')
    {
        return(0);
    }
    
    i = 0;
    while (str[i])
    {
        if (ft_is_binary_char(str[i]) == 0)
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
        char *binary = "0 1";
        
        if (ft_str_is_binary(binary) == 1)
        {
            printf("IS BINARY\n");
        }
        else
        {
            printf("No is\n");
        }
        return(0);
    }
*/

/*
    ft_str_is_octal
    Retorna 1 se a string tiver apenas '0' a '7'.
*/
int ft_is_octal_char(char c)
{
    if (c < '0' || c > '7')
    {
        return(0);
    }
    return(1);
}

int ft_str_is_octal(char *str)
{
    int i;

    if (!str || str[0] == '\0')
    {
        return(0);
    }
    
    i = 0;
    while (str[i])
    {
        if (ft_is_octal_char(str[i]) == 0)
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
        char *octal = "1258";
        
        if (ft_str_is_octal(octal) == 1)
        {
            printf("IS OCTAL\n");
        }
        else
        {
            printf("No is\n");
        }
        return(0);
    }
*/

/*
    ft_str_is_alnum
    Retorna 1 se a string tiver apenas letras ou números.
*/
int ft_is_alnum_char(char c)
{
    if (c >= '0' && c <= '9')
    {
        return(1);
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return(1);
    }
    else if (c >= 'a' && c <= 'z')
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
int ft_str_is_alnum(char *str)
{
    int i;

    if (!str || str[0] == '\0')
    {
        return(0);
    }
    
    i = 0;
    while (str[i])
    {
        if (ft_is_alnum_char(str[i]) == 0)
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
        char *alnum = "12AA azZ";
        
        if (ft_str_is_alnum(alnum) == 1)
        {
            printf("IS ALNUM\n");
        }
        else
        {
            printf("No is\n");
        }
        return(0);
    }
*/