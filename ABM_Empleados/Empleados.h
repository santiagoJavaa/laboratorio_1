

typedef struct{

 int legajo_empleado;
 char nombre[51];
 char apellido[51];
 char sexo[15];
 float salario;
 int fechaDeIngreso[20];
 char sector[51];
 int estado;


}eEmpleados;

void inicializa_Empleados(eEmpleados empleaods[], int tamanioEmpleado);

void datos_hardcode_Empleados(eEmpleados empleados[], int tamanioEmpleados);

void lista_empleados(eEmpleados empleados[], int tamanioEmpleados);
