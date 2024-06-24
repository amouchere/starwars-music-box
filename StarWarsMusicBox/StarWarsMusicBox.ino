// définition des broches pour les leds
#define LED_PIN_GP1_1 2
#define LED_PIN_GP1_2 3
#define LED_PIN_GP1_3 4
#define LED_PIN_GP2_1 10
#define LED_PIN_GP2_2 11
#define LED_PIN_GP2_3 12

// définition des broches pour les boutons
#define BUTTON_PIN_1 8
#define BUTTON_PIN_2 7

// définition des broches pour le speaker
#define SPEAKER_PIN 5

// définition des fréquences par note
#define c 261
#define d 294
#define e 329
#define f 349
#define fS 370
#define g 391
#define gS 415
#define a 440
#define aS 466
#define b 494
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880
// frequencies for the tones we're going to use
// used http://home.mit.bme.hu/~bako/tonecalc/tonecalc.htm to get these

int prev_button_1_state = LOW; // The previous state from the input pin
int prev_button_2_state = LOW; // The previous state from the input pin
int button_1_state;            // The current reading from the input pin
int button_2_state;            // The current reading from the input pin

void setup()
{
  Serial.begin(9600);
  Serial.println("setup");
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);

  // initialisation des broches leds et speaker comme étant une sortie
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(LED_PIN_GP1_1, OUTPUT);
  pinMode(LED_PIN_GP1_2, OUTPUT);
  pinMode(LED_PIN_GP1_3, OUTPUT);
  pinMode(LED_PIN_GP2_1, OUTPUT);
  pinMode(LED_PIN_GP2_2, OUTPUT);
  pinMode(LED_PIN_GP2_3, OUTPUT);

  lightDown();
}

void loop()
{
  lightDown();
  // read the state of the switch/button:
  button_1_state = digitalRead(BUTTON_PIN_1);
  button_2_state = digitalRead(BUTTON_PIN_2);

  if (prev_button_1_state == HIGH && button_1_state == LOW)
  {
    Serial.println("The button 1 is pressed");
    // lightUp3Led(LED_PIN_GP2_1, LED_PIN_GP2_2, LED_PIN_GP2_3);
    startThemeTune();
  }
  else if (prev_button_1_state == LOW && button_1_state == HIGH)
  {
    Serial.println("The button 1 is released");
  }

  if (prev_button_2_state == HIGH && button_2_state == LOW)
  {
    Serial.println("The button 2 is pressed");
    // lightUp3Led(LED_PIN_GP1_1, LED_PIN_GP1_2, LED_PIN_GP1_3);
    imperialMarch();
  }
  else if (prev_button_2_state == LOW && button_2_state == HIGH)
  {
    Serial.println("The button 2 is released");
  }

  // save the the last state
  prev_button_1_state = button_1_state;
  prev_button_2_state = button_2_state;
}

void lightUp(unsigned char ledPin)
{
  digitalWrite(ledPin, HIGH);
}

void lightDown(unsigned char ledPin)
{
  digitalWrite(ledPin, LOW);
}

void lightUp3Led(unsigned char led1Pin, unsigned char led2Pin, unsigned char led3Pin)
{
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, HIGH);
  digitalWrite(led3Pin, HIGH);
}

void lightDown()
{
  digitalWrite(LED_PIN_GP1_1, LOW);
  digitalWrite(LED_PIN_GP1_2, LOW);
  digitalWrite(LED_PIN_GP1_3, LOW);
  digitalWrite(LED_PIN_GP2_1, LOW);
  digitalWrite(LED_PIN_GP2_2, LOW);
  digitalWrite(LED_PIN_GP2_3, LOW);
}

