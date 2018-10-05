int incomingByte;
#include "IRremote.h"
#include <Servo.h> 
#define pi  3.14 //Αρχικοποίηση του π

//----------------------------Δήλωση Servo-------------------------------

Servo axonas1; //Ο servo στην βάση του mr.robot
Servo axonas2; //O servo ανάμεσα στο μπράτσο l1 και l2
Servo akro;    //O servo στο άκρο εργασίας

//-----------------------------Δήλωση γωνιών-----------------------------

float angle1;  //Γωνία του πρώτου άξονα
float angle2;  //Γωνία του δεύτερου άξονα

//------------------------Δήλωση μήκους μπράτσων-------------------------

const int l1 = 10;  // Μήκος του l1 
const int l2 = 10;  // Μήκος του l2

//-----------------------------------------------------------------------


//Μεγέθη για τον υπολογισμό των γωνιών
double A; 
double B;  
double C;  
double th;        

//Σημεία ενδιαφέροντος
double x;  // Eπιθυμητό σημείο x
double y;  // Eπιθυμητό σημείο y
double c;  // Υποτείνουσα που σχηματίζετε απο τα σημεία x,y 

//-----------------------------------------------------------------------

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~VOID SETUP~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setup()
{
  Serial.begin(9600);
  axonas1.attach(2); //Τοποθέτηση servo1 στο pin5 (Βάση)           
  axonas2.attach(3); //Τοποθέτηση servo2 στο pin6 (Ενδιάμεσα από τα μπράτσα)
  akro.attach(4);    //Τοποθέτηση servo3 στο pin7 (Άκρο)
  akro.write(90);
  x=5;               //Αρχικό σημείο Χ
  y=5;               //Αρχικό σημείο Y
  anglecalculation();//Κάνουμε μια φορά τον υπολογισμό με βάση τις διορθωμένες γωνίες  
  robotmove();       //και εκτελούμε την κίνηση
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~VOID LOOP~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void loop()
{ 
if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read()-48;
                translateIR();
        }    
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Υπολογισμός γωνιών με βάση τα δοσμένα σημεία
void anglecalculation()
{ 

  c = sqrt( pow(x,2) + pow(y,2) );                          
  B = (acos( (pow(l2,2) - pow(l1,2) - pow(c,2))/(-2*l1*c) )) * (180/pi);            
  C = (acos( (pow(c,2) - pow(l1,2) - pow(l1,2))/(-2*l1*l2) )) * (180/pi); 
  th = (asin( y / c )) * (180/pi);                    
  angle1 = B + th  ;                  
  angle2 = C ;                           
}

//Γενική Κίνηση Servo
void robotmove() 
{
  axonas1.write(angle1);
  axonas2.write(angle2); 
  delay(100); 
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Κινήσεις 7-ΤΑΕ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void kinishYp(void){
  for(int i=1;i<=8;i++){ //Για 5 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();          
    robotmove();          //και κάνε κίνηση των servo 
    delay(500);
    y=y+0.1;              //Αύξησε την μετατόπηση του y κατα 0.1 cm
  }
}

void kinishXd(void){
  for(int i=1;i<=10;i++){ //Για 20 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();           
    robotmove();          //και κάνε κίνηση των servo              
    delay(500);
    x=x+0.1;              //Αύξησε την μετατόπηση του x κατα 0.1 cm
  }
}

void kinishYk(void){
  for(int i=1;i<=8;i++){ //Για 15 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();     
    robotmove();          //και κάνε κίνηση των servo     
    delay(500);
    y=y-0.1;              //Μείωσε την μετατόπηση του y κατα 0.1 cm
  }
}

void kinishXa(void){
  for(int i=1;i<=10;i++){ //Για 20 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();           
    robotmove();          //και κάνε κίνηση των servo 
    delay(500);    
    x=x-0.1;              //Μείωσε την μετατόπηση του χ κατα 0.1 cm
  }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void akrosweep90(){
for(int pos = 180; pos >= 90; pos = pos -1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    akro.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(50);                       // waits 15ms for the servo to reach the position 
  } 
}
void akrosweep180(){
for(int pos = 90; pos <= 180; pos = pos +1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    akro.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(50);                       // waits 15ms for the servo to reach the position 
  } 
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Συνάρτηση του mhden~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void mhden(){
  kinishYp(); //Δύο διαδοχικές κινήσεις προς τα επάνω κατα 3 cm
  delay(500);   
  kinishYp();
  delay(500);   
  kinishXd(); //Μια κίνηση δεξιά κατα 2 cm
  delay(500);   
  kinishYk(); //Δύο διαδοχικές κινήσεις προς τα κάτω κατα 3 cm
  delay(500);   
  kinishYk();
  delay(500);   
  kinishXa(); //Μια κίνηση αριστερά κατα 2 cm   
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
