/*
 *  @author Tedd OKANO
 *
 *  Released under the MIT license
 */

#include	"r01lib.h"
#include	"afe/NAFE33352_UIOM.h"
#include	"utils.h"
#include	<map>

extern	NAFE33352_UIOM	shasta;

#if 0
std::map<int, const char*>	regstr	= {
{ 0x1021, "AI_CONFIG1" },
{ 0x1022, "AI_CONFIG2" },
{ 0x1023, "AI_MULTI_CH_EN" },
{ 0x1024, "AI_SYSCFG" },
{ 0x1025, "AI_STATUS" },
{ 0x1026, "AI_STATUS_OVR" },
{ 0x1027, "AI_STATUS_UDR" },
{ 0x1030, "AI_DATA0" },
{ 0x1031, "AI_DATA1" },
{ 0x1032, "AI_DATA2" },
{ 0x1033, "AI_DATA3" },
{ 0x1034, "AI_DATA4" },
{ 0x1035, "AI_DATA5" },
{ 0x1036, "AI_DATA6" },
{ 0x1037, "AI_DATA7" },
{ 0x1038, "AI_CH_OVR_THR_0" },
{ 0x1039, "AI_CH_OVR_THR_1" },
{ 0x103A, "AI_CH_OVR_THR_2" },
{ 0x103B, "AI_CH_OVR_THR_3" },
{ 0x103C, "AI_CH_OVR_THR_4" },
{ 0x103D, "AI_CH_OVR_THR_5" },
{ 0x103E, "AI_CH_OVR_THR_6" },
{ 0x103F, "AI_CH_OVR_THR_7" },
{ 0x1040, "AI_CH_UDR_THR_0" },
{ 0x1041, "AI_CH_UDR_THR_1" },
{ 0x1042, "AI_CH_UDR_THR_2" },
{ 0x1043, "AI_CH_UDR_THR_3" },
{ 0x1044, "AI_CH_UDR_THR_4" },
{ 0x1045, "AI_CH_UDR_THR_5" },
{ 0x1046, "AI_CH_UDR_THR_6" },
{ 0x1047, "AI_CH_UDR_THR_7" },
{ 0x1C20, "AIO_CONFIG" },
{ 0x1C21, "AO_CAL_COEF" },
{ 0x1C22, "AIO_PROT_CFG" },
{ 0x1C23, "AO_SLR_CTRL" },
{ 0x1C24, "AWG_PER" },
{ 0x1C25, "AO_SYSCFG" },
{ 0x1C26, "AIO_STATUS" },
{ 0x1C28, "AO_DATA" },
{ 0x1C29, "AO_OC_POS_LIMIT" },
{ 0x1C2A, "AO_OC_NEG_LIMIT" },
{ 0x1C2B, "AWG_AMP_MAX" },
{ 0x1C2C, "AWG_AMP_MIN" },
{ 0x0020, "CRC_CONF_REGS" },
{ 0x0021, "CRC_COEF_REGS" },
{ 0x0022, "CRC_TRIM_REGS" },
{ 0x003F, "CRC_TRIM_REF" },
{ 0x0023, "GPI_DATA" },
{ 0x0024, "GPO_ENABLE" },
{ 0x0025, "GPIO_FUNCTION" },
{ 0x0026, "GPI_ENABLE" },
{ 0x0027, "GPI_EDGE_POS" },
{ 0x0028, "GPI_EDGE_NEG" },
{ 0x0029, "GPO_DATA" },
{ 0x002A, "SYS_CONFIG" },
{ 0x002B, "SYS_STATUS" },
{ 0x0030, "CK_SRC_SEL_CONFIG" },
{ 0x002C, "GLOBAL_ALARM_ENABLE" },
{ 0x002D, "GLOBAL_ALARM_INT" },
{ 0x002E, "DIE_TEMP" },
{ 0x002F, "TEMP_THRS" },
{ 0x0050, "GAIN_COEF0" },
{ 0x0051, "GAIN_COEF1" },
{ 0x0052, "GAIN_COEF2" },
{ 0x0053, "GAIN_COEF3" },
{ 0x0054, "GAIN_COEF4" },
{ 0x0055, "GAIN_COEF5" },
{ 0x0056, "GAIN_COEF6" },
{ 0x0057, "GAIN_COEF7" },
{ 0x0058, "OFFSET_COEF0" },
{ 0x0059, "OFFSET_COEF1" },
{ 0x005A, "OFFSET_COEF2" },
{ 0x005B, "OFFSET_COEF3" },
{ 0x005C, "OFFSET_COEF4" },
{ 0x005D, "OFFSET_COEF5" },
{ 0x005E, "OFFSET_COEF6" },
{ 0x005F, "OFFSET_COEF7" },
{ 0x0060, "EXTRA_CAL_COEF0" },
{ 0x0061, "EXTRA_CAL_COEF1" },
{ 0x0062, "EXTRA_CAL_COEF2" },
{ 0x0063, "EXTRA_CAL_COEF3" },
{ 0x0064, "EXTRA_CAL_COEF4" },
{ 0x0065, "EXTRA_CAL_COEF5" },
{ 0x0066, "EXTRA_CAL_COEF6" },
{ 0x0067, "EXTRA_CAL_COEF7" },
{ 0x0040, "PN2" },
{ 0x0041, "PN1" },
{ 0x0042, "PN0_REV" },
{ 0x0043, "SERIAL1" },
{ 0x0044, "SERIAL0" }
	};
