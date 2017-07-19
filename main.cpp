#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>

using namespace std;


//Variables

string input;
string opcion;
string lista_asesores[5][3];
string citas[5][8];
string title; // Cambia el nombre del encabezado
string disponibilidad;
string deseo;
string status;
string newstatus;
int tot_dis_counter=0;
int tot_ocu_counter=0;
int dis_counter = 0;
int ocu_counter = 0;
int indx;
int i_a=0;
int continuar = 1;
int cont_la = 0; // Contador de la lista de asesores.
int rows = 4;
int cols = 1;
int i=0;
int j;






int listado_asesores()

    {
        cout << "\n\n";
        cout << title;
        cout << "\n\n\n\n";

        cout << "\t Codigo   |   Nombre  \n";
        cout << "\t-----------------------------";
        cout << "\n\n";

        for (int j=0; j<=4; j++)
            {
                cout << "\t   ";
                cout << lista_asesores[j][0];
                cout << "    |   ";
                cout << lista_asesores[j][1];
                cout << "\n";

            }
        cout << "\n\n\n";



    }

int busca_asesor()

    {
       cout << "\tIntroduzca el Codigo de Asesor que desea visualizar: ";

        getline(cin, opcion);


        // Con el siguiente for, vamos a buscar el codigo del asesor para obtener un indice.
        for (int a=0; a<=4; a++)

            {
                if (lista_asesores[a][0] == opcion)
                    {
                        i_a = a; //indice de busqueda para futura referencia [Index_Asesor]
                        cout << "\n";
                    }
            }

        //Ahora se procede a usar el indice para mostrar la disponibilidad

        cout << "\t";
        cout << "\n\n\t Agenda del Asesor\n\n";
        cout << "\t";
        cout << " Codigo\t| Nombre\t| Cita 1\t | Cita 2\t| Cita 3\t| Cita 4\t| Cita 5\t| Cita 6\t|";
        cout << "\n\t-------------------------------------------------------------------------------------------------------------------------";
        cout << "\n\t  ";

    }

int disp_ocu()


    {

        listado_asesores();

        busca_asesor();

        for (int c=0; c<=7; c++)
            {
                cout << " ";
                cout << citas[i_a][c];

                cout << "\t|";

            }

        cout << "\n\n\n";
        cout << disponibilidad;
        cout << "\t";
        for (int d=2; d<=7; d++)
            {
                 if (citas[i_a][d] == status)
                    {
                        int e = d-1;
                        cout << e;
                        cout << " , ";
                    }

            }

        cout << "\n\n";

        //Aqui el usuario digita el numero y se agenda en la matriz.

        cout << "Cual Turno desea ";
        cout << deseo;
        cout << " ?:";

        cin >> indx;
        indx = indx + 1;  //Ante los ojos puede ser un numero, pero en la matriz debemos movernos un campo


        cout << "\n\n\n";



        citas[i_a][indx] = newstatus;

        system("pause");



    }

int submenu_4()

    {
        title = "\tListado de Asesores";
        listado_asesores();
        system("pause");
    }

int inicia_matriz()



    {

        cout << "\n\n";
cout << "por aqu";
system("pause");
        for (int l=0; l<=i-1; l++)

            {
                citas[l][0] = lista_asesores[l][0];
                citas[l][1] = lista_asesores[l][1];

                for (int m=2; m<=7; m++)
                    {
                       citas[l][m] = "Disponible";
                    }
            }
    }

int imprime_matriz()

    {

        cout << "\t";
        cout << "\n\n Ahora si a imprimir la matriz.\n\n";

        cout << "\tCodigo  |\tNombre  |\tCita 1  |\tCita 2  |\tCita 3  |\tCita 4  |\tCita 5  |\tCita 6  |";
        cout << "\n\t-------------------------------------------------------------------------------------------------------------------------";
        cout << "\n\t  ";
            for (int o=0; o<=4; o++)
                {
                    for (int p=0; p<=7; p++)
                        {
                           cout << " ";
                           cout << citas[o][p];
                           cout << " ";
                           cout << "\t|" ;
                        }
                    cout << "\n\t  ";
                }
    }

int submenu_5()

    {
        cout << "\n\n\n";
        cout << "\tVisualizacion de Turnos";
        cout << "\n";
        cout << "\t-------------------------";
        cout << "\n\n\n";


        if (i>0)
            {
                imprime_matriz();
            }

        else
            {

                cout << "\tNo Existen Asesores en el Sistema\n";
                cout << "\n\n\n";

            }



    }

int submenu_6()

    {
        listado_asesores();
        busca_asesor();


         for (int h=0; h<=7; h++)
            {
                cout << " ";
                cout << citas[i_a][h];

                cout << "\t|";

            }

        cout << "\n\n";

        system("pause");


    }


int submenu_7()

    {
        system("cls");
        cout << "\t\t";
        cout << "\tEn Total hay ";
        cout << i;
        cout << " Asesores de 5";

        cout << "\n\n";

        for (int t=0; t<i; t++)

            {
                for (int u=0; u<=7; u++)
                       {
                           if (citas[t][u] == "Disponible")
                               {
                                    dis_counter++;
                                    tot_dis_counter++;
                               }

                            if (citas[t][u] == "Ocupado")

                                {
                                    ocu_counter++;
                                    tot_ocu_counter++;
                                }

                       }
                cout << "El Asesor ";
                cout << citas[t][1];
                cout << " Cuenta con ";
                cout << dis_counter;
                cout << " Citas Disponibles, y con ";
                cout << ocu_counter;
                cout << " Citas Ocupadas \n";

                dis_counter=0;
                ocu_counter=0;
            }

                cout << "\n\n";
                cout << "En total de todos los asesores hay ";
                cout << tot_dis_counter;
                cout << " Citas Disponibles y un total de ";
                cout << tot_ocu_counter;
                cout << " Citas Ocupadas";

                tot_dis_counter=0;
                tot_ocu_counter=0;

                cout << "\n\n";


    }

