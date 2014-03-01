
#ifndef config_h
#define config_h

//#include DIY_OSD_v0_18.ino
//===========================
// Hardware Arduino or SimpleOSD 16 mhz??
//===========================

// from code version 5, support for 16 mhz SimpleOSD with Arduino bootloader have been added. It uses the 
//same microcontroller etc - but a LM1881 chip is used to detect new lines and frames.

//Arduino = 0, SimpleOSD = 1
#define CONTROLLER 0

//===========================
// Video system: PAL or NTSC
//===========================
// Pal = 0, NTSC = 1
#define VIDEO_SYSTEM 0


//=============================================================================================
// Setup
//=============================================================================================

// Baud-rate for GPS
#define BAUD 9600

// Current-sensor
#define offset_ 0
#define current_cal 0.24 
// These values should more or less be correct. Feel free to make a calibration (a few measurements and a linear approksimation) if you feel like it. 
// 25 A sensor = 0.24
// 50 A sensor = 0.49
// 100A sensor = 0.98

// How to calculate it...
// Let's say we use a 25 A current sensor that outputs 1 volt for every 5 amps.
// Our microcontroller will have 0 v = 0 and 5 volt = 1024. This means 5 A (1 volt) will show as 1024 / 5 = 205
// We want to show the amps as xx.x A - but we don't want decimals, so we will keep it a factor 10 higher.
// The calibration should then be 205 * x = 50 A (in theory 5 A, but remember the factor 10). This gives 50/205 = 0.24
// You can also take measurements and make a linear approksimatioin in excel etc - a quick test gave me more or less the same result...

// Voltage divider
#define voltage_divider_cal 1.82          // For SimpleOSD, I have used 1.82 - the formula gives 1.86. Test with a multimeter 
// Calculated by (1024)/(50*divider) 

//Altitude offset (automatic set to 0 when home-position is set)
//1 = on, 0=off.
#define altitude_offset_on_ 1

// Delay when setting home position. When GPS have GPS-fix the homeposition will automatically be set. For better accuracy a delay can be added. The delay is defined as GPS update-rate / value set.
// Example: 5 hz GPS with 25 delay will give 5 hz / 25 delay = 5 seconds delay.
#define set_home_delay 25

// Align text. On different screens/video signals I have seen, that the text is not alligned perfectly. Decreasing the number will move all text left, increasing the number will move it right.
// Smallest number allowed is 1
// Please be aware - no limits have been made, so you can move the entire text as much as you want. If you push the text "over the edge" (when you can't see it anymore) this will cause the text 
// to interrupt with the "new line sync". You can give it a try to see what it does - but I deffinately recommend to keep the text on the screen when flying :) 
#define align_text_ 22

// Depending on your model (plane/heli/car) it can be necessary to edit these parameters to show flight-summary only when landed. To disable it, just put for example 0 in speed. The speed will never be less than 0.  

// As default configured for standard plane
///*
#define summary_speed 5       // Speed less than (in km/h)
#define summary_los 100       // LOS less than (in meters)
#define summary_current 99   // Current less than (in amps)
#define summary_time 0       // Flight time more than (in seconds)
#define summary_altitude 999  // altitude less than (in meters)
//*/

/* 
// Quad/helicopter example
#define summary_speed 99       // Speed less than (in km/h)
#define summary_los 9999       // LOS less than (in meters)
#define summary_current 3   // Current less than (in amps)
#define summary_time 0       // Flight time more than (in seconds)
#define summary_altitude 999  // altitude less than (in meters)
*/

// RSSI setup. Please note, when RSSI is active it will replace mah/km.
#define show_rssi 0 // 1= on, 0 = off
#define rssi_cal 1 
#define rssi_min 103 // Minimum RSSI-value. Will be voltage * 205. 0.5 volt = 103. You can set this to zero and just read the min value and max value
#define rssi_input 1 // The input pin

// I was asked to make a calculation on mah/km - this can be useful to find the most efficient cruise-speed etc.
// It can be turned on and off as you want. Please note that it will only update when the speed is > 1 km/h.
// The number will show above mah and without unit (it's mah/km). 
//1 = on, 0=off.
#define show_mah_km_ 1

// For a cleaner look it's possible to remove decimals from speed and altitude. Speeds < 10 km/h will still show with decimals (can be changed if you wan't). 
//1 = on, 0=off.
#define show_decimals_ 1

// Hide GPS-coordinates when altitude is more than x meter
#define show_gps_coordinates_altitude 500

// If GPS-coordinates are hidden when flying higher than x m, GPS-coordinates can show every x second. If anyone uses this it should be updated a bit, right now it only looks at the last number
// Value should be 1-9 (1 = show every second (always), 2 = show once every 2. second etc.)
#define show_gps_coordinates_second 1


