#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

#define DISCORD_EPOCH 1420070400000

void get_creation_date(uint64_t snowflake) {
    uint64_t timestamp = (snowflake >> 22) + DISCORD_EPOCH;
    time_t seconds = timestamp / 1000;
    struct tm *timeinfo = localtime(&seconds);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    printf("Creation date: %s\n", buffer);
}

int is_valid_snowflake(uint64_t snowflake) {
    int length = snprintf(NULL, 0, "%llu", snowflake);
    return length == 18 || length == 19;
}

int main() {
    uint64_t snowflake;

    while (1) {
        printf("Enter a Discord ID (enter 0 to exit): ");
        scanf("%llu", &snowflake);

        if (snowflake == 0) {
            printf("Exiting the program.\n");
            break;
        }

        if (is_valid_snowflake(snowflake)) {
            get_creation_date(snowflake);
        } else {
            printf("Invalid Discord ID.\n");
        }
    }

    return 0;
}