void beep(unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{

  int x;
  long delayAmount = (long)(1000000 / frequencyInHertz);
  long loopTime = (long)((timeInMilliseconds * 1000) / (delayAmount * 2));
  for (x = 0; x < loopTime; x++)
  {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(delayAmount);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(delayAmount);
  }

  delay(20);
  // a little delay to make all notes sound separate
}

void imperialMarch()
{
  // for the sheet music see:
  // http://www.musicnotes.com/sheetmusic/mtd.asp?ppn=MN0016254
  // this is just a translation of said sheet music to frequencies / time in ms
  // used 500 ms for a quart note

  lightUp(LED_PIN_GP1_1);
  beep(SPEAKER_PIN, a, 500);
  lightUp(LED_PIN_GP1_2);
  beep(SPEAKER_PIN, a, 500);
  lightUp(LED_PIN_GP1_3);
  beep(SPEAKER_PIN, a, 500);
  beep(SPEAKER_PIN, f, 350);
  beep(SPEAKER_PIN, cH, 150);

  beep(SPEAKER_PIN, a, 500);
  beep(SPEAKER_PIN, f, 350);
  beep(SPEAKER_PIN, cH, 150);
  lightDown();
  beep(SPEAKER_PIN, a, 1000);
  
  // first bit
  lightUp(LED_PIN_GP1_1);
  beep(SPEAKER_PIN, eH, 500);
  lightUp(LED_PIN_GP1_2);
  beep(SPEAKER_PIN, eH, 500);
  lightUp(LED_PIN_GP1_3);
  beep(SPEAKER_PIN, eH, 500);
  beep(SPEAKER_PIN, fH, 350);
  beep(SPEAKER_PIN, cH, 150);

  beep(SPEAKER_PIN, gS, 500);
  beep(SPEAKER_PIN, f, 350);
  beep(SPEAKER_PIN, cH, 150);
  lightDown();
  beep(SPEAKER_PIN, a, 1000);
  // second bit...
  lightUp(LED_PIN_GP1_1);
  beep(SPEAKER_PIN, aH, 500); 
  lightUp(LED_PIN_GP1_2);
  beep(SPEAKER_PIN, a, 350);
  lightUp(LED_PIN_GP1_3);
  beep(SPEAKER_PIN, a, 150);
  beep(SPEAKER_PIN, aH, 500);
  
  beep(SPEAKER_PIN, gSH, 250);
  beep(SPEAKER_PIN, gH, 250);

  beep(SPEAKER_PIN, fSH, 125);
  beep(SPEAKER_PIN, fH, 125);
  beep(SPEAKER_PIN, fSH, 250);
  delay(250);
  beep(SPEAKER_PIN, aS, 250);
  beep(SPEAKER_PIN, dSH, 500);
  beep(SPEAKER_PIN, dH, 250);
  beep(SPEAKER_PIN, cSH, 250);
  // start of the interesting bit
  
  beep(SPEAKER_PIN, cH, 125);
  beep(SPEAKER_PIN, b, 125);
  beep(SPEAKER_PIN, cH, 250);
  delay(250);
  beep(SPEAKER_PIN, f, 125);
  beep(SPEAKER_PIN, gS, 500);
  beep(SPEAKER_PIN, f, 375);
  beep(SPEAKER_PIN, a, 125);

  lightDown();
  beep(SPEAKER_PIN, cH, 500);
  lightUp(LED_PIN_GP1_1);
  beep(SPEAKER_PIN, a, 375);
  lightUp(LED_PIN_GP1_2);
  beep(SPEAKER_PIN, cH, 125);
  lightUp(LED_PIN_GP1_3);
  beep(SPEAKER_PIN, eH, 1000);
  // more interesting stuff (this doesn't quite get it right somehow)

  beep(SPEAKER_PIN, aH, 500);
  beep(SPEAKER_PIN, a, 350);
  beep(SPEAKER_PIN, a, 150);
  beep(SPEAKER_PIN, aH, 500);
  beep(SPEAKER_PIN, gSH, 250);
  beep(SPEAKER_PIN, gH, 250);

  beep(SPEAKER_PIN, fSH, 125);
  beep(SPEAKER_PIN, fH, 125);
  beep(SPEAKER_PIN, fSH, 250);
  delay(250);
  beep(SPEAKER_PIN, aS, 250);
  beep(SPEAKER_PIN, dSH, 500);
  beep(SPEAKER_PIN, dH, 250);
  beep(SPEAKER_PIN, cSH, 250);
  // repeat... repeat
  
  beep(SPEAKER_PIN, cH, 125);
  beep(SPEAKER_PIN, b, 125);
  beep(SPEAKER_PIN, cH, 250);
  delay(250);
  beep(SPEAKER_PIN, f, 250);
  beep(SPEAKER_PIN, gS, 500);
  beep(SPEAKER_PIN, f, 375);
  beep(SPEAKER_PIN, cH, 125);

  beep(SPEAKER_PIN, a, 500);
  lightDown(LED_PIN_GP1_3);
  beep(SPEAKER_PIN, f, 375);
  lightDown(LED_PIN_GP1_2);
  beep(SPEAKER_PIN, c, 125);
  lightDown(LED_PIN_GP1_1);
  beep(SPEAKER_PIN, a, 1000);
  // and we're done \ó/
}

void startThemeTune()
{
  
  // http://thirdstreetmusic.blogspot.com/2012/04/recorder-ensemble-star-wars-first.html
  lightUp(LED_PIN_GP2_1);
  beep(SPEAKER_PIN, d, 250);
  lightUp(LED_PIN_GP2_2);
  beep(SPEAKER_PIN, d, 250);
  lightUp(LED_PIN_GP2_3);
  beep(SPEAKER_PIN, d, 250);
  themeTunePart1();
  delay(350);
  beep(SPEAKER_PIN, d, 125);
  delay(25);
  beep(SPEAKER_PIN, d, 250);
  delay(250);
  themeTunePart1();
  delay(250);
  themeTunePart2();
  delay(50);
  themeTunePart3();
}

void themeTunePart1()
{
  Serial.println("themeTunePart1");
  beep(SPEAKER_PIN, g, 1000);
  lightDown();
  beep(SPEAKER_PIN, dH, 1000);
  delay(250);
  lightUp(LED_PIN_GP2_1);
  beep(SPEAKER_PIN, cH, 250);
  lightUp(LED_PIN_GP2_2);
  beep(SPEAKER_PIN, b, 250);
  lightUp(LED_PIN_GP2_3);
  beep(SPEAKER_PIN, a, 250);
  beep(SPEAKER_PIN, gH, 1000);
  lightDown();
  beep(SPEAKER_PIN, dH, 1000);
  delay(125);
  lightUp(LED_PIN_GP2_1);
  beep(SPEAKER_PIN, cH, 250);
  lightUp(LED_PIN_GP2_2);
  beep(SPEAKER_PIN, b, 250);
  lightUp(LED_PIN_GP2_3);
  beep(SPEAKER_PIN, a, 250);
  beep(SPEAKER_PIN, gH, 1000);
  beep(SPEAKER_PIN, dH, 1000);
  delay(125);
  lightDown();
  beep(SPEAKER_PIN, cH, 250);
  lightUp(LED_PIN_GP2_1);
  beep(SPEAKER_PIN, b, 250);
  lightUp(LED_PIN_GP2_2);
  beep(SPEAKER_PIN, cH, 250);
  lightUp(LED_PIN_GP2_3);
  beep(SPEAKER_PIN, a, 1000);
}

void themeTunePart2()
{
  Serial.println("themeTunePart2");
  lightDown();
  beep(SPEAKER_PIN, d, 500);
  delay(25);
  lightUp(LED_PIN_GP2_1);
  beep(SPEAKER_PIN, d, 125);
  lightUp(LED_PIN_GP2_2);
  beep(SPEAKER_PIN, e, 1000);
  delay(25);
  lightUp(LED_PIN_GP2_3);
  beep(SPEAKER_PIN, e, 125);
  delay(25);
  beep(SPEAKER_PIN, cH, 250);
  beep(SPEAKER_PIN, b, 250);
  beep(SPEAKER_PIN, a, 250);
  beep(SPEAKER_PIN, g, 250);
  delay(25);
  beep(SPEAKER_PIN, g, 175);
  beep(SPEAKER_PIN, a, 175);
  beep(SPEAKER_PIN, b, 175);
  beep(SPEAKER_PIN, a, 250);
  delay(25);
  beep(SPEAKER_PIN, e, 250);
  beep(SPEAKER_PIN, fS, 500);
  delay(25);
  lightDown();
  beep(SPEAKER_PIN, d, 500);
  delay(25);
  lightUp(LED_PIN_GP2_1);
  beep(SPEAKER_PIN, d, 125);
  lightUp(LED_PIN_GP2_2);
  beep(SPEAKER_PIN, e, 1000);
  delay(25);
  lightUp(LED_PIN_GP2_3);
  beep(SPEAKER_PIN, e, 125);
  delay(75);
  beep(SPEAKER_PIN, g, 250);
  beep(SPEAKER_PIN, b, 250);
  beep(SPEAKER_PIN, a, 250);
  beep(SPEAKER_PIN, g, 250);
  delay(25);
  beep(SPEAKER_PIN, dH, 500);
  beep(SPEAKER_PIN, a, 125);
  beep(SPEAKER_PIN, a, 1000);
  delay(350);
  beep(SPEAKER_PIN, d, 500);
  delay(25);
  beep(SPEAKER_PIN, d, 125);
  beep(SPEAKER_PIN, e, 1000);
  delay(25);
  beep(SPEAKER_PIN, e, 125);
  delay(25);
  beep(SPEAKER_PIN, cH, 250);
  beep(SPEAKER_PIN, b, 250);
  beep(SPEAKER_PIN, a, 250);
  beep(SPEAKER_PIN, g, 250);
  delay(75);
  beep(SPEAKER_PIN, g, 175);
  beep(SPEAKER_PIN, a, 175);
  beep(SPEAKER_PIN, b, 175);
  beep(SPEAKER_PIN, a, 250);
  delay(50);
  beep(SPEAKER_PIN, e, 250);
  beep(SPEAKER_PIN, fS, 500);
}

void themeTunePart3()
{
  Serial.println("themeTunePart3");
  beep(SPEAKER_PIN, dH, 125);
  delay(250);
  beep(SPEAKER_PIN, dH, 125);
  beep(SPEAKER_PIN, gH, 250);
  beep(SPEAKER_PIN, fH, 250);
  beep(SPEAKER_PIN, dSH, 250);
  beep(SPEAKER_PIN, dH, 250);
  beep(SPEAKER_PIN, cH, 250);
  beep(SPEAKER_PIN, aS, 250);
  beep(SPEAKER_PIN, a, 250);
  beep(SPEAKER_PIN, g, 250);
  delay(25);
  beep(SPEAKER_PIN, dH, 500);
  delay(125);
  beep(SPEAKER_PIN, d, 250);
  lightDown(LED_PIN_GP2_3);
  delay(125);
  beep(SPEAKER_PIN, d, 125);
  lightDown(LED_PIN_GP2_2);
  beep(SPEAKER_PIN, d, 1000);
  lightDown(LED_PIN_GP2_1);
}
