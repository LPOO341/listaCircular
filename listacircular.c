// Practica 2 Listas Circulares Jorge Omar Torres Sosa

#include <stdio.h>
#include <stdlib.h>

struct CLLNode
{
	int data;
	struct CLLNode *next;
};

// prototypes
int CircularListLength(struct CLLNode *head);
void PrintCircularListData(struct CLLNode *head);
void InsertAtEndInCLL(struct CLLNode **head, int data);
void InsertAtBeginInCLL(struct CLLNode **head, int data);
void DeleteLastNodeFromCLL(struct CLLNode **head);
void DeleteFrontNodeFromCLL(struct CLLNode **head);
void instrucciones();
int obtenerEntero(char mensaje[]);
void Inicializar(struct CLLNode **head, int valor);

int main()
{
	struct CLLNode *nodoInicio = NULL;
	int opcion, dato;

do
{
	instrucciones();
	opcion = obtenerEntero("Opcion: ");
	switch (opcion)
	{
		case 1:
			dato = obtenerEntero("Ingrese dato: ");
			if (nodoInicio == NULL)
			{
				Inicializar(&nodoInicio, dato);
			}
			else{
				InsertAtBeginInCLL(&nodoInicio, dato);
			}
			PrintCircularListData(nodoInicio);
			break;
		case 2:
			dato = obtenerEntero("Ingrese dato: ");
			if (nodoInicio == NULL)
			{
				Inicializar(&nodoInicio, dato);
			}
			else{
				InsertAtEndInCLL(&nodoInicio, dato);	
			}
			PrintCircularListData(nodoInicio);
			break;
		case 3:
			if(CircularListLength(nodoInicio) > 1)
			{
				DeleteFrontNodeFromCLL(&nodoInicio);
				PrintCircularListData(nodoInicio);
			}
			else
				printf("No puedes eleminar el ultimo elemento\n");
			break;
		case 4:
			if(CircularListLength(nodoInicio) > 1)
			{
				DeleteLastNodeFromCLL(&nodoInicio);
				PrintCircularListData(nodoInicio);
			}
			else
				printf("No puedes eleminar el ultimo elemento\n");
			break;
		case 5:
			printf("El tamaño es: %d\n", CircularListLength(nodoInicio));
			break;
		case 6:
			printf("Saliendo...");
			break;
		default:
			printf("Opcion no valida");
			break;
	}
		
	} while (opcion != 6);
	
	return 0;
}
void instrucciones()
{
	printf("1. Ingresar al inicio\n2. Ingresar al final\n3. Borrar Inicio \n4. Borrar Final \n5. Tamaño Arreglo\n6. Salir");
}
int CircularListLength(struct CLLNode *head)
{
	struct CLLNode *current = head;
	int count = 0;
	if(head == NULL)
		return 0;
	do{
		current = current->next;
		count++;
	}while (current != head);
	return count;
}

void PrintCircularListData(struct CLLNode *head)
{
	struct CLLNode *current = head;
	if(head == NULL)
		return;
	do
	{
		printf("%d",current->data);
		printf("->");
		current = current->next;
	} while (current != head);
	printf("%d\n", head->data);
}

void InsertAtEndInCLL(struct CLLNode **head, int data)
{
	struct CLLNode *current = *head;
	struct CLLNode *newNode = (struct CLLNode *)(malloc(sizeof(struct CLLNode)));
	if(!newNode)
	{
		printf("Memory Error");
		return;
	}
	newNode->data = data;
	while (current->next != *head)
	{
		current = current->next;
	}
	newNode->next = newNode;
	if (*head == NULL)
	{
		*head = newNode;
	}
	else{
		newNode->next = *head;
		current->next = newNode;
	}
}

void InsertAtBeginInCLL(struct CLLNode **head, int data){
	struct CLLNode *current = *head;
	struct CLLNode *newNode = (struct CLLNode *)(malloc(sizeof(struct CLLNode)));
	if(newNode){
		newNode->data = data;
		while (current ->next != *head)
		{
			current = current->next;
		}
		newNode->next = newNode;
		if (*head == NULL)
		{
			*head = newNode;
		}else{
			newNode->next = *head;
			current->next = newNode;
			*head = newNode;
		}
		return;
		
	}
}

void Inicializar(struct CLLNode **head, int valor)
{
	struct CLLNode *newNode = (struct CLLNode *)(malloc(sizeof(struct CLLNode)));
	if(newNode){
		newNode->data = valor;
		newNode->next = newNode;
		*head = newNode;
	}
}

void DeleteLastNodeFromCLL(struct CLLNode **head)
{
	struct CLLNode *temp = *head, *current = *head;
	if (*head == NULL)
	{
		printf("List Empty");
		return;
	}
	while (current->next != *head)
	{
		temp = current;
		current = current->next;
	}
	temp->next = current->next;
	free(current);
	return;
}

void DeleteFrontNodeFromCLL(struct CLLNode **head)
{
	struct CLLNode *temp = *head;
	struct CLLNode *current = *head;
	if (*head == NULL)
	{
		printf("List Empty");
		return;
	}
	while (current->next != *head)
	{
		current = current->next;
	}
	current->next = (*head)->next;
	*head = (*head)->next;
	free(temp);
	return;
}

int obtenerEntero(char mensaje[]) // Elimina la redundacia al obtener los int
{
	int var;
	printf("\n%s", mensaje);
	scanf("%d", &var);
	return var;
}