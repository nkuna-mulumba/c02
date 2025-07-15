/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucongol <jucongol@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-15 19:13:59 by jucongol          #+#    #+#             */
/*   Updated: 2025-07-15 19:13:59 by jucongol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Imprime o endereço de memória em 16 dígitos hexadecimais seguido de ': '
void print_address(unsigned long addr)
{
    char *hex = "0123456789abcdef";
    char str[16];
    int i = 15;

    // Converte o número do endereço para uma string hexadecimal
    while (i >= 0)
    {
        str[i] = hex[addr % 16]; // pega o dígito menos significativo
        addr /= 16;              // avança para o próximo
        i--;
    }
    write(1, str, 16);  // imprime os 16 caracteres hexadecimais do endereço
    write(1, ": ", 2);  // separador entre endereço e dados
}

// Imprime até 16 bytes em formato hexadecimal agrupados por pares (2 chars por byte + espaço)
void print_hex(unsigned char *ptr, unsigned int size)
{
    char *hex = "0123456789abcdef";
    int i;

    for (i = 0; i < 16; i++)
    {
        if (i < size)
        {
            // Converte cada byte em dois caracteres hexadecimais
            write(1, &hex[ptr[i] / 16], 1); // parte alta
            write(1, &hex[ptr[i] % 16], 1); // parte baixa
        }
        else
            write(1, "  ", 2); // espaços para alinhamento caso haja menos de 16 bytes

        // Espaço adicional a cada 2 bytes
        if (i % 2 == 1)
            write(1, " ", 1);
    }
}

// Imprime os 16 bytes como caracteres ('.' para os não imprimíveis)
void print_chars(unsigned char *ptr, unsigned int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        // Se o byte for imprimível (ASCII entre 32 e 126), imprime normalmente
        if (ptr[i] >= 32 && ptr[i] <= 126)
            write(1, &ptr[i], 1);
        else
            write(1, ".", 1); // substitui caracteres não imprimíveis por '.'
    }
}

// Função principal: imprime blocos de memória de addr com tamanho size
void *ft_print_memory(void *addr, unsigned int size)
{
    unsigned int i = 0;
    unsigned char *ptr = (unsigned char *)addr;

    if (size == 0)
        return addr; // nada a imprimir

    // Percorre a memória em blocos de 16 bytes
    while (i < size)
    {
        // Calcula o tamanho real do bloco atual (último bloco pode ter < 16)
        unsigned int block = (size - i >= 16) ? 16 : size - i;

        // Imprime endereço, conteúdo em hexadecimal e caracteres
        print_address((unsigned long)(ptr + i));
        print_hex(ptr + i, block);
        print_chars(ptr + i, block);
        write(1, "\n", 1);

        i += 16;
    }
    return addr;
}

int main(void)
{
    char data[] = "Hola mundo...\n\ttes\tpara a funçao.";
    ft_print_memory(data, sizeof(data));
    return 0;
}
