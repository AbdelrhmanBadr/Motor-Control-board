/** @file Atmega32A.h
*
* @brief This file is used to define all configurations and registers related to microcontrollers .
* @note THIS FILE MUST BE INCLUDED AT ALL SOURCE FILES
* @author Abdelrhman Badr
* @lastUpdate 27-sep-21
*/

#ifndef Atmega32A_H_
#define Atmega32A_H_

/*Cpu frequency*/
#define CPU_FREQUENCY	(8000000UL)
#define F_CPU			(8000000UL)
/*Define null*/
#define NULL			(0)

/*Define microcontroller pins*/
#define PIN7	(7)
#define PIN6	(6)
#define PIN5	(5)
#define PIN4	(4)
#define PIN3	(3)
#define PIN2	(2)
#define PIN1	(1)
#define PIN0	(0)

/*Define microcontroller ports*/
#define PORTA	(1)
#define PORTB	(2)
#define PORTC	(3)
#define PORTD	(4)

/*Define Special pins and its port*/

/*For ADC*/
#define ADC_PORT	(PORTA)
#define ADC7_PIN	(7)
#define ADC6_PIN	(6)
#define ADC5_PIN	(5)
#define ADC4_PIN	(4)
#define ADC3_PIN	(3)
#define ADC2_PIN	(2)
#define ADC1_PIN	(1)
#define ADC0_PIN	(0)

/*For timer*/
#define T0_PORT		(PORTB)
#define T0_PIN		(PIN0)
#define T1_PORT		(PORTB)
#define T1_PIN		(PIN1)
#define OC0_PORT	(PORTB)
#define OC0_PIN		(PIN3)
#define OC1A_PORT	(PORTD)
#define OC1A_PIN	(PIN5)
#define OC1B_PORT	(PORTD)
#define OC1B_PIN	(PIN4)
#define OC2_PORT	(PORTD)
#define OC2_PIN	(PIN7)

/*For external interrupt*/
#define INT2_PORT	(PORTB)
#define INT2_PIN	(PIN2)
#define INT1_PORT	(PORTD)
#define INT1_PIN	(PIN3)
#define INT0_PORT	(PORTD)
#define INT0_PIN	(PIN2)

/*For SPI*/
#define SS_PORT	(PORTB)
#define SS_PIN		(PIN4)
#define MOSI_PORT	(PORTB)
#define MOSI_PIN	(PIN5)
#define MISO_PORT	(PORTB)
#define MISO_PIN	(PIN6)
#define SCK_PORT	(PORTB)
#define SCK_PIN	(PIN7)

/*For I2C*/
#define SCL_PORT	(PORTC)
#define SCL_PIN		(PIN0)
#define SDA_PORT	(PORTC)
#define SDA_PIN	(PIN1)

/*For USART*/
#define RX_PORT		(PORTD)
#define RX_PIN		(PIN0)
#define TX_PORT		(PORTD)
#define TX_PIN		(PIN1)

/*Define Atmega32a registers*/

#define SREG_REG		(*( ( volatile uint8 * ) 0X5F ) )
#define SREG_I_BIT		(7)
#define SREG_T_BIT		(6)
#define SREG_H_BIT		(5)
#define SREG_S_BIT		(4)
#define SREG_V_BIT		(3)
#define SREG_N_BIT		(2)
#define SREG_Z_BIT		(1)
#define SREG_C_BIT		(0)

#define SPH_REG		(*( ( volatile uint8 * ) 0X5E ) )
#define SPH_SP11_BIT	(3)
#define SPH_SP10_BIT	(2)
#define SPH_SP9_BIT		(1)
#define SPH_SP8_BIT		(0)

#define SPL_REG		(*( ( volatile uint8 * ) 0X5D ) )
#define SPL_SP7_BIT		(7)
#define SPL_SP6_BIT		(6)
#define SPL_SP5_BIT		(5)
#define SPL_SP4_BIT		(4)
#define SPL_SP3_BIT		(3)
#define SPL_SP2_BIT		(2)
#define SPL_SP1_BIT		(1)
#define SPL_SP0_BIT		(0)

