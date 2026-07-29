# 🏎️ High-Speed Autonomous Line-Follower Robot (ESP32)

An autonomous high-speed line-following robot platform powered by the ESP32 microcontroller. Designed with a closed-loop PID (Proportional-Integral-Derivative) control algorithm and QTR-8RC IR sensor array for smooth high-speed navigation and precise cornering.

---

## 🛠️ Hardware Architecture
- Microcontroller: ESP32 (32-bit Dual-Core @ 240MHz)
- Sensor Array: Pololu QTR-8RC Reflectance Sensor Array
- Motor Driver: TB6612FNG Dual H-Bridge Motor Driver
- Motors: 12V High-RPM Micro Metal Gearmotors with Encoders
- Power Supply: 3S LiPo Battery (11.1V) with LM2596 Buck Converter

---

## 🚀 Key Features & Control Logic
- PID Control Algorithm: Implements dynamic error correction to eliminate oscillation at high speeds.
- Sensor Calibration: Automatic dark/light surface calibration algorithm.
- Differential Drive Logic: Real-time PWM output adjustments for smooth cornering and speed optimization.

---

## 📂 Project Structure
```text
├── src/
│   └── main.cpp    # Core PID control logic & hardware routines
└── README.md       # Project documentation

👤 Author
 Ahmed Tamer - https://linkedin.com/in/ahmed-tamer-eng
