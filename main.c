#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingresante.h"
#include "lista_ingresante.h"
#define DNIMAXIMO 99999999
#define AA 181
#define aa 160
#define ee 130
#define ii 161
#define II 214
#define OO 224
#define oo 162
#define uu 163

int controlDNI(lista,long);
void ingresar(lista*);
void buscaringresante (lista);
void mostrarporcarrera(lista);
void mostrar(lista);
ingresantes buscar(lista*);
void modificaringreso(lista*);
void modificarestado(lista*);
void ingresarUnico(lista*);
void inscribirMas(lista*);
void borrarcarrera(lista*);
ingresantes buscarcarrera(lista,int,int*);
void aspirantes(lista);
void auxAP(lista);
int mostrarap(lista,int,ingresantes,int,int);
void almacenarconarchivo(lista);
void cargaconarchivo(lista*,char[]);

int main(){
    int color,menu,admin,user;
    char Archivo[20];
    lista l;
    init(&l);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\nSea bienvenido al practico m%cquina de Valentin Gimenez y Juan Sanchez\n\n",aa);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Antes de comenzar, seleccione el color con el que visualizara la consola.\n\n");
    do{
         printf("[1] Seguir de la misma forma que hasta ahora.\n"
                "[2] Fondo Negro, Letra Blanca Brillante.\n"
                "[3] Fondo Azul, Letra Blanca.\n"
                "[4] Fondo Amarillo, Letra Azul.\n"
                "[5] Fondo Rojo, Letra Blanca.\n"
                "[6] Fondo Negro, Letra Aguamarina.\n");
         scanf("%d",&color);
    }while (color < 1 || color > 6);
    switch (color)
    {
        case 1:break;
        case 2:system("color 0F");break;
        case 3:system("color 1F");break;
        case 4:system("color E9");break;
        case 5:system("color 4F");break;
        case 6:system("color 0B");
    }
    do{
        do{
            system("cls");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\t\t\tSeleccione una opci%cn   \n"
                    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                    "<1> ADMINISTRACI%cN.       \n"
                    "<2> INGRESANTE.           \n"
                    "<3> SALIR.                \n",oo,OO);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            scanf("%d",&menu);
        }while(menu<1||menu>3);
        switch(menu){

            case 1:
                do{
                    do{
                        system("cls");
                        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                        printf("\t\t\tSeleccione una opci%cn \n"
                                "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                                "<1> INGRESAR DATOS.\n"
                                "<2> MOSTRAR LISTA. \n"
                                "<3> BUSCAR INGRESANTE. \n"
                                "<4> MODIFICAR INGRESO.\n"
                                "<5> MODIFICAR ESTADO.\n"
                                "<6> INSCRIBIR A MAS CARRERA/s.\n"
                                "<7> BORRAR INSCRIPCION A CARRERA/S.\n"
                                "<8> MOSTRAR POR CARRERA.\n"
                                "<9> CALCULAR CANTIDAD DE ASPIRANTES POR CARRERA.\n"
                                "<10> VER INGRESANTES QUE APROBARON EL INGRESO DE UNA CARRERA.\n"
                                "<11> PRECARGA CON ARCHIVO.\n"
                                "<12> ALMACENAR LISTA DE INGRESANTES QUE PASAN AL TFA.\n"
                                "<13> SALIR.\n",oo);
                                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                            scanf("%d",&admin);
                    }while(admin<1||admin>13);
                        switch(admin){
                            case 1:
                                system("cls");
                                ingresar(&l);
                                system("pause");
                                break;
                            case 2:
                                system("cls");
                                mostrar(l);
                                system("pause");
                                break;
                            case 3:
                                system("cls");
                                buscaringresante(l);
                                system("pause");
                                break;
                            case 4:
                                system("cls");
                                modificaringreso(&l);
                                system("pause");
                                break;
                            case 5:
                                system("cls");
                                modificarestado(&l);
                                system("pause");
                                break;
                            case 6:
                                system("cls");
                                inscribirMas(&l);
                                system("pause");
                                break;
                            case 7:
                                system("cls");
                                borrarcarrera(&l);
                                system("pause");
                                break;
                            case 8:
                                system("cls");
                                mostrarporcarrera(l);
                                system("pause");
                                break;
                            case 9:
                                system("cls");
                                aspirantes(l);
                                system("pause");
                                break;
                            case 10:
                                system("cls");
                                auxAP(l);
                                system("pause");
                                break;
                            case 11:
                                system("cls");
                                printf("Ingrese el nombre del archivo en el cual va a empezar almacenar sus alumnos \n");
                                getchar();scanf("%s",Archivo);
                                fflush(stdin);
                                strcat(Archivo,".txt");
                                cargaconarchivo(&l,Archivo);
                                break;
                            case 12:
                                system("cls");
                                fflush(stdin);
                                almacenarconarchivo(l);
                                system("pause");
                        }
                }while(admin!=13);
                break;
            case 2:
                do{
                    do{
                        system("cls");
                        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                        printf("\t\t\tSeleccione una opci%cn: \n"
                               "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                                "<1> INGRESAR TUS DATOS DE INGRESANTE.\n"
                                "<2> BUSCAR Y MOSTRAR TUS DATOS.\n"
                                "<3> INSCRIBIRSE EN MAS CARRERAS.\n"
                                "<4> BORRAR INSCRIPCION A CARRERA/S.\n"
                                "<5> SALIR DEL MENU INGRESANTE.\n",oo);
                        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                        scanf("%d",&user);
                    }while(user<1||user>5);
                    switch(user){
                        case 1:
                            system("cls");
                            ingresarUnico(&l);
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            buscaringresante(l);
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            inscribirMas(&l);
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            borrarcarrera(&l);
                            system("pause");
                    }
                }while(user!=5);
                break;
            case 3:
                system("cls");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
                printf("PRACTICO MAQUINA REALIZADO POR: GIMENEZ VALENTIN ALEJANDRO Y JUAN MANUEL SANCHEZ RODRIGUEZ.\n");
                printf("SALIENDO....\n\n\a");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }

    }while(menu!=3);
    return 0;
    }