#define OCR0_REG		(*(( volatile uint8 * )0X5C ))

#define GICR_REG		(*(( volatile uint8 * )0X5B ))
#define GICR_INT1_BIT		(7)
#define GICR_INT0_BIT		(6)
#define GICR_INT2_BIT		(5)
#define GICR_IVSEL_BIT		(1)
#define GICR_IVCE_BIT		(0)	

#define GIFR_REG		(*(( volatile uint8 * )0X5A ))
#define GIFR_INTF1_BIT		(7)
#define GIFR_INTF0_BIT		(6)
#define GIFR_INTF2_BIT		(5)

#define TIMSK_REG		(*(( volatile uint8 * )0X59 ))
#define TIMSK_OCIE2_BIT		(7)
#define TIMSK_TOIE2_BIT		(6)
#define TIMSK_TICIE1_BIT	(5)
#define TIMSK_OCIE1A_BIT	(4)
#define TIMSK_OCIE1B_BIT	(3)
#define TIMSK_TOIE1_BIT		(2)
#define TIMSK_OCIE0_BIT		(1)
#define TIMSK_TOIE0_BIT		(0)

#define TIFR_REG		(*(( volatile uint8 * )0X58 ))
#define TIFR_OCF2_BIT		(7)
#define TIFR_TOV2_BIT		(6)
#define TIFR_ICF1_BIT		(5)
#define TIFR_OCF1A_BIT		(4)
#define TIFR_OCF1B_BIT		(3)
#define TIFR_TOV1_BIT		(2)
#define TIFR_OCF0_BIT		(1)
#define TIFR_TOV0_BIT		(0)
       
#define SPMCR_REG		(*(( volatile uint8 * )0X57))
#define SPMCR_SPMIE_BIT		(7)
#define SPMCR_RWWSB_BIT		(6)
#define SPMCR_RWWSRE_BIT	(4)
#define SPMCR_BLBSET_BIT	(3)
#define SPMCR_PGWRT_BIT		(2)
#define SPMCR_PGERS_BIT		(1)
#define SPMCR_SPMEN_BIT		(0)
       
#define TWCR_REG		(*(( volatile uint8 * )0X56))
#define TWCR_TWINT_BIT		(7)
#define TWCR_TWEA_BIT		(6)
#define TWCR_TWSTA_BIT		(5)
#define TWCR_TWSTO_BIT		(4)
#define TWCR_TWWC_BIT		(3)
#define TWCR_TWEN_BIT		(2)
#define TWCR_TWIE_BIT		(0)
       
#define MCUCR_REG		(*(( volatile uint8 * )0X55 ))
#define MCUCR_SE_BIT		(7)
#define MCUCR_SM2_BIT		(6)
#define MCUCR_SM1_BIT		(5)
#define MCUCR_SM0_BIT		(4)
#define MCUCR_ISC11_BIT		(3)
#define MCUCR_ISC10_BIT		(2)
#define MCUCR_ISC01_BIT		(1)
#define MCUCR_ISC00_BIT		(0)
       
#define MCUCSR_REG		(*(( volatile uint8 * )0X54))
#define MCUCSR_JTD_BIT		(7)
#define MCUCSR_ISC2_BIT		(6)
#define MCUCSR_JTRF_BIT		(4)
#define MCUCSR_WDRF_BIT		(3)
#define MCUCSR_BORF_BIT		(2)
#define MCUCSR_EXTRF_BIT	(1)
#define MCUCSR_PORF_BIT		(0)
       
