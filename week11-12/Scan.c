#include <stdio.h>

#include <stdlib.h>

#define LOW 0

#define HIGH 199

int main()
{

    int queue[20];

    int head, q_size, temp;

    int total_movement = 0;

    int head_index;

    printf("Enter number of disk requests: ");

    scanf("%d", &q_size);

    printf("Enter head position: ");

    scanf("%d", &head);

    printf("Enter disk requests:\n");

    for (int i = 0; i < q_size; i++)
    {

        scanf("%d", &queue[i]);
    }

    queue[q_size] = head;

    q_size++;

    for (int i = 0; i < q_size - 1; i++)
    {

        for (int j = i + 1; j < q_size; j++)
        {

            if (queue[i] > queue[j])
            {

                temp = queue[i];

                queue[i] = queue[j];

                queue[j] = temp;
            }
        }
    }

    for (int i = 0; i < q_size; i++)
    {

        if (queue[i] == head)
        {

            head_index = i;

            break;
        }
    }

    printf("\n--------------------------------------------\n");

    printf("Disk Sequence (C-SCAN Order):\n");

    printf("--------------------------------------------\n");

    printf("%d", head);

    for (int i = head_index + 1; i < q_size; i++)
    {

        printf(" --> %d", queue[i]);
    }

    if (queue[q_size - 1] != HIGH)

        printf(" --> %d", HIGH);

    printf(" --> %d", LOW);

    for (int i = 0; i < head_index; i++)
    {

        printf(" --> %d", queue[i]);
    }

    total_movement = (HIGH - head) + (HIGH - LOW) + (queue[head_index - 1] - LOW);

    printf("\n\n--------------------------------------------\n");

    printf("Total Head Movement = %d\n", total_movement);

    printf("Average Head Movement = %.2f\n", (float)total_movement / (q_size - 1));

    printf("--------------------------------------------\n");

    return 0;
}
