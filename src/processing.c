
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "packet.h"
#include <stdio.h>
#include "processing.h"

extern QueueHandle_t packetQueue;
extern QueueHandle_t forwardQueue;

void vPacketProcessingTask(void *pvParameters) {
    Packet packet;
    while (1) {
        // Receive a packet for processing
        if (xQueueReceive(packetQueue, &packet, portMAX_DELAY) == pdPASS) {
            // Modify packet for forwarding
            packet.source_ip += 1;

            printf("Processing packet from %d to %d\n", packet.source_ip, packet.dest_ip);

            // Send processed packet to forward queue
            if (xQueueSend(forwardQueue, &packet, portMAX_DELAY) == pdPASS) {
                printf("Packet processed: %s\n", packet.payload);
            }
        }

        // Simulate processing time
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}