int controlDNI(lista l, long dni){ /*FUNCION AUXILIAR*/
    reset(&l);
    ingresantes a;
    if(!IsEmpty(l)){
        a=copiar(l);
        while(!isOos(l)&&( ver_dni(a)!= dni))
        {
            forwardd(&l);
            if(!isOos(l))a=copiar(l);
        }
        if(!isOos(l))return 1;
        else return 0;
    }else return 0;
}
void ingresar(lista *l){
    int division,auxp=0;
    int u,u2,u3,n,i=0;
    ingresantes a;
    ingresantes aux;
    printf("Cuantas personas desea ingresar: ");
    scanf("%d",&n);
    while(!IsFull() && i<n){
       system("cls");
        do{
            printf("Ingrese DNI : ");
            getchar(); scanf("%ld" , &aux.DNI);
        }while (aux.DNI < 1 || aux.DNI > DNIMAXIMO);
        if(controlDNI(*l,aux.DNI)!=1){
            do{
                printf("Ingrese apellido del ingresante : ");
                getchar();scanf("%[^\n]s",aux.apellido);
            }while (strlen(aux.apellido) > sizenya);
            do{
                printf("Ingrese nombre del ingresante : ");
                getchar();scanf("%[^\n]s",aux.nombre);
            }while (strlen(aux.nombre) > sizenya);
            do{
                printf("A cuantas carreras se va a inscribir?\n"); getchar();
                scanf("%d",&u2);
            }while (u2<0 || u2> 21);
            for(u=0;u<cant;u++){
                carga_carreras(&a,0,u);
            }
            aux.cantcarreras=0;
            for (u=0;u<u2;u++){
                do{
                    printf("Seleccione una divisi%cn: \n"
                                "<1> INGENIER%cAS.\n"
                                "<2> LICENCIATURAS. \n"
                                "<3> PROFESORADOS.\n"
                                "<4> TECNICATURAS UNIVERSITARIAS.\n",oo,II);
                    scanf("%d",&division);
                }while(division<1||division>4);
                switch(division){
                    case 1:
                        do{
                        printf("[1]Ingenier%ca Electr%cnica con Orientaci%cn en Sistemas Digitales\n"
                                "[2]Ingenier%ca en Computaci%cn\n"
                                "[3]Ingenier%ca en Inform%ctica\n"
                                "[4]Ingenier%ca en Minas\n",ii,oo,oo,ii,oo,ii,aa,ii);
                            printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                            getchar();scanf("%d",&aux.carreras[u]);
                        }while(aux.carreras[u]<1||aux.carreras[u]>4);
                        break;
                    case 2:
                        do{
                        printf("[5]Licenciatura en Ciencias de la Computaci%cn\n"
                                "[6]Licenciatura en Ciencias Geol%cgicas\n"
                                "[7]Licenciatura en Ciencias Matem%cticas\n"
                                "[8]Licenciatura en F%csica\n"
                                "[9]Licenciatura en Matem%ctica Aplicada\n",oo,oo,aa,ii,aa);
                            printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                            getchar();scanf("%d",&aux.carreras[u]);
                        }while(aux.carreras[u]<5||aux.carreras[u]>9);
                        break;
                    case 3:
                        do{
                        printf("[10]Profesorado en Ciencias de la Computaci%cn\n"
                                "[11]Profesorado en F%csica\n"
                                "[12]Profesorado en Matem%ctica\n"
                                "[13]Profesorado en Tecnolog%ca Electr%cnica\n",oo,ii,aa,oo,oo);
                            printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                            getchar();scanf("%d",&aux.carreras[u]);
                        }while(aux.carreras[u]<10||aux.carreras[u]>13);
                        break;
                    case 4:
                        do{
                        printf("[14]Tecnicatura Universitaria en Electr%cnica\n"
                                "[15]Tecnicatura Universitaria en Energ%cas Renovables\n"
                                "[16]Tecnicatura Universitaria en Mineria\n"
                                "[17]Tecnicatura Universitaria en Geoinform%ctica\n"
                                "[18]Tecnicatura Universitaria en Obras Viales  \n"
                                "[19]Tecnicatura Universitaria en Redes de Computadoras\n"
                                "[20]Tecnicatura Universitaria en Telecomunicaciones\n"
                                "[21]Tecnicatura Universitaria en Web\n"
                                "[22]Tecnicatura Universitaria en Fotografia (Se abre en a%cos pares)\n",oo,ii,aa,164);
                            printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                            getchar();scanf("%d",&aux.carreras[u]);
                            if(aux.carreras[u]==22)printf("La tecnicatura universitaria en Fotografia solamente se abre en a%cos pares.\n",164);
                        }while(aux.carreras[u]<14||aux.carreras[u]>21);
                }
                for(u3=0;u3<cant;u3++){
                    while((aux.carreras[u]==ver_carreras(a,u3))&&(u!=u3))
                    {
                        printf("\nUsted ya esta inscripto a esta carrera, seleccione otra: \n\n");
                        do{
                            printf("Seleccione una divisi%cn: \n"
                                        "<1> INGENIER%cAS.\n"
                                        "<2> LICENCIATURAS. \n"
                                        "<3> PROFESORADOS.\n"
                                        "<4> TECNICATURAS UNIVERSITARIAS.\n",oo,II);
                            scanf("%d",&division);
                        }while(division<1||division>4);
                        switch(division){
                            case 1:
                                do{
                                printf("[1]Ingenier%ca Electr%cnica con Orientaci%cn en Sistemas Digitales\n"
                                        "[2]Ingenier%ca en Computaci%cn\n"
                                        "[3]Ingenier%ca en Inform%ctica\n"
                                        "[4]Ingenier%ca en Minas\n",ii,oo,oo,ii,oo,ii,aa,ii);
                                    printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                                    getchar();scanf("%d",&aux.carreras[u]);
                                }while(aux.carreras[u]<1||aux.carreras[u]>4);
                                break;
                            case 2:
                                do{
                                printf("[5]Licenciatura en Ciencias de la Computaci%cn\n"
                                        "[6]Licenciatura en Ciencias Geol%cgicas\n"
                                        "[7]Licenciatura en Ciencias Matem%cticas\n"
                                        "[8]Licenciatura en F%csica\n"
                                        "[9]Licenciatura en Matem%ctica Aplicada\n",oo,oo,aa,ii,aa);
                                    printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                                    getchar();scanf("%d",&aux.carreras[u]);
                                }while(aux.carreras[u]<5||aux.carreras[u]>9);
                                break;
                            case 3:
                                do{
                                printf("[10]Profesorado en Ciencias de la Computaci%cn\n"
                                        "[11]Profesorado en F%csica\n"
                                        "[12]Profesorado en Matem%ctica\n"
                                        "[13]Profesorado en Tecnolog%ca Electr%cnica\n",oo,ii,aa,oo,oo);
                                    printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                                    getchar();scanf("%d",&aux.carreras[u]);
                                }while(aux.carreras[u]<10||aux.carreras[u]>13);
                                break;
                            case 4:
                                do{
                                printf("[14]Tecnicatura Universitaria en Electr%cnica\n"
                                        "[15]Tecnicatura Universitaria en Energ%cas Renovables\n"
                                        "[16]Tecnicatura Universitaria en Mineria\n"
                                        "[17]Tecnicatura Universitaria en Geoinform%ctica\n"
                                        "[18]Tecnicatura Universitaria en Obras Viales  \n"
                                        "[19]Tecnicatura Universitaria en Redes de Computadoras\n"
                                        "[20]Tecnicatura Universitaria en Telecomunicaciones\n"
                                        "[21]Tecnicatura Universitaria en Web\n"
                                        "[22]Tecnicatura Universitaria en Fotografia (Se abre en a%cos pares)\n",oo,ii,aa,164);
                                    printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                                    getchar();scanf("%d",&aux.carreras[u]);
                                    if(aux.carreras[u]==22)printf("La tecnicatura universitaria en Fotografia solamente se abre en a%cos pares\n",164);
                                }while(aux.carreras[u]<14||aux.carreras[u]>21);
                        }
                    }
                }
                carga_carreras(&a,aux.carreras[u],u);
                aux.cantcarreras++;
            }
            do{
                printf("Ingrese si aprob%c o no el ingreso <1> SI <0> NO : ",oo);
                getchar();scanf("%d",&aux.ingreso);
            }while (aux.ingreso!=0 && aux.ingreso!=1);
            do{
                printf("Ingrese si entreg%c o no la documentaci%cn <1> SI <0> NO : ",oo,oo);
                getchar();scanf("%d",&auxp);
            }while (auxp!=0 && auxp!=1);
            if (auxp==0) aux.estado=1;
            if (aux.ingreso==0 && auxp==1) aux.estado=2;
            if (aux.ingreso==1 && auxp==1) aux.estado=3;
            do{
                printf("Ingrese celular de la forma: +CODIGO DE AREA DEL PAIS - CARACTERISTICA DE LA PROVINCIA - NUMERO DE CELULAR.\nEJ:+54 266 4111111\nRESPETE LOS ESPACIOS!!\nSu Numero:+");
                getchar();scanf("%d %d %ld",&aux.celu.carpais,&aux.celu.carprov,&aux.celu.num);
                if(aux.celu.carpais<0||aux.celu.carpais>9999)printf("\nINGRESO INCORRECTAMENTE EL CODIGO DE AREA.\n");
                if(aux.celu.carprov<0||aux.celu.carprov>99999)printf("\nINGRESO INCORRECTAMENTE LA CARACTERISTICA PROVINCIAL.\n");
                if(aux.celu.num<0||aux.celu.num>9999999)printf("\nINGRESO INCORRECTAMENTE SU NUMERO.\n");
            }while((aux.celu.carpais<0||aux.celu.carpais>9999)||(aux.celu.carprov<0||aux.celu.carprov>99999)||(aux.celu.num<0||aux.celu.num>9999999));
            inicializar(&a);
            carga_apellido(&a,aux.apellido);
            carga_celular(&a,aux.celu);
            carga_DNI(&a,aux.DNI);
            carga_estado(&a,aux.estado);
            carga_ingreso(&a,aux.ingreso);
            carga_nombre(&a,aux.nombre);
            carga_cantcarreras(&a,aux.cantcarreras);
            insertar(l,a);
            forwardd(l);
        }else printf("LA PERSONA DE DNI: %ld YA SE ENCUENTRA EN LA LISTA.\n",aux.DNI);
        i++;
    }
    if(IsFull())printf("NO HAY MEMORIA SUFICIENTE.\n");
}
void mostrar(lista l){
    int i,u=1;
    ingresantes a;
    reset(&l);
    celular aux;
    if(!IsEmpty(l)){
        while(!isOos(l))
        {
            a=copiar(l);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Ingresante Nro <%d>\n",u);
            printf("Numero de inscripci%cn: %d\n",oo,ver_inscripcion(a));
            printf("DNI: %ld\n",ver_dni(a));
            printf("Apellido: %s \n",ver_apellido(a));
            printf("Nombre: %s\n",ver_nombre(a));
            printf("Carreras inscriptas: %d\n",ver_cantcarreras(a));
            printf("Carrera/s: \n");
            for(i=0;i<cant;i++)
            {
             if(ver_carreras(a,i)!=0)printf("Carrera Nro <%d>: ",i+1);
                switch(ver_carreras(a,i))
                {
                    case 1:printf("Ingenier%ca Electr%cnica con Orientaci%cn en Sistemas Digitales\n",ii,oo,oo);break;
                    case 2:printf("Ingenier%ca en Computaci%cn\n",ii,oo);break;
                    case 3:printf("Ingenier%ca en Inform%ctica\n",ii,aa);break;
                    case 4:printf("Ingenier%ca en Minas\n",ii);break;
                    case 5:printf("Licenciatura en Ciencias de la Computaci%cn\n",oo);break;
                    case 6:printf("Licenciatura en Ciencias Geol%cgicas\n",oo);break;
                    case 7:printf("Licenciatura en Ciencias Matem%cticas\n",aa);break;
                    case 8:printf("Licenciatura en F%csica\n",ii);break;
                    case 9:printf("Licenciatura en Matem%ctica Aplicada\n",aa);break;
                    case 10:printf("Profesorado en Ciencias de la Computaci%cn\n",oo);break;
                    case 11:printf("Profesorado en F%csica\n",ii);break;
                    case 12:printf("Profesorado en Matem%ctica\n",aa);break;
                    case 13:printf("Profesorado en Tecnolog%ca Electr%cnica\n",ii,oo);break;
                    case 14:printf("Tecnicatura Universitaria en Electr%cnica\n",oo);break;
                    case 15:printf("Tecnicatura Universitaria en Energ%cas Renovables\n",ii);break;
                    case 16:printf("Tecnicatura Universitaria en Miner%ca\n",ii);break;
                    case 17:printf("Tecnicatura Universitaria en Geoinform%ctica\n",aa);break;
                    case 18:printf("Tecnicatura Universitaria en Obras Viales  \n");break;
                    case 19:printf("Tecnicatura Universitaria en Redes de Computadoras\n");break;
                    case 20:printf("Tecnicatura Universitaria en Telecomunicaciones\n");break;
                    case 21:printf("Tecnicatura Universitaria en Web\n");
                }
            }
            if(ver_ingreso(a)==1)printf("Aprob%c el ingreso \n",oo);
            else printf("No aprob%c el ingreso \n",oo);
            aux=ver_celular(a);
            printf("Celular de contacto: +%d%d%ld\n",aux.carpais,aux.carprov,aux.num);
            if(ver_estado(a)==1)printf("Estado: Preinscripto \n");
            else if(ver_estado(a)==2)printf("Estado: Aspirante \n");
            else printf("Estado: Inscripto \n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            forwardd(&l);
            u++;
        }
    }else printf("No es posible realizar esta operaci%cn ya que NO hay elementos cargados en la lista\n",162);
}
ingresantes buscar(lista *l){ /*FUNCION AUXILIAR*/
        reset(l);
        int decision;
        long buscarDNI;
        long buscarNROINS;
        ingresantes a;
        a=copiar(*l);
        do{
            printf("Como desea buscar?\n"
                    "<1> Con numero de DNI.\n"
                    "<2> Con numero de inscripcion.\n");
            scanf("%d",&decision);
        }while(decision!=1&&decision!=2);
        if(decision==1){
            do{
            printf("INGRESE EL DNI DE LA PERSONA QUE BUSCA: ");
            getchar();scanf("%ld",&buscarDNI);
            }while (buscarDNI < 1);
            while(!isOos(*l)&&( ver_dni(a)!= buscarDNI))
            {
                forwardd(l);
                if(!isOos(*l))a=copiar(*l);
            }
            if(!isOos(*l)){
                printf("LA PERSONA BUSCADA EST%c EN LA LISTA.\n",AA);
            }else printf("LA PERSONA BUSCADA NO EST%c EN LA LISTA.\n",AA);
            return a;
        }else{
            do{
            printf("INGRESE EL NRO DE INSCRIPCION DE LA PERSONA QUE BUSCA: ");
            getchar();scanf("%ld",&buscarNROINS);
            }while (buscarNROINS < 1000000 || buscarNROINS >= 10000000);
            while(!isOos(*l)&&( ver_inscripcion(a)!= buscarNROINS))
            {
                forwardd(l);
                if(!isOos(*l))a=copiar(*l);
            }
            if(!isOos(*l)){
                printf("LA PERSONA BUSCADA EST%c EN LA LISTA.\n",AA);
            }else printf("LA PERSONA BUSCADA NO EST%c EN LA LISTA.\n",AA);
            return a;
        }
}
void buscaringresante(lista l ){
    ingresantes a;
    celular aux;
    int i;
    if(!IsEmpty(l)){
        a=buscar(&l);
        if(!isOos(l)){
        system("cls");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Los datos del ingresante buscado son:\n");
        printf("Numero de inscripci%cn: %d\n",oo,ver_inscripcion(a));
        printf("DNI: %ld\n",ver_dni(a));
        printf("Apellido: %s \n",ver_apellido(a));
        printf("Nombre: %s\n",ver_nombre(a));
        printf("Carreras inscriptas: %d\n",ver_cantcarreras(a));
        printf("Carrera/s: \n");
        for(i=0;i<=ver_cantcarreras(a);i++)
        {
            if(ver_carreras(a,i)!=0)printf("Carrera Nro <%d>: ",i+1);
            switch(ver_carreras(a,i))
            {
                case 1:printf("Ingenier%ca Electr%cnica con Orientaci%cn en Sistemas Digitales\n",ii,oo,oo);break;
                case 2:printf("Ingenier%ca en Computaci%cn\n",ii,oo);break;
                case 3:printf("Ingenier%ca en Inform%ctica\n",ii,aa);break;
                case 4:printf("Ingenier%ca en Minas\n",ii);break;

                case 5:printf("Licenciatura en Ciencias de la Computaci%cn\n",oo);break;
                case 6:printf("Licenciatura en Ciencias Geol%cgicas\n",oo);break;
                case 7:printf("Licenciatura en Ciencias Matem%cticas\n",aa);break;
                case 8:printf("Licenciatura en F%csica\n",ii);break;
                case 9:printf("Licenciatura en Matem%ctica Aplicada\n",aa);break;

                case 10:printf("Profesorado en Ciencias de la Computaci%cn\n",oo);break;
                case 11:printf("Profesorado en F%csica\n",ii);break;
                case 12:printf("Profesorado en Matem%ctica\n",aa);break;
                case 13:printf("Profesorado en Tecnolog%ca Electr%cnica\n",ii,oo);break;

                case 14:printf("Tecnicatura Universitaria en Electr%cnica\n",oo);break;
                case 15:printf("Tecnicatura Universitaria en Energ%cas Renovables\n",ii);break;
                case 16:printf("Tecnicatura Universitaria en Miner%ca\n",ii);break;
                case 17:printf("Tecnicatura Universitaria en Geoinform%ctica\n",aa);break;
                case 18:printf("Tecnicatura Universitaria en Obras Viales  \n");break;
                case 19:printf("Tecnicatura Universitaria en Redes de Computadoras\n");break;
                case 20:printf("Tecnicatura Universitaria en Telecomunicaciones\n");break;
                case 21:printf("Tecnicatura Universitaria en Web\n");
            }

        }
        if(ver_ingreso(a)==1)printf("Aprob%c el ingreso \n",oo);
        else printf("No aprob%c el ingreso \n",oo);
        aux=ver_celular(a);
        printf("Celular de contacto: +%d%d%ld\n",aux.carpais,aux.carprov,aux.num);
        if(ver_estado(a)==1)printf("Estado: Preinscripto \n");
        else if(ver_estado(a)==2)printf("Estado: Aspirante \n");
        else printf("Estado: Inscripto \n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
    }else printf("No es posible realizar esta operaci%cn ya que NO hay elementos cargados en la lista\n",162);
}
void modificaringreso(lista *l){
    int aux;
    ingresantes a;
    if(!IsEmpty(*l))
    {
        a=buscar(l);
        if(!isOos(*l))
        {
            do{
                printf("Ingrese el valor correspondiente a si aprob%c o no el ingreso [1] SI [0] NO\n",oo);
                getchar(); scanf("%d",&aux);
            }while (aux != 0 && aux != 1);
            if (ver_ingreso(a) != aux)
            {
                modificar_ingreso(&a,aux);
                if (aux==1 && ver_estado(a)== 2){
                    modificar_estado(&a,3);
                    printf("Ahora el ingresante %s %s al aprobar el ingreso y haber entregado la documentaci%cn es un inscripto\n",ver_nombre(a),ver_apellido(a),oo);
                }
                if (aux==1 && ver_estado(a)==1){
                    printf("El ingresante %s %s tiene aprobado el ingreso pero no llega al estado de inscripto\n"
                           "debido a que no ha entregado a%cn la documentaci%cn correspondiente\n",ver_nombre(a),ver_apellido(a),uu,oo);
                }
                if (aux==0 && ver_estado(a)==3){
                    printf("El ingresante %s %s ahora no ha aprobado el ingreso y al ser antes un inscripto pasa a ser ahora un aspirante.\n",ver_nombre(a),ver_apellido(a));
                    modificar_estado(&a,2);
                }
                if (aux==0 && ver_estado(a)==1){
                    printf("El ingresante %s %s ahora ha sido modificado y no ha aprobado el ingreso y tampoco ha entregado la documentaci%cn por lo que su estado sigue siendo preinscripto.\n",ver_nombre(a),ver_apellido(a),oo);
                }
                supress(l);
                insertar(l,a);
            }
            else
            {
                printf("No se hizo ninguna modificaci%cn, se ingreso el mismo valor que estaba antes\n",oo);
            }
        }
    }
    else printf("No es posible realizar esta operaci%cn ya que NO hay elementos cargados en la lista\n",oo);
}
void modificarestado(lista *l){
    int aux,tres=0;
    ingresantes a;
    if(!IsEmpty(*l))
    {
        a=buscar(l);
        if (ver_estado(a)==3)tres=1;
        if(!isOos(*l))
        {
            printf("Aclaraci%cn: Si el estudiante aprob%c el ingreso y entrego los papeles es automaticamente un inscripto\n\n",oo,oo);
            do{
                printf("Ingrese el nuevo estado:\n"
                       "<1> Preinscripto (No aprob%c ingreso ni entrego documentaci%cn)\n"
                       "<2> Aspirante (Documentaci%cn entregada pero ingreso a%cn no aprobado)\n"
                       "<3> Inscripto (Ingreso aprobado y documetaci%cn entregada)\n",oo,oo,oo,uu,oo);
                getchar(); scanf("%d",&aux);
            }while (aux != 1 && aux != 2 && aux != 3);
            if (ver_estado(a) != aux)
            {
                modificar_estado(&a,aux);
                if (ver_ingreso(a)==1 && ver_estado(a)== 2 && tres==0){
                    printf("Ahora el estado del ingresante %s %s es inscripto porque entrego documentaci%cn y aprob%c el ingreso\n",ver_nombre(a),ver_apellido(a),oo,oo);
                    modificar_estado(&a,3);
                }
                if (ver_ingreso(a)==0 && ver_estado(a)==2 && tres==0){
                    printf("El ingresante %s %s entreg%c la documentaci%cn pero no ha aprobado el ingreso a%cn\n"
                           "por ende, no alcanza el estado de inscripto\n",ver_nombre(a),ver_apellido(a),oo,oo,uu);
                }
                if (ver_ingreso(a)==1 && ver_estado(a)==1 && tres==0){
                    printf("El estudiante tiene aprobado el ingreso pero a%cn no entrega la documentaci%cn requerida\n",uu,oo);
                }
                if (ver_ingreso(a)==0 && ver_estado(a)==1 && tres==0){
                    printf("El ingresante %s %s es ahora un preinscripto, no ha entregado ni documentaci%cn ni ha aprobado el ingreso\n",ver_nombre(a),ver_apellido(a),oo);
                }
                if (ver_estado(a)==2 && tres==1){
                    printf("El ingresante %s %s estaba en el estado de inscripto pero fue modificado hacia aspirante\n"
                           "Por ende, ahora no tiene aprobado el ingreso\n",ver_nombre(a),ver_apellido(a));
                    modificar_ingreso(&a,0);
                }
                if (ver_estado(a)==1 && tres==1){
                    printf("El ingresante %s %s estaba en el estado de inscripto pero fue modificado hacia preinscripto\n"
                           "Por ende, ahora no ha aprobado el ingreso ni ha entregado documentaci%cn\n",ver_nombre(a),ver_apellido(a),oo);
                    modificar_ingreso(&a,0);
                }
                if (ver_estado(a)==3){
                    printf("Ahora el ingresante %s %s es un inscripto.\n",ver_nombre(a),ver_apellido(a));
                    modificar_ingreso(&a,1);
                }
                    supress(l);
                    insertar(l,a);
            }
            else
            {
                printf("No se hizo ninguna modificaci%cn, se ingreso el mismo valor que estaba antes\n",oo);
            }
        }
    }
    else printf("No es posible realizar esta operaci%cn ya que NO hay elementos cargados en la lista\n",oo);
}
void ingresarUnico(lista *l){
    int division;
    int u,u2,u3;
    ingresantes a;
    ingresantes aux;
    if(!IsFull()){
        system("cls");
        printf("Ingrese sus datos: \n");
        do{
            printf("Ingrese DNI : ");
            getchar(); scanf("%ld" , &aux.DNI);
        }while (aux.DNI < 1 || aux.DNI > DNIMAXIMO);
        if(controlDNI(*l,aux.DNI)!=1){
            do{
                printf("Ingrese su apelido: ");
                getchar();scanf("%[^\n]s",aux.apellido);
            }while (strlen(aux.apellido) > sizenya);
            do{
                printf("Ingrese su nombre: ");
                getchar();scanf("%[^\n]s",aux.nombre);
            }while (strlen(aux.nombre) > sizenya);
            do{
                printf("A cuantas carreras se va a inscribir?\n"); getchar();
                scanf("%d",&u2);
            }while (u2<0 || u2> 21);
            for(u=0;u<cant;u++){
                carga_carreras(&a,0,u);
            }
            aux.cantcarreras=0;
            for (u=0;u<u2;u++){
                do{
                    printf("Seleccione una divisi%cn: \n"
                            "<1> INGENIER%cAS.\n"
                            "<2> LICENCIATURAS. \n"
                            "<3> PROFESORADOS.\n"
                            "<4> TECNICATURAS UNIVERSITARIAS.\n",oo,II);
                    scanf("%d",&division);
                }while(division<1||division>4);
                switch(division){
                    case 1:
                        printf("[1]Ingenier%ca Electr%cnica con Orientaci%cn en Sistemas Digitales\n"
                                "[2]Ingenier%ca en Computaci%cn\n"
                                "[3]Ingenier%ca en Inform%ctica\n"
                                "[4]Ingenier%ca en Minas\n",ii,oo,oo,ii,oo,ii,aa,ii);
                        do{
                            printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                            getchar();scanf("%d",&aux.carreras[u]);
                        }while(aux.carreras[u]<1||aux.carreras[u]>4);
                        break;
                    case 2:
                        printf("[5]Licenciatura en Ciencias de la Computaci%cn\n"
                                "[6]Licenciatura en Ciencias Geol%cgicas\n"
                                "[7]Licenciatura en Ciencias Matem%cticas\n"
                                "[8]Licenciatura en F%csica\n"
                                "[9]Licenciatura en Matem%ctica Aplicada\n",oo,oo,aa,ii,aa);
                        do{
                            printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                            getchar();scanf("%d",&aux.carreras[u]);
                        }while(aux.carreras[u]<5||aux.carreras[u]>9);
                        break;
                    case 3:
                        printf("[10]Profesorado en Ciencias de la Computaci%cn\n"
                                "[11]Profesorado en F%csica\n"
                                "[12]Profesorado en Matem%ctica\n"
                                "[13]Profesorado en Tecnolog%ca Electr%cnica\n",oo,ii,aa,ii,oo);
                        do{
                            printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                            getchar();scanf("%d",&aux.carreras[u]);
                        }while(aux.carreras[u]<10||aux.carreras[u]>13);
                        break;
                    case 4:
                        printf("[14]Tecnicatura Universitaria en Electr%cnica\n"
                                "[15]Tecnicatura Universitaria en Energ%cas Renovables\n"
                                "[16]Tecnicatura Universitaria en Mineria\n"
                                "[17]Tecnicatura Universitaria en Geoinform%ctica\n"
                                "[18]Tecnicatura Universitaria en Obras Viales  \n"
                                "[19]Tecnicatura Universitaria en Redes de Computadoras\n"
                                "[20]Tecnicatura Universitaria en Telecomunicaciones\n"
                                "[21]Tecnicatura Universitaria en Web\n"
                                "[22]Tecnicatura Universitaria en Fotografia (Se abre en a%cos pares)\n",oo,ii,aa,164);
                        do{
                            printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                            getchar();scanf("%d",&aux.carreras[u]);
                            if(aux.carreras[u]==22)printf("La tecnicatura universitaria en Fotografia solamente se abre en a%cos pares\n",164);
                        }while(aux.carreras[u]<14||aux.carreras[u]>21);
                }
                for(u3=0;u3<cant;u3++){
                    while((aux.carreras[u]==ver_carreras(a,u3))&&(u!=u3))
                    {
                        printf("\nUsted ya esta inscripto a esta carrera, seleccione otra: \n\n");
                        do{
                            printf("Seleccione una divisi%cn: \n"
                                        "<1> INGENIER%cAS.\n"
                                        "<2> LICENCIATURAS. \n"
                                        "<3> PROFESORADOS.\n"
                                        "<4> TECNICATURAS UNIVERSITARIAS.\n",oo,II);
                            scanf("%d",&division);
                        }while(division<1||division>4);
                        switch(division){
                            case 1:
                                printf("[1]Ingenier%ca Electr%cnica con Orientaci%cn en Sistemas Digitales\n"
                                        "[2]Ingenier%ca en Computaci%cn\n"
                                        "[3]Ingenier%ca en Inform%ctica\n"
                                        "[4]Ingenier%ca en Minas\n",ii,oo,oo,ii,oo,ii,aa,ii);
                                do{
                                    printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                                    getchar();scanf("%d",&aux.carreras[u]);
                                }while(aux.carreras[u]<1||aux.carreras[u]>4);
                                break;
                            case 2:
                                printf("[5]Licenciatura en Ciencias de la Computaci%cn\n"
                                        "[6]Licenciatura en Ciencias Geol%cgicas\n"
                                        "[7]Licenciatura en Ciencias Matem%cticas\n"
                                        "[8]Licenciatura en F%csica\n"
                                        "[9]Licenciatura en Matem%ctica Aplicada\n",oo,oo,aa,ii,aa);
                                do{
                                    printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                                    getchar();scanf("%d",&aux.carreras[u]);
                                }while(aux.carreras[u]<5||aux.carreras[u]>9);
                                break;
                            case 3:
                                printf("[10]Profesorado en Ciencias de la Computaci%cn\n"
                                        "[11]Profesorado en F%csica\n"
                                        "[12]Profesorado en Matem%ctica\n"
                                        "[13]Profesorado en Tecnolog%ca Electr%cnica\n",oo,ii,aa,oo,oo);
                                do{
                                    printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                                    getchar();scanf("%d",&aux.carreras[u]);
                                }while(aux.carreras[u]<10||aux.carreras[u]>13);
                                break;
                            case 4:
                                printf("[14]Tecnicatura Universitaria en Electr%cnica\n"
                                        "[15]Tecnicatura Universitaria en Energ%cas Renovables\n"
                                        "[16]Tecnicatura Universitaria en Mineria\n"
                                        "[17]Tecnicatura Universitaria en Geoinform%ctica\n"
                                        "[18]Tecnicatura Universitaria en Obras Viales  \n"
                                        "[19]Tecnicatura Universitaria en Redes de Computadoras\n"
                                        "[20]Tecnicatura Universitaria en Telecomunicaciones\n"
                                        "[21]Tecnicatura Universitaria en Web\n"
                                        "[22]Tecnicatura Universitaria en Fotografia (Se abre en a%cos pares)\n",oo,ii,aa,164);
                                do{
                                    printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                                    getchar();scanf("%d",&aux.carreras[u]);
                                    if(aux.carreras[u]==22)printf("La tecnicatura universitaria en Fotografia solamente se abre en a%cos pares\n",164);
                                }while(aux.carreras[u]<14||aux.carreras[u]>21);
                        }
                    }
                }
                carga_carreras(&a,aux.carreras[u],u);
                aux.cantcarreras++;
            }
            do{
                printf("Ingrese celular de la forma: +CODIGO DE AREA DEL PAIS - CARACTERISTICA DE LA PROVINCIA - NUMERO DE CELULAR.\nEJ:+54 266 4111111\nRESPETE LOS ESPACIOS!!\nSu Numero:+");
                getchar();scanf("%d %d %ld",&aux.celu.carpais,&aux.celu.carprov,&aux.celu.num);
                if(aux.celu.carpais<0||aux.celu.carpais>9999)printf("\nINGRESO INCORRECTAMENTE EL CODIGO DE AREA.\n");
                if(aux.celu.carprov<0||aux.celu.carprov>99999)printf("\nINGRESO INCORRECTAMENTE LA CARACTERISTICA PROVINCIAL.\n");
                if(aux.celu.num<0||aux.celu.num>9999999)printf("\nINGRESO INCORRECTAMENTE SU NUMERO.\n");
            }while((aux.celu.carpais<0||aux.celu.carpais>9999)||(aux.celu.carprov<0||aux.celu.carprov>99999)||(aux.celu.num<0||aux.celu.num>9999999));
            inicializar(&a);
            carga_apellido(&a,aux.apellido);
            carga_celular(&a,aux.celu);
            carga_DNI(&a,aux.DNI);
            carga_estado(&a,1);
            carga_ingreso(&a,0);
            carga_nombre(&a,aux.nombre);
            carga_cantcarreras(&a,aux.cantcarreras);
            insertar(l,a);
            forwardd(l);
        }else printf("LA PERSONA DE DNI: %ld YA SE ENCUENTRA EN LA LISTA.\n",aux.DNI);
    }else printf("NO HAY MEMORIA SUFICIENTE.\n");
}
void inscribirMas(lista *l){
    int u,u2,u3,division;
    ingresantes a;
    ingresantes aux;
    if(!IsEmpty(*l)){
        a=buscar(l);
        if(!isOos(*l)){
            do{
                printf("A cuantas carreras se va a inscribir?\n");
                getchar();scanf("%d",&u2);
            }while (u2<0 || (u2+ver_cantcarreras(a))> 21);
            u2+=ver_cantcarreras(a);
            aux.cantcarreras=ver_cantcarreras(a);
            for (u=(ver_cantcarreras(a));u<u2;u++)
            {
                do{
                    printf("Seleccione una divisi%cn: \n"
                        "<1> INGENIER%cAS.\n"
                        "<2> LICENCIATURAS. \n"
                        "<3> PROFESORADOS.\n"
                        "<4> TECNICATURAS UNIVERSITARIAS.\n",oo,II);
                    scanf("%d",&division);
                }while(division<1||division>4);
                switch(division){
                    case 1:
                        printf("[1]Ingenier%ca Electr%cnica con Orientaci%cn en Sistemas Digitales\n"
                                "[2]Ingenier%ca en Computaci%cn\n"
                                "[3]Ingenier%ca en Inform%ctica\n"
                                "[4]Ingenier%ca en Minas\n",ii,oo,oo,ii,oo,ii,aa,ii);
                        do{
                            printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                            getchar();scanf("%d",&aux.carreras[u]);
                        }while(aux.carreras[u]<1||aux.carreras[u]>4);
                        break;
                    case 2:
                        printf("[5]Licenciatura en Ciencias de la Computaci%cn\n"
                                "[6]Licenciatura en Ciencias Geol%cgicas\n"
                                "[7]Licenciatura en Ciencias Matem%cticas\n"
                                "[8]Licenciatura en F%csica\n"
                                "[9]Licenciatura en Matem%ctica Aplicada\n",oo,oo,aa,ii,aa);
                        do{
                            printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                            getchar();scanf("%d",&aux.carreras[u]);
                        }while(aux.carreras[u]<5||aux.carreras[u]>9);
                        break;
                    case 3:
                        printf("[10]Profesorado en Ciencias de la Computaci%cn\n"
                                "[11]Profesorado en F%csica\n"
                                "[12]Profesorado en Matem%ctica\n"
                                "[13]Profesorado en Tecnolog%ca Electr%cnica\n",oo,ii,aa,ii,oo);
                        do{
                            printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                            getchar();scanf("%d",&aux.carreras[u]);
                        }while(aux.carreras[u]<10||aux.carreras[u]>13);
                        break;
                    case 4:
                        printf("[14]Tecnicatura Universitaria en Electr%cnica\n"
                                "[15]Tecnicatura Universitaria en Energ%cas Renovables\n"
                                "[16]Tecnicatura Universitaria en Mineria\n"
                                "[17]Tecnicatura Universitaria en Geoinform%ctica\n"
                                "[18]Tecnicatura Universitaria en Obras Viales  \n"
                                "[19]Tecnicatura Universitaria en Redes de Computadoras\n"
                                "[20]Tecnicatura Universitaria en Telecomunicaciones\n"
                                "[21]Tecnicatura Universitaria en Web\n"
                                "[22]Tecnicatura Universitaria en Fotografia (Se abre en a%cos pares)\n",oo,ii,aa,164);
                        do{
                            printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                            getchar();scanf("%d",&aux.carreras[u]);
                            if(aux.carreras[u]==22)printf("La tecnicatura universitaria en Fotografia solamente se abre en a%cos pares\n",164);
                        }while(aux.carreras[u]<14||aux.carreras[u]>21);
                }
                for(u3=0;u3<cant;u3++){
                    while(aux.carreras[u]==ver_carreras(a,u3))
                    {
                        printf("\nUsted ya esta inscripto a esta carrera, seleccione otra: \n\n");
                        do{
                            printf("Seleccione una divisi%cn: \n"
                                        "<1> INGENIER%cAS.\n"
                                        "<2> LICENCIATURAS. \n"
                                        "<3> PROFESORADOS.\n"
                                        "<4> TECNICATURAS UNIVERSITARIAS.\n",oo,II);
                            scanf("%d",&division);
                        }while(division<1||division>4);
                        switch(division){
                            case 1:
                                printf("[1]Ingenier%ca Electr%cnica con Orientaci%cn en Sistemas Digitales\n"
                                        "[2]Ingenier%ca en Computaci%cn\n"
                                        "[3]Ingenier%ca en Inform%ctica\n"
                                        "[4]Ingenier%ca en Minas\n",ii,oo,oo,ii,oo,ii,aa,ii);
                                do{
                                    printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                                    getchar();scanf("%d",&aux.carreras[u]);
                                }while(aux.carreras[u]<1||aux.carreras[u]>4);
                                break;
                            case 2:
                                printf("[5]Licenciatura en Ciencias de la Computaci%cn\n"
                                        "[6]Licenciatura en Ciencias Geol%cgicas\n"
                                        "[7]Licenciatura en Ciencias Matem%cticas\n"
                                        "[8]Licenciatura en F%csica\n"
                                        "[9]Licenciatura en Matem%ctica Aplicada\n",oo,oo,aa,ii,aa);
                                do{
                                    printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                                    getchar();scanf("%d",&aux.carreras[u]);
                                }while(aux.carreras[u]<5||aux.carreras[u]>9);
                                break;
                            case 3:
                                printf("[10]Profesorado en Ciencias de la Computaci%cn\n"
                                        "[11]Profesorado en F%csica\n"
                                        "[12]Profesorado en Matem%ctica\n"
                                        "[13]Profesorado en Tecnolog%ca Electr%cnica\n",oo,ii,aa,oo,oo);
                                do{
                                    printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                                    getchar();scanf("%d",&aux.carreras[u]);
                                }while(aux.carreras[u]<10||aux.carreras[u]>13);
                                break;
                            case 4:
                                printf("[14]Tecnicatura Universitaria en Electr%cnica\n"
                                        "[15]Tecnicatura Universitaria en Energ%cas Renovables\n"
                                        "[16]Tecnicatura Universitaria en Mineria\n"
                                        "[17]Tecnicatura Universitaria en Geoinform%ctica\n"
                                        "[18]Tecnicatura Universitaria en Obras Viales  \n"
                                        "[19]Tecnicatura Universitaria en Redes de Computadoras\n"
                                        "[20]Tecnicatura Universitaria en Telecomunicaciones\n"
                                        "[21]Tecnicatura Universitaria en Web\n"
                                        "[22]Tecnicatura Universitaria en Fotografia (Se abre en a%cos pares)\n",oo,ii,aa,164);
                                do{
                                    printf("\nIngrese el numero de la carrera a la que desea inscribirse: ");
                                    getchar();scanf("%d",&aux.carreras[u]);
                                    if(aux.carreras[u]==22)printf("La tecnicatura universitaria en Fotografia solamente se abre en a%cos pares\n",164);
                                }while(aux.carreras[u]<14||aux.carreras[u]>21);
                        }
                    }
                }
                carga_carreras(&a,aux.carreras[u],u);
                aux.cantcarreras++;
            }
            carga_cantcarreras(&a,aux.cantcarreras);
            supress(l);
            insertar(l,a);
        }
        printf("Se ha inscrito a las nuevas carreras exitosamente\n");

    }else printf("No es posible realizar esta operaci%cn ya que NO hay elementos cargados en la lista\n",oo);
}
void borrarcarrera(lista *l){
    int u=0,u2=0,u3=0,division=0,c=0;
    ingresantes a;
    ingresantes aux;
    int carr;
    int mov[cant];
    if(!IsEmpty(*l)){
        a=buscar(l);
        if(!isOos(*l))
        {
            do{
                printf("De cuantas carreras se va a borrar?\n");
                scanf("%d",&u2);getchar();
            }while (u2<0 || u2 > ver_cantcarreras(a));
            for (u=0;u<u2;u++)
            {
                do{
                    printf("Seleccione una divisi%cn: \n"
                            "<1> INGENIER%cAS.\n"
                            "<2> LICENCIATURAS. \n"
                            "<3> PROFESORADOS.\n"
                            "<4> TECNICATURAS UNIVERSITARIAS.\n",oo,II);
                    scanf("%d",&division); getchar();
                }while(division<1||division>4);
                switch(division){
                    case 1:
                        printf("[1]Ingenier%ca Electr%cnica con Orientaci%cn en Sistemas Digitales\n"
                                "[2]Ingenier%ca en Computaci%cn\n"
                                "[3]Ingenier%ca en Inform%ctica\n"
                                "[4]Ingenier%ca en Minas\n",ii,oo,oo,ii,oo,ii,aa,ii);
                        do{
                            printf("\nIngrese el numero de la carrera a la que desea borrarse: ");
                            scanf("%d",&carr); getchar();
                        }while(carr < 1||carr > 4);
                        break;
                    case 2:
                        printf("[5]Licenciatura en Ciencias de la Computaci%cn\n"
                                "[6]Licenciatura en Ciencias Geol%cgicas\n"
                                "[7]Licenciatura en Ciencias Matem%cticas\n"
                                "[8]Licenciatura en F%csica\n"
                                "[9]Licenciatura en Matem%ctica Aplicada\n",oo,oo,aa,ii,aa);
                        do{
                            printf("\nIngrese el numero de la carrera a la que desea borrarse: ");
                            scanf("%d",&carr); getchar();
                        }while(carr < 5||carr > 9);
                        break;
                    case 3:
                        printf("[10]Profesorado en Ciencias de la Computaci%cn\n"
                                "[11]Profesorado en F%csica\n"
                                "[12]Profesorado en Matem%ctica\n"
                                "[13]Profesorado en Tecnolog%ca Electr%cnica\n",oo,ii,aa,ii,oo);
                        do{
                            printf("\nIngrese el numero de la carrera a la que desea borrarse: ");
                            scanf("%d",&carr); getchar();
                        }while(carr < 10||carr > 13);
                        break;
                    case 4:
                        printf("[14]Tecnicatura Universitaria en Electr%cnica\n"
                                "[15]Tecnicatura Universitaria en Energ%cas Renovables\n"
                                "[16]Tecnicatura Universitaria en Mineria\n"
                                "[17]Tecnicatura Universitaria en Geoinform%ctica\n"
                                "[18]Tecnicatura Universitaria en Obras Viales  \n"
                                "[19]Tecnicatura Universitaria en Redes de Computadoras\n"
                                "[20]Tecnicatura Universitaria en Telecomunicaciones\n"
                                "[21]Tecnicatura Universitaria en Web\n",oo,ii,aa);
                        do{
                            printf("\nIngrese el numero de la carrera a la que desea borrarse: ");
                            scanf("%d",&carr); getchar();
                        }while(carr < 14||carr > 21);
                }
                for(u3=0;u3<cant;u3++){
                    if (carr == ver_carreras(a,u3))
                    {
                        modificar_carreras(&a,0,u3);
                        c+=1;
                    }
                }
                if(c==0)printf("No esta inscripto en la carrera ingresada.\n");
            }
            aux.cantcarreras=0;
            for(u=0;u<cant;u++){
                if(ver_carreras(a,u)!=0)aux.cantcarreras++;
            }
            carga_cantcarreras(&a,aux.cantcarreras);
            for(u=0;u<cant;u++){
                mov[u]=0;
            }
            if(ver_cantcarreras(a)>=1)
            {
                u=0;
                while(u<ver_cantcarreras(a))
                {
                    for(u2=0;u2<cant;u2++)
                    {
                        if(ver_carreras(a,u2)!=0)
                        {
                            mov[u]=ver_carreras(a,u2);
                            u++;
                        }
                    }
                }
                for(u=0;u<cant;u++){
                    modificar_carreras(&a,mov[u],u);
                }
                supress(l);
                insertar(l,a);
                printf("Te has borrado de la/las carreras exitosamente\n");
            }else
            {
                supress(l);
                printf("El ingresante ahora no esta inscripto en ninguna carrera por lo que ha sido borrado de la lista.\n");
            }
        }

    }else printf("No es posible realizar esta operaci%cn ya que NO hay elementos cargados en la lista\n",oo);
}
ingresantes buscarcarrera(lista l,int carr,int *encontrado){ /*FUNCION AUXILIAR*/
    ingresantes a;
    a=copiar(l);
    int i;
    *encontrado=0;
    while(!isOos(l) && *encontrado!=1 && *encontrado!=2)
    {
        for(i=0;i<cant;i++)
        {
            if(carr==ver_carreras(a,i))*encontrado=1;
        }
        if(*encontrado!=1)*encontrado=2;

    }
    return a;

}
void mostrarporcarrera(lista l){
    ingresantes a;
    int division,carr,encontrado,c=0,x=1;
    reset(&l);
    if(!IsEmpty(l)){
        do{
            printf("Seleccione una divisi%cn: \n"
                    "<1> INGENIER%cAS.\n"
                    "<2> LICENCIATURAS. \n"
                    "<3> PROFESORADOS.\n"
                    "<4> TECNICATURAS UNIVERSITARIAS.\n",oo,II);
            scanf("%d",&division);
        }while(division<1||division>4);
        switch(division){
            case 1:
                printf("[1]Ingenier%ca Electr%cnica con Orientaci%cn en Sistemas Digitales\n"
                        "[2]Ingenier%ca en Computaci%cn\n"
                        "[3]Ingenier%ca en Inform%ctica\n"
                        "[4]Ingenier%ca en Minas\n",ii,oo,oo,ii,oo,ii,aa,ii);
                do{
                    printf("\nIngrese el numero de la carrera de la que quiere ver los inscriptos: ");
                    getchar();scanf("%d",&carr);
                }while(carr<1||carr>4);
                break;
            case 2:
                printf("[5]Licenciatura en Ciencias de la Computaci%cn\n"
                        "[6]Licenciatura en Ciencias Geol%cgicas\n"
                        "[7]Licenciatura en Ciencias Matem%cticas\n"
                        "[8]Licenciatura en F%csica\n"
                        "[9]Licenciatura en Matem%ctica Aplicada\n",oo,oo,aa,ii,aa);
                do{
                    printf("\nIngrese el numero de la carrera de la que quiere ver los inscriptos: ");
                    getchar();scanf("%d",&carr);
                }while(carr<5||carr>9);
                break;
            case 3:
                printf("[10]Profesorado en Ciencias de la Computaci%cn\n"
                        "[11]Profesorado en F%csica\n"
                        "[12]Profesorado en Matem%ctica\n"
                        "[13]Profesorado en Tecnolog%ca Electr%cnica\n",oo,ii,aa,oo,oo);
                do{
                    printf("\nIngrese el numero de la carrera de la que quiere ver los inscriptos: ");
                    getchar();scanf("%d",&carr);
                }while(carr<10||carr>13);
                break;
            case 4:
                printf("[14]Tecnicatura Universitaria en Electr%cnica\n"
                        "[15]Tecnicatura Universitaria en Energ%cas Renovables\n"
                        "[16]Tecnicatura Universitaria en Mineria\n"
                        "[17]Tecnicatura Universitaria en Geoinform%ctica\n"
                        "[18]Tecnicatura Universitaria en Obras Viales  \n"
                        "[19]Tecnicatura Universitaria en Redes de Computadoras\n"
                        "[20]Tecnicatura Universitaria en Telecomunicaciones\n"
                        "[21]Tecnicatura Universitaria en Web\n",oo,ii,aa);
                do{
                    printf("\nIngrese el numero de la carrera de la que quiere ver los inscriptos: ");
                    getchar();scanf("%d",&carr);
                }while(carr<14||carr>21);
        }
        while(!isOos(l))
        {
            a=buscarcarrera(l,carr,&encontrado);
            if(encontrado==1)
            {
                c+=1;
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("Ingresante de la carrera ingresada Nro <%d>\n",x);
                printf("Nombre: %s\n",ver_nombre(a));
                printf("Apellido: %s \n",ver_apellido(a));
                printf("DNI: %ld\n",ver_dni(a));
                x+=1;
            }
            forwardd(&l);
        }
        if (c==0)
        {
            printf("No hay ingresantes inscriptos en la carrera seleccionada\n");
        }
    }else printf("No es posible realizar esta operaci%cn ya que NO hay elementos cargados en la lista\n",oo);
}
void cargaconarchivo(lista *l, char nombre[]){
    int i;
    char espacio[30];
    ingresantes a;
    ingresantes aux;
    FILE *Fp;
    Fp = fopen(nombre,"r");
    if (Fp == NULL)
    {
        printf("El archivo que ingreso no es valido \n");
    }else{
        while (!feof(Fp))
        {
            if(!IsFull()){
                fscanf(Fp,"%d\n",&aux.nroinscripcion);
                fscanf(Fp,"%ld\n",&aux.DNI);
                fscanf(Fp, "%[^\n] s",aux.apellido);
                fscanf(Fp, "%[^\n] s",aux.nombre);
                fscanf(Fp,"%d",&aux.cantcarreras);
                for(i=0;i<aux.cantcarreras;i++){
                fscanf(Fp,"%d",&aux.carreras[i]);}
                fscanf(Fp,"%d",&aux.ingreso);
                fscanf(Fp,"%d %d %ld",&aux.celu.carpais,&aux.celu.carprov,&aux.celu.num);
                fscanf(Fp,"%d",&aux.estado);
                fscanf(Fp,"%s",espacio);
                carganroinscripcion(&a,aux.nroinscripcion);
                carga_DNI(&a,aux.DNI);
                carga_apellido(&a,aux.apellido);
                carga_nombre(&a,aux.nombre);
                for (i=0;i<aux.cantcarreras;i++)carga_carreras(&a,aux.carreras[i],i);
                for (i=aux.cantcarreras;i<cant;i++)carga_carreras(&a,0,i);
                carga_ingreso(&a,aux.ingreso);
                carga_celular(&a,aux.celu);
                carga_estado(&a,aux.estado);
                carga_cantcarreras(&a,aux.cantcarreras);
                insertar(l,a);
                forwardd(l);
            }else{
                printf("No hay suficiente memoria.\n");
                fclose(Fp);
                return;/*No retorno nada, solo lo utilizo para salir de la funcion*/
                }
        }
    fclose(Fp);
    }
}
void aspirantes(lista l){
    ingresantes a;
    int i,u=0,division,buscado;
    reset(&l);
    if (!IsEmpty(l))
    {
        printf("A continuaci%cn seleccione la carrera de la cual quiere ver los ingresantes en estado de aspirante\n",oo);
        do{
            printf("Seleccione una divisi%cn: \n"
                    "<1> INGENIER%cAS.\n"
                    "<2> LICENCIATURAS. \n"
                    "<3> PROFESORADOS.\n"
                    "<4> TECNICATURAS UNIVERSITARIAS.\n",oo,II);
            scanf("%d",&division); getchar();
        }while(division<1||division>4);
        switch(division){
            case 1:
                printf("[1]Ingenier%ca Electr%cnica con Orientaci%cn en Sistemas Digitales\n"
                        "[2]Ingenier%ca en Computaci%cn\n"
                        "[3]Ingenier%ca en Inform%ctica\n"
                        "[4]Ingenier%ca en Minas\n",ii,oo,oo,ii,oo,ii,aa,ii);
                do{
                    printf("\nIngrese el numero de la carrera de la que desea saber los ingresantes en estado de aspirante: ");
                    scanf("%d",&buscado); getchar();
                }while(buscado<1||buscado>4);
                break;
            case 2:
                printf("[5]Licenciatura en Ciencias de la Computaci%cn\n"
                        "[6]Licenciatura en Ciencias Geol%cgicas\n"
                        "[7]Licenciatura en Ciencias Matem%cticas\n"
                        "[8]Licenciatura en F%csica\n"
                        "[9]Licenciatura en Matem%ctica Aplicada\n",oo,oo,aa,ii,aa);
                do{
                    printf("\nIngrese el numero de la carrera de la que desea saber los ingresantes en estado de aspirante: ");
                    scanf("%d",&buscado); getchar();
                }while(buscado<5||buscado>9);
                break;
            case 3:
                printf("[10]Profesorado en Ciencias de la Computaci%cn\n"
                        "[11]Profesorado en F%csica\n"
                        "[12]Profesorado en Matem%ctica\n"
                        "[13]Profesorado en Tecnolog%ca Electr%cnica\n",oo,ii,aa,ii,oo);
                do{
                    printf("\nIngrese el numero de la carrera de la que desea saber los ingresantes en estado de aspirante: ");
                    scanf("%d",&buscado); getchar();
                }while(buscado<10||buscado>13);
                break;
            case 4:
                printf("[14]Tecnicatura Universitaria en Electr%cnica\n"
                        "[15]Tecnicatura Universitaria en Energ%cas Renovables\n"
                        "[16]Tecnicatura Universitaria en Mineria\n"
                        "[17]Tecnicatura Universitaria en Geoinform%ctica\n"
                        "[18]Tecnicatura Universitaria en Obras Viales  \n"
                        "[19]Tecnicatura Universitaria en Redes de Computadoras\n"
                        "[20]Tecnicatura Universitaria en Telecomunicaciones\n"
                        "[21]Tecnicatura Universitaria en Web\n",oo,ii,aa);
                do{
                    printf("\nIngrese el numero de la carrera de la que desea saber los ingresantes en estado de aspirante: ");
                    scanf("%d",&buscado); getchar();
                }while(buscado<14||buscado>21);
        }
        while (!isOos(l))
        {
            a=copiar(l);
            for (i=0;i<cant;i++){
            if (ver_estado(a)==2 && ver_carreras(a,i)==buscado)
            {
                u+=1;
            }}
            forwardd(&l);
        }
        if (u==0) printf("No hay ingresantes de la carrera ingresada en el estado de aspirante\n");
        else printf("La cantidad de ingresantes en el estado de aspirante en la carrera elegida es de %d\n",u);
    }
    else printf("No es posible realizar esta operaci%cn ya que no hay elementos cargados en la lista\n",oo);
}
void auxAP(lista l){/**/
    int buscado,opc,ap;
    ingresantes aux;
    if (IsEmpty(l)) printf("No es posible realizar esta operaci%cn ya que no hay elementos cargados en la lista\n",oo);
    else{
        reset(&l);
        printf("A continuaci%cn seleccione la carrera de la cual quiere ver los ingresaantes que aprobaron el ingreso\n",oo);
        do{
            printf("Seleccione una divisi%cn: \n"
                    "<1> INGENIER%cAS.\n"
                    "<2> LICENCIATURAS. \n"
                    "<3> PROFESORADOS.\n"
                    "<4> TECNICATURAS UNIVERSITARIAS.\n",oo,II);
            scanf("%d",&opc); getchar();
        }while(opc<1||opc>4);
        switch(opc){
            case 1:
                printf("[1]Ingenier%ca Electr%cnica con Orientaci%cn en Sistemas Digitales\n"
                        "[2]Ingenier%ca en Computaci%cn\n"
                        "[3]Ingenier%ca en Inform%ctica\n"
                        "[4]Ingenier%ca en Minas\n",ii,oo,oo,ii,oo,ii,aa,ii);
                do{
                    printf("\nIngrese el numero de la carrera de la cual quiere ver los ingresantes que aprobaron el ingreso: ");
                    scanf("%d",&buscado); getchar();
                }while(buscado<1||buscado>4);
                break;
            case 2:
                printf("[5]Licenciatura en Ciencias de la Computaci%cn\n"
                        "[6]Licenciatura en Ciencias Geol%cgicas\n"
                        "[7]Licenciatura en Ciencias Matem%cticas\n"
                        "[8]Licenciatura en F%csica\n"
                        "[9]Licenciatura en Matem%ctica Aplicada\n",oo,oo,aa,ii,aa);
                do{
                    printf("\nIngrese el numero de la carrera de la cual quiere ver los ingresantes que aprobaron el ingreso: ");
                    scanf("%d",&buscado); getchar();
                }while(buscado<5||buscado>9);
                break;
            case 3:
                printf("[10]Profesorado en Ciencias de la Computaci%cn\n"
                        "[11]Profesorado en F%csica\n"
                        "[12]Profesorado en Matem%ctica\n"
                        "[13]Profesorado en Tecnolog%ca Electr%cnica\n",oo,ii,aa,ii,oo);
                do{
                    printf("\nIngrese el numero de la carrera de la cual quiere ver los ingresantes que aprobaron el ingreso: ");
                    scanf("%d",&buscado); getchar();
                }while(buscado<10||buscado>13);
                break;
            case 4:
                printf("[14]Tecnicatura Universitaria en Electr%cnica\n"
                        "[15]Tecnicatura Universitaria en Energ%cas Renovables\n"
                        "[16]Tecnicatura Universitaria en Mineria\n"
                        "[17]Tecnicatura Universitaria en Geoinform%ctica\n"
                        "[18]Tecnicatura Universitaria en Obras Viales  \n"
                        "[19]Tecnicatura Universitaria en Redes de Computadoras\n"
                        "[20]Tecnicatura Universitaria en Telecomunicaciones\n"
                        "[21]Tecnicatura Universitaria en Web\n",oo,ii,aa);
                do{
                    printf("\nIngrese el numero de la carrera de la cual quiere ver los ingresantes que aprobaron el ingreso: ");
                    scanf("%d",&buscado); getchar();
                }while(buscado<14||buscado>21);
        }
        ap=mostrarap(l,buscado,aux,0,0);
        if(ap==0)printf("No hay ningun ingresante en la carrera ingresada o no hay ningun ingresante que aprobo el ingreso en la la carrera ingresada.\n");
    }
}
int mostrarap(lista l,int buscado,ingresantes a,int encontrado,int u){
    if (isOos(l)==1){
        return u;
    }else{
        a=buscarcarrera(l,buscado,&encontrado);
        if (encontrado==1 && ver_ingreso(a)==1){
            u=u+1;
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Ingresante Nro <%d>\n",u);
            printf("Nombre: %s\n",ver_nombre(a));
            printf("Apellido: %s \n",ver_apellido(a));
            printf("DNI: %ld\n",ver_dni(a));
        }
        forwardd(&l);
        mostrarap(l,buscado,a,encontrado,u);
    }
} /* WARNING SIN SENTIDO */
void almacenarconarchivo(lista l){
    int i,u=1,c=0;
    reset(&l);
    ingresantes a;
    celular aux;
    char espacio[85]="~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    FILE *Fp;
    if(!IsEmpty(l)){
        Fp = fopen("Ingresantes2021.txt","w");
        if (Fp == NULL)
        {
            printf("El archivo no pudo ser creado\n");
        }else{
            while (isOos(l)==0)
            {
                a=copiar(l);
                if (a.ingreso==0)
                {
                    c++;
                    fprintf(Fp,"Ingresante TFA Nro <%d>\n",u);
                    fprintf(Fp,"Nombre: %s\n",ver_nombre(a));
                    fprintf(Fp,"Apellido: %s\n",ver_apellido(a));
                    fprintf(Fp,"DNI: %ld\n",ver_dni(a));
                    for(i=0;i<cant;i++){
                    if(ver_carreras(a,i)!=0)fprintf(Fp,"Carrera Nro <%d>: ",i+1);
                    switch(ver_carreras(a,i))
                            {
                                case 1:fprintf(Fp,"Ingenieria Electronica con Orientacion en Sistemas Digitales\n");break;
                                case 2:fprintf(Fp,"Ingenieria en Computacion\n");break;
                                case 3:fprintf(Fp,"Ingenieria en Informatica\n");break;
                                case 4:fprintf(Fp,"Ingenieria en Minas\n");break;
                                case 5:fprintf(Fp,"Licenciatura en Ciencias de la Computacion\n");break;
                                case 6:fprintf(Fp,"Licenciatura en Ciencias Geologicas\n");break;
                                case 7:fprintf(Fp,"Licenciatura en Ciencias Matematicas\n");break;
                                case 8:fprintf(Fp,"Licenciatura en Fisica\n");break;
                                case 9:fprintf(Fp,"Licenciatura en Matematica Aplicada\n");break;
                                case 10:fprintf(Fp,"Profesorado en Ciencias de la Computacion\n");break;
                                case 11:fprintf(Fp,"Profesorado en Fisica\n");break;
                                case 12:fprintf(Fp,"Profesorado en Matematica\n");break;
                                case 13:fprintf(Fp,"Profesorado en Tecnologia Electronica\n");break;
                                case 14:fprintf(Fp,"Tecnicatura Universitaria en Electronica\n");break;
                                case 15:fprintf(Fp,"Tecnicatura Universitaria en Energias Renovables\n");break;
                                case 16:fprintf(Fp,"Tecnicatura Universitaria en Mineria\n");break;
                                case 17:fprintf(Fp,"Tecnicatura Universitaria en Geoinformatica\n");break;
                                case 18:fprintf(Fp,"Tecnicatura Universitaria en Obras Viales  \n");break;
                                case 19:fprintf(Fp,"Tecnicatura Universitaria en Redes de Computadoras\n");break;
                                case 20:fprintf(Fp,"Tecnicatura Universitaria en Telecomunicaciones\n");break;
                                case 21:fprintf(Fp,"Tecnicatura Universitaria en Web\n");
                            }
                    }
                    aux=ver_celular(a);
                    fprintf(Fp,"Celular de contacto: +%d%d%ld\n",aux.carpais,aux.carprov,aux.num);
                    fprintf(Fp,"%s",espacio);
                    u++;
                }
                    forwardd(&l);
            }
        fclose(Fp);
        if(c!=0)printf("Los ingresantes que pasan al TFA han sido cargados en el archivo Ingresantes2021.txt correctamente\n");
        else printf("No hay ingresantes que pasan al TFA\n");
        }
    }else printf("No es posible realizar esta operaci%cn ya que no hay elementos cargados en la lista\n",oo);
}
