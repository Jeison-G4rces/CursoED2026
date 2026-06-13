/*
Autor:
Jeison Elian Garcés Longa

Taller Unidad 5
Métodos de ordenamiento eficientes y búsqueda binaria
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CONTENEDORES 30

int pesos[MAX_CONTENEDORES];
int ordenado = 0;
int cantidadContenedores = 0;

void quickSort(int inicio, int fin);
int particion(int inicio, int fin);


void mergeSort(int izquierda, int derecha);
void merge(int izquierda, int medio, int derecha);

void heapSort();
void heapify(int n, int i);

int busquedaBinaria(int valorBuscado);

int main(){  
srand(time(NULL));
int opcion;
char condicion; 

//creo el menu de opciones (do-while por deberia mostrarse al menos una vez)
do{
    printf("================================================\n"
            
        "SISTEMA DE ORGANIZACION DE CONTENEDORES\n"
        "MUELLE DE CARGA\n"
        
        "=========================================================");
    printf("\n1. Registrar peso de contenedores manualmente\n" 
    "2. Generar pesos aleatorios de contenedores\n" 
    "3. Mostrar contenedores registrados\n"
    "4. Ordenar contenedores Metodo 1\n"
    "5. Ordenar contenedores Metodo 2\n" 
    "6. Ordenar contenedores Metodo 3\n" 
    "7. Buscar contenedor\n"
    "8. Salir\n");
    printf("==================================================\n");
    printf("seleccione una opcion: ");    
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        do
        {       
            //en caso de tener el contenedor lleno   
            if (cantidadContenedores >= MAX_CONTENEDORES )
            {
                printf("Se alcanzó el límite máximo de contenedores");
                break;

            }
            //registrar el peso de los contenedores
                printf("ingrese el peso: ");
                scanf("%d", &pesos[cantidadContenedores]);
                cantidadContenedores++;
                ordenado = 0; 
                printf("contenedor guardado\n");
                printf("Contenedores: %d\n", cantidadContenedores);

                printf("Desea agregar otro contenedor? (S/N): ");
                scanf(" %c", &condicion);

        } while (condicion == 's' || condicion == 'S');
        
        break;
        
    case 2:
    {
        int cantidadGenerar;

        if (cantidadContenedores >= MAX_CONTENEDORES)
        {
            printf("Se alcanzo el limite maximo de contenedores\n");
            break;
        }

        printf("Cuantos contenedores desea generar?: ");
        scanf("%d", &cantidadGenerar);

        if (cantidadGenerar <= 0)
        {
            printf("Cantidad invalida\n");
            break;
        }

        if (cantidadContenedores + cantidadGenerar > MAX_CONTENEDORES)
        {
            printf("No hay suficiente espacio. Solo quedan %d posiciones disponibles\n",
                MAX_CONTENEDORES - cantidadContenedores);
            break;
        }

        for (int i = 0; i < cantidadGenerar; i++)
        {
            pesos[cantidadContenedores] = 500 + rand() % 2501;
            cantidadContenedores++;
        }

        ordenado = 0;

        printf("Se generaron %d contenedores correctamente\n", cantidadGenerar);
        printf("Total de contenedores: %d\n", cantidadContenedores);

        break;
    }
    case 3:
        if (cantidadContenedores == 0)
        {
            printf("No hay contenedores registrados");
            break;
        }
        printf("CONTENEDORES REGISTRADOS\n");
        for (int  i = 0; i < cantidadContenedores; i++)
        {
            printf("[%d] %dkg\n", i + 1, pesos[i]);
        }
        

        break;
    
    case 4:
        if (cantidadContenedores == 0)
        {
            printf("No hay contenedores registrados\n");
            break;
        }

        if (cantidadContenedores == 1)
        {
            printf("Ya esta ordenado\n");
            ordenado = 1;
            break;
        }

        quickSort(0, cantidadContenedores - 1);
        ordenado = 1;
        printf("Contenedores ordenados mediante QuickSort\n");
        break;

    case 5:
        if (cantidadContenedores == 0)
        {
            printf("no hay contenedores registrados\n");
        break;
        }
        if (cantidadContenedores == 1)
        {
            printf("Ya esta ordenado\n");
            ordenado = 1;
            break;
        }
        mergeSort(0, cantidadContenedores - 1);
        ordenado = 1;
        printf("Contenedores ordenados mediante Merge Sort\n");
        break;
        
        case 6:
        if (cantidadContenedores == 0)
        {
            printf("no hay contenedores registrados\n");
            break;
        }
        if (cantidadContenedores == 1)
        {
            ordenado = 1;
            break;
        }
        heapSort();
        ordenado = 1;
        printf("Contenedores ordenados mediante Heap Sort\n");
        break;   
    case 7:
    {
        int pesoBuscado;
        int posicion;

        if (cantidadContenedores == 0)
        {
            printf("No hay contenedores registrados\n");
            break;
        }

        if (ordenado == 0)
        {
            printf("Debe ordenar los contenedores antes de realizar una busqueda binaria\n");
            break;
        }

        printf("Ingrese el peso a buscar: ");
        scanf("%d", &pesoBuscado);

        posicion = busquedaBinaria(pesoBuscado);

        if (posicion == -1)
        {
            printf("Contenedor no encontrado\n");
        }
        else
        {
            printf("Contenedor encontrado en la posicion %d\n", posicion + 1);
        }

        break;
}
    case 8:
        printf("Gracias por venis, Hasta pronto\n");
        break;
    
    default:
        printf("selecione una opcion valida por favor\n");
        break;
    }
      


}while (opcion != 8);

return 0;
}


int particion(int inicio, int fin)
{
    int pivote = pesos[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++)
    {
        if (pesos[j] <= pivote)
        {
            i++;

            int temp = pesos[i];
            pesos[i] = pesos[j];
            pesos[j] = temp;
        }
    }

    int temp = pesos[i + 1];
    pesos[i + 1] = pesos[fin];
    pesos[fin] = temp;

    return i + 1;
}

void quickSort(int inicio, int fin)
{
    if (inicio < fin)
    {
        int indicePivote = particion(inicio, fin);

        quickSort(inicio, indicePivote - 1);

        quickSort(indicePivote + 1, fin);
    }
}


void mergeSort(int izquierda, int derecha)
{
    if (izquierda < derecha)
    {
        int medio = (izquierda + derecha) / 2;

        mergeSort(izquierda, medio);

        mergeSort(medio + 1, derecha);

        merge(izquierda, medio, derecha);
    }
}


void merge(int izquierda, int medio, int derecha)
{
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    int izquierdaTemp[n1];
    int derechaTemp[n2];

    for (int i = 0; i < n1; i++)
    {
        izquierdaTemp[i] = pesos[izquierda + i];
    }

    for (int j = 0; j < n2; j++)
    {
        derechaTemp[j] = pesos[medio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = izquierda;

    while (i < n1 && j < n2)
    {
        if (izquierdaTemp[i] <= derechaTemp[j])
        {
            pesos[k] = izquierdaTemp[i];
            i++;
        }
        else
        {
            pesos[k] = derechaTemp[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        pesos[k] = izquierdaTemp[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        pesos[k] = derechaTemp[j];
        j++;
        k++;
    }
}

void heapSort()
{
    for (int i = cantidadContenedores / 2 - 1; i >= 0; i--)
    {
        heapify(cantidadContenedores, i);
    }

    for (int i = cantidadContenedores - 1; i > 0; i--)
    {
        int temp = pesos[0];
        pesos[0] = pesos[i];
        pesos[i] = temp;

        heapify(i, 0);
    }
}

void heapify(int n, int i)
{
    int mayor = i;

    int izquierda = 2 * i + 1;
    int derecha = 2 * i + 2;

    if (izquierda < n && pesos[izquierda] > pesos[mayor])
    {
        mayor = izquierda;
    }

    if (derecha < n && pesos[derecha] > pesos[mayor])
    {
        mayor = derecha;
    }

    if (mayor != i)
    {
        int temp = pesos[i];
        pesos[i] = pesos[mayor];
        pesos[mayor] = temp;

        heapify(n, mayor);
    }
}

int busquedaBinaria(int valorBuscado)
{
    int izquierda = 0;
    int derecha = cantidadContenedores - 1;

    while (izquierda <= derecha)
    {
        int medio = (izquierda + derecha) / 2;

        if (pesos[medio] == valorBuscado)
        {
            return medio;
        }

        if (pesos[medio] < valorBuscado)
        {
            izquierda = medio + 1;
        }
        else
        {
            derecha = medio - 1;
        }
    }

    return -1;
}