#include "m-rtos.h"

#define  TASK1_STK_SIZE       128
#define  TASK2_STK_SIZE       128
static   m_rtos_tcb    Task1TCB;
static   m_rtos_tcb    Task2TCB;

static   m_rtos_u32   Task1Stk[TASK1_STK_SIZE];
static   m_rtos_u32   Task2Stk[TASK2_STK_SIZE];

/* 任务1 */
void Task1( void *p_arg )
{
	m_rtos_u32 flag1;
	
	for( ;; )
	{
		flag1 = 1;	
		m_rtos_delay( 100 );	
		flag1 = 0;
	}
}

/* 任务2 */
void Task2( void *p_arg )
{
	m_rtos_u32 flag2;
	
	for( ;; )
	{
		flag2 = 1;
		m_rtos_delay( 200 );		
		flag2 = 0;
	}
}

/**
 * @brief  main funtion
 * @param  none
 * @author ma57457@163.com
 * @date 2018-6-25
 */
int main(void)
{
	m_rtos_init();
	
	M_RTOS_TaskCreate ((m_rtos_tcb*)      &Task1TCB, 
	              (M_RTOS_TASK_PTR ) Task1, 
	              (void *)       0,
	              (m_rtos_u32*)     &Task1Stk[0],
	              (m_rtos_u32) TASK1_STK_SIZE,
								5);
				  
	M_RTOS_TaskCreate ((m_rtos_tcb*)      &Task2TCB, 
	              (M_RTOS_TASK_PTR ) Task2, 
	              (void *)       0,
	              (m_rtos_u32*)     &Task2Stk[0],
	              (m_rtos_u32) TASK2_STK_SIZE,
								5);	
	
	OSStartHighRdy();
}
