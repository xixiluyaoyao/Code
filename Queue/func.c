#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "head.h"
// ��ʼ������
void initQueue(Queue* p) {
    p->front = 0;
    p->rear = -1;
    p->size = 0;
}

// �������Ƿ�Ϊ��
bool isEmpty(Queue* p) {
    return p->rear == -1;
}

// �������Ƿ�����
bool isFull(Queue* p) {
    return p->size == MAX_SIZE;
}

// ��Ӳ���
void enqueue(Queue* p,int value) {
    if (isFull(p)) {
        return;
    }
    p->size++;
    p->rear = (p->rear + 1) % MAX_SIZE;// ѭ�����У���βָ��ѭ���ƶ�
    p->queue[p->rear] = value;
}

// ���Ӳ���
int dequeue(Queue* p) {
    if (isEmpty(p)) {
        return -1;
    }
    p->size--;
    int value = p->queue[p->front];
    p->front = (p->front + 1) % MAX_SIZE;// ѭ����ͷ����βָ��ѭ���ƶ�
    return value;
}
void printQueue(Queue* p) {
    if (isEmpty(p)) {
        printf("����Ϊ�գ�\n");
        return;
    }
    int i = p->front;
    int cnt = 0;
    while (cnt < p->size) {
        printf("%d ", p->queue[i]);
        i = (i + 1) % MAX_SIZE;
        cnt++;
    }
    printf("\n");
}

int peek(Queue* p) {
    if (isEmpty(p)) {
        printf("����Ϊ�գ��޶���Ԫ�أ�\n");
        return -1; // ����һ������ֵ
    }
    return p->queue[p->front];
}



