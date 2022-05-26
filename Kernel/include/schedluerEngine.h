
#define MAX_PROCESSES 3
#define MAX_STACK 1000
#define REGISTER_COUNT 17

#define RSP 7               // defino el indice donde guardo el RSP en mi arreglo de registros
#define SHELL 0

/*
 * Definido el formato donde voy a almacenar los contextos de los diferentes proyectos que van a correr,
 * una array que en cada indice va a guardar el valor de cada uno de los registro. 
 */
typedef struct {
    long registers[REGISTER_COUNT];
} Context;

/*
 * Defino el formato que voy a utilizar para almacenar los procesos en mi tabla para hacer context switching
 */
typedef struct {
    Context context;
    int flagRunning;
    char stackFrame[MAX_STACK];
} Process;
          

/* 
* Defino el array para guardar los contextos de todos los procesos que puedo switchear al mismo tiempo.
 * Obs: si tendriamos memoria dinamica esto quedaria mejor.
*/
static Process procesos[MAX_PROCESSES];


/*
    * Defino la cantidad de procesos que tengo corriendo en este mismo momento
    * Obs: siempre tiene que ser menor que MAX_PROCESES
*/
static int processesRunning = 0;

/*
 * Funcion que recibe el puntero a posicion de memoria donde tengo el ultimo contexto y el
 * proceso que es duenio de ese contexto. Luego sobreescribe en el contextHolder el contexto
 * del proximo proceso, y en el contextOwner copia el identificador del contexto.
 */
void switchContext(long * contextHolder, long * contextOwner);
/*
    * Funcion la cual va a copiar todos los registros mandados desde assembler
    * a la struct en el array
*/
static void pushContext(long * contextHolder, long contextOwner);
static void popContext(long * contextHolder, long contextOwner);
/*
    * Funcion que recibe el numero de duenio del contexto para sacarlo del array
*/
void exitProces(long * contextHolder,long * contextOwner);
/*
    * Funcion la cual va a recibir el contexto para iniciar un nuevo proceso
    * obs: si ya hay mas de 2 procesos no se lo agrega
*/
void loadProces(long * contextHolder);
long  nextProcess(long * contextOwner ) ;