/*
 * Serial Receive & React Sketch
 * This sketch will blink the on-board LED at a rate proportional to the digit
 * value received via the serial port.
*/
int blinkDelay = 0;

void setup()
{
    while (!Serial)
    {
        ; // wait for serial port to open, required for some boards like Nano & Leonardo
    }
    Serial.begin(9600);           // send and receive at 9600 baud
    pinMode(LED_BUILTIN, OUTPUT); //set this pin as an output
}

void loop()
{
    if (Serial.available()) // Check if there is at least one chararcter in the receive buffer
    {
        char ch = (char)Serial.read();
        if (isDigit(ch)) // must be an Ascii digit between 0 and 9
        {
            blinkDelay = (ch - '0'); // Convert Ascii value to numeric value
        }
    }
    blink();
}

// turn the LED on and off every blinkDelay seconds
void blink()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(blinkDelay * 1000); // delay based on last received blinkDelay value
    digitalWrite(LED_BUILTIN, LOW);
    delay(blinkDelay * 1000);
}