int main(void) {
    // Create packet queues
    packetQueue = xQueueCreate(10, sizeof(Packet));  // Max 10 packets in queue
    forwardQueue = xQueueCreate(10, sizeof(Packet)); // Max 10 packets in queue

    // Create tasks
    xTaskCreate(vPacketReceptionTask, "Reception Task", 1000, NULL, 2, NULL);
    xTaskCreate(vPacketProcessingTask, "Processing Task", 1000, NULL, 1, NULL);
    xTaskCreate(vPacketForwardingTask, "Forwarding Task", 1000, NULL, 2, NULL);

    // Start the scheduler
    vTaskStartScheduler();

    for (;;);
}
