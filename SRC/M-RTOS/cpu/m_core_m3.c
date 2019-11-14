#include "M-RTOS.h"

/**
 * @brief  task stack initialize
 * @param  none
 * @author ma57457@163.com
 * @date 2019.11.14
 */
m_rtos_u32 *M_RTOS_TaskStackInit (M_RTOS_TASK_PTR  p_task,
                        void         *p_arg,
                        m_rtos_u32      *p_stk_base,
                        m_rtos_u32 stk_size)
{
	m_rtos_u32  *p_stk;

	p_stk = &p_stk_base[stk_size];
													  /* Òì³£·¢ÉúÊ±×Ô¶¯±£´æµÄ¼Ä´æÆ÷                              */
	*--p_stk = (m_rtos_u32)0x01000000u;               /* xPSRµÄbit24±ØÐëÖÃ1                                     */
	*--p_stk = (m_rtos_u32)p_task;                    /* ÈÎÎñµÄÈë¿ÚµØÖ·                                         */
	*--p_stk = (m_rtos_u32)0u;                        /* R14 (LR)                                               */
	*--p_stk = (m_rtos_u32)0u;                        /* R12                                                    */
	*--p_stk = (m_rtos_u32)0u;                        /* R3                                                     */
	*--p_stk = (m_rtos_u32)0u;                        /* R2                                                     */
	*--p_stk = (m_rtos_u32)0u;                        /* R1                                                     */
	*--p_stk = (m_rtos_u32)p_arg;                     /* R0 : ÈÎÎñÐÎ²Î                                          */
													  /* Òì³£·¢ÉúÊ±ÐèÊÖ¶¯±£´æµÄ¼Ä´æÆ÷                            */
	*--p_stk = (m_rtos_u32)0u;                        /* R11                                                    */
	*--p_stk = (m_rtos_u32)0u;                        /* R10                                                    */
	*--p_stk = (m_rtos_u32)0u;                        /* R9                                                     */
	*--p_stk = (m_rtos_u32)0u;                        /* R8                                                     */
	*--p_stk = (m_rtos_u32)0u;                        /* R7                                                     */
	*--p_stk = (m_rtos_u32)0u;                        /* R6                                                     */
	*--p_stk = (m_rtos_u32)0u;                        /* R5                                                     */
	*--p_stk = (m_rtos_u32)0u;                        /* R4                                                     */
	return (p_stk);
}

