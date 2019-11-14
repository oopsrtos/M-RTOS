#include "M-RTOS.h"

/**
 * @brief  task stack initialize
 * @param  none
 * @author ma57457@163.com
 * @date 2019.10.18
 */
m_rtos_u32 *M_RTOS_TaskStackInit (M_RTOS_TASK_PTR  p_task,
                        void         *p_arg,
                        m_rtos_u32      *p_stk_base,
                        m_rtos_u32 stk_size)
{
	m_rtos_u32  *p_stk;
#if (__FPU_PRESENT == 1)
	*(--p_stk) = (m_rtos_u32)0;             /* No name register */
	*(--p_stk) = (m_rtos_u32)0x03000000;    /* FPSCR		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S15		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S14		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S13		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S12		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S11		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S10		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S9		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S8		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S7		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S6		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S5		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S4		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S3		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S2		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S1		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S0		*/
#endif
	p_stk = &p_stk_base[stk_size];			/* Òì³£·¢ÉúÊ±×Ô¶¯±£´æµÄ¼Ä´æÆ÷         */
	*--p_stk = (m_rtos_u32)0x01000000u;     /* xPSRµÄbit24±ØÐëÖÃ1                 */
	*--p_stk = (m_rtos_u32)p_task;          /* ÈÎÎñµÄÈë¿ÚµØÖ·                     */
	*--p_stk = (m_rtos_u32)0u;              /* R14 (LR)                           */
	*--p_stk = (m_rtos_u32)0u;              /* R12                                */
	*--p_stk = (m_rtos_u32)0u;              /* R3                                 */
	*--p_stk = (m_rtos_u32)0u;              /* R2                                 */
	*--p_stk = (m_rtos_u32)0u;              /* R1                                 */
	*--p_stk = (m_rtos_u32)p_arg;           /* R0 : ÈÎÎñÐÎ²Î                      */
#if (__FPU_PRESENT == 1)
	*(--p_stk) = (m_rtos_u32)0;             /* S31		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S30		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S29		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S28		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S27		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S26		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S25		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S24		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S23		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S22		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S21		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S20		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S19		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S18		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S17		*/
	*(--p_stk) = (m_rtos_u32)0;             /* S16		*/
#endif													  /* Òì³£·¢ÉúÊ±ÐèÊÖ¶¯±£´æµÄ¼Ä´æÆ÷       */
	*--p_stk = (m_rtos_u32)0u;                   /* R11                                */
	*--p_stk = (m_rtos_u32)0u;                   /* R10                                */
	*--p_stk = (m_rtos_u32)0u;                   /* R9                                 */
	*--p_stk = (m_rtos_u32)0u;                   /* R8                                 */
	*--p_stk = (m_rtos_u32)0u;                   /* R7                                 */
	*--p_stk = (m_rtos_u32)0u;                   /* R6                                 */
	*--p_stk = (m_rtos_u32)0u;                   /* R5                                 */
	*--p_stk = (m_rtos_u32)0u;                   /* R4                                 */

	return (p_stk);
}