#endif
#if 0
typedef struct	_register_attribute	{
	uint8_t		length;
	const char* name;
} register_attribute;

std::map<int, register_attribute>	regstr	= {
	{ 0x1020, { 16, "AI_CONFIG0" } },
	{ 0x1021, { 16, "AI_CONFIG1" } },
	{ 0x1022, { 16, "AI_CONFIG2" } },
	{ 0x1023, { 16, "AI_MULTI_CH_EN" } },
	{ 0x1024, { 16, "AI_SYSCFG" } },
	{ 0x1025, { 16, "AI_STATUS" } },
	{ 0x1026, { 16, "AI_STATUS_OVR" } },
	{ 0x1027, { 16, "AI_STATUS_UDR" } },
	{ 0x1030, { 24, "AI_DATA0" } },
	{ 0x1031, { 24, "AI_DATA1" } },
	{ 0x1032, { 24, "AI_DATA2" } },
	{ 0x1033, { 24, "AI_DATA3" } },
	{ 0x1034, { 24, "AI_DATA4" } },
	{ 0x1035, { 24, "AI_DATA5" } },
	{ 0x1036, { 24, "AI_DATA6" } },
	{ 0x1037, { 24, "AI_DATA7" } },
	{ 0x1038, { 24, "AI_CH_OVR_THR_0" } },
	{ 0x1039, { 24, "AI_CH_OVR_THR_1" } },
	{ 0x103A, { 24, "AI_CH_OVR_THR_2" } },
	{ 0x103B, { 24, "AI_CH_OVR_THR_3" } },
	{ 0x103C, { 24, "AI_CH_OVR_THR_4" } },
	{ 0x103D, { 24, "AI_CH_OVR_THR_5" } },
	{ 0x103E, { 24, "AI_CH_OVR_THR_6" } },
	{ 0x103F, { 24, "AI_CH_OVR_THR_7" } },
	{ 0x1040, { 24, "AI_CH_UDR_THR_0" } },
	{ 0x1041, { 24, "AI_CH_UDR_THR_1" } },
	{ 0x1042, { 24, "AI_CH_UDR_THR_2" } },
	{ 0x1043, { 24, "AI_CH_UDR_THR_3" } },
	{ 0x1044, { 24, "AI_CH_UDR_THR_4" } },
	{ 0x1045, { 24, "AI_CH_UDR_THR_5" } },
	{ 0x1046, { 24, "AI_CH_UDR_THR_6" } },
	{ 0x1047, { 24, "AI_CH_UDR_THR_7" } },
	{ 0x1C20, { 16, "AIO_CONFIG" } },
	{ 0x1C21, { 16, "AO_CAL_COEF" } },
	{ 0x1C22, { 16, "AIO_PROT_CFG" } },
	{ 0x1C23, { 16, "AO_SLR_CTRL" } },
	{ 0x1C24, { 16, "AWG_PER" } },
	{ 0x1C25, { 16, "AO_SYSCFG" } },
	{ 0x1C26, { 16, "AIO_STATUS" } },
	{ 0x1C28, { 24, "AO_DATA" } },
	{ 0x1C29, { 24, "AO_OC_POS_LIMIT" } },
	{ 0x1C2A, { 24, "AO_OC_NEG_LIMIT" } },
	{ 0x1C2B, { 24, "AWG_AMP_MAX" } },
	{ 0x1C2C, { 24, "AWG_AMP_MIN" } },
	{ 0x0020, { 16, "CRC_CONF_REGS" } },
	{ 0x0021, { 16, "CRC_COEF_REGS" } },
	{ 0x0022, { 16, "CRC_TRIM_REGS" } },
	{ 0x003F, { 16, "CRC_TRIM_REF" } },
	{ 0x0023, { 16, "GPI_DATA" } },
	{ 0x0024, { 16, "GPO_ENABLE" } },
	{ 0x0025, { 16, "GPIO_FUNCTION" } },
	{ 0x0026, { 16, "GPI_ENABLE" } },
	{ 0x0027, { 16, "GPI_EDGE_POS" } },
	{ 0x0028, { 16, "GPI_EDGE_NEG" } },
	{ 0x0029, { 16, "GPO_DATA" } },
	{ 0x002A, { 16, "SYS_CONFIG" } },
	{ 0x002B, { 16, "SYS_STATUS" } },
	{ 0x0030, { 16, "CK_SRC_SEL_CONFIG" } },
	{ 0x002C, { 16, "GLOBAL_ALARM_ENABLE" } },
	{ 0x002D, { 16, "GLOBAL_ALARM_INT" } },
	{ 0x002E, { 16, "DIE_TEMP" } },
	{ 0x002F, { 16, "TEMP_THRS" } },
	{ 0x0050, { 24, "GAIN_COEF0" } },
	{ 0x0051, { 24, "GAIN_COEF1" } },
	{ 0x0052, { 24, "GAIN_COEF2" } },
	{ 0x0053, { 24, "GAIN_COEF3" } },
	{ 0x0054, { 24, "GAIN_COEF4" } },
	{ 0x0055, { 24, "GAIN_COEF5" } },
	{ 0x0056, { 24, "GAIN_COEF6" } },
	{ 0x0057, { 24, "GAIN_COEF7" } },
	{ 0x0058, { 24, "OFFSET_COEF0" } },
	{ 0x0059, { 24, "OFFSET_COEF1" } },
	{ 0x005A, { 24, "OFFSET_COEF2" } },
	{ 0x005B, { 24, "OFFSET_COEF3" } },
	{ 0x005C, { 24, "OFFSET_COEF4" } },
	{ 0x005D, { 24, "OFFSET_COEF5" } },
	{ 0x005E, { 24, "OFFSET_COEF6" } },
	{ 0x005F, { 24, "OFFSET_COEF7" } },
	{ 0x0060, { 24, "EXTRA_CAL_COEF0" } },
	{ 0x0061, { 24, "EXTRA_CAL_COEF1" } },
	{ 0x0062, { 24, "EXTRA_CAL_COEF2" } },
	{ 0x0063, { 24, "EXTRA_CAL_COEF3" } },
	{ 0x0064, { 24, "EXTRA_CAL_COEF4" } },
	{ 0x0065, { 24, "EXTRA_CAL_COEF5" } },
	{ 0x0066, { 24, "EXTRA_CAL_COEF6" } },
	{ 0x0067, { 24, "EXTRA_CAL_COEF7" } },
	{ 0x0040, { 16, "PN2" } },
	{ 0x0041, { 16, "PN1" } },
	{ 0x0042, { 16, "PN0_REV" } },
	{ 0x0043, { 24, "SERIAL1" } },
	{ 0x0044, { 24, "SERIAL0" } },
};


