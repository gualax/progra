#ifndef LISTA_DOBLE_H_INCLUDED
#define LISTA_DOBLE_H_INCLUDED

typedef struct
{
    int dni;
    char nombre[5];
}t_dato;

typedef t_dato t_info;

typedef struct s_nodo
{
    t_info dato;
    struct s_nodo* sig;
    struct s_nodo* ant;
}t_nodo;

typedef t_nodo* t_lista_d;

void crear_lista_d(t_lista_d *);
void vaciar_lista_d(t_lista_d *);
int poner_lista_d(t_lista_d *,const t_info*);
int sacar_lista_d(t_lista_d *,t_info *);
int lista_d_llena(const t_lista_d *);
int lista_d_vacia(const t_lista_d *);
int busqueda_info(const t_lista_d *,t_info *);

int compara(const t_info*,const t_info *);

#endif // LISTA_DOBLE_H_INCLUDED
