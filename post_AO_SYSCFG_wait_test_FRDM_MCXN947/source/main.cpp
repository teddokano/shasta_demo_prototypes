#include	"r01lib.h"
#include	"afe/NAFE33352_UIOM.h"
#include	"utils.h"
#include	<vector>


std::vector<int>	wait_duration_variation	= { 0, 10, 100, 150, 200, 250 };	//	mili-seconds
std::vector<int>	result;

double				wait_duration;
constexpr int		repeat			= 100;	//	times


class NAFE33352_UIOM_custom : public NAFE33352_UIOM
{
public:
	NAFE33352_UIOM_custom( SPI& spi, bool spi_addr = 0, bool highspeed_variant = false, int nINT = D7, int DRDY = D4, int SYN = D2, int nRESET = DISABLED_PIN, int SYNCDAC = D3 )
		: NAFE33352_UIOM( spi, spi_addr, highspeed_variant, nINT, DRDY, SYN, nRESET, SYNCDAC )
	{
	}

	void open_dac_output( const uint16_t (&cc)[ 6 ] )
	{
		reg( AO_SYSCFG, cc[ 5 ] );	//	turn the DAC on first
		wait_ms( wait_duration );

		for ( auto i = 0; i < 5; i++ )
			reg( AIO_CONFIG + i, cc[ i ] );
	}
};


SPI						spi( ARD_MOSI, ARD_MISO, ARD_SCK, ARD_CS );	//	MOSI, MISO, SCLK, CS
NAFE33352_UIOM_custom	shasta( spi, 0 );

using enum NAFE33352_UIOM::Register16;
using enum NAFE33352_UIOM::Register24;
using enum NAFE33352_UIOM::Command;
using enum NAFE33352_UIOM::DAC::ModeSelect;

//#define	VOLTAGE_OUTPUT_SETTING
#define		CURRENT_LOAD_TEST


bool	test( void );

int main( void )
{
	printf( "***** Hello, UIOM board! *****\r\n" );

	spi.frequency( 1'000'000 );
	spi.mode( 1 );

	shasta.begin();

	printf( "Part number          = 0x%04X%04X%02X\r\n", shasta.reg( PN2 ), shasta.reg( PN1 ), shasta.reg( PN0_REV ) >> 8 );
	printf( "Revision             = 0x%02X\r\n", shasta.reg( PN0_REV ) & 0xFF );
	printf( "Unique serial number = 0x%06lX%06lX\r\n", shasta.reg( SERIAL1 ), shasta.reg( SERIAL0 ) );

	for ( auto&& wd: wait_duration_variation )
	{
		wait_duration	= wd;
		int	pulse_count	= 0;
		
		printf( "\r\npost AO_SYSCFG wait test\r\n" );
		printf( "wait duration  = %6.1lfms\r\n", wait_duration );
		
		for ( auto loop_count = 0; loop_count < repeat; loop_count++ )
		{
			pulse_count	+= test() ? 1 : 0;
			printf( "protection abort count = %d, loop count = %d\r\n", pulse_count, loop_count + 1 );				
		}
		
		result.push_back( pulse_count );
	}

	auto count	= 0;
	printf( "\r\nresult\r\n" );
	for ( auto&& wd: wait_duration_variation )
	{
		printf( "wait duration = %4dms : fail = %3d / %3d\r\n", wd, result[ count++ ], repeat );
	}
	
	printf( "\r\ndone\r\n" );

	while ( true )
		;
}

bool test( void )
{
	shasta.begin();	//	SHASTA is reset in this function
	wait( 0.5 );	//	wait for a while for just in case

#ifdef	VOLTAGE_OUTPUT_SETTING
	double	output_value	= 5.00;			//	5V
	shasta.dac.configure( VOLTAGE );
#else
	double	output_value	= 10 * 1e-3;	//	10mA
	shasta.dac.configure( CURRENT );
#endif

	shasta.dac	= output_value;

	wait_ms( 1 );
	
	if ( 0x7800 != shasta.reg( AIO_STATUS ) )
	{
//		printf( " ** CMD_AO_ABORT done (1) **\r\n" );
		shasta.command( CMD_AO_ABORT );
		
		return	true;
	}

	return	false;
}
