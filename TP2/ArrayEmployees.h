#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int idem;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty; // 1 esta vacia --- 0 esta ocupado

} eEmpleado;

#endif // ARRAYEMPLOYEES_H_INCLUDED

#define ASC 0
#define DESC 1

int inicializarEmpleados(eEmpleado empleados[], int tam);
int altaEmpleados(eEmpleado empleados[], int tam, int legajo);
/** \brief nos permite ingresar en nuetra lista empleados
 *
 * \param tomamos por parametros el array de empleados
 * \param nos indica el tamaño de la lista
 * \param ya nos de por orden del ordenador un numero fijo para cada empleado
 * \return esto devuelve 1 si hubo algun error o 0 si se pudo realizar la funcion
 *
 */

int buscarLibre(eEmpleado empleados[], int tam);
/** \brief busca en nuetra lista un legajo en especifico y nos mustra en que lugar se encuentra
 *
 * \param recibe un array de empleados en el cual va a buscar
 * \param recibe un tamaño de la lista
 * \return retorna -1 si no se encontro el legajo que estamos buscando, sino nos devuelve el indice de donde esta ese legajo
 *
 */

void mostrarEmpleado(eEmpleado unEmpleado);
int mostrarEmpleados(eEmpleado empleados[], int tam);
/** \brief nos muestra los todos los empleados del array el cual los recorre y con la funcion mostrarEmpleado
 *
 * \param recibe como parametro el array de empleados
 * \param recibimos el tamaño de la lista
 * \return nos devuelve 1 si dio algun error al mostrar o 0 si relizo lo prometido en esta funcion
 *
 */

int buscarEmpleadoId(eEmpleado empleados[], int tam, int legajo);
/** \brief busca un unico empleado con el mismo ID ingresado
 *
 * \param recibe array de empleados
 * \param recibe su tamaño
 * \param recibe el legajo a buscar
 * \return nos devuelve -1 si no encontro dicho Id o 0 si lo encontro
 *
 */

int bajaEmpleado(eEmpleado empleados[], int tam);
/** \brief busca un empleado con ese id y lo elimina de la lista
 *
 * \param recibe array de empleados
 * \param recibe tamaño del array
 * \return nos devuelve 0 si encontro el Id y lo borro 1 si no encontro Id o 2 si lo encontro y lo cancelo
 *
 */

int modificarEmpleado(eEmpleado empleados[], int tam);
/** \brief busca el empleado por el id y el usuario elije que desea cambiar
 *
 * \param recibe array de empleados
 * \param recibe tamaño del array
 * \return devuelve 0 si pudo cambiar el campo correctamente o 1 si no enocontro id no o lo pudo cambiar
 *
 */

int ordenarApellidos(eEmpleado empleados[], int tam, int criterio);
/** \brief ordena de manera alfabetica A - Z los empleados por apellidos
 *
 * \param recibe array de empleados
 * \param recibe el tamaño del array
 * \param recibe un parametro de 0 o 1 para ordenarlos
 * \return devuelve 0 si los ordeno correctmente o 1 si no pudo
 *
 */

int salarioEmpleado(eEmpleado empleados[], int tam);
/** \brief nos muestra cuanto es el salario total de la empresa, el promedio y cuantos son los empleados con sueldo mayor al basico
 *
 * \param recibe array de tipo empleado
 * \param recibe el tamaño de dicho array
 * \return devuelve 0 si pudo hacer la funcion correctamente o 1 si hubo algun error
 *
 */