#define TCCR0_REG		(*(( volatile uint8 * )0X53 ))
#define TCCR0_FOC0_BIT		(7)
#define TCCR0_WGM00_BIT		(6)
#define TCCR0_COM01_BIT		(5)
#define TCCR0_COM00_BIT		(4)
#define TCCR0_WGM01_BIT		(3)
#define TCCR0_CS02_BIT		(2)
#define TCCR0_CS01_BIT		(1)
#define TCCR0_CS00_BIT		(0)

#define TCNT0_REG		(*(( volatile uint8 * )0X52))
#define OSCCAL_REG		(*(( volatile uint8 * )0X51))
#define OCDR_REG		(*(( volatile uint8 * )0X51))
  
#define SFIOR_REG		(*(( volatile uint8 * )0X50 ))
#define SFIOR_ADTS2_BIT		(7)
#define SFIOR_ADTS1_BIT		(6)
#define SFIOR_ADTS0_BIT		(5)
#define SFIOR_ACME_BIT		(3)
#define SFIOR_PUD_BIT		(2)
#define SFIOR_PSR2_BIT		(1)
#define SFIOR_PSR10_BIT		(0)
       
#define TCCR1A_REG		(*(( volatile uint8 * )0X4F ))
#define TCCR1A_COM1A1_BIT		(7)
#define TCCR1A_COM1A0_BIT		(6)
#define TCCR1A_COM1B1_BIT		(5)
#define TCCR1A_COM1B0_BIT		(4)
#define TCCR1A_FOC1A_BIT		(3)
#define TCCR1A_FOC1B_BIT		(2)
#define TCCR1A_WGM11_BIT		(1)
#define TCCR1A_WGM10_BIT		(0)
       
#define TCCR1B_REG		(*(( volatile uint8 * )0X4E ))
#define TCCR1B_ICNC1_BIT	(7)
#define TCCR1B_ICES1_BIT	(6)
#define TCCR1B_WGM13_BIT	(4)
#define TCCR1B_WGM12_BIT	(3)
#define TCCR1B_CS12_BIT		(2)
#define TCCR1B_CS11_BIT		(1)
#define TCCR1B_CS10_BIT		(0)

#define TCNT1H_REG		(*(( volatile uint8 * )0X4D ))
#define TCNT1L_REG		(*(( volatile uint8 * )0X4C ))
#define OCR1AH_REG		(*(( volatile uint8 * )0X4B ))
#define OCR1AL_REG		(*(( volatile uint8 * )0X4A ))
#define OCR1BH_REG		(*(( volatile uint8 * )0X49 ))
#define OCR1BL_REG		(*(( volatile uint8 * )0X48 ))
#define ICR1H_REG		(*(( volatile uint8 * )0X47 ))
#define ICR1L_REG		(*(( volatile uint8 * )0X46 ))

       
#define TCCR2_REG		(*(( volatile uint8 * )0X45 ))
#define TCCR2_FOC2_BIT		(7)
#define TCCR2_WGM20_BIT		(6)
#define TCCR2_COM21_BIT		(5)
#define TCCR2_COM20_BIT		(4)
#define TCCR2_WGM21_BIT		(3)
#define TCCR2_CS22_BIT		(2)
#define TCCR2_CS21_BIT		(1)
#define TCCR2_CS20_BIT		(0)

#define TCNT2_REG		(*(( volatile uint8 * )0X44 ))
#define OCR2_REG		(*(( volatile uint8 * )0X43 ))
    
#define ASSR_REG		(*(( volatile uint8 * )0X42 ))
#define ASSR_AS2_BIT		(3)
#define ASSR_TCN2UB_BIT		(2)
#define ASSR_OCR2UB_BIT		(1)
#define ASSR_TCR2UB_BIT		(0)
    
#define WDTCR_REG		(*(( volatile uint8 * )0X41 ))
#define WDTCR_WDTOE_BIT		(4)
#define WDTCR_WDE_BIT		(3)
#define WDTCR_WDP2_BIT		(2)
#define WDTCR_WDP1_BIT		(1)
#define WDTCR_WDP0_BIT		(0)

