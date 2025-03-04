#include <stdio.h>
#include <string.h>

const char *mapaTeclado[] = {
    "",//0
    "",//1
    "abc",//2
    "def",//3
    "ghi",//4
    "jkl",//5
    "mno",//6
    "pqrs",//7
    "tuv",//8
    "wxyz"//9
};//letras mapeadas por posicion en el arreglo

void generarCombinaciones(char *digitos, int indice, char *actual, int longitud) {
    if(indice == longitud){
        printf("%s\n", actual);//cuando hayamos terminado imprimimos actual
        return;
    }

    int digito = digitos[indice] - '0';//asignamos el digito en turno
    
    if(digito < 2 || digito > 9){
        printf("Numero no valido: %d\n", digito);
        return;
    }
    
    const char *letras = mapaTeclado[digito];//dependiendo del digito regresa las letras correspondientes
    for(int i = 0; i < strlen(letras); i++){//recorreremos las letras del digito en turno (se hara 3 o 4 veces)
        actual[indice] = letras[i];//se asigna al resultado final la letra correspondinete (el for recorrerá para cada uno de las posibles letras para ese digito)
        generarCombinaciones(digitos, indice + 1, actual, longitud);//ingresamos el siguiente digito para que haga la proxima combinacion
    }
}

int main(int argc, char *argv[]){
    char digitos[100];//vamos a tratar todos los numeros como cadena para que sea mas facil manejarlos
    printf("Ingrese un numero (solo digitos del 2 al 9): ");
    scanf("%s", digitos);
    int longitud = strlen(digitos);
    char actual[longitud + 1];
    actual[longitud] = '\0';  // Para terminar la cadena en el ultimo digito
    generarCombinaciones(digitos, 0, actual, longitud);
    return 0;
}