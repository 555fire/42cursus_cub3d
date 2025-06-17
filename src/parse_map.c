/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:03:35 by lchuang           #+#    #+#             */
/*   Updated: 2025/06/17 15:30:26 by lchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parse_cub(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening .cub file");
        exit(1);
    }

    char buffer[MAX_LINE];
    int i = 0;
    int ret;
    char c;

    while ((ret = read(fd, &c, 1)) > 0)
    {
        if (i < MAX_LINE - 1)
        {
            buffer[i++] = c;
            if (c == '\n')
            {
                buffer[i] = '\0';
                printf("Line: %s", buffer);
                i = 0;
            }
        }
    }

    if (i > 0)
    {
        buffer[i] = '\0';
        printf("Line: %s\n", buffer);
    }

    close(fd);
}
