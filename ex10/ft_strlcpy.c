/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucongol <jucongol@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-15 16:44:44 by jucongol          #+#    #+#             */
/*   Updated: 2025-07-15 16:44:44 by jucongol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_strlcpy - Replica o comportamento da função strlcpy.
                 Copia até size - 1 caracteres de src para dest e garante NUL-terminação.
    Parâmetros:
        dest → destino da cópia
        src → origem
        size → tamanho máximo de dest
    Retorno:
        Comprimento total de src (como strlen)
*/
unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int    len;
    unsigned int    j;

    len = 0;
    //Conta tamanho total de src
    while(src[len])
    {
        len++;
    }
    //Verificar se dest, tem buffer para pelomenos 1 caracter e terminal nulo
    if(size > 0)
    {
        j = 0;
        while(src[j] && j < size - 1)
        {
            dest[j] = src[j];
            j++;
        }
        dest[j] = '\0';
    }
    return(len);//Comprimento total de src
}

/*
    #include <stdio.h>
    int main(void)
    {
        char    src[] = "eu que";
        int     i = 0;
        printf("Src: %s\n", src);
        
        char dest[10];

        int len_src = ft_strlcpy(dest, src, 2);
        
        printf("Dest copy: [%s]\n", dest);

        printf("Length of [%s] -> [%d]\n", src, len_src);
        return(0);
    }
*/

