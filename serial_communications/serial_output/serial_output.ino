/*
     * Serial Output Sketch
     * This sketch prints sequential numbers to the serial port
*/

void setup()
{
    while (!Serial)
    {
        ; // wait for serial port to open, required for some boards like Nano & Leonardo
    }
    Serial.begin(9600); // send and receive at 9600 baud
}

int counter = 0;

void loop()
{
    Serial.print("The number is ");
    Serial.println(counter); // print the number, followed by a new line
    delay(1000);             // delay one second between numbers
    counter++;               // increment counter
}