#define UBRRH_REG		(*(( volatile uint8 * )0X40 ))
#define UBRRH_URSEL_BIT		(7)
       
#define UCSRC_REG		(*(( volatile uint8 * )0X40))
#define UCSRC_URSEL_BIT		(7)
#define UCSRC_UMSEL_BIT		(6)
#define UCSRC_UPM1_BIT		(5)
#define UCSRC_UPM0_BIT		(4)
#define UCSRC_USBS_BIT		(3)
#define UCSRC_UCSZ1_BIT		(2)
#define UCSRC_UCSZ0_BIT		(1)
#define UCSRC_UCPOL_BIT		(0)

#define EEARH_REG		(*(( volatile uint8 * )0X3F))
#define EEARH_EEAR9_BIT		(1)
#define EEARH_EEAR8_BIT		(0)

#define EEARL_REG		(*(( volatile uint8 * )0X3E))
#define EEDR_REG		(*(( volatile uint8 * )0X3D))
   
#define EECR_REG		(*(( volatile uint8 * )0X3C ))
#define EECR_EERIE_BIT		(3)
#define EECR_EEMWE_BIT		(2)
#define EECR_EEWE_BIT		(1)
#define EECR_EERE_BIT		(0)

#define PORTA_REG		(*(( volatile uint8 * )0X3B))
#define PORTA_PORTA7_BIT		(7)
#define PORTA_PORTA6_BIT		(6)
#define PORTA_PORTA5_BIT		(5)
#define PORTA_PORTA4_BIT		(4)
#define PORTA_PORTA3_BIT		(3)
#define PORTA_PORTA2_BIT		(2)
#define PORTA_PORTA1_BIT		(1)
#define PORTA_PORTA0_BIT		(0)
  
#define DDRA_REG		(*(( volatile uint8 * )0X3A))
#define DDRA_DDA7_BIT		(7)
#define DDRA_DDA6_BIT		(6)
#define DDRA_DDA5_BIT		(5)
#define DDRA_DDA4_BIT		(4)
#define DDRA_DDA3_BIT		(3)
#define DDRA_DDA2_BIT		(2)
#define DDRA_DDA1_BIT		(1)
#define DDRA_DDA0_BIT		(0)

#define PINA_REG		(*(( volatile uint8 * )0X39))
#define PINA_PINA7_BIT		(7)
#define PINA_PINA6_BIT		(6)
#define PINA_PINA5_BIT		(5)
#define PINA_PINA4_BIT		(4)
#define PINA_PINA3_BIT		(3)
#define PINA_PINA2_BIT		(2)
#define PINA_PINA1_BIT		(1)
#define PINA_PINA0_BIT		(0)

#define PORTB_REG		(*(( volatile uint8 * )0X38))
#define PORTB_PORTB7_BIT		(7)
#define PORTB_PORTB6_BIT		(6)
#define PORTB_PORTB5_BIT		(5)
#define PORTB_PORTB4_BIT		(4)
#define PORTB_PORTB3_BIT		(3)
#define PORTB_PORTB2_BIT		(2)
#define PORTB_PORTB1_BIT		(1)
#define PORTB_PORTB0_BIT		(0)
  
#define DDRB_REG		(*(( volatile uint8 * )0X37))
#define DDRB_DDB7_BIT		(7)
#define DDRB_DDB6_BIT		(6)
#define DDRB_DDB5_BIT		(5)
#define DDRB_DDB4_BIT		(4)
#define DDRB_DDB3_BIT		(3)
#define DDRB_DDB2_BIT		(2)
#define DDRB_DDB1_BIT		(1)
#define DDRB_DDB0_BIT		(0)

