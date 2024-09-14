
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "packet.h"
#include <stdio.h>
#include "forwarding.h"

extern QueueHandle_t forwardQueue;

void vPacketForwardingTask(void *pvParameters) {
    Packet packet;
    while (1) {
        // Receive a packet to forward
        if (xQueueReceive(forwardQueue, &packet, portMAX_DELAY) == pdPASS) {
            // Simulate forwarding
            printf("Forwarding packet: Source: %d, Dest: %d, Payload: %s\n",
                   packet.source_ip, packet.dest_ip, packet.payload);
        }

        // Simulate forwarding time
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}
