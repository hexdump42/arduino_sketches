# Send Text Message From Arduino

## Problem

You want to send a multi text field message via the serial port to a computer or another serial device.

## Solution

This can be achieved by sending a text string with the individual fields separated by a delimiter character, such as a comma or semi-colon.
Each message is terminated with a LF.

See sketch serial_send_text_message.ino

The python script serial_receive_text_message.py will read the output from the sketch. Since the message sent from the arduino is terminated
with a LF, the python scripts can use the pySerial readline function to retrieve each message from the serial stream. For every valid message,
the script will print the full message and the individual fields of the message to the console.

e.g.
```
M;704;This is a message
Message Type: M
Message Id: 704
Message Field 1: This is a message
```