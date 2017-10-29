                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 CYREG_PM_ACT_CFG12)
#define CY_FLASH_PM_ACT_CFG12_PTR            (  (reg8 *) CYREG_PM_ACT_CFG12)

/* Alternate Active Power Mode Configuration Register 12 */
#define CY_FLASH_PM_ALTACT_CFG12_REG         (* (reg8 *) CYREG_PM_STBY_CFG12)
#define CY_FLASH_PM_ALTACT_CFG12_PTR         (  (reg8 *) CYREG_PM_STBY_CFG12)

/* Wake count (BUS_CLK cycles) it takes for the Flash and EEPROM to wake up */
#define CY_FLASH_SPC_FM_EE_WAKE_CNT_REG      (* (reg8 *) CYREG_SPC_FM_EE_WAKE_CNT)
#define CY_FLASH_SPC_FM_EE_WAKE_CNT_PTR      (  (reg8 *) CYREG_SPC_FM_EE_WAKE_CNT)

/* Flash macro control register */
#define CY_FLASH_SPC_FM_EE_CR_REG            (* (reg8 *) CYREG_SPC_FM_EE_CR)
#define CY_FLASH_SPC_FM_EE_CR_PTR            (  (reg8 *) CYREG_SPC_FM_EE_CR)


/* Cache Control Register */
#if (CY_PSOC3)

    #define CY_FLASH_CONTROL_REG                (* (reg8 *) CYREG_CACHE_CR )
    #define CY_FLASH_CONTROL_PTR                (  (reg8 *) CYREG_CACHE_CR )

#else

    #define CY_FLASH_CONTROL_REG                (* (reg8 *) CYREG_CACHE_CC_CTL )
    #define CY_FLASH_CONTROL_PTR                (  (reg8 *) CYREG_CACHE_CC_CTL )

#endif  /* (CY_PSOC3) */


/* EEPROM Status & Control Register */
#define CY_FLASH_EE_SCR_REG                     (* (reg8 *) CYREG_SPC_EE_SCR)
#define CY_FLASH_EE_SCR_PTR                     (  (reg8 *) CYREG_SPC_EE_SCR)



/***************************************
*     Register Constants
***************************************/

/* Power Mode Masks */

/* Enable EEPROM */
#define CY_FLASH_PM_ACT_CFG12_EN_EE             (0x10u)
#define CY_FLASH_PM_ALTACT_CFG12_EN_EE          (0x10u)

/* Enable Flash */
#if (CY_PSOC3)
    #define CY_FLASH_PM_ACT_CFG12_EN_FM         (0x01u)
    #define CY_FLASH_PM_ALTACT_CFG12_EN_FM      (0x01u)
#else
    #define CY_FLASH_PM_ACT_CFG12_EN_FM         (0x0Fu)
    #define CY_FLASH_PM_ALTACT_CFG12_EN_FM      (0x0Fu)
#endif  /* (CY_PSOC3) */



/* Frequency Constants */
#if (CY_PSOC3)
    #define CY_FLASH_CACHE_WS_VALUE_MASK        (0xC0u)
    #define CY_FLASH_CACHE_WS_1_VALUE_MASK      (0x40u)
    #define CY_FLASH_CACHE_WS_2_VALUE_MASK      (0x80u)
    #define CY_FLASH_CACHE_WS_3_VALUE_MASK      (0xC0u)

    #define CY_FLASH_CACHE_WS_1_FREQ_MAX        (22u)
    #define CY_FLASH_CACHE_WS_2_FREQ_MAX        (44u)
    #define CY_FLASH_CACHE_WS_3_FREQ_MAX        (67u)
#endif  /* (CY_PSOC3) */

#if (CY_PSOC5)
    #define CY_FLASH_CACHE_WS_VALUE_MASK        (0xE0u)
    #define CY_FLASH_CACHE_WS_1_VALUE_MASK      (0x40u)
    #define CY_FLASH_CACHE_WS_2_VALUE_MASK      (0x80u)
    #define CY_FLASH_CACHE_WS_3_VALUE_MASK      (0xC0u)
    #define CY_FLASH_CACHE_WS_4_VALUE_MASK      (0x00u)
    #define CY_FLASH_CACHE_WS_5_VALUE_MASK      (0x20u)

    #define CY_FLASH_CACHE_WS_1_FREQ_MAX        (16u)
    #define CY_FLASH_CACHE_WS_2_FREQ_MAX        (33u)
    #define CY_FLASH_CACHE_WS_3_FREQ_MAX        (50u)
    #define CY_FLASH_CACHE_WS_4_FREQ_MAX        (67u)
    #define CY_FLASH_CACHE_WS_5_FREQ_MAX        (83u)
