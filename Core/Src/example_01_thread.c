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
#ifdef EXA_USING_CREATE_SUSPEND_THREAD

static rt_thread_t led1_thread = RT_NULL;
static rt_thread_t key_thread = RT_NULL;

static void led1_thread_entry(void *parameter)
{
    while(1)
    {
        LED_ON();
        rt_thread_delay(200);
        LED_OFF();
        rt_thread_delay(200);
    }
}

 static uint8_t key_status = 0;
static void key_thread_entry(void *parameter)
{
    rt_err_t res = RT_EOK;
    while(1)
    {
        if(HAL_GPIO_ReadPin(KEY_GPIO_Port,KEY_Pin) ==0 )
        {
            HAL_Delay(100);//按键滤波
            if(HAL_GPIO_ReadPin(KEY_GPIO_Port,KEY_Pin) ==0 && (key_status == 0))
            {
                /* !!!并不一定每次都能成功,挂起线程操作不能对已经处于堵塞状态线程操作 !!!!!*/
                res = rt_thread_suspend(led1_thread);
                if(RT_EOK == res)
                {
                    key_status = 1;
                    rt_kprintf("Suspend led1 thread sucess!\n");
                }
                else
                {
                    rt_kprintf("Suspend led1 thread fialed!\n");
                }  
            }
            else if(HAL_GPIO_ReadPin(KEY_GPIO_Port,KEY_Pin) ==0 && (key_status == 1))
            {
                res = rt_thread_resume(led1_thread);
                if(RT_EOK == res)
                {
                    key_status = 0;
                    rt_kprintf("Resume led1 thread sucess!\n");
                }
                else
                {
                    rt_kprintf("Resume led1 thread fialed!\n");
                }  
            }
        }
         rt_thread_delay(20);
    }
}
void example_01_create_threads(void)
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
    
    key_thread = rt_thread_create("led1",
                      key_thread_entry,
                      RT_NULL,
                      512,
                      2,
                      20);
    if(key_thread != RT_NULL)
        rt_thread_startup(key_thread);
    else
        return; 
}

#endif

