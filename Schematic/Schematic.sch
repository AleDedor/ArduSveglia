EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x04 J1
U 1 1 614CD164
P 5850 3950
F 0 "J1" H 5930 3942 50  0000 L CNN
F 1 "RGB" H 5930 3851 50  0000 L CNN
F 2 "" H 5850 3950 50  0001 C CNN
F 3 "~" H 5850 3950 50  0001 C CNN
	1    5850 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 614CEEA9
P 5300 3850
F 0 "R1" V 5200 3850 50  0000 C CNN
F 1 "330" V 5300 3850 50  0000 C CNN
F 2 "" V 5230 3850 50  0001 C CNN
F 3 "~" H 5300 3850 50  0001 C CNN
	1    5300 3850
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 614CF949
P 5300 4050
F 0 "R2" V 5300 3950 50  0000 C CNN
F 1 "1k" V 5300 4100 50  0000 C CNN
F 2 "" V 5230 4050 50  0001 C CNN
F 3 "~" H 5300 4050 50  0001 C CNN
	1    5300 4050
	0    1    1    0   
$EndComp
Wire Wire Line
	4850 3850 5150 3850
Wire Wire Line
	5450 3850 5650 3850
Wire Wire Line
	4850 4050 5150 4050
Wire Wire Line
	5150 4150 4850 4150
Wire Wire Line
	5450 4050 5650 4050
Wire Wire Line
	5450 4150 5650 4150
$Comp
L Device:R R3
U 1 1 614CFE2C
P 5300 4150
F 0 "R3" V 5300 4050 50  0000 C CNN
F 1 "1k" V 5300 4200 50  0000 C CNN
F 2 "" V 5230 4150 50  0001 C CNN
F 3 "~" H 5300 4150 50  0001 C CNN
	1    5300 4150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 614D5BB8
P 5500 3950
F 0 "#PWR?" H 5500 3700 50  0001 C CNN
F 1 "GND" H 5505 3777 50  0000 C CNN
F 2 "" H 5500 3950 50  0001 C CNN
F 3 "" H 5500 3950 50  0001 C CNN
	1    5500 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 3950 5500 3950
$Comp
L MCU_Module:Arduino_Nano_v2.x A?
U 1 1 614DB94A
P 2850 3600
F 0 "A?" H 2850 2511 50  0000 C CNN
F 1 "Arduino_Nano_v2.x" H 2850 2420 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 2850 3600 50  0001 C CIN
F 3 "https://www.arduino.cc/en/uploads/Main/ArduinoNanoManual23.pdf" H 2850 3600 50  0001 C CNN
	1    2850 3600
	-1   0    0    -1  
$EndComp
Text GLabel 3600 4100 2    50   Input ~ 0
RED
Text GLabel 3600 4000 2    50   Input ~ 0
GREEN
Text GLabel 3600 3900 2    50   Input ~ 0
BLUE
Wire Wire Line
	3600 3900 3350 3900
Wire Wire Line
	3600 4000 3350 4000
Wire Wire Line
	3600 4100 3350 4100
Text GLabel 4850 4150 0    50   Output ~ 0
RED
Text GLabel 4850 4050 0    50   Output ~ 0
GREEN
Text GLabel 4850 3850 0    50   Output ~ 0
BLUE
$Comp
L Switch:SW_Push SW3
U 1 1 614E67B6
P 5200 2100
F 0 "SW3" H 5200 2385 50  0001 C CNN
F 1 "SW_Push" H 5200 2294 50  0001 C CNN
F 2 "" H 5200 2300 50  0001 C CNN
F 3 "~" H 5200 2300 50  0001 C CNN
	1    5200 2100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 614E7EC2
P 5350 2350
F 0 "SW2" H 5350 2635 50  0001 C CNN
F 1 "SW_Push" H 5350 2544 50  0001 C CNN
F 2 "" H 5350 2550 50  0001 C CNN
F 3 "~" H 5350 2550 50  0001 C CNN
	1    5350 2350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 614E85B0
P 5500 2600
F 0 "SW1" H 5500 2550 50  0001 C CNN
F 1 "SW_Push" H 5500 2794 50  0001 C CNN
F 2 "" H 5500 2800 50  0001 C CNN
F 3 "~" H 5500 2800 50  0001 C CNN
	1    5500 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 614E8C4C
P 5250 2800
F 0 "R4" H 5320 2846 50  0000 L CNN
F 1 "10k" H 5320 2755 50  0000 L CNN
F 2 "" V 5180 2800 50  0001 C CNN
F 3 "~" H 5250 2800 50  0001 C CNN
	1    5250 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 614EC299
