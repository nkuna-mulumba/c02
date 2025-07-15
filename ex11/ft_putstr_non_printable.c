/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucongol <jucongol@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-15 18:08:07 by jucongol          #+#    #+#             */
/*   Updated: 2025-07-15 18:08:07 by jucongol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putstr_non_printable(char *str)
{
    int     i;
    char    *hex;

    i = 0;
    //Base hexadecimal: cada índice representa um dígito 0–15
    hex = "0123456789abcdef";
    //Itera string caractere por caractere
    while(str[i])
    {
        //Verifica se aractere não é imprimível:
        //- ASCII de 0 a 31 são de controle
        //- ASCII 127 é o DEL (delete), também não é imprimível
        if(str[i] >= 0 && str[i] <= 31 || str[i] == 127)
        {
            write(1, "\\", 1);//Escreve caractere de escape '\'
            //Converte valor do caractere para 2 dígitos hexadecimais:
            write(1, &hex[(unsigned char)str[i] / 16], 1);//Primeiro dígito = parte alta (divisão / 16)
            write(1, &hex[(unsigned char)str[i] % 16], 1);//Segundo dígito = parte baixa (resto da divisão / 16)
        }
        else
        {
            //Se caractere é imprimível
            write(1, &str[i], 1);
        }
        i++;
    }
}

/*
    int main(void)
    {
        char    *str = "Ola\nesta bem?";
        int     i = 0;

        while(str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
        write(1, "\n", 1);

        ft_putstr_non_printable(str);
        write(1, "\n", 1);
        
        return(0);
    }
*/