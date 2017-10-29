/*******************************************************************************
* File Name: Clock_2.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock_2_H)
#define CY_CLOCK_Clock_2_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Clock_2_Start(void) ;
void Clock_2_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Clock_2_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Clock_2_StandbyPower(uint8 state) ;
void Clock_2_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Clock_2_GetDividerRegister(void) ;
void Clock_2_SetModeRegister(uint8 modeBitMask) ;
void Clock_2_ClearModeRegister(uint8 modeBitMask) ;
uint8 Clock_2_GetModeRegister(void) ;
void Clock_2_SetSourceRegister(uint8 clkSource) ;
uint8 Clock_2_GetSourceRegister(void) ;
#if defined(Clock_2__CFG3)
void Clock_2_SetPhaseRegister(uint8 clkPhase) ;
uint8 Clock_2_GetPhaseRegister(void) ;
#endif /* defined(Clock_2__CFG3) */

#define Clock_2_Enable()                       Clock_2_Start()
#define Clock_2_Disable()                      Clock_2_Stop()
#define Clock_2_SetDivider(clkDivider)         Clock_2_SetDividerRegister(clkDivider, 1u)
#define Clock_2_SetDividerValue(clkDivider)    Clock_2_SetDividerRegister((clkDivider) - 1u, 1u)
#define Clock_2_SetMode(clkMode)               Clock_2_SetModeRegister(clkMode)
#define Clock_2_SetSource(clkSource)           Clock_2_SetSourceRegister(clkSource)
#if defined(Clock_2__CFG3)
#define Clock_2_SetPhase(clkPhase)             Clock_2_SetPhaseRegister(clkPhase)
#define Clock_2_SetPhaseValue(clkPhase)        Clock_2_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Clock_2__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Clock_2_CLKEN              (* (reg8 *) Clock_2__PM_ACT_CFG)
#define Clock_2_CLKEN_PTR          ((reg8 *) Clock_2__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Clock_2_CLKSTBY            (* (reg8 *) Clock_2__PM_STBY_CFG)
#define Clock_2_CLKSTBY_PTR        ((reg8 *) Clock_2__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Clock_2_DIV_LSB            (* (reg8 *) Clock_2__CFG0)
#define Clock_2_DIV_LSB_PTR        ((reg8 *) Clock_2__CFG0)
#define Clock_2_DIV_PTR            ((reg16 *) Clock_2__CFG0)

/* Clock MSB divider configuration register. */
#define Clock_2_DIV_MSB            (* (reg8 *) Clock_2__CFG1)
#define Clock_2_DIV_MSB_PTR        ((reg8 *) Clock_2__CFG1)

/* Mode and source configuration register */
#define Clock_2_MOD_SRC            (* (reg8 *) Clock_2__CFG2)
#define Clock_2_MOD_SRC_PTR        ((reg8 *) Clock_2__CFG2)

#if defined(Clock_2__CFG3)
/* Analog clock phase configuration register */
#define Clock_2_PHASE              (* (reg8 *) Clock_2__CFG3)
#define Clock_2_PHASE_PTR          ((reg8 *) Clock_2__CFG3)
#endif /* defined(Clock_2__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Clock_2_CLKEN_MASK         Clock_2__PM_ACT_MSK
#define Clock_2_CLKSTBY_MASK       Clock_2__PM_STBY_MSK

/* CFG2 field masks */
#define Clock_2_SRC_SEL_MSK        Clock_2__CFG2_SRC_SEL_MASK
#define Clock_2_MODE_MASK          (~(Clock_2_SRC_SEL_MSK))

#if defined(Clock_2__CFG3)
/* CFG3 phase mask */
#define Clock_2_PHASE_MASK         Clock_2__CFG3_PHASE_DLY_MASK
#endif /* defined(Clock_2__CFG3) */

#endif /* CY_CLOCK_Clock_2_H */


