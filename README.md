# Air Quality Monitoring System 🌫️

## 📌 Project Overview

The Air Quality Monitoring System is an Arduino-based project designed to monitor air quality parameters using multiple sensors. The collected data is processed by the Arduino Uno and displayed on an LCD.

## 🎯 Objectives

- Monitor air quality conditions in real time
- Detect harmful gases and pollutants
- Measure temperature and humidity
- Monitor particulate matter in the air
- Display sensor readings on an LCD

## 🛠️ Hardware Components

- Arduino Uno
- DHT11 Temperature and Humidity Sensor
- MQ-7 Gas Sensor
- MQ-3 Gas Sensor
- SDS011 Dust/Particulate Matter Sensor
- 16×2 I2C LCD Display
- Buzzer
- Jumper Wires
- Power Supply

## 💻 Technologies Used

- Arduino
- Embedded C/C++
- Sensor Interfacing
- LCD Interfacing

## ⚙️ Working Principle

1. The sensors collect data from the surrounding air.
2. DHT11 measures temperature and humidity.
3. MQ-7 and MQ-3 detect gases present in the air.
4. SDS011 measures particulate matter such as PM2.5 and PM10.
5. Arduino Uno processes the sensor readings.
6. The readings are displayed on the LCD.
7. An alert can be generated when the measured values exceed the specified limits.

## 📊 Parameters Monitored

| Sensor | Parameter |
| DHT11 | Temperature & Humidity |
| MQ-7 | Carbon Monoxide (CO) |
| MQ-3 | Alcohol/Vapour-related gases |
| SDS011 | PM2.5 & PM10 |

## 🎯 Applications

- Indoor air quality monitoring
- Smart homes
- Industrial environments
- Environmental monitoring
- Smart city applications
- Pollution monitoring

## 🚀 Future Scope

- IoT-based remote monitoring
- Mobile application integration
- Cloud data storage
- Real-time AQI calculation
- Automatic warning notifications
- Data logging and analysis

## 📷 Project Prototype

The project prototype consists of an Arduino Uno, gas sensors, particulate matter sensor, temperature and humidity sensor, and LCD display.

## 👩‍💻 Project Status

Hardware prototype developed and tested.