// la siguiente funcion es el menu, que podra ser llamado luego.

int submenu_3()

{
        status = "Ocupado"; //Visualiza cuales estan ocupados
        newstatus ="Disponible"; //Actualiza y lo hace disponible
        title = "\tEliminar Cita";
        disponibilidad = "\tTurnos a Eliminar\n";
        deseo = "Eliminar";
        disp_ocu();
}


int submenu_2()

    {
        status = "Disponible"; // Visualiza los disponibles
        newstatus = "Ocupado"; // Actualiza y lo hace Ocupado.
        title = "\tNueva Cita";
        disponibilidad = "\tTurnos Disponibles\n";
        deseo = "Agendar";
        disp_ocu(); // Funcion que servira tanto para anadir como para eliminar.

    }

int submenu_1()

    {
        //Este menu va agregar los asesores en una tabla (matriz) llamada lista_asesores
        //Validamos si puede continuar por falta de campos

        if (i > 4)
        {
            cout << "\n\n\n";
            cout << "\tNo hay mas campos disponibles, \n";
            cout << "\n\n\n";
            system("pause");
        }

        while ((i <=4) && (continuar = 1 ))


            {

                system("cls");
                cout << "\n\n\n";
                cout << "\t------------------------------------\n\n";
                cout << "\tSub Menu --- Agregar Asesor ----\n\n";
                cout << "\t------------------------------------\n";
                cout << "\n\n";
                cout << "\tExisten ";
                cout << 5-i;
                cout << " Campos Disponibles";
                cout << "\n\n\n\n\n";
                cout << "\t Introduzca Codigo de Asesor: ";
                getline(cin, input);

                //Valida si el codigo es de 3 digitos o no

                while (input.length() != 3)

                {
                    cout << "\n\n";
                    cout << "\tError El Codigo debe ser de 3 digitos\n\n";
                    cout << "\t Introduzca Codigo de Asesor: ";
                    getline(cin, input);

                }


                lista_asesores[i][0] = input;
                cout << "\n";
                cout << "\t Nombre Completo por Favor: ";
                getline(cin, input);

                //Validamos que sea un nombre de al menos 10 caracteres

                lista_asesores[i][1] = input;
                lista_asesores[i][2] = i+1;   //Se le asigna un orden para evitar un algoritmo posterior.
                cont_la++;
                i++;

                cout << "\n\n";
                cout << "\tDesea Agregar otro asesor (S/N) ?";
                getline(cin, input);

                //Para ver si continua o no.

                if (input == "S")
                    {
                        continuar = 1;
                    }

                if (input == "N")
                    {
                        inicia_matriz();
                        continuar = 0;
                        system("cls");
                        return 0;


                    }

                else
                    {
                        continuar = 0;
                    }


            }


    }


int menu()
{

    // Se hace un ciclo para repetir el menu, si se escoje el 8, termina el ciclo y se cierra el programa

    while (opcion != "8")

    {

        system("cls");
        cout << "\n\n\n";
        cout << "\t Bienvenido al Menu Principal \n";
        cout << "\t ---------------------------- \n";
        cout << "\n";
        cout << "\t Escoja una opcion\n";
        cout << "\n\n";

        cout << "\t (1) Agregar Asesor\n";
        cout << "\t (2) Nueva Cita\n";
        cout << "\t (3) Eliminar Cita\n";
        cout << "\t (4) Listado de Asesores\n";
        cout << "\t (5) Listado de Turnos\n";
        cout << "\t (6) Listado de turnos ocupados para un asesor especifico\n";
        cout << "\t (7) Listado Resumen\n";
        cout << "\t (8) Salir del Programa\n";
        cout << "\n\n";
        cout << "\t Introduzca un numero y presione Enter: ";

        // A continuacion almacena la seleccion en una variable para trato posterior.

        getline(cin, opcion);
        cout << opcion;

        // Ahora se valida y se llaman los submenues

        if (opcion == "1")
            {
                system("cls");
                submenu_1();
            }

        if (opcion == "2")

            {
                system("cls");
                submenu_2();
            }

        if (opcion == "3")
            {
                system("cls");
                submenu_3();
            }

        if (opcion == "4")
            {
                system("cls");
                submenu_4();
            }

        if (opcion == "5")

            {
                system("cls");
                submenu_5();
                system("pause");
            }

        if (opcion == "6")
            {
                system("cls");
                submenu_6();
            }

        if (opcion == "7")

        {
            system("cls");
            submenu_7();
            system("pause");
        }


        /*
        if (opcion == "2")
            {submenu_2();}
        if (opcion == "3")
            {submenu_3);



        if (opcion == "4")
            {submenu_4);}
        if (opcion == "5")
            {submenu_5);
        if (opcion == "6")
            {submenu_6);}
        if (opcion == "7")
            {submenu_7);
        if (opcion == "8")
            {submenu_2();}
    */

    }

}



int main() // Funcion Principal

    {

    menu();  // Se llama a la funcion Menu
    }

