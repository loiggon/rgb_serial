/**********************************************************************************
**                                                                               **
**                         RGB                                                   **
**                                                                               **
**********************************************************************************/


//********** Includes *************************************************************


//********** Variables ************************************************************
// pins for the LEDs:
const int ledPin = 13;
const int redPin = 3;
const int greenPin = 6;
const int bluePin = 5;
int valorR = 0, valorG = 0, valorB = 0;


//********** Setup ****************************************************************
void setup() {
  // initialize serial:
  Serial.begin(9600);
  Serial.print("Entra els valors R G B del color a veure (entre 0 i 1023): R=");
  // make the pins outputs:
  pinMode(ledPin, OUTPUT); 
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  analogWrite(redPin, valorR);
  analogWrite(greenPin, valorG);
  analogWrite(bluePin, valorB);
}

//********** Loop *****************************************************************
void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    valorR = Serial.parseInt(); 
    Serial.print(valorR);
    Serial.print(", G=");
    valorG = Serial.parseInt(); 
    Serial.print(valorG);
    Serial.print(", B=");
    valorB = Serial.parseInt(); 
    Serial.println(valorB);

    // look for the newline. That's the end of your sentence:
    if (Serial.read() == '\n') {
      analogWrite(redPin, valorR);
      analogWrite(greenPin, valorG);
      analogWrite(bluePin, valorB);
    }
    Serial.print("Entra els valors R G B del color a veure (entre 0 i 1023): R=");
  }
}

//********** Funcions *************************************************************