void show_r( uint16_t r )
{
	if ( regstr[ r ].length	== 16 )
		printf( "  %20s(0x%04X): 0x  %04X", regstr[ r ].name, r, shasta.read_r16( r ) );
	else
		printf( "  %20s(0x%04X): 0x%06lX", regstr[ r ].name, r, shasta.read_r24( r ) & 0xFFFFFF );
}
void reg_dump( RegVct reg_vctr, int column )
{
	table_view(
		reg_vctr.size(),
		column,
		[ &reg_vctr ]( int v )
		{
			//uint16_t	r	= static_cast<uint16_t>( reg_vctr[ v ] );
			//uint16_t r	= std::visit([](auto&& arg) { return static_cast<uint16_t>(arg); }, reg_vctr[v]);
			
			uint16_t r;
			if (std::holds_alternative<NAFE33352_Base::Register16>(reg_vctr[v])) {
				r = static_cast<uint16_t>(std::get<NAFE33352_Base::Register16>(reg_vctr[v]));
			} else {
				r = static_cast<uint16_t>(std::get<NAFE33352_Base::Register24>(reg_vctr[v]));
			}
			
			show_r( r );
		},   
		[]()
		{
		   printf( "\r\n" );
		}
	);
}

#else

void reg_dump( RegVct reg_vctr, int column )
{
	table_view(
		reg_vctr.size(),
		column,
		[ &reg_vctr ]( int v )
		{
			if ( const NAFE33352_Base::Register24 *ap	= std::get_if<NAFE33352_Base::Register24>( &(reg_vctr[ v ] ) ) )
			{
				printf( "      0x%04X: 0x%06lX", static_cast<int>( *ap ), shasta.reg( *ap ) & 0xFFFFFF );
			}
			else if ( const NAFE33352_Base::Register16 *ap	= std::get_if<NAFE33352_Base::Register16>( &(reg_vctr[ v ]) ) )
			{
				printf( "      0x%04X: 0x  %04X", static_cast<int>( *ap ), shasta.reg( *ap ) );
			}
		},   
		[]()
		{
		   printf( "\r\n" );
		}
	);
}
#endif
void reg_dump( NAFE33352_Base::Register24 addr, int length )
{
	table_view( length, 4, [ & ]( int v ){ printf( "      0x%04X: 0x%06lX", v + (uint16_t)addr, shasta.reg( v + addr ) & 0xFFFFFF ); }, [](){ printf( "\r\n" ); });
}

