
String str;                                              
int blueToothVal;                                         // stores the last value sent via bluetooth

int left = 11;
int right = 10;

int maxForward = 250;
int slowForward = 210;
int medForward = 230;
int slowBackward = 190;
int off = 100;

//-----------------------------------------------------------------------------------------------------
void setup() 
{  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);                                  // Serial 0 is for communication with the serial monitor
  Serial.begin(9600);                                    // Serial 1 is for Bluetooth communication - DO NOT MODIFY  
}

//-----------------------------------------------------------------------------------------------------
// Main Loop

void loop()
{   
  bluetooth();                                          // Run the Bluetooth procedure to see if there is any data being sent via BT
}




//-----------------------------------------------------------------------------------------------------
// This procedure reads the serial port - Serial - for bluetooth commands being sent from the Android device

void bluetooth()
{
 while (Serial.available())                             // Read bluetooth commands over Serial 
 {  
  {  
      str = Serial.readStringUntil('\n');               // str is the temporary variable for storing the last sring sent over bluetooth from Android device    
  } 
    
    blueToothVal = (str.toInt());                       //  convert the string 'str' into an integer and assign it to blueToothVal
    Serial.print("BlueTooth Value ");
    Serial.println(blueToothVal);    



// Bluetooth Section
//-----------------------------------------------------------------------------------------------------

 switch (blueToothVal) 
 {
      case 1:                                
        Serial.println("Forward");
        Forward(1);
        break;

      case 2:
        Serial.println("Forward");
        Forward(2);
        break;

      case 3:
        Serial.println("Forward");
        Forward(3);
        break;
        
      case 4:                 
        Serial.println("Reverse");
        Reverse(1);
        break;

      case 7:         
        Serial.println("Left");
        LeftTurn(1);
        break;
        
      case 10:                     
        Serial.println("Right");
        RightTurn(1);
        break;
        
      case 13:                                            
        Serial.println("Stop");
        Stop();
        break;      

 }                                                              

 }                                                              
 
   // if no data from Bluetooth 
   if (Serial.available() < 0)                              
    {
     Serial.println("No Bluetooth Data ");          
    }
  
}




// Motor Control Section
//-----------------------------------------------------------------------------------------------------
void Forward(int whatSpeed)
{
  if (whatSpeed == 1){
    analogWrite(left,slowForward);
    analogWrite(right,slowForward);
    
  } else if (whatSpeed == 2){
    analogWrite(left,medForward);
    analogWrite(right,medForward);
    
  } else if(whatSpeed == 3){
    analogWrite(left,maxForward);
    analogWrite(right,maxForward);
    
  } else {
    Serial.println("Error with Forward control");
  }
}

//-----------------------------------------------------------------------------------------------------

void Reverse(int whatSpeed)
{
 if (whatSpeed == 1){
    analogWrite(left,slowBackward);
    analogWrite(right,slowBackward);
  } else {
    Serial.println("Error with Backward control");
  }
}

//-----------------------------------------------------------------------------------------------------
void LeftTurn(int whatSpeed)
{
  if (whatSpeed == 1){
    analogWrite(left,slowBackward);
    analogWrite(right,slowForward);
  } else {
    Serial.println("Error with Left control");
  }
}

//-----------------------------------------------------------------------------------------------------
void RightTurn(int whatSpeed)
{
  if (whatSpeed == 1){
    analogWrite(left,slowForward);
    analogWrite(right,slowBackward);
  } else {
    Serial.println("Error with Right control");
  }                                                   
}

//-----------------------------------------------------------------------------------------------------
void Stop()
{ 
  analogWrite(left,off);
  analogWrite(right,off);
 
}
