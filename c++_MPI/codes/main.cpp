#include <iostream>
#include "mpi.h"


int main(int argc, char **argv) {
    // Initialize MPI
    MPI_Init(&argc, &argv);
    int world_size, world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int color = world_rank / 4;

    // Split
    MPI_Comm row_comm;
    MPI_Comm_split(MPI_COMM_WORLD, color, world_rank, &row_comm);

    int row_rank, row_size;
    MPI_Comm_size(row_comm, &row_size);
    MPI_Comm_rank(row_comm, &row_rank);

    printf("WORLD RANK/SIZE: %d/%d \t ROW RANK/SIZE: %d/%d\n",
	            world_rank, world_size, row_rank, row_size);

    MPI_Comm_free(&row_comm);

    MPI_Finalize();

    return 0;
}