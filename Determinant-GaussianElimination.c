/* ==========================================================================

   Determinant by Guassian-Elimination.c
   (c) 2015 Aparna Lavanya K

   Program to find the Determinant of a Square Matrix
   Using Gaussian Elimination Method

 ========================================================================== */


#include<stdio.h>

int swapMultiplier = 1; // Is swapping of rows done?

int swapRows(double matrix[25][25], int order){

      int flag = 0 ;
      double temp ;
      int i, j ;

        for(i=1; i<order; i++){
            if(matrix[i][0] != 0.00){   //Check for non-zero entry in first column
                flag = 1 ;
                break ;
            }
        }

        for(j=0; j<order; j++){    //swap rows
            temp = matrix[0][j] ;
            matrix[0][j] = matrix[i][j] ;
            matrix[i][j] = temp ;
        }

        if(flag == 0){
            // all entries of first column is zero hence determinant is zero
            return 0 ;
        }

      return 1 ;
}



double determinant(double matrix[25][25], int order){

      double determinant = 1.00;
      int i, j, k;   //iteration variables
      int exist = 1 ; // determinant exists or not
      double multiplier ;

		// Base case : Single element Matrix
		    if(order == 1){
            determinant = matrix[0][0] ;
			      return determinant ;
		    }

    //Base case : 2X2 matrix
	      if (order == 2){
			      determinant = matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0] ;
            return determinant ;
		    }

		    else{
		    // when order of matrix > 2
            if(matrix[0][0] == 0){
                 // if matrix[0][0] = 0 we need to swap rows to make it non-zero
                 exist = swapRows(matrix, order) ;
                 swapMultiplier = -1 ;   // if rows were swapped, need to multiply by -1
            }
        }

        //Corner case : all entries in first column is zero
        if(exist == 0){
            return 0 ;   // hence determinant is zero
        }

      // calculate the determinant
      //generation of upper triangular matrix by Gaussian Elimination

      for(i=0; i<order-1; i++){
            for(j=i+1; j<order; j++){

                 if(i<j){
                      multiplier=matrix[i][k]/matrix[i][i];

                      for(k=0; k<order; k++){

                           matrix[j][k] = matrix[j][k]-multiplier*matrix[j][i];
                      }
                 }
            }

      }

    // multiply diagonal elements to get determinant
      for(i=0; i<order; i++){
          determinant *= matrix[i][i] ;
      }

      determinant *= swapMultiplier;

    return determinant ;
}



int main(){

      int order ;
      int i, j;   //iteration variables
      double matrix[25][25];

      // Get the matrix
      printf("\nEnter the order of the matrix: ");
      scanf("%d",&order);

      if(order == 0){  // Corner Case : Null matix
          return 0;
      }

	    printf("\nEnter the elements of the matrix: \n") ;
	    for(i=0;i<order;i++){
		       for(j=0;j<order;j++){

			          scanf("%lf",&matrix[i][j]);
	       	}
	    }

      printf("\nValue of the determinant : %lf", determinant(matrix, order)) ;

   return 0;
}
