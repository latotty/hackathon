### Laser Diode

A laser diode, or LD, is an electrically pumped semiconductor laser in which the active laser medium is formed by a p-n junction of a semiconductor diode similar to that found in a light-emitting diode.

![alt text](img/laser1.jpg)

### Raspberry PI usage:

#### Safety information!

The GPIO pins are connected directly to the BCM2835 chip at the heart of the Raspberry Pi. These provide only a 3.3V output level, and are not capable of supplying much power. More importantly, if they are damaged through misuse the Pi itself will need to be replaced.

So, if you are connecting anything more than a small LED to the GPIO output, you should use an additional circuit to boost the voltage and/or current.

#### Pinout

![alt text](img/pir2.jpg)

![alt text](img/laser2.png)

#### Wiring

![alt text](img/laser.png)

### Arduino nano usage:

#### Pinout

![alt text](img/arduino_pinout.png)

#### Wiring

![alt text](img/laserardu.png)

#### Example code
```
void setup() {
  // initialize digital pin 4 as an output.
  pinMode(4, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(4, HIGH);   // turn the Laser LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(4, LOW);    // turn the Laser LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
```

###### Source:
[Here](http://wikipedia.org)
