
/* Program untuk menampilkan posisi(jumlah counter) dan kecepatan(rpm) encoder di serial monitor */


/* Pin interrupt (di UNO 2&3 */
#define ROTARY_PIN_INTERRUPT  2

/* Pin digital biasa */ 
#define ROTARY_PIN_DIGITAL    4

/* Masukkan PPR Encoder */
#define ppr          3600

int32_t rpm;
int32_t pos;
volatile int32_t rot_count = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(ROTARY_PIN_INTERRUPT,INPUT);
  pinMode(ROTARY_PIN_DIGITAL,INPUT);
  attachInterrupt(digitalPinToInterrupt(ROTARY_PIN_INTERRUPT),ISR_Rotary,RISING);
}

void loop() 
{
  update_rpm();
}

void ISR_Rotary()
{
  if(digitalRead(ROTARY_PIN_DIGITAL)==0) rot_count++;
  else rot_count--;
}