P 4950 2800
F 0 "R5" H 5020 2846 50  0000 L CNN
F 1 "10k" H 5020 2755 50  0000 L CNN
F 2 "" V 4880 2800 50  0001 C CNN
F 3 "~" H 4950 2800 50  0001 C CNN
	1    4950 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 614EDE72
P 4650 2800
F 0 "R6" H 4720 2846 50  0000 L CNN
F 1 "10k" H 4720 2755 50  0000 L CNN
F 2 "" V 4580 2800 50  0001 C CNN
F 3 "~" H 4650 2800 50  0001 C CNN
	1    4650 2800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 614EE75A
P 4650 2950
F 0 "#PWR?" H 4650 2700 50  0001 C CNN
F 1 "GND" H 4655 2777 50  0000 C CNN
F 2 "" H 4650 2950 50  0001 C CNN
F 3 "" H 4650 2950 50  0001 C CNN
	1    4650 2950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 614EEB6C
P 4950 2950
F 0 "#PWR?" H 4950 2700 50  0001 C CNN
F 1 "GND" H 4955 2777 50  0000 C CNN
F 2 "" H 4950 2950 50  0001 C CNN
F 3 "" H 4950 2950 50  0001 C CNN
	1    4950 2950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 614EF0F3
P 5250 2950
F 0 "#PWR?" H 5250 2700 50  0001 C CNN
F 1 "GND" H 5255 2777 50  0000 C CNN
F 2 "" H 5250 2950 50  0001 C CNN
F 3 "" H 5250 2950 50  0001 C CNN
	1    5250 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 2100 4650 2100
Wire Wire Line
	4650 2100 4650 2650
Wire Wire Line
	5150 2350 4950 2350
Wire Wire Line
	4950 2350 4950 2650
Wire Wire Line
	5300 2600 5250 2600
Wire Wire Line
	5250 2600 5250 2650
Text GLabel 4300 2600 0    50   Output ~ 0
P1
Text GLabel 4300 2350 0    50   Output ~ 0
P2
Text GLabel 4300 2100 0    50   Output ~ 0
P3
Text GLabel 3600 3200 2    50   Input ~ 0
P1
Text GLabel 3600 3300 2    50   Input ~ 0
P2
Text GLabel 3600 3400 2    50   Input ~ 0
P3
Wire Wire Line
	3600 3200 3350 3200
Wire Wire Line
	3600 3300 3350 3300
Wire Wire Line
	3600 3400 3350 3400
$Comp
L power:+5V #PWR?
U 1 1 614F8483
P 6100 2100
F 0 "#PWR?" H 6100 1950 50  0001 C CNN
F 1 "+5V" H 6115 2273 50  0000 C CNN
F 2 "" H 6100 2100 50  0001 C CNN
F 3 "" H 6100 2100 50  0001 C CNN
	1    6100 2100
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 614F8B0C
P 6100 2350
F 0 "#PWR?" H 6100 2200 50  0001 C CNN
F 1 "+5V" H 6115 2523 50  0000 C CNN
F 2 "" H 6100 2350 50  0001 C CNN
F 3 "" H 6100 2350 50  0001 C CNN
	1    6100 2350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 614F8EE8
P 6100 2600
F 0 "#PWR?" H 6100 2450 50  0001 C CNN
F 1 "+5V" H 6115 2773 50  0000 C CNN
F 2 "" H 6100 2600 50  0001 C CNN
F 3 "" H 6100 2600 50  0001 C CNN
	1    6100 2600
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 614F9606
P 2650 2500
F 0 "#PWR?" H 2650 2350 50  0001 C CNN
F 1 "+5V" H 2665 2673 50  0000 C CNN
F 2 "" H 2650 2500 50  0001 C CNN
F 3 "" H 2650 2500 50  0001 C CNN
	1    2650 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 2100 6100 2100
Wire Wire Line
	5550 2350 6100 2350
Wire Wire Line
	5700 2600 6100 2600
Wire Wire Line
	4650 2100 4300 2100
Connection ~ 4650 2100
Wire Wire Line
	4300 2350 4950 2350
Connection ~ 4950 2350
Wire Wire Line
	5250 2600 4300 2600
Connection ~ 5250 2600
Wire Wire Line
	2650 2600 2650 2500
$Comp
L Device:LED D1
U 1 1 614FC134
P 6900 3450
F 0 "D1" V 6939 3332 50  0000 R CNN
F 1 "ALARM_ONOFF" V 6848 3332 50  0000 R CNN
F 2 "" H 6900 3450 50  0001 C CNN
F 3 "~" H 6900 3450 50  0001 C CNN
	1    6900 3450
	0    -1   -1   0   