#endif  /* (CY_PSOC5) */

#define CY_FLASH_CYCLES_MASK_SHIFT              (0x06u)
#define CY_FLASH_CYCLES_MASK                    ((uint8)(0x03u << (CY_FLASH_CYCLES_MASK_SHIFT)))

#define CY_FLASH_EE_SCR_AHB_EE_REQ              (0x01u)
#define CY_FLASH_EE_SCR_AHB_EE_ACK              (0x02u)


#define CY_FLASH_EE_EE_AWAKE                    (0x20u)

/* 5(us) * BUS_CLK(80 MHz) / granularity(2) */
#define CY_FLASH_SPC_FM_EE_WAKE_CNT_80MHZ       (0xC8u)

/* Enable clk_spc. This also internally enables the 36MHz IMO. */
#define CY_FLASH_PM_ACT_CFG0_EN_CLK_SPC         (0x08u)
#define CY_FLASH_PM_ALTACT_CFG0_EN_CLK_SPC      (0x08u)

/* Default values for getting temperature. */

#define CY_TEMP_NUMBER_OF_SAMPLES               (0x1u)
#define CY_TEMP_TIMER_PERIOD                    (0xFFFu)
#define CY_TEMP_CLK_DIV_SELECT                  (0x4u)
#define CY_TEMP_NUM_SAMPLES                     (1 << (CY_TEMP_NUMBER_OF_SAMPLES))
#define CY_SPC_CLK_PERIOD                       (120u)      /* nS */
#define CY_SYS_ns_PER_TICK                      (1000u)
#define CY_FRM_EXEC_TIME                        (1000u)     /* nS */

#define CY_GET_TEMP_TIME                        ((1 << (CY_TEMP_NUM_SAMPLES + 1)) * \
                                                    (CY_SPC_CLK_PERIOD * CY_TEMP_CLK_DIV_SELECT) * \
                                                    CY_TEMP_TIMER_PERIOD + CY_FRM_EXEC_TIME)

#define CY_TEMP_MAX_WAIT                        ((CY_GET_TEMP_TIME) / CY_SYS_ns_PER_TICK)    /* In system ticks. */


/*******************************************************************************
* Thne following code is OBSOLETE and must not be used starting with cy_boot
* 4.20.
*
* If the obsoleted macro definitions intended for use in the application use the
* following scheme, redefine your own versions of these definitions:
*    #ifdef <OBSOLETED_DEFINE>
*        #undef  <OBSOLETED_DEFINE>
*        #define <OBSOLETED_DEFINE>      (<New Value>)
*    #endif
*
* Note: Redefine obsoleted macro definitions with caution. They might still be
*       used in the application and their modification might lead to unexpected
*       consequences.
*******************************************************************************/
#if (CY_PSOC5)
    #define CY_FLASH_LESSER_OR_EQUAL_16MHz      (0x01u)
    #define CY_FLASH_LESSER_OR_EQUAL_33MHz      (0x02u)
    #define CY_FLASH_LESSER_OR_EQUAL_50MHz      (0x03u)
    #define CY_FLASH_GREATER_51MHz              (0x00u)
#endif  /* (CY_PSOC5) */

#if (CY_PSOC3)
    #define CY_FLASH_LESSER_OR_EQUAL_22MHz      (0x01u)
    #define CY_FLASH_LESSER_OR_EQUAL_44MHz      (0x02u)
    #define CY_FLASH_GREATER_44MHz              (0x03u)
#endif  /* (CY_PSOC3) */

#define CY_FLASH_PM_ACT_EEFLASH_REG         (* (reg8 *) CYREG_PM_ACT_CFG12)
#define CY_FLASH_PM_ACT_EEFLASH_PTR         (  (reg8 *) CYREG_PM_ACT_CFG12)
#define CY_FLASH_PM_ALTACT_EEFLASH_REG      (* (reg8 *) CYREG_PM_STBY_CFG12)
#define CY_FLASH_PM_ALTACT_EEFLASH_PTR      (  (reg8 *) CYREG_PM_STBY_CFG12)
#define CY_FLASH_PM_EE_MASK                 (0x10u)
#define CY_FLASH_PM_FLASH_MASK              (0x01u)

