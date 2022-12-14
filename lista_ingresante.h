#ifndef LISTA_INGRESANTE_H_INCLUDED
#define LISTA_INGRESANTE_H_INCLUDED

/*---------------------------------------*/
typedef struct NODO{
    ingresantes vipd;
    struct NODO *siguiente;
}NODO;

typedef struct{
    NODO *acc;
    NODO *cur;
    NODO *aux;
}lista;

/*---------------------------------------*/
/*                 INIT                  */
/*---------------------------------------*/
void init(lista *a){
    (*a).cur= NULL;
    (*a).acc= NULL;
    (*a).aux= NULL;
}
/*---------------------------------------*/
/*                INSERTAR               */
/*---------------------------------------*/
void insertar(lista *a, ingresantes ins){
    NODO *m=(NODO*)malloc(sizeof(NODO));

    (*m).vipd=ins;
    if((*a).cur==(*a).acc){
        (*m).siguiente=(*a).cur;
        (*a).acc=m;
        (*a).cur=m;
    }else{
        (*((*a).aux)).siguiente = m;
        (*m).siguiente = (*a).cur;
        (*a).cur = (*((*a).aux)).siguiente;
    }
}
/*---------------------------------------*/
/*                FORWARD                */
/*---------------------------------------*/
void forwardd(lista *a){
    (*a).aux=(*a).cur;
    (*a).cur=(*((*a).cur)).siguiente;
}
/*---------------------------------------*/
/*                 RESET                 */
/*---------------------------------------*/
void reset(lista *a){
    (*a).cur=(*a).acc;
    (*a).aux=(*a).acc;
}
/*---------------------------------------*/
/*                SUPRESS                */
/*---------------------------------------*/
void supress(lista *a){

    if((*a).acc==(*a).cur){
        (*a).acc=(*((*a).cur)).siguiente;
        free((*a).cur);
        (*a).cur=(*a).acc;
    }else{
        (*((*a).aux)).siguiente=(*((*a).cur)).siguiente;
        free((*a).cur);
        (*a).cur=(*((*a).aux)).siguiente;
    }
}
/*---------------------------------------*/
/*                 IsEmpty               */
/*---------------------------------------*/
int IsEmpty(lista a){
    if(a.acc==NULL)return 1;
    else return 0;
}
/*---------------------------------------*/
/*                 IsFull                */
/*---------------------------------------*/
int IsFull()
{
    NODO *m=(NODO*)malloc(sizeof(NODO));
    if(m==NULL){
        free((void*)m);
        return 1;
    }else{
        free((void*)m);
        return 0;
    }
}
/*---------------------------------------*/
/*                 IsOos                */
/*---------------------------------------*/
int isOos(lista a)
{
    if(a.cur==NULL) return 1;
    else return 0;
}
/*---------------------------------------*/
/*                 COPY                  */
/*---------------------------------------*/
ingresantes copiar(lista a){
    return a.cur->vipd;
}
/*---------------------------------------*/
#endif // LISTA_INGRESANTE_H_INCLUDED
