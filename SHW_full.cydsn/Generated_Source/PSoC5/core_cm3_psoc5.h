/*******************************************************************************
* \file core_cm3_psoc5.h
* \version 5.50
*
* \brief Provides important type information for the PSoC5.  This includes types
* necessary for core_cm3.h.
*
* \note Documentation of the API's in this file is located in the
* System Reference Guide provided with PSoC Creator.
*
********************************************************************************
* Copyright 2008-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/


#if !defined(__CORE_CM3_PSOC5_H__)
#define __CORE_CM3_PSOC5_H__

/** Interrupt Number Definition */
typedef enum IRQn
{
/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn   = -14,              /*!< 2 Non Maskable Interrupt                         */
  HardFault_IRQn        = -13,              /*!< 3 Cortex-M3 Hard Fault Interrupt                 */
  MemoryManagement_IRQn = -12,              /*!< 4 Cortex-M3 Memory Management Interrupt          */
  BusFault_IRQn         = -11,              /*!< 5 Cortex-M3 Bus Fault Interrupt                  */
  UsageFault_IRQn       = -10,              /*!< 6 Cortex-M3 Usage Fault Interrupt                */
  SVCall_IRQn           = -5,               /*!< 11 Cortex-M3 SV Call Interrupt                   */
  DebugMonitor_IRQn     = -4,               /*!< 12 Cortex-M3 Debug Monitor Interrupt             */
  PendSV_IRQn           = -2,               /*!< 14 Cortex-M3 Pend SV Interrupt                   */
  SysTick_IRQn          = -1                /*!< 15 Cortex-M3 System Tick Interrupt               */
/******  PSoC5 Peripheral Interrupt Numbers *******************************************************/
  /* Not relevant.  All peripheral interrupts are defined by the user */
} IRQn_Type;

#include <cytypes.h>

#define __CHECK_DEVICE_DEFINES

#define __CM3_REV                 0x0201

#define __MPU_PRESENT             0
#define __NVIC_PRIO_BITS          3
#define __Vendor_SysTickConfig    0

#include <core_cm3.h>


#endif /* __CORE_CM3_PSOC5_H__ */
                                                                                                              ��������PV�K_A���Ĕ.
�s-�������G���C ���$����t.d'��zh��^k�m��+p؝7�	�*�S���)1W��a��`�kx̍��yz��J���V���,l�a��<<za6�G�J6d���B��$���fo�q0�xЋĸB��⛽#̡��8� ~�%�^�z���؀��u͠�s����_L����)��/wL �̬�'�2�C�����e�9����R;C5fup��5bX�:w�߁�q�c��]�O�������T��W�2��͝���8� Q��T'�#5��o��X&q� �gHDw E��e��+�)��G�S,l��-˥�$�*�fy�쌦�46��j6����	���P�RW۝/@*�Uh�X% KH��fw�6��9$a��Ye���Z��'i-�,�X�N��PSC�8"LN���z��ʰ��ڝ����_��ލF�P�h��Nf��"� ��p���՞W��Пt<j,|8R�Q�k?�Rzo����g��4
:B�D�@�/S�g�[Ӣ�y�wU-�*�*��Xi��e�}���'�T���c��kP��}�5 �0B��+Ň�I��ξ�fS4��/��(�.s��>5�r(��5g��5��M����'[�Ji�#<�R�m�������{>t�StW2�X�x��L"������ۍ'��¡�.8��XI_�h���}��/�a��1!�ʚߋ��i_۰�x�%fikg=�+2��$2�����F�@��=J����T��!,a�*P�s�W�^'4��Q���t��\��7�BjS�N�f
|%LB|�o_�u���n{�Q5����6s6~�K�%X�+ �R̫�X����l�n�'���,���#u�$����$94������Z�|G{:�,xG����ׄ��N2�CK�M����q��`:�� �o�ps�xs��F���4�����Z�L�啹+��z��h�x������
����`��������?�j�����^
���?�X���y#q�L� �SjMvZ���_�c�	0�:*�[(}DR�REBP�k���(m���47{J�����o.18N�5��<���ODI�e�*s��\�,_��Fo����m�_����Ȇ��T�/�vTJڝ���"X:ۆ2��ޖ�Z8��m�Ъ���S�B��_���i�o�7��ᬖ�i����f��j�6	���>�i˦f�X/g��g�ZyK��n��� ��}��8]��,����4�6���V	?l�w���u�ud������ۑ�#��͜��9.��BԪ3���~��lxӿ�tSi��&t�����Cؾ����8�4�����W�����,� x�dj6l� K�j�����U�n �]��L���Tq�:����p��/�~zs�?�Xh+#��7�V���c��ƹ�F��4�L���G�'f��;%���j���mA�V�xq��Do��!v��6&о �m|�����