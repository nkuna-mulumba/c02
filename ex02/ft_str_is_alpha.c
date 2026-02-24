/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casa <casa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:27:55 by nkuna             #+#    #+#             */
/*   Updated: 2026/02/24 15:37:14 by casa             ###   ########.fr       */
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
#include <stdio.h>
#include <unistd.h>
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


/*
    ft_str_is_numeric
    Cria uma função que retorna 1 se a string contiver apenas dígitos (0–9).
    Retorna 0 se houver qualquer outro caractere.
*/
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
        if ((str[i] < '0') || (str[i] > '9'))
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
        char    *string = "";
        
        if (ft_str_is_numeric(string) == 1)
        {
            printf("Is numeric\n");
        }
        else
        {
            printf("NO is numeric\n");
        }    
        return(0);
    }
*/


/*
    ft_str_is_lowercase
    Retorna 1 se a string contiver apenas letras minúsculas (a–z).
    Retorna 0 caso contrário.
*/
int     ft_str_is_lowercase(char *str)
{
    int i;

    if (!str || str[0] == '\0')
    {
        return(0);
    }

    i = 0;
    while (str[i])
    {
        if (str[i] < 'a' || str[i] > 'z')
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
        char    *string = "az";
        
        if (ft_str_is_lowercase(string) == 1)
        {
            printf("LOWERCASE\n");
        }
        else
        {
            printf("NO is\n");
        }    
        return(0);
    }
*/



/*
    ft_str_is_uppercase
    Retorna 1 se a string contiver apenas letras maiúsculas (A–Z).
    Retorna 0 caso contrário.
*/

int     ft_str_is_uppercase(char *str)
{
    int i;

    if (!str || str[0] == '\0')
    {
        return(0);
    }
    
    i = 0;
    while (str[i])
    {
        if (str[i] < 'A' || str[i] > 'Z')
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
        char    *string = "AZ";
        
        if (ft_str_is_uppercase(string) == 1)
        {
            printf("UPPERCASE\n");
        }
        else
        {
            printf("NO is\n");
        }    
        return(0);
    }
*/

/*
    ft_str_is_alnum
    Retorna 1 se a string contiver apenas letras ou números.
    Retorna 0 se tiver símbolos, espaços ou pontuação.
*/
// Verifica se o caractere é um dígito ('0' a '9')
int ft_is_dig(char c)
{
    if (c >= '0' && c <= '9')
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
// Verifica se o caractere é uma letra maiúscula ('A' a 'Z')
int ft_is_alph_upp(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return(1);
    }
    else
    {
        return(0);
    }   
}
// Verifica se o caractere é uma letra minúscula ('a' a 'z')
int ft_is_alph_low(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return(1);
    }
    else
    {
        return(0);
    }   
}
// Verifica se o caractere é o terminador de string '\0'
int ft_is_empty(char c)
{
    if (c == '\0')
    {
        return(1);
    }
    else
    {
        return(0);
    }   
}
// Verifica se o ponteiro da string é NULL
int ft_is_null(char *str)
{
    if (!str)
    {
        return(1);
    }
    else
    {
        return(0);
    }   
}
// Função principal: verifica se todos os caracteres são letras ou números
int    ft_str_is_alnum(char *str)
{
    int i;

    if (ft_is_null(str) || ft_is_empty(str[0]))
    {
        return(0);
    }
    
    i = 0;
    while (str[i])
    {
        if (!ft_is_dig(str[i]) && !ft_is_alph_upp(str[i]) && !ft_is_alph_low(str[i]))
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
        char    *string = "aZ5:";
        
        if (ft_str_is_alnum(string) == 1)
        {
            printf("ALNUM\n");
        }
        else
        {
            printf("NO is\n");
        }    
        return(0);
    }
*/

/*
    ft_str_is_printable
    Retorna 1 se todos os caracteres estiverem no intervalo ASCII imprimível (32 a 126).
    Retorna 0 se encontrar caracteres de controlo.
*/
// Verifica se o caractere está no intervalo ASCII imprimível (32 a 126)
int ft_printable_char_ascii(char c)
{
    if (c < ' ' || c > '~')
    {
        return(0);
    }
    return(1);
}

// Função principal: verifica se todos os caracteres são imprimiveis ou nao
int    ft_str_is_printable(char *str)
{
    int i;

    if (ft_is_null(str) || ft_is_empty(str[0]))
    {
        return(0);
    }
    
    i = 0;
    while (str[i])
    {
        if (ft_printable_char(str[i]) == 0)
        {
            return(0);
        }
        i++;
    }
    return(1);
}

/**/
    int main(void)
    {
        char    *string = "âçá";
        
        if (ft_str_is_printable(string) == 1)
        {
            printf("PRINTABLE\n");
        }
        else
        {
            printf("NO is\n");
        }    
        return(0);
    }