void logical_ch_config_view( void )
{
	uint16_t	en_ch_bitmap	= shasta.reg( AI_MULTI_CH_EN ) >> 8;
	const char	*reg_name[]		= { "AI_CONFIG0", "AI_CONFIG1", "AI_CONFIG2" };
	
	for ( auto channel = 0; channel < 16; channel++ )
	{	
		printf( "  logical channel %2d : ", channel );

		if ( en_ch_bitmap & (0x1 << channel) )
		{
			shasta.command( CMD_CH0 + channel );
			table_view( 3, 3, [ &reg_name ]( int v ){ printf( "   %s: 0x%04X", reg_name[ v ], shasta.reg( v + AI_CONFIG0 ) ); } );
		}
		else
		{
			printf(  "  (disabled)\r\n" );
		}
	}
}

void table_view( int length, int cols, std::function<void(int)> value, std::function<void(void)> linefeed )
{
	const auto	raws	= (int)(length + cols - 1) / cols;
	
	for ( auto i = 0; i < raws; i++  )
	{
		if ( i )
		{
			if ( linefeed )
				linefeed();
			else
				printf( "\r\n" );
		}
		
		for ( auto j = 0; j < cols; j++  )
		{
			auto	index	= i + j * raws;
			
			if ( index < length  )
				value( index );
		}
	}
	
	if ( linefeed )
		linefeed();
	else
		printf( "\r\n" );
}

