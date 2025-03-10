#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "fila.h"
#include "ticket.h"
#include "outros.h"
#include "tecnico.h"
#include "usuario.h"

int main(int argc, char const *argv[])
{
    Usuario* u = leUsuario();
    imprimeUsuario(u);
    
    return 0;
}