/*******************************************************************************
* The following code is OBSOLETE and must not be used starting with cy_boot 3.0
*******************************************************************************/
#define FLASH_SIZE                  (CY_FLASH_SIZE)
#define FLASH_SIZEOF_SECTOR         (CY_FLASH_SIZEOF_ARRAY)
#define FLASH_NUMBER_ROWS           (CY_FLASH_NUMBER_ROWS)
#define FLASH_NUMBER_SECTORS        (CY_FLASH_NUMBER_ARRAYS)
#define EEPROM_SIZE                 (CY_EEPROM_SIZE)
#define EEPROM_SIZEOF_SECTOR        (CYDEV_EEPROM_SECTOR_SIZE)
#define EEPROM_NUMBER_ROWS          (CY_EEPROM_NUMBER_ROWS)
#define EEPROM_NUMBER_SECTORS       (CY_EEPROM_NUMBER_SECTORS)


/*******************************************************************************
* The following code is OBSOLETE and must not be used starting with cy_boot 3.30
*******************************************************************************/
#define FLASH_CYCLES_PTR            (CY_FLASH_CONTROL_PTR)

#define TEMP_NUMBER_OF_SAMPLES      (CY_TEMP_NUMBER_OF_SAMPLES)
#define TEMP_TIMER_PERIOD           (CY_TEMP_TIMER_PERIOD)
#define TEMP_CLK_DIV_SELECT         (CY_TEMP_CLK_DIV_SELECT)
#define NUM_SAMPLES                 (CY_TEMP_NUM_SAMPLES)
#define SPC_CLK_PERIOD              (CY_SPC_CLK_PERIOD)
#define FRM_EXEC_TIME               (CY_FRM_EXEC_TIME)
#define GET_TEMP_TIME               (CY_GET_TEMP_TIME)
#define TEMP_MAX_WAIT               (CY_TEMP_MAX_WAIT)

#define ECC_ADDR                    (0x80u)


#define PM_ACT_EE_PTR           (CY_FLASH_PM_ACT_EEFLASH_PTR)
#define PM_ACT_FLASH_PTR        (CY_FLASH_PM_ACT_EEFLASH_PTR)

#define PM_STBY_EE_PTR          (CY_FLASH_PM_ALTACT_EEFLASH_PTR)
#define PM_STBY_FLASH_PTR       (CY_FLASH_PM_ALTACT_EEFLASH_PTR)

#define PM_EE_MASK              (CY_FLASH_PM_EE_MASK)
#define PM_FLASH_MASK           (CY_FLASH_PM_FLASH_MASK)

#define FLASH_CYCLES_MASK_SHIFT     (CY_FLASH_CYCLES_MASK_SHIFT)
#define FLASH_CYCLES_MASK           (CY_FLASH_CYCLES_MASK)


#if (CY_PSOC3)

    #define LESSER_OR_EQUAL_22MHz   (CY_FLASH_LESSER_OR_EQUAL_22MHz)
    #define LESSER_OR_EQUAL_44MHz   (CY_FLASH_LESSER_OR_EQUAL_44MHz)
    #define GREATER_44MHz           (CY_FLASH_GREATER_44MHz)

#endif  /* (CY_PSOC3) */

#if (CY_PSOC5)

    #define LESSER_OR_EQUAL_16MHz   (CY_FLASH_LESSER_OR_EQUAL_16MHz)
    #define LESSER_OR_EQUAL_33MHz   (CY_FLASH_LESSER_OR_EQUAL_33MHz)
    #define LESSER_OR_EQUAL_50MHz   (CY_FLASH_LESSER_OR_EQUAL_50MHz)
    #define LESSER_OR_EQUAL_67MHz   (CY_FLASH_LESSER_OR_EQUAL_67MHz)
    #define GREATER_67MHz           (CY_FLASH_GREATER_67MHz)
    #define GREATER_51MHz           (CY_FLASH_GREATER_51MHz)

#endif  /* (CY_PSOC5) */

#define AHUB_EE_REQ_ACK_PTR         (CY_FLASH_EE_SCR_PTR)


#endif  /* (CY_BOOT_CYFLASH_H) */


