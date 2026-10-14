#include <stdlib.h>
#include <string.h>

#include "estruturas.h"

No* CreateNewNode(void)
{
    return NULL;
}

No* SearchElement(char *cod_comp, No *head)
{
    No *current = head;
    while (current != NULL)
    {
        if (strcmp(current->data->cod_comp, cod_comp) == 0) return current;
        current = current->next;
    }
    return NULL;
}
