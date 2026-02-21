/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casa <casa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:23:20 by jucongol          #+#    #+#             */
/*   Updated: 2026/02/21 18:14:45 by casa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ft_strncpy - Copia até 'n' caracteres da string 'src' para 'dest'.
 *				Se 'src' for menor que 'n', o restante de 'dest' será preenchido com '\0'.
 *
 * @dest: Ponteiro para o destino da cópia.
 * @src: Ponteiro para a string fonte.
 * @n: Número máximo de caracteres a copiar.
 *
 * Retorna: O ponteiro para a string de destino 'dest'.
 */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	//Copia caracteres de 'src' para 'dest' até encontrar '\0' ou atingir 'n'
	while(src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	//Preenche restante de 'dest' com '\0' caso 'src' seja menor que 'n'
	while(i < n)
	{
		dest[i] = '\0';
		i++;
	}
	//Retorna o ponteiro para a string copiada
	return(dest);
}

/*
	#include <unistd.h>
	int main(void)
	{
		char	dest[10];
		char	*src = "Hola mundo";
		int	n = 4;

		ft_strncpy(dest, src, n);//Hola

		int i = 0;
		while(dest[i])
		{
			write(1, &dest[i], 1);
			i++;
		}
		write(1, "\n", 1);
		return(0);
	}
*/

/*
	ft_copy_first(char *dest, char *src, unsigned int n)
    Objetivo: copiar apenas os primeiros n caracteres da string src para dest.
    Exemplo: "programmer", n = 5 → "progr"  
    Trabalha com: limites de cópia e leitura parcial da string.
    Reforça: controle de índices e noção de truncamento (corte da string).
*/

char	*ft_copy_first(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	
	
	if (!src)
	{
		return(dest);
	}
	
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return(dest);
}

/*

	int main(void)
	{
		char	d[20] = "ABCDEFG";
		char	*s = "programmer";
		int	first = -5;
		
		printf("%s\n", d);
		if (first > 0)
		{
			ft_copy_first(d, s, first);
		}
		printf("%s\n", d);
		return(0);
	}
*/

/*
	ft_copy_fill(char *dest, char *src, unsigned int n)
    Objetivo: copiar uma string curta para um buffer maior, preenchendo o restante com '\0'.
    Exemplo: "ola", n = 10 → "ola\0\0\0\0\0\0\0"  
    Trabalha com: buffers fixos e preenchimento manual.
    Reforça: importância do terminador nulo e segurança na memória.
*/

char	*ft_copy_fill(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	if (!src)
	{
		return(dest);
	}
	
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return(dest);
}

/*

	int main(void)
	{
		char	d[20] = "ABCDEFG";
		char	*s = "ola";
		int	i = 10;
		
		printf("%s\n", d);
		if (i > 0)
		{
			ft_copy_fill(d, s, i);
		}
		printf("%s\n", d);
		return(0);
	}
*/


/*
	ft_copy_exact(char *dest, char *src, unsigned int n)
    Objetivo: testar o caso onde o tamanho de src é exatamente igual a n.
    Exemplo: "12345", n = 5 → "12345" (sem '\0' no final)
    Trabalha com: comportamento real da função strncpy.
    Reforça: atenção ao terminador nulo quando o limite é atingido.
*/
int		ft_stlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return(i);
}

char	*ft_copy_exact(char *dest, char *src, unsigned int n)
{
	unsigned int	len_src;
	unsigned int	i;
	
	len_src = ft_stlen(src);
	if (len_src == n)
	{
		i = 0;
		while (src[i] && i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return(dest);
}


/*

	int main(void)
	{
		char	d[20] = "ABCDEFG";
		char	*s = "12345";
		int		i = 5;
		
		printf("%s\n", d);
		ft_copy_exact(d, s, i);
		printf("%s\n", d);
		return(0);
	}
*/


/*
	ft_copy_half(char *dest, char *src)
	Objetivo: copiar apenas a metade inicial da string original.
    Exemplo: "abcdef" → "abc"  
    Trabalha com: cálculo de tamanho usando strlen.
    Reforça: integração entre funções e lógica simples de divisão.
*/
char	*ft_copy_half(char *dest, char *src)
{
	int	len_src;
	int	i;

	len_src = ft_stlen(src) / 2;
	
	if (len_src > 0)
	{
		i = 0;
		while (src[i] && i < len_src)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return(dest);
}

/*
	int main(void)
	{
		char	d[20] = "123456";
		char	*s = "abc";
		
		printf("%s\n", d);
		ft_copy_half(d, s);
		printf("%s\n", d);
		return(0);
	}
*/

/*
	ft_copy_until_space(char *dest, char *src, unsigned int n)
    Objetivo: copiar caracteres até encontrar um espaço ou até atingir n.
    Exemplo: "ola mundo", n = 10 → "ola"  
    Trabalha com: leitura sequencial e detecção de delimitadores.
    Reforça: extração de palavras e uso de limites.
*/
int	ft_is_espace(char c)
{
	if (c == ' ')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
char	*ft_copy_until_space(char *dest, char *src, unsigned int n)
{
	unsigned int	i_src;
	unsigned int	i_dest;

	i_src = 0;
	// Ignorar espaços iniciais
	while (ft_is_espace(src[i_src]) == 1)
	{
		i_src++;
	}

	i_dest = 0;
	// Copiar até espaço ou até n
	while (src[i_src] && (ft_is_espace(src[i_src]) != 1) && (i_dest < n))
	{
		dest[i_dest] = src[i_src];
		i_src++;
		i_dest++;
	}
	return(dest);
}

/*
	int main(void)
	{
		char	d[20] = "123456";
		char	*s = "  ola mundo";
		int		i = 10;
		
		printf("%s\n", d);
		if (i > 1)
		{
			ft_copy_until_space(d, s, i);
		}
		printf("%s\n", d);
		return(0);
	}	
*/