# Smart-Parking

Uses SR04 (ultrasonic sensors) to check
for empty parking slots.

# Bit Sequencing

1 ==> Slot Full
0 ==> Slot Empty

# Serial Communication 

The bit sequence for 5 sensors is 
serially communicated to a 
microprocessor unit(a Raspberry Pi)
in this case and the serially 
communicated data is read via a 
python script.

The Data is then parsed and the 
information is fed directly to Google
Sheets via a Googel Scripts App.
