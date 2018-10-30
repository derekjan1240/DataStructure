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

	return sizeOfArray;
}

void SetArrayElement(char *array, int sizeOfArray){
	printf("Enter the elements of the array:\n");
    for (int i = 0; i < sizeOfArray; i++){
    	printf("[%d]:", i);
    	fflush(stdin);
    	scanf("%c", &array[i]);
    	fflush(stdin);
	}

	//print array
	PrintArray(array, sizeOfArray);
}

bool isEmpty(int sizeOfArray){

	if(sizeOfArray == 0){
		return true;
	}else{
		return false;
	}
}

char* Queue(char *array, int *sizeOfArray, char elementOfQueue) 
{ 	
	printf("%s%c\n", "queue element:", elementOfQueue);
	
	*sizeOfArray = *sizeOfArray+1;

	char *newArray = realloc(array, (*sizeOfArray) * sizeof(*array));
	newArray[*sizeOfArray-1] = elementOfQueue;

	return newArray;
} 

char* Dequeue(char *array, int *sizeOfArray, char *elementOfDequeue) 
{ 	
	if(!isEmpty(*sizeOfArray)){

		*elementOfDequeue = array[0];
		printf("%s%c\n", "dequeue element:", *elementOfDequeue);

		*sizeOfArray = *sizeOfArray-1;
		for(int j=0; j<*sizeOfArray; j++){
			array[j]=array[j+1];
		}

		char *newArray = realloc(array, (*sizeOfArray) * sizeof(*array));

		return newArray;

	}else{
		printf("%s", "no element can dequeue!\n");
		return array;
	}
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
    //set array elements
    SetArrayElement(array, sizeOfArray);

    
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
		    array = Queue(array, &sizeOfArray, elementOfQueue);
		    PrintArray(array, sizeOfArray);
	    }else if(choose == 'b' || choose == 'B'){
	    	/* dequeue */
		    array = Dequeue(array, &sizeOfArray, &elementOfDequeue);
		    // printf("%s%c\n", "elementOfDequeue:", elementOfDequeue);
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