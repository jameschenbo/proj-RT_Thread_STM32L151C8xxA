#include "app_config.h"
#include "board.h"
#include "rtthread.h"

/* example01:创建静态线程 */
#ifdef EXA_USING_CREATE_STATIC_THREAD

ALIGN(RT_ALIGN_SIZE)
/* 定义线程栈 */
static rt_uint8_t rt_led1_thread_stack[1024];

/* 定义线程控制块 */
static struct rt_thread led1_thread;

static void led1_thread_entry(void *parameter)
{
    while(1)
    {
        LED_TOGGLE();
        rt_thread_delay(300);
    }
}

/**
*创建静态线程
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

#ifdef EXA_USING_CREATE_DYNAMIC_THREAD
/* 定义线程控制块 */
static rt_thread_t led1_thread = RT_NULL;

static void led1_thread_entry(void *parameter)
{
    while(1)
    {
        LED_ON();
        rt_thread_delay(100);
        LED_OFF();
        rt_thread_delay(1000);
    }
}

void example_01_create_dynamic_thread(void)
{
    led1_thread = rt_thread_create("led1",
                      led1_thread_entry,
                      RT_NULL,
                      512,
                      3,
                      20);
    if(led1_thread != RT_NULL)
        rt_thread_startup(led1_thread);
    else
        return;
}



#endif

