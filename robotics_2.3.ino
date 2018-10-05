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

const int l1 = 11;  // Μήκος του l1 
const float l2 = 11.5;  // Μήκος του l2

//-----------------------------------------------------------------------


//-------------------Δήλωση αντικειμένων Υπέρυθρων-----------------------
      
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
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  Serial.begin(9600);
  axonas1.attach(2); //Τοποθέτηση servo1 στο pin2 (Βάση)           
  axonas2.attach(3); //Τοποθέτηση servo2 στο pin3 (Ενδιάμεσα από τα μπράτσα)
  akro.attach(4);    //Τοποθέτηση servo3 στο pin4 (Άκρο)
  akro.write(95);     //Τοποθέτηση γραφίδας προς τα πάνω
  x=0;               //Αρχικό σημείο Χ
  y=8;               //Αρχικό σημείο Y
  anglecalculation();//Κάνουμε μια φορά τον υπολογισμό με βάση τις συντεταγμένες  
  robotmove();       //και εκτελούμε την κίνηση
  akro.write(180);
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

void translateIR(){ //Κάνει ένα σετ εντολών με βάση το σήμα που θα λάβει

switch(incomingByte){
  case 0:  // O αριθμός 0
    mhden();
    break;
  
  case 1:  // O αριθμός 1
    ena();
    break;
 
  case 2:  // O αριθμός 2
    duo();
    break;
  
  case 3:  // O αριθμός 3
    tria();
    break;
  
  case 4:  // O αριθμός 4
    tessera();
    break;

  case 5:  // O αριθμός 5
    pente();
    break;

  case 6:  // O αριθμός 6
    eksi();
    break;

  case 7:  // O αριθμός 7
    efta();
    break;

  case 8:  // O αριθμός 8
    oxtw();
    break;

  case 9:  // O αριθμός 9
    ennia(); 
    break;
}

}
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
  delay(10); 
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Κινήσεις 7-ΤΑΕ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void kinishYp(void){
  for(int i=1;i<=15;i++){ //Για 15 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();          
    robotmove();          //και κάνε κίνηση των servo 
    delay(50);
    y=y+0.1;              //Αύξησε την μετατόπηση του y κατα 0.1 cm
  }
}

void kinishYp4(void){
  for(int i=1;i<=20;i++){ //Για 15 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();          
    robotmove();          //και κάνε κίνηση των servo 
    delay(50);
    y=y+0.1;              //Αύξησε την μετατόπηση του y κατα 0.1 cm
  }
}

void kinishXd(void){
  for(int i=1;i<=20;i++){ //Για 20 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();           
    robotmove();          //και κάνε κίνηση των servo               
    delay(50);
    x=x+0.1;              //Αύξησε την μετατόπηση του x κατα 0.1 cm
  }
}
void kinishXd2(void){
  for(int i=1;i<=20;i++){ //Για 20 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();           
    robotmove();          //και κάνε κίνηση των servo               
    delay(50);
    x=x+0.1;    //Αύξησε την μετατόπηση του x κατα 0.1 cm
    y=y+0.01;
  }
}
void kinishXd3(void){
  for(int i=1;i<=17;i++){ //Για 20 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();           
    robotmove();          //και κάνε κίνηση των servo               
    delay(50);
    x=x+0.1;              //Αύξησε την μετατόπηση του x κατα 0.1 cm
  }
}

void kinishXd4(void){
  for(int i=1;i<=10;i++){ //Για 20 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();           
    robotmove();          //και κάνε κίνηση των servo               
    delay(50);
    x=x+0.1;              //Αύξησε την μετατόπηση του x κατα 0.1 cm
  }
}

