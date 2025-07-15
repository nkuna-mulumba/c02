/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:22:16 by jcongolo          #+#    #+#             */
/*   Updated: 2025/07/15 15:31:12 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_str_is_uppercase - Verifica se string contém apenas letras maiúsculas.
    Parâmetro:
        str - ponteiro para a string que será analisada
    Retorno:
        1 → se todos caracteres forem letras maiúsculas ou se string estiver vazia
        0 → se houver qualquer caractere que não seja uma letra maiúscula
    Observações:
        - A função assume que 'str' é um ponteiro válido
        - Não utiliza nenhuma função externa
*/
int ft_str_is_uppercase(char *str)
{
    int i;

    i = 0;
    //Retorna 1 se string estiver vazia
    if (str[i] == '\0')
    {
        return(1);//String vazia → retorna 1
    }
    //Percorre string caractere por caractere
    while (str[i])
    {
        //Verifica se caractere está no intervalo de letras maiúsculas
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            i++; //Avança para próximo caractere
        }
        else
        {
            return(0);//Se não for maiúsculo, retorna 0 imediatamente
        }
    }
    return(1);//Todos caracteres são maiúsculos
}

/*
    #include <stdio.h>
    #include <unistd.h>
    int main(void)
    {
        char    *str = "ABC";
        int     i = 0;
        while (str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
        write(1, "\n", 1);
        
        int return_function = ft_str_is_uppercase(str);
        printf("Value return of function ->[%d]\n", return_function);
        return(0);
    }
*/