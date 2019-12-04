# ESP8266_Temperature_Sensor

This is an arduino sketch, used on a ESP8266 board. The goal is to send temperature readings via Wifi to a remote api.

I have used pin A0 ( the only analog pin ) to connect up the temperature sensor to the board. The readings are then converted into degrees Celcius before being uploaded to the web api.