void kinishXd6(void){
  for(int i=1;i<=25;i++){ //Για 20 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();           
    robotmove();          //και κάνε κίνηση των servo               
    delay(50);
    x=x+0.1;              //Αύξησε την μετατόπηση του x κατα 0.1 cm
  }
}
void kinishYk(void){
  for(int i=1;i<=15;i++){ //Για 15 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();           
    robotmove();          //και κάνε κίνηση των servo              
    delay(50);
    y=y-0.1;              //Μείωσε την μετατόπηση του y κατα 0.1 cm
  }
}
void kinishYk4(void){
  for(int i=1;i<=20;i++){ //Για 15 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();           
    robotmove();          //και κάνε κίνηση των servo              
    delay(50);
    y=y-0.1;              //Μείωσε την μετατόπηση του y κατα 0.1 cm
  }
}

void kinishXa(void){
  for(int i=1;i<=20;i++){ //Για 20 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();           
    robotmove();          //και κάνε κίνηση των servo               
    delay(50);
    x=x-0.1;              //Μείωσε την μετατόπηση του χ κατα 0.1 cm
  }
}

void kinishXa3(void){
  for(int i=1;i<=25;i++){ //Για 20 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();           
    robotmove();          //και κάνε κίνηση των servo               
    delay(50);
    x=x-0.1;              //Μείωσε την μετατόπηση του χ κατα 0.1 cm
  }
}
void kinishXa4(void){
  for(int i=1;i<=13;i++){ //Για 20 φορές υπολόγιζε τις γωνίες με βάση τις προυπάρχουσες συντεταγμένες
    anglecalculation();           
    robotmove();          //και κάνε κίνηση των servo               
    delay(50);
    x=x-0.1;              //Μείωσε την μετατόπηση του χ κατα 0.1 cm
  }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~Συνάρτηση ομαλής περιστροφής άκρου εργασίας προς την θέση γραφής~~~~~~~~~~~~
void akroPros180 (){ // 172 moires einai katakorufa to stulo
  for(int pos = 95; pos <= 172; pos += 1){                                 
    akro.write(pos);              
    delay(20);                      
  } 
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~Συνάρτηση ομαλής περιστροφής άκρου εργασίας προς την θέση ισορροπίας~~~~~~~~~
void akroPros0 (){
  for(int pos = 172; pos>=95; pos-=1){                                 
    akro.write(pos);              
    delay(20);                      
  } 
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Συνάρτηση του Μηδέν~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void mhden(){
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  
  akroPros0();
  
     
  kinishXd(); //Μια κίνηση δεξιά κατα 2 cm
  delay(50);   
  kinishYk(); //Δύο διαδοχικές κινήσεις προς τα κάτω κατα 3 cm
  delay(50);   
  kinishYk();
  delay(50);   
  kinishXa(); //Μια κίνηση αριστερά κατα 2 cm 
  delay(50); 
  kinishYp(); //Δύο διαδοχικές κινήσεις προς τα επάνω κατα 3 cm
  delay(50);   
  kinishYp();
  delay(50);
  
  akroPros180();
  
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Συνάρτηση του Ένα~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void ena(){
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  
  
  kinishYp(); //Δύο διαδοχικές κινήσεις προς τα επάνω κατα 3 cm  
  kinishYp();   
  kinishXd(); //Μια κίνηση δεξιά κατα 2 cm

  akroPros0(); //Κατεβαίνει η γραφίδα 
  
  kinishYk(); //Δύο διαδοχικές κινήσεις προς τα κάτω κατα 3 cm
  delay(50);   
  kinishYk();
  delay(50);
  
  akroPros180();
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Συνάρτηση του Δύο~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void duo(){
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(13, HIGH);
  
  kinishYp(); //Δύο διαδοχικές κινήσεις προς τα επάνω κατα 3 cm   
   
  
  akroPros0();
  
  kinishXd(); //Μια κίνηση δεξιά κατα 2 cm
  delay(50);
  kinishYk();
  delay(50);
  kinishXa(); //Μια κίνηση αριστερά κατα 2 cm
  delay(50);
  kinishYk();
  delay(50);
  kinishXd2(); //Μια κίνηση δεξιά κατα 2 cm
  delay(50); 
  
  akroPros180();
  
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(13, LOW);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Συνάρτηση του Τρία~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void tria(){
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(13, HIGH);
  
  kinishYp(); //Δύο διαδοχικές κινήσεις προς τα επάνω κατα 3 cm   
  
  
  akroPros0();
  
  kinishXd3(); //Μια κίνηση δεξιά κατα 2 cm
  delay(50);
  kinishYk();
  delay(50);
  kinishXa();
  delay(50);
  kinishXd();
  delay(50);
  kinishYk();
  delay(50);
  kinishXa3(); //Μια κίνηση αριστερά κατα 2 cm
  delay(500);

  akroPros180();
  
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(13, LOW);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Συνάρτηση του Τέσσερα~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void tessera(){
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  
  kinishXd();
 
  akroPros0();
 
  kinishYk();
  delay(50);
  kinishXd4(); //Μια κίνηση δεξιά κατα 2 cm
  delay(50);
  kinishYp4();
  delay(50);
  kinishYk4();
  delay(50);
  kinishYk4();
  delay(50);
 
  akroPros180();
  
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Συνάρτηση του Πέντε~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void pente(){
  digitalWrite(7, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
     
  kinishXd(); //Μια κίνηση δεξιά κατα 2 cm

  akroPros0(); //Κατεβαίνει η γραφίδα 
 
  kinishXa(); //Μια κίνηση αριστερά κατα 2 cm
  delay(50);
  kinishYk();
  delay(50);
  kinishXd(); //Μια κίνηση δεξιά κατα 2 cm
  delay(50);
  kinishYk();
  delay(50);
  kinishXa(); //Μια κίνηση αριστερά κατα 2 cm
  delay(50);
 
  akroPros180();
  
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Συνάρτηση του Έξι~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void eksi(){
  digitalWrite(7, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  
  kinishYp();
  
  akroPros0(); //Κατεβαίνει η γραφίδα 
 
  kinishXd(); //Μια κίνηση αριστερά κατα 2 cm
  delay(50);
  kinishYk();
  delay(50);
  kinishXa3(); //Μια κίνηση δεξιά κατα 2 cm
  delay(50);
  kinishYp();
  delay(50);
  kinishYp(); //Μια κίνηση αριστερά κατα 2 cm
  delay(50);
  kinishXd6();
  delay(50);
 
  akroPros180();
  
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Συνάρτηση του Εφτά~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void efta(){
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  
  kinishYp();   
 
  akroPros0(); //Κατεβαίνει η γραφίδα 
 
  kinishXd(); //Μια κίνηση δεξιά κατα 2 cm
  delay(50);
  kinishYk(); //Δύο διαδοχικές κινήσεις προς τα κάτω κατα 3 cm
  delay(50);   
  kinishYk4();
  delay(50);
  
  akroPros180();
  
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Συνάρτηση του Οχτώ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void oxtw(){
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  
  akroPros0();
  

  kinishYk();
  delay(50);
  kinishXd(); //Μια κίνηση δεξιά κατα 2 cm
  delay(50);
  kinishYp(); //Δύο διαδοχικές κινήσεις προς τα κάτω κατα 3 cm
  delay(50);
  kinishXa();
  delay(50);
  kinishYp(); //Μια κίνηση αριστερά κατα 2 cm
  delay(50);
  kinishXd(); //Μια κίνηση προς τα επάνω κατα 1.5 cm
  delay(50);
  kinishYk(); //Μια κίνηση δεξιά κατα 2 cm
  delay(50);    
  
  akroPros180();
  
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Συνάρτηση του Εννιά~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void ennia(){
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  
 
  akroPros0();
  
 
  kinishYp();
  delay(50);
  kinishXd(); //Μια κίνηση δεξιά κατα 2 cm
  delay(50);
  kinishYk(); //Δύο διαδοχικές κινήσεις προς τα κάτω κατα 3 cm
  kinishYk();
  delay(50);
  kinishXa(); //Μια κίνηση αριστερά κατα 2 cm
  delay(50);
  kinishYp4(); //Μια κίνηση προς τα επάνω κατα 1.5 cm
  delay(50);
  kinishXd6(); //Μια κίνηση δεξιά κατα 2 cm
  delay(50);
 
  akroPros180();
  
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}
