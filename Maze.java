/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg132lab5;

/**
 *
 * @author ryancummings
 */
class Maze {

    //constructor
    public Maze() {}
    
    char[][] map = {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
            {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
            {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
            {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '#'},
            {'#', '#', '#', '#', '.', '#', 'F', '#', '.', '#', '.', '#'},
            {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
            {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
            {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
            {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
            {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
        };

    public void printMaze() {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println("");
        }
    }

    /*
        x refers to columns, y refers to rows
     */
    public int traverse(char[][] theMaze, int xLoc, int yLoc, int handLocationX, int handLocationY) {
        /*
        Base Case
         */
        if (xLoc == 6 && yLoc == 5) {
            printMaze();
            System.out.println("You are a winner!");
            return 1;
            
        // If facing East
        } else if (handLocationY > yLoc) {
            System.out.println(handLocationX + ", " + handLocationY);
            // right hand on a wall and the path forward is blocked by a wall
            if (theMaze[handLocationY][handLocationX] == '#' && theMaze[xLoc][yLoc] == '#') { 
                // turns North 
                handLocationY--;
                handLocationX++;
               
            // right hand on wall and path forward is clear
            } else if (theMaze[handLocationY][handLocationX] == '#' && theMaze[xLoc][yLoc] == '.') {
                // places X and advances one step
                theMaze[yLoc][xLoc] = 'X';
                xLoc++;
                printMaze();
                
            }else{
                System.out.println("Something went wrong while facing East");
                return 0;
            }
        // if facing West
        }else if (handLocationY < yLoc){
            // right hand on a wall and the path forward is blocked   
            if (theMaze[handLocationY][handLocationX] == '#' && theMaze[xLoc][yLoc] == '#') { 
                // turns South
                handLocationY++;
                handLocationX--; 
                
            // right hand on wall and path forward is clear            
            } else if (theMaze[handLocationY][handLocationX] == '#' && theMaze[xLoc][yLoc] == '.') {
                // places X and advances one step
                theMaze[yLoc][xLoc] = 'X';
                xLoc--;
                printMaze();
               
            }else
                System.out.println("Something went wrong while facing West");
                return 0;
            
        // if facing North
        }else if (handLocationX > xLoc){
            // right hand on a wall and the path forward is blocked
            if (theMaze[handLocationY][handLocationX] == '#' && theMaze[xLoc][yLoc] == '#') { 
                // turn West
                handLocationY--;
                handLocationX--;
                
            // right hand on a wall and the path forward is clear
            }else if (theMaze[handLocationY][handLocationX] == '#' && theMaze[xLoc][yLoc] == '.'){
                // places X and advances one step
                theMaze[yLoc][xLoc] = 'X';
                yLoc--;
                printMaze();
                
            }else 
                return 0;
            
        // if facing South
        }else if (handLocationX < xLoc){
            // right hand on a wall and the path forward is blocked
            if (theMaze[handLocationY][handLocationX] == '#' && theMaze[xLoc][yLoc] == '#') { 
                // turns East 
                handLocationY++;
                handLocationX++;
                
            // right hand on a wall and the path forward is clear
            }else if (theMaze[handLocationY][handLocationX] == '#' && theMaze[xLoc][yLoc] == '.'){
                // places X and advances one step
                theMaze[yLoc][xLoc] = 'X';
                yLoc++;
                printMaze();
                //return traverse(theMaze, xLoc, yLoc, handLocationX, handLocationY);
            }else
                return 0;
        }
        return traverse(theMaze, xLoc, yLoc, handLocationX, handLocationY);  
    }
}
