/*
 * Class contains x and y position values for pixels on the screen.  Instances of this class
 * are used with a stack to check the rgb values of surrounding pixels.
 */
public class PixelRegion {
    int x;
    int y;
    public PixelRegion(int xPos, int yPos) {
        int x = xPos;
        int y = yPos;
        System.out.println("creating new pixel region values: " + x + ", " + y);
    }
}
