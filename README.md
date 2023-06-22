# ArduSveglia
Code for an alarm clock based on arduino nano Atmega328 and an RTC module DS3231

3 buttons to set all parameters:

- P1: change menu page by clicking
- P2, P3: use to increment time or date

On page 0 (TIME):
- P1: change page
- P2: increment hours
- P3: increment minutes

On page 1 (TEMP):
- P1: change page
- P2: nothing
- P3: nothing

On page 2 (ALARM):
- P1: change page
- P2: increment hours
- P3: increment minutes
- P1: long press (>2s), turn on/off the alarm. The LED will show the status.

On page 3 (DATE):
- P1: change page
- P2: select parameter to change
    a number at bottom right corner will be displayed
    0: use P3 to increment day
    1: use P3 to increment month
    2: use P3 to increment year
- P3: increment values

A RGB led is light up 15 minutes before alarm turns on, different colours will shouw up to simulate sunrise
A buzzer is used to play an alarm. Long press P1 to turn off the alarm when ringing.


