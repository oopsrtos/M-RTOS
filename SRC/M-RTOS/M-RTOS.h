#ifndef   M_RTOS_H
#define   M_RTOS_H
/*************************************************************************************************************************
                                                   global value define
*************************************************************************************************************************/
#ifdef     M_RTOS_GLOBALS
#define    M_RTOS_EXT
#else
#define    M_RTOS_EXT  extern
#endif

#define  m_rtos_u32 unsigned int
#define  m_rtos_u8 unsigned char
	
typedef  void                        (*M_RTOS_TASK_PTR)(void *p_arg); /*函数指针定义*/
#define  M_RTOS_PRIO_MAX                32u					/* 支持最大的优先级 */

#define	NULL	0

typedef struct	m_rtos_semaphore_def m_rtos_semaphore;//信号量

/*************************************************************************************************************************
                                                   task define
*************************************************************************************************************************/
typedef struct 
{
	m_rtos_u32    *StkPtr;
	m_rtos_u32    StkSize;
	m_rtos_u32		Priority;		/*优先级*/
	m_rtos_u32		Virtual_Pri;/*虚拟优先级*/
	m_rtos_u32		DelayTicks; /*任务延时时间,单位为tick*/
	m_rtos_semaphore *Wait_Semaphore;
}m_rtos_tcb;
/*************************************************************************************************************************
                                                   task list define
*************************************************************************************************************************/
struct	m_rtos_task_list_def
{
	struct m_rtos_task_list_def		*PrevNode;//下一个任务节点
	struct m_rtos_task_list_def		*NextNode;//下一个任务节点
	m_rtos_tcb        				*TaskPtr; //任务指针
};

typedef struct	m_rtos_task_list_def m_rtos_task_list;
/*************************************************************************************************************************
                                                   semaphore
*************************************************************************************************************************/
struct	m_rtos_semaphore_def
{
	m_rtos_tcb        						*OwnerTaskPtr; //任务指针
	m_rtos_u32        						*Value; 			 //信号量
	m_rtos_u8											Type;					 //信号量类型 0：二值信号量 1：消息邮箱
};

#define MUTEX 	 0
#define MAIL_BOX 1
#define SEMAPHORE_GET_FILE 		1
#define SEMAPHORE_GET_SUCCESS 0
#define SEMAPHORE_RELEASE_FILE 		1
#define SEMAPHORE_RELEASE_SUCCESS 0
#define INFINITE_WAIT					0xffffffff
/*************************************************************************************************************************
                                                   全局变量
*************************************************************************************************************************/
M_RTOS_EXT    m_rtos_tcb         *M_RTOS_CurPtr;		//汇编函数调用的全局变量
M_RTOS_EXT    m_rtos_tcb         *M_RTOS_RdyPtr;		//汇编函数调用的全局变量
M_RTOS_EXT    m_rtos_task_list   *M_RTOS_RdyTaskList;	//就绪任务列表
M_RTOS_EXT    m_rtos_task_list   *M_RTOS_PendTaskList;//阻塞任务列表
/*************************************************************************************************************************
                                                  函数声明
*************************************************************************************************************************/

/*************************************************************************************************************************
                                                   head file include
*************************************************************************************************************************/
#include "m_rtos_core.h"
#include "ARMCM3.h"
#include <stdlib.h>
/*************************************************************************************************************************
                                                   汇编函数的外部声明
*************************************************************************************************************************/									 
void m_rtos_set_interrupt_stop( void );
void m_rtos_set_interrupt_start( void );
void OSStartHighRdy( void );
									 
#endif