$EndComp
Text GLabel 3600 3700 2    50   Input ~ 0
ONOFF
Text GLabel 3600 3600 2    50   Input ~ 0
BUZZER
$Comp
L Device:R R7
U 1 1 614FF219
P 6650 3300
F 0 "R7" V 6550 3300 50  0000 C CNN
F 1 "330" V 6650 3300 50  0000 C CNN
F 2 "" V 6580 3300 50  0001 C CNN
F 3 "~" H 6650 3300 50  0001 C CNN
	1    6650 3300
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 614FFF7E
P 6900 3600
F 0 "#PWR?" H 6900 3350 50  0001 C CNN
F 1 "GND" H 6905 3427 50  0000 C CNN
F 2 "" H 6900 3600 50  0001 C CNN
F 3 "" H 6900 3600 50  0001 C CNN
	1    6900 3600
	1    0    0    -1  
$EndComp
Text GLabel 6350 3300 0    50   Output ~ 0
ONOFF
Wire Wire Line
	6350 3300 6500 3300
Wire Wire Line
	6800 3300 6900 3300
$Comp
L Device:Buzzer BZ1
U 1 1 6150241F
P 6600 3900
F 0 "BZ1" H 6753 3929 50  0000 L CNN
F 1 "ALARM" H 6753 3838 50  0000 L CNN
F 2 "" V 6575 4000 50  0001 C CNN
F 3 "~" V 6575 4000 50  0001 C CNN
	1    6600 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 61506C9C
P 6500 4000
F 0 "#PWR?" H 6500 3750 50  0001 C CNN
F 1 "GND" H 6505 3827 50  0000 C CNN
F 2 "" H 6500 4000 50  0001 C CNN
F 3 "" H 6500 4000 50  0001 C CNN
	1    6500 4000
	1    0    0    -1  
$EndComp
Text GLabel 6350 3550 0    50   Output ~ 0
BUZZER
Wire Wire Line
	6350 3550 6500 3550
Wire Wire Line
	6500 3550 6500 3800
Text GLabel 2050 4000 0    50   Input ~ 0
SDA
Text GLabel 2050 4100 0    50   Input ~ 0
SCL
Wire Wire Line
	2050 4000 2350 4000
Wire Wire Line
	2350 4100 2050 4100
Text GLabel 4300 5250 0    50   Output ~ 0
SDA
Text GLabel 4300 5450 0    50   Output ~ 0
SCL
$Comp
L Device:R R8
U 1 1 6150BCF9
P 4600 4800
F 0 "R8" H 4670 4846 50  0000 L CNN
F 1 "1.5k" H 4670 4755 50  0000 L CNN
F 2 "" V 4530 4800 50  0001 C CNN
F 3 "~" H 4600 4800 50  0001 C CNN
	1    4600 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R9
U 1 1 6150CD14
P 5050 4800
F 0 "R9" H 5120 4846 50  0000 L CNN
F 1 "1.5k" H 5120 4755 50  0000 L CNN
F 2 "" V 4980 4800 50  0001 C CNN
F 3 "~" H 5050 4800 50  0001 C CNN
	1    5050 4800
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 6150F271
P 4800 4500
F 0 "#PWR?" H 4800 4350 50  0001 C CNN
F 1 "+5V" H 4815 4673 50  0000 C CNN
F 2 "" H 4800 4500 50  0001 C CNN
F 3 "" H 4800 4500 50  0001 C CNN
	1    4800 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 4500 4600 4500
Wire Wire Line
	4600 4500 4600 4650
Wire Wire Line
	4800 4500 5050 4500
Wire Wire Line
	5050 4500 5050 4650
Connection ~ 4800 4500
$Comp
L Connector_Generic:Conn_01x04 J2
U 1 1 61511426
P 6700 4900
F 0 "J2" H 6780 4892 50  0000 L CNN
F 1 "RTC" H 6780 4801 50  0000 L CNN
F 2 "" H 6700 4900 50  0001 C CNN
F 3 "~" H 6700 4900 50  0001 C CNN
	1    6700 4900
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J3
U 1 1 615138AF
P 6700 5650
F 0 "J3" H 6780 5642 50  0000 L CNN
F 1 "LCD" H 6780 5551 50  0000 L CNN
F 2 "" H 6700 5650 50  0001 C CNN
F 3 "~" H 6700 5650 50  0001 C CNN
	1    6700 5650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 61515242
P 4300 5550
F 0 "#PWR?" H 4300 5300 50  0001 C CNN
F 1 "GND" H 4305 5377 50  0000 C CNN
F 2 "" H 4300 5550 50  0001 C CNN
F 3 "" H 4300 5550 50  0001 C CNN
	1    4300 5550
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 6151682D
P 4300 6000
F 0 "#PWR?" H 4300 5850 50  0001 C CNN
F 1 "+5V" H 4315 6173 50  0000 C CNN
F 2 "" H 4300 6000 50  0001 C CNN
F 3 "" H 4300 6000 50  0001 C CNN
	1    4300 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 5450 5050 5450
