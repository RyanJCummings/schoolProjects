/*
 * This class creates and traverses a maze using a recursive algorithm.
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
            if (theMaze[handLocationY][handLocationX] == '#' && theMaze[yLoc][xLoc] == '#') { 
                // turns North 
                handLocationY--;
                handLocationX++;
               
            // right hand on wall and path forward is clear
            } else if (theMaze[handLocationY][handLocationX] == '#' && (theMaze[yLoc][xLoc] == '.' || theMaze[yLoc][xLoc] == 'X')) {
                // places X and advances one step
                theMaze[yLoc][xLoc] = 'X';
                xLoc++;
                printMaze();
            
            // right hand on a clear path: turn right and advance one step
            }else if (theMaze[handLocationY][handLocationX] == '.' || theMaze[yLoc][xLoc] == 'X'){ 
                theMaze[yLoc][xLoc] = 'X';
                handLocationY++;
                handLocationX--;
                yLoc++;
                printMaze();
                
            }else{
                System.out.println("Something went wrong while facing East");
                return 0;
            }
            
        // if facing West
        }else if (handLocationY < yLoc){
            // right hand on a wall and the path forward is blocked   
            if (theMaze[handLocationY][handLocationX] == '#' && theMaze[yLoc][xLoc] == '#') { 
                // turns South
                handLocationY++;
                handLocationX--; 
                
            // right hand on wall and path forward is clear            
            } else if (theMaze[handLocationY][handLocationX] == '#' && (theMaze[yLoc][xLoc] == '.' || theMaze[yLoc][xLoc] == 'X')) {
                // places X and advances one step
                theMaze[yLoc][xLoc] = 'X';
                xLoc--;
                printMaze();
            
             
             // right hand on clear path: turn right and advance one step
             }else if (theMaze[handLocationY][handLocationX] == '.' || theMaze[yLoc][xLoc] == 'X'){ 
                theMaze[yLoc][xLoc] = 'X';
                handLocationY--;
                handLocationX++;
                yLoc--;
                printMaze();
                
            }else
                System.out.println("Something went wrong while facing West");
                return 0;
            
        // if facing North
        }else if (handLocationX > xLoc){
            // right hand on a wall and the path forward is blocked
            if (theMaze[handLocationY][handLocationX] == '#' && theMaze[yLoc][xLoc] == '#') { 
                // turn West
                handLocationY--;
                handLocationX--;
                
            // right hand on a wall and the path forward is clear
            }else if (theMaze[handLocationY][handLocationX] == '#' && (theMaze[yLoc][xLoc] == '.' || theMaze[yLoc][xLoc] == 'X')){
                // places X and advances one step
                theMaze[yLoc][xLoc] = 'X';
                yLoc--;
                printMaze();
            
                 // right hand on a clear path: turn right and advance one step
            }else if (theMaze[handLocationY][handLocationX] == '.' || theMaze[yLoc][xLoc] == 'X'){ 
                theMaze[yLoc][xLoc] = 'X';
                handLocationY++;
                handLocationX++;
                xLoc++;
                printMaze();
                
            }else 
                System.out.println("Something went wrong facing North");
                return 0;
            
        // if facing South
        }else if (handLocationX < xLoc){
            // right hand on a wall and the path forward is blocked
            if (theMaze[handLocationY][handLocationX] == '#' && theMaze[yLoc][xLoc] == '#') { 
                // turns East 
                handLocationY++;
                handLocationX++;
                
            // right hand on a wall and the path forward is clear
            }else if (theMaze[handLocationY][handLocationX] == '#' && (theMaze[yLoc][xLoc] == '.' || theMaze[yLoc][xLoc] == 'X')){
                // places X and advances one step
                theMaze[yLoc][xLoc] = 'X';
                yLoc++;
                printMaze();
                //return traverse(theMaze, xLoc, yLoc, handLocationX, handLocationY);
                
             // right hand on a clear path: turn right and advance one step
            }else if (theMaze[handLocationY][handLocationX] == '.' || theMaze[yLoc][xLoc] == 'X'){ 
                theMaze[yLoc][xLoc] = 'X';
                handLocationY--;
                handLocationX--;
                xLoc--;
                printMaze();
                
            }else
                System.out.println("Something went wrong facing South");
                return 0;
        }
        return traverse(theMaze, xLoc, yLoc, handLocationX, handLocationY);  
    }
}
