#include <stdlib.h>
#include<stdio.h>
#include<math.h>

#include "mpi.h"

int main( int argc, char** argv ){ 
  
  int rank, ranksent, size, source, dest, tag, i; 
  MPI_Status status;
  char h_name[1024] = "fail";
  int h_size = 1024;
  
  MPI_Init( &argc, &argv );
  MPI_Comm_rank( MPI_COMM_WORLD, &rank ); 
  MPI_Comm_size( MPI_COMM_WORLD, &size );
  
  if(size>1){
    
  //h_name = malloc(sizeof(char) * 50);
  //h_size = 50;
  ///*
  if(gethostname(h_name,h_size))
  {
  exit(0);
  }/**/
  
    if( rank != 0 ){ dest=0; tag=0; 
      MPI_Send( &rank, 1, MPI_INT, dest, tag, MPI_COMM_WORLD );
      MPI_Send( &h_size, 1, MPI_INT, dest, tag, MPI_COMM_WORLD );
      MPI_Send( (void*)&h_name, h_size, MPI_CHAR, dest, tag, MPI_COMM_WORLD );
      //
    } else {
      
      for( i=1; i<size; i++ ) { 
	///*
	MPI_Recv( &ranksent, 1, MPI_INT, MPI_ANY_SOURCE, 
		  MPI_ANY_TAG, MPI_COMM_WORLD, &status );
	MPI_Recv( &h_size, 1, MPI_INT, ranksent, 
		  MPI_ANY_TAG, MPI_COMM_WORLD, &status );
	MPI_Recv( &h_name, h_size, MPI_INT, ranksent, 
		  MPI_ANY_TAG, MPI_COMM_WORLD, &status );
	/**/
	//MPI_Recv( &ranksent, 1, MPI_INT, MPI_ANY_SOURCE, 
	//	  MPI_ANY_TAG, MPI_COMM_WORLD, &status );
	printf("Dane od procesu o randze (status.MPI_SOURCE ->) %d: %d (i=%d)\nHostname:	%s\n", 
	       status.MPI_SOURCE, ranksent, i,h_name );
      }
      
    }

  }
  else{
	printf("Pojedynczy proces o randze: %d (brak komunikatów)\n", rank);
  }

  
  MPI_Finalize(); 
  
  return(0);

}

