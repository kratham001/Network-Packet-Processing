#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "reception.h"
#include "processing.h"
#include "forwarding.h"

// Queue handles
QueueHandle_t packetQueue;
QueueHandle_t forwardQueue;

int main(void) {
    // Initialize packet queues
    packetQueue = xQueueCreate(10, sizeof(Packet));
    forwardQueue = xQueueCreate(10, sizeof(Packet));

    // Create tasks
    xTaskCreate(vPacketReceptionTask, "Reception Task", 1000, NULL, 2, NULL);
    xTaskCreate(vPacketProcessingTask, "Processing Task", 1000, NULL, 1, NULL);
    xTaskCreate(vPacketForwardingTask, "Forwarding Task", 1000, NULL, 2, NULL);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    // Should never reach here
    while(1);
    return 0;
}
