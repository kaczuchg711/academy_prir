#include <stdlib.h>
#include <stdio.h>
#include "mpi/mpi.h"

int main(int argc, char **argv) {
    int rank, sended_number, size, source, dest, tag, i, len;
    char name[20];
    len = 20;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Get_processor_name(name, &len);
    int number;
    if(rank == 0)
        number = 44;
    MPI_Bcast(&number,1,MPI_INT,0,MPI_COMM_WORLD);

    if(rank != 0)
    {
        printf("proces %d otrzymal od mamy %d\n",rank, number);
    }

    MPI_Finalize();
    return (0);
}