#define PINB_REG		(*(( volatile uint8 * )0X36))
#define PINB_PINB7_BIT		(7)
#define PINB_PINB6_BIT		(6)
#define PINB_PINB5_BIT		(5)
#define PINB_PINB4_BIT		(4)
#define PINB_PINB3_BIT		(3)
#define PINB_PINB2_BIT		(2)
#define PINB_PINB1_BIT		(1)
#define PINB_PINB0_BIT		(0)

#define PORTC_REG		(*(( volatile uint8 * )0X35))
#define PORTC_PORTC7_BIT		(7)
#define PORTC_PORTC6_BIT		(6)
#define PORTC_PORTC5_BIT		(5)
#define PORTC_PORTC4_BIT		(4)
#define PORTC_PORTC3_BIT		(3)
#define PORTC_PORTC2_BIT		(2)
#define PORTC_PORTC1_BIT		(1)
#define PORTC_PORTC0_BIT		(0)
  
#define DDRC_REG		(*(( volatile uint8 * )0X34))
#define DDRC_DDC7_BIT		(7)
#define DDRC_DDC6_BIT		(6)
#define DDRC_DDC5_BIT		(5)
#define DDRC_DDC4_BIT		(4)
#define DDRC_DDC3_BIT		(3)
#define DDRC_DDC2_BIT		(2)
#define DDRC_DDC1_BIT		(1)
#define DDRC_DDC0_BIT		(0)

#define PINC_REG		(*(( volatile uint8 * )0X33))
#define PINC_PINC7_BIT		(7)
#define PINC_PINC6_BIT		(6)
#define PINC_PINC5_BIT		(5)
#define PINC_PINC4_BIT		(4)
#define PINC_PINC3_BIT		(3)
#define PINC_PINC2_BIT		(2)
#define PINC_PINC1_BIT		(1)
#define PINC_PINC0_BIT		(0)

#define PORTD_REG		(*(( volatile uint8 * )0X32))
#define PORTD_PORTD7_BIT		(7)
#define PORTD_PORTD6_BIT		(6)
#define PORTD_PORTD5_BIT		(5)
#define PORTD_PORTD4_BIT		(4)
#define PORTD_PORTD3_BIT		(3)
#define PORTD_PORTD2_BIT		(2)
#define PORTD_PORTD1_BIT		(1)
#define PORTD_PORTD0_BIT		(0)
  
#define DDRD_REG		(*(( volatile uint8 * )0X31))
#define DDRD_DDD7_BIT		(7)
#define DDRD_DDD6_BIT		(6)
#define DDRD_DDD5_BIT		(5)
#define DDRD_DDD4_BIT		(4)
#define DDRD_DDD3_BIT		(3)
#define DDRD_DDD2_BIT		(2)
#define DDRD_DDD1_BIT		(1)
#define DDRD_DDD0_BIT		(0)

#define PIND_REG		(*(( volatile uint8 * )0X30))
#define PIND_PIND7_BIT		(7)
#define PIND_PIND6_BIT		(6)
#define PIND_PIND5_BIT		(5)
#define PIND_PIND4_BIT		(4)
#define PIND_PIND3_BIT		(3)
#define PIND_PIND2_BIT		(2)
#define PIND_PIND1_BIT		(1)
#define PIND_PIND0_BIT		(0)

#define SPDR_REG		(*(( volatile uint8 * )0X2F ))
 
#define SPSR_REG		(*(( volatile uint8 * )0X2E ))
#define SPSR_SPIF_BIT		(7)
#define SPSR_WCOL_BIT		(6)
#define SPSR_SPI2X_BIT		(0)
    
#define SPCR_REG		(*(( volatile uint8 * )0X2D ))
#define SPCR_SPIE_BIT		(7)
#define SPCR_SPE_BIT		(6)
#define SPCR_DORD_BIT		(5)
#define SPCR_MSTR_BIT		(4)
#define SPCR_CPOL_BIT		(3)
#define SPCR_CPHA_BIT		(2)
#define SPCR_SPR1_BIT		(1)
#define SPCR_SPR0_BIT		(0)