Wire Wire Line
	5750 5450 5750 5850
Wire Wire Line
	5750 5850 6500 5850
Wire Wire Line
	4300 5250 4600 5250
Wire Wire Line
	5850 5250 5850 5750
Wire Wire Line
	5850 5750 6500 5750
Wire Wire Line
	4300 5550 6300 5550
Wire Wire Line
	6500 5650 6200 5650
Wire Wire Line
	4800 5650 4800 6000
Wire Wire Line
	4800 6000 4300 6000
Wire Wire Line
	6500 5100 6300 5100
Wire Wire Line
	6300 5100 6300 5550
Connection ~ 6300 5550
Wire Wire Line
	6300 5550 6500 5550
Wire Wire Line
	6200 5650 6200 5000
Wire Wire Line
	6200 5000 6500 5000
Connection ~ 6200 5650
Wire Wire Line
	6200 5650 4800 5650
Wire Wire Line
	6500 4900 5850 4900
Wire Wire Line
	5850 4900 5850 5250
Connection ~ 5850 5250
Wire Wire Line
	6500 4800 5750 4800
Wire Wire Line
	5750 4800 5750 5450
Connection ~ 5750 5450
Wire Wire Line
	4600 4950 4600 5250
Connection ~ 4600 5250
Wire Wire Line
	4600 5250 5850 5250
Wire Wire Line
	5050 4950 5050 5450
Connection ~ 5050 5450
Wire Wire Line
	5050 5450 5750 5450
Text GLabel 3150 5550 2    50   Output ~ 0
Vcc
Text GLabel 2950 2200 1    50   Output ~ 0
Vcc
Wire Wire Line
	2950 2200 2950 2600
Wire Wire Line
	3600 3700 3350 3700
Text GLabel 3600 3500 2    50   Input ~ 0
LCD
Wire Wire Line
	3350 3500 3600 3500
Wire Wire Line
	3350 3600 3600 3600
$Comp
L Regulator_Linear:L7808 U?
U 1 1 61C7E309
P 2850 5550
F 0 "U?" H 2850 5792 50  0000 C CNN
F 1 "L7808" H 2850 5701 50  0000 C CNN
F 2 "" H 2875 5400 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 2850 5500 50  0001 C CNN
	1    2850 5550
	1    0    0    -1  
$EndComp
$Comp
L pspice:CAP C1
U 1 1 61C7F410
P 2250 5900
F 0 "C1" H 2428 5946 50  0000 L CNN
F 1 "220uF" H 2428 5855 50  0000 L CNN
F 2 "" H 2250 5900 50  0001 C CNN
F 3 "~" H 2250 5900 50  0001 C CNN
	1    2250 5900
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Bridge_+-AA D?
U 1 1 61C80CC9
P 1650 5550
F 0 "D?" H 1994 5596 50  0000 L CNN
F 1 "D_Bridge_+-AA" H 1994 5505 50  0000 L CNN
F 2 "" H 1650 5550 50  0001 C CNN
F 3 "~" H 1650 5550 50  0001 C CNN
	1    1650 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 5550 2250 5550
Wire Wire Line
	2250 5650 2250 5550
Connection ~ 2250 5550
Wire Wire Line
	2250 5550 2550 5550
Wire Wire Line
	2850 5850 2850 6200
Wire Wire Line
	2850 6200 2250 6200
Wire Wire Line
	1250 6200 1250 5550
Wire Wire Line
	1250 5550 1350 5550
Wire Wire Line
	2250 6150 2250 6200
Connection ~ 2250 6200
Wire Wire Line
	2250 6200 1250 6200
$Comp
L power:AC #PWR?
U 1 1 61C8BFCB
P 800 5200
F 0 "#PWR?" H 800 5100 50  0001 C CNN
F 1 "AC" H 800 5475 50  0000 C CNN
F 2 "" H 800 5200 50  0001 C CNN
F 3 "" H 800 5200 50  0001 C CNN
	1    800  5200
	1    0    0    -1  
$EndComp
$Comp
L power:AC #PWR?
U 1 1 61C8CE0A
P 800 5800
F 0 "#PWR?" H 800 5700 50  0001 C CNN
F 1 "AC" H 800 6075 50  0000 C CNN
F 2 "" H 800 5800 50  0001 C CNN
F 3 "" H 800 5800 50  0001 C CNN
	1    800  5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  5200 1650 5200
Wire Wire Line
	1650 5200 1650 5250
Wire Wire Line
	1650 5850 800  5850
Wire Wire Line
	800  5850 800  5800
$EndSCHEMATC
