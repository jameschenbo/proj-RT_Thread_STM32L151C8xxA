#include "app_config.h"
#include "board.h"
#include "rtthread.h"

/* example01:������̬�߳� */
#ifdef EXA_USING_CREATE_STATIC_THREAD

ALIGN(RT_ALIGN_SIZE)
/* �����߳�ջ */
static rt_uint8_t rt_led1_thread_stack[1024];

/* �����߳̿��ƿ� */
static struct rt_thread led1_thread;

static void led1_thread_entry(void *parameter)
{
    while(1)
    {
        LED_TOGGLE();
        rt_thread_delay(500);
    }
}

/**
*������̬�߳�
*/
void example_01_create_static_thread(void)
{
    rt_thread_init(&led1_thread,
                   "led1",
                   led1_thread_entry,
                   RT_NULL,
                   &rt_led1_thread_stack[0],
                   sizeof(rt_led1_thread_stack),
                   3,
                   20);
                   
    rt_thread_startup(&led1_thread);
}
#endif

