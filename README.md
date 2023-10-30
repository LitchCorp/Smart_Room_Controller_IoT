# Smart_Room_Controller_IoT

The IoT Classroom Control System is a Particle Photon-based project that combines various IoT devices, including Wemo switches, Hue lightbulbs, ultrasonic sensors, PIR sensors, and a button hook, to create a smart classroom control system. This system can be used to control lighting, alert systems, and more in a classroom or similar environment.

## Table of Contents

- [Features](#features)
- [Prerequisites](#prerequisites)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Features

- Control Wemo switches to manage electrical devices in the classroom.
- Activate/deactivate lighting for Hue lightbulbs.
- Monitor the classroom environment using ultrasonic and PIR sensors.
- Display status and messages on an OLED screen.
- Customize system behavior using a button hook interface.

## Prerequisites

Before you begin, ensure you have met the following requirements:

- A Particle Photon device.
- Wi-Fi connectivity for IoT devices.
- Wemo switches and Hue lightbulbs.
- Ultrasonic sensors and PIR sensors.
- A button hook for user input.
- An OLED display for user feedback.

## Getting Started

1. Clone this repository to your Particle Photon device.
2. Install the necessary libraries and dependencies for Wemo switches, Hue lightbulbs, and OLED display.
3. Connect your IoT devices to the Particle Photon.
4. Configure the Wi-Fi credentials for your network.
5. Upload the code to the Particle Photon.

## Usage

1. Power on your Particle Photon device.
2. The system initializes, displaying a welcome message on the OLED screen.
3. Use the button hook to activate the classroom control system. The Wemo switches, Hue lightbulbs, and sensors will respond to user input.
4. Deactivate the system by using the button hook. Wemo switches and Hue lightbulbs return to their default states.
5. The system monitors the classroom environment using the ultrasonic and PIR sensors, activating a buzzer under specific conditions.

## Contributing

1. Fork the project.
2. Create a new branch for your feature (`git checkout -b feature/your-feature-name`).
3. Commit your changes (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature/your-feature-name`).
5. Open a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