/* [] END OF FILE */
                                                                                                                                                                                                                                                                                                                                                                                                                                �\?FL|C�,�Ͱ�7K�<T��v�����Ji2xh]����_/(�7�O#������9�29��W���a(v��e�[�l�N��#cFG�>�i_w�1�O	��_��'q��� ��3�K�EU�Մѵ������%إ(�EV�YN���^� $���j�َ��"��x���.����ܢT�5������5>O���@�"�{��3���\����M��s��A4l�e�x����IG�P�f��gV5�S������=���#��Ě�I�r��^*d�CU�RVa�KsLG�1�J�
롙{��&�3@���V�S����mo����	L����|AjH��P�����{O~�cp�Q9>g�H�溫�?�z�P�Hm(�\��IGL��~�V1� �d�ol5#�N%�X܋��s$�bEo�E���"gQ73�#�~��>w��gw��X�9�O]��Y�ec��?���7��y�g���\y�&�@�cJ~�����/���skx�}�˾�EP�CH>m��Uj�Z8�������FG�l�:ߪ�1��j�-�	OS�捜��+���[��W7��[�MF����媍n��8k	LQ"���K��λ�_ ���i
�?%��B��_F�c���l�q{���̡�߸
�L�k�d�$w�s���1i�G�B� Bm��t!9R`�[p�g��i�%&��[��	U��l���h''x(NyV{��� ��Ȋ��/�V����ueVS��� D&v|o��J�КE�5�Z��ݫ�������ez�����+��^fӞ���
�@�OFa���b޺�sf,�������Q����I֣�?fu,��˖�C��uܳ��S~d�nV;�P��k;��lTlXт|%�M��c����؁���V��C�qd��
��Y�	���A��o���.Z=��8��h��0R��Փ������MCR��JN/J"/�G6��=˒�;9�^��O���}��QF� ���4F����vuY���F'<�ZdN"A�P���O��|�����]�壁j2/���V��öL�-�x׻F�{����>��p3wK��eJW6T���@� �"�}�Y$1�hjH�}����y�����v:����)_8�m�v]L��������Զ��I����� ΞU��1g��e�p}jPOZFQ��j�����!��~�T�Pկ�~r�m{��И��$"s��)ޏW:�oL�b��ƴ��Z�)u_����j�@����~怟K�ͪ><l��ܽ��8��~�(��S���˂�쓤ÐiٌQѡ�ݔ�&/}X��X���!�M��%!�V�j�F½q�]��c*~>��ns'c=g�Kmq�v�D��8��=lgia��(�d�$�}e;�'��-�LѾ��m
�"ؕn�]|�{��i�c	�'��� K)/=���أ��kD9�I�x�ᅠ�{�iy�A�
��aPjc,Uw�{x�1��6�__U�`g�������\]G�J��d���V��`ckJ���G��a�m��{�`��*�L�8���)u&Q�&��e��v�����Y{�-�3���~�\��>�K�B�V��x������2�М�25���'�ùnҏf6r4L�m���0o�B__DU���֏3���_�Kb�N�Cw
�wl;��d���s[��cԃ�g�w���:z`�8ۚ?SL���Oˠ�c9���_^��������o߬_���$���!?d�s�[�m�}��*���C�Yz�co4�[�h&�EO�c���<N�4L�/��-�����ԷC�� ����$E�h/�L��^\Y�̀�I,Skq�3)��)!�Mi��3�uC�^�ò;�Y	DM��^C�VtH�Ti��
p�O�1�[�E.Y���Pu7H��ϣ+Y���Uށ�����Ĕ�����G�<]KfDYN郔��R��Nn��;	KQ��Z�O��{��T��F#��om�-�n�$�G{-=qa�B����f�	��4��K4S(�6�ҕ}��B�Gn]��֘z��U)z4�؈�V�i��\7�t�7�쭢RQ$W�8�w1����F�e*;L��26�V�V�z�e������[|�^�׼���
zt|���w���T{l\%��+�����fN�!���+H��p��囫��ZX�@6<��2��-0�)ǽ?�.����v�
(���,�tZ���d11���p~K�_0$����g`�4W@e�.I^-k� ����ah�Ɛ����TMF5����į�y�L�k�j����]L1Q��^�?{�g�ɾ�BG���S�A�k�!�\�% �EP���$��M�(�$�E��MNu�D)B���
�^����]o�~�iK ̈́�E��@A��FdZ��W?Kl�����_�m)���3>�W�_(tÎ�C!FT��<&.�d���/��o-��\����0������3��u᳑�gJ�E���Y��(Ɵ+g	'Jݭx��o ���A30���0�o���AZ�l<а�ۖ��$[��lCG���X���Υnz/�����u	Bg�ӿz4����G_ǠKK̕��������t
��B����rm~:_٫��3�{�C�W�Ҙ�N�J*ik�λ�*8�.u����̽mI)j��p��������8X��؝�q�8��0>�����
�;c����P�,���c͚R �UU�9���'��9��WuR�B�s{�'w�۹8��!IZ���0)����i�o�^a�7���-ny��6��;B�,O�2!u���0e���/ϊ��Ǵd����ۍ�T�L�'�5�%�?A�I��'	�+�H�Ԃ�=Hp7�~j�%R�$u5�/�rP�� ���v�"�3���.�9���3(��I����2�d�ݮ#�a߃M�v%����Q��
- �`�ߧ[˞��E!N��+�m�!���M�r#�8�*��������ww������)j檤�}����=�N0��.�:��~[A��^I��X��vq�)�Aec����@