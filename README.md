# ESP32 Web Server GPIO Control (GPIO 26 & 27)

A simple yet stylish web server project using the ESP32 that allows you to control two GPIO pins (GPIO 26 and GPIO 27) remotely via a browser-based interface over Wi-Fi. This project is ideal for home automation, IoT learning, or simply understanding how to interface web technologies with microcontrollers.

## 📷 Preview
(https://github.com/Aryanwankhade/ESP32-Web-Server./blob/main/circuit%20diagram%20.png)

## ✨ Features

- Control GPIO 26 and GPIO 27 from any device on your local network
- Elegant web interface using Google Fonts and responsive styling
- Real-time button status and background color changes
- Easily extendable for more GPIOs or sensors

## 🔧 Hardware Required

- ESP32 Development Board
- Micro USB Cable
- Wi-Fi Network (2.4 GHz)
- LED or other devices (optional, for testing outputs)

## 🧠 How It Works

The ESP32 hosts a web server on port 80. When accessed through a browser, it displays buttons to control GPIO 26 and GPIO 27. Clicking a button sends an HTTP GET request (`/ON26`, `/OFF26`, etc.) which toggles the respective pin and reloads the page with updated states.

## 🚀 Getting Started

### 1. Install Arduino IDE

### 2. Install ESP32 Board Package

In Arduino IDE:

- Then go to **Tools > Board > Boards Manager**
- Search for **ESP32** and install it

### 3. Upload the Code

- Open the `ESP32_Web_Server_GPIO.ino` file in Arduino IDE
- Replace your **WiFi SSID** and **password** in the code:
```cpp
const char* ssid = "Enter Your WIFI NAME";
const char* password = "Enter your WIFI PASSWORD";
    Select the correct board and port in Arduino IDE

    Upload the code

4. Access the Web Server

    Open Serial Monitor at 115200 baud

    Note the IP address printed after connecting to WiFi

    Open a browser and go to http://<your-esp32-ip>

    Control GPIO 26 and 27 using the ON/OFF buttons

📁 File Structure

ESP32_Web_Server_GPIO/
├── ESP32_Web_Server_GPIO.ino  # Main Arduino Sketch
├── README.md                  # Project Documentation
└── screenshot.png             # Optional web interface screenshot

📋 Code Output (Serial Monitor)

Connecting...
Connecting...
192.168.1.104

📌 Notes

    GPIOs 26 and 27 are safe for output control

    You can attach LEDs or relays to visualize output

    This code can be easily modified to support more GPIOs

🙋‍♂️ Author

Aryan Wankhade
Feel free to use, fork, and modify this project for your own ESP32 applications.

