"""
Read messages sent by serial_send_text_message.ino sketch

Requires Python 3.2+ with the pySerial module to be installed:

pip install pyserial

To run on OSX or Linux the command below, 
replacing /dev/tty.usbmodem142401 with the name of the serial port 
the arduino is connected to on your computer:

python serial_receive_text_message.py --serialport /dev/tty.usbmodem142401

To run on Windows the command below, replacing COM7 with the name of 
the serial port the arduino is connected to on your computer:

python serial_receive_text_message.py --serialport COM7

"""
import serial
import argparse

msg_start_marker = "M"
msg_field_delimiter = ";"


def setup_serial(serial_port_name, baudrate, timeout=1, wait=True):
    global serial_port

    serial_port = serial.Serial(
        port=serial_port_name, baudrate=baudrate, timeout=timeout, rtscts=True
    )

    print(
        "serial port "
        + serial_port_name
        + "opened with baudrate = "
        + str(baudrate)
        + ", read timeout = "
        + str(timeout)
    )

    if wait:
        wait_until_arduino_ready()


def recv_msg():
    msg = serial_port.readline().decode("utf-8")
    if len(msg) > 0 and msg[0] == msg_start_marker:
        return msg[:-1]  # strip \n at end of the message
    else:
        return "Invalid message!"


def wait_until_arduino_ready():
    """
    Wait until Arduino resets & sends 'Arduino is ready'.
    Also ensures that any bytes from previous session are discarded.
    Some boards reset (e.g Uno) when the serial port is opened, otherwise manual reset
    by user is required or this check can be bypassed by setting wait parameter
    in setup_serial function call to False.
    """
    print("waiting for Ardunio to reset...")

    msg = serial_port.readline().decode("utf-8")

    while msg.find("Arduino is ready") == -1:
        msg = serial_port.readline().decode("utf-8")


def main(serial_port_name, baudrate,):
    setup_serial(serial_port_name, baudrate, 1, True)
    while True:
        arduino_msg = recv_msg()
        print(arduino_msg)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-p", "--serialport", required=True, help="name of serial port")
    parser.add_argument("-b", "--baudrate", default=9600)
    args = parser.parse_args()

    main(args.serialport, args.baudrate)