#include <stdlib.h>
#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

void PrintArray(char *array, int sizeOfArray) {

    printf("Array: ["); // [

    for (int i = 0; i < sizeOfArray - 1; i++) {  
        printf("%c, ", array[i]);
    }

    if (sizeOfArray >= 1){
    	printf("%c", array[sizeOfArray-1]); 
	}

    printf("]\n"); // ]

    printf("%s%p\n\n", "array address: ", array);
}

int SetArraySize(){
	int sizeOfArray;

	//get array size by input 
	printf("%s", "Input size of array:");
	scanf("%d", &sizeOfArray);
	printf("%s%d \n", "sizeOfArray: ", sizeOfArray);
	fflush(stdin);

	return sizeOfArray;
}

bool isFull(int sizeOfArray, int countOfElement){

	if(sizeOfArray == countOfElement){
		return true;
	}else{
		return false;
	}
}

bool isEmpty(int countOfElement){

	if(countOfElement == 0){
		return true;
	}else{
		return false;
	}
}

char* Queue(char *array, int *sizeOfArray, int *countOfElement, char elementOfQueue) 
{ 	
	printf("%s%c\n", "queue element:", elementOfQueue);

	if(isFull(*sizeOfArray, *countOfElement)){
		printf("%s\n", "Array is Full!");
	}else{
		*countOfElement = *countOfElement+1;
		array[*countOfElement-1]=elementOfQueue;
	}
	
	return array;
} 

char* Dequeue(char *array, int *sizeOfArray, int *countOfElement, char *elementOfDequeue) 
{ 	
	*elementOfDequeue = array[0];

	if(isEmpty(*countOfElement)){
		printf("%s\n", "Array is Empty!");
	}else{
		*countOfElement = *countOfElement-1;
		for(int i=0;i<*countOfElement;i++){
			array[i]= array[i+1];
		}
		array[*countOfElement]= '\0';
	}

	return array;
} 


int main()
{
	/* Set original array */
	//set array size
	int sizeOfArray = SetArraySize();
	char  *array = malloc(sizeOfArray * sizeof(*array));
	//erro handle
    if (!array) {
        printf("%s", "There was a problem with malloc.");
        exit(EXIT_FAILURE);
    }

    //initial array
    for (int i = 0; i < sizeOfArray; ++i)
    {
    	array[i]='\0';
    }

    int countOfElement=0;

    /* Queue & Dequeue */
    char choose, 
		 elementOfQueue, elementOfDequeue;

	while(1){
		printf("\n%s", "> A:queue B:dequeue Others:exit :");
	    scanf("%c", &choose);
	    fflush(stdin);

	    if(choose == 'a' || choose == 'A'){
	    	/* queue */
	    	printf("%s", "Input queue element: ");
	    	scanf("%c", &elementOfQueue);
	    	fflush(stdin);
		    array = Queue(array, &sizeOfArray, &countOfElement, elementOfQueue);
		    PrintArray(array, sizeOfArray);
	    }else if(choose == 'b' || choose == 'B'){
	    	/* dequeue */
		    array = Dequeue(array, &sizeOfArray, &countOfElement, &elementOfDequeue);
		    printf("%s%c\n", "elementOfDequeue:", elementOfDequeue);
		    PrintArray(array, sizeOfArray);
	    }else{
	    	break;
	    }
	}

    printf("\n%s\n", "Exit");
    PrintArray(array, sizeOfArray);
    free(array);

	return 0;
}