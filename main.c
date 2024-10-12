#include <stdio.h>

#define N 5  // Size of the maze (N x N)

// Function to print the solution matrix
void printSolution(int solution[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", solution[i][j]);
        }
        printf("\n");
    }
}

// Utility function to check if (x, y) is a valid move
int isSafe(int maze[N][N], int x, int y, int solution[N][N]) {
    // Returns true if (x, y) is a valid index and the cell is not a wall (1), and not already visited
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0 && solution[x][y] == 0);
}

// Utility function to solve the maze using backtracking
int solveMazeUtil(int maze[N][N], int x, int y, int solution[N][N]) {
    // Base case: If x, y is the bottom-right corner, we have found a solution
    if (x == N - 1 && y == N - 1 && maze[x][y] == 0) {
        solution[x][y] = 1;
        return 1;
    }

    // Check if maze[x][y] is a valid move
    if (isSafe(maze, x, y, solution)) {
        // Mark x, y as part of the solution path
        solution[x][y] = 1;

        // Move right
        if (solveMazeUtil(maze, x, y + 1, solution)) {
            return 1;
        }

        // Move down
        if (solveMazeUtil(maze, x + 1, y, solution)) {
            return 1;
        }

        // Move left
        if (solveMazeUtil(maze, x, y - 1, solution)) {
            return 1;
        }

        // Move up
        if (solveMazeUtil(maze, x - 1, y, solution)) {
            return 1;
        }

        // Backtracking: Unmark x, y as part of the solution
        solution[x][y] = 0;
        return 0;
    }
    return 0;
}

// Main function to solve the maze problem
int solveMaze(int maze[N][N]) {
    int solution[N][N] = {0};  // Initialize solution matrix to 0

    if (solveMazeUtil(maze, 0, 0, solution) == 0) {
        printf("No solution exists\n");
        return 0;
    }

    printf("Solution found:\n");
    printSolution(solution);
    return 1;
}

int main() {
    // Define the maze: 0 is path, 1 is wall
    int maze[N][N] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    // Solve the maze
    solveMaze(maze);

    return 0;
}