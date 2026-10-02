# 4-Wheel Mecanum Omnidirectional Mobile Robot

An omnidirectional mobile robotic platform designed for high-maneuverability in confined indoor environments, such as automated warehouses, congested parking slots, and logistics facilities. Utilizing four independently driven 45 ° Mecanum wheels, the platform achieves holonomic locomotion—including lateral strafing, diagonal vectoring, and zero-radius pivot rotation—without altering its orientation.

---

## Platform Specifications & Calculations

| Parameter | Value | Notes |
| :--- | :--- | :--- |
|**Wheel Diameter**| OD: 48 mm | ID: 24 mm, 45° roller angle |
| **Chassis Footprint**| 140 mm × 90 mm × 15 mm | Compact aluminum/wooden mounting base |
|**Ground Clearance**| 10 mm | Optimized for smooth floor traversal |
| **Power Source**| 7.4V (2S (18650) Li-ion Pack) | ~~1–2 hours operational runtime |
| **Wireless Control**| HC-05 Bluetooth Transceiver | 9600 baud, wireless user interface |

---

## System Architecture

```text
                 [Smartphone  / Controller]
                             |
                     (uART / Bluetooth)
                             v
                   [ Human-Machine Interface (HC-05) ]
                             |
                             v
                   [ Arduino Uno R3 (ATmega328P) ]
                             |
                             v
                   [ L293D Motor Driver Shield ]
                             |
         +----------------------+--------------------+
         |                    |                    |
         v                    v                    v
 [ MI: Front-Left ]   [ M2: Rear-Left ]   [ M3: Rear-Right ]   [ M4: Front-Right ]
   (12V TT Gear Motor)   (12VZ TT Gear Motor)  (12V TT Gear Motor)   (12V TT Gear Motor)
```

---

## KINEMATIC MOTION MATRIX

Mecanum locomotion relies on vectoring forces from the 45° angled surface rollers. Wheels are astembled in an 'X' orientation pattern:

* **Forward ('v'):** All wheels rotate forward to generate aligned translation.
* **Lateral Strafe Left ('L'):** Wheels 1 & 4 and 2 & 3 counter-rotate, cancelling forward/reverse vectors and producing pure lateral forces.
*`*Diagonal Traversal ('G', 'I', 'H', 'J'):** Only one diagonal pair of wheels rotates while the other remains at rest, producing direct 45° diagonal sliding.
* **Zero-Radius Pivot:** Left and right wheel pairs rotate in opposite directions to spin the chassis on its own central axis.

---

## Bill of Materials

|Component | Quantity | Specification |
| :--- | :--- | :--- |
|**Mecanum Wheels**| 4 | 48 mm OD, 45° roller configuration (2L + 2R) |
| **GC Motors**| 4 | L-Type TT geared DC motors with integrated reduction |
| **Motor Driver** | 1 | L293D dual H-bridge Driver Shield |
|**Microcontroller** | 1 | Arduino Uno R3 (ATMega328P) |
|**Wireless**| 1 | HC-05 Serial Bluetooth Module |
|**Power Source** | 1 | 2S 7.4V (2 x 18650 lithium-ion cells) |
| **Chassis** | 1 | 140 mm x 90 mm rigid mounting plate |

---

## Authors

* **Likith K** (Robotics & Automation Engineering)
* Guided by **Dr. Vishwanath KC**, RajaRajeswari College of Engineering
