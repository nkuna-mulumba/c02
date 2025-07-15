/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucongol <jucongol@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-14 18:23:20 by jucongol          #+#    #+#             */
/*   Updated: 2025-07-14 18:23:20 by jucongol         ###   ########.fr       */
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