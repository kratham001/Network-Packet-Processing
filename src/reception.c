
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "packet.h"
#include <stdio.h>
#include <stdlib.h>
#include "reception.h"

extern QueueHandle_t packetQueue;

void vPacketReceptionTask(void *pvParameters) {
    Packet packet;
    while (1) {
        // Simulate packet reception
        packet.source_ip = rand() % 255;
        packet.dest_ip = rand() % 255;
        snprintf(packet.payload, sizeof(packet.payload), "Data from %d", packet.source_ip);

        // Send packet to processing queue
        if (xQueueSend(packetQueue, &packet, portMAX_DELAY) == pdPASS) {
            printf("Packet received: %s\n", packet.payload);
        }

        // Delay to simulate packet reception rate
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
