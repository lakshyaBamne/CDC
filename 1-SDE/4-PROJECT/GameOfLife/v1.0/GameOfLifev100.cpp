/*
    Mathematician John H. Conway's Game of Life

    => v1.00 is a starting point to understand the concept and nuances
    => Finite Grid game with randomized initialized conditions
    => Command Line Program with user selected number of generations    
    => Raw C/C++ should be only used, other optimization to be done later
*/

#include<iostream>

// function to print the grid at any point in it's life
void print_grid(int* grid, int grid_size){
    
}

int main(){
    const int GRID_SIZE = 10;

    int grid[GRID_SIZE][GRID_SIZE] = {};

    std::cout << "Initialized grid is :- " << std::endl;
    for(int i=0 ; i<GRID_SIZE ; i++){
        for(int j=0 ; j<GRID_SIZE ; j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}

