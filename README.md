# Smart_Room_Controller_IoT

# Key Reminder Device

## Overview

The Key Reminder Device is designed to help people remember to hang up their keys when they get home and take their keys with them before leaving the house. It uses a combination of sensors, a button, and IoT integration to provide reminders and automate certain actions.

The main features of this project include:
- Displaying welcome and goodbye messages on an OLED display.
- Activating WeMo switches to control lights or appliances.
- Controlling Hue lightbulbs.
- Using an ultrasonic sensor to detect proximity.
- Utilizing passive infrared (PIR) sensors to detect movement.
- Sounding a buzzer as a reminder.
- Integrating IoT capabilities for remote control.

## Components Utilized

This project involves several components:

- Particle Photon 2: This is the main controller responsible for managing the sensors, buttons, and IoT devices.
- Adafruit SSD1306 OLED Display: A small OLED display to show welcome and goodbye messages.
- Button: A button for manual control and user interaction.
- Ultrasonic Sensor: Used to detect proximity to the device.
- Passive Infrared (PIR) Sensors: Detects motion within their range.
- Buzzer: Provides audio reminders.
- WeMo Switches: Controlled via the Particle Photon for managing lights or appliances.
- Hue Lightbulbs: Controlled through the Hue API to manage lighting.
- WiFi Connection: Provides internet connectivity to integrate IoT capabilities.

## Setup and Installation

Follow these steps to set up the Key Reminder Device:

1. **Hardware Connections:**
    - Connect all the components to your Particle Photon 2 according to the wiring diagram provided in your project's documentation.
    - Ensure the OLED display is correctly connected to the Photon.

2. **Particle Photon Setup:**
    - Make sure your Particle Photon is set up and connected to the internet.
    - Upload the provided code to the Photon using Particle Workbench or the Particle Web IDE.
    - ![IMG_1469](/photos/IMG_1469.jpeg)
3. **OLED Display:**
    - Install any necessary libraries for the OLED display.
    - Adjust the display settings and text messages according to your preferences.

4. **WeMo Switches:**
    - Set up your WeMo switches and ensure they are connected to your local network.
    - Update the code with your specific WeMo switch details.

5. **Hue Lightbulbs:**
    - Ensure your Hue lightbulbs are set up and connected to your Hue Bridge.
    - Update the code with your specific Hue Bridge details.

6. **IoT Network:**
    - Modify the WiFi settings in the code to connect to your IoT network.

7. **Compile and Upload:**
    - Compile and upload the code to your Particle Photon 2.

8. **Power On:**
    - Power on the device and ensure it connects to the IoT network.

## Usage

Once the device is set up and running, here's how it works:

- When you enter your home and don't press and hold the button, the device will detect your proximity using the ultrasonic sensor and check for motion using PIR sensors.
- If the right conditions are met (e.g., proximity and PIR sensor activation), the buzzer will remind you to hang up your keys.

- When you leave your home and don't press and hold the button, the device will again check for conditions using the ultrasonic sensor and PIR sensors.
- If the right conditions are met, the buzzer will remind you to take your keys with you.

- If you press and hold the button when entering, the device will display a welcome message and activate WeMo switches and Hue lightbulbs.
- If you press and hold the button when leaving, the device will display a goodbye message and deactivate WeMo switches and Hue lightbulbs.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

This project was developed as part of the IoT Classroom at CNM Ingenuity DeepDive IOT Bootcamp. Special thanks to our instructors and collaborators for their guidance and support.

## Contact

For questions or inquiries about this project, please contact Joshua Benavidez at joshua.n.benavidez@gmail.com.

---