#define UDR_REG		(*(( volatile uint8 * )0X2C ))
       
#define UCSRA_REG		(*(( volatile uint8 * )0X2B ))
#define UCSRA_RXC_BIT		(7)
#define UCSRA_TXC_BIT		(6)
#define UCSRA_UDRE_BIT		(5)
#define UCSRA_FE_BIT		(4)
#define UCSRA_DOR_BIT		(3)
#define UCSRA_PE_BIT		(2)
#define UCSRA_U2X_BIT		(1)
#define UCSRA_MPCM_BIT		(0)

#define UCSRB_REG		(*(( volatile uint8 * )0X2A ))
#define UCSRB_RXCIE_BIT		(7)
#define UCSRB_TXCIE_BIT		(6)
#define UCSRB_UDRIE_BIT		(5)
#define UCSRB_RXEN_BIT		(4)
#define UCSRB_TXEN_BIT		(3)
#define UCSRB_UCSZ2_BIT		(2)
#define UCSRB_RXB8_BIT		(1)
#define UCSRB_TXB8_BIT		(0)

#define UBRRL_REG		(*(( volatile uint8 * )0X29 ))

       
#define ACSR_REG		(*(( volatile uint8 * )0X28))
#define ACSR_ACD_BIT		(7)
#define ACSR_ACBG_BIT		(6)
#define ACSR_ACO_BIT		(5)
#define ACSR_ACI_BIT		(4)
#define ACSR_ACIE_BIT		(3)
#define ACSR_ACIC_BIT		(2)
#define ACSR_ACIS1_BIT		(1)
#define ACSR_ACIS0_BIT		(0)

#define ADMUX_REG		(*(( volatile uint8 * )0X27))
#define ADMUX_REFS1_BIT		(7)
#define ADMUX_REFS0_BIT		(6)
#define ADMUX_ADLAR_BIT		(5)
#define ADMUX_MUX4_BIT		(4)
#define ADMUX_MUX3_BIT		(3)
#define ADMUX_MUX2_BIT		(2)
#define ADMUX_MUX1_BIT		(1)
#define ADMUX_MUX0_BIT		(0)

#define ADCSRA_REG		(*(( volatile uint8 * )0X26))
#define ADCSRA_ADEN_BIT		(7)
#define ADCSRA_ADSC_BIT		(6)
#define ADCSRA_ADATE_BIT	(5)
#define ADCSRA_ADIF_BIT		(4)
#define ADCSRA_ADIE_BIT		(3)
#define ADCSRA_ADPS2_BIT	(2)
#define ADCSRA_ADPS1_BIT	(1)
#define ADCSRA_ADPS0_BIT	(0)

#define ADCH_REG		(*(( volatile uint8 * )0X25))

#define ADCL_REG		(*(( volatile uint8 * )0X24))

#define TWDR_REG		(*(( volatile uint8 * )0X23))

#define TWAR_REG		(*(( volatile uint8 * )0X22))
#define TWAR_TWA6_BIT		(7)
#define TWAR_TWA5_BIT		(6)
#define TWAR_TWA4_BIT		(5)
#define TWAR_TWA3_BIT		(4)
#define TWAR_TWA2_BIT		(3)
#define TWAR_TWA1_BIT		(2)
#define TWAR_TWA0_BIT		(1)
#define TWAR_TWGCE_BIT		(0)
  
#define TWSR_REG		(*(( volatile uint8 * )0X21))
#define TWSR_TWS7_BIT		(7)
#define TWSR_TWS6_BIT		(6)
#define TWSR_TWS5_BIT		(5)
#define TWSR_TWS4_BIT		(4)
#define TWSR_TWS3_BIT		(3)
#define TWSR_TWPS1_BIT		(1)
#define TWSR_TWPS0_BIT		(0)

#define TWBR_REG		(*(( volatile uint8 * )0X20))
#endif /*end of Atmega32A_H_*/
