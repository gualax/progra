#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#define TODO_BIEN 1
#define SIM_MEM 500

typedef struct
{
    long int dni;
    char nombre[36];
    int edad;
}t_info;

typedef struct s_nodo
{
    t_info info;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo *t_lista;

#endif // GLOBAL_H_INCLUDED
