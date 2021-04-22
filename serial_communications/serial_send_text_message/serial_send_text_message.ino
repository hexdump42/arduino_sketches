/*
 * Serial Send Delimited Text Message Sketch
 * This sketch will blink the on-board LED at a rate proportional to the digit
 * value received via the serial port.
*/

void setup()
{
    while (!Serial)
    {
        ; // wait for serial port to open, required for some boards like Nano & Leonardo
    }
    Serial.begin(9600); // send and receive at 9600 baud
    Serial.println("Arduino is ready");
}

char fieldDelimiter = ';';
String startOfMsg = "M";
String endOfMsg = "\n";
int msgSeq = 1;

void loop()
{
    // some values to send
    int msgId = msgSeq;
    String msgField1 = "This is a message";

    // create message and send
    Serial.print(createMsg(msgId, msgField1));

    delay(500);
    msgSeq++;
}

// build a message string of the following format:
// <startOfMsg>;<msgId>;<msgField1><endOfMsg>
// e.g.
// M;1;This is a message\n
String createMsg(int id, String field1)
{
    String msg = startOfMsg;
    msg.concat(fieldDelimiter);
    msg.concat(id);
    msg.concat(fieldDelimiter);
    msg.concat(field1);
    msg.concat(endOfMsg);

    return msg;
}
