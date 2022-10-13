#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Multiply Function
int dimension=0; 
int ** multiply (int ** a, int** b) 
{
	int t=0;
	int ** product = (int **)malloc(sizeof(int *) * dimension);
	int i;
	for (i =0; i<dimension; i++) 
    {
		product[i] = (int *)malloc(sizeof(int)* dimension);
	}
	int y;
    int p;
    int x;
	for (y=0; y< dimension; y++)
    {
		for (p=0; p< dimension; p++)
        {
			for (x=0; x< dimension; x++)
            {
				t= t+ a[y][x] * b[x][p];
			}
			product[y][p] = t;
			t=0;
		}
	}	
	return product;
}
//main function
int main (int argc, char** argv) 
{
	int size = 0;
	for (size=0; argv[1][size]!='\0'; size++) 
    {
	};
	size++;
	char * filename = (char *)malloc(sizeof(char)*size);
	strcpy(filename, argv[1]);
    FILE *fp;
	fp = fopen(filename, "r");
    fscanf(fp, "%d\n", &dimension);
	if (!fp) 
    {
		printf("error\n");
		return 0;
	}
	int ** result = (int ** )malloc(sizeof(int *) * dimension);
    int ** matrix = (int ** )malloc(sizeof(int *) * dimension);
	int i;
	for (i=0; i<dimension; i++) 
    {
		result[i] = (int*)malloc(sizeof(int) * dimension);
		matrix[i] = (int*)malloc(sizeof(int) * dimension);
	}
	int j;
	for (i=0; i<dimension; i++)
    {
		for (j=0; j<dimension; j++) 
        {
			fscanf(fp, "%d", &matrix[i][j]);
			result[i][j] = matrix [i][j];
		}
	}

	int power =0;
	fscanf(fp, "%d", &power);

	for (i=1; i<power; i++) 
    {

		result = multiply(matrix, result);	
	}
	for (i=0; i<dimension; i++)
    {
		for (j=0; j<dimension; j++) 
        {
			printf("%d", result[i][j]);
			if (j<(dimension-1)) 
            {
            printf(" ");
            }
		}
		printf("\n");
	}
    if (power==0) 
    {
		for (i=0; i<dimension; i++)
        {
			for (j=0; j<dimension; j++) 
            {
				if (i==j) 
                {
					result[i][j] = 1;
				}
                else 
                {
					result[i][j] = 0;
				}
				
			}
		} 
	}

	fclose(fp);

	return 0;
}