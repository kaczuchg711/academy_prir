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
    while(1) {
        if (rank == 0)
        {
            scanf("%d", &number);
            if(number <0)
                MPI_Abort(MPI_COMM_WORLD,-1);
        }
        MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);

        if (rank != 0) {
            printf("proces %d otrzymal od mamy %d\n", rank, number);
        }
    }
    MPI_Finalize();
    return (0);
}