/* [] END OF FILE */
                                                                  QiTNWFiWlrbpbqgwAAAAAAAASJMIIEhTCCA22gAwIBAgIIOzyY6Xi8gwUwDQYJKoZIhvcNAQELBQAwSTELMAkGA1UEBhMCVVMxEzARBgNVBAoTCkdvb2dsZSBJbmMxJTAjBgNVBAMTHEdvb2dsZSBJbnRlcm5ldCBBdXRob3JpdHkgRzIwHhcNMTcxMDEwMTQzMzU2WhcNMTcxMjI5MDAwMDAwWjBlMQswCQYDVQQGEwJVUzETMBEGA1UECAwKQ2FsaWZvcm5pYTEWMBQGA1UEBwwNTW91bnRhaW4gVmlldzETMBEGA1UECgwKR29vZ2xlIEluYzEUMBIGA1UEAwwLKi5nb29nbGUuaXMwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC2ebMydgREvzy1vsU/PQy5mTXEnVFcn4K1aBx8Q8s3Smwq3iBzysGOGCo4tzqB0KqxBEQ+Hzy96LEt5PmrX+362xOveQUOblEfFrzmHaSQlf2ghR8UDE2+rX/NmmQ3CKfyG+CRUmoMFthn/QQHCXlQBRk3p9kfxYkupjvc+ZMNm9pyux/dVni5BNdFN6ZY3vLGPpnunusL/C2qkWai5cYVlWoC5If+JrHS2r1iajyvY+BrNWTYmlhJPyTNajcqmHzMpYcDHBggs3O1D6xSoj5NXj4WTPt+maQpxVBGsl7ZFBaBuJhxaQnzm+arGfT/VorTO/MFB52tjFErAmoFY8KzAgMBAAGjggFTMIIBTzAdBgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwIQYDVR0RBBowGIILKi5nb29nbGUuaXOCCWdvb2dsZS5pczBoBggrBgEFBQcBAQRcMFowKwYIKwYBBQUHMAKGH2h0dHA6Ly9wa2kuZ29vZ2xlLmNvbS9HSUFHMi5jcnQwKwYIKwYBBQUHMAGGH2h0dHA6Ly9jbGllbnRzMS5nb29nbGUuY29tL29jc3AwHQYDVR0OBBYEFHoTDMsy98dQsvQNtyVfIMak+HI9MAwGA1UdEwEB/wQCMAAwHwYDVR0jBBgwFoAUSt0GFhu89mi1dvWBtrtiGrpagS8wIQYDVR0gBBowGDAMBgorBgEEAdZ5AgUBMAgGBmeBDAECAjAwBgNVHR8EKTAnMCWgI6Ahhh9odHRwOi8vcGtpLmdvb2dsZS5jb20vR0lBRzIuY3JsMA0GCSqGSIb3DQEBCwUAA4IBAQCMAwg8SZCxzt/ttoxFbt/xpzx+jSPdFPxmdqHR2tXL6ZHwamPjXoZotTHNCkUAR20tDs2HkiSeorAi0PcXwW+pRqjugEo/dc64BYyjUlX7AnR8Xbp9MIj7NrQKrvuCVejsykxPFSKobPDqzxeVFqaP2YefbfaB+t/mzt8DVilPayEd1LZ+aiBfLC7MOoeR95Bzlca4xOlI9g/jxANKv5OtU/umG7ZhKYVMCldzcnzAKW1ooTYbMSK63aGYq0mmKF2KCxsSa1yC15HMZveSUxrTxVe+f+zEgkQmBf8PALhA0F7GCjaeS0l8XK/DGrH3x6jdAe2SDbZypN7sg6onI9ymwC8BAwAAAAABAQAAAAA= request-method GET response-head HTTP/2.0 200 OK
date: Thu, 19 Oct 2017 10:46:11 GMT
expires: Tue, 03 Jul 2018 15:36:33 GMT
content-type: image/png
access-control-allow-origin: *
content-security-policy: script-src 'none'; object-src 'none'; base-uri 'none'
x-content-type-options: nosniff
server: paintfe
content-length: 528
x-xss-protection: 1; mode=block
x-frame-options: SAMEORIGIN
cache-control: public, max-age=22222222
age: 361223
alt-svc: quic=":443"; ma=2592000; v="39,38,37,35"
X-Firefox-Spdy: h2
 original-response-headers date: Thu, 19 Oct 2017 10:46:11 GMT
expires: Tue, 03 Jul 2018 15:36:33 GMT
content-type: image/png
access-control-allow-origin: *
content-security-policy: script-src 'none'; object-src 'none'; base-uri 'none'
x-content-type-options: nosniff
server: paintfe
content-length: 528
x-xss-protection: 1; mode=block
x-frame-options: SAMEORIGIN
cache-control: public, max-age=22222222
age: 361223
alt-svc: quic=":443"; ma=2592000; v="39,38,37,35"
X-Firefox-Spdy: h2
 net-response-time-onstart 42 net-response-time-onstop 42                                                                                                                                                                                                                                                                                                                                                                                                             