// Dimming can be turned off. Mainly for debugging
// 1 = on, 0 = off
#define dim_on 1

// Show plane pos
#define show_plane_pos_ 1

// Units. Meters and km/hr, or feet and miles
// 1 = meters, 0 = feet
#define units 1

// Used stored values
// From version 15 settings can be saved. This means, that even when updating software or reloading firmware settings will remain
// If you want to load the settings from this code, please change this value to 1, upload the code, change the value to 0 and upload again.
// 1 = reset/reload values, 0 = don't reload values. 
#define reset_values 0

// From software version 15 a menu can be used for configuration. You only need a single button. If no button is used, menu should be turned off.
// It will always be on if controller 1 (SimpleOSD OPEN have been choosen)
// 1 = on, 0 = off:
#define Usebutton 1

// The arduino-pin Button-pin is connected to:
#define Buttonpin_ 2

//======================================================
// Set alarms. Will blink when value is exceeded
//======================================================
// Voltage alarm (voltage will blink if it drops below the given value). To avoid decimal, use a factor 10 higher value, meaning 10 volt = 100, 8 Volt = 80 etc. 
#define volt_alarm_ 100 // 100 = 10 volt

// mah alarm. mah will blink if it exceeds the defined value. Should be written in mah, meaning 2000 mah = 2000. 
#define mah_alarm_ 2000

// los alarm. los-number will blink if it exceeds the defined value. Should be written in meter, meaning 2000 meter = 2000, 4 km = 4000 etc. 
#define los_alarm_ 2000

// Altitude alarm. altitude-number will blink if it exceeds the defined value. Should be written in meter, meaning 2000 meter = 2000, 4 km = 4000 etc. 
#define alt_alarm_ 1100



//========================================================================
// END SETUP
//========================================================================


#if (video_system == 0)
  // PAL
  #define toplinetext 41
  #define toplinenumbers 51
  #define butlinenumbers 271
  #define timer_line 252
  #define gps_nmea_line 32
  #define summaryline 102
  #define current_calc_line 292
#else 
  //NTSC
  #define toplinetext 24
  #define toplinenumbers 34
  #define butlinenumbers 229
  #define timer_line 210
  #define gps_nmea_line 15
  #define summaryline 100
  #define current_calc_line 260
#endif

// Arduino
#if (CONTROLLER == 0)

// Input from current-sensor and voltage-divider
  #define voltage_divider_input 1
  #define current_sensor_input 2


#if (dim_on == 1)
// This is used for dimming. can be changed to another pin if you want. 
  #define DimOn  DDRB |= 0b00000001;
  #define DimOff DDRB &= 0b11111110;
#else
  #define DimOn  DDRB |= 0b00000000;
  #define DimOff DDRB &= 0b11111111;
#endif  
  
  #define little_delay
  
  
 // SimpleOSD XL 16 mhz
#else
         
  // Input from current-sensor and voltage-divider
  #define voltage_divider_input 7
  #define current_sensor_input 4
  
#if (dim_on == 1)
// This is used for dimming. can be changed to another pin if you want. 
 //define SimpleOSD OPEN's dim pin C5
  #define DimOn  DDRC |= 0b00100000;
  #define DimOff DDRC &= 0b11011111;
#else
  #define DimOn  DDRB |= 0b00000000;
  #define DimOff DDRB &= 0b11111111;
#endif    
  

  
  #define little_delay _delay_loop_1(13);
  
#endif

#define mux_currentSens ADMUX = (0<<MUX3) | (0<<MUX2) | (0<<MUX1) | (current_sensor_input<<MUX0) | (1<<REFS0) |(0<<REFS1);
#define mux_batVoltage ADMUX = (0<<MUX3) | (0<<MUX2) | (0<<MUX1) | (voltage_divider_input<<MUX0) | (1<<REFS0) |(0<<REFS1);
#define mux_rssi ADMUX = (0<<MUX3) | (0<<MUX2) | (0<<MUX1) | (rssi_input<<MUX0) | (1<<REFS0) |(0<<REFS1);

// Lets define some delays
#define delay15 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
#define delay14 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
#define delay13 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
#define delay12 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
#define delay11 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
#define delay10 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
#define delay9  __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
#define delay8  __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
#define delay7  __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
#define delay6  __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
#define delay5  __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
#define delay4  __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"); 
#define delay3  __asm__("nop\n\t""nop\n\t""nop\n\t"); 
#define delay2  __asm__("nop\n\t""nop\n\t"); 
#define delay1  __asm__("nop\n\t"); 

#define clock 16000000
#define BAUD_SETTINGS clock/16/BAUD-1

#endif
