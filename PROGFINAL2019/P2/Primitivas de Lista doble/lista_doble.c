#include <stdio.h>
#include <stdlib.h>
#include "lista_doble.h"

int compara(const t_info *d1,const t_info*d2)
{
    return d1->dni-d2->dni;
}

void crear_lista_d(t_lista_d * pl)
{
    *pl=NULL;
}

int poner_lista_d(t_lista_d *pl,const t_info *pd)
{
    t_nodo * act=*pl;
    t_nodo *ant,*sig,*nue;
    int comp;
    if(act)
    {
        while (act->sig && (comp=compara(&(*pl)->dato,pd))<0 )
        {
            act=act->sig;
        }
        while (act->ant && (comp=compara(&(*pl)->dato,pd))>0)
        {
            act=act->ant;
        }

        comp=compara(&(*pl)->dato,pd);

        if(comp==0)
            return 2;//DUPLICADO
        if(comp<0)
        {
            ant=act;
            sig=act->sig;
        }
        else
        {
            ant=act->ant;
            sig=act;
        }
    }
    else
        ant=sig=NULL;

    nue=(t_nodo *)malloc(sizeof(t_nodo));
    if (!nue)
        return -5;//SIN MEMORIA
    nue->dato=*pd;
    nue->ant=ant;
    nue->sig=sig;

    if(ant)
        ant->sig=nue;
    if(sig)
        sig->ant=nue;

    *pl=nue;

    return 1;//TODO OK
}

int sacar_lista_d(t_lista_d *pl,t_info *pd)
{
    t_nodo *aux,*ant,*sig;
    int comp;

    if (!*pl)
        return -1;//LISTA VACIA

    while ((*pl)->sig && (comp=compara(&(*pl)->dato,pd))<0)
        pl=&(*pl)->sig;

    while ((*pl)->ant && (comp=compara(&(*pl)->dato,pd))>0)
        pl=&(*pl)->ant;

    comp=compara(&(*pl)->dato,pd);

    if (comp!=0)
        return -2;//NO ENCONTRADO

    aux=*pl;
    ant=aux->ant;
    sig=aux->sig;

    if (ant && sig)
    {
        ant->sig=sig;
        sig->ant=ant;
    }
    else
    {
        if (ant)
            ant->sig=NULL;
        else
            if (sig)
                sig->ant=NULL;
            else
                *pl=NULL;
    }
    free(aux);
    return 1;//TODO OK
}

int busqueda_info(const t_lista_d *pl,t_info *pd)
{
    int comp;
    t_nodo *act=*pl;

    if(!*pl)
        return -2;//LISTA VACIA

    while (act->sig && (comp=compara(&(*pl)->dato,pd))<0)
        act=act->sig;
    while (act->ant && (comp=compara(&(*pl)->dato,pd))>0)
        act=act->ant;
    comp=compara(&(*pl)->dato,pd);
    if(comp!=0)
        return 0;//NO ENCONTRADO
    *pd=act->dato;
    return 1;//TODO OK
}

void vaciar_lista_d(t_lista_d *pl)
{
    t_nodo *paux;
    while ((*pl)->sig)
        pl=&(*pl)->sig;

    while (*pl)
    {
        paux=*pl;
        pl=&paux->ant;
        free(paux);
    }
    *pl=NULL;
    return;
}
//////////////////////////////
int buscaryEliminarDeListaDoble(t_lista* pl,t_info* d)
{
    t_nodo*act=*pl,*ant,*aux;
    if(act)
    {
        while(act->sig&&(comparar(d,&act->info))>0)
            act=act->sig;
        while(act->ant&&(comparar(d,&act->info))<0)
            act=act->ant;
        if((comparar(d,&act->info))==0)
        {
            aux=act;
            *d=aux->info;
            ant=act->ant;
            act=act->sig;
            if(ant)
                ant->sig=act;
            if(act)
                act->ant=ant;
            if((act&&!ant)||(act&&ant)) //act&&ant podria ponerlo dentro, pero para descartar mas rapido lo uso aca
                *pl=act;
            else
            {
                if((!act&&ant))
                    *pl=ant;
                else // !act &&!ant)
                    *pl=NULL;
            }
            free(aux);
            return 1;
        }
    }
    return 0;
}
