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
    int value_to_send = 333333;
    int value_to_receive;
    int end_work = 0;
    while (1) {
        if (rank == 0) {
            scanf("%d", &value_to_send);
            if (value_to_send < 0) {
                MPI_Abort(MPI_COMM_WORLD,0);
            }
            MPI_Send(&value_to_send, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
        }


        MPI_Barrier(MPI_COMM_WORLD);

        for (int j = 1; j < size; ++j) {

            if (rank == j) {
                MPI_Recv(&value_to_receive, 1, MPI_INT, j - 1, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
                printf("Proces %d otrzymał od %d wartosc %d\n", rank, j - 1, value_to_receive);
                value_to_send = value_to_receive;
                if (rank != size - 1) {
                    MPI_Send(&value_to_send, 1, MPI_INT, j + 1, tag, MPI_COMM_WORLD);
                }
            }
            MPI_Barrier(MPI_COMM_WORLD);
        }
    }
    MPI_Finalize();
    return (0);
}