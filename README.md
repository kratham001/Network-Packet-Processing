# Network-Packet-Processing
Network Packet Processing Using RTOS

<h2>Overview</h2>
<p>This project simulates a Network Packet Processing System using FreeRTOS. It demonstrates how to handle network packets in a real-time system, where tasks are responsible for packet reception, processing, and forwarding. The system is implemented in C and built using the FreeRTOS kernel for task management, with communication handled using FreeRTOS queues.</p>

<h2>Features</h2>
<p>Packet Reception: Simulates the receipt of network packets from various sources.
Packet Processing: Processes each packet, modifying its content for forwarding.
Packet Forwarding: Forwards processed packets to their destination.
Real-time scheduling and queue-based communication using FreeRTOS.
Modular code structure with separate tasks for each function (Reception, Processing, Forwarding).</p>

<h2>How It Works</h2>
<p>The project consists of three main tasks, each handling a part of the network packet flow:

Packet Reception Task:

Receives packets from various sources.
Creates random packets with a source IP, destination IP, and payload.
Sends received packets to a queue for processing.
Packet Processing Task:

Receives packets from the reception queue.
Modifies the packet (e.g., increments the source IP).
Sends the processed packet to a forwarding queue.
Packet Forwarding Task:

Receives packets from the processing queue.
Simulates forwarding the packet to the destination.
Outputs the details of the forwarded packet to the console.</p>

<h2>Customization</h2>
<p>You can customize the following aspects of the system:

Packet Reception: Modify how packets are generated in reception.c.
Packet Processing: Implement custom packet handling logic in processing.c.
Packet Forwarding: Modify the forwarding rules in forwarding.c.</p>

<h3>By Kartikay Azad</h3>


