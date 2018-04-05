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
    
    public Maze(){
       
    }
    public void printMaze(){
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
    public int traverse(char[][] theMaze, int xLoc, int yLoc, int handLocationX, int handLocationY){
        if (xLoc == 6 && yLoc == 5){
            System.out.println("You are a winner!");
            return 1;
        }
        else if (theMaze[handLocationY][handLocationX] == '#'){
            if(handLocationY < yLoc){  //detects East, turns north
                handLocationY++;
                handLocationX++;
            }
            if(handLocationY > yLoc){  //detects West, turns South
                handLocationY--;
                handLocationX--;
            }
            if(handLocationX > xLoc){  //detects North turns West
                handLocationY++;
                handLocationX--;
            }
            if(handLocationX < xLoc){  //detects South, turns North
                handLocationY--;
                handLocationX++;
            }
            handLocationY = handLocationY++;
            return traverse(theMaze, xLoc, yLoc, handLocationX, handLocationY);
        }
        else
            return 0;
    }
    
}
