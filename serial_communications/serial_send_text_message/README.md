# Send Text Message From Arduino

## Problem

You want to send a multi text field message via the serial port to a computer or another serial device.

## Solution

This can be achieved by sending a text string with the individual fields separated by a delinter character, such as a comma or semi-colon.

See sketch serial_send_text_message.ino

The python script serial_receive_text_message.py will read the output from the sketch.