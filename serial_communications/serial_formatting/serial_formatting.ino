/*
      Serial Formatting Sketch
      This sketch prints variable values of the basic data types in various 
      formats to the serial port
*/

void setup()
{
    while (!Serial)
    {
        ; // wait for serial port to open, required for some boards like Nano & Leonardo
    }
    Serial.begin(9600); // send and receive at 9600 baud
}

char charVariable = 42; // Ascii *
int intVariable = 42;
byte byteVariable = 42;
float floatVariable = 42.0;

void loop()
{
    Serial.println("charVariable ");
    Serial.print("Serial.print(charVariable): ");
    Serial.print(charVariable);
    Serial.println();
    Serial.print("Serial.write(charVariable): ");
    Serial.write(charVariable);
    Serial.println();
    Serial.print("Serial.print(charVariable, DEC): ");
    Serial.print(charVariable, DEC);
    Serial.println();
    Serial.print("Serial.print(charVariable, HEX): ");
    Serial.print(charVariable, HEX);
    Serial.println();
    Serial.print("Serial.print(charVariable, OCT): ");
    Serial.print(charVariable, OCT);
    Serial.println();
    Serial.print("Serial.print(charVariable, BIN): ");
    Serial.print(charVariable, BIN);
    Serial.println();

    Serial.println("intVariable ");
    Serial.print("Serial.print(intVariable): ");
    Serial.print(intVariable);
    Serial.println();
    Serial.print("Serial.write(intVariable): ");
    Serial.write(intVariable);
    Serial.println();
    Serial.print("Serial.print(intVariable, DEC): ");
    Serial.print(intVariable, DEC);
    Serial.println();
    Serial.print("Serial.print(intVariable, HEX): ");
    Serial.print(intVariable, HEX);
    Serial.println();
    Serial.print("Serial.print(intVariable, OCT): ");
    Serial.print(intVariable, OCT);
    Serial.println();
    Serial.print("Serial.print(intVariable, BIN): ");
    Serial.print(intVariable, BIN);
    Serial.println();

    Serial.println("byteVariable ");
    Serial.print("Serial.print(byteVariable): ");
    Serial.print(byteVariable);
    Serial.println();
    Serial.print("Serial.write(byteVariable): ");
    Serial.write(byteVariable);
    Serial.println();
    Serial.print("Serial.print(byteVariable, DEC): ");
    Serial.print(byteVariable, DEC);
    Serial.println();
    Serial.print("Serial.print(byteVariable, HEX): ");
    Serial.print(byteVariable, HEX);
    Serial.println();
    Serial.print("Serial.print(byteVariable, OCT): ");
    Serial.print(byteVariable, OCT);
    Serial.println();
    Serial.print("Serial.print(byteVariable, BIN): ");
    Serial.print(byteVariable, BIN);
    Serial.println();

    Serial.println("floatVariable ");
    Serial.print("Serial.print(floatVariable): ");
    Serial.print(floatVariable);
    Serial.println();
    Serial.print("Serial.write(floatVariable): ");
    Serial.print("This will fail with a compile error similar to: error: call of overloaded 'write(float&)' is ambiguous");
    Serial.println();
    Serial.print("Serial.print(floatVariable, DEC): ");
    Serial.print(floatVariable, DEC);
    Serial.println();
    Serial.print("Serial.print(floatVariable, HEX): ");
    Serial.print(floatVariable, HEX);
    Serial.println();
    Serial.print("Serial.print(floatVariable, OCT): ");
    Serial.print(floatVariable, OCT);
    Serial.println();
    Serial.print("Serial.print(floatVariable, BIN): ");
    Serial.print(floatVariable, BIN);
    Serial.println();

    delay(1000);
    charVariable++;
    intVariable++;
    byteVariable++;
    floatVariable++;
}