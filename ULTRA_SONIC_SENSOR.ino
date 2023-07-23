#include <dummy.h>

// TS: 09/15/2018    
// UP: 02/11/2021
// AU: Joseph S. Miles
// DS: Basic UltraSonic Sensor Test – Open a new sketch without libraries and copy in and compile and upload
// DS: Sketch saved under /Documents/Arduino on Office Laptop


#include <WemosInit.h>
#include <Servo.h>

/*Ultrasonic HC-SR04 Sensor Testing with WemosInit Library for D1-R1*/

/*Define variables for collecting data */
long duration_Driver;
long duration_Front;
long duration_Pass;

double distance_cm;
double distance_cm_Front;
double distance_cm_Pass;

double distance_in;
double distance_in_Front;
double distance_in_Pass;

double distance_ft;
double distance_ft_Front;
double distance_ft_Pass;

char distanceString[50];
char distanceStringFront[50];
char distanceStringPass[50];

void setup()
{
 //Driver Sensor from Front
  pinMode(D8,OUTPUT);    //Trigger-Send Pulse - Orange
  pinMode(D5,INPUT);     //Echo - Receive Pulse - Yellow

//Front Sensor
  pinMode(D9,OUTPUT);   //Trigger-Send Pulse - Orange
  pinMode(D6,INPUT);    //Echo - Receive Pulse - Yellow
  
  //Passenger Sensor from Front
  pinMode(D10,OUTPUT);   //Trigger-Send Pulse - Orange
  pinMode(D7,INPUT);     //Echo - Receive Pulse - Yellow

    
  Serial.begin(115200);  // Set baud rate to serial monitor
  delay(5000);//Delay 5 seconds to allow for time to open Serial Monitor after program upload



  Serial.println ("         Dur. Cent.  In. Feet"); ///Print caption
  for (int ctr=0;ctr<900;ctr++){//loop for 250 iterations
    
    duration_Driver=ultrasonicPing(D8,D5);//This statement retrieves the data from the Center sensor (trigger, echo)
    duration_Front=ultrasonicPing(D9,D6);//This statement retrieves the data from the Left (looking at front) Sensor
    duration_Pass=ultrasonicPing(D10,D7);//This statement retrieves the data from the Right (looking at front) Sensor
    delay(100);
    
    //Conversions from duration to inches and centimeters can be found on-line  
    distance_cm = duration_Driver / 58;          //converts echo duration to centimeters
    distance_in = duration_Driver / 148;         //converts echo duration to inches
    distance_ft = distance_in /12;        //converts echo duration to feet
    
    //Create comma delimited output for Center Sensor
    Serial.println ("       Duration   Cent.    Inch     Feet"); ///Print caption
    Serial.print("Driver:  ");//print value being tested
    Serial.print(duration_Driver);
    Serial.print(",   ");
    Serial.print(distance_cm);//print conversion value for centimeters
    Serial.print(",    ");
    Serial.print(distance_in);//print conversion value for inches
    Serial.print(",    ");
    Serial.print(distance_ft);//print conversion value for feet
    Serial.println();
    
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    distance_cm_Front = duration_Front / 58;          //converts echo duration to centimeters
    distance_in_Front = duration_Front / 148;         //converts echo duration to inches
    distance_ft_Front = distance_in_Front /12;        //converts echo duration to feet

   //Create comma delimited output for Left Sensor
    Serial.print("  Front:  ");//print value being tested
    Serial.print(duration_Front);
    Serial.print(",    ");
    Serial.print(distance_cm_Front);//print conversion value for centimeters
    Serial.print(",    ");
    Serial.print(distance_in_Front);//print conversion value for inches
    Serial.print(",    ");
    Serial.print(distance_ft_Front);//print conversion value for feet
    Serial.println();
    
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    distance_cm_Pass = duration_Pass/ 58;          //converts echo duration to centimeters
    distance_in_Pass = duration_Pass / 148;         //converts echo duration to inches
    distance_ft_Pass = distance_in_Pass /12;        //converts echo duration to feet

    //Create comma delimited output for Right Sensor
    Serial.print(" Pass:  ");//print value being tested
    Serial.print(duration_Pass);
    Serial.print(",    ");
    Serial.print(distance_cm_Pass);//print conversion value for centimeters
    Serial.print(",    ");
    Serial.print(distance_in_Pass);//print conversion value for inches
    Serial.print(",    ");
    Serial.print(distance_ft_Pass);//print conversion value for feet
    Serial.println();
    Serial.println("");
   
    delay(1000);
  }
}

void loop() 
{
}
