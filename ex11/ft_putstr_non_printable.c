/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:08:07 by jucongol          #+#    #+#             */
/*   Updated: 2025/07/16 13:11:09 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_putstr_non_printable - Imprime uma string na tela.
Substitui os caracteres não imprimíveis por sua forma hexadecimal seguida por '\'.
Parâmetros:
str → string a ser mostrada
Comportamento:
- Caractere imprimível → exibido normalmente
- Caractere não imprimível (ASCII < 32 ou == 127) → exibido como '\xy', onde xy é o valor hexadecimal
Exemplo:
Entrada: "Ola\nesta"
Saída:   Ola\0aesta
*/
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
        if(((unsigned char)str[i] >= 0 && (unsigned char)str[i] <= 31) || (unsigned char)str[i] == 127)
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
