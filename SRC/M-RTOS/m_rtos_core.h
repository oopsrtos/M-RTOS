#ifndef M_RTOS_CORE
#define M_RTOS_CORE

#define  NVIC_INT_CTRL                      *((m_rtos_u32 *)0xE000ED04)   /* 中断控制及状态寄存器 SCB_ICSR */
#define  NVIC_PENDSVSET                                    0x10000000    /* 触发PendSV异常的值 Bit28：PENDSVSET */

#define  m_rtos_contex_switch()               NVIC_INT_CTRL = NVIC_PENDSVSET

void m_rtos_init(void);
void m_rtos_sched(void);
void M_RTOS_TaskCreate (m_rtos_tcb *p_tcb, 
                   M_RTOS_TASK_PTR   p_task, 
                   void          *p_arg,
                   m_rtos_u32       *p_stk_base,
                   m_rtos_u32  stk_size,
									 m_rtos_u32	 			stk_pri);
									 
void m_rtos_delay(m_rtos_u32 tick);
void M_RTOS_SemaphoreInit(m_rtos_semaphore *semaphore,m_rtos_u8 semaphore_type);
m_rtos_u8 M_RTOS_SemaphorePend(m_rtos_semaphore *semaphore,m_rtos_u32 wait_time);
m_rtos_u8 M_RTOS_SemaphorePost(m_rtos_semaphore *semaphore);

void m_rtos_heap_buffer_init(void);
void* m_rtos_malloc(uint32_t size);
void m_rtos_free(void* address);
#endif
