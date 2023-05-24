/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

#define SOPT5_UART0TXSRC_UART_TX 0x00u /*!<@brief UART 0 transmit data source select: UART0_TX pin */

/*! @name PORTB16 (number 62), U7[4]/UART0_RX
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_DEBUG_UART_RX_PORT PORTB                /*!<@brief PORT peripheral base pointer */
#define BOARD_DEBUG_UART_RX_PIN 16U                   /*!<@brief PORT pin number */
#define BOARD_DEBUG_UART_RX_PIN_MASK (1U << 16U)      /*!<@brief PORT pin mask */
                                                      /* @} */

/*! @name PORTB17 (number 63), U10[1]/UART0_TX
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_DEBUG_UART_TX_PORT PORTB                /*!<@brief PORT peripheral base pointer */
#define BOARD_DEBUG_UART_TX_PIN 17U                   /*!<@brief PORT pin number */
#define BOARD_DEBUG_UART_TX_PIN_MASK (1U << 17U)      /*!<@brief PORT pin mask */
                                                      /* @} */

/*! @name PORTC3 (number 73), RGB_R
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_RGB_R_GPIO GPIOC               /*!<@brief GPIO peripheral base pointer */
#define BOARD_RGB_R_GPIO_PIN_MASK (1U << 3U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_RGB_R_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_RGB_R_PIN 3U                   /*!<@brief PORT pin number */
#define BOARD_RGB_R_PIN_MASK (1U << 3U)      /*!<@brief PORT pin mask */
                                             /* @} */

/*! @name PORTB23 (number 69), J1[10]
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_RGB_G_GPIO GPIOB                /*!<@brief GPIO peripheral base pointer */
#define BOARD_RGB_G_GPIO_PIN_MASK (1U << 23U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_RGB_G_PORT PORTB                /*!<@brief PORT peripheral base pointer */
#define BOARD_RGB_G_PIN 23U                   /*!<@brief PORT pin number */
#define BOARD_RGB_G_PIN_MASK (1U << 23U)      /*!<@brief PORT pin mask */
                                              /* @} */

/*! @name PORTC2 (number 72), J1[14]
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_RGB_B_GPIO GPIOC               /*!<@brief GPIO peripheral base pointer */
#define BOARD_RGB_B_GPIO_PIN_MASK (1U << 2U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_RGB_B_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_RGB_B_PIN 2U                   /*!<@brief PORT pin number */
#define BOARD_RGB_B_PIN_MASK (1U << 2U)      /*!<@brief PORT pin mask */
                                             /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
