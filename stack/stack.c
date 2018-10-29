#include <stdlib.h>
#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

void printArray(char *array, int sizeOfArray) {

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

int setArraySize(){
	int sizeOfArray;

	//get array size by input 
	printf("%s", "Input size of array:");
	scanf("%d", &sizeOfArray);
	printf("%s%d \n", "sizeOfArray: ", sizeOfArray);

	return sizeOfArray;
}

void setArrayElement(char *array, int sizeOfArray){
	printf("Enter the elements of the array:\n");
    for (int i = 0; i < sizeOfArray; i++){
    	printf("[%d]:", i);
    	fflush(stdin);
    	scanf("%c", &array[i]);
    	fflush(stdin);
	}

	//print array
	printArray(array, sizeOfArray);
}

bool isEmpty(int sizeOfArray){

	if(sizeOfArray == 0){
		return true;
	}else{
		return false;
	}
}

char* push(char *array, int *sizeOfArray, char elementOfPush) 
{ 	
	printf("%s%c\n", "push element:", elementOfPush);
	
	*sizeOfArray = *sizeOfArray+1;

	char *newArray = realloc(array, (*sizeOfArray) * sizeof(*array));
	newArray[*sizeOfArray-1] = elementOfPush;

	return newArray;
} 

char* pop(char *array, int *sizeOfArray) 
{ 	
	if(!isEmpty(*sizeOfArray)){

		printf("%s%c\n", "pop element:", array[*sizeOfArray-1]);

		*sizeOfArray = *sizeOfArray-1;

		char *newArray = realloc(array, (*sizeOfArray) * sizeof(*array));

		return newArray;

	}else{
		printf("%s", "no element can pop!\n");
		return array;
	}
} 


int main()
{
	/* Set original array */
	//set array size
	int sizeOfArray = setArraySize();
	char  *array = malloc(sizeOfArray * sizeof(*array));
	//erro handle
    if (!array) {
        printf("%s", "There was a problem with malloc.");
        exit(EXIT_FAILURE);
    }
    //set array elements
    setArrayElement(array, sizeOfArray);

    
    /* Push & Pop */
    char choose, 
		 pushElement;

	while(1){
		printf("\n%s", "> A:push B:pop Others:exit :");
	    scanf("%c", &choose);
	    fflush(stdin);

	    if(choose == 'a' || choose == 'A'){
	    	/* push */
	    	printf("%s", "Input push element: ");
	    	scanf("%c", &pushElement);
	    	fflush(stdin);
		    array = push(array, &sizeOfArray, pushElement);
		    printArray(array, sizeOfArray);
	    }else if(choose == 'b' || choose == 'B'){
	    	/* pop */
		    array = pop(array, &sizeOfArray);
		    printArray(array, sizeOfArray);
	    }else{
	    	break;
	    }
	}

    printf("\n%s\n", "Exit");
    printArray(array, sizeOfArray);
    free(array);

	return 0;
}




