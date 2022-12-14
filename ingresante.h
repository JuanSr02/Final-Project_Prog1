#ifndef INGRESANTE_H_INCLUDED
#define INGRESANTE_H_INCLUDED

#define sizenya 60
#define cant 22
#define sizenro 20

typedef struct{
    int carpais;/*'54'*/
    int carprov;/*'266'*/
    long num;/*'4111111'*/
}celular;
typedef struct{
    int nroinscripcion; /**/
    long DNI;   /**/
    char apellido[sizenya]; /**/
    char nombre[sizenya];   /**/
    int carreras[cant]; /*;*/
    int ingreso;    /*1= aprobo ; 0= no aprobo*/
    celular celu; /* DE LA FORMA XX XXX XXXXXXX. */
    int estado; /*1= inscripto ; 2= aspirante ; 3= preinscripto*/
    int cantcarreras;   /* cuenta en cuantas carreras esta inscripto el estudiante */
}ingresantes;

/*CARGA*/
    void inicializar(ingresantes *a){
    (*a).nroinscripcion= 1000000 + rand() % (10000000-1000000);
    }
    void carganroinscripcion(ingresantes *a,int reg){
    (*a).nroinscripcion=reg;
    }
    void carga_DNI(ingresantes *a, long dni){
    (*a).DNI=dni;
    }
    void carga_apellido(ingresantes *a,char apellido[]){
    strcpy((*a).apellido,apellido);
    }
    void carga_nombre(ingresantes *a,char nombre[]){
    strcpy((*a).nombre,nombre);
    }
    void carga_carreras(ingresantes *a, int carr,int i){
    (*a).carreras[i]=carr;
    }
    void carga_ingreso(ingresantes *a,int ingreso){
    (*a).ingreso=ingreso;
    }
    void carga_celular(ingresantes *a,celular cel){
    (*a).celu=cel;
    }
    void carga_estado(ingresantes *a,int estado){
    (*a).estado=estado;
    }
    void carga_cantcarreras(ingresantes *a, int posicion){
    (*a).cantcarreras=posicion;
    }
/*MODIFICAR*/
    void modificar_carreras(ingresantes *a, int carr,int i){
    (*a).carreras[i]=carr;
    }
    void modificar_ingreso(ingresantes *a,int ingreso){
    (*a).ingreso=ingreso;
    }
    void modificar_estado(ingresantes *a,int estado){
    (*a).estado=estado;
    }

/*MOSTRAR*/
    int ver_inscripcion(ingresantes a){
    return a.nroinscripcion;
    }
    long ver_dni(ingresantes a){
    return a.DNI;
    }
    char* ver_apellido(ingresantes a){
    char* aux;
    aux=(char*)malloc(strlen(a.apellido)+1);
    strcpy(aux,a.apellido);
    return aux;
    }
    char* ver_nombre(ingresantes a){
    char* aux;
    aux=(char*)malloc(strlen(a.nombre)+1);
    strcpy(aux,a.nombre);
    return aux;
    }
    int ver_carreras(ingresantes a,int i){
    return a.carreras[i];
    }
    int ver_ingreso(ingresantes a){
    return a.ingreso;
    }
    celular ver_celular(ingresantes a){
    return a.celu;
    }
    int ver_estado(ingresantes a){
    return a.estado;
    }
    int ver_cantcarreras(ingresantes a){
    return a.cantcarreras;
    }

#endif // INGRESANTE_H_INCLUDED
