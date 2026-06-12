<<<<<<< HEAD
/*                                                    +:+ +:+         +:+     */
#include <unistd.h>
/*   Updated: 2026/06/11 14:20:06 by coressor         ###   ########.fr       */
#include <stdlib.h>

=======
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
>>>>>>> create-window
#include "parsing.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Arguments incorrect : ./cub3d /path/to/map.cub\n");
        return (1);
    }
    if (!parsing(argv[1]))
        return (1);
    return (0);
}
