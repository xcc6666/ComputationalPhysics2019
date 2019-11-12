#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
//mpic++ -o pi pi.c
//mpirun -n 1 ./pi 1000000
int main(int argc,char **argv)
//argv and argc are how command line arguments are passed to main() in C and C++.
//argc will be the number of strings pointed to by argv. This will (in practice) be 1 plus the number of arguments, as virtually all implementations will prepend the name of the program to the array.
{
        double t1, t2; 
	int rank,size,i;
	double x=0,y=0,pi,z;
	int no = atoi(argv[1]);
	int count=0,total_count=0,no_div=0,fin_no = 0;
	MPI_Init(&argc,&argv);
	t1 = MPI_Wtime(); 
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
        printf("rank= %i ; size= %i\n", rank, size);
	no_div = no/size;
	srand ( time(NULL) );
	for(i=0;i<no_div;i++)
		{
		x=rand()/(double)RAND_MAX;
		y=rand()/(double)RAND_MAX;
		z=x*x+y*y;
		if(z<=1)
		count++;
		}
	printf("For rank %d count = %d itrr = %d\n",rank,count,no_div);
	MPI_Reduce(&count,&total_count,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	MPI_Reduce(&no_div,&fin_no,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
//MPI_Reduce: https://mpitutorial.com/tutorials/mpi-reduce-and-allreduce/
	t2 = MPI_Wtime(); 
	printf("total time for rank %i: = %lf\n", rank, t2-t1);

	if(rank ==0){
	printf("        \n");
	printf("*** Average over all processors ***\n");
	printf("Total count  = %d, total itrr = %d\n",total_count,fin_no);
	pi = ((double)total_count)/fin_no*4.0000;
	printf("Pi value = %lf\n",pi);
		}
	MPI_Finalize();
//cout is not thread-safe, while printf is